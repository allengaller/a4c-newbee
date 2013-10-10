/***************include file**********************/
#include <stdio.h>
#include <stdlib.h>
#include "nexus_types.h"
#include "nexus_platform.h"
#include "bstd.h"
#include "bkni.h"
#include "nexus_i2c.h"
#include "priv/nexus_i2c_priv.h"

#define 	CHIPADDR       0X34




static void init_platform(void)
{
    
    NEXUS_I2cSettings pSettings;
  
    NEXUS_PlatformSettings platformSettings;
    NEXUS_Platform_GetDefaultSettings(&platformSettings); 
    platformSettings.openFrontend = false;

    NEXUS_Platform_Init(&platformSettings); 
}


static NEXUS_I2cHandle init_i2c(void)
{
	
	NEXUS_I2cHandle i2c;
	NEXUS_PlatformConfiguration platformConfig;
	NEXUS_Platform_GetConfiguration(&platformConfig);
   i2c = platformConfig.i2c[0];
	return i2c;
}

void Write_Max()
{
	NEXUS_Error err;
	NEXUS_I2cHandle i2c;
	uint8_t setup_data = 0xA2;
    uint8_t config_data = 0x61;
	i2c = init_i2c();	
	if(NULL==i2c){
		printf("i2c handle is null\n");
	}	
	else{	
	    err =  NEXUS_I2c_WriteNoAddr(i2c,CHIPADDR,&setup_data,1);
	    err =  NEXUS_I2c_WriteNoAddr(i2c,CHIPADDR,&config_data,1);
	}
	
	 if(0!=err)
	 {
        printf("=========================write============================ \n");
	 }
	
	
}

void Read_Max()
{


	NEXUS_Error err;
	NEXUS_I2cHandle i2c;
	#if 0
	uint16_t *read_dat;
	#endif
	int i =0;
	int ret = 0;
   unsigned char read_dat[2] ={0} ;
	int data[10]={0};
	i2c = init_i2c();
   if(NULL==i2c){
		printf("i2c handle is null\n");
	}	
	else{
	   for(i=0;i<10;i++){
		err = NEXUS_I2c_ReadNoAddr(i2c,CHIPADDR,read_dat,2);
		ret+= (int)(((read_dat[0]&0X0F)<<8)|read_dat[1]);
		printf("[ret]:%d\n",ret);
		}
	 }
	 if(0!=err)
	 {
        printf("============================read========================= \n");
	 }
    
        return(ret/10);
}

int main(void)
{ 
	 init_platform();
	 Write_Max();
	 /*while(1){*/
	 Read_Max();
	/*}*/
	/**********************
	NEXUS_Error err;
	NEXUS_I2cHandle i2c;
	NEXUS_PlatformConfiguration platformConfig;
	NEXUS_Platform_GetConfiguration(&platformConfig);
   i2c = platformConfig.i2c[0];

   uint8_t tmp;	

	while(1){
	err =  NEXUS_I2c_Read(i2c,0x68,0x02,&tmp,1);
	
}*********************/
    
   
	NEXUS_Platform_Uninit();
	return 0;
}



