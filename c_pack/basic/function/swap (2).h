#ifndef SWAP_H
#define SWAP_H

#define MAX_1210_CMD_MAX_PROP_LEN 1024

typedef struct cmd_r_s
{
    char SrcCode[MAX_1210_CMD_MAX_PROP_LEN];
    char DstCode[MAX_1210_CMD_MAX_PROP_LEN];
}cmd_r;  

void swap_srccode_dstcode(char* srccode_orig, char* dstcode_orig);

#endif
