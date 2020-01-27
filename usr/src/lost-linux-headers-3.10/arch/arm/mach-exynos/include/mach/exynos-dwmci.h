/* arch/arm/mach-exynos/include/mach/exynos-dwmci.h
 *
 * Copyright (c) 2014 Samsung Electronics Co., Ltd.
 *						  http://www.samsung.com
 *
 * Exynos dependent definitions for DesignWare MMC driver
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef _EXYNOS_DWMCI_H_
#define _EXYNOS_DWMCI_H_

/*****************/
/* SFR addresses */
/*****************/

#define SFR_OFFSET		0x0004

#if defined(CONFIG_SOC_EXYNOS5433)

#define SDMMC_DBADDRL 		 0x0088
#define SDMMC_DBADDRU		(SDMMC_DBADDRL + SFR_OFFSET)
#define SDMMC_IDSTS		(SDMMC_DBADDRU + SFR_OFFSET)
#define SDMMC_IDINTEN		(SDMMC_IDSTS + SFR_OFFSET)
#define SDMMC_DSCADDRL		(SDMMC_IDINTEN + SFR_OFFSET)
#define SDMMC_DSCADDRU		(SDMMC_DSCADDRL + SFR_OFFSET)
#define SDMMC_BUFADDR		(SDMMC_DSCADDRU + SFR_OFFSET)
#define SDMMC_BUFADDRU		(SDMMC_BUFADDR + SFR_OFFSET)
#define SDMMC_CLKSEL		(SDMMC_BUFADDRU + SFR_OFFSET) /* specific to Samsung Exynos */

#define SDMMC_AXI_BURST_LEN	0x00b4
#define SDMMC_SECTOR_NUM_INC	0x01F8

#else

#define SDMMC_DBADDR		 0x0088
#define SDMMC_IDSTS		(SDMMC_DBADDR + SFR_OFFSET)
#define SDMMC_IDINTEN		(SDMMC_IDSTS + SFR_OFFSET)
#define SDMMC_DSCADDR		(SDMMC_IDINTEN + SFR_OFFSET)
#define SDMMC_BUFADDR		(SDMMC_DSCADDR + SFR_OFFSET)
#define SDMMC_CLKSEL		(SDMMC_BUFADDR + SFR_OFFSET) /* specific to Samsung Exynos */

#define SDMMC_AXI_BURST_LEN	0xffff	/*not used*/
#define SDMMC_SECTOR_NUM_INC	0xffff	/*not used*/

#endif

#define SDMMC_CDTHRCTL		0x100
#define SDMMC_DATA(x)		(x)

#if defined(CONFIG_SOC_EXYNOS5422) || defined(CONFIG_SOC_EXYNOS5430) || defined(CONFIG_SOC_EXYNOS5433)
#define SDMMC_DDR200_ENABLE_SHIFT	0x110
#define SDMMC_DDR200_RDDQS_EN		0x180
#define SDMMC_DDR200_ASYNC_FIFO_CTRL	0x184
#define SDMMC_DDR200_DLINE_CTRL		0x188
#else
#define SDMMC_DDR200_RDDQS_EN		0x110
#define SDMMC_DDR200_ASYNC_FIFO_CTRL	0x114
#define SDMMC_DDR200_DLINE_CTRL		0x118
#endif

#define SDMMC_EMMCP_BASE		0x1000
#define SDMMC_MPSTAT			(SDMMC_EMMCP_BASE + 0x0008)
#define SDMMC_MPSECURITY		(SDMMC_EMMCP_BASE + 0x0010)
#define SDMMC_MPENCKEY			(SDMMC_EMMCP_BASE + 0x0020)
#define SDMMC_MPSBEGIN0			(SDMMC_EMMCP_BASE + 0x0200)
#define SDMMC_MPSEND0			(SDMMC_EMMCP_BASE + 0x0204)
#define SDMMC_MPSCTRL0			(SDMMC_EMMCP_BASE + 0x020C)
#define SDMMC_MPSBEGIN1			(SDMMC_EMMCP_BASE + 0x0210)
#define SDMMC_MPSEND1			(SDMMC_EMMCP_BASE + 0x0214)
#define SDMMC_MPSCTRL1			(SDMMC_EMMCP_BASE + 0x021C)

/******************/
/* Derived macros */
/******************/
/* SDMMC_CLKSEL */
#define SDMMC_CLKSEL_CCLK_SAMPLE(x)	(((x) & 7) << 0)
#define SDMMC_CLKSEL_CCLK_FINE_SAMPLE(x)	(((x) & 0xF) << 0)
#define SDMMC_CLKSEL_CCLK_DRIVE(x)	(((x) & 7) << 16)
#define SDMMC_CLKSEL_CCLK_FINE_DRIVE(x)	(((x) & 3) << 22)
#define SDMMC_CLKSEL_CCLK_DIVIDER(x)	(((x) & 7) << 24)
#define SDMMC_CLKSEL_GET_DRV_WD3(x)	(((x) >> 16) & 0x7)
#define SDMMC_CLKSEL_GET_DIVRATIO(x)	((((x) >> 24) & 0x7) + 1)
#define SDMMC_CLKSEL_TIMING(div, f_drv, drv, sample) \
	(SDMMC_CLKSEL_CCLK_DIVIDER(div) |	\
	 SDMMC_CLKSEL_CCLK_FINE_DRIVE(f_drv) |	\
	 SDMMC_CLKSEL_CCLK_DRIVE(drv) |		\
	 SDMMC_CLKSEL_CCLK_SAMPLE(sample))

/* SDMMC_DDR200_RDDQS_EN */
#define DWMCI_TXDT_CRC_TIMER_FASTLIMIT(x)	(((x) & 0xFF) << 16)
#define DWMCI_TXDT_CRC_TIMER_INITVAL(x)		(((x) & 0xFF) << 8)
#define DWMCI_TXDT_CRC_TIMER_SET(x, y)	(DWMCI_TXDT_CRC_TIMER_FASTLIMIT(x) | \
					DWMCI_TXDT_CRC_TIMER_INITVAL(y))
#define DWMCI_AXI_NON_BLOCKING_WRITE		BIT(7)
#define DWMCI_RESP_RCLK_MODE			BIT(5)
#define DWMCI_BUSY_CHK_CLK_STOP_EN		BIT(2)
#define DWMCI_RXDATA_START_BIT_SEL		BIT(1)
#define DWMCI_RDDQS_EN				BIT(0)
#define DWMCI_DDR200_RDDQS_EN_DEF	(DWMCI_TXDT_CRC_TIMER_FASTLIMIT(0x13) | \
					DWMCI_TXDT_CRC_TIMER_INITVAL(0x15))

/* SDMMC_DDR200_ASYNC_FIFO_CTRL */
#define DWMCI_ASYNC_FIFO_RESET		BIT(0)

/* SDMMC_DDR200_DLINE_CTRL */
#define DWMCI_WD_DQS_DELAY_CTRL(x)		(((x) & 0x3FF) << 20)
#define DWMCI_FIFO_CLK_DELAY_CTRL(x)		(((x) & 0x3) << 16)
#define DWMCI_RD_DQS_DELAY_CTRL(x)		((x) & 0x3FF)
#define DWMCI_DDR200_DLINE_CTRL_SET(x, y, z)	(DWMCI_WD_DQS_DELAY_CTRL(x) | \
						DWMCI_FIFO_CLK_DELAY_CTRL(y) | \
						DWMCI_RD_DQS_DELAY_CTRL(z))
#define DWMCI_DDR200_DLINE_CTRL_DEF	(DWMCI_FIFO_CLK_DELAY_CTRL(0x2) | \
					DWMCI_RD_DQS_DELAY_CTRL(0x96))

/* SDMMC_SECTOR_NUM_INC */
#define DWMCI_BURST_LENGTH_MASK		(0xF)
#define DWMCI_BURST_LENGTH_CTRL(x)	(((x)&DWMCI_BURST_LENGTH_MASK) | \
					(((x)&DWMCI_BURST_LENGTH_MASK)<<16))

/* SDMMC_SECTOR_NUM_INC */
#define DWMCI_SECTOR_SIZE_MASK		(0x1FFF)
#define DWMCI_SECTOR_SIZE_CTRL(x)	((x)&DWMCI_SECTOR_SIZE_MASK)

/* SDMMC_DDR200_ENABLE_SHIFT */
#define DWMCI_ENABLE_SHIFT_MASK			(0x3)
#define DWMCI_ENABLE_SHIFT(x)			((x) & DWMCI_ENABLE_SHIFT_MASK)

/* Block number in eMMC */
#define DWMCI_BLOCK_NUM			0xFFFFFFFF

/* SMU control bits */
#define DWMCI_MPSCTRL_SECURE_READ_BIT		BIT(7)
#define DWMCI_MPSCTRL_SECURE_WRITE_BIT		BIT(6)
#define DWMCI_MPSCTRL_NON_SECURE_READ_BIT	BIT(5)
#define DWMCI_MPSCTRL_NON_SECURE_WRITE_BIT	BIT(4)
#define DWMCI_MPSCTRL_USE_FUSE_KEY		BIT(3)
#define DWMCI_MPSCTRL_ECB_MODE			BIT(2)
#define DWMCI_MPSCTRL_ENCRYPTION		BIT(1)
#define DWMCI_MPSCTRL_VALID			BIT(0)

#define EXYNOS4210_FIXED_CIU_CLK_DIV	2
#define EXYNOS4412_FIXED_CIU_CLK_DIV	4

/* FMP configuration */
#if defined(CONFIG_SOC_EXYNOS5433)
#define DW_MMC_BYPASS_SECTOR_BEGIN		0x80000000
#define DW_MMC_BYPASS_SECTOR_END		0xFFFFFFFF
#define DW_MMC_ENCRYPTION_SECTOR_BEGIN		0
#define DW_MMC_ENCRYPTION_SECTOR_END		0x7FFFFFFF
#else
#define DW_MMC_BYPASS_SECTOR_BEGIN		0
#define DW_MMC_BYPASS_SECTOR_END		0
#define DW_MMC_ENCRYPTION_SECTOR_BEGIN		1
#define DW_MMC_ENCRYPTION_SECTOR_END		0xFFFFFFFF
#endif

#endif /* _EXYNOS_DWMCI_H_ */
