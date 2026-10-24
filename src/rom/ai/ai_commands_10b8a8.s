.setcpu "65816"
.segment "CODE"
.org $B8A8
.include "ai_command_macros.inc"
ai_pc_6993:
    ai_rnd_var3_2c $0003
ai_pc_6995:
    ai_set_var2_27 $0004
ai_pc_6997:
    ai_pos_save_9f
ai_pc_6998:
    ai_if_var3_nz_05_short $6998, $69A0
ai_pc_699a:
    ai_hop_e0 $0008, $0004, $000F
ai_pc_699e:
    ai_jmp_01_short $699E, $69B6
ai_pc_69a0:
    ai_if_var3_ne_0d_short $0001, $69A0, $69A9
ai_pc_69a3:
    ai_hop_e0 $0004, $0004, $000F
ai_pc_69a7:
    ai_jmp_01_short $69A7, $69B6
ai_pc_69a9:
    ai_if_var3_ne_0d_short $0002, $69A9, $69B2
ai_pc_69ac:
    ai_hop_e0 $0001, $0004, $000F
ai_pc_69b0:
    ai_jmp_01_short $69B0, $69B6
ai_pc_69b2:
    ai_hop_e0 $0002, $0004, $000F
ai_pc_69b6:
    ai_if_pos_moved_9e_short $69B6, $69BB
ai_pc_69b8:
    ai_jmp_01_long $69B8, $69BE
ai_pc_69bb:
    ai_dec_var2_20
ai_pc_69bc:
    ai_if_var2_nz_04_short $69BC, $6997
ai_pc_69be:
    ai_ret_00
