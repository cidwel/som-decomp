; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-list.md.
.setcpu "65816"
.smart
.a8
.i16

play_native_menu_ring_open_or_change_sound = $6F5E
step_native_menu_ring_category_across_shop_and_hero_constraints = $6EF0

.segment "CODE"
.org $6F77
step_category_then_build_native_menu_ring_list:
    jsr play_native_menu_ring_open_or_change_sound
    jsr step_native_menu_ring_category_across_shop_and_hero_constraints
