; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-state-api.md.
.setcpu "65816"
.smart
.a8
.i16

dim_existing_native_menu_palette_with_saved_context = $6460

.segment "CODE"
.org $641A
forward_native_menu_palette_dimming:
    jmp dim_existing_native_menu_palette_with_saved_context
