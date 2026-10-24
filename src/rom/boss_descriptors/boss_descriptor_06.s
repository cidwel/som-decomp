; Typed fields consumed by C23438; docs/boss-descriptor-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D451
boss_descriptor_06:
descriptor_06_allocation_flags:
    .word $1C11
descriptor_06_actor_70:
    .word $0000
descriptor_06_initialize_callback:
    .word $41F8
descriptor_06_chooser_callback:
    .word $4213
descriptor_06_action_callback:
    .word $4235
descriptor_06_hurt_callback:
    .word $42D3
descriptor_06_actor_bc:
    .word $D46B
descriptor_06_actor_be:
    .word $D46D
descriptor_06_state_table:
    .word $D4CF
descriptor_06_actor_a7:
    .word $0003
descriptor_06_alternate_death_callback:
    .word $42E0
descriptor_06_height_parameter:
    .word $FFE0
descriptor_06_custom_terminal_table:
    .word $0000
