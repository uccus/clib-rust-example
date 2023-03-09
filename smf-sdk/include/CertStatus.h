#ifndef _CERT_STATUS_H_
#define _CERT_STATUS_H_
// 证书的所有状态
#define CERT_ST_NOT_REGISTERED   -2   //未注册
#define CERT_ST_UNREGISTERED     -1   //已注销
#define CERT_ST_NOT_EXIST        0    //证书不存在
#define CERT_ST_EXIST            1    //证书存在
#define CERT_ST_EXIST_ONLYLOCAL  2    //只是本地有证书，服务端无效
#define CERT_ST_REGISTER2REVIEW  1000 //证书申请待审核
#define CERT_ST_ISSUE_REFUSED    1001 //证书申请审核未通过
#define CERT_ST_TOBE_ISSUE       1002 //待发证
#define CERT_ST_ISSUED           2000 //已发证
#define CERT_ST_UPDATE2REVIEW    2001 //更新待审核
#define CERT_ST_TOBE_UPDATE      2002 //待更新
#define CERT_ST_POSTPONE2REVIEW  2003 //延期待审核
#define CERT_ST_TOBE_POSTPONE    2004 //待延期
#define CERT_ST_FREEZED          2005 //已冻结
#define CERT_ST_CERT_REVOKED     2006 //证书已废除
#define CERT_ST_REAPPLY2REVIEW   2007 //重发待审核
#define CERT_ST_TOBE_RECOVER     2008 //待恢复
#define CERT_ST_TOBE_REISSUE     2009 //待重发
#define CERT_ST_FREEZE2REVIEW    2010 //冻结待审核
#define CERT_ST_TOBE_FREEZE      2011 //待冻结
#define CERT_ST_UNFREEZE2REVIEW  2012 //解冻待审核
#define CERT_ST_TOBE_UNFREEZE    2013 //待解冻
#define CERT_ST_KEYUPDATE2REVIEW 2014 //密钥更新待审核
#define CERT_ST_TOBE_KEYUPDATE   2015 //待更新密钥
#define CERT_ST_RECOVER2REVIEW   2016 //恢复待审核
#define CERT_ST_REVOKED2REVIEW   2017 //废除待审核
#define CERT_ST_REVOKED2REVIEW2  2018 //冻结废除待审核
#define CERT_ST_TOBE_REVOKED     2019 //待废除
#define CERT_ST_FREEZED2REVOKED  2021 //冻结待废除
#define CERT_ST_UNLOCK2REVIEW    2022 //解锁申请待审核
#define CERT_ST_TOBE_UNLOCKED    2023 //证书待解锁
#define CERT_ST_LOCKED           2024 //证书锁定
#define CERT_ST_EXPIRED          2025 //证书已过期
#define CERT_ST_UNEFFECT         2026 //证书未生效
#define CERT_ST_EXPIRED_SOON     2027 //证书即将过期

#endif /* _CERT_STATUS_H_ */