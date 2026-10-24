; Typed fields consumed by C23438; docs/boss-descriptor-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D20A
boss_descriptor_02:
descriptor_02_allocation_flags:
    .word $1C11
descriptor_02_actor_70:
    .word $0000
descriptor_02_initialize_callback:
    .word $3F78
descriptor_02_chooser_callback:
    .word $3F93
descriptor_02_action_callback:
    .word $3FD9
descriptor_02_hurt_callback:
    .word $4083
descriptor_02_actor_bc:
    .word $D224
descriptor_02_actor_be:
    .word $D226
descriptor_02_state_table:
    .word $D272
descriptor_02_actor_a7:
    .word $0003
descriptor_02_alternate_death_callback:
    .word $4090
descriptor_02_height_parameter:
    .word $FFE0
descriptor_02_custom_terminal_table:
    .word $0000
