; Typed fields consumed by C23438; docs/boss-descriptor-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EB49
boss_descriptor_07:
descriptor_07_allocation_flags:
    .word $9C01
descriptor_07_actor_70:
    .word $0000
descriptor_07_initialize_callback:
    .word $70B3
descriptor_07_chooser_callback:
    .word $70C5
descriptor_07_action_callback:
    .word $7110
descriptor_07_hurt_callback:
    .word $0000
descriptor_07_actor_bc:
    .word $EB7B
descriptor_07_actor_be:
    .word $EB6B
descriptor_07_state_table:
    .word $EB9D
descriptor_07_actor_a7:
    .word $0004
descriptor_07_alternate_death_callback:
    .word $7272
descriptor_07_height_parameter:
    .word $FFD0
descriptor_07_custom_terminal_table:
    .word $EB63
