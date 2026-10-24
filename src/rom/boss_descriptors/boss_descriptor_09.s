; Typed fields consumed by C23438; docs/boss-descriptor-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E120
boss_descriptor_09:
descriptor_09_allocation_flags:
    .word $1C11
descriptor_09_actor_70:
    .word $0000
descriptor_09_initialize_callback:
    .word $6501
descriptor_09_chooser_callback:
    .word $6520
descriptor_09_action_callback:
    .word $654B
descriptor_09_hurt_callback:
    .word $0000
descriptor_09_actor_bc:
    .word $E13A
descriptor_09_actor_be:
    .word $E13C
descriptor_09_state_table:
    .word $E173
descriptor_09_actor_a7:
    .word $0004
descriptor_09_alternate_death_callback:
    .word $65DC
descriptor_09_height_parameter:
    .word $FFE0
descriptor_09_custom_terminal_table:
    .word $0000
