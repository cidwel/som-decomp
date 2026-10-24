; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-palette-graphics.md.
.setcpu "65816"
.smart
.a8
.i16

reset_map_menu_state = $0EBF

.segment "CODE"
.org $0095
close_dialogue_public_jump:
    jmp reset_map_menu_state
