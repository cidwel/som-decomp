; Typed fields consumed by C23438; docs/boss-descriptor-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DD35
boss_descriptor_05:
descriptor_05_allocation_flags:
    .word $9C11
descriptor_05_actor_70:
    .word $0001
descriptor_05_initialize_callback:
    .word $603B
descriptor_05_chooser_callback:
    .word $604B
descriptor_05_action_callback:
    .word $60BB
descriptor_05_hurt_callback:
    .word $6175
descriptor_05_actor_bc:
    .word $DD57
descriptor_05_actor_be:
    .word $DD5A
descriptor_05_state_table:
    .word $DD94
descriptor_05_actor_a7:
    .word $0002
descriptor_05_alternate_death_callback:
    .word $617F
descriptor_05_height_parameter:
    .word $FFF8
descriptor_05_custom_terminal_table:
    .word $DD4F
