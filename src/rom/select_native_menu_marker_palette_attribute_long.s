; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-target-selector.md.
.setcpu "65816"
.smart
.a8
.i16

select_event_menu_oam_palette_attribute = $70E3

.segment "CODE"
.org $70DB
select_native_menu_marker_palette_attribute_long:
    jsr select_event_menu_oam_palette_attribute
    rtl
