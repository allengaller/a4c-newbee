#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "swap.h"



void swap_srccode_dstcode(char* srccode_orig_t, char* dstcode_orig_t)
{
    char* swap = NULL;
    
    char*   srccode_orig_t = NULL;
    char*   dstcode_orig_t = NULL;
    swap = malloc(strlen(my_cmd_r.SrcCode)+1);
    
    /*Save to original value for comparing*/
    strcpy(srccode_orig , my_cmd_r.SrcCode);     
    strcpy(dstcode_orig , my_cmd_r.DstCode);
    
    /*Swap*/
    strcpy(swap , srccode_orig);
    strcpy(srccode_orig, dstcode_orig);
    strcpy(dstcode_orig , swap);

    strcpy(my_cmd_r.SrcCode, srccode_orig);     
    strcpy(my_cmd_r.DstCode, dstcode_orig);

    /*Free memory space that vars used*/    
    free(swap);
    free(srccode_orig);
    free(dstcode_orig);

    if(!(strcmp(my_cmd_r.SrcCode, dstcode_orig) && strcmp(my_cmd_r.DstCode, srccode_orig)))
    {
        printf("\n  SrcCode DstCode swap done!  \n");
        #if 0
        /*Marking the original value of SrcCode and DstCode*/
        printf("    my_cmd_r: ORIG SrcCode:  %s\n",   my_cmd_r.SrcCode);
        printf("    my_cmd_r: ORIG DstCode:  %s\n",   my_cmd_r.DstCode);
        
        /*Marking the value ofMarks处理后的SrcCode, DstCode*/
        printf("    my_cmd_r: SrcCode:      %s\n",   my_cmd_r.SrcCode);
        printf("    my_cmd_r: DstCode:      %s\n",   my_cmd_r.DstCode);
        #endif   
    }
}

int main()
{
    char* SrcCode = NULL;
    char* DstCode = NULL;
        
    cmd_r my_cmd_r;
    my_cmd_r = malloc(sizeof(cmd_r));    

    SrcCode = malloc(strlen(my_cmd_r.SrcCode)+1);
    DstCode = malloc(strlen(my_cmd_r.DstCode)+1);
    
    strcpy(SrcCode, "1110111N");
    strcpy(DstCode, "1010010X");    
    
    swap_srccode_detcode(SrcCode, DstCode);
}

