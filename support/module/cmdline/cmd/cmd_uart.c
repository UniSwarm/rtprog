
#include "driver/uart.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define puts(str) cmd_puts((str))
#define printf(format, ...) cmd_printf((format), ##__VA_ARGS__)
#include "cmd.h"

int cmd_uart(int argc, char **argv)
{
    uint8_t uart = 255;
    rt_dev_t uart_dev;
    char c;

#if !defined (UART_COUNT) || UART_COUNT==0
    puts("No UART module");
    return 1;
#else
    // no args -> print number of uarts
    if(argc == 1)
    {
        printf("count: %d\r\n", (int)UART_COUNT);
        return 0;
    }

    // first arg numeric : convert to uart id
    c = argv[1][0];
    if(isdigit(c))
    {
        uart = c - '0';
        c = argv[1][1];
        if(isdigit(c))
            uart = uart * 10 + (c - '0');
    }
    if (uart >= UART_COUNT)
    {
        printf("Invalid uart id %d\r\n", uart);
        return 0;
    }
    uart_dev = MKDEV(DEV_CLASS_UART, uart);

    // if no more arg, print properties of uart
    if(argc == 2)
    {
        char parity;
        switch (uart_bitParity(uart_dev))
        {
        case UART_BIT_PARITY_NONE:
            parity = 'N';
            break;
        case UART_BIT_PARITY_EVEN:
            parity = 'E';
            break;
        case UART_BIT_PARITY_ODD:
            parity = 'O';
            break;
        default:
            parity = 'U';
            break;
        }
        printf("Config: %lubds %d%c%d (%lubds)\r\n",
            uart_effectiveBaudSpeed(uart_dev),
            (int)uart_bitLenght(uart_dev),
            parity,
            (int)uart_bitStop(uart_dev),
            uart_baudSpeed(uart_dev));

        return 0;
    }

    // parse argv 2

    if(argc < 4)
        return 1;
    // == write
    if(strcmp(argv[2], "write")==0)
    {
        uart_write(uart_dev, argv[3], strlen(argv[3]));
        puts("ok");
        return 0;
    }
    // == read
    if(strcmp(argv[2], "read")==0)
    {
        char buff[100];
        size_t data_read;
        data_read = uart_read(uart_dev, buff, 100);
        buff[data_read] = 0;
        puts(buff);
        return 0;
    }
    // == setbs
    if(strcmp(argv[2], "setbs")==0)
    {
        uint32_t baudSpeed;
        baudSpeed = atol(argv[3]);
        uart_setBaudSpeed(uart_dev, baudSpeed);
        puts("ok");
        return 0;
    }

    return 1;
#endif
}
