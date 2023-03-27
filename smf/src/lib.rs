#![allow(non_snake_case)]
#![allow(unused_imports)]
#![allow(dead_code)]
#![allow(unused_variables)]

mod internal;
pub use internal::*;

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn testInit(){
        let mut helper = SmfHelper::new();
        helper.setCertServer("gmvpn://10.0.240.13:18555".to_string()).unwrap();
        helper.setUid("test123".to_string()).unwrap();
        helper.setPassword("test123".to_string()).unwrap();
        helper.setPin("123123".to_string()).unwrap();
        let ret = helper.initUser().unwrap();
        assert_eq!(ret, 2000);
        helper.initialize().unwrap();
        helper.enrollCert().unwrap();
        assert_eq!(0, 0);
    }
}
