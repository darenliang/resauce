extern crate gio;
extern crate gtk;

use gio::prelude::*;
use gtk::prelude::*;

use std::env::args;

mod config;
mod ui;
mod utils;

fn build_ui(application: &gtk::Application) {
    let app = ui::App::new(application);
    app.window.show_all();
}

fn main() {
    let application =
        gtk::Application::new(Some(config::info::APP_ID), Default::default())
            .expect("Cannot initialize gtk application.");

    application.connect_activate(|app| {
        build_ui(app);
    });

    application.run(&args().collect::<Vec<_>>());
}
