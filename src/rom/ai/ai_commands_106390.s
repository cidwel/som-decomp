.setcpu "65816"
.segment "CODE"
.org $6390
.include "ai_command_macros.inc"
ai_pc_147b:
    ai_if_field_gt_30_short $0080, $006D, $0000, $147B, $1483
ai_pc_1480:
    ai_jmp_01_long $1480, $1488
ai_pc_1483:
    ai_move_toward_alt_fd $0005, $000A
ai_pc_1486:
    ai_jmp_01_short $1486, $146B
ai_pc_1488:
    ai_ret_00
ai_pc_1489:
    ai_call_ff $14B8
ai_pc_148c:
    ai_rnd_var3_2c $000F
ai_pc_148e:
    ai_if_var3_nz_05_short $148E, $1495
ai_pc_1490:
    ai_call_ff $683C
ai_pc_1493:
    ai_jmp_01_short $1493, $14B0
ai_pc_1495:
    ai_call_ff $6AE1
ai_pc_1498:
    ai_if_tgt_not_within_32_4c_short $1498, $149F
ai_pc_149a:
    ai_call_ff $14BB
ai_pc_149d:
    ai_jmp_01_short $149D, $14B0
ai_pc_149f:
    ai_if_tgt_not_within_48_51_short $149F, $14A6
ai_pc_14a1:
    ai_call_ff $14D9
ai_pc_14a4:
    ai_jmp_01_short $14A4, $14B0
ai_pc_14a6:
    ai_if_tgt_not_within_64_56_short $14A6, $14AD
ai_pc_14a8:
    ai_call_ff $14F0
ai_pc_14ab:
    ai_jmp_01_short $14AB, $14B0
ai_pc_14ad:
    ai_call_ff $3815
ai_pc_14b0:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $14B0, $148C
ai_pc_14b5:
    ai_jmp_01_short $14B5, $148C
