; Typed fields consumed by C23438; docs/boss-descriptor-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D080
boss_descriptor_00:
descriptor_00_allocation_flags:
    .word $1C11
descriptor_00_actor_70:
    .word $0001
descriptor_00_initialize_callback:
    .word $3D48
descriptor_00_chooser_callback:
    .word $3D5A
descriptor_00_action_callback:
    .word $3D8C
descriptor_00_hurt_callback:
    .word $0000
descriptor_00_actor_bc:
    .word $D09A
descriptor_00_actor_be:
    .word $D09C
descriptor_00_state_table:
    .word $D0C9
descriptor_00_actor_a7:
    .word $0004
descriptor_00_alternate_death_callback:
    .word $0000
descriptor_00_height_parameter:
    .word $FFE8
descriptor_00_custom_terminal_table:
    .word $0000
