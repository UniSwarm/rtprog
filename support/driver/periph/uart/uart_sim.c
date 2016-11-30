/**
 * @file uart_dspic.c
 * @author Sebastien CAUX (sebcaux)
 * @copyright Robotips 2016
 *
 * @date April 13, 2016, 11:49 AM
 *
 * @brief Uart simulator support for rtprog
 */

#include "uart.h"
#include "uart_sim.h"
#include "simulator.h"

#include "driver/sysclock.h"
#include "sys/fifo.h"

#if !defined (UART_COUNT) || UART_COUNT==0
    #error No device
#endif

#include <stdio.h>

uart_dev uarts[] = {
    {.baudSpeed=0},
#if UART_COUNT>=2
    {.baudSpeed=0},
#endif
#if UART_COUNT>=3
    {.baudSpeed=0},
#endif
#if UART_COUNT>=4
    {.baudSpeed=0},
#endif
#if UART_COUNT>=5
    {.baudSpeed=0},
#endif
#if UART_COUNT>=6
    {.baudSpeed=0},
#endif
};

void uart_sendconfig(uint8_t uart)
{
    simulator_send(UART_SIM_MODULE, uart, UART_SIM_CONFIG, (char*)&uarts[uart], sizeof(uart_dev));
}

rt_dev_t uart_getFreeDevice()
{
    uint8_t i;

    for (i = 0; i < UART_COUNT; i++)
        if (uarts[i].baudSpeed == 0)
            break;

    if (i == UART_COUNT)
        return NULLDEV;

    uarts[i].baudSpeed = 115200;
    uarts[i].bitLenght = 8;
    uarts[i].bitStop = 1;
    uarts[i].bitParity = UART_BIT_PARITY_NONE;
    uart_sendconfig(i);

    return MKDEV(DEV_CLASS_UART, i);
}

void uart_releaseDevice(rt_dev_t device)
{
    uint8_t uart = MINOR(device);
    if (uart >= UART_COUNT)
        return;

    uarts[uart].baudSpeed = 0;
    uart_sendconfig(uart);
}

int uart_enable(rt_dev_t device)
{
    uint8_t uart = MINOR(device);
    if (uart >= UART_COUNT)
        return -1;

    uarts[uart].enabled = 1;
    uart_sendconfig(uart);

    return 0;
}

int uart_disable(rt_dev_t device)
{
    uint8_t uart = MINOR(device);
    if (uart >= UART_COUNT)
        return -1;

    uarts[uart].enabled = 0;
    uart_sendconfig(uart);

    return 0;
}

int uart_setBaudSpeed(rt_dev_t device, uint32_t baudSpeed)
{
    uint8_t uart = MINOR(device);
    if (uart >= UART_COUNT)
        return 0;

    uarts[uart].baudSpeed = baudSpeed;
    uart_sendconfig(uart);

    return 0;
}

uint32_t uart_baudSpeed(rt_dev_t device)
{
    uint8_t uart = MINOR(device);
    if (uart >= UART_COUNT)
        return 0;

    return uarts[uart].baudSpeed;
}

uint32_t uart_effectiveBaudSpeed(rt_dev_t device)
{
    uint8_t uart = MINOR(device);
    if (uart >= UART_COUNT)
        return 0;

    return uarts[uart].baudSpeed;
}

int uart_setBitConfig(rt_dev_t device, uint8_t bitLenght,
                      uint8_t bitParity, uint8_t bitStop)
{
    uint8_t uart = MINOR(device);
    if (uart >= UART_COUNT)
        return -1;

    uarts[uart].bitLenght = bitLenght;
    uarts[uart].bitStop = bitStop;
    uarts[uart].bitParity = bitParity;
    uart_sendconfig(uart);

    return 0;
}

uint8_t uart_bitLenght(rt_dev_t device)
{
    uint8_t uart = MINOR(device);
    if (uart >= UART_COUNT)
        return 0;

    return uarts[uart].bitLenght;
}

uint8_t uart_bitParity(rt_dev_t device)
{
    uint8_t uart = MINOR(device);
    if (uart >= UART_COUNT)
        return -1;

    return uarts[uart].bitParity;
}

uint8_t uart_bitStop(rt_dev_t device)
{
    uint8_t uart = MINOR(device);
    if (uart >= UART_COUNT)
        return -1;

    return uarts[uart].bitStop;
}

ssize_t uart_write(rt_dev_t device, const char *data, size_t size)
{
    uint8_t uart = MINOR(device);
    if (uart >= UART_COUNT)
        return -1;

    simulator_send(UART_SIM_MODULE, uart, UART_SIM_WRITE, data, size);

    return 0;
}

ssize_t uart_read(rt_dev_t device, char *data, size_t size_max)
{
	size_t size_read;
    uint8_t uart = MINOR(device);
    if (uart >= UART_COUNT)
        return 0;

    // TODO
    //simulator_send(UART_SIM_MODULE, uart, UART_SIM_READ, data, size);
    size_read = 0;

    return size_read;
}
