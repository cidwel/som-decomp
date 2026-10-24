; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-state-api.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_native_menu_hero_categories_with_saved_context = $6433

.segment "CODE"
.org $6400
forward_native_menu_state_initialization:
    jmp initialize_native_menu_hero_categories_with_saved_context
