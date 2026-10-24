; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-vblank.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_menu_actor_palette_or_default_palette = $CD8E

.segment "CODE"
.org $CD27
initialize_palette_then_fall_through_to_native_menu_dimming:
    jsr initialize_menu_actor_palette_or_default_palette
