mod libs;
use libs::*;
use std::ffi::CStr;
use std::ffi::CString;

pub fn SMF_ConfigInit() -> i32{
    let mut config = Config_t::new();
    config.setCertServer("gmvpn:://10.0.243.13:18556".to_string()).unwrap();
    println!("{:#?}", unsafe{CStr::from_ptr(config.cert_server_url).to_str().unwrap()});
    println!("{:#?}", unsafe{CStr::from_ptr(config.cert_server_url).to_str().unwrap()});
    config.setCertServer("gmvpn:://10.0.243.13:18557".to_string()).unwrap();
    println!("{:#?}", unsafe{CStr::from_ptr(config.cert_server_url).to_str().unwrap()});
    2
}


#[test]
fn it_works() {
    let n_ret = SMF_ConfigInit();
    assert_eq!(n_ret, 0)
}
