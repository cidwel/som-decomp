; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-general.md.
.setcpu "65816"
.smart
.a8
.i16

forward_general_ring_menu_to_saved_context_entry = $6403

.segment "CODE"
.org $0015
public_general_ring_menu_alias:
    jmp forward_general_ring_menu_to_saved_context_entry
