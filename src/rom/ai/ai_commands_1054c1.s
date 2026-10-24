.setcpu "65816"
.segment "CODE"
.org $54C1
.include "ai_command_macros.inc"
ai_pc_05ac:
    ai_dec_var2_20
ai_pc_05ad:
    ai_if_var2_nz_04_short $05AD, $05B9
ai_pc_05af:
    ai_rnd_var3_2c $0005
ai_pc_05b1:
    ai_if_var3_nz_05_short $05B1, $05B9
ai_pc_05b3:
    ai_move_toward_e4 $0000, $001E
ai_pc_05b6:
    ai_jmp_01_long $05B6, $05BB
ai_pc_05b9:
    ai_if_tgt_not_band_64_46_short $05B9, $0599
ai_pc_05bb:
    ai_ret_00
ai_pc_05bc:
    ai_call_ff $05E1
ai_pc_05bf:
    ai_call_ff $6AE1
ai_pc_05c2:
    ai_call_ff $0640
ai_pc_05c5:
    ai_call_ff $060A
ai_pc_05c8:
    ai_if_tgt_not_within_48_51_short $05C8, $05CF
ai_pc_05ca:
    ai_call_ff $05E6
ai_pc_05cd:
    ai_jmp_01_short $05CD, $05D9
ai_pc_05cf:
    ai_if_tgt_not_within_64_56_short $05CF, $05D6
ai_pc_05d1:
    ai_call_ff $0606
ai_pc_05d4:
    ai_jmp_01_short $05D4, $05D9
ai_pc_05d6:
    ai_move_toward_e4 $0000, $0000
ai_pc_05d9:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $05D9, $05BF
ai_pc_05de:
    ai_jmp_01_short $05DE, $05BF
