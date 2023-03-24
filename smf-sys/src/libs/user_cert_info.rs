use std::error::Error;
use std::ptr::null_mut;
use std::ffi::*;

#[repr(C)]
#[derive(Debug)]
pub struct UserCertInfo{
    pub issue_name: [c_char;32],        /*颁发者CN项*/
    pub subject_name: [c_char;32],      /*使用者CN项*/
    pub cid: [c_char;64],               /*证书ID*/
    pub not_before: [c_char;32],        /*生效时间*/
    pub not_after: [c_char;32],         /*失效时间*/
    pub last_use_time: [c_char;32],     /*最后一次使用时间*/
    pub term_os: [c_char;32],           /*终端操作系统*/
    pub term_ip: [c_char;32],           /*终端IP*/
    pub term_desc: [c_char;32],         /*终端描述信息*/
    pub term_hdtype: [c_char;32],       /*终端硬件类型*/
    pub term_manufacturer: [c_char;32], /*终端厂商*/
}

impl UserCertInfo{
    pub fn new() -> UserCertInfo {
        UserCertInfo{
            issue_name: ['0' as c_char;32],        /*颁发者CN项*/
            subject_name: ['0' as c_char;32],      /*使用者CN项*/
            cid: ['0' as c_char;64],               /*证书ID*/
            not_before: ['0' as c_char;32],        /*生效时间*/
            not_after: ['0' as c_char;32],         /*失效时间*/
            last_use_time: ['0' as c_char;32],     /*最后一次使用时间*/
            term_os: ['0' as c_char;32],           /*终端操作系统*/
            term_ip: ['0' as c_char;32],           /*终端IP*/
            term_desc: ['0' as c_char;32],         /*终端描述信息*/
            term_hdtype: ['0' as c_char;32],       /*终端硬件类型*/
            term_manufacturer: ['0' as c_char;32], /*终端厂商*/
        }
    }
}