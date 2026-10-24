; Typed fields consumed by C23438; docs/boss-descriptor-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E82E
boss_descriptor_08:
descriptor_08_allocation_flags:
    .word $9C01
descriptor_08_actor_70:
    .word $0000
descriptor_08_initialize_callback:
    .word $6DE7
descriptor_08_chooser_callback:
    .word $6DFB
descriptor_08_action_callback:
    .word $6E82
descriptor_08_hurt_callback:
    .word $6EBA
descriptor_08_actor_bc:
    .word $E848
descriptor_08_actor_be:
    .word $E84A
descriptor_08_state_table:
    .word $E896
descriptor_08_actor_a7:
    .word $0000
descriptor_08_alternate_death_callback:
    .word $6ECA
descriptor_08_height_parameter:
    .word $0000
descriptor_08_custom_terminal_table:
    .word $0000
