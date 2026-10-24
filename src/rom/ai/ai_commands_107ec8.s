.setcpu "65816"
.segment "CODE"
.org $7EC8
.include "ai_command_macros.inc"
ai_pc_2fb3:
    ai_call_ff $685D
ai_pc_2fb6:
    ai_jmp_01_short $2FB6, $2FD3
ai_pc_2fb8:
    ai_call_ff $6AE1
ai_pc_2fbb:
    ai_if_tgt_not_within_16_34_short $2FBB, $2FC2
ai_pc_2fbd:
    ai_call_ff $2FDE
ai_pc_2fc0:
    ai_jmp_01_short $2FC0, $2FD3
ai_pc_2fc2:
    ai_if_tgt_not_within_48_51_short $2FC2, $2FC9
ai_pc_2fc4:
    ai_call_ff $2FF0
ai_pc_2fc7:
    ai_jmp_01_short $2FC7, $2FD3
ai_pc_2fc9:
    ai_if_tgt_not_within_64_56_short $2FC9, $2FD0
ai_pc_2fcb:
    ai_call_ff $301B
ai_pc_2fce:
    ai_jmp_01_short $2FCE, $2FD3
ai_pc_2fd0:
    ai_call_ff $3034
ai_pc_2fd3:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $2FD3, $2FAF
ai_pc_2fd8:
    ai_jmp_01_short $2FD8, $2FAF
