/***************************************************
 * File:hx83112b_drivers_s4322.h
 * VENDOR_EDIT
 * Copyright(C) 2008-2012 OPPO Mobile Comm Corp., Ltd
 * Description:
 *             hx83112b s4322 driver
 * Version:1.0:
 * Date created:2017/04/17
 * Author: MingQiang.Guo@Bsp.Driver
 * TAG: BSP.TP.Init
 * *
 * -------------- Revision History: -----------------
   <author >  <data>  <version>  <desc>
****************************************************/

#ifndef HX83112B_H
#define HX83112B_H

/*********PART1:Head files**********************/
#include <linux/i2c.h>
#ifdef CONFIG_FB
#include <linux/fb.h>
#include <linux/notifier.h>
#endif
#ifdef CONFIG_SPI_MT65XX
#include <linux/platform_data/spi-mt65xx.h>
#endif
#include "../himax_common.h"
#ifdef CONFIG_TOUCHPANEL_MTK_PLATFORM
#include "mtk_gpio.h"
#else
#include "oppo_spi.h"
#endif

#define HX_ZERO_FLASH

/*********PART2:Define Area**********************/
#define ENABLE_UNICODE    0x40
#define ENABLE_VEE        0x20
#define ENABLE_CIRCLE     0x08
#define ENABLE_SWIPE      0x02
#define ENABLE_DTAP       0x01

#define UNICODE_DETECT    0x0b
#define VEE_DETECT        0x0a
#define CIRCLE_DETECT     0x08
#define SWIPE_DETECT      0x07
#define DTAP_DETECT       0x03

#define RESET_TO_NORMAL_TIME         2    /*Sleep time after reset*/

#define SPURIOUS_FP_LIMIT            100
#define SPURIOUS_FP_RX_NUM           8
#define SPURIOUS_FP_TX_NUM           9
#define SPURIOUS_FP_BASE_DATA_RETRY  10

#define I2C_ERROR_MAX_TIME           5

#define HX_32K_SZ 0x8000
#define FOUR_BYTE_ADDR_SZ     4

#define EXTEND_EE_SHORT_RESET_DUR    60
#define EXTEND_EE_SHORT_INT_DUR      150
#define EXTEND_EE_SHORT_TX_ON_COUNT  146
#define EXTEND_EE_SHORT_RX_ON_COUNT  146
#define EXTEND_EE_SHORT_TEST_LIMIT_PART1    160
#define EXTEND_EE_SHORT_TEST_LIMIT_PART2    80         // ( unit = ratio )

/* tddi f54 test reporting - */
#define ELEC_OPEN_TEST_TX_ON_COUNT      2
#define ELEC_OPEN_TEST_RX_ON_COUNT      2
#define ELEC_OPEN_INT_DUR_ONE           15
#define ELEC_OPEN_INT_DUR_TWO           25
#define ELEC_OPEN_TEST_LIMIT_ONE        500
#define ELEC_OPEN_TEST_LIMIT_TWO        50

#define COMMAND_FORCE_UPDATE            4

//#define UPDATE_DISPLAY_CONFIG

//Self Capacitance key test limite
#define MENU_LOW_LIMITE        1630
#define MENU_HIGH_LIMITE       3803

#define BACK_LOW_LIMITE        3016
#define BACK_HIGH_LIMITE       7039

#define TEST_FAIL    1
#define TEST_PASS    0

#define LIMIT_DOZE_LOW     50
#define LIMIT_DOZE_HIGH    975

//gmq-himax

#define HX64K	0x10000
#define FW_BIN_16K_SZ 0x4000
struct touchpanel_data *private_ts;
int g_f_0f_updat = 0; 

/**COMMON USE   ***START***/
unsigned long FW_VER_MAJ_FLASH_ADDR;
unsigned long FW_VER_MIN_FLASH_ADDR;
unsigned long CFG_VER_MAJ_FLASH_ADDR;
unsigned long CFG_VER_MIN_FLASH_ADDR;
unsigned long CID_VER_MAJ_FLASH_ADDR;
unsigned long CID_VER_MIN_FLASH_ADDR;
unsigned long FW_VER_MAJ_FLASH_LENG;
unsigned long FW_VER_MIN_FLASH_LENG;
unsigned long CFG_VER_MAJ_FLASH_LENG;
unsigned long CFG_VER_MIN_FLASH_LENG;
unsigned long CID_VER_MAJ_FLASH_LENG;
unsigned long CID_VER_MIN_FLASH_LENG;
unsigned long FW_CFG_VER_FLASH_ADDR;
uint8_t HX_PROC_SEND_FLAG;

struct proc_dir_entry *himax_proc_register_file = NULL;
uint8_t byte_length = 0;
uint8_t register_command[4];
bool cfg_flag = false;

//#ifdef HX_ESD_RECOVERY
u8 HX_ESD_RESET_ACTIVATE;
int hx_EB_event_flag;
int hx_EC_event_flag;
int hx_ED_event_flag;
//#endif

bool HX_RESET_STATE = false;

unsigned char IC_TYPE = 11;
unsigned char IC_CHECKSUM = 0;
bool DSRAM_Flag = false;
int g_diag_command = 0;
uint8_t diag_coor[128];// = {0xFF};
int32_t diag_self[100] = {0};

int g_max_mutual = 0;
int g_min_mutual = 255;
int g_max_self = 0;
int g_min_self = 255;

int mutual_set_flag = 0;
uint8_t cmd_set[8];

/**GESTURE_TRACK*/
static int gest_pt_cnt;
static int gest_pt_x[10];
static int gest_pt_y[10];


#define HX_KEY_MAX_COUNT             4
#define DEFAULT_RETRY_CNT            3
#define HIMAX_REG_RETRY_TIMES        10

#define HX_83112A_SERIES_PWON        16
#define HX_83112B_SERIES_PWON        17

#define HX_TP_BIN_CHECKSUM_SW        1
#define HX_TP_BIN_CHECKSUM_HW        2
#define HX_TP_BIN_CHECKSUM_CRC       3

#define SHIFTBITS 5

#define  FW_SIZE_64k          65536
#define  FW_SIZE_128k         131072

#define NO_ERR                0
#define READY_TO_SERVE        1
#define WORK_OUT              2
#define I2C_FAIL              -1
#define MEM_ALLOC_FAIL        -2
#define CHECKSUM_FAIL         -3
#define GESTURE_DETECT_FAIL   -4
#define INPUT_REGISTER_FAIL   -5
#define FW_NOT_READY          -6
#define LENGTH_FAIL           -7
#define OPEN_FILE_FAIL        -8
#define ERR_WORK_OUT          -10

#define HX_FINGER_ON          1
#define HX_FINGER_LEAVE       2

#define HX_REPORT_COORD       1
#define HX_REPORT_SMWP_EVENT  2

//gesture head information
#define GEST_PTLG_ID_LEN     (4)
#define GEST_PTLG_HDR_LEN    (4)
#define GEST_PTLG_HDR_ID1    (0xCC)
#define GEST_PTLG_HDR_ID2    (0x44)
#define GEST_PT_MAX_NUM      (128)

#define BS_RAWDATANOISE      10
#define    BS_OPENSHORT      0

#define    SKIPRXNUM         31
/**COMMON USE*********END***/

/** FOR DEBUG USE*****START***/
typedef enum
{
    DEBUG_DATA_BASELINE = 0x08,
    DEBUG_DATA_DELTA    = 0x09,
    DEBUG_DATA_RAW      = 0x0A,
}DEBUG_DATA_TYPE;

//self test use
typedef enum
{
    HIMAX_INSPECTION_OPEN,
    HIMAX_INSPECTION_MICRO_OPEN,
    HIMAX_INSPECTION_SHORT,
    HIMAX_INSPECTION_RAWDATA,
    HIMAX_INSPECTION_NOISE,
    HIMAX_INSPECTION_SORTING,
    HIMAX_INSPECTION_BACK_NORMAL,
    HIMAX_INSPECTION_DOZE_RAWDATA,
    HIMAX_INSPECTION_DOZE_NOISE,
    HIMAX_INSPECTION_LPWUG_RAWDATA,
    HIMAX_INSPECTION_LPWUG_NOISE,
    HIMAX_INSPECTION_LPWUG_IDLE_RAWDATA,
    HIMAX_INSPECTION_LPWUG_IDLE_NOISE,
}THP_INSPECTION_ENUM;

/* Error code of AFE Inspection */
typedef enum
{
    RESULT_OK = 0,
    RESULT_ERR,
    RESULT_RETRY,
}RETURN_RESLUT;

typedef enum
{
    SKIPTXNUM_START = 6,
    SKIPTXNUM_6 = SKIPTXNUM_START,
    SKIPTXNUM_7,
    SKIPTXNUM_8,
    SKIPTXNUM_9,
    SKIPTXNUM_END = SKIPTXNUM_9,
}SKIPTXNUMINDEX;

char* g_himax_inspection_mode[]=
{
    "HIMAX_INSPECTION_OPEN",
    "HIMAX_INSPECTION_MICRO_OPEN",
    "HIMAX_INSPECTION_SHORT",
    "HIMAX_INSPECTION_RAWDATA",
    "HIMAX_INSPECTION_NOISE",
    "HIMAX_INSPECTION_SORTING",
    "HIMAX_INSPECTION_BACK_NORMAL",
    "HIMAX_INSPECTION_LPWUG_RAWDATA",
    "HIMAX_INSPECTION_LPWUG_NOISE",
    "HIMAX_INSPECTION_DOZE_RAWDATA",
    "HIMAX_INSPECTION_DOZE_NOISE",
    "HIMAX_INSPECTION_LPWUG_IDLE_RAWDATA",
    "HIMAX_INSPECTION_LPWUG_IDLE_NOISE",
};

/* Error code of AFE Inspection */
typedef enum
{
    THP_AFE_INSPECT_OK      = 0,               /* OK */
    THP_AFE_INSPECT_ESPI    = (1 << 0),        /* SPI communication error */
    THP_AFE_INSPECT_ERAW    = (1 << 1),        /* Raw data error */
    THP_AFE_INSPECT_ENOISE  = (1 << 2),        /* Noise error */
    THP_AFE_INSPECT_EOPEN   = (1 << 3),        /* Sensor open error */
    THP_AFE_INSPECT_EMOPEN  = (1 << 4),        /* Sensor micro open error */
    THP_AFE_INSPECT_ESHORT  = (1 << 5),        /* Sensor short error */
    THP_AFE_INSPECT_ERC     = (1 << 6),        /* Sensor RC error */
    THP_AFE_INSPECT_EPIN    = (1 << 7),        /* Errors of TSVD!FTSHD!FTRCST!FTRCRQ and other PINs
                                                  when Report Rate Switching between 60 Hz and 120 Hz */
    THP_AFE_INSPECT_EOTHER  = (1 << 8)         /* All other errors */
} THP_AFE_INSPECT_ERR_ENUM;


//Himax MP Limit
/*#define RAWMIN         3547*0.05
#define RAWMAX         5352*0.9*/
#define RAWMIN         906
#define RAWMAX         16317
#define SHORTMIN       0
#define SHORTMAX       150
#define OPENMIN        50
#define OPENMAX        500
#define M_OPENMIN      0
#define M_OPENMAX      150
#define NOISEFRAME     BS_RAWDATANOISE+40
#define NOISE_P        256 //gmqtest
#define UNIFMAX        500

//Himax MP Password
#define PWD_OPEN_START      0x77
#define PWD_OPEN_END        0x88
#define PWD_SHORT_START     0x11
#define PWD_SHORT_END       0x33
#define PWD_RAWDATA_START   0x00
#define PWD_RAWDATA_END     0x99
#define PWD_NOISE_START     0x00
#define PWD_NOISE_END       0x99
#define PWD_SORTING_START   0xAA
#define PWD_SORTING_END     0xCC

//Himax DataType
#define DATA_OPEN           0x0B
#define DATA_MICRO_OPEN     0x0C
#define DATA_SHORT          0x0A
#define DATA_RAWDATA        0x0A
#define DATA_NOISE          0x0F
#define DATA_BACK_NORMAL    0x00
#define DATA_LPWUG_RAWDATA  0x0C
#define DATA_LPWUG_NOISE    0x0F
#define DATA_DOZE_RAWDATA   0x0A
#define DATA_DOZE_NOISE     0x0F
#define DATA_LPWUG_IDLE_RAWDATA    0x0A
#define DATA_LPWUG_IDLE_NOISE      0x0F

//Himax Data Ready Password
#define Data_PWD0    0xA5
#define Data_PWD1    0x5A

static uint16_t NOISEMAX;
static uint16_t LPWUG_NOISEMAX;

#define BS_LPWUG           1
#define BS_DOZE            1
#define BS_LPWUG_dile      1

#define LPWUG_NOISE_MAX          100
#define LPWUG_NOISE_MIN          0
#define LPWUG_RAWDATA_MAX        15000
#define LPWUG_RAWDATA_MIN        0
#define DOZE_NOISE_MAX           100
#define DOZE_NOISE_MIN           0
#define DOZE_RAWDATA_MAX         9999
#define DOZE_RAWDATA_MIN         0
#define LPWUG_IDLE_NOISE_MAX     100
#define LPWUG_IDLE_NOISE_MIN     0
#define LPWUG_IDLE_RAWDATA_MAX   15000
#define LPWUG_IDLE_RAWDATA_MIN   0

#define PWD_NONE                 0x00
#define PWD_LPWUG_START          0x55
#define PWD_LPWUG_END            0x66
#define PWD_DOZE_START           0x22
#define PWD_DOZE_END             0x44
#define PWD_LPWUG_IDLE_START     0x50
#define PWD_LPWUG_IDLE_END       0x60

#define SKIP_NOTCH_START         5
#define SKIP_NOTCH_END           10
#define SKIP_DUMMY_START         23    //TX+SKIP_NOTCH_START
#define SKIP_DUMMY_END           28 // TX+SKIP_NOTCH_END

/** FOR DEBUG USE ****END****/

struct himax_report_data
{
    int touch_all_size;
    int raw_cnt_max;
    int raw_cnt_rmd;
    int touch_info_size;
    uint8_t finger_num;
    uint8_t finger_on;
    uint8_t *hx_coord_buf;
    uint8_t hx_state_info[2];

    int event_size;
    uint8_t *hx_event_buf;

    int rawdata_size;
    uint8_t diag_cmd;
    uint8_t *hx_rawdata_buf;
    //uint32_t *diag_mutual;
    int32_t *diag_mutual;
    uint8_t rawdata_frame_size;
};

/*********PART3:Struct Area**********************/

struct chip_data_hx83112b {
    uint32_t *p_tp_fw;
    tp_dev tp_type;
    struct himax_proc_operations *syna_ops; /*hx83112b func provide to hx83112b common driver*/

    struct hw_resource *hw_res;
    int16_t *spuri_fp_data;
    struct spurious_fp_touch *p_spuri_fp_touch;
/********SPI bus*******************************/	
	struct spi_device	*hx_spi;
	int 				hx_irq;
#ifdef CONFIG_TOUCHPANEL_MTK_PLATFORM
	struct mtk_chip_config hx_spi_mcc;
#else
    struct mt_chip_conf    hx_spi_mcc;
#endif
/********SPI bus*******************************/
#ifdef HX_ZERO_FLASH
    struct mutex             spi_lock;
    struct workqueue_struct  *himax_0f_update_wq;
    struct delayed_work      work_0f_update;
    struct firmware_headfile *p_firmware_headfile;
    const struct firmware    *g_fw_entry;
    uint8_t *tmp_data;
#endif
    uint8_t     touch_direction;    //show touchpanel current direction
    bool        using_headfile;
    bool        first_download_finished;
};

/*********PART4:ZERO FLASH**********************/
#if defined(HX_ZERO_FLASH)
#define HX_0F_DEBUG
#define HX_48K_SZ 0xC000
#define MAX_TRANS_SZ    240     /*MTK:240_WRITE_limit*/
#define MAX_RECVS_SZ    56      /*MTK:56_READ_limit*/

#define zf_addr_dis_flash_reload              0x10007f00
#define zf_data_dis_flash_reload              0x00009AA9
#define zf_addr_system_reset                 0x90000018
#define zf_data_system_reset                 0x00000055
#define zf_data_sram_start_addr              0x08000000
#define zf_data_sram_clean             0x10000000
#define zf_data_cfg_info             0x10007000
#define zf_data_fw_cfg_p1             0x10007084
#define zf_data_fw_cfg_p2             0x10007264
#define zf_data_fw_cfg_p3             0x10007300
#define zf_data_adc_cfg_1             0x10006A00
#define zf_data_adc_cfg_2             0x10007B28
#define zf_data_adc_cfg_3             0x10007AF0
#define zf_data_map_table             0x10007500
#define zf_data_mode_switch             0x10007294

struct zf_operation {
	uint8_t addr_dis_flash_reload[4];
	uint8_t data_dis_flash_reload[4];
	uint8_t addr_system_reset[4];
	uint8_t data_system_reset[4];
	uint8_t data_sram_start_addr[4];
	uint8_t data_sram_clean[4];
	uint8_t data_cfg_info[4];
	uint8_t data_fw_cfg[4];
	uint8_t data_fw_cfg_p1[4];
	uint8_t data_fw_cfg_p2[4];
	uint8_t data_fw_cfg_p3[4];
	uint8_t data_adc_cfg_1[4];
	uint8_t data_adc_cfg_2[4];
	uint8_t data_adc_cfg_3[4];
	uint8_t data_map_table[4];
	uint8_t data_mode_switch[4];
};
struct zf_info{
	uint8_t sram_addr[4];
	int write_size;
	uint32_t fw_addr;
	uint32_t cfg_addr;
};


struct himax_core_fp {
	int (*fp_reload_disable)(int disable);
	void (*fp_sys_reset)(void);
	void (*fp_clean_sram_0f)(uint8_t *addr, int write_len, int type);
	void (*fp_write_sram_0f)(const struct firmware *fw_entry, uint8_t *addr, int start_index, uint32_t write_len);
	void (*fp_firmware_update_0f)(const struct firmware *fw_entry);
	int (*fp_0f_operation_dirly)(void);
	int (*fp_0f_op_file_dirly)(char *file_name);
	void (*fp_0f_operation)(struct work_struct *work);
#ifdef HX_0F_DEBUG
	void (*fp_read_sram_0f)(const struct firmware *fw_entry, uint8_t *addr, int start_index, int read_len);
	void (*fp_read_all_sram)(uint8_t *addr, int read_len);
	void (*fp_firmware_read_0f)(const struct firmware *fw_entry, int type);
	void (*fp_0f_operation_check)(int type);
#endif
};
#endif

#endif
