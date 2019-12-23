use std::process;
use gtk::*;

pub fn quit_application(application: &ApplicationWindow) {
    // application.close();
    process::exit(0);
}