//XML�������

//������ѯ�ϱ����
typedef struct 
{
	int  	   Value;           	//������Ϣ 0.�ɹ�     1.ʧ�� 
	char       Desc[20];            //�������� ���ɹ���,    ��ʧ�ܡ�, 
	int        Freq;				//Ƶ��
	int        Index;				//ͨ���ţ���������չ�ۺţ�
	int        Count;     
}XML_ALA_REP_HEAD;

typedef struct 
{
	int	  Type;
    	char      Desc[20];
	int 	  Value;
	char      Time[20];     
}XML_ALA_REP_INF;


void TestAlarmReportXml( int Type, int TdFlag, int TdCnt, BjValueNew bjValue[MAX_REP_CNT] )	//���Ա���XML�ϱ�
{

        char              data[2000] = {0,};
	XML_ALA_REP_HEAD  xmlAlaRepHead;
	XML_ALA_REP_INF	  xmlAlaRepInfArray[MAX_REP_CNT];
	int 		  i;
        int               pos,len, cnt;

        xmlAlaRepHead.Value = 0;           	//������Ϣ 0.�ɹ�     1.ʧ�� 
	strcpy(xmlAlaRepHead.Desc, "�����ɹ�");  	//�������� ���ɹ���,    ��ʧ�ܡ�, 
	xmlAlaRepHead.Freq = 482000;	 	//Ƶ��
	xmlAlaRepHead.Index= 1;			//ͨ���ţ���������չ�ۺţ�
	xmlAlaRepHead.Count= 1;     

        cnt = xmlAlaRepHead.Count;
        for (i=0; i<cnt; i++)
        {
		xmlAlaRepInfArray[i].Type  = i+1;
		sprintf( xmlAlaRepInfArray[i].Desc, "����%d", i+1);
            	xmlAlaRepInfArray[i].Value = 1;
		strcpy(xmlAlaRepInfArray[i].Time, "2009-03-31 10:00:00"); 
        }
        
        pos = 0;

        memcpy(data,     (char*)(&xmlAlaRepHead),  sizeof(XML_ALA_REP_HEAD) );

        pos = sizeof(XML_ALA_REP_HEAD);
        memcpy(data+pos, (char*)xmlAlaRepInfArray, sizeof(XML_ALA_REP_INF)*cnt);
      
        len = sizeof(XML_ALA_REP_HEAD) + sizeof(XML_ALA_REP_INF)*cnt;

        //data ���� ��  len���ݳ��� 


}
