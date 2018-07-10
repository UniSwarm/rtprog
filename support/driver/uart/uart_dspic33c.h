/**
 * @file uart_dspic33.h
 * @author Sebastien CAUX (sebcaux)
 * @copyright UniSwarm 2018
 *
 * @date July 05, 2018, 13:24 PM
 *
 * @brief Uart communication support driver for dsPIC33CH and dsPIC33CK
 *
 * Implementation based on Microchip document DS70000582E :
 *  http://ww1.microchip.com/downloads/en/DeviceDoc/dsPIC33-PIC24-FRM-Multiprotocol-Universal-Asynchronous-Receiver-Transmitter-UART-Module-70005288b.pdf
 */

#ifndef UART_DSPIC33C_H
#define UART_DSPIC33C_H

// calculate UART count on the device
#if defined(DEVICE_33CH128MP202S1) || defined(DEVICE_33CH128MP203S1) || defined(DEVICE_33CH128MP205S1) \
 || defined(DEVICE_33CH128MP206S1) || defined(DEVICE_33CH128MP208S1) || defined(DEVICE_33CH128MP502S1) \
 || defined(DEVICE_33CH128MP503S1) || defined(DEVICE_33CH128MP505S1) || defined(DEVICE_33CH128MP506S1) \
 || defined(DEVICE_33CH128MP508S1) || defined(DEVICE_33CH64MP202S1) || defined(DEVICE_33CH64MP203S1) \
 || defined(DEVICE_33CH64MP205S1) || defined(DEVICE_33CH64MP206S1) || defined(DEVICE_33CH64MP208S1) \
 || defined(DEVICE_33CH64MP502S1) || defined(DEVICE_33CH64MP503S1) || defined(DEVICE_33CH64MP505S1) \
 || defined(DEVICE_33CH64MP506S1) || defined(DEVICE_33CH64MP508S1)
 #define UART_COUNT 1
#elif defined(DEVICE_33CH128MP202) || defined(DEVICE_33CH128MP203) || defined(DEVICE_33CH128MP205) \
 || defined(DEVICE_33CH128MP206) || defined(DEVICE_33CH128MP208) || defined(DEVICE_33CH128MP502) \
 || defined(DEVICE_33CH128MP503) || defined(DEVICE_33CH128MP505) || defined(DEVICE_33CH128MP506) \
 || defined(DEVICE_33CH128MP508) || defined(DEVICE_33CH64MP202) || defined(DEVICE_33CH64MP203) \
 || defined(DEVICE_33CH64MP205) || defined(DEVICE_33CH64MP206) || defined(DEVICE_33CH64MP208) \
 || defined(DEVICE_33CH64MP502) || defined(DEVICE_33CH64MP503) || defined(DEVICE_33CH64MP505) \
 || defined(DEVICE_33CH64MP506) || defined(DEVICE_33CH64MP508)
 #define UART_COUNT 2
#elif defined(DEVICE_33CK128MP202) || defined(DEVICE_33CK128MP203) || defined(DEVICE_33CK128MP205) \
 || defined(DEVICE_33CK128MP206) || defined(DEVICE_33CK128MP208) || defined(DEVICE_33CK128MP502) \
 || defined(DEVICE_33CK128MP503) || defined(DEVICE_33CK128MP505) || defined(DEVICE_33CK128MP506) \
 || defined(DEVICE_33CK128MP508) || defined(DEVICE_33CK256MP202) || defined(DEVICE_33CK256MP203) \
 || defined(DEVICE_33CK256MP205) || defined(DEVICE_33CK256MP206) || defined(DEVICE_33CK256MP208) \
 || defined(DEVICE_33CK256MP502) || defined(DEVICE_33CK256MP503) || defined(DEVICE_33CK256MP505) \
 || defined(DEVICE_33CK256MP506) || defined(DEVICE_33CK256MP508) || defined(DEVICE_33CK32MP102) \
 || defined(DEVICE_33CK32MP103) || defined(DEVICE_33CK32MP105) || defined(DEVICE_33CK32MP202) \
 || defined(DEVICE_33CK32MP203) || defined(DEVICE_33CK32MP205) || defined(DEVICE_33CK32MP206) \
 || defined(DEVICE_33CK32MP502) || defined(DEVICE_33CK32MP503) || defined(DEVICE_33CK32MP505) \
 || defined(DEVICE_33CK32MP506) || defined(DEVICE_33CK64MP102) || defined(DEVICE_33CK64MP103) \
 || defined(DEVICE_33CK64MP105) || defined(DEVICE_33CK64MP202) || defined(DEVICE_33CK64MP203) \
 || defined(DEVICE_33CK64MP205) || defined(DEVICE_33CK64MP206) || defined(DEVICE_33CK64MP208) \
 || defined(DEVICE_33CK64MP502) || defined(DEVICE_33CK64MP503) || defined(DEVICE_33CK64MP505) \
 || defined(DEVICE_33CK64MP506) || defined(DEVICE_33CK64MP508)
 #define UART_COUNT 3
#else
 #define UART_COUNT 0
#endif

#define UART_MAXBRG 0x000FFFFF    // 24 bits divisor

#endif // UART_DSPIC33C_H
