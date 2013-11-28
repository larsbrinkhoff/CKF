/*******************************************************************************
 * ChipKitForth
 * Interactive Forth environment for PIC32 based ChipKit boards.
 * Based on DIOSFORTH. http://www.forth.cz/Download/DIOSForth/DIOSForth.html
 * Developed under MPIDE.
 * Public repository: https://github.com/jvvood/ChipKitForth
 * Published under GPLv3.
 * Created by Janos Waldhauser (2013).
 * Email: janos.waldhauser@gmail.com
 ******************************************************************************/
 

/*******************************************************************************
 * This file contains extensions of dictionary with user defined C/C++ words.
 ******************************************************************************/


        {18, pr|4,     "dump",       (void *) Fdump}, 
	{5,  pr|2,     "++",         (void *) plusplus}, 
	{5,  pr|2,     "--",         (void *) minusminus}, 
	{5,  pr|1,     "?",          (void *) question}, 
	{5,  pr|2,     "u?",         (void *) uquestion}, 
	{5,  pr|6,     "millis",     (void *) Fmillis}, 
	{12, pr|6,     "micros",     (void *) Fmicros}, 
	{6,  pr|3,     "pm!",        (void *) Fpinmode}, 
	{7,  pr|2,     "d!",         (void *) Fdigitalwrite}, 
	{10, pr|2,     "d@",         (void *) Fdigitalread}, 
	{11, pr|2,     "a@",         (void *) Fanalogread},
	{11, pr|8,     "mask2bit",   (void *) mask2bit},
	{11, pr|11,    "portbit2pin",(void *) portbit2pin},
	{11, pr|12,    "portmask2pin",(void *) portmask2pin},
#ifdef WITH_SOFTPWM
	{11, pr|2,     "a!",         (void *) Fpwmwrite}, 
	{11, pr|2,     "s!",         (void *) Fservowrite}, 
#else
	{11, pr|2,     "a!",         (void *) Fanalogwrite}, 
#endif

	{11, pr|4,     "tone",       (void *) Ftone},
	{11, pr|6,     "notone",     (void *) no_tone},
	{11, pr|8,     "shiftout",   (void *) shiftout},
	{11, pr|7,     "shiftin",    (void *) shiftin},
	{11, pr|7,     "pulsein",    (void *) pulsein},

#ifdef WITH_WIRE
	{10, pr|8,     "i2c_init",   (void *) wire_begin}, 
	{10, pr|7,     "i2c_req",    (void *) wire_requestFrom}, 
	{10, pr|9,     "i2c_begin",  (void *) wire_beginTransmission}, 
	{10, pr|8,     "i2c_done",   (void *) wire_endTransmission}, 
	{10, pr|4,     "?i2c",       (void *) wire_available}, 
	{10, pr|5,     "i2c_@",      (void *) wire_receive}, 
	{10, pr|8,     "i2c_type",   (void *) wire_send}, 
	{10, pr|6,     "i2c_c!",     (void *) wire_send_byte}, 
	{10, pr|5,     "i2c_!",      (void *) wire_send_word}, 
#endif



#ifdef WITH_SPI
	{10, pr|8,     "spi_init",      (void *) spi_begin}, 
	{10, pr|8,     "spi_done",      (void *) spi_end}, 
	{10, pr|12,    "spi_bitorder",  (void *) spi_setBitOrder}, 
	{10, pr|12,    "spi_clockdiv",  (void *) spi_setClockDivider}, 
	{10, pr|8,     "spi_mode",      (void *) spi_setDataMode}, 
	{10, pr|11,    "spi_transfer",  (void *) spi_transfer}, 
#endif

#ifdef WITH_ISR
	{2,  pr|2,     "ei",            (void *) isrenable}, 
	{2,  pr|2,     "di",            (void *) isrdisable}, 
	{2,  pr|7,     "isrmask",       (void *) isrmask}, 
	{2,  pr|9,     "isrsource",     (void *) isrsource}, 
	{2,  pr|7,     "isrdata",       (void *) isrdata}, 
	{2,  pr|8,     "isrdata@",      (void *) isrdatafetch}, 
	{2,  pr|12,    "ISR_DATASIZE",  (void *) c_isrdatasize}, 
	{2,  pr|8,     "isrwords",      (void *) isrwords}, 
	{2,  pr|6,     "setisr",        (void *) setisr}, 
	{2,  pr|9,     "enableisr",     (void *) enableisr}, 
	{2,  pr|10,    "disableisr",    (void *) disableisr}, 
#ifdef WITH_CORETIM_ISR
	{2,  pr|6,     "uptime",        (void *) uptime}, 
#ifdef WITH_LOAD_INDICATOR
        {00, pr|4,     "load",          (void *) load},
#endif  // WITH_LOAD_INDICATOR
	{2,  pr|13,    "ISR_CORETIMER", (void *) c_coretimer}, 
#endif  // WITH_CORETIM_ISR
#ifdef WITH_PINCHANGE_ISR
	{2,  pr|13,    "ISR_PINCHANGE", (void *) c_pinchange}, 
	{2,  pr|7,     "pintocn",       (void *) pinToCN}, 
	{2,  pr|9,     "pinfromcn",     (void *) pinFromCN}, 
	{2,  pr|10,    "?pinchange",    (void *) pinchanged}, 

#endif // WITH_PINCHANGE_ISR
#endif  // WITH_ISR

#ifdef WITH_LCD
	{2,  pr|8,     "lcd_init",     (void *) lcd_init}, 
	{2,  pr|9,     "lcd_begin",    (void *) lcd_begin}, 
	{2,  pr|9,     "lcd_clear",    (void *) lcd_clear}, 
	{2,  pr|8,     "lcd_home",     (void *) lcd_home}, 
	{2,  pr|8,     "lcd_goto",     (void *) lcd_setcursor}, 
	{2,  pr|8,     "lcd_emit",     (void *) lcd_emit}, 
	{2,  pr|6,     "lcd_on",       (void *) lcd_on}, 
	{2,  pr|7,     "lcd_off",      (void *) lcd_off}, 
#endif // #ifdef WITH_LCD
	{2,  pr|7,     "extdict",      (void *) extdict}, 


