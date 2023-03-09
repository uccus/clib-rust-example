#ifndef _CERT_STATUS_H_
#define _CERT_STATUS_H_
// ֤�������״̬
#define CERT_ST_NOT_REGISTERED   -2   //δע��
#define CERT_ST_UNREGISTERED     -1   //��ע��
#define CERT_ST_NOT_EXIST        0    //֤�鲻����
#define CERT_ST_EXIST            1    //֤�����
#define CERT_ST_EXIST_ONLYLOCAL  2    //ֻ�Ǳ�����֤�飬�������Ч
#define CERT_ST_REGISTER2REVIEW  1000 //֤����������
#define CERT_ST_ISSUE_REFUSED    1001 //֤���������δͨ��
#define CERT_ST_TOBE_ISSUE       1002 //����֤
#define CERT_ST_ISSUED           2000 //�ѷ�֤
#define CERT_ST_UPDATE2REVIEW    2001 //���´����
#define CERT_ST_TOBE_UPDATE      2002 //������
#define CERT_ST_POSTPONE2REVIEW  2003 //���ڴ����
#define CERT_ST_TOBE_POSTPONE    2004 //������
#define CERT_ST_FREEZED          2005 //�Ѷ���
#define CERT_ST_CERT_REVOKED     2006 //֤���ѷϳ�
#define CERT_ST_REAPPLY2REVIEW   2007 //�ط������
#define CERT_ST_TOBE_RECOVER     2008 //���ָ�
#define CERT_ST_TOBE_REISSUE     2009 //���ط�
#define CERT_ST_FREEZE2REVIEW    2010 //��������
#define CERT_ST_TOBE_FREEZE      2011 //������
#define CERT_ST_UNFREEZE2REVIEW  2012 //�ⶳ�����
#define CERT_ST_TOBE_UNFREEZE    2013 //���ⶳ
#define CERT_ST_KEYUPDATE2REVIEW 2014 //��Կ���´����
#define CERT_ST_TOBE_KEYUPDATE   2015 //��������Կ
#define CERT_ST_RECOVER2REVIEW   2016 //�ָ������
#define CERT_ST_REVOKED2REVIEW   2017 //�ϳ������
#define CERT_ST_REVOKED2REVIEW2  2018 //����ϳ������
#define CERT_ST_TOBE_REVOKED     2019 //���ϳ�
#define CERT_ST_FREEZED2REVOKED  2021 //������ϳ�
#define CERT_ST_UNLOCK2REVIEW    2022 //������������
#define CERT_ST_TOBE_UNLOCKED    2023 //֤�������
#define CERT_ST_LOCKED           2024 //֤������
#define CERT_ST_EXPIRED          2025 //֤���ѹ���
#define CERT_ST_UNEFFECT         2026 //֤��δ��Ч
#define CERT_ST_EXPIRED_SOON     2027 //֤�鼴������

#endif /* _CERT_STATUS_H_ */