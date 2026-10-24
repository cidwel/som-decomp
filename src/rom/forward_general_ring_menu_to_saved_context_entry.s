; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-general.md.
.setcpu "65816"
.smart
.a8
.i16

enter_general_ring_with_saved_stack_context_and_actor_selection = $6594

.segment "CODE"
.org $6403
forward_general_ring_menu_to_saved_context_entry:
    jmp enter_general_ring_with_saved_stack_context_and_actor_selection
