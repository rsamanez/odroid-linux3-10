/*  rtc.h
 *
 * Copyright (c) 2011 Samsung Electronics Co., Ltd
 *              http://www.samsung.com
 *
 *  This program is free software; you can redistribute  it and/or modify it
 *  under  the terms of  the GNU General  Public License as published by the
 *  Free Software Foundation;  either version 2 of the  License, or (at your
 *  option) any later version.
 *
 */

#ifndef __LINUX_MFD_SEC_RTC_H
#define __LINUX_MFD_SEC_RTC_H

enum s2m_rtc_reg {
	S2M_RTC_CTRL,
	S2M_RTC_WTSR_SMPL,
	S2M_RTC_UPDATE,
	S2M_CAP_SEL,
	S2M_RTC_SEC,
	S2M_RTC_MIN,
	S2M_RTC_HOUR,
	S2M_RTC_WEEK,
	S2M_RTC_DAY,
	S2M_RTC_MON,
	S2M_RTC_YEAR,
	S2M_ALARM0_SEC,
	S2M_ALARM0_MIN,
	S2M_ALARM0_HOUR,
	S2M_ALARM0_WEEK,
	S2M_ALARM0_DAY,
	S2M_ALARM0_MON,
	S2M_ALARM0_YEAR,
	S2M_ALARM1_SEC,
	S2M_ALARM1_MIN,
	S2M_ALARM1_HOUR,
	S2M_ALARM1_WEEK,
	S2M_ALARM1_DAY,
	S2M_ALARM1_MON,
	S2M_ALARM1_YEAR,
};

#define RTC_I2C_ADDR		(0x0C >> 1)

#define HOUR_12			(1 << 7)
#define HOUR_AMPM		(1 << 6)
#define HOUR_PM			(1 << 5)
#define ALARM0_STATUS		(1 << 1)
#define ALARM1_STATUS		(1 << 2)
#define UPDATE_AD		(1 << 0)

/* RTC Control Register */
#define BCD_EN_SHIFT		0
#define BCD_EN_MASK		(1 << BCD_EN_SHIFT)
#define MODEL24_SHIFT		1
#define MODEL24_MASK		(1 << MODEL24_SHIFT)
/* RTC Update Register1 */
#define RTC_UDR_SHIFT		0
#define RTC_UDR_MASK		(1 << RTC_UDR_SHIFT)

#define RTC_WUDR_SHIFT		4
#define RTC_WUDR_MASK		(1 << RTC_WUDR_SHIFT)
#define RTC_TCON_SHIFT		2
#define RTC_TCON_MASK		(1 << RTC_TCON_SHIFT)
#define RTC_RUDR_SHIFT		0
#define RTC_RUDR_MASK		(1 << RTC_RUDR_SHIFT)
#define RTC_TIME_EN_SHIFT	0
#define RTC_TIME_EN_MASK	(1 << RTC_TIME_EN_SHIFT)
/* RTC Hour register */
#define HOUR_PM_SHIFT		6
#define HOUR_PM_MASK		(1 << HOUR_PM_SHIFT)
/* RTC Alarm Enable */
#define ALARM_ENABLE_SHIFT	7
#define ALARM_ENABLE_MASK	(1 << ALARM_ENABLE_SHIFT)

#define SMPL_ENABLE_SHIFT	7
#define SMPL_ENABLE_MASK	(1 << SMPL_ENABLE_SHIFT)

#define WTSR_ENABLE_SHIFT	6
#define WTSR_ENABLE_MASK	(1 << WTSR_ENABLE_SHIFT)
#define RTCA0E			(1<<2)
#define RTCA1E			(1<<1)

enum {
	RTC_SEC = 0,
	RTC_MIN,
	RTC_HOUR,
	RTC_WEEKDAY,
	RTC_DATE,
	RTC_MONTH,
	RTC_YEAR1,
	RTC_YEAR2,
};

#endif /*  __LINUX_MFD_SEC_RTC_H */
