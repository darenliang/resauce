use gtk::*;
use glib::clone;

use crate::config::info;

pub struct About(pub AboutDialog);


impl About {
    pub fn new() -> About {
        let button = Button::new();
        button.set_label("About");

        let about_dialog = AboutDialog::new();
        about_dialog.set_program_name(info::NAME);
        about_dialog.set_version(Some(info::VERSION));
        about_dialog.set_website(Some(info::WEBSITE_URL));
        about_dialog.set_license_type(info::LICENSE);
        about_dialog.set_authors(info::AUTHORS);

        button.connect_clicked(clone!(@weak about_dialog => move |_| {
            about_dialog.run();
            about_dialog.hide();
        }));

        About(about_dialog)
    }
}