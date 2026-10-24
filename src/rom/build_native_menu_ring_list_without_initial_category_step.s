; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-list.md.
.setcpu "65816"
.smart
.a8
.i16

build_native_ring_descriptors_icons_geometry_and_row_records = $6F7D
play_native_menu_ring_open_or_change_sound = $6F5E

.segment "CODE"
.org $6F72
build_native_menu_ring_list_without_initial_category_step:
    jsr play_native_menu_ring_open_or_change_sound
    bra build_native_ring_descriptors_icons_geometry_and_row_records
