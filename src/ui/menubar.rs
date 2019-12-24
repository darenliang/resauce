use gtk::*;
use glib::clone;

use gtk::MenuBar as gtkMenuBar;

use crate::ui::about::About;
use crate::utils::misc;

pub struct MenuBar {
    pub menu_bar: gtkMenuBar,
    pub accel_group: AccelGroup,
}

impl MenuBar {
    pub fn new() -> MenuBar {
        let accel_group = AccelGroup::new();

        let menu_bar = gtkMenuBar::new();

        let file = MenuItem::new_with_label("File");
        let file_submenu = Menu::new();
        let quit_entry = MenuItem::new_with_label("Quit");
        file_submenu.append(&quit_entry);
        file.set_submenu(Some(&file_submenu));
        menu_bar.append(&file);

        let help = MenuItem::new_with_label("Help");
        let help_submenu = Menu::new();
        let about_entry = MenuItem::new_with_label("About");
        help_submenu.append(&about_entry);
        help.set_submenu(Some(&help_submenu));
        menu_bar.append(&help);

        let about = About::new().0;

        about_entry.connect_activate(clone!(@weak about => move |_| {
            about.run();
            about.hide();
        }));

        quit_entry.connect_activate(|_| { misc::quit_application() });

        let (ctrl_q_key, ctrl_q_modifier) = gtk::accelerator_parse("<Primary>Q");
        quit_entry.add_accelerator("activate", &accel_group, ctrl_q_key, ctrl_q_modifier, AccelFlags::VISIBLE);

        MenuBar { menu_bar, accel_group }
    }
}