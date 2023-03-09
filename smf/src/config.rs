
pub struct Config(*mut ffi::Config);

impl Drop for Config{
    fn drop(&mut self){
        self.0.drop();
    }
}

impl Config {
    pub fn new() -> Config{
        let c = ffi::Config { 
            cert_server_url: null_mut(),
            sks_server_url: null_mut(),
            cert_expired_days: 5,
            log_level: SMF_LOG_DEBUG,
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
        };
        Box::new(c)
    }

    // pub fn setCertServer(&mut self, url: String) 
    //     -> Result<(), Box<dyn Error>> {
    //     if !self.cert_server_url.is_null() {
    //         println!("释放指针");
    //         unsafe{CString::from_raw(self.cert_server_url);}
    //     }
    //     self.cert_server_url = CString::new(url)?.into_raw();
    //     Ok(())
    // }

    // pub fn setLogLevel(&mut self, level: c_int) 
    //     -> Result<(), Box<dyn Error>> {
    //     self.log_level = level;
    //     Ok(())
    // }
}
