/*
<?xml version="1.0" encoding="utf-8"?>
<Msg Version="4" MsgID="10" Type="MISInterfaceToDevice" DateTime="2010-07-09 11:22:35" SrcCode="Mis" DstCode="2_6_20" SrcUrl="http://192.168.2.63:8080/Setup" Priority="1">
  <搜台 GroupName=" 全国 _ 北京 _ SMG1210 组 " DeviceName="SMG1210@192.168.0.171 " CellName="Input" />
</Msg>z���
*/

#include<string.h>
#include<stdio.h>
main()
{
    char s[] = "xml abc  xml d";
    char* delim ="xml";
    char* p;
    printf("strtok(s, delim):%s\n", strtok(s, delim));
    while(p = strtok(NULL,delim)) printf("p:%s\n",p);
        printf("\n");
}

