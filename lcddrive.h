#ifndef _LCDDRIVE_H_
#define _LCDDRIVE_H_

#include <reg52.h>
#include <basetypehelp.h>

#define LCD_DATA_PORT	P0

sbit LCD_CS = P2^6;
sbit LCD_RST = P2^7;
sbit LCD_RS = P2^5;
sbit LCD_WR = P3^3;
sbit LCD_RD = P3^2;

#define CHIP_ID		(0x00)
	#define READ_REV_ID						(0xF8)
	#define READ_CHIP_ID					(0x07)

#define MODE_SEL1	(0x01)
	#define PANEL_RESOLUTION_128X160						(0x00) // default
	#define PANEL_RESOLUTION_128X128						(0x40)
	#define PANEL_RESOLUTION_96X96							(0x80)
	#define PANEL_RESOLUTION_132X160						(0xC0)
		#define VCOM_NORMAL									(0x00) // default
		#define VCOM_OUTPUT_MASK							(0x20)
			#define COLOR_MODE_16_18						(0x00)
			#define COLOR_MODE_16_18_PARTIAL				(0x04)
			#define COLOR_MODE_8							(0x08)
			#define COLOR_MODE_8_PARTIAL					(0x0C)
			#define COLOR_MODE_8_DITHERING					(0x10)
			#define COLOR_MODE_8_DITHERING_PARTIAL			(0x14)
				#define SLEEP_MODE_SLEEP					(0x00)
				#define SLEEP_MODE_NORMAL					(0x02) // default
					#define OUT_OF_RANGE_COLOR_WHITE		(0x00) // default
					#define OUT_OF_RANGE_COLOR_BLACK		(0x01)

#define	MODE_SEL2	(0x02)
	#define SCAN_DIRECTION_CSV_H										(0x00) // default
	#define SCAN_DIRECTION_CSV_L										(0x80)
		#define SCAN_DIRECTION_CSH_H									(0x00) // default
		#define SCAN_DIRECTION_CSH_L									(0x40)
			#define INVERSION_LINE										(0x00) // default
			#define INVERSION_FRAME										(0x20)
				#define STV2_OUTPUT										(0x00)
				#define STV2_NO_OUTPUT									(0x10) // default
					#define STV1_OUTPUT									(0x00) // default
					#define STV1_NO_OUTPUT								(0x08)
						#define NON_PARTIAL_AREA_DATA_OUTPUT_GND		(0x00)
						#define NON_PARTIAL_AREA_DATA_OUTPUT_VCOM		(0x02) // default
						#define NON_PARTIAL_AREA_DATA_OUTPUT_HI_Z		(0x04)
							#define NON_PARTIAL_AREA_OUTPUT_CKH123_LOW	(0x00) // default
							#define NON_PARTIAL_AREA_OUTPUT_CKH123_HIGH	(0x01)

#define MODE_SEL3	(0x03)
	#define INPUT_DATA_MODE_8_BIT								(0x00) // default
	#define INPUT_DATA_MODE_16_BIT								(0x40)
	#define INPUT_DATA_MODE_9_BIT								(0x80)
	#define INPUT_DATA_MODE_18_BIT								(0xC0)
		#define	DATA_ACCESS_CONTROL_CYCLE1_2BIT_CYCLE2_16BIT	(0x00)	// default
		#define DATA_ACCESS_CONTROL_CYCLE1_16BIT_CYCLE2_2BIT	(0x10)
		#define DATA_ACCESS_CONTROL_CYCLE_16BIT					(0x20)

#define MODE_SEL4	(0x04)
	#define RGB_INTERFACE_MODE_DE				(0x00) // default
	#define RGB_INTERFACE_MODE_VS_HS			(0x80)
		#define SYNC_POLARITY_NEGATIVE			(0x00) // default
		#define SYNC_POLARITY_POSITIVE			(0x40)
			#define INPUT_DATA_MAPPING_18BIT	(0x00) // default
			#define INPUT_DATA_MAPPING_16BIT	(0x20)
				#define INPUT_MODE_MOVING		(0x00) // default
				#define INPUT_MODE_STILL		(0x10)
				
#define VCO_MODE	(0x05)
	#define VCO_BIAS_MODE_DEC5	    			(0x00)
	#define VCO_BIAS_MODE_TYPICAL				(0x08) // default
	#define VCO_BIAS_MODE_ADD5					(0x10)
	#define VCO_BIAS_MODE_ADD10					(0x18)
		#define VCO_FREQUENCY_1D82_MHZ			(0x00) // default
		#define VCO_FREQUENCY_1D82MUL3DIV4_MHZ	(0x20)
		#define VCO_FREQUENCY_1D82DIV2_MHZ		(0x01)
		#define VCO_FREQUENCY_1D5_MHZ			(0x02)
		#define VCO_FREQUENCY_1D5MUL3DIV4_MHZ	(0x22)
		#define VCO_FREQUENCY_1D5DIV2_MHZ		(0x03)
		#define VCO_FREQUENCY_0D9_MHZ			(0x04)
		#define VCO_FREQUENCY_0D9MUL3DIV4_MHZ	(0x24)
		#define VCO_FREQUENCY_0D9DIV2_MHZ		(0x05)
		
#define DAC_OP_CTRL2	(0x06) // 
	#define DCDC_VPOWER_INPUT_PIN_PWDN			(0x00)
	#define DCDC_VPOWER_INPUT_INTERNAL_REGISTER	(0x80) // default
		#define PWDN_AVDD1_AVDD2_POWER_OFF		(0x00) // default
		#define PWDN_AVDD1_AVDD2_POWER_ON		(0x40)
			#define DAC_BIAS_100				(0x00) // default
			#define DAC_BIAS_80					(0x10)
			#define DAC_BIAS_60					(0x20)
			#define DAC_BIAS_50					(0x30)
				#define VCOM_BIAS_DEC20xNORMAL	(0x00)
				#define VCOM_BIAS_NORMAL		(0x04) // default
				#define VCOM_BIAS_20xNORMAL		(0x08)
				#define VCOM_BIAS_40xNORMAL		(0x0C)
					#define RGB_LOAD_5P			(0x00)
					#define RGB_LOAD_10D5P		(0x01) // default
					#define RGB_LOAD_15P		(0x02)
					#define RGB_LOAD_20P		(0x03)

#define VCOMH_CTRL	(0x07) // 2.1V / VCOM_H_V_MAX = 0.0164V default = 4.0v
	#define VCOM_H_V_MAX	(127)
	#define VCOM_H_V_MIN	(0) 

#define VCOML_CTRL	(0x08) // 2.1V / VCOM_L_V_MAX = 0.0164V default = 0.197v
	#define VCOM_L_V_MAX	(127)
	#define VCOM_L_V_MIN	(0)
	
#define SRAM_PWS_X	(0x09)
#define SRAM_PWS_Y	(0x10)
#define SRAM_PWE_X	(0x11)
#define SRAM_PWE_Y	(0x12)
#define SRAM_PDS_Y	(0x14)
#define SRAM_PDE_Y	(0x16)

#define SRAM_CONTROL	(0x17)
	#define SRAM_X_Y_NOT_CHANGED				(0x00) // default
	#define	SRAM_X_Y_CHANGED					(0x08)
		#define SRAM_X_POS_COUNTER_ADD1			(0x00) // default
		#define SRAM_X_POS_COUNTER_DEC1			(0x04)
			#define SRAM_Y_POS_COUNTER_ADD1		(0x00) // default
			#define SRAM_Y_POS_COUNTER_DEC1		(0x02)
				#define SRAM_X_Y_COUNTER_ADD	(0x00) // default
				#define SRAM_Y_X_COUNTER_ADD	(0x01)

#define SRAM_POS_X	(0x18)
	#define SRAM_POS_X_MAX	(0x83)
	#define SRAM_POS_X_MIN	(0)

#define SRAM_POS_Y	(0x19)
	#define SRAM_POS_Y_MAX	(0x9F)
	#define SRAM_POS_Y_MIN	(0)
	
#define TH	(0x1A)
	#define TH_MAX	(255)
	#define TH_MIN	(0)

#define TV	(0x1B)
	#define TV_MAX	(31)
	#define TV_MIN	(0)

#define GAMMA_ADJUST1	(0x21)
#define GAMMA_ADJUST2	(0x22)
#define GAMMA_ADJUST3	(0x23)
#define GAMMA_ADJUST4	(0x24)
#define GAMMA_ADJUST5	(0x25)
#define GAMMA_ADJUST6	(0x26)
#define GAMMA_ADJUST7	(0x27)
#define GAMMA_ADJUST8	(0x28)
#define GAMMA_ADJUST9	(0x29)
	#define GAMMA_ADJUST_PV_MAX		(15)
	#define GAMMA_ADJUST_PV_MIN		(0)
	#define GAMMA_ADJUST_NV_MAX		(15)
	#define GAMMA_ADJUST_NV_MIN		(0)
		#define GAMMA_ADJUST_PV(v)	(v << 4)
		#define GAMMA_ADJUST_NV(v)	(v)	

#define ENGINEERING_TIMING_TABLE				(0x3F)
	#define ENGINEERING_TIMING_TABLE_DISABLE	(0x00)
	#define ENGINEERING_TIMING_TABLE_ENABLE		(0x08)

#define ENGINEERING_TIMING_TABLE_RESERVE		(0x40)
#define ENGINEERING_TIMING_TABLE_CK_P			(0x41)
#define ENGINEERING_TIMING_TABLE_CK3_CK2		(0x42)
#define ENGINEERING_TIMING_TABLE_EC				(0x43)
#define ENGINEERING_TIMING_TABLE_EL				(0x44)
#define ENGINEERING_TIMING_TABLE_PC				(0x45)
#define ENGINEERING_TIMING_TABLE_PH				(0x46)
#define ENGINEERING_TIMING_TABLE_FC				(0x47)
#define ENGINEERING_TIMING_TABLE_SC				(0x48)
#define ENGINEERING_TIMING_TABLE_CV_CH			(0x49)
#define ENGINEERING_TIMING_TABLE_CD				(0x4A)
#define ENGINEERING_TIMING_TABLE_SD				(0x4B)

#define SCREEN_RESOLUTION_X_MAX	(127)
#define SCREEN_RESOLUTION_Y_MAX	(159)

#define RGB(r, g, b) ((uint)(r << 11 | ((g << 1) | (g >> 4)) << 5 | b))
#define RGBMAX	(31)

// driver base function
extern void LCDInit();
extern void LCDRegisterWrite(byte addr, byte wdata);
extern void LCDRegisterRead(byte addr, byte *rdata);
extern void LCDMemoryWrite(uint wdata);
extern void LCDMemoryRead(uint *rdata);

#endif