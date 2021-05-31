/**
 * @file timer_dspic33c.h
 * @author Sebastien CAUX (sebcaux)
 * @copyright UniSwarm 2018-2021
 *
 * @date June 01, 2018, 05:28 PM
 *
 * @brief Timer support for udevkit dsPIC33CH, dsPIC33CK
 *
 * Implementation based on Microchip document DS70005279B :
 *  http://ww1.microchip.com/downloads/en/DeviceDoc/dsPIC33-PIC24-FRM-Timer1-Module-70005279B.pdf
 */

#ifndef TIMER_DSPIC33C_H
#define TIMER_DSPIC33C_H

#if defined(DEVICE_33CH64MP202) || defined(DEVICE_33CH64MP202S1) || defined(DEVICE_33CH64MP203)                        \
    || defined(DEVICE_33CH64MP203S1) || defined(DEVICE_33CH64MP205) || defined(DEVICE_33CH64MP205S1)                   \
    || defined(DEVICE_33CH64MP206) || defined(DEVICE_33CH64MP206S1) || defined(DEVICE_33CH64MP208)                     \
    || defined(DEVICE_33CH64MP208S1) || defined(DEVICE_33CH64MP502) || defined(DEVICE_33CH64MP502S1)                   \
    || defined(DEVICE_33CH64MP503) || defined(DEVICE_33CH64MP503S1) || defined(DEVICE_33CH64MP505)                     \
    || defined(DEVICE_33CH64MP505S1) || defined(DEVICE_33CH64MP506) || defined(DEVICE_33CH64MP506S1)                   \
    || defined(DEVICE_33CH64MP508) || defined(DEVICE_33CH64MP508S1) || defined(DEVICE_33CH128MP202)                    \
    || defined(DEVICE_33CH128MP202S1) || defined(DEVICE_33CH128MP203) || defined(DEVICE_33CH128MP203S1)                \
    || defined(DEVICE_33CH128MP205) || defined(DEVICE_33CH128MP205S1) || defined(DEVICE_33CH128MP206)                  \
    || defined(DEVICE_33CH128MP206S1) || defined(DEVICE_33CH128MP208) || defined(DEVICE_33CH128MP208S1)                \
    || defined(DEVICE_33CH128MP502) || defined(DEVICE_33CH128MP502S1) || defined(DEVICE_33CH128MP503)                  \
    || defined(DEVICE_33CH128MP503S1) || defined(DEVICE_33CH128MP505) || defined(DEVICE_33CH128MP505S1)                \
    || defined(DEVICE_33CH128MP506) || defined(DEVICE_33CH128MP506S1) || defined(DEVICE_33CH128MP508)                  \
    || defined(DEVICE_33CH128MP508S1) || defined(DEVICE_33CH256MP205) || defined(DEVICE_33CH256MP205S1)                \
    || defined(DEVICE_33CH256MP206) || defined(DEVICE_33CH256MP206S1) || defined(DEVICE_33CH256MP208)                  \
    || defined(DEVICE_33CH256MP208S1) || defined(DEVICE_33CH256MP505) || defined(DEVICE_33CH256MP505S1)                \
    || defined(DEVICE_33CH256MP506) || defined(DEVICE_33CH256MP506S1) || defined(DEVICE_33CH256MP508)                  \
    || defined(DEVICE_33CH256MP508S1) || defined(DEVICE_33CH512MP205) || defined(DEVICE_33CH512MP205S1)                \
    || defined(DEVICE_33CH512MP206) || defined(DEVICE_33CH512MP206S1) || defined(DEVICE_33CH512MP208)                  \
    || defined(DEVICE_33CH512MP208S1) || defined(DEVICE_33CH512MP505) || defined(DEVICE_33CH512MP505S1)                \
    || defined(DEVICE_33CH512MP506) || defined(DEVICE_33CH512MP506S1) || defined(DEVICE_33CH512MP508)                  \
    || defined(DEVICE_33CH512MP508S1) || defined(DEVICE_33CK32MC102) || defined(DEVICE_33CK32MC103)                    \
    || defined(DEVICE_33CK32MC105) || defined(DEVICE_33CK32MP102) || defined(DEVICE_33CK32MP103)                       \
    || defined(DEVICE_33CK32MP105) || defined(DEVICE_33CK32MP202) || defined(DEVICE_33CK32MP203)                       \
    || defined(DEVICE_33CK32MP205) || defined(DEVICE_33CK32MP206) || defined(DEVICE_33CK32MP502)                       \
    || defined(DEVICE_33CK32MP503) || defined(DEVICE_33CK32MP505) || defined(DEVICE_33CK32MP506)                       \
    || defined(DEVICE_33CK64MC102) || defined(DEVICE_33CK64MC103) || defined(DEVICE_33CK64MC105)                       \
    || defined(DEVICE_33CK64MP102) || defined(DEVICE_33CK64MP103) || defined(DEVICE_33CK64MP105)                       \
    || defined(DEVICE_33CK64MP202) || defined(DEVICE_33CK64MP203) || defined(DEVICE_33CK64MP205)                       \
    || defined(DEVICE_33CK64MP206) || defined(DEVICE_33CK64MP208) || defined(DEVICE_33CK64MP502)                       \
    || defined(DEVICE_33CK64MP503) || defined(DEVICE_33CK64MP505) || defined(DEVICE_33CK64MP506)                       \
    || defined(DEVICE_33CK64MP508) || defined(DEVICE_33CK128MP202) || defined(DEVICE_33CK128MP203)                     \
    || defined(DEVICE_33CK128MP205) || defined(DEVICE_33CK128MP206) || defined(DEVICE_33CK128MP208)                    \
    || defined(DEVICE_33CK128MP502) || defined(DEVICE_33CK128MP503) || defined(DEVICE_33CK128MP505)                    \
    || defined(DEVICE_33CK128MP506) || defined(DEVICE_33CK128MP508) || defined(DEVICE_33CK256MP202)                    \
    || defined(DEVICE_33CK256MP203) || defined(DEVICE_33CK256MP205) || defined(DEVICE_33CK256MP206)                    \
    || defined(DEVICE_33CK256MP208) || defined(DEVICE_33CK256MP305) || defined(DEVICE_33CK256MP306)                    \
    || defined(DEVICE_33CK256MP308) || defined(DEVICE_33CK256MP502) || defined(DEVICE_33CK256MP503)                    \
    || defined(DEVICE_33CK256MP505) || defined(DEVICE_33CK256MP506) || defined(DEVICE_33CK256MP508)                    \
    || defined(DEVICE_33CK256MP605) || defined(DEVICE_33CK256MP606) || defined(DEVICE_33CK256MP608)                    \
    || defined(DEVICE_33CK512MP305) || defined(DEVICE_33CK512MP306) || defined(DEVICE_33CK512MP308)                    \
    || defined(DEVICE_33CK512MP605) || defined(DEVICE_33CK512MP606) || defined(DEVICE_33CK512MP608)
#    define TIMER_COUNT 1
#else
#    define TIMER_COUNT 0
#endif

#endif  // TIMER_DSPIC33C_H
