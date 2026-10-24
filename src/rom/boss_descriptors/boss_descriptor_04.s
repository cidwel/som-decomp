; Typed fields consumed by C23438; docs/boss-descriptor-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E5AD
boss_descriptor_04:
descriptor_04_allocation_flags:
    .word $9C02
descriptor_04_actor_70:
    .word $0001
descriptor_04_initialize_callback:
    .word $6B1B
descriptor_04_chooser_callback:
    .word $6B33
descriptor_04_action_callback:
    .word $6B63
descriptor_04_hurt_callback:
    .word $0000
descriptor_04_actor_bc:
    .word $E5C7
descriptor_04_actor_be:
    .word $E5C8
descriptor_04_state_table:
    .word $E5FC
descriptor_04_actor_a7:
    .word $0003
descriptor_04_alternate_death_callback:
    .word $6BAD
descriptor_04_height_parameter:
    .word $FFE0
descriptor_04_custom_terminal_table:
    .word $0000
