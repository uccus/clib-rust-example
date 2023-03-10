use libc::*;
use std::error::Error;

pub struct Config{
    pub config: ffi::Config,
}

impl Config{
    pub fn new() -> Config{
        Config{
            config: ffi::Config::new(),
        }
    }

    pub fn setCertServer(&mut self, url: String) 
        -> Result<(), Box<dyn Error>> {
        return self.config.setCertServer(url);
    }

    pub fn setLogLevel(&mut self, level: c_int) 
        -> Result<(), Box<dyn Error>> {
        return self.config.setLogLevel(level);
    }

    pub fn getCertServer(&mut self) -> String{
        return self.config.getCertServer();
    }
}