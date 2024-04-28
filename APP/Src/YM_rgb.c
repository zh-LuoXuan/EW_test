#include "YM_rgb.h"
#include "YM_ccp.h"
#include "userlib.h"
#include "YM_dma.h"
#include "dma.h"
#include "timer.h"

#if CCP_IT_CHANS
uint32_t CamplaBuff[24] = {0};
#elif DMA_TGR_CHANS
uint32_t DMACamplaBuff[DMA_CCP_MAX_RECV_LEN] = {0};
#endif 

RGB_DataTypdef RGB_DataStracture;


/**
 * @brief �õ���ɫ����ģʽɫ��
 * 
 * @param [in] current����ǰ����ֵ, [in] breath_val������ģʽ���ۼ�(��)ֵ
 * 
 * @note breath_k��ֵӦ����[0:255]��
 * 
 * @return static uint32_t fdb �õ��º���ֵ
 */
static uint32_t get_white_breathRGB(uint32_t current, uint8_t breath_k)
{   
    static int8_t addSymbol = 1;
    static int16_t R = 0,
                   G = 0,
                   B = 0;   
    static uint32_t fdb = 0;  

    R = (int16_t) ((current >> 16) & 0xFF);
    G = (int16_t) ((current >> 8) & 0xFF);
    B = (int16_t) ((current >> 0) & 0xFF);

    if(current >= (uint32_t) WHITE)   
    addSymbol = -1;   
    if(current <= (uint32_t) 0)  
    addSymbol = 1;   
	
    R += addSymbol * breath_k;
    R = limit_int16(R, 255, 0);
    G += addSymbol * breath_k;
    G = limit_int16(R, 255, 0);
    B += addSymbol * breath_k;
    B = limit_int16(R, 255, 0);

    fdb = (uint32_t)(R << 16 | G << 8 | B << 0);   
    return fdb;   
}

/**
 * @brief �õ��Ƚ�ֵ����
 * 
 * @param [in] RGB�ṹ��ָ��
 * 
 * @return static void
 */
static void get_CamplarBuff(RGB_DataTypdef* RGB_Stracture)
{
    if(RGB_Stracture == NULL)
    {
        return;
    }
	uint8_t i;
#if CCP_IT_CHANS 
    for(i = 0; i < 24; i++)
        CamplaBuff[i] = GETCOMPLAR((RGB_DataStracture.ColorGRB >> (23 - i)) & 0x01);
#elif DMA_TGR_CHANS
    for(i = 0; i < 96; i++)
	{
		if(i < 24)
	    DMACamplaBuff[i] = GETCOMPLAR((RGB_DataStracture.ColorGRB >> (23 - i)) & 0x01);
		else if(i >= 24 && i < 48)
	    DMACamplaBuff[i] = GETCOMPLAR((RGB_DataStracture.ColorGRB >> (23 - (i - 24))) & 0x01);
		else if(i >= 48 && i < 72)
	    DMACamplaBuff[i] = GETCOMPLAR((RGB_DataStracture.ColorGRB >> (23 - (i - 48))) & 0x01);
		else if(i >= 72 && i < 96)
	    DMACamplaBuff[i] = GETCOMPLAR((RGB_DataStracture.ColorGRB >> (23 - (i - 72))) & 0x01);
	}
#endif 
}

/**
 * @brief �õ�GRBֵ��Ƚ�ֵ
 * 
 * @param [in] RGB�ṹ��ָ��
 * 
 * @return static void
 */
static void get_RGB_GRB_Camplar(RGB_DataTypdef* RGB_Stracture)
{
    RGB_Stracture->ColorGRB = RGBTOGRB(RGB_Stracture->ColorRGB[Current]);
    get_CamplarBuff(RGB_Stracture);
}


/**
 * @brief RGBģʽ����
 * 
 * @param [in] mode��Normal / Breath
 * 
 * @return void
 */
void RGB_Mode_Set(RGB_Mode_e mode)
{
    RGB_DataStracture.Mode[Current] = mode;
    RGB_Mode_Update(&RGB_DataStracture);
}

/**
 * @brief RGB��ɫ��������
 * 
 * @param [in]Color��White / Cyan / Purple
 * 
 * @return void
 */
void RGB_Color_Set(RGB_Color_e color)
{
    RGB_DataStracture.Color[Current] = color;
    RGB_Color_Update(&RGB_DataStracture);
}

/**
 * @brief RGB��ɫɫ������
 * 
 * @param [in]Color_RGB
 * 
 * @return void
 */
void RGB_ColorRGB_Set(uint32_t color_rgb)
{
    RGB_DataStracture.ColorRGB[Current] = color_rgb;
    RGB_ColorRGB_Update(&RGB_DataStracture);
}

/**
 * @brief RGB��Դ����״̬����
 * 
 * @param [in]power��Off / On
 * 
 * @return void
 */
void RGB_Power_Set(RGB_Power_e power)
{
    RGB_DataStracture.Power = power;
    RGB_Power_Update(&RGB_DataStracture);
}

/**
 * @brief ��������ʱ�Ը�ģ��Ŀ����Ӻ���
 * 
 * @param void
 * 
 * @return void
 */
void Update_Hook(void)
{
    RGB_DataStracture.Lock = Unlock;
    CCP_EnableRun(CCP0);			
    CCP_Start(CCP0);
    CCP->LOCK = CCP_P1A_WRITE_KEY;
}

/**
 * @brief RGBֵ����
 * 
 * @param [in] RGB_Stracture��RGB�ṹ��ָ��, [in] breath_val������ģʽ���ۼ�(��)ֵ
 * 
 * @note Ӧ���ں���ģʽ�¸��°�ɫRGBֵ��breath_val��ֵӦ����[0:255]��
 * 
 * @return void
 */
void RGB_Breath_Update(RGB_DataTypdef* RGB_Stracture, uint32_t breath_val)
{
    if(RGB_Stracture == NULL)
    {
        return;
    }

    if(breath_val > 255)
    breath_val = 255;
    else if(breath_val < 0)
    breath_val = 0;

    switch(RGB_Stracture->Mode[Current])
    {
        case Breath:
            if(RGB_Stracture->Color[Current] != White)
            {
                RGB_Stracture->Color[Current] = White;
                RGB_Stracture->ColorRGB[Current] = WHITE;
            }
            RGB_Stracture->ColorRGB[Current] = get_white_breathRGB(RGB_Stracture->ColorRGB[Current], breath_val);
			RGB_ColorRGB_Update(RGB_Stracture);
            Update_Hook();
            break;
        default:
            break;
    }
}

/**
 * @brief RGB��Դ����״̬����
 * 
 * @param [in] RGB�ṹ��ָ��
 * 
 * @return void
 */
void RGB_Power_Update(RGB_DataTypdef* RGB_Stracture)
{
    if(RGB_Stracture == NULL)
    {
        return;
    }
    switch(RGB_Stracture->Power)
	{
		case On:
			PORT_ClrBit(PORT2, PIN4);
			break;
		case Off:
		default:
			PORT_SetBit(PORT2, PIN4);
			break;
	}
    Update_Hook();
}

/**
 * @brief RGB��ɫ���Ÿ���
 * 
 * @param [in] RGB�ṹ��ָ��
 * 
 * @return void
 */
void RGB_Color_Update(RGB_DataTypdef* RGB_Stracture)
{
    if(RGB_Stracture == NULL)
    {
        return;
    }
    if(RGB_Stracture->Color[Last] != RGB_Stracture->Color[Current])
    {
        switch(RGB_Stracture->Color[Current])
        {
            case Cyan:
                RGB_Stracture->ColorRGB[Current] = CYAN;
                break;
            case Purple:
                RGB_Stracture->ColorRGB[Current] = PURPLE;
                break;
            case White:
                if(RGB_Stracture->Mode[Current] != Breath)
                    RGB_Stracture->ColorRGB[Current] = WHITE;
                break;
            default:
                RGB_Stracture->ColorRGB[Current] = WHITE;
                break;
        }
        get_RGB_GRB_Camplar(RGB_Stracture);
        Update_Hook();
        RGB_Stracture->Color[Last] = RGB_Stracture->Color[Current];
    } 
    if(RGB_Stracture->ColorRGB[Last] != RGB_Stracture->ColorRGB[Current])
    {
        RGB_Stracture->ColorRGB[Last] = RGB_Stracture->ColorRGB[Current];
    }           
}

/**
 * @brief RGBɫ����ֵ����
 * 
 * @param [in] RGB�ṹ��ָ��
 * 
 * @return void
 */
void RGB_ColorRGB_Update(RGB_DataTypdef* RGB_Stracture)
{
    if(RGB_Stracture == NULL)
    {
        return;
    }
    if(RGB_Stracture->ColorRGB[Last] != RGB_Stracture->ColorRGB[Current])
    {
        get_RGB_GRB_Camplar(RGB_Stracture);
        Update_Hook();
        RGB_Stracture->ColorRGB[Last] = RGB_Stracture->ColorRGB[Current];	
    }
}

/**
 * @brief RGBģʽ����
 * 
 * @param [in] RGB�ṹ��ָ��
 * 
 * @return void
 */
void RGB_Mode_Update(RGB_DataTypdef* RGB_Stracture)
{
    if(RGB_Stracture == NULL)
    {
        return;
    }
    if(RGB_Stracture->Mode[Last] != RGB_Stracture->Mode[Current])
    {
        switch(RGB_Stracture->Mode[Current])
        {
            case Breath:
                if(RGB_Stracture->Color[Current] != White)
                {
                    RGB_Stracture->Color[Current] = White;
                    RGB_Stracture->ColorRGB[Current] = WHITE;
                }
                break;
            case Normal:
                switch(RGB_Stracture->Color[Current])
                {
                    case Cyan:
                        RGB_Stracture->ColorRGB[Current] = CYAN;
                        break;
                    case Purple:
                        RGB_Stracture->ColorRGB[Current] = PURPLE;
                        break;
                    case White:
                        if(RGB_Stracture->Mode[Current] != Breath)
                            RGB_Stracture->ColorRGB[Current] = WHITE;
                        break;
                    default:
                        RGB_Stracture->ColorRGB[Current] = WHITE;
                        break;
                }
            default:
                break;
        }
        get_RGB_GRB_Camplar(RGB_Stracture);
        Update_Hook();
        RGB_Stracture->Mode[Last] = RGB_Stracture->Mode[Current];
    }
    if(RGB_Stracture->ColorRGB[Last] != RGB_Stracture->ColorRGB[Current])
    {
        RGB_Stracture->ColorRGB[Last] = RGB_Stracture->ColorRGB[Current];
    }           
}

/**
 * @brief RGB״̬������
 * 
 * @param [in] RGB�ṹ��ָ��
 * 
 * @return void
 */
void RGB_Status_Update(RGB_DataTypdef* RGB_Stracture)
{
    if(RGB_Stracture == NULL)
    {
        return;
    }
	RGB_Power_Update(RGB_Stracture);
    RGB_Color_Update(RGB_Stracture);    
    RGB_Mode_Update(RGB_Stracture);    
    RGB_ColorRGB_Update(RGB_Stracture);  
}

/**
 * @brief RGB���ݳ�ʼ��
 * 
 * @param [in] RGB�ṹ��ָ��
 * 
 * @return static void
 */
static void RGB_DataInit(RGB_DataTypdef* RGB_Stracture)
{
    if(RGB_Stracture == NULL)
    {
        return;
    }
#if CCP_IT_CHANS 
    RGB_Stracture->RGB_CCPBuff = CamplaBuff;
#elif DMA_TGR_CHANS
	RGB_Stracture->RGB_DMABuff = DMACamplaBuff;
#endif
    RGB_Stracture->Lock = Unlock;
	RGB_Stracture->Power = On;
    RGB_Stracture->Color[Current] = White;
    RGB_Stracture->SendState = Busy;
    get_RGB_GRB_Camplar(RGB_Stracture);
    RGB_Mode_Set(Normal);
    RGB_Status_Update(RGB_Stracture);
}

/**
 * @brief RGB��ʼ������
 * 
 * @param [in] RGB�ṹ��ָ��
 * 
 * @return void
 */
void RGB_Init_Config(void)
{
	GPIO_Init(PORT2, PIN4, OUTPUT);
	PORT_SetBit(PORT2, PIN4);
    RGB_DataInit(&RGB_DataStracture);
}

