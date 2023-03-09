use std::error::Error;
use super::*;

pub struct SmfHelper{
    config: *mut ffi::Config,
}

impl SmfHelper{
    pub fn new() -> SmfHelper {
        SmfHelper{
            config: Box::new(ffi::Config::new()).as_mut(),
        }
    }

    pub fn setCertServer(&mut self, url: String) -> Result<(), Box<dyn Error>> {
        // unsafe {self.config.as_mut().ok_or()?.setCertServer(url)?;}
        Ok(())
    }

    pub fn initUser(&self) -> Result<(), Box<dyn Error>> {
        unsafe {ffi::SMF_ConfigInit(self.config);}
        Ok(())
    }
}