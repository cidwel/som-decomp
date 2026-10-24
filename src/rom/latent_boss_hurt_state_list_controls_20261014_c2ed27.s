; Producer-selected numeric action enum and terminal; not a raw script dump.
.setcpu "65816"
.segment "RODATA"
.org $ED27
boss_descriptor_10_hurt_state_action_id:
    .byte $0E ; Action enum 14, indexed by C2377A
boss_descriptor_10_hurt_state_list_terminal:
    .byte $FF ; C23561 terminates this state list
