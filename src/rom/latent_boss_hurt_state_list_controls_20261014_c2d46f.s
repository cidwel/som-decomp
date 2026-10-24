; Producer-selected numeric action enum and terminal; not a raw script dump.
.setcpu "65816"
.segment "RODATA"
.org $D46F
boss_descriptor_6_hurt_state_action_id:
    .byte $23 ; Action enum 35, indexed by C2377A
boss_descriptor_6_hurt_state_list_terminal:
    .byte $FF ; C23561 terminates this state list
