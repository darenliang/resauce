use gtk::*;

use crate::ui::menubar::MenuBar;

pub struct Content {
    pub v_box: Box,
    pub accel_group: AccelGroup,
}

impl Content {
    pub fn new() -> Content {
        let v_box = Box::new(Orientation::Vertical, 0);

        let menu_bar = MenuBar::new();

        let accel_group = menu_bar.accel_group;

        v_box.pack_start(&menu_bar.menu_bar, false, false, 0);

        Content { v_box, accel_group }
    }
}