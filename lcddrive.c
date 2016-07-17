#include <basetypehelp.h>
#include <lcddrive.h>

static void delay(uint s)
{
	byte k;
	while (s--) for (k = 0; k < 255; k++);
}

void LCDInit()
{
	LCD_CS = 0;
	LCD_RS = 0;
	LCD_WR = 0;
	LCD_RD = 0;
	LCD_RST = 0;
	delay(1);
	LCD_RST = 1;
	delay(40);  // >= 100 us

	LCDRegisterWrite(MODE_SEL4, RGB_INTERFACE_MODE_DE | SYNC_POLARITY_NEGATIVE | INPUT_DATA_MAPPING_16BIT | INPUT_MODE_MOVING);
	LCDRegisterWrite(SRAM_PWS_X, 0x00);
	LCDRegisterWrite(SRAM_PWS_Y, 0x00);
	LCDRegisterWrite(SRAM_PWE_X, SCREEN_RESOLUTION_X_MAX);
	LCDRegisterWrite(SRAM_PWE_Y, SCREEN_RESOLUTION_Y_MAX);
	LCDRegisterWrite(SRAM_POS_X, 0x00);
	LCDRegisterWrite(SRAM_POS_Y, 0x00);
	LCDRegisterWrite(SRAM_CONTROL, 0x00);
 	LCDRegisterWrite(DAC_OP_CTRL2, DCDC_VPOWER_INPUT_INTERNAL_REGISTER | PWDN_AVDD1_AVDD2_POWER_ON | DAC_BIAS_100 | VCOM_BIAS_NORMAL | RGB_LOAD_10D5P);
}

void LCDRegisterWrite(byte addr, byte wdata)
{
	LCD_CS = 0;
	LCD_RS = 0;
	LCD_WR = 0;
	LCD_RD = 1;
	LCD_DATA_PORT = addr;
	LCD_WR = 1;
	LCD_RS = 1;
	LCD_WR = 0;
	LCD_DATA_PORT = wdata;
	LCD_WR = 1;
	LCD_CS = 1;
}

void LCDRegisterRead(byte addr, byte *rdata)
{
	LCD_CS = 0;
	LCD_RS = 0;
	LCD_WR = 0;
	LCD_RD = 1;
	LCD_DATA_PORT = addr;
	LCD_WR = 1;
	LCD_RS = 1;
	LCD_RD = 0;
	LCD_DATA_PORT = 0xFF;
	*rdata = LCD_DATA_PORT;
	LCD_RD = 1;
	LCD_CS = 1;
}

void LCDMemoryWrite(uint wdata)
{
	LCD_CS = 0;
	LCD_RS = 1;
	LCD_WR = 0;
	LCD_RD = 1;
	LCD_DATA_PORT = (byte)(wdata >> 8);
	LCD_WR = 1;
	LCD_WR = 0;
	LCD_DATA_PORT = (byte)wdata;
	LCD_WR = 1;
	LCD_CS = 1;
}

void LCDMemoryRead(uint *rdata)
{
	LCD_CS = 0;
	LCD_RS = 1;
	LCD_WR = 1;
 	LCD_RD = 0;
 	LCD_RD = 1;

 	LCD_RD = 0;
 	LCD_RD = 1;

	LCD_RD = 0;
	LCD_DATA_PORT = 0xFF;
	*rdata = LCD_DATA_PORT;
	LCD_RD = 1;

	LCD_RD = 0;
	LCD_DATA_PORT = 0xFF;
	*rdata = ((*rdata) << 8) | LCD_DATA_PORT;
	LCD_RD = 1;

	LCD_CS = 1;
}