/*
 * =============================================================================
 *                                                                             * 
 *       Filename:  smg1210_xml_parse_to_struct.c                              * 
 *                                                                             * 
 *    Description:  xml parsing main functional module                         * 
 *                                                                             *     
 *        Version:  1.0                                                        * 
 *        Created:  2010/05/07 9:17:30                                         * 
 *       Revision:  none                                                       * 
 *       Compiler:  gcc                                                        *     
 *                                                                             * 
 *         Author:  Allen Galler 曹亚仑                                         *   
 *                  allengaller@gmail.com                                      * 
 *                                                                             * 
 *        Company:  BVCOM Gorp.                                                * 
 *                                                                             * 
 * =============================================================================
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<libxml/xmlmemory.h>
#include<libxml/parser.h>
#include<libxml/xmlmemory.h>

#include "smg1210_xml_parse_to_struct.h"    //xml parse function declear
#include "smg1210_xml_packing.h"            //xml packing module head file

#include "tsc_demo_define.h"

/*The replay struct.This global struct stores the info that packing mudule needs*/
//cmd_r my_cmd_query_prog_r;
cmd_query_prog_r my_cmd_query_prog_r;

/*SrcCode and DstCode change place from each other here*/
void swap_srccode_dstcode(char* srccode_orig, char* dstcode_orig)
{
    #if 0
    /*Swap algorism parameter*/
    char* swap;

    swap = malloc(strlen(my_cmd_query_prog_r.SrcCode)+1);
    srccode_orig = malloc(strlen(my_cmd_query_prog_r.SrcCode)+1);
    dstcode_orig = malloc(strlen(my_cmd_query_prog_r.DstCode)+1);

    /*Save to original value for comparing*/
    strcpy(srccode_orig , my_cmd_query_prog_r.SrcCode);     
    strcpy(dstcode_orig , my_cmd_query_prog_r.DstCode);
    
    /*Swap*/
    strcpy(swap , srccode_orig);
    strcpy(srccode_orig, dstcode_orig);
    strcpy(dstcode_orig , swap);

    strcpy(my_cmd_query_prog_r.SrcCode, srccode_orig);     
    strcpy(my_cmd_query_prog_r.DstCode, dstcode_orig);

    /*Free memory space that vars used*/    
    free(swap);
    free(srccode_orig);
    free(dstcode_orig);

    if(!(strcmp(my_cmd_query_prog_r.SrcCode, dstcode_orig) && strcmp(my_cmd_query_prog_r.DstCode, srccode_orig)))
    {
        printf("\n  SrcCode DstCode swap done!  \n");
        #if 0
        /*Marking the original value of SrcCode and DstCode*/
        printf("    my_cmd_query_prog_r: ORIG SrcCode:  %s\n",   my_cmd_query_prog_r.SrcCode);
        printf("    my_cmd_query_prog_r: ORIG DstCode:  %s\n",   my_cmd_query_prog_r.DstCode);
        
        /*Marking the value ofMarks处理后的SrcCode, DstCode*/
        printf("    my_cmd_query_prog_r: SrcCode:      %s\n",   my_cmd_query_prog_r.SrcCode);
        printf("    my_cmd_query_prog_r: DstCode:      %s\n",   my_cmd_query_prog_r.DstCode);
        #endif   
    }
    #endif
}


/*******************************************************************************
 *   smg1210_cmd_module* get_risc_module_value(smg1210_cmd_module* cmd_module, *
 *                                               xmlDocPtr doc, xmlNodePtr cur)*
 *   INTERFACE:                                                                *
 *       struct smg1210_cmd_module* cmd_module:                                * 
 *       xmlDocPtr doc: Doc pointer for libxml2 parsing.                       * 
 *       xmlNodePtr cur: Node pointer for libxml2 parsing.                     * 
 *   USAGE:                                                                    * 
 *       Get the prop value of Module while the prop value of CellName is RISC.* 
 *   RETURN:                                                                   * 
 *       struct smg1210_cmd_module: Contains info of Module Node               *
 *******************************************************************************/
smg1210_cmd_module* get_risc_module_value(smg1210_cmd_module* cmd_module, xmlDocPtr doc, xmlNodePtr cur)
{
    /*set_param contains all kinds of param that tsc need*/
    set_param set_info;
    Tuner_Param_c tuner_info;
    
    /*xmlChar equals unsigned char */
    xmlChar *ModuleName;
    xmlChar *ModuleValue;
        
    printf("\n[Receive]Get module.\n");
    
    //unsigned int module_cnt = 0;
    
	/*Move current node pointer to child node*/    
	cur = cur->xmlChildrenNode;
    
	while(cur != NULL)
    {
        if((!xmlStrcmp(cur->name, (const xmlChar *)"Module")))	
	    {
	        //Get Nameprop value.
	        ModuleName = xmlGetProp(cur, "Name");	
	        if(!strcmp(ModuleName, (const xmlChar *)"IP地址")){
	            cmd_module->i_type = SMG1210_RISC_IP_ADDRESS_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
#if 0
                /*if ModuleValue is int then device use cmd_module->i_valuem 
                  otherwise use cmd_module->s_origin_value*/
                if(atoi(ModuleValue) == ModuleValue){
                    cmd_module->i_value =  atoi(ModuleValue);
                    /* Setting to config file */
                    set_info.ip_addr = cmd_module->i_value;
                    tsc_ip_addr_setting(&set_info);
                    set_ip_addr_cfg(&set_info);
                } else {
                    strcpy(cmd_module->s_origin_value,ModuleValue);
                    /* Setting to config file */
                    set_info.ip_addr = cmd_module->i_value;
                    tsc_ip_addr_setting(&set_info);
                    set_ip_addr_cfg(&set_info);
                }
#endif
		cmd_module->i_value =  atoi(ModuleValue);
                /* Setting to config file */
                set_info.ip_addr = cmd_module->i_value;
                tsc_ip_addr_setting(&set_info);
                set_ip_addr_cfg(&set_info);

                printf("[Receive]Module IP地址 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"子网掩码")){
	            cmd_module->i_type = SMG1210_RISC_SUBNET_MASK_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                }
                printf("[Receive]Module 子网掩码 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "网关地址")){
	            cmd_module->i_type = SMG1210_RISC_GATEWAY_ADDRESS_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 网关地址 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "MAC地址")){
	            cmd_module->i_type = SMG1210_RISC_MAC_ADDRESS_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module MAC地址 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "设备型号")){
	            cmd_module->i_type = SMG1210_RISC_DEVICE_TYPE_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 设备型号 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "产品序号")){
	            cmd_module->i_type = SMG1210_RISC_PRODUCT_SERIAL_NUMBER_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                strcpy(cmd_module->s_origin_value , ModuleValue);
                /*Formatting module value then store it to down stream struct*/
                cmd_module->i_value =  atoi(ModuleValue);
                printf("[Receive]Module 产品序号 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "硬件版本号")){
	            cmd_module->i_type = SMG1210_RISC_HARDWARE_VERSION_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 硬件版本号 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"软件版本号")){
	            cmd_module->i_type = SMG1210_RISC_SOFTWARE_VERSION_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 软件版本号 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "系统时间")){
	            cmd_module->i_type = SMG1210_RISC_SYS_TIME_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 系统时间 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "系统运行时间")){
	            cmd_module->i_type = SMG1210_RISC_SYS_RUN_TIME_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 系统运行时间： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"系统的工作状态")){
	            cmd_module->i_type = SMG1210_RISC_SYS_STATUS_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 系统的工作状态 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "CPU整体占用率")){
	            cmd_module->i_type = SMG1210_RISC_CPU_UTILIZATION_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module CPU整体占用率 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *)"进程数")){
	            cmd_module->i_type = SMG1210_RISC_THREAD_COUNT_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 进程数 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "内存总容量")){
	            cmd_module->i_type = SMG1210_RISC_MEM_TOTAL_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 内存总容量 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "内存可用容量")){
	            cmd_module->i_type = SMG1210_RISC_MEM_FREE_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 内存可用容量 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "报警级别")){
	            cmd_module->i_type = SMG1210_RISC_ALERT_LEVEL_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 报警级别 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "最高温度")){
	            cmd_module->i_type = SMG1210_RISC_MAX_TMP_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 最高温度 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "最低温度")){
	            cmd_module->i_type = SMG1210_RISC_MIN_TMP_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 最低温度 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "板卡温度值")){
	            cmd_module->i_type = SMG1210_RISC_ICB_TMP_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value = atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 板卡温度值 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"升级文件类型")){
	            cmd_module->i_type = SMG1210_RISC_UPDATE_FILE_TYPE_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 升级文件类型 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "升级文件路径")){
	            cmd_module->i_type = SMG1210_RISC_UPDATE_FILE_PATH_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 升级文件路径 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "子模块复位")){
	            cmd_module->i_type = SMG1210_RISC_SUBMODULAR_RESET_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 子模块复位 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"与子模块通道状态")){
	            cmd_module->i_type = SMG1210_RISC_SUBMODULAR_CHANNEL_STATUS_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);
                printf("[Receive]Module 与子模块通道状态 ： %s\n", ModuleValue);
            }
            xmlFree(ModuleValue);
            xmlFree(ModuleName);
        }
	    cur = cur->next;	
    }
    free(cmd_module);
    printf("[Receive]Get Module Done.\n");
}

/*******************************************************************************
 * smg1210_cmd_module* get_ts_over_ip_module_value(smg1210_cmd_module*         * 
 *                                                 cmd_module,                 * 
 *                                                 xmlDocPtr doc,              * 
 *                                                 xmlNodePtr cur)             * 
 * INTERFACE:                                                                  * 
 *     struct smg1210_cmd_module* cmd_module:                                  *
 *     xmlDocPtr doc: Doc pointer for libxml2 parsing.                         * 
 *     xmlNodePtr cur: Node pointer for libxml2 parsing.                       * 
 * USAGE:                                                                      * 
 *     Get the prop value of Module while the prop value of CellName is ts     * 
 *     over ip.                                                                * 
 * RETURN:                                                                     * 
 *     struct smg1210_cmd_module: Contains info of Module Node                 * 
 *******************************************************************************/
smg1210_cmd_module* get_ts_over_ip_module_value(smg1210_cmd_module* cmd_module, xmlDocPtr doc, xmlNodePtr cur)
{
    /*set_param contains all kinds of param that tsc need*/
    set_param set_info;
    Tuner_Param_c tuner_info;
    
    /*xmlChar equals unsigned char */
    xmlChar *ModuleName;                   
    xmlChar *ModuleValue;                   
    
    printf("\n[Receive]Get module.\n");
    
    /*
    @@BUGGY:unfinished function, flexible module node
    unsigned int module_cnt = 0;
    */
    
    /*Move current node pointer to child node*/    
	cur = cur->xmlChildrenNode;
    
	while(cur != NULL)
    {
        if((!xmlStrcmp(cur->name, (const xmlChar *)"Module")))	
	    {
	        //Get Name prop value
	        ModuleName = xmlGetProp(cur, "Name");	
	        if(!strcmp(ModuleName,(const xmlChar *) "本地IP")){
	            cmd_module->i_type = SMG1210_DCAS_CI_INFO_QUERY_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 本地IP ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "本地端口")){
	            cmd_module->i_type = SMG1210_DCAS_CI_COUNT_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
                    
                /* Setting to config file */
                set_info.port = cmd_module->i_value; 
                set_port_cfg(&set_info);
                    
//strcpy(cmd_module->s_origin_value , ModuleValue);                                
                }
                printf("[Receive]Module 本地端口 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"目标IP")){
	            cmd_module->i_type = SMG1210_DCAS_SMART_CARD_1_INFO_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 目标IP ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"目标端口")){
	            cmd_module->i_type = SMG1210_DCAS_SMART_CARD_2_INFO_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 目标端口 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"协议")){
	            cmd_module->i_type = SMG1210_DCAS_PROG_COUNT_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 协议 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"TS Over IP开关")){
	            cmd_module->i_type = SMG1210_DCAS_CUR_DCAS_PROG_NAME_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module TS Over IP 开关 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"TS Over IP状态查询")){
	            cmd_module->i_type = SMG1210_DCAS_CI_1_PROG_COUNT_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module TS Over IP 状态查询 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "当前本地IP")){
	            cmd_module->i_type = SMG1210_DCAS_CI_2_PROG_COUNT_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 当前本地IP ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "当前本地端口")){
	            cmd_module->i_type = SMG1210_DCAS_CI_2_PROG_COUNT_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 当前本地端口 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "当前目标IP")){
	            cmd_module->i_type = SMG1210_DCAS_CI_2_PROG_COUNT_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 当前目标IP ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"当前目标端口")){
	            cmd_module->i_type = SMG1210_DCAS_CI_2_PROG_COUNT_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 当前目标端口 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"当前协议")){
	            cmd_module->i_type = SMG1210_DCAS_CI_2_PROG_COUNT_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 当前协议 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"当前TS Over IP开关状态")){
	            cmd_module->i_type = SMG1210_DCAS_CI_2_PROG_COUNT_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 当前TS Over IP 开关状态 ： %s\n", ModuleValue);
            }
            xmlFree(ModuleValue);
            xmlFree(ModuleName); 
        }
	    cur = cur->next;	
	    //module_cnt++;
    }
    free(cmd_module);
    printf("[Receive]Get Module Done.\n");
}

/*******************************************************************************
 * smg1210_cmd_module* get_transcoding_module_value(smg1210_cmd_module*        *
 *                                                  cmd_module,                *
 *                                                  xmlDocPtr doc,             * 
 *                                                  xmlNodePtr cur)            * 
 * INTERFACE:                                                                  * 
 *     struct smg1210_cmd_module* cmd_module:                                  *
 *     xmlDocPtr doc: Doc pointer for libxml2 parsing.                         *
 *     xmlNodePtr cur: Node pointer for libxml2 parsing.                       * 
 * USAGE:                                                                      * 
 *     Get the prop value of Module while the prop value of CellName is        * 
 *     transcoding.                                                            * 
 * RETURN:                                                                     * 
 *     struct smg1210_cmd_module: Contains info of Module Node                 *
 *******************************************************************************/
smg1210_cmd_module* get_transcoding_module_value(smg1210_cmd_module* cmd_module, xmlDocPtr doc, xmlNodePtr cur)
{
    /*set_param contains all kinds of param that tsc need*/
    set_param set_info;
    Tuner_Param_c tuner_info;

    /*xmlChar equals unsigned char */
    xmlChar *ModuleName;
    xmlChar *ModuleValue;

    printf("\n[Receive]Get module.\n");

    //unsigned int module_cnt = 0;

    /*Move current node pointer to child node*/    
	cur = cur->xmlChildrenNode;

	while(cur != NULL)
    {
        //Get Name prop value.
        if((!xmlStrcmp(cur->name, (const xmlChar *)"Module")))	{
	        ModuleName = xmlGetProp(cur, "Name");	

	        if(!strcmp(ModuleName,(const xmlChar *) "转码节目选择")){
	            cmd_module->i_type = SMG1210_TSC_PROG_SEL_MODULE;
    	        /* 转码节目选择 */
                ModuleValue = xmlGetProp(cur, "Value");
                /*if ModuleValue is int then device use 
                cmd_module->i_value otherwise use cmd_module->s_origin_value*/
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 转码节目选择 ： %s\n", ModuleValue);

            } else if(!strcmp(ModuleName,(const xmlChar *) "转码视频最大码率")) {
                /* 转码视频最大码率 */
	            cmd_module->i_type = SMG1210_TSC_VIDEO_MAX_BIT_RATE_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                /*if ModuleValue is int then device use 
                cmd_module->i_value otherwise use cmd_module->s_origin_value*/
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 转码视频最大码率 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "转码视频最小码率")){
                /* 转码视频最小码率 */
	            cmd_module->i_type = SMG1210_TSC_VIDEO_MIN_BIT_RATE_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 转码视频最小码率 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "转码视频平均码率")){
	            cmd_module->i_type = SMG1210_TSC_VIDEO_AVERAGE_BIT_RATE_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 转码视频平均码率 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "转码输出VBR/CBR选择")){
	            cmd_module->i_type = SMG1210_TSC_OUTPUT_VBR_CBR_SEL_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 转码输出VBR/CBR选择 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "音频格式选择")){
	            cmd_module->i_type = SMG1210_TSC_AUDIO_FORMAT_SEL_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 音频格式选择 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "转码输出分辨率")){
	            cmd_module->i_type = SMG1210_TSC_OUTPUT_RESOLUTION_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);

                /* Setting to config file */                
                set_info.v_format = cmd_module->i_value;
                set_v_format_cfg(&set_info);
              //strcpy(cmd_module->s_origin_value , ModuleValue);
                printf("[Receive]Module 转码输出分辨率 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "转码输出音频格式")){
	            cmd_module->i_type = SMG1210_TSC_OUTPUT_AUDIO_FORMAT_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 转码输出音频格式 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"转码输出Service ID")){
	            cmd_module->i_type = SMG1210_TSC_OUTPUT_SERVICE_ID_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 转码输出Service ID ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "转码输出视频PID")){
	            cmd_module->i_type = SMG1210_TSC_OUTPUT_VIDEO_PID_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);

                /* Setting to config file */                
                set_info.tsc_v_pid = cmd_module->i_value;
                set_tsc_v_pid_cfg(&set_info);
              //strcpy(cmd_module->s_origin_value , ModuleValue);                                
                printf("[Receive]Module 转码输出视频PID ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "转码输出音频PID")){
                cmd_module->i_type = SMG1210_TSC_OUTPUT_AUDIO_PID_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
                    
                /* Setting to config file */                
                set_info.tsc_a_pid = cmd_module->i_value;
                set_tsc_a_pid_cfg(&set_info);
              //strcpy(cmd_module->s_origin_value , ModuleValue);                                
                printf("[Receive]Module 转码输出音频PID ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "转码输出PMT PID")){
	            cmd_module->i_type = SMG1210_TSC_OUTPUT_PMT_PID_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);

                /* Setting to config file */                
                set_info.tsc_pmt_pid = cmd_module->i_value;
                set_tsc_pmt_pid_cfg(&set_info);
              //strcpy(cmd_module->s_origin_value , ModuleValue);                                
                printf("[Receive]Module 转码输出PMT PID ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "转码输出PCR PID")){
	            cmd_module->i_type = SMG1210_TSC_OUTPUT_PCR_PID_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);

                /* Setting to config file ??*/                
                set_info.src_pcr_pid = cmd_module->i_value;
                set_src_pcr_pid_cfg(&set_info);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                

                printf("[Receive]Module 转码输出PCR PID ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "转码再复用使能")){
	            cmd_module->i_type = SMG1210_TSC_RUMX_EN_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 转码再复用使能 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"Service ID")){
	            cmd_module->i_type = SMG1210_TSC_SERVICE_ID_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module Service ID ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"当前转码状态查询")){
	            cmd_module->i_type = SMG1210_TSC_CUR_STATUS_QUERY_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 当前转码状态查询 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"当前转码状态")){
	            cmd_module->i_type = SMG1210_TSC_CUR_STATUS_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 当前转码状态 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"当前转码输出分辨率")){
	            cmd_module->i_type = SMG1210_TSC_CUR_OUTPUT_RESOLUTION_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 当前转码输出分辨率 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"当前转码输出音频格式")){
	            cmd_module->i_type = SMG1210_TSC_CUR_OUTPUT_AUDIO_FORMAT_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 当前转码输出音频格式 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"当前转码输出视频PID")){
	            cmd_module->i_type = SMG1210_TSC_CUR_OUTPUT_VIDEO_PID_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 当前转码输出视频PID ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"当前转码输出音频PID")){
	            cmd_module->i_type = SMG1210_TSC_CUR_OUTPUT_AUDIO_PID_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 当前转码输出音频PID ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "当前转码输出PMT PID")){
	            cmd_module->i_type = SMG1210_TSC_CUR_OUTPUT_PMT_PID_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 当前转码输出PMT PID ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"当前转码输出PCR PID")){
	            cmd_module->i_type = SMG1210_TSC_CUR_OUTPUT_PCR_PID_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 当前转码输出PCR PID ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "当前转码再复用使能")){
	            cmd_module->i_type = SMG1210_TSC_CUR_RMUX_EN_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 当前转码再复用使能 ： %s\n", ModuleValue);
            }
            xmlFree(ModuleValue);
            xmlFree(ModuleName); 
	    }
        cur = cur->next;	
        //module_cnt++;
    }
    free(cmd_module);
    printf("[Receive]Get Module Done.\n");
}



/*******************************************************************************
 * smg1210_cmd_module* get_input_module_value(smg1210_cmd_module* cmd_module,  *
 *                                            xmlDocPtr doc, xmlNodePtr cur)   *
 * INTERFACE:                                                                  *
 *      struct smg1210_cmd_module* cmd_module:                                 *
 *      xmlDocPtr doc: Doc pointer for libxml2 parsing.                        *                     
 *      xmlNodePtr cur: Node pointer for libxml2 parsing.                      * 
 * USAGE:                                                                      * 
 *      Get the prop value of Module while the prop value of CellName is input.*
 * RETURN:                                                                     *
 *      struct smg1210_cmd_module: Contains info of Module Node                * 
 *                                                                             *
 ******************************************************************************/
smg1210_cmd_module* get_input_module_value(smg1210_cmd_module* cmd_module, xmlDocPtr doc, xmlNodePtr cur)
{
    /*set_param contains all kinds of param that tsc need*/
    set_param set_info;
    Tuner_Param_c tuner_info;
    
    /*xmlChar equals unsigned char */
    xmlChar* ModuleName;
    xmlChar* ModuleValue;
    
    printf("\n[Receive]Get module.\n");
    
    //unsigned int module_cnt = 0;
    
    /*Move current node pointer to child node*/    
	cur = cur->xmlChildrenNode;
    
	while(cur != NULL)
    {
        if((!xmlStrcmp(cur->name, (const xmlChar *) "Module")))	
	    {
	        //Get Name prop value.
	        ModuleName = xmlGetProp(cur, "Name");	
	        if(!strcmp(ModuleName, (const xmlChar *) "输入状态查询")){
   		        /*Dealing CellName with enum*/
	            cmd_module->i_type = SMG1210_INPUT_QUERY_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                    cmd_module->i_value =  atoi(ModuleValue);
//       strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 输入状态查询 ： %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *) "输入类型")){
                /*Dealing CellName with enum*/       
	            cmd_module->i_type = SMG1210_INPUT_TYPE_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 输入类型 : %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "设置频率")){
	            /*Dealing CellName with enum*/
	            cmd_module->i_type = SMG1210_SET_FREQ_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);

                /* Setting for config file */
                tuner_info.freq = cmd_module->i_value;
                set_tuner_c_cfg(&tuner_info);
              //strcpy(cmd_module->s_origin_value,ModuleValue);
                printf("[Receive]Module 设置频率 : %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"设置调制方式")){
	            /*Dealing CellName with enum*/
	            cmd_module->i_type = SMG1210_SET_MOD_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 设置调制方式 : %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"设置符号率")){
	            /*Dealing CellName with enum*/
	            cmd_module->i_type = SMG1210_SET_SYMBOL_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
                    
                /*  Setting for config file ??*/
                tuner_info.baud_rate = cmd_module->i_value;                    
                set_tuner_c_cfg(&tuner_info);                    
              //strcpy(cmd_module->s_origin_value,ModuleValue);
                printf("[Receive]Module 设置符号率 : %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"设置带宽")){
	            /*Dealing CellName with enum*/
	            cmd_module->i_type = SMG1210_SET_BW_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 设置带宽 : %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"设置载波模式")){
	            /*Dealing CellName with enum*/
	            cmd_module->i_type = SMG1210_SET_CW_TYPE_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
              //strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 设置载波模式 : %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "搜台")){
	            /*Dealing CellName with enum*/
	            cmd_module->i_type = SMG1210_PROG_QUERY_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                cmd_module->i_value =  atoi(ModuleValue);
                    
                ts_man_start();
                /* Starts DVB psi analyse */
                start_dvbpsi_analyse();
                sleep(2);
                stop_dvbpsi_analyse();
                ts_man_stop(); /* Within libusi: Data pipe stop,close;Data sink stop,close*/
//strcpy(cmd_module->s_origin_value,ModuleValue);                                
                printf("[Receive]Module 搜台 : %s\n", ModuleValue);
#if 0
            }else if(!strcmp(ModuleName, (const xmlChar *)"节目名称")){
	            /*Dealing CellName with enum*/
                /*SSample*/
	            cmd_module->i_type = SMG1210_PROG_NAME_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                if(atoi(ModuleValue) == ModuleValue) {
                    cmd_module->i_value =  atoi(ModuleValue);
                } else {
                    strcpy(cmd_module->s_origin_value,ModuleValue);                                
                }
                printf("[Receive]Module 节目名称 : %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"Service ID")){
	            /*Dealing CellName with enum*/
	            cmd_module->i_type = SMG1210_SERVICE_ID_NAME_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                if(atoi(ModuleValue) == ModuleValue) {
                    cmd_module->i_value =  atoi(ModuleValue);
                } else {
                    strcpy(cmd_module->s_origin_value,ModuleValue);                                
                }
                printf("[Receive]Module Service ID : %s\n", ModuleValue);

            }else if(!strcmp(ModuleName,(const xmlChar *) "Video PID")){
	            /*Dealing CellName with enum*/
	            cmd_module->i_type = SMG1210_VIDEO_PID_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                if(atoi(ModuleValue) == ModuleValue) {
                    cmd_module->i_value =  atoi(ModuleValue);
                } else {
                    strcpy(cmd_module->s_origin_value,ModuleValue);                                
                }
                printf("[Receive]Module Video PID : %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"Audio PID")){
	            /*Dealing CellName with enum*/
	            cmd_module->i_type = SMG1210_AUDIO_PID_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                if(atoi(ModuleValue) == ModuleValue) {
                    cmd_module->i_value =  atoi(ModuleValue);
                } else {
                    strcpy(cmd_module->s_origin_value,ModuleValue);                                
                }
                printf("[Receive]Module Audio PID : %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"PMT PID")){
	            /*Dealing CellName with enum*/
	            cmd_module->i_type = SMG1210_PMT_PID_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                if(atoi(ModuleValue) == ModuleValue) {
                    cmd_module->i_value =  atoi(ModuleValue);
                } else {
                    strcpy(cmd_module->s_origin_value,ModuleValue);                                
                }
                printf("[Receive]Module PMT PID : %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *)"PCR PID")){
	            /*Dealing CellName with enum*/
	            cmd_module->i_type = SMG1210_PCR_PID_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                if(atoi(ModuleValue) == ModuleValue) {
                    cmd_module->i_value =  atoi(ModuleValue);
                } else {
                    strcpy(cmd_module->s_origin_value,ModuleValue);                                
                }
                printf("[Receive]Module PCR PID : %s\n", ModuleValue);

            }else if(!strcmp(ModuleName, (const xmlChar *) "解扰节目选择")){
	            /*Dealing CellName with enum*/
	            cmd_module->i_type = SMG1210_DCAS_MODULE;
                ModuleValue = xmlGetProp(cur, "Value");
                if(atoi(ModuleValue) == ModuleValue) {
                    cmd_module->i_value =  atoi(ModuleValue);
                } else {
                    strcpy(cmd_module->s_origin_value,ModuleValue);                                
                }
                printf("[Receive]Module 解扰节目选择 : %s\n", ModuleValue);
            }
#endif 0
		    xmlFree(ModuleValue);
		    xmlFree(ModuleName); 
	    }
        cur = cur->next;
	    //module_cnt++;
    }
    free(cmd_module);	
    printf("[Receive]Get Module Done.\n");
}

/*******************************************************************************
 * smg1210_cmd_cell* get_cell(smg1210_cmd_cell* cmd_cell, xmlDocPtr doc,       * 
 *                            xmlNodePtr cur)                                  * 
 * INTERFACE:                                                                  * 
 *     smg1210_cmd_cell* cmd_cell: Contains prop value of CellName and other   * 
 *                                 prop within the same node.                  *     
 *     xmlDocPtr doc: doc pointer for libxml2 parsing.                         * 
 *     xmlNodePtr cur: node pointer for libxml2 parsing.                       * 
 * USAGE:                                                                      * 
 *     Get the prop value of CellName and other prop within the same node.     *     
 * RETURN:                                                                     *     
 *     struct smg1210_cmd_cell: Contains info of CellName,DeviceName,GroupName.*  
 *******************************************************************************/
smg1210_cmd_cell* get_cell(smg1210_cmd_cell* cmd_cell, xmlDocPtr doc, xmlNodePtr cur)
{
  	/*xmlChar equals unsigned char */
	/*Declare vars using data structure from libxml2*/
    xmlChar* GroupName;                    
	xmlChar* DeviceName;
	xmlChar* cell;
	
	/*Move current node pointer to child node*/    
	cur = cur->xmlChildrenNode;

    /*Apply memory space for cmd_module*/
    smg1210_cmd_module* cmd_module = malloc(sizeof(smg1210_cmd_module)+1);
    
	while(cur != NULL)
   	{
   	    /*Determine node name*/
       	if((!xmlStrcmp(cur->name,(const xmlChar *) "Set")))	{ 
       	    
            /*Node name is Set. Relevant dealing will be executed*/
            printf("\n[Receive]Get Cmd.\n");
       	    printf("[Receive]参数设置\n");
       	    printf("[Receive]Get Cmd Done.\n");

            /*Copy to replying struct for packing*/
       	    strcpy(my_cmd_query_prog_r.type, "Set");
 
      	    printf("\n[Receive]Get Cell.\n");
       	    //Get Groupname
       	    GroupName = xmlGetProp(cur, "GroupName");            
            printf("[Receive]GroupName: %s\n", GroupName);
            
            /*Copy to replying struct for packing*/
            strcpy(my_cmd_query_prog_r.GroupName, GroupName);
            //Get DeviceName            
            DeviceName = xmlGetProp(cur, "DeviceName");
            printf("[Receive]DeviceName: %s\n", DeviceName);
            
            /*Copy to replying struct for packing*/
            strcpy(my_cmd_query_prog_r.DeviceName, DeviceName);	
       	    //Get CellName.
	        cell = xmlGetProp(cur, "CellName");

		    if(!xmlStrcmp(cell,(const xmlChar *) "Input")){          
		        /*Dealing CellName with enum*/
	            cmd_cell->i_type = SMG1210_INPUT_CELL;
	            
                printf("[Receive]CellName: Input.\n");	
	            printf("[Receive]Get Cell Done.\n");

	            /*Copy to replying struct for packing*/       
	            strcpy(my_cmd_query_prog_r.CellName, "Input");

                /*Invoke relevant function to get module node info*/
	            get_input_module_value(cmd_module, doc, cur);

            } else if(!strcmp(cell, (const xmlChar *) "Transcoding")){
	            /*Dealing CellName with enum*/
	            cmd_cell->i_type = SMG1210_TSC_CELL;

	            printf("[Receive]CellName: Transcoding.\n");
                printf("[Receive]Get Cell Done.\n");

	            /*Copy to replying struct for packing*/
	            strcpy(my_cmd_query_prog_r.CellName, "Transcoding");

	            /*Invoke relevant function to get module node info*/
	            get_transcoding_module_value(cmd_module, doc, cur);	

            } else if(!strcmp(cell, (const xmlChar *) "DVB/ATSC scrambling")){
                /*Dealing CellName with enum*/	            
	            cmd_cell->i_type = SMG1210_CAS;

	            printf("[Receive]CellName: DVB/ATSC scrambling.\n");
                printf("[Receive]Get Cell Done.\n");

                /*Copy to replying struct for packing*/
                strcpy(my_cmd_query_prog_r.CellName, "DVB/ATSC scrambling");

                /*Invoke relevant function to get module node info*/
	            get_dvb_atsc_descrambling_module_value(cmd_module, doc, cur);	

            } else if(!strcmp(cell, (const xmlChar *) "TS Over IP")){
	            /*Dealing CellName with enum*/
	            cmd_cell->i_type = SMG1210_TSOIP;

	            printf("[Receive]CellName: TS Over IP.\n");
                printf("[Receive]Get Cell Done.\n");

                /*Copy to replying struct for packing*/
                strcpy(my_cmd_query_prog_r.CellName, "TS Over IP");

                /*Invoke relevant function to get module node info*/
	            get_ts_over_ip_module_value(cmd_module, doc, cur);	

            } else if(!strcmp(cell, (const xmlChar *)"RISC")){
	            /*Dealing CellName with enum*/
	            cmd_cell->i_type = SMG1210_RISC;

	            printf("[Receive]CellName: RISC.\n");
                printf("[Receive]Get Cell Done.\n");

                /*Copy to replying struct for packing*/
                strcpy(my_cmd_query_prog_r.CellName, "RISC");

                /*Invoke relevant function to get module node info*/
	            get_risc_module_value(cmd_module, doc, cur);	

            }
            /*Free memory space libxml2 vars used*/
            xmlFree(cell);  
            xmlFree(GroupName);
            xmlFree(DeviceName);

	    }else if((!xmlStrcmp(cur->name, (const xmlChar *)"Get")))  {	

             printf("\n[Receive]Get Cmd.\n");
             printf("[Receive]参数同步\n");
             printf("[Receive]Get Cmd Done.\n");

             strcpy(my_cmd_query_prog_r.type, "Get");
             
             printf("\n[Receive]Get Cell.\n");
             
             //Get GroupName
             GroupName = xmlGetProp(cur, "GroupName");            
             printf("[Receive]GroupName: %s\n", GroupName);

             /*Copy to replying struct for packing*/
             strcpy(my_cmd_query_prog_r.GroupName, GroupName);
             
             //Get DeviceName
             DeviceName = xmlGetProp(cur, "DeviceName");
             printf("[Receive]DeviceName: %s\n", DeviceName);

             /*Copy to replying struct for packing*/
             strcpy(my_cmd_query_prog_r.DeviceName, DeviceName);

             //Get CellName
	         cell = xmlGetProp(cur, "CellName");

           	 if(!strcmp(cell,(const xmlChar *) "Input")){                   
	            /*Dealing CellName with enum*/
	            cmd_cell->i_type = SMG1210_INPUT_CELL;
	           
                printf("[Receive]CellName: Input.\n");
                printf("[Receive]Get Cell Done.\n");
                
                /*Copy to replying struct for packing*/
                strcpy(my_cmd_query_prog_r.CellName, "Input");

                /*Invoke relevant function to get module node info*/       
	            get_input_module_value(cmd_module, doc, cur);	

             }else if(!strcmp(cell,(const xmlChar *) "Transcoding")){
	            /*Dealing CellName with enum*/
	            cmd_cell->i_type = SMG1210_TSC_CELL;

	            printf("[Receive]CellName: Transcoding.\n");	
                printf("[Receive]Get Cell Done.\n");
                
                /*Copy to replying struct for packing*/
                strcpy(my_cmd_query_prog_r.CellName, "Transcoding");

                /*Invoke relevant function to get module node info*/       
	            get_transcoding_module_value(cmd_module, doc, cur);	

             } else if(!strcmp(cell,(const xmlChar *) "DVB/ATSC scrambling")){
	            /*Dealing CellName with enum*/
	            cmd_cell->i_type = SMG1210_CAS;

	            printf("[Receive]CellName: DVB/ATSC scrambling.\n");	
                printf("[Receive]Get Cell Done.\n");

                /*Copy to replying struct for packing*/                
                strcpy(my_cmd_query_prog_r.CellName, "DVB/ATSC scrambling");

                /*Invoke relevant function to get module node info*/       
	            get_dvb_atsc_descrambling_module_value(cmd_module, doc, cur);	

             } else if(!strcmp(cell,(const xmlChar *) "TS Over IP")){
	            /*Dealing CellName with enum*/
	            cmd_cell->i_type = SMG1210_TSOIP;

	            printf("[Receive]CellName: TS Over IP.\n");	
                printf("[Receive]Get Cell Done.\n");

                /*Copy to replying struct for packing*/
                strcpy(my_cmd_query_prog_r.CellName, "TS Over IP");

                /*Invoke relevant function to get module node info*/       
	            get_ts_over_ip_module_value(cmd_module, doc, cur);	

             } else if(!strcmp(cell,(const xmlChar *) "RISC")){
	            /*Dealing CellName with enum*/
	            cmd_cell->i_type = SMG1210_RISC;

	            printf("[Receive]CellName: RISC.\n");	
                printf("[Receive]Get Cell Done.\n");

                /*Copy to replying struct for packing*/
                strcpy(my_cmd_query_prog_r.CellName, "RISC");

                /*Invoke relevant function to get module node info*/      
	            get_risc_module_value(cmd_module, doc, cur);	

             }
            xmlFree(cell);  
            xmlFree(GroupName);
            xmlFree(DeviceName);
        }else if((!xmlStrcmp(cur->name, (const xmlChar *)"搜台"))){    	
    
            printf("\n[Receive]Get Cmd.\n");
       	    printf("[Receive]搜台\n");
       	    printf("[Receive]Get Cmd Done.\n");
       	   
            strcpy(my_cmd_query_prog_r.type, "搜台");
       	    
       	    //Marks:Get cell done.
            printf("\n[Receive]Get Cell.\n");

            //Get GroupName
            GroupName = xmlGetProp(cur, "GroupName");            
            printf("[Receive]GroupName: %s\n", GroupName);
            /*Copy to replying struct for packing*/
            strcpy(my_cmd_query_prog_r.GroupName, GroupName);
            
            //Get DeviceName
            DeviceName = xmlGetProp(cur, "DeviceName");
            printf("[Receive]DeviceName: %s\n", DeviceName);
            /*Copy to replying struct for packing*/
            strcpy(my_cmd_query_prog_r.DeviceName, DeviceName);

            //Get CellName
	        cell = xmlGetProp(cur, "CellName");
            
			if(!strcmp(cell, (const xmlChar *)"Input")){                   
	            /*Dealing CellName with enum*/
	            cmd_cell->i_type = SMG1210_INPUT_CELL;

	            printf("[Receive]CellName: Input.\n");	
                printf("[Receive]Get Cell Done.\n");

                /*Copy to replying struct for packing*/
                strcpy(my_cmd_query_prog_r.CellName, "Input");

                /*Invoke relevant function to get module node info*/       
	            get_input_module_value(cmd_module, doc, cur);	

            }else if(!strcmp(cell, (const xmlChar *)"Transcoding")){
	            /*Dealing CellName with enum*/
	            cmd_cell->i_type = SMG1210_TSC_CELL;

	            printf("[Receive]CellName: Transcoding.\n");	
                printf("[Receive]Get Cell Done.\n");

                /*Copy to replying struct for packing*/
                strcpy(my_cmd_query_prog_r.CellName, "Transcoding");

                /*Invoke relevant function to get module node info*/       
	            get_transcoding_module_value(cmd_module, doc, cur);	

            } else if(!strcmp(cell, (const xmlChar *)"DVB/ATSC scrambling")){
                /*Dealing CellName with enum*/
	            cmd_cell->i_type = SMG1210_CAS;

	            printf("[Receive]CellName: DVB/ATSC scrambling.\n");	
                printf("[Receive]Get Cell Done.\n");

                /*Copy to replying struct for packing*/
                strcpy(my_cmd_query_prog_r.CellName, "DVB/ATSC scrambling");

                /*Invoke relevant function to get module node info*/      
	            get_dvb_atsc_descrambling_module_value(cmd_module, doc, cur);	

            } else if(!strcmp(cell, (const xmlChar *)"TS Over IP")){
	            /*Dealing CellName with enum*/
	            cmd_cell->i_type = SMG1210_TSOIP;

	            printf("[Receive]CellName: TS Over IP.\n");	
                printf("[Receive]Get Cell Done.\n");

                /*Copy to replying struct for packing*/
                strcpy(my_cmd_query_prog_r.CellName, "TS Over IP");

                /*Invoke relevant function to get module node info*/       
	            get_ts_over_ip_module_value(cmd_module, doc, cur);	
            } else if(!strcmp(cell, (const xmlChar *)"RISC")){
	            /*Dealing CellName with enum*/
	            cmd_cell->i_type = SMG1210_RISC;

	            printf("[Receive]CellName: RISC.\n");	    
                printf("[Receive]Get Cell Done.\n");

                /*Copy to replying struct for packing*/
                strcpy(my_cmd_query_prog_r.CellName, "RISC");

                /*Invoke relevant function to get module node info*/      
	            get_risc_module_value(cmd_module, doc, cur);	
            }  
            xmlFree(cell);  
            xmlFree(GroupName);
            xmlFree(DeviceName);

	    }else if((!xmlStrcmp(cur->name, (const xmlChar *)"选台")))	{

            printf("\n[Receive]Get Cmd.\n");
       	    printf("[Receive]选台\n");
       	    printf("[Receive]Get Cmd Done.\n");

       	    /*Dealing CellName with enum*/
       	    strcpy(my_cmd_query_prog_r.type, "选台");
       	    
            printf("\n[Receive]Get Cell.\n");
            
            //Get GroupName
            GroupName = xmlGetProp(cur, "GroupName");            
            printf("[Receive]GroupName: %s\n", GroupName);
            /*Copy to replying struct for packing*/
            strcpy(my_cmd_query_prog_r.GroupName, GroupName);
            
            //Get DeviceName
            DeviceName = xmlGetProp(cur, "DeviceName");
            printf("[Receive]DeviceName: %s\n", DeviceName);
            /*Copy to replying struct for packing*/
            strcpy(my_cmd_query_prog_r.DeviceName, DeviceName);

            //Get CellName
	        cell = xmlGetProp(cur, "CellName");
            
			if(!strcmp(cell, (const xmlChar *)"Input")){                   
	            /*Dealing CellName with enum*/
	            cmd_cell->i_type = SMG1210_INPUT_CELL;

	            printf("[Receive]CellName: Input.\n");	
                printf("[Receive]Get Cell Done.\n");

                /*Copy to replying struct for packing*/
                strcpy(my_cmd_query_prog_r.CellName, "Input");

                /*Invoke relevant function to get module node info*/       
	            get_input_module_value(cmd_module, doc, cur);	

            }else if(!strcmp(cell, (const xmlChar *)"Transcoding")){
	            /*Dealing CellName with enum*/
	            cmd_cell->i_type = SMG1210_TSC_CELL;

	            printf("[Receive]CellName: Transcoding.\n");	
                printf("[Receive]Get Cell Done.\n");

                /*Copy to replying struct for packing*/
                strcpy(my_cmd_query_prog_r.CellName, "Transcoding");

                /*Invoke relevant function to get module node info*/       
	            get_transcoding_module_value(cmd_module, doc, cur);	
            }else if(!strcmp(cell, (const xmlChar *)"DVB/ATSC scrambling")){
	            /*Dealing CellName with enum*/
	            cmd_cell->i_type = SMG1210_CAS;

	            printf("[Receive]CellName: DVB/ATSC scrambling.\n");	
                printf("[Receive]Get Cell Done.\n");

                /*Copy to replying struct for packing*/
                strcpy(my_cmd_query_prog_r.CellName, "DVB/ATSC scrambling");

                /*Invoke relevant function to get module node info*/      
	            get_dvb_atsc_descrambling_module_value(cmd_module, doc, cur);	

            }else if(!strcmp(cell,(const xmlChar *) "TS Over IP")){
	            /*Dealing CellName with enum*/
	            cmd_cell->i_type = SMG1210_TSOIP;

	            printf("[Receive]CellName: TS Over IP.\n");	
                printf("[Receive]Get Cell Done.\n");

                /*Copy to replying struct for packing*/
                strcpy(my_cmd_query_prog_r.CellName, "TS Over IP");

                /*Invoke relevant function to get module node info*/       
	            get_ts_over_ip_module_value(cmd_module, doc, cur);	

            }else if(!strcmp(cell, (const xmlChar *)"RISC")){
	            /*Dealing CellName with enum*/
	            cmd_cell->i_type = SMG1210_RISC;

	            printf("[Receive]CellName: RISC.\n");	
                printf("[Receive]Get Cell Done.\n");

                /*Copy to replying struct for packing*/
                strcpy(my_cmd_query_prog_r.CellName, "RISC");

                /*Invoke relevant function to get module node info*/      
	            get_risc_module_value(cmd_module, doc, cur);	
            } 
            //释放保存CellName的变量    
            xmlFree(cell);  
            xmlFree(GroupName);
            xmlFree(DeviceName);
	    }   
	    /*Move current pointer to nexts node*/
	    cur = cur->next;	
   	}
   	/*返回下行结构体*/
   	/*包含二级结点的结点治属性和prop value */
    return cmd_cell;
    free(cmd_cell);
}

/*******************************************************************************
 * smg1210_cmd_msg* get_msg(smg1210_cmd_msg* cmd_msg, char* mis_string)        *
 * INTERFACE:                                                                  *                     
 *     smg1210_cmd_msg* cmd_msg: Contains prop info of Msg node.               * 
 *     char* mis_string: xml string that MIS sys post to device.               *     
 * USAGE:                                                                      * 
 *     Get prop info of Msg node.                                              * 
 * RETURN:                                                                     * 
 *     struct smg1210_cmd_msg: Contain prop info of Msg node.                  *
 *******************************************************************************/
smg1210_cmd_msg* get_msg(smg1210_cmd_msg* cmd_msg, char* mis_string)
{
    xmlDocPtr   doc;         
    xmlNodePtr  cur;		    
	
	/*xmlChar equals unsigned char  */
	xmlChar *Version;	    
	xmlChar *MsgID;     
	xmlChar *Type;     
	xmlChar *DateTime;     
	xmlChar *SrcCode;     
	xmlChar *DstCode;     
	xmlChar *SrcUrl;     
	xmlChar *Priority;     

	int len = strlen(mis_string);                       
	
	/*Use libxml2 API to load xml string to doc pointer*/
    doc = xmlParseMemory(mis_string, len);
    
    if(NULL == doc) {
        fprintf(stderr, "\n==== XML Parsing Failed ====\n");
		return;
	} else {
		printf("\n==== XML Parsing Starts Here ====\n");
    }
    
    /*Load the doc from root then use libxml2 API to get current node pointer*/
	cur = xmlDocGetRootElement(doc);
	
	if(NULL == cur){
        fprintf(stderr, "\n==== Empty XML ====\n");
		xmlFreeDoc(doc); 
		return;
    }
    
    /*Determine the node name whether it's 'Msg' or not*/
	if(xmlStrcmp(cur->name, (const xmlChar *)"Msg")){               
        fprintf(stderr, "XML of the wrong type, root node != Msg.\n");
		xmlFreeDoc(doc);
        return;
    }

    /*Starts to parse Msg node*/
	while(cur != NULL)
    {
    	if((!xmlStrcmp(cur->name, (const xmlChar *)"Msg")))	
	    {   
	        printf("\n[Receice]Get Msg.\n");

	        //Get Version
	        Version = xmlGetProp(cur, "Version");
	        /*Copy to replying struct for packing*/
            strcpy(my_cmd_query_prog_r.Version,Version);
			/*Copy to downstream struct for setting*/
			strcpy(cmd_msg->Version, Version);
            printf("[Receive]Msg:Version: %s\n", cmd_msg->Version);		
			xmlFree(Version); 

            /*Get MsgID*/
        	MsgID = xmlGetProp(cur, "MsgID");
        	/*Copy to replying struct for packing*/
        	strcpy(my_cmd_query_prog_r.ReplyID, MsgID);
            /*Copy to downstream struct for setting*/
		    strcpy(cmd_msg->MsgID, MsgID);
		    printf("[Receive]Msg:MsgID: %s\n", cmd_msg->MsgID);			
			xmlFree(MsgID); 

            /*Get Type*/
			Type = xmlGetProp(cur, "Type");
            /*Copy to replying struct for packing*/
			strcpy(my_cmd_query_prog_r.Type, Type);
			/*Copy to downstream struct for setting*/
			strcpy(cmd_msg->Type, Type);
			printf("[Receive]Msg:Type: %s\n", cmd_msg->Type);			
			xmlFree(Type); 

            /*Get DateTime*/
			DateTime = xmlGetProp(cur, "DateTime");
			/*Copy to replying struct for packing*/
			strcpy(my_cmd_query_prog_r.DateTime, DateTime);
			/*Copy to downstream struct for setting*/
			strcpy(cmd_msg->DateTime, DateTime);
			printf("[Receive]Msg:DateTime: %s\n", cmd_msg->DateTime);			
			xmlFree(DateTime); 
    
            /*Get SrcCode*/
			SrcCode = xmlGetProp(cur, "SrcCode");
			/*Copy to replying struct for packing*/
			strcpy(my_cmd_query_prog_r.SrcCode, SrcCode);
			/*Copy to downstream struct for setting*/
            strcpy(cmd_msg->SrcCode, SrcCode);
			printf("[Receive]Msg:SrcCode: %s\n", cmd_msg->SrcCode);			
			xmlFree(SrcCode); 

            /*Get DstCode*/
			DstCode = xmlGetProp(cur, "DstCode");
			/*Copy to replying struct for packing*/
			strcpy(my_cmd_query_prog_r.DstCode, DstCode);
			/*Copy to downstream struct for setting*/
			strcpy(cmd_msg->DstCode, DstCode);
			printf("[Receive]Msg:DstCode: %s\n", cmd_msg->DstCode);			
			xmlFree(DstCode); 

            /*Get SrcUrl*/
			SrcUrl = xmlGetProp(cur, "SrcUrl");
			/*Copy to replying struct for packing*/
			strcpy(my_cmd_query_prog_r.SrcUrl, SrcUrl);
			/*Copy to downstream struct for setting*/
			strcpy(cmd_msg->SrcUrl, SrcUrl);
			printf("[Receive]Msg:SrcUrl: %s\n", cmd_msg->SrcUrl);			
			xmlFree(SrcUrl); 

            /*Get Priority*/
	    	Priority = xmlGetProp(cur, "Priority");
			strcpy(cmd_msg->Priority, Priority);
			printf("[Receive]Msg:Priority: %s\n", cmd_msg->Priority);			
			xmlFree(Priority); 

            /*Maeking: Finish parsing Msg Node*/
            printf("[Receive]Get Msg Done.\n");                        
            			
            /*Apply memory space for cmd_cell*/
            smg1210_cmd_cell* cmd_cell = malloc(sizeof(smg1210_cmd_cell)+1);  
            
            /*Invode get_cell() to continue parsing*/
            get_cell(cmd_cell, doc, cur);   
            free(cmd_cell);
		  }
		    /*Move current node pointer to the next node*/
			cur = cur->next;
       }
    /*Return struct cmd_msg which contains info to device*/   
    return cmd_msg;
    /*Free the doc pointer*/
	xmlFreeDoc(doc);
    xmlFree(cur);
}

/*******************************************************************************
 * cmd_r smg1210_xml_parse_to_struct(char* mis_string)                         * 
 * INTERFACE:                                                                  * 
 *    char* mis_string: xml string that MIS sys post to smg1210.               *     
 * USAGE:                                                                      *     
 *    Parsing starts here......                                                *     
 * RETURN:                                                                     *     
 *    struct cmd_r: Contains info that packing needs.                          *     
 *******************************************************************************/
cmd_query_prog_r smg1210_xml_parse_to_struct(char* mis_string)
{
    /* Apply memory space for cmd_msg */
    smg1210_cmd_msg* cmd_msg = malloc(sizeof(smg1210_cmd_msg)+1);
    
    /*
     * get_msg(cmd_msg, mis_string)
     * INTERFACE:
     *    struct cmd_msg: Contains all the prop info within Msg node.
     * USAGE:
     *    Invoke get_msg(), all the parsing starts......
     * RETURN:
     *    void.
     */
	get_msg(cmd_msg , mis_string);

    /*Marking: Finish parsing xml string.*/
	printf("\n==== Parse done ====\n");


    /*SrcCode DstCode互换模块*/
    //swap_srccode_dstcode(my_cmd_query_prog_r.SrcCode, my_cmd_query_prog_r.DstCode);

#if 0
    /*Marking:Global struct to get packing info builed up success.*/
    if(0 != sizeof(my_cmd_query_prog_r))
    {
        printf("\n  [Parse]Reply struct build up success!   \n");

        printf("\n  my_cmd_query_prog_r: Version:      %s\n",   my_cmd_query_prog_r.Version);
        printf("    my_cmd_query_prog_r: Type:         %s\n",   my_cmd_query_prog_r.Type);
        printf("    my_cmd_query_prog_r: DataTime:     %s\n",   my_cmd_query_prog_r.DateTime);

        /*Marking the original value of SrcCode and DstCode*/
        printf("    my_cmd_query_prog_r: ORG SrcCode:  %s\n",   my_cmd_query_prog_r.SrcCode);
        printf("    my_cmd_query_prog_r: ORG DstCode:  %s\n",   my_cmd_query_prog_r.DstCode);
        
        /*Marking the value ofMarks处理后的SrcCode, DstCode*/
        printf("    my_cmd_query_prog_r: SrcCode:      %s\n",   my_cmd_query_prog_r.SrcCode);
        printf("    my_cmd_query_prog_r: DstCode:      %s\n",   my_cmd_query_prog_r.DstCode);

        /*ReplyID的值来源于MsgID, SrcUrl的值取出以在post时使用*/
        printf("    my_cmd_query_prog_r: ReplyID:      %s\n",   my_cmd_query_prog_r.ReplyID);
        printf("    my_cmd_query_prog_r: SrcUrl:       %s\n",   my_cmd_query_prog_r.SrcUrl);
        
        /*type指命令种类,有搜台, 选台, Set, Get*/
    	printf("\n  my_cmd_query_prog_r: type:         %s\n",   my_cmd_query_prog_r.type);
        printf("    my_cmd_query_prog_r: CellName:     %s\n",   my_cmd_query_prog_r.CellName);
        printf("    my_cmd_query_prog_r: GroupName:    %s\n",   my_cmd_query_prog_r.GroupName);
        printf("    my_cmd_query_prog_r: DeviceName:   %s\n",   my_cmd_query_prog_r.DeviceName);
    }
#endif 

    /*Return global struct my_cmd_query_prog_r which contains all the info the packing needs*/
	return my_cmd_query_prog_r;

    /*free memory space cmd_msg used*/
	free(cmd_msg);
}
