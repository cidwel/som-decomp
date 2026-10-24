.setcpu "65816"
.segment "CODE"
.org $56C9
.include "ai_command_macros.inc"
ai_pc_07b4:
    ai_call_ff $07EA
ai_pc_07b7:
    ai_rnd_var3_2c $0007
ai_pc_07b9:
    ai_if_var3_nz_05_short $07B9, $07C0
ai_pc_07bb:
    ai_call_ff $65CA
ai_pc_07be:
    ai_jmp_01_short $07BE, $07E2
ai_pc_07c0:
    ai_call_ff $6AE1
ai_pc_07c3:
    ai_if_tgt_not_within_16_34_short $07C3, $07CA
ai_pc_07c5:
    ai_call_ff $07ED
ai_pc_07c8:
    ai_jmp_01_short $07C8, $07E2
ai_pc_07ca:
    ai_if_tgt_not_within_32_4c_short $07CA, $07D1
ai_pc_07cc:
    ai_call_ff $0894
ai_pc_07cf:
    ai_jmp_01_short $07CF, $07E2
ai_pc_07d1:
    ai_if_tgt_not_within_48_51_short $07D1, $07D8
ai_pc_07d3:
    ai_call_ff $0878
ai_pc_07d6:
    ai_jmp_01_short $07D6, $07E2
ai_pc_07d8:
    ai_if_tgt_not_within_64_56_short $07D8, $07DF
ai_pc_07da:
    ai_call_ff $07FE
ai_pc_07dd:
    ai_jmp_01_short $07DD, $07E2
ai_pc_07df:
    ai_call_ff $083B
ai_pc_07e2:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $07E2, $07B7
ai_pc_07e7:
    ai_jmp_01_short $07E7, $07B7
