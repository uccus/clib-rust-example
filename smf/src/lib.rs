#![allow(non_snake_case)]
#![allow(unused_imports)]
#![allow(dead_code)]
#![allow(unused_variables)]

mod smf_helper;
pub use smf_helper::*;

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn testInit(){
        let mut helper = SmfHelper::new();
        helper.setCertServer("gmvpn://10.0.240.13:18555".to_string()).unwrap();
        helper.initUser().unwrap();
        assert_eq!(0, 0);
    }
}
