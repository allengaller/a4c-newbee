
==============================================搜台

2.3.2 应用代理下行
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISInterfaceToDevice" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" 
    SrcUrl="http://10.1.1.1:8089/" Priority="1">
    <搜台 GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="MHP1"></搜台>
</Msg>

*2.3.3 应用代理上行
*2.3.3.1 成功
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISDeviceToInterface" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" ReplyID="2">
    <Return type="搜台" GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="MHP1" Value="0" Desc="成功"></Return>
</Msg>

*2.3.3.2 失败
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISDeviceToInterface" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" ReplyID="2">
    <Return type="搜台" GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="MHP1" Value="1" Desc="失败">
        <ErrReport Commont="内部错误"></ErrReport>
    </Return>
</Msg>


==============================================选台

2.4.2 应用代理下行
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISAppToInterface" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" 
SrcUrl="http://10.1.1.1:8089/" Priority="1">
    <选台GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="MHP1"></选台>
</Msg>

2.4.3 应用代理上行
2.4.3.1 成功
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISInterfaceToApp" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" ReplyID="2">
    <Return type="选台" GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="MHP1" Value="0" Desc="成功"></Return>
</Msg>

2.4.3.2 失败
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISInterfaceToApp" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" ReplyID="2">
    <Return type="选台" GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="MHP1" Value="1" Desc="失败">
        <ErrReport comment="内部错误" />
    </Return>
</Msg>




==============================================Get
2.2.2 应用代理 下行
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISAppToInterface" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" 
    SrcUrl="http://10.1.1.1:8089/" Priority="1">
        <Get GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="Demux" />
</Msg>

2.2.3 应用代理 上行
2.2.3.1 成功
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISInterfaceToApp" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" ReplyID="2">
    <Return type="Get" GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="Demux" Value="0" Desc="成功"></Return>
</Msg>

2.2.3.2 失败
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISInterfaceToApp" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" ReplyID="2">
    <Return type="Get" GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="Demux" Value="1" Desc="失败">
        <ErrReport Commont="内部错误" />
    </Return>
</Msg>



==============================================Set
2.1.2 应用代理下行
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISAppToInterface" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" 
    SrcUrl="http://10.1.1.1:8089/" Priority="1">
    <Set GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="Demux1" />
</Msg>

2.1.3 应用代理上行
2.1.3.1 成功
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISInterfaceToApp" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" ReplyID="2">
    <Return type="Set" GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="Demux1" Value="0" Desc="成功"></Return>
</Msg>

2.1.3.2 失败
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Msg Version="4" MsgID="2" Type="MISInterfaceToApp" DateTime="2010-02-03 11:12:00" SrcCode="110000X01" DstCode="110000N01" ReplyID="2">
    <Return type="Set" GroupName="中国_北京_海淀_AU5800组" DeviceName="AU5800-1" CellName="Demux1" Value="1" Desc="失败">
        <ErrReport Commont="内部错误"></ErrReport>
    </Return>
</Msg>

