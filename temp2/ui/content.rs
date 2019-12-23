use gtk::*;
use gtk::Orientation;

pub struct Content(pub Box);

impl Content {
    pub fn new() -> Content {
        let content = Box::new(Orientation::Vertical, 0);

        Content(content)
    }
}