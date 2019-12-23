use gtk::*;

use crate::ui::About;

pub struct Content(pub Box);

impl Content {
    pub fn new() -> Content {
        let content = Box::new(Orientation::Vertical, 0);

        let about = About::new();

        content.pack_start(&about.button, false, false, 0);

        Content(content)
    }
}