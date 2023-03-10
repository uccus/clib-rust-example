use std::error::Error;
use super::*;

pub struct SmfHelper{
    uid: String,
    pass: String,
    pin: String,
    config: Config,
    ctx: SmfContext,
}

impl SmfHelper{
    pub fn new() -> SmfHelper {
        SmfHelper{
            uid: "".to_string(),
            pass: "".to_string(),
            pin: "".to_string(),
            config: Config::new(),
            ctx: SmfContext::new(),
        }
    }

    pub fn setCertServer(&mut self, url: String) -> Result<(), Box<dyn Error>> {
        self.config.setCertServer(url)?;
        Ok(())
    }

    pub fn setUid(&mut self, uid:String) -> Result<(), Box<dyn Error>>{
        self.uid = uid;
        Ok(())
    }

    pub fn setPassword(&mut self, pass:String) -> Result<(), Box<dyn Error>>{
        self.pass = pass;
        Ok(())
    }

    pub fn setPin(&mut self, pin:String) -> Result<(), Box<dyn Error>>{
        self.pin = pin;
        Ok(())
    }

    pub fn initUser(&mut self) -> Result<(), Box<dyn Error>> {
        return initUserConfig(&mut self.config);
    }

    pub fn initialize(&mut self) ->Result<(), Box<dyn Error>> {
        return initialize(self.uid.clone(), self.config.getCertServer().clone(), &mut self.ctx);
    }

    pub fn enrollCert(&mut self) -> Result<(), Box<dyn Error>> {
        return enrollCert(&mut self.ctx, self.pin.clone());
    }

}