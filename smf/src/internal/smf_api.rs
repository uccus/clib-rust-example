use super::*;
use std::ffi::CString;
use std::error::Error;

pub fn initUserConfig(config: &mut Config) -> Result<(), Box<dyn Error>> {
    let config = &mut config.config as *mut ffi::Config;
    let ret = unsafe { ffi::SMF_ConfigInit(config) };
    Ok(())
}

pub fn initialize(uid: String, url: String, out: &mut SmfContext) 
    -> Result<(), Box<dyn Error>> {
    let uid = CString::new(uid)?.into_raw();
    let url = CString::new(url)?.into_raw();
    // 二级指针
    let ctx = &mut out.ctx as *mut *mut ffi::SMF_CONTEXT;
    let ret = unsafe { ffi::SMF_Initialize(uid, url, ctx) };
    Ok(())
}

pub fn enrollCert(ctx: &mut SmfContext, pin: String) ->Result<(), Box<dyn Error>> {
    let pin = CString::new(pin)?.into_raw();
    let ret = unsafe {
        ffi::SMF_CertEnroll(ctx.ctx, pin);
    };
    Ok(())
}