; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-state-api.md.
.setcpu "65816"
.smart
.a8
.i16

restore_existing_native_menu_palette_with_saved_context = $6474

.segment "CODE"
.org $641D
forward_native_saved_menu_palette_restoration:
    jmp restore_existing_native_menu_palette_with_saved_context
