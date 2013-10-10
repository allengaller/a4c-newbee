
MIS接口协议

1 ==== 通用要求 ====
1.1 数据交换文件产生规则
数据交换文件中所有文字信息全部大小写敏感。

1.2 通用属性定义
“Date” 属性：       格式为“yyyy-mm-dd”，其中“yyyy”、“mm”、“dd”分别表示年、月、日，数据长度分别为4、2、2，不够部分以0 补足，如：“2003-08-25”、“2003-12-07”等；
“DateTime”属性：   格式为“yyyy-mm-dd hh:mi:ss”，其中“yyyy”、“mm”、“dd” 、“hh” 、“mi” 、“ss”分别表示年、月、日、时、分、秒，数据长度分别为4、2、2、2、2、2，不够部分以0
补足，其中小时为24 小时制，如：“ 2003-08-25 12:50:23 ”、“ 2003-12-07 08:48:09”等；

1.3 数据交换规则
数据交换规则分为两个交换形式：
    1.    应用代理与接口代理进行数据交换。
            应用代理下行：应用代理下发给接口代理，应用代理仅下发设置通知。
            应用代理上行：应用代理接收接口代理的回复。

    2.    接口代理与设备进行数据交换。
            接口代理下行：接口代理下发给设备。接口代理根据通知从数据库查询取数，
            生成接口代理的参数设置XML 下发给设备。
            接口代理上行：接口代理接收设备的回复。

1.4 数据交换请求文件格式
应用代理向口代理发送的数据交换请求指令，接口代理向设备发送的数据
交换请求指令均采用XML 语言作为描述语言,文档内容采用UTF-8 编码，其基本结构如下：
<?xml version="1.0" encoding="utf-8" standalone="yes" ?>
<Msg Version="1" MsgID="2" Type="MISAppToInterface" DateTime="2010-02-03 15:30:00" SrcCode="110000G01" DstCode="110000M01"
    SrcUrl="http://10.24.32.28:8089/servlet/casreceiver" DstCode="110000C01" Priority="1">
    <!-- 具体交换应答数据-->
</Msg>

根元素“Msg”是应用代理向接口代理，接口代理向设备发出请求的基本元素。它包含如下几个属性（★号表示必须存在的属性）：

Version ★   数据交换接口标准的版本编号，目前版本为“1”。
MsgID ★     由应用代理下发时产生消息编号，每一个应用代理产生的编号唯一。
Type ★      取值为“MISAppDown”，表示应用代理向接口代理发送请求；
DateTime ★  请求产生的日期和时间，具体格式参见通用“DateTime”属性定义。
SrcCode     消息来源编码，此处使用MIS编码，具体编码格式参见附录A；
SrcUrl      指明应用代理或接口代理接收用来上报数据服务的URL 编码，如为空则使用MIS 系统本地保存的URL。
DstCode     消息目标编码，此处使用设备编码，具体编码格式参见附录B。
Priority    命令优先级,分为1 到10. 1 的优先级最高,10的最低。

1.5 数据交换应答文件格式
接口代理向应用代理返回应答数据的接口，设备向接口代理返回应答数据的
接口，均采用XML 语言作为描述语言,文档内容采用UTF-8 编码，其基本结构如下：
正常设置：
<?xml version="1.0" encoding="utf-8" standalone="yes" ?>
<Msg Version="1" MsgID="1" Type="MISInterfaceToApp" DateTime="2010-02-03 15:30:00" SrcCode="110000M01" DstCode="110000G01">
    <Return Type="xxxx" Value="0" Desc="成功" Redirect=""/>
</Msg>

正常查询命令返回：
<?xml version="1.0" encoding=" utf-8" standalone="yes" ?>
<Msg Version="1" MsgID="1" Type=" MISInterfaceToApp" DateTime="2010-02-03 15:30:00" SrcCode="110000M01" DstCode="110000G01">
    <Return Type="xxxx" Value="0" Desc="成功" Redirect=""/>
        <ReturnInfo>
            <NVRVideoHistoryInquiry>
                <NVRVideoHistory URL="192.168.0.1"/>
            </NVRVideoHistoryInquiry>
        </ReturnInfo>
     </Return>
</Msg>

异常返回：
<?xml version="1.0" encoding="GB2312" standalone="yes" ?>
<Msg Version="1" MsgID="1" Type=" MISInterfaceToApp" DateTime="2002-08-17 15:30:00" SrcCode="110000M01" DstCode="110000G01">
    <Return Type="xxxx" Value="0" Desc="前端处理异常" Redirect=""/>
        <ErrReport>
            <AlarmThreshold Type="1" Desc="载噪比" DownThreshold="50" UpThreshold="90" Comment="内部错误"/>
        </ErrReport>
</Msg>

根元素“Msg”是设备向接口代理，或接口代理向应用代理返回应答信息
数据接口标准的基本元素。它包含如下几个属性（★号表示必须存在的属性）：
Version ★       数据交换接口标准的版本编号，目前版本为“1”。
MsgID ★         由设备产生的唯一消息编号。
Type ★          取值为“MISInterfaceToApp”，表示从接口代理查询得到的返回应答数据。
DateTime ★      数据产生的日期和时间，具体格式参见通用“DateTime”属性定义。
SrcCode ★       消息源编码，此处使用设备编码，具体编码格式参见附录B，和指令发出文件中的DstCode对应。
DstCode ★       消息目标编码，此处使用MIS编码，具体编码格式参见附录A，和指令发出文件中的SrcCode对应。
ReplyID ★       应答数据对应的监管请求的MsgID。元素“Return”是描述设备执行MIS请求的结果状态。它包含如下几个属性（★号表示必须存在的属性）：
Type ★          描述设备执行的MIS请求
Value ★         返回设备执行MIS请求的处理结果的代码，取值如下:
    0: 成功
    1: 设备处理异常
         设备在处理命令时,发生了异常，此时ErrReport 字段必定存在，该字段描述详细的错误信息
    2：没有查到相应数据；
       MIS 在查询内容时，设备发现要查询的内容不存在，此时返回“没有查到相应数据”，此时ErrReport字段不存在
    3: 命令格式错误下发命令格式不合法. 此时ErrReport 字段不存在Desc 返回值的描述，限定在100字符以内.Redirect 当设备处理成功后返回应答数据文件重定向的URL，此时本次应答的XML 文
         件中将不包含详细数据，应答数据将由MIS 到指定的URL 下载。重定向数据文件格式为XML 文本文件，文件后缀为“.xml”，如果数据文件大于1M，可以将此XML文件采用ZIP 格式进行压缩（ZIP 
         文件格式参见相关国际标准），文件名不变，后缀为“.zip”，同时一个ZIP文件的顶层目录只能包含一个同名XML 数据文件。
         例如：
            Redirect="http://10.1.1.88/MHPR2003-02-01.xml"
            Redirect="http://10.1.1.88/MHPR2003-02-01.zip"
    
    元素“ReturnInfo”是设备返回信息的描述。若需要返回内容信息则该元素就存在(如指标查询等内容命令),否则就不存在(设置命令)。
    元素“ErrReport”是描述设备执行请求的异常描述。如果在执行请求时发生了异常就会存在. 元素“ErrReport”下包含的项是发生异常的操作命令.
    它包含如下几个属性（★号表示必须存在的属性）：
   Comment ★ 描述设备执行的MIS 请求发生错误的详细原因.例如“数据库读写错误” “内部处理异常”等。此处由设备自己定义，MIS 只用显示出来。

2 ==== 资源 ====

2.1 ==== 参数设置 Set====

功能描述
参数设置：用户通过UI 操作设置设备端模块的参数。

应用代理下行
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISInterfaceToDevice" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" 
    SrcUrl="http://10.1.1.1:8089/" Priority="1">
    <Set GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="Demux">
        <Module Name="节目名称"  Value="CCTV1" />
        <Module Name="PMT PID"  Value="101" />
        <Module Name="PCR PID"  Value="102" />
    </Set>
</Msg>

应用代理上行
成功
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISDeviceToInterface" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" ReplyID="2">
    <Return type="Set" GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="Demux1" Value="0" Desc="成功"></Return>
</Msg>

失败
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISDeviceToInterface" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" ReplyID="2">
    <Return type="Set" GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="Demux1" Value="1" Desc="成功">
        <ErrReport Commont="内部错误" />
    </Return>
</Msg>

命令格式描述

AppSetting ★        标识应用代理参数设置
GroupName           标识组名String
DeviceName          标识设备名称String
CellName            单元名String
InterfaceSetting ★  标识接口代理参数设置
Module              标识模块
Name                标识模块名称String
Value               标识模块值

2.2 ====参数同步 Get====

功能描述:参数同步：用户过通过UI 操作，获取设备端参数，实现MIS 与设备端的参数同步。

应用代理 下行
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISInterfaceToDevice" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" 
    SrcUrl="http://10.1.1.1:8089/" Priority="1">
    <Get GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="Demux">
        <Module Name="节目名称" />
        <Module Name="PMT PID" />
        <Module Name="PCR PID" />
    </Get>
</Msg>

应用代理 上行
成功
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISDeviceToInterface" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" ReplyID="2">
    <Return type="Get" GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="Demux1" Value="0" Desc="成功">
        <ReturnInfo>
            <Module Name="PMT PID" Value="101" />
            <Module Name="节目名称" Value="CCTV1" />
            <Module Name="PCR PID" Value="102" />
        </ReturnInfo>
    </Return>
</Msg>

失败
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISDeviceToInterface" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" ReplyID="2">
    <Return type="Get" GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="Demux1" Value="1" Desc="失败">
        <ErrReport comment="内部错误" />
    </Return>
</Msg>

命令格式描述
Set ★       标识应用代理参数同步
GroupName   标识组名String
DeviceName  标识设备名称String
CellName    单元名String
Get ★       标识接口代理参数同步
Cell        标识单元
Name        标识单元名称
Module      标识模块
Name        标识模块名称String
Value       标识模块值

2.3 ==== 搜台 prog_query ====

功能描述:搜台
应用代理下行
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISInterfaceToDevice" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" 
SrcUrl="http://10.1.1.1:8089/" Priority="1">
    <搜台GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="RISC"></搜台>
</Msg>

//
<Msg Version="4" ReplyID="2" Type="MISDeviceToInterface" DateTime="2010-02-03 11:12:00" SrcCode="110000N01" DstCode="110000X01"><Return type="搜台" GroupName="中国_北京_海淀_AU5823432432423423432400组" DeviceName="AU5800-1" CellName="RISC" Desc="成功" Value="0"></Return></Msg>
//



应用代理上行
2.3.5.1 成功
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISDeviceToInterface" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" ReplyID="2">
    <Return type="搜台" GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="RISC" Value="0" Desc="成功">
        <RetureInfo>
        <Module Name="serviceID 1" Value="257" />
        <Module Name="节目名称1" Value="CCTV1"></Module>
        <Module Name="PMT PID 1" Value="257"></Module>
        <Module Name="PCR PID 1" Value="8190"></Module>
        <Module Name="数据PID个数1" Value="2"></Module>
        <Module Name="DATA PID1-1" Value="512"></Module>
        <Module Name="DATA PID1-1属性" Value="VDEC_MPEG2"></Module>
        <Module Name="DATA PID1-2" Value="650"></Module>
        <Module Name="DATA PID1-2属性" Value="ADEC_MP3"></Module>
        <Module Name="serviceID 2" Value="258" />
        <Module Name="节目名称2" Value="CCTV2"></Module>
        <Module Name="PMT PID 2" Value="253"></Module>
        <Module Name="PCR PID 2" Value="8190"></Module>
        <Module Name="数据PID个数2" Value="2"></Module>
        <Module Name="DATA PID2-1" Value="513"></Module>
        <Module Name="DATA PID2-1属性" Value="VDEC_MPEG2"></Module>
        <Module Name="DATA PID2-2" Value="660"></Module>
        <Module Name="DATA PID2-2属性" Value="ADEC_MP3"></Module>
        </RetureInfo>
    </Return>
</Msg>
    
失败
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISDeviceToInterface" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" ReplyID="2">
    <Return type="搜台" GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="RISC" Value="1" Desc="失败"></Return>
    <ErrReport Commont="内部错误"></ErrReport>
</Msg>

2.4 ==== 选台 prog_select ====

功能描述: 选台

应用代理下行
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISInterfaceToDevice" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" 
SrcUrl="http://10.1.1.1:8089/" Priority="1">
    <选台 GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="RISC">
        <Module Name="待解码的PCR PID" Value="8190" />
        <Module Name="待解码的视频PID" Value="257"></Module>
        <Module Name="待解码的音频PID" Value="512"></Module>
        <Module Name="待解码视频PID类型" Value="VDEC_MPEG2"></Module>
        <Module Name="待解码音频PID类型" Value="ADEC_MP3"></Module>
    </选台>
</Msg>

应用代理上行
2.4.5.1 成功
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISDeviceToInterface" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" ReplyID="2">
    <Return type="选台" GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="RISC" Value="0" Desc="成功"></Return>
</Msg>

失败
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISDeviceToInterface" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" ReplyID="2">
    <Return type="选台" GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="RISC" Value="1" Desc="失败">
        <ErrReport comment="内部错误" />
    </Return>
</Msg>

3 ===== 状态 ====

实时报警

功能描述:设备主动向MIS 系统发送报警XML，由接口代理解析报警XML 并入库，同时通知应用代理从数据库读取报警信息。

应用代理上行
成功
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISInterfaceToApp" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" ReplyID="2">
    <Return type="AlarmGet" GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="Encode" Value="0" Desc="成功">
        <ReturnInfo>
            <AlarmGet type="1" Time="2010-02-04 18:07:00" />
        </ReturnInfo>
    </Return>
</Msg>

失败
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISInterfaceToApp" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" ReplyID="2">
    <Return type="AlarmGet" GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="Demux1" Value="1" Desc="失败">
        <ErrReport comment="内部错误" />
    </Return>
</Msg>

接口代理上行
成功
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISDeviceToInterface" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" ReplyID="2">
    <Return type="AlarmGet" GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="Encode" Value="0" Desc="成功">
        <ReturnInfo>
            <AlarmGet type="1" Desc="AV信号失锁" Time="2010-02-04 18:07:00" />
        </ReturnInfo>
    </Return>
</Msg>

失败
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISDeviceToInterface" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" ReplyID="2">
    <Return type="AlarmGet" GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="Encode" Value="1" Desc="失败">
        <ErrReport comment="内部错误" />
    </Return>
</Msg>

命令格式描述
AlarmGet        标识查询内容
ReplyID -1      代表是主动上报,否则一定大于或等于零
Type            报警类型，由设备级提供，可暂不使用。UINT
Desc            标识有返回数据String
ReturnInfo      返回指标的具体值
Value           错误描述,范围
    0:没有发生.UCHAR
    1:正在发生.
    2:恢复了.
Time 报警发生时间
格式yyyy-mm-dd hh:mi:ss”，其中“yyyy”、“mm”、“dd”、“hh”、“mi”、“ss”分别表示年、月、日、时、分、秒，数据长度分别为4、2、2、2、2、2，不够部分以0 补足，其中小时为24 小时制，
如：“2003-08-25 12:50:23”、“ 2003-12-0708:48:09”等；

4 ==== 附录A ====
SrcCode 格式：“结点ID_组ID_设备ID”
结点ID，组ID，设备ID 分别为10 位，SrcCode 共32 位
如：0000000001_0000000001_0000000001
SrcCode 的生成：MIS 网管添加设备时自动生成SrcCode，并由网管下发给设备，设备端记录下来。
DstCode：        MIS 配置文件中进行配置，默认为“MIS”
