use gtk::*;

use crate::config::info;

use super::Content;

pub struct App {
    pub window: ApplicationWindow,
    pub content: Content,
}

impl App {
    pub fn new(application: &Application) -> App {
        let window = ApplicationWindow::new(application);

        let content = Content::new();

        window.set_title(info::NAME);
        window.set_default_size(800, 600);
        window.add(&content.0);

        App { window, content }
    }
}