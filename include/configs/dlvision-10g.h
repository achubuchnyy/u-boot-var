/*
 * (C) Copyright 2010
 * Dirk Eibach,  Guntermann & Drunck GmbH, eibach@gdsys.de
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_405EP		1	/* this is a PPC405 CPU */
#define CONFIG_DLVISION_10G	1	/*  on a DLVision-10G board */

#define	CONFIG_SYS_TEXT_BASE	0xFFFC0000

/*
 * Include common defines/options for all AMCC eval boards
 */
#define CONFIG_HOSTNAME		dlvsion-10g
#define CONFIG_IDENT_STRING	" dlvision-10g 0.06"
#include "amcc-common.h"

#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_BOARD_EARLY_INIT_R
#define CONFIG_MISC_INIT_R
#define CONFIG_LAST_STAGE_INIT

#define CONFIG_SYS_CLK_FREQ	33333333 /* external frequency to pll   */

#undef CONFIG_ZERO_BOOTDELAY_CHECK     /* ignore keypress on bootdelay==0 */

/*
 * Configure PLL
 */
#define PLLMR0_DEFAULT PLLMR0_266_133_66
#define PLLMR1_DEFAULT PLLMR1_266_133_66

/* new uImage format support */
#define CONFIG_FIT
#define CONFIG_FIT_VERBOSE	/* enable fit_format_{error,warning}() */
#define CONFIG_FIT_DISABLE_SHA256

#define CONFIG_ENV_IS_IN_FLASH	/* use FLASH for environment vars */

/*
 * Default environment variables
 */
#define	CONFIG_EXTRA_ENV_SETTINGS					\
	CONFIG_AMCC_DEF_ENV						\
	CONFIG_AMCC_DEF_ENV_POWERPC					\
	CONFIG_AMCC_DEF_ENV_NOR_UPD					\
	"kernel_addr=fc000000\0"					\
	"fdt_addr=fc1e0000\0"						\
	"ramdisk_addr=fc200000\0"					\
	""

#define CONFIG_PHY_ADDR		4	/* PHY address			*/
#define CONFIG_HAS_ETH0
#define CONFIG_HAS_ETH1
#define CONFIG_PHY1_ADDR	0xc	/* EMAC1 PHY address		*/
#define CONFIG_PHY_CLK_FREQ	EMAC_STACR_CLK_66MHZ

/*
 * Commands additional to the ones defined in amcc-common.h
 */
#define CONFIG_CMD_DTT
#undef CONFIG_CMD_DHCP
#undef CONFIG_CMD_DIAG
#undef CONFIG_CMD_EEPROM
#undef CONFIG_CMD_I2C
#undef CONFIG_CMD_IRQ

/*
 * SDRAM configuration (please see cpu/ppc/sdram.[ch])
 */
#define CONFIG_SDRAM_BANK0	1	/* init onboard SDRAM bank 0 */

/* SDRAM timings used in datasheet */
#define CONFIG_SYS_SDRAM_CL             3	/* CAS latency */
#define CONFIG_SYS_SDRAM_tRP           20	/* PRECHARGE command period */
#define CONFIG_SYS_SDRAM_tRC           66	/* ACTIVE-to-ACTIVE period */
#define CONFIG_SYS_SDRAM_tRCD          20	/* ACTIVE-to-READ delay */
#define CONFIG_SYS_SDRAM_tRFC          66	/* Auto refresh period */

/*
 * If CONFIG_SYS_EXT_SERIAL_CLOCK, then the UART divisor is 1.
 * If CONFIG_SYS_405_UART_ERRATA_59, then UART divisor is 31.
 * Otherwise, UART divisor is determined by CPU Clock and CONFIG_SYS_BASE_BAUD.
 * The Linux BASE_BAUD define should match this configuration.
 *    baseBaud = cpuClock/(uartDivisor*16)
 * If CONFIG_SYS_405_UART_ERRATA_59 and 200MHz CPU clock,
 * set Linux BASE_BAUD to 403200.
 */
#define CONFIG_CONS_INDEX	1	/* Use UART0			*/
#undef  CONFIG_SYS_EXT_SERIAL_CLOCK	/* external serial clock */
#undef  CONFIG_SYS_405_UART_ERRATA_59	/* 405GP/CR Rev. D silicon */
#define CONFIG_SYS_BASE_BAUD		691200

/*
 * I2C stuff
 */
#define CONFIG_SYS_I2C_PPC4XX
#define CONFIG_SYS_I2C_PPC4XX_CH0
#define CONFIG_SYS_I2C_PPC4XX_SPEED_0		100000
#define CONFIG_SYS_I2C_PPC4XX_SLAVE_0		0x7F

#define CONFIG_SYS_I2C_IHS
#define CONFIG_SYS_I2C_IHS_CH0
#define CONFIG_SYS_I2C_IHS_SPEED_0		50000
#define CONFIG_SYS_I2C_IHS_SLAVE_0		0x7F
#define CONFIG_SYS_I2C_IHS_CH1
#define CONFIG_SYS_I2C_IHS_SPEED_1		50000
#define CONFIG_SYS_I2C_IHS_SLAVE_1		0x7F

#define CONFIG_SYS_SPD_BUS_NUM		2

/* Temp sensor/hwmon/dtt */
#define CONFIG_SYS_DTT_BUS_NUM	2
#define CONFIG_DTT_LM63		1	/* National LM63	*/
#define CONFIG_DTT_SENSORS	{ 0x4c, 0x4e, 0x18 } /* Sensor addresses */
#define CONFIG_DTT_PWM_LOOKUPTABLE	\
		{ { 46, 10 }, { 48, 14 }, { 50, 19 }, { 52, 23 },\
		  { 54, 27 }, { 56, 31 }, { 58, 36 }, { 60, 40 } }
#define CONFIG_DTT_TACH_LIMIT	0xa10

#define CONFIG_SYS_ICS8N3QV01_I2C	{0, 1}
#define CONFIG_SYS_SIL1178_I2C		{0, 1}

/* EBC peripherals */

#define CONFIG_SYS_FLASH_BASE		0xFC000000
#define CONFIG_SYS_FPGA0_BASE		0x7f100000
#define CONFIG_SYS_FPGA1_BASE		0x7f200000
#define CONFIG_SYS_LATCH_BASE		0x7f300000

#define CONFIG_SYS_FPGA_BASE(k) \
	(k ? CONFIG_SYS_FPGA1_BASE : CONFIG_SYS_FPGA0_BASE)

#define CONFIG_SYS_FPGA_DONE(k) \
	(k ? 0x2000 : 0x1000)

#define CONFIG_SYS_FPGA_COUNT		2

#define CONFIG_SYS_FPGA_PTR { \
	(struct ihs_fpga *)CONFIG_SYS_FPGA0_BASE, \
	(struct ihs_fpga *)CONFIG_SYS_FPGA1_BASE }

#define CONFIG_SYS_FPGA_COMMON

#define CONFIG_SYS_LATCH0_RESET		0xffff
#define CONFIG_SYS_LATCH0_BOOT		0xffff
#define CONFIG_SYS_LATCH1_RESET		0xffbf
#define CONFIG_SYS_LATCH1_BOOT		0xffff

#define CONFIG_SYS_FPGA_NO_RFL_HI

/*
 * FLASH organization
 */
#define CONFIG_SYS_FLASH_CFI		/* The flash is CFI compatible	*/
#define CONFIG_FLASH_CFI_DRIVER		/* Use common CFI driver	*/

#define CONFIG_SYS_FLASH_BANKS_LIST	{ CONFIG_SYS_FLASH_BASE }

#define CONFIG_SYS_MAX_FLASH_BANKS	1	/* max num of memory banks */
#define CONFIG_SYS_MAX_FLASH_SECT	512	/* max num of sectors per chip*/

#define CONFIG_SYS_FLASH_ERASE_TOUT	120000	/* Timeout for Flash Erase/ms */
#define CONFIG_SYS_FLASH_WRITE_TOUT	500	/* Timeout for Flash Write/ms */

#define CONFIG_SYS_FLASH_USE_BUFFER_WRITE 1	/* use buff'd writes */

#define CONFIG_SYS_FLASH_EMPTY_INFO	/* 'E' for empty sector on flinfo */
#define CONFIG_SYS_FLASH_QUIET_TEST	1	/* no warn upon unknown flash */

#ifdef CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_SECT_SIZE	0x20000	/* size of one complete sector */
#define CONFIG_ENV_ADDR		((-CONFIG_SYS_MONITOR_LEN)-CONFIG_ENV_SECT_SIZE)
#define	CONFIG_ENV_SIZE		0x2000	/* Total Size of Environment Sector */

/* Address and size of Redundant Environment Sector	*/
#define CONFIG_ENV_ADDR_REDUND	(CONFIG_ENV_ADDR-CONFIG_ENV_SECT_SIZE)
#define CONFIG_ENV_SIZE_REDUND	(CONFIG_ENV_SIZE)
#endif

/*
 * PPC405 GPIO Configuration
 */
#define CONFIG_SYS_4xx_GPIO_TABLE { /* GPIO	Alternate1	*/ \
{ \
/* GPIO Core 0 */ \
{ GPIO_BASE, GPIO_OUT, GPIO_SEL,  GPIO_OUT_NO_CHG }, /* GPIO0	PerBLast */ \
{ GPIO_BASE, GPIO_OUT, GPIO_SEL,  GPIO_OUT_NO_CHG }, /* GPIO1	TS1E */ \
{ GPIO_BASE, GPIO_OUT, GPIO_SEL,  GPIO_OUT_NO_CHG }, /* GPIO2	TS2E */ \
{ GPIO_BASE, GPIO_IN,  GPIO_SEL,  GPIO_OUT_NO_CHG }, /* GPIO3	TS1O */ \
{ GPIO_BASE, GPIO_OUT, GPIO_SEL,  GPIO_OUT_NO_CHG }, /* GPIO4	TS2O */ \
{ GPIO_BASE, GPIO_OUT, GPIO_SEL,  GPIO_OUT_1      }, /* GPIO5	TS3 */ \
{ GPIO_BASE, GPIO_IN,  GPIO_SEL,  GPIO_OUT_NO_CHG }, /* GPIO6	TS4 */ \
{ GPIO_BASE, GPIO_OUT, GPIO_SEL,  GPIO_OUT_1      }, /* GPIO7	TS5 */ \
{ GPIO_BASE, GPIO_OUT, GPIO_SEL,  GPIO_OUT_NO_CHG }, /* GPIO8	TS6 */ \
{ GPIO_BASE, GPIO_OUT, GPIO_SEL,  GPIO_OUT_NO_CHG }, /* GPIO9	TrcClk */ \
{ GPIO_BASE, GPIO_OUT, GPIO_ALT1, GPIO_OUT_NO_CHG }, /* GPIO10	PerCS1 */ \
{ GPIO_BASE, GPIO_OUT, GPIO_ALT1, GPIO_OUT_NO_CHG }, /* GPIO11	PerCS2 */ \
{ GPIO_BASE, GPIO_OUT, GPIO_ALT1, GPIO_OUT_NO_CHG }, /* GPIO12	PerCS3 */ \
{ GPIO_BASE, GPIO_IN,  GPIO_SEL,  GPIO_OUT_NO_CHG }, /* GPIO13	PerCS4 */ \
{ GPIO_BASE, GPIO_OUT, GPIO_ALT1, GPIO_OUT_NO_CHG }, /* GPIO14	PerAddr03 */ \
{ GPIO_BASE, GPIO_OUT, GPIO_ALT1, GPIO_OUT_NO_CHG }, /* GPIO15	PerAddr04 */ \
{ GPIO_BASE, GPIO_OUT, GPIO_ALT1, GPIO_OUT_NO_CHG }, /* GPIO16	PerAddr05 */ \
{ GPIO_BASE, GPIO_IN,  GPIO_ALT1, GPIO_OUT_NO_CHG }, /* GPIO17	IRQ0 */ \
{ GPIO_BASE, GPIO_IN,  GPIO_ALT1, GPIO_OUT_NO_CHG }, /* GPIO18	IRQ1 */ \
{ GPIO_BASE, GPIO_IN,  GPIO_ALT1, GPIO_OUT_NO_CHG }, /* GPIO19	IRQ2 */ \
{ GPIO_BASE, GPIO_IN,  GPIO_SEL,  GPIO_OUT_NO_CHG }, /* GPIO20	IRQ3 */ \
{ GPIO_BASE, GPIO_OUT, GPIO_SEL,  GPIO_OUT_NO_CHG }, /* GPIO21	IRQ4 */ \
{ GPIO_BASE, GPIO_OUT, GPIO_SEL,  GPIO_OUT_NO_CHG }, /* GPIO22	IRQ5 */ \
{ GPIO_BASE, GPIO_IN,  GPIO_SEL,  GPIO_OUT_NO_CHG }, /* GPIO23	IRQ6 */ \
{ GPIO_BASE, GPIO_IN,  GPIO_ALT1, GPIO_OUT_NO_CHG }, /* GPIO24	UART0_DCD */ \
{ GPIO_BASE, GPIO_IN,  GPIO_ALT1, GPIO_OUT_NO_CHG }, /* GPIO25	UART0_DSR */ \
{ GPIO_BASE, GPIO_IN,  GPIO_ALT1, GPIO_OUT_NO_CHG }, /* GPIO26	UART0_RI */ \
{ GPIO_BASE, GPIO_OUT, GPIO_ALT1, GPIO_OUT_NO_CHG }, /* GPIO27	UART0_DTR */ \
{ GPIO_BASE, GPIO_IN,  GPIO_ALT1, GPIO_OUT_NO_CHG }, /* GPIO28	UART1_Rx */ \
{ GPIO_BASE, GPIO_OUT, GPIO_ALT1, GPIO_OUT_NO_CHG }, /* GPIO29	UART1_Tx */ \
{ GPIO_BASE, GPIO_OUT, GPIO_SEL,  GPIO_OUT_NO_CHG }, /* GPIO30	RejectPkt0 */ \
{ GPIO_BASE, GPIO_IN,  GPIO_SEL,  GPIO_OUT_NO_CHG }, /* GPIO31	RejectPkt1 */ \
} \
}

/*
 * Definitions for initial stack pointer and data area (in data cache)
 */
/* use on chip memory (OCM) for temperary stack until sdram is tested */
#define CONFIG_SYS_TEMP_STACK_OCM	1

/* On Chip Memory location */
#define CONFIG_SYS_OCM_DATA_ADDR	0xF8000000
#define CONFIG_SYS_OCM_DATA_SIZE	0x1000
#define CONFIG_SYS_INIT_RAM_ADDR	CONFIG_SYS_OCM_DATA_ADDR /* in SDRAM */
#define CONFIG_SYS_INIT_RAM_END	CONFIG_SYS_OCM_DATA_SIZE /* End of used area */

#define CONFIG_SYS_GBL_DATA_OFFSET \
	(CONFIG_SYS_INIT_RAM_END - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_OFFSET	CONFIG_SYS_GBL_DATA_OFFSET

/*
 * External Bus Controller (EBC) Setup
 */

/* Memory Bank 0 (NOR-flash) */
#define CONFIG_SYS_EBC_PB0AP	(EBC_BXAP_BME_ENABLED		|	\
				 EBC_BXAP_FWT_ENCODE(8)		|	\
				 EBC_BXAP_BWT_ENCODE(7)		|	\
				 EBC_BXAP_BCE_DISABLE		|	\
				 EBC_BXAP_BCT_2TRANS		|	\
				 EBC_BXAP_CSN_ENCODE(0)		|	\
				 EBC_BXAP_OEN_ENCODE(2)		|	\
				 EBC_BXAP_WBN_ENCODE(2)		|	\
				 EBC_BXAP_WBF_ENCODE(2)		|	\
				 EBC_BXAP_TH_ENCODE(4)		|	\
				 EBC_BXAP_RE_DISABLED		|	\
				 EBC_BXAP_SOR_NONDELAYED	|	\
				 EBC_BXAP_BEM_WRITEONLY		|	\
				 EBC_BXAP_PEN_DISABLED)
#define CONFIG_SYS_EBC_PB0CR	(EBC_BXCR_BAS_ENCODE(CONFIG_SYS_FLASH_BASE) | \
				 EBC_BXCR_BS_64MB		|	\
				 EBC_BXCR_BU_RW			|	\
				 EBC_BXCR_BW_16BIT)

/* Memory Bank 1 (FPGA0) */
#define CONFIG_SYS_EBC_PB1AP	(EBC_BXAP_BME_DISABLED		|	\
				 EBC_BXAP_TWT_ENCODE(5)		|	\
				 EBC_BXAP_BCE_DISABLE		|	\
				 EBC_BXAP_BCT_2TRANS		|	\
				 EBC_BXAP_CSN_ENCODE(0)		|	\
				 EBC_BXAP_OEN_ENCODE(2)		|	\
				 EBC_BXAP_WBN_ENCODE(1)		|	\
				 EBC_BXAP_WBF_ENCODE(1)		|	\
				 EBC_BXAP_TH_ENCODE(0)		|	\
				 EBC_BXAP_RE_DISABLED		|	\
				 EBC_BXAP_SOR_NONDELAYED	|	\
				 EBC_BXAP_BEM_WRITEONLY		|	\
				 EBC_BXAP_PEN_DISABLED)
#define CONFIG_SYS_EBC_PB1CR	(EBC_BXCR_BAS_ENCODE(CONFIG_SYS_FPGA0_BASE) | \
				 EBC_BXCR_BS_1MB		|	\
				 EBC_BXCR_BU_RW			|	\
				 EBC_BXCR_BW_16BIT)

/* Memory Bank 2 (FPGA1) */
#define CONFIG_SYS_EBC_PB2AP	(EBC_BXAP_BME_DISABLED		|	\
				 EBC_BXAP_TWT_ENCODE(6)		|	\
				 EBC_BXAP_BCE_DISABLE		|	\
				 EBC_BXAP_BCT_2TRANS		|	\
				 EBC_BXAP_CSN_ENCODE(0)		|	\
				 EBC_BXAP_OEN_ENCODE(2)		|	\
				 EBC_BXAP_WBN_ENCODE(1)		|	\
				 EBC_BXAP_WBF_ENCODE(1)		|	\
				 EBC_BXAP_TH_ENCODE(0)		|	\
				 EBC_BXAP_RE_DISABLED		|	\
				 EBC_BXAP_SOR_NONDELAYED	|	\
				 EBC_BXAP_BEM_WRITEONLY		|	\
				 EBC_BXAP_PEN_DISABLED)
#define CONFIG_SYS_EBC_PB2CR	(EBC_BXCR_BAS_ENCODE(CONFIG_SYS_FPGA1_BASE) | \
				 EBC_BXCR_BS_1MB		|	\
				 EBC_BXCR_BU_RW			|	\
				 EBC_BXCR_BW_16BIT)

/* Memory Bank 3 (Latches) */
#define CONFIG_SYS_EBC_PB3AP	(EBC_BXAP_BME_ENABLED		|	\
				 EBC_BXAP_FWT_ENCODE(8)		|	\
				 EBC_BXAP_BWT_ENCODE(4)		|	\
				 EBC_BXAP_BCE_DISABLE		|	\
				 EBC_BXAP_BCT_2TRANS		|	\
				 EBC_BXAP_CSN_ENCODE(0)		|	\
				 EBC_BXAP_OEN_ENCODE(1)		|	\
				 EBC_BXAP_WBN_ENCODE(1)		|	\
				 EBC_BXAP_WBF_ENCODE(1)		|	\
				 EBC_BXAP_TH_ENCODE(2)		|	\
				 EBC_BXAP_RE_DISABLED		|	\
				 EBC_BXAP_SOR_NONDELAYED	|	\
				 EBC_BXAP_BEM_WRITEONLY		|	\
				 EBC_BXAP_PEN_DISABLED)
#define CONFIG_SYS_EBC_PB3CR	(EBC_BXCR_BAS_ENCODE(CONFIG_SYS_LATCH_BASE) | \
				 EBC_BXCR_BS_1MB		|	\
				 EBC_BXCR_BU_RW			|	\
				 EBC_BXCR_BW_16BIT)

/*
 * OSD Setup
 */
#define CONFIG_SYS_MPC92469AC
#define CONFIG_SYS_OSD_SCREENS		CONFIG_SYS_FPGA_COUNT

#endif	/* __CONFIG_H */
