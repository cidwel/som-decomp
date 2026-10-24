; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-state-api.md.
.setcpu "65816"
.smart
.a8
.i16

forward_native_menu_state_initialization = $6400

.segment "CODE"
.org $0012
public_native_menu_state_initialization_alias:
    jmp forward_native_menu_state_initialization
