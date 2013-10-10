#include<stdio.h>
#include<string.h>
#include<stdlib.h>

main()
{
    char* xml_string;
    unsigned int xml_string_len = sizeof("<Msg>qweasdzxc</Msg>!@##");
    printf("xml_string_len:%d\n", xml_string_len);
    
    xml_string = malloc(xml_string_len);
    memcpy(xml_string, "<Msg>qweasdzxc</Msg>!@##", xml_string_len);

    char* clean1;
    clean1 = strstr(xml_string, "</Msg>");
    unsigned int clean1_len = sizeof(clean1);
    printf("clean1:%s\n", clean1);
    printf("clean1_len:%d\n",clean1_len);
    
    unsigned int clean2_len = xml_string_len - clean1_len -1;
    printf("clean2_len:%d\n", clean2_len);
    char* clean2;
    clean2 = malloc(clean2_len);

    memcpy(clean2 , xml_string , clean2_len);
    printf("clean2:%s\n", clean2);

    free(xml_string);
    free(clean2);
}
