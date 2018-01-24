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
	//����Ʒ���к�
	__int16 __stdcall dev_readsnr(HANDLE icdev,unsigned char nSnrLen,char* sSnrData);
	//д��Ʒ���к�
	__int16 __stdcall dev_writesnr(HANDLE icdev,unsigned char nSnrLen,char* sSnrData);
	//��EEPROM
	__int16 __stdcall dev_readeeprom(HANDLE icdev,unsigned short nAddr,unsigned short nDLen,unsigned char* sReadData);
	//дEEPROM
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
	//�Ӵ�ʽ������ѡ��
	__int16 __stdcall contact_select(HANDLE icdev,unsigned char nCardType);
	__int16 _stdcall contact_verify(HANDLE icdev, unsigned char *nCardType);
	//�ж��Ƿ�Ϊ4442��
	__int16 __stdcall sle4442_is42( HANDLE icdev,unsigned char* sCardState );
	//��4442��
	__int16 __stdcall sle4442_read(HANDLE icdev,unsigned char nAddr,unsigned short nDLen,unsigned char* sRecData);
	//д4442��
	__int16 __stdcall sle4442_write(HANDLE icdev,unsigned char nAddr,unsigned short nWLen,unsigned char* sWriteData);
	//442��У������
	__int16 __stdcall sle4442_pwd_check(HANDLE icdev,unsigned char* sKey);
	// ������
	//__int16 __stdcall sle4442_pwd_read(HANDLE icdev,unsigned char* sKey);
	//�޸�����
	__int16 __stdcall sle4442_pwd_modify(HANDLE icdev,unsigned char* sKey);
	//������λ
	__int16 __stdcall sle4442_probit_read(HANDLE icdev,unsigned char* nLen,unsigned char* sProBitData);
	//д����λ
	__int16 __stdcall sle4442_probit_write(HANDLE icdev,unsigned char nAddr,unsigned short nWLen,unsigned char*sProBitData);
	//���������
	__int16 __stdcall sle4442_errcount_read(HANDLE icdev,unsigned char* nErrCount);
	
	//******************************* SLE4428 ********************************************************//
	//����Ƿ�Ϊ4428��
	__int16 __stdcall sle4428_is28(HANDLE icdev,unsigned char* sCardState);
	//��4428��
	__int16 __stdcall sle4428_read(HANDLE icdev,unsigned short nAddr,unsigned short nDLen,unsigned char* sRecData);
	//д4428��
	__int16 __stdcall sle4428_write(HANDLE icdev,unsigned short nAddr,unsigned short nWLen,unsigned char* sWriteData);
	//4428��У������
	__int16 __stdcall sle4428_pwd_check(HANDLE icdev,unsigned char* sKey);
	//�޸�����
	__int16 __stdcall sle4428_pwd_modify(HANDLE icdev,unsigned char* sKey);
	// ������
	//__int16 __stdcall sle4428_pwd_read(HANDLE icdev,unsigned char* sKey);
	//������λ������
	__int16 __stdcall sle4428_probit_readdata(HANDLE icdev,unsigned short nAddr,unsigned short nDLen,unsigned char* sRecData);
	//������λд����
	__int16 __stdcall sle4428_probit_writedata(HANDLE icdev,unsigned short nAddr,unsigned short nWLen,unsigned char*sWriteData);
	//���������
	//__int16 __stdcall sle4428_errcount_read(HANDLE icdev,unsigned char* nErrCount);
	

	//******************************* AT88SC102 *****************************************************//
	//��Ƭ����У��
	__int16 __stdcall at88sc102_pwd_check(HANDLE icdev,unsigned char* sKey);

	//�޸Ŀ�Ƭ����
	__int16 __stdcall at88sc102_pwd_modify(HANDLE icdev,unsigned char* sNewKey);

	//��ȡ��Ƭ����
	__int16 __stdcall at88sc102_pwd_read(HANDLE icdev,unsigned char* sKey);

	//�û���1��������У��
	__int16 __stdcall at88sc102_ua1_epwd_check(HANDLE icdev,unsigned char* sKey);

	//�޸��û���1��������
	__int16 __stdcall at88sc102_ua1_epwd_modify(HANDLE icdev,unsigned char* sNewKey);
	
	//��ȡ�û���1��������
	__int16 __stdcall at88sc102_ua1_epwd_read(HANDLE icdev,unsigned char* sKey);
	
	//�û���2��������У��
	__int16 __stdcall at88sc102_ua2_epwd_check(HANDLE icdev,unsigned char* sKey);
	
	//�޸��û���2��������
	__int16 __stdcall at88sc102_ua2_epwd_modify(HANDLE icdev,unsigned char* sNewKey);
	
	//��ȡ�û���2��������
	__int16 __stdcall at88sc102_ua2_epwd_read(HANDLE icdev,unsigned char* sKey);
	
	//��ȡ������������ֵ
	__int16 __stdcall at88sc102_pwd_errorcount(HANDLE icdev,unsigned char* nErrorCount);
	
	//��ȡEZ2����������ֵ
	__int16 __stdcall at88sc102_ua2_fusecount(HANDLE icdev,unsigned char* nCount);
	
	/*����λ����:д����λ1��д����λ2��������λ1��������λ2
	nProBitType:1-д����λ1;2--д����λ2;3--������λ1;4--������λ2.
	*/
	__int16 __stdcall at88sc102_probit_clr(HANDLE icdev,unsigned char nProBitType);
	
	//���û���1ָ����ַ��ȡ����
	__int16 __stdcall at88sc102_ua1_readdata(HANDLE icdev,unsigned char nAddr,unsigned char nRLen,unsigned char* sRecData);
	
	//���û���2ָ����ַ��ȡ����
	__int16 __stdcall at88sc102_ua2_readdata(HANDLE icdev,unsigned char nAddr,unsigned char nRLen,unsigned char* sRecData);
	//�����û���1����
	__int16 __stdcall at88sc102_ua1_clrdata(HANDLE icdev);
	
	//�����û���2���ݣ�nECState:1--EC�ر�,2--EC��.
	__int16 __stdcall at88sc102_ua2_clrdata(HANDLE icdev,unsigned char nECState);
	
	//ģ���۶�
	__int16 __stdcall at88sc102_Anafuse(HANDLE icdev);
	
	//ȡ��ģ���۶�
	__int16 __stdcall at88sc102_Anafuse_cancel(HANDLE icdev);
	
	//�޸��û���1����
	__int16 __stdcall at88sc102_ua1_modifydata(HANDLE icdev,unsigned char nAddr,unsigned char nMLen,unsigned char* sModifyData);
	
	//�޸��û���2���ݣ�nECState: 1--EC�ر�;2--EC��.
	__int16 __stdcall at88sc102_ua2_modifydata(HANDLE icdev,unsigned char nECState,unsigned char nAddr,unsigned char nMLen,unsigned char* sModifyData);
	
	//�۶�ISSUER FUSE
	__int16 __stdcall at88sc102_fuse_issuerfuse(HANDLE icdev);
	
	//�۶�EC2EN FUSE�����޲����������ƣ�
	__int16 __stdcall at88sc102_fuse_ec2enfuse(HANDLE icdev);

	//����Ƿ�Ϊ102��.0--102������0--����102����
	__int16 __stdcall at88sc102_is102(HANDLE icdev,unsigned char* nCardState);


	//******************************* ������̲��� *****************************************************//
	/*//ָ����Խӿں���
	__int16 __stdcall dev_pwdkb(HANDLE icdev,unsigned char nTimeouts,unsigned char nRetain,unsigned char nCmdLen,unsigned char* sKBCmd,unsigned char* nRecLen,unsigned char* sRecData);
	//��������
	__int16 __stdcall dev_pwdkb_getpwd(HANDLE icdev,unsigned char nTimeouts,unsigned char* nPwdLen,unsigned char* sPwdData);

	//�ٴ���������
	__int16 __stdcall dev_pwdkb_getpwd_again(HANDLE icdev,unsigned char nTimeouts,unsigned char* nPwdLen,unsigned char* sPwdData);

	//�������룬����
	__int16 __stdcall dev_pwdkb_getpwd_encrypt(HANDLE icdev,unsigned char nTimeouts,unsigned char* nPwdLen,unsigned char* sPwdData);

	//�ٴ��������룬����
	__int16 __stdcall dev_pwdkb_getpwd_again_encrypt(HANDLE icdev,unsigned char nTimeouts,unsigned char* nPwdLen,unsigned char* sPwdData);

	//11-08-25 ������̺������ġ�
	//����������̳�ʱʱ��   
	__int16 __stdcall pwdkb_settimeout(HANDLE icdev,unsigned char nTimeouts);
	//�������볤��              
	__int16 __stdcall pwdkb_setpwdlen(HANDLE icdev,unsigned char nPwdLen);
	//��������Կ                
	__int16 __stdcall pwdkb_load_mainkey(HANDLE icdev,unsigned char nDesType,unsigned char nMainKeyNo,unsigned char* sMainKey);
	//���ع�����Կ              
	__int16 __stdcall pwdkb_load_workkey(HANDLE icdev,unsigned char nDesType,unsigned char nMainKeyNo,unsigned char nWorkKeyNo,unsigned char* sWorkKey);
	//��ȡ��������              
	__int16 __stdcall pwdkb_getpwd(HANDLE icdev,unsigned char* nPwdLen,unsigned char* sPwdData);
	//��ȡ��������,�ٴ���������              
	__int16 __stdcall pwdkb_getpwd_again(HANDLE icdev,unsigned char* nPwdLen,unsigned char* sPwdData);
	//��ȡ��������              
	__int16 __stdcall pwdkb_getpwd_encrypt(HANDLE icdev,unsigned char nWorkKeyNo,unsigned char* sCardNo,unsigned char* nPwdLen,unsigned char* sPwdData);
	//��ȡ��������,�ٴ���������              
	__int16 __stdcall pwdkb_getpwd_again_encrypt(HANDLE icdev,unsigned char nWorkKeyNo,unsigned char* sCardNo,unsigned char* nPwdLen,unsigned char* sPwdData);*/

	//DES���ܺ���
	__int16 __stdcall des_encrypt(unsigned char *key,unsigned char *ptrSource, unsigned char msgLen,unsigned char *ptrDest);
	//DES���ܺ���
	__int16 __stdcall des_decrypt(unsigned char *key,unsigned char *ptrSource, unsigned char msgLen,unsigned char *ptrDest);
	//3DES���ܺ���
	__int16 __stdcall des3_encrypt(unsigned char *key,unsigned char *ptrSource, unsigned char msgLen,unsigned char *ptrDest);
	//3Des���ܺ���
	__int16 __stdcall des3_decrypt(unsigned char *key,unsigned char *ptrSource, unsigned char msgLen,unsigned char *ptrDest);

	//����������ݽ���
	__int16 __stdcall pwd_decrypt(unsigned char *ptrSource, unsigned char nDataLen,unsigned char *ptrDest);

	//�ͻ�Ҫ��ķ�װ����
	//���������
	__int16 __stdcall mw_kb_open(int port, long baud);
	//������̲����رն˿�
	__int16 __stdcall mw_kb_close(HANDLE icdev);
	//���������������Կ
	__int16 __stdcall mw_kb_downloadmainkey(HANDLE icdev,int destype,int mainkeyno,unsigned char *mainkey);
	//����������ع�����Կ
	__int16 __stdcall mw_kb_downloaduserkey(HANDLE icdev, int destype, int mainkeyno, int userkeyno, unsigned char *userkey);
	//������̼�������Կ�͹�����Կ
	__int16 __stdcall mw_kb_activekey(HANDLE icdev, int mainkeyno,int userkeyno);
	//������������������볤��
	__int16 __stdcall mw_kb_setpasslen(HANDLE icdev, int passlen);
	//����������ó�ʱʱ��
	__int16 __stdcall mw_kb_settimeout(HANDLE icdev, int timeout);
	//������̻�ȡ��������
	__int16 __stdcall mw_kb_getpin(HANDLE icdev, int type, unsigned char *planpin);
	//������̻�ȡ��������
	__int16 __stdcall mw_kb_getenpin(HANDLE icdev, int type, unsigned char *cardno, unsigned char *planpin);

	//���ع�����Կ--��ԿΪ����
	__int16 __stdcall mw_kb_downloaduserkey_nb(HANDLE icdev, int destype, int mainkeyno,int userkeyno, unsigned char *userkey);
	//��ȡ��������  1--��������,2--�ٴ���������
	__int16 __stdcall mw_kb_getenpin_nb(HANDLE icdev, int type, unsigned char userkeyno, unsigned char *planpin);
	//LCD��ʾ����ʾ
	__int16 __stdcall lcd_display_string(HANDLE icdev, __int16 row, __int16 column,__int16 len, char *disp_buf);
	//LCD����
	__int16 __stdcall lcd_clear(HANDLE icdev);
	//���ü������� 0--����������� 1--�����������
	void __stdcall set_kb_type(int type); 
	//2.4G��ͨ������
	__int16 __stdcall ds_command_trn(HANDLE icdev,unsigned char *sCmd,unsigned short nCmdLen, unsigned char *sResp, unsigned short *nRespLen);
}