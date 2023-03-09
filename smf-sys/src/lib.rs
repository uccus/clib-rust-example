#![allow(dead_code, non_snake_case, unused_imports, unused_must_use)]

mod libs;
use libs::*;
use std::ffi::CStr;
use std::ffi::CString;

// 条件编译
// #[cfg(not(cfg_test))]
pub fn SMF_ConfigInit123() -> i32{
    let mut config = Box::new(Config::new());
    config.setCertServer("gmvpn:://10.0.243.13:18556".to_string()).unwrap();
    println!("{:#?}", unsafe{CStr::from_ptr(config.cert_server_url).to_str().unwrap()});
    println!("{:#?}", unsafe{CStr::from_ptr(config.cert_server_url).to_str().unwrap()});
    config.setCertServer("gmvpn:://10.0.243.13:18557".to_string()).unwrap();
    println!("{:#?}", unsafe{CStr::from_ptr(config.cert_server_url).to_str().unwrap()});
    config.setLogLevel(SMF_LOG_DEBUG);

    let ret = unsafe {SMF_ConfigInit(&mut *config)};
    ret
}


#[test]
fn it_works() {
    let n_ret = SMF_ConfigInit123();
    assert_eq!(n_ret, 0)
}
