; Typed fields consumed by C23438; docs/boss-descriptor-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D658
boss_descriptor_01:
descriptor_01_allocation_flags:
    .word $9C01
descriptor_01_actor_70:
    .word $0000
descriptor_01_initialize_callback:
    .word $42E1
descriptor_01_chooser_callback:
    .word $42E8
descriptor_01_action_callback:
    .word $4341
descriptor_01_hurt_callback:
    .word $0000
descriptor_01_actor_bc:
    .word $D690
descriptor_01_actor_be:
    .word $D672
descriptor_01_state_table:
    .word $D6CA
descriptor_01_actor_a7:
    .word $0007
descriptor_01_alternate_death_callback:
    .word $4412
descriptor_01_height_parameter:
    .word $FFE8
descriptor_01_custom_terminal_table:
    .word $0000
