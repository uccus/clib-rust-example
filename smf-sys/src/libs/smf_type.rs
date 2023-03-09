extern crate libc;
use libc::*;
use std::error::Error;
use std::ptr::null_mut;
use std::ffi::CString;

#[allow(unused_imports)]

#[repr(C)]
pub struct SMF_CONTEXT{
    pub _inner_ctx: *mut c_void,
}

#[repr(C)]
pub struct SMF_CIPHER_CTX{
    pub _inner_ctx: *mut c_void,
    pub _cipher_ctx: *mut c_void,
}

#[repr(C)]
#[derive(Debug)]
pub struct Config_t{
    pub cert_server_url: *mut c_char,
    pub sks_server_url: *mut c_char,
    pub cert_expired_days: c_int,
    pub log_level: c_int,
    pub log_dir: *mut c_char,
    pub recv_exception: c_int,
    pub time_out: c_int,
    pub simple_auth: c_int,
    pub pin_retry_count: c_int,
    pub cert_chain_count: c_int,
    pub cert_chain: [*mut c_char; 32],
    pub term_info: *mut c_char,
    pub verify_cert_trust_partial: c_int,
    pub client_cert_file: *mut c_char,
    pub client_cert_pwd: *mut c_char,
    pub simple_auth_secret: *mut c_char,
    pub data_exlen: c_int,
    pub data_ex: [c_char;1],
}

impl Config_t {
    pub fn new() -> Config_t{
        Config_t { 
            cert_server_url: null_mut(),
            sks_server_url: null_mut(),
            cert_expired_days: 5,
            log_level: 6,
            log_dir: null_mut(),
            recv_exception: -1,
            time_out: 10,
            simple_auth: 1,
            pin_retry_count: 5,
            cert_chain_count: 0,
            cert_chain: [null_mut();32],
            term_info: null_mut(),
            verify_cert_trust_partial: 0,
            client_cert_file: null_mut(),
            client_cert_pwd: null_mut(),
            simple_auth_secret: null_mut(),
            data_exlen: 0,
            data_ex: ['0' as c_char],
        }
    }

    pub fn setCertServer(&mut self, url: String) 
        -> Result<(), Box<dyn Error>>
    {
        if !self.cert_server_url.is_null() {
            println!("释放指针");
            unsafe{CString::from_raw(self.cert_server_url);}
        }
        self.cert_server_url = CString::new(url)?.into_raw();
        Ok(())
    }
}

impl Drop for Config_t{
    fn drop(&mut self) {
        unsafe {
            println!("释放指针");
            if !self.cert_server_url.is_null() {
                CString::from_raw(self.cert_server_url);
            }
            if !self.sks_server_url.is_null() {
                CString::from_raw(self.sks_server_url);
            }
        }
    }
}