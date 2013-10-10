//XML测试相关

//报警查询上报相关
typedef struct 
{
	int  	   Value;           	//返回信息 0.成功     1.失败 
	char       Desc[20];            //返回描述 “成功”,    “失败”, 
	int        Freq;				//频率
	int        Index;				//通道号，（用于扩展槽号）
	int        Count;     
}XML_ALA_REP_HEAD;

typedef struct 
{
	int	  Type;
    	char      Desc[20];
	int 	  Value;
	char      Time[20];     
}XML_ALA_REP_INF;


void TestAlarmReportXml( int Type, int TdFlag, int TdCnt, BjValueNew bjValue[MAX_REP_CNT] )	//测试报警XML上报
{

        char              data[2000] = {0,};
	XML_ALA_REP_HEAD  xmlAlaRepHead;
	XML_ALA_REP_INF	  xmlAlaRepInfArray[MAX_REP_CNT];
	int 		  i;
        int               pos,len, cnt;

        xmlAlaRepHead.Value = 0;           	//返回信息 0.成功     1.失败 
	strcpy(xmlAlaRepHead.Desc, "操作成功");  	//返回描述 “成功”,    “失败”, 
	xmlAlaRepHead.Freq = 482000;	 	//频率
	xmlAlaRepHead.Index= 1;			//通道号，（用于扩展槽号）
	xmlAlaRepHead.Count= 1;     

        cnt = xmlAlaRepHead.Count;
        for (i=0; i<cnt; i++)
        {
		xmlAlaRepInfArray[i].Type  = i+1;
		sprintf( xmlAlaRepInfArray[i].Desc, "错误%d", i+1);
            	xmlAlaRepInfArray[i].Value = 1;
		strcpy(xmlAlaRepInfArray[i].Time, "2009-03-31 10:00:00"); 
        }
        
        pos = 0;

        memcpy(data,     (char*)(&xmlAlaRepHead),  sizeof(XML_ALA_REP_HEAD) );

        pos = sizeof(XML_ALA_REP_HEAD);
        memcpy(data+pos, (char*)xmlAlaRepInfArray, sizeof(XML_ALA_REP_INF)*cnt);
      
        len = sizeof(XML_ALA_REP_HEAD) + sizeof(XML_ALA_REP_INF)*cnt;

        //data 数据 ＋  len数据长度 


}
