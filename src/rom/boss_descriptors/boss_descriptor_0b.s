; Typed fields consumed by C23438; docs/boss-descriptor-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F00C
boss_descriptor_0b:
descriptor_0b_allocation_flags:
    .word $1801
descriptor_0b_actor_70:
    .word $0000
descriptor_0b_initialize_callback:
    .word $8AFC
descriptor_0b_chooser_callback:
    .word $8B31
descriptor_0b_action_callback:
    .word $8C20
descriptor_0b_hurt_callback:
    .word $0000
descriptor_0b_actor_bc:
    .word $F028
descriptor_0b_actor_be:
    .word $F02A
descriptor_0b_state_table:
    .word $F056
descriptor_0b_actor_a7:
    .word $0004
descriptor_0b_alternate_death_callback:
    .word $8CFA
descriptor_0b_height_parameter:
    .word $FFE0
descriptor_0b_custom_terminal_table:
    .word $0000
