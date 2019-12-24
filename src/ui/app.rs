use gtk::*;

use crate::config::info;

use crate::ui::content::Content;

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
        window.add_accel_group(&content.accel_group);
        window.add(&content.v_box);

        App { window, content }
    }
}