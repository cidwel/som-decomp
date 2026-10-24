; Typed fields consumed by C23438; docs/boss-descriptor-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DF9E
boss_descriptor_03:
descriptor_03_allocation_flags:
    .word $9C11
descriptor_03_actor_70:
    .word $0000
descriptor_03_initialize_callback:
    .word $62B8
descriptor_03_chooser_callback:
    .word $62C2
descriptor_03_action_callback:
    .word $630F
descriptor_03_hurt_callback:
    .word $0000
descriptor_03_actor_bc:
    .word $DFB8
descriptor_03_actor_be:
    .word $DFBA
descriptor_03_state_table:
    .word $DFE7
descriptor_03_actor_a7:
    .word $0004
descriptor_03_alternate_death_callback:
    .word $63AB
descriptor_03_height_parameter:
    .word $FFE0
descriptor_03_custom_terminal_table:
    .word $0000
