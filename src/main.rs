extern crate gtk;
extern crate gio;
extern crate gdk;

pub mod ui;

use ui::App;

fn main() {
    App::new()
        .connect_events()
        .then_execute();
}