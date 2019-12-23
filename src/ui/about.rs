use gtk::*;

use crate::config::info;

pub struct About {
    pub button: Button,
    pub about_dialog: AboutDialog,
}


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

        let about_dialog_clone = about_dialog.clone();

        button.connect_clicked(move |_| {
            about_dialog_clone.run();
            about_dialog_clone.hide();
        });

        About { button, about_dialog }
    }
}