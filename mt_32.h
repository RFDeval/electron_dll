extern "C"
{
	HANDLE  __stdcall open_device(unsigned char nPort,unsigned long ulBaud);
	__int16 __stdcall close_device(HANDLE icdev);
	__int16 __stdcall get_version(HANDLE icdev,unsigned char *nVerLen,unsigned char *sVerData);
	__int16 __stdcall dev_beep(HANDLE icdev, unsigned char nMsec,unsigned char nMsec_end,unsigned char nTime );
	__int16 __stdcall dev_setbaud(HANDLE icdev,unsigned char nBaud);
	__int16 __stdcall dev_disp(HANDLE icdev, unsigned char nStatus);
	__int16 __stdcall dev_cardstate(HANDLE icdev, unsigned char* nCardStatus);
	__int16 __stdcall rf_encrypt(unsigned char *key,unsigned char *ptrSource, unsigned __int16 msgLen,unsigned char *ptrDest);
	__int16 __stdcall rf_decrypt(unsigned char *key,unsigned char *ptrSource, unsigned __int16 msgLen,unsigned char *ptrDest);
	__int16 __stdcall hex_asc(unsigned char *sHex,unsigned char *sAsc,unsigned long ulLength);
	__int16 __stdcall asc_hex(unsigned char *sAsc,unsigned char *sHex,unsigned long ulLength);
	__int16 __stdcall rf_desele(HANDLE icdev);
	__int16 __stdcall rf_halt(HANDLE icdev);
	//读产品序列号
	__int16 __stdcall dev_readsnr(HANDLE icdev,unsigned char nSnrLen,char* sSnrData);
	//写产品序列号
	__int16 __stdcall dev_writesnr(HANDLE icdev,unsigned char nSnrLen,char* sSnrData);
	//读EEPROM
	__int16 __stdcall dev_readeeprom(HANDLE icdev,unsigned short nAddr,unsigned short nDLen,unsigned char* sReadData);
	//写EEPROM
	__int16 __stdcall dev_writeeeprom(HANDLE icdev,unsigned short nAddr,unsigned short nDLen,unsigned char* sWriteData);
	//******************************* Contactless CPU card *****************************************//
	__int16 __stdcall OpenCard(HANDLE icdev, unsigned char nMode,unsigned char *sSnr,unsigned char *sCardInfo, unsigned char *nCardInfoLen) ;
	__int16 __stdcall Open_Card(HANDLE icdev, unsigned char nMode,unsigned char *sSnr) ;
	__int16 __stdcall Reset_Card(HANDLE icdev,unsigned char *sCardInfo, unsigned char *nCardInfoLen) ;
	__int16 __stdcall ExchangePro(HANDLE icdev, unsigned char *sCmd, unsigned short nCmdLen, unsigned char *sResp, unsigned short *nRespLen);
	__int16 __stdcall CloseCard(HANDLE icdev);
	__int16 __stdcall ExchangePro_hex(HANDLE icdev, char *sCmd,  char *sResp);

	//******************************* Contact CPU card and PSAM card ********************************//
	__int16 __stdcall ICC_Reset(HANDLE icdev, unsigned char nCardSet, unsigned char *sAtr, unsigned char *nAtrLen);
	__int16 __stdcall ICC_Reset_Baud(HANDLE icdev, unsigned char nCardSet, unsigned char nBaud,unsigned char *sAtr, unsigned char *nAtrLen);
	__int16 __stdcall ICC_PowerOn(HANDLE icdev, unsigned char nCardSet, unsigned char *sAtr, unsigned char *nAtrLen);
	__int16 __stdcall ICC_CommandExchange(HANDLE icdev, unsigned char nCardSet, unsigned char *sCmd, unsigned short nCmdLen, unsigned char *sResp, unsigned short *nRespLen);
	__int16 __stdcall ICC_PowerOff(HANDLE icdev, unsigned char nCardSet);
	__int16 __stdcall ICC_CommandExchange_hex(HANDLE icdev,  unsigned char nCardSet,  char *sCmd,  char *sResp);
	__int16 __stdcall ICC_PowerOn_Baud(HANDLE icdev, unsigned char nCardSet, unsigned char nBaud,unsigned char *sAtr, unsigned char *nAtrLen);

	//******************************* M1 card ********************************************************//
	__int16 __stdcall rf_reset(HANDLE icdev);
	__int16 __stdcall rf_card (HANDLE icdev,unsigned char nMode,unsigned char *sSnr);
	__int16 __stdcall rf_authentication_key (HANDLE icdev,unsigned char nMode,unsigned char nBlockaddr,unsigned char *sNkey);
	__int16 __stdcall rf_read (HANDLE icdev,unsigned char nAdr,unsigned char *sReadData);
	__int16 __stdcall rf_write (HANDLE icdev,unsigned char nAdr,unsigned char *sWriteData);
	__int16 __stdcall rf_initval(HANDLE icdev,unsigned char nAdr,unsigned long ulValue);
	__int16 __stdcall rf_readval(HANDLE icdev,unsigned char nAdr,unsigned long *ulValue);
	__int16 __stdcall rf_increment(HANDLE icdev,unsigned char nAdr,unsigned long ulValue);
	__int16 __stdcall rf_decrement(HANDLE icdev,unsigned char nAdr,unsigned long ulValue);
	__int16 __stdcall rf_transfer(HANDLE icdev,unsigned char nAdr);
	__int16 __stdcall rf_terminal(HANDLE icdev);
	__int16 __stdcall rf_restore(HANDLE icdev,unsigned char nAdr); 

	//******************************* Record **********************************************************//
	__int16 __stdcall open_record(HANDLE icdev);
	__int16 __stdcall close_record(HANDLE icdev);
	__int16 __stdcall nt_read(HANDLE icdev,unsigned long ulAddr,unsigned char* sRecordData);

	//******************************* SLE4442 ********************************************************//
	//接触式卡类型选择
	__int16 __stdcall contact_select(HANDLE icdev,unsigned char nCardType);
	__int16 _stdcall contact_verify(HANDLE icdev, unsigned char *nCardType);
	//判断是否为4442卡
	__int16 __stdcall sle4442_is42( HANDLE icdev,unsigned char* sCardState );
	//读4442卡
	__int16 __stdcall sle4442_read(HANDLE icdev,unsigned char nAddr,unsigned short nDLen,unsigned char* sRecData);
	//写4442卡
	__int16 __stdcall sle4442_write(HANDLE icdev,unsigned char nAddr,unsigned short nWLen,unsigned char* sWriteData);
	//442卡校验密码
	__int16 __stdcall sle4442_pwd_check(HANDLE icdev,unsigned char* sKey);
	// 读密码
	//__int16 __stdcall sle4442_pwd_read(HANDLE icdev,unsigned char* sKey);
	//修改密码
	__int16 __stdcall sle4442_pwd_modify(HANDLE icdev,unsigned char* sKey);
	//读保护位
	__int16 __stdcall sle4442_probit_read(HANDLE icdev,unsigned char* nLen,unsigned char* sProBitData);
	//写保护位
	__int16 __stdcall sle4442_probit_write(HANDLE icdev,unsigned char nAddr,unsigned short nWLen,unsigned char*sProBitData);
	//读错误计数
	__int16 __stdcall sle4442_errcount_read(HANDLE icdev,unsigned char* nErrCount);
	
	//******************************* SLE4428 ********************************************************//
	//检测是否为4428卡
	__int16 __stdcall sle4428_is28(HANDLE icdev,unsigned char* sCardState);
	//读4428卡
	__int16 __stdcall sle4428_read(HANDLE icdev,unsigned short nAddr,unsigned short nDLen,unsigned char* sRecData);
	//写4428卡
	__int16 __stdcall sle4428_write(HANDLE icdev,unsigned short nAddr,unsigned short nWLen,unsigned char* sWriteData);
	//4428卡校验密码
	__int16 __stdcall sle4428_pwd_check(HANDLE icdev,unsigned char* sKey);
	//修改密码
	__int16 __stdcall sle4428_pwd_modify(HANDLE icdev,unsigned char* sKey);
	// 读密码
	//__int16 __stdcall sle4428_pwd_read(HANDLE icdev,unsigned char* sKey);
	//带保护位读数据
	__int16 __stdcall sle4428_probit_readdata(HANDLE icdev,unsigned short nAddr,unsigned short nDLen,unsigned char* sRecData);
	//带保护位写数据
	__int16 __stdcall sle4428_probit_writedata(HANDLE icdev,unsigned short nAddr,unsigned short nWLen,unsigned char*sWriteData);
	//读错误计数
	//__int16 __stdcall sle4428_errcount_read(HANDLE icdev,unsigned char* nErrCount);
	

	//******************************* AT88SC102 *****************************************************//
	//卡片密码校验
	__int16 __stdcall at88sc102_pwd_check(HANDLE icdev,unsigned char* sKey);

	//修改卡片密码
	__int16 __stdcall at88sc102_pwd_modify(HANDLE icdev,unsigned char* sNewKey);

	//读取卡片密码
	__int16 __stdcall at88sc102_pwd_read(HANDLE icdev,unsigned char* sKey);

	//用户区1擦除密码校验
	__int16 __stdcall at88sc102_ua1_epwd_check(HANDLE icdev,unsigned char* sKey);

	//修改用户区1擦除密码
	__int16 __stdcall at88sc102_ua1_epwd_modify(HANDLE icdev,unsigned char* sNewKey);
	
	//读取用户区1擦除密码
	__int16 __stdcall at88sc102_ua1_epwd_read(HANDLE icdev,unsigned char* sKey);
	
	//用户区2擦除密码校验
	__int16 __stdcall at88sc102_ua2_epwd_check(HANDLE icdev,unsigned char* sKey);
	
	//修改用户区2擦除密码
	__int16 __stdcall at88sc102_ua2_epwd_modify(HANDLE icdev,unsigned char* sNewKey);
	
	//读取用户区2擦除密码
	__int16 __stdcall at88sc102_ua2_epwd_read(HANDLE icdev,unsigned char* sKey);
	
	//读取密码错误计数器值
	__int16 __stdcall at88sc102_pwd_errorcount(HANDLE icdev,unsigned char* nErrorCount);
	
	//读取EZ2擦除计数器值
	__int16 __stdcall at88sc102_ua2_fusecount(HANDLE icdev,unsigned char* nCount);
	
	/*保护位清零:写保护位1，写保护位2，读保护位1，读保护位2
	nProBitType:1-写保护位1;2--写保护位2;3--读保护位1;4--读保护位2.
	*/
	__int16 __stdcall at88sc102_probit_clr(HANDLE icdev,unsigned char nProBitType);
	
	//从用户区1指定地址读取数据
	__int16 __stdcall at88sc102_ua1_readdata(HANDLE icdev,unsigned char nAddr,unsigned char nRLen,unsigned char* sRecData);
	
	//从用户区2指定地址读取数据
	__int16 __stdcall at88sc102_ua2_readdata(HANDLE icdev,unsigned char nAddr,unsigned char nRLen,unsigned char* sRecData);
	//擦除用户区1数据
	__int16 __stdcall at88sc102_ua1_clrdata(HANDLE icdev);
	
	//擦除用户区2数据，nECState:1--EC关闭,2--EC打开.
	__int16 __stdcall at88sc102_ua2_clrdata(HANDLE icdev,unsigned char nECState);
	
	//模拟熔断
	__int16 __stdcall at88sc102_Anafuse(HANDLE icdev);
	
	//取消模拟熔断
	__int16 __stdcall at88sc102_Anafuse_cancel(HANDLE icdev);
	
	//修改用户区1数据
	__int16 __stdcall at88sc102_ua1_modifydata(HANDLE icdev,unsigned char nAddr,unsigned char nMLen,unsigned char* sModifyData);
	
	//修改用户区2数据，nECState: 1--EC关闭;2--EC打开.
	__int16 __stdcall at88sc102_ua2_modifydata(HANDLE icdev,unsigned char nECState,unsigned char nAddr,unsigned char nMLen,unsigned char* sModifyData);
	
	//熔断ISSUER FUSE
	__int16 __stdcall at88sc102_fuse_issuerfuse(HANDLE icdev);
	
	//熔断EC2EN FUSE（即无擦除次数限制）
	__int16 __stdcall at88sc102_fuse_ec2enfuse(HANDLE icdev);

	//检查是否为102卡.0--102卡，非0--不是102卡。
	__int16 __stdcall at88sc102_is102(HANDLE icdev,unsigned char* nCardState);


	//******************************* 密码键盘操作 *****************************************************//
	/*//指令调试接口函数
	__int16 __stdcall dev_pwdkb(HANDLE icdev,unsigned char nTimeouts,unsigned char nRetain,unsigned char nCmdLen,unsigned char* sKBCmd,unsigned char* nRecLen,unsigned char* sRecData);
	//输入密码
	__int16 __stdcall dev_pwdkb_getpwd(HANDLE icdev,unsigned char nTimeouts,unsigned char* nPwdLen,unsigned char* sPwdData);

	//再次输入密码
	__int16 __stdcall dev_pwdkb_getpwd_again(HANDLE icdev,unsigned char nTimeouts,unsigned char* nPwdLen,unsigned char* sPwdData);

	//输入密码，加密
	__int16 __stdcall dev_pwdkb_getpwd_encrypt(HANDLE icdev,unsigned char nTimeouts,unsigned char* nPwdLen,unsigned char* sPwdData);

	//再次输入密码，加密
	__int16 __stdcall dev_pwdkb_getpwd_again_encrypt(HANDLE icdev,unsigned char nTimeouts,unsigned char* nPwdLen,unsigned char* sPwdData);

	//11-08-25 密码键盘函数更改。
	//设置密码键盘超时时间   
	__int16 __stdcall pwdkb_settimeout(HANDLE icdev,unsigned char nTimeouts);
	//设置密码长度              
	__int16 __stdcall pwdkb_setpwdlen(HANDLE icdev,unsigned char nPwdLen);
	//下载主密钥                
	__int16 __stdcall pwdkb_load_mainkey(HANDLE icdev,unsigned char nDesType,unsigned char nMainKeyNo,unsigned char* sMainKey);
	//下载工作密钥              
	__int16 __stdcall pwdkb_load_workkey(HANDLE icdev,unsigned char nDesType,unsigned char nMainKeyNo,unsigned char nWorkKeyNo,unsigned char* sWorkKey);
	//获取明文密码              
	__int16 __stdcall pwdkb_getpwd(HANDLE icdev,unsigned char* nPwdLen,unsigned char* sPwdData);
	//获取明文密码,再次输入密码              
	__int16 __stdcall pwdkb_getpwd_again(HANDLE icdev,unsigned char* nPwdLen,unsigned char* sPwdData);
	//获取密文密码              
	__int16 __stdcall pwdkb_getpwd_encrypt(HANDLE icdev,unsigned char nWorkKeyNo,unsigned char* sCardNo,unsigned char* nPwdLen,unsigned char* sPwdData);
	//获取密文密码,再次输入密码              
	__int16 __stdcall pwdkb_getpwd_again_encrypt(HANDLE icdev,unsigned char nWorkKeyNo,unsigned char* sCardNo,unsigned char* nPwdLen,unsigned char* sPwdData);*/

	//DES加密函数
	__int16 __stdcall des_encrypt(unsigned char *key,unsigned char *ptrSource, unsigned char msgLen,unsigned char *ptrDest);
	//DES解密函数
	__int16 __stdcall des_decrypt(unsigned char *key,unsigned char *ptrSource, unsigned char msgLen,unsigned char *ptrDest);
	//3DES加密函数
	__int16 __stdcall des3_encrypt(unsigned char *key,unsigned char *ptrSource, unsigned char msgLen,unsigned char *ptrDest);
	//3Des解密函数
	__int16 __stdcall des3_decrypt(unsigned char *key,unsigned char *ptrSource, unsigned char msgLen,unsigned char *ptrDest);

	//密码键盘数据解密
	__int16 __stdcall pwd_decrypt(unsigned char *ptrSource, unsigned char nDataLen,unsigned char *ptrDest);

	//客户要求的封装函数
	//打开密码键盘
	__int16 __stdcall mw_kb_open(int port, long baud);
	//密码键盘操作关闭端口
	__int16 __stdcall mw_kb_close(HANDLE icdev);
	//密码键盘下载主密钥
	__int16 __stdcall mw_kb_downloadmainkey(HANDLE icdev,int destype,int mainkeyno,unsigned char *mainkey);
	//密码键盘下载工作密钥
	__int16 __stdcall mw_kb_downloaduserkey(HANDLE icdev, int destype, int mainkeyno, int userkeyno, unsigned char *userkey);
	//密码键盘激活主密钥和工作密钥
	__int16 __stdcall mw_kb_activekey(HANDLE icdev, int mainkeyno,int userkeyno);
	//密码键盘设置输入密码长度
	__int16 __stdcall mw_kb_setpasslen(HANDLE icdev, int passlen);
	//密码键盘设置超时时间
	__int16 __stdcall mw_kb_settimeout(HANDLE icdev, int timeout);
	//密码键盘获取明文密码
	__int16 __stdcall mw_kb_getpin(HANDLE icdev, int type, unsigned char *planpin);
	//密码键盘获取密文密码
	__int16 __stdcall mw_kb_getenpin(HANDLE icdev, int type, unsigned char *cardno, unsigned char *planpin);

	//下载工作密钥--密钥为明文
	__int16 __stdcall mw_kb_downloaduserkey_nb(HANDLE icdev, int destype, int mainkeyno,int userkeyno, unsigned char *userkey);
	//获取密文密码  1--输入密码,2--再次输入密码
	__int16 __stdcall mw_kb_getenpin_nb(HANDLE icdev, int type, unsigned char userkeyno, unsigned char *planpin);
	//LCD显示屏显示
	__int16 __stdcall lcd_display_string(HANDLE icdev, __int16 row, __int16 column,__int16 len, char *disp_buf);
	//LCD清屏
	__int16 __stdcall lcd_clear(HANDLE icdev);
	//设置键盘类型 0--内置密码键盘 1--外置密码键盘
	void __stdcall set_kb_type(int type); 
	//2.4G卡通道函数
	__int16 __stdcall ds_command_trn(HANDLE icdev,unsigned char *sCmd,unsigned short nCmdLen, unsigned char *sResp, unsigned short *nRespLen);
}