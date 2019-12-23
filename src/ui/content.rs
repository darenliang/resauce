use gtk::*;

pub struct Content {
    pub container: Label
}

impl Content {
    pub fn new() -> Content {
        let container = Label::new(Some("something"));

        Content { container }
    }
}