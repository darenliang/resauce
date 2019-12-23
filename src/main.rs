extern crate gtk;
extern crate gio;

use gtk::prelude::*;
use gio::prelude::*;

use gtk::{ApplicationWindow, Builder, AboutDialog, TreeStore};

use std::env::args;

fn build_ui(application: &gtk::Application) {
    let layout_src: &str = include_str!("test_layout.glade");
    let builder: Builder = Builder::new_from_string(layout_src);

    let window: ApplicationWindow = builder.get_object("mainWindow")
        .expect("Couldn't get mainWindow");

    window.set_application(Some(application));

    let about_dialog: AboutDialog = builder.get_object("aboutDialog")
        .expect("Couldn't get aboutDialog");

    let folder_store: TreeStore = builder.get_object("folderStore")
        .expect("Couldn't get folderStore");

    for _ in 0..10 {
        folder_store.insert_with_values(None, None, &[0, 1, 2, 3, 4], &[&"1", &"2", &"3", &"4", &"5"]);
    }

    builder.connect_signals(move |_, handler_name| {
        match handler_name {
            "about_activate" => {
                let about_dialog: AboutDialog = about_dialog.clone();

                Box::new(move |_| {
                    about_dialog.run();
                    about_dialog.hide();
                    None
                })
            }

            "close_about" => {
                let about_dialog: AboutDialog = about_dialog.clone();

                Box::new(move |_| {
                    about_dialog.close();
                    None
                })
            }

            _ => panic!("Unknown handler name {}", handler_name)
        }
    });

    window.show_all();
}

fn main() {
    let application = gtk::Application::new(
        Some("com.darenliang.test"),
        Default::default())
        .expect("Initialization failed...");

    application.connect_activate(|app| {
        build_ui(app);
    });

    application.run(&args().collect::<Vec<_>>());
}