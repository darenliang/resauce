use gtk::*;
use gdk::enums::key;
use gdk::ModifierType;

use super::Content;
use super::app_info::*;
use super::util::*;

pub struct App {
    pub window: ApplicationWindow,
    pub content: Content,
}

pub struct InteractiveApp(App);

impl InteractiveApp {
    pub fn then_execute(self) {
        self.0.window.show_all();
        gtk::main();
    }
}

impl App {
    pub fn new() -> App {
        let application = Application::new(
            Some(APP_ID),
            Default::default())
            .expect("Failed to initialize application.");

        let window = ApplicationWindow::new(&application);

        let content = Content::new();

        window.set_title(NAME);
        window.set_default_size(800, 600);
        window.add(&content.0);

        App { window, content }
    }

    pub fn connect_events(self) -> InteractiveApp {
        self.handle_key_events();
        InteractiveApp(self)
    }

    fn handle_key_events(&self) {
        self.window.connect_key_press_event(move |window, event| {
            match event.get_keyval() {
                key if key == 'q' as u32 && event.get_state().contains(ModifierType::CONTROL_MASK) => {
                    quit_application(window);
                }
                _ => (),
            }
            Inhibit(false)
        });
    }
}