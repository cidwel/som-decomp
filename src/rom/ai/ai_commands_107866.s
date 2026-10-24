.setcpu "65816"
.segment "CODE"
.org $7866
.include "ai_command_macros.inc"
ai_pc_2951:
    ai_pose_e2 $0000
ai_pc_2953:
    ai_set_var1_26 $000A
ai_pc_2955:
    ai_ret_00
ai_pc_2956:
    ai_move_toward_e4 $0000, $0005
ai_pc_2959:
    ai_call_ff $29D4
ai_pc_295c:
    ai_if_crowd_gt_f5_short $0001, $295C, $296D
ai_pc_295f:
    ai_rnd_var3_2c $0007
ai_pc_2961:
    ai_if_var3_nz_05_short $2961, $2968
ai_pc_2963:
    ai_call_ff $29AA
ai_pc_2966:
    ai_jmp_01_short $2966, $296B
ai_pc_2968:
    ai_move_toward_e4 $0000, $0005
ai_pc_296b:
    ai_jmp_01_short $296B, $299A
ai_pc_296d:
    ai_move_toward_e4 $0000, $0005
ai_pc_2970:
    ai_rnd_var3_2c $0003
ai_pc_2972:
    ai_if_var3_nz_05_short $2972, $2997
ai_pc_2974:
    ai_rnd_var3_2c $000F
ai_pc_2976:
    ai_if_var3_nz_05_short $2976, $2992
ai_pc_2978:
    ai_if_field_lt_2f_short $0081, $0000, $0081, $2978, $2982
ai_pc_297d:
    ai_call_ff $11AA
ai_pc_2980:
    ai_jmp_01_short $2980, $2990
ai_pc_2982:
    ai_if_word_gt_bd_short $0080, $0002, $0097, $0001, $2982, $298D
ai_pc_2988:
    ai_call_ff $299B
ai_pc_298b:
    ai_jmp_01_short $298B, $2990
ai_pc_298d:
    ai_call_ff $29AA
ai_pc_2990:
    ai_jmp_01_short $2990, $2995
ai_pc_2992:
    ai_move_toward_e4 $0000, $0005
ai_pc_2995:
    ai_jmp_01_short $2995, $299A
ai_pc_2997:
    ai_move_toward_e4 $0000, $0005
ai_pc_299a:
    ai_ret_00
ai_pc_299b:
    ai_if_obj_outside_5f_short $0080, $299B, $29A6
ai_pc_299e:
    ai_tgt2_cur_c1
ai_pc_299f:
    ai_cast_e9 $0001, $0008
ai_pc_29a2:
    ai_tgt2_none_c0
ai_pc_29a3:
    ai_move_toward_e4 $0000, $00B4
ai_pc_29a6:
    ai_move_toward_e4 $0000, $0005
ai_pc_29a9:
    ai_ret_00
ai_pc_29aa:
    ai_if_obj_outside_5f_short $0080, $29AA, $29D3
ai_pc_29ad:
    ai_rnd_var3_2c $0002
ai_pc_29af:
    ai_if_var3_nz_05_short $29AF, $29BB
ai_pc_29b1:
    ai_tgt2_cur_c1
ai_pc_29b2:
    ai_cast_e9 $0001, $0012
ai_pc_29b5:
    ai_tgt2_none_c0
ai_pc_29b6:
    ai_move_toward_e4 $0000, $00B4
ai_pc_29b9:
    ai_jmp_01_short $29B9, $29D0
ai_pc_29bb:
    ai_if_var3_ne_0d_short $0001, $29BB, $29C8
ai_pc_29be:
    ai_tgt2_cur_c1
ai_pc_29bf:
    ai_cast_e9 $0001, $0013
ai_pc_29c2:
    ai_tgt2_none_c0
ai_pc_29c3:
    ai_move_toward_e4 $0000, $00B4
ai_pc_29c6:
    ai_jmp_01_short $29C6, $29D0
ai_pc_29c8:
    ai_tgt2_cur_c1
ai_pc_29c9:
    ai_cast_e9 $0001, $0006
ai_pc_29cc:
    ai_tgt2_none_c0
ai_pc_29cd:
    ai_move_toward_e4 $0000, $00B4
ai_pc_29d0:
    ai_move_toward_e4 $0000, $0005
ai_pc_29d3:
    ai_ret_00
ai_pc_29d4:
    ai_if_obj_outside_5f_short $0080, $29D4, $29E7
ai_pc_29d7:
    ai_if_var1_lt_17_short $0001, $29D7, $29E7
ai_pc_29da:
    ai_if_crowd_gt_f5_short $0002, $29DA, $29E4
ai_pc_29dd:
    ai_pose_e2 $0003
ai_pc_29df:
    ai_cmd43_ed $0031
ai_pc_29e1:
    ai_dec_var1_1f
ai_pc_29e2:
    ai_jmp_01_short $29E2, $29E7
ai_pc_29e4:
    ai_move_toward_e4 $0000, $0005
ai_pc_29e7:
    ai_ret_00
ai_pc_29e8:
    ai_call_ff $2A1E
ai_pc_29eb:
    ai_rnd_var3_2c $000F
ai_pc_29ed:
    ai_if_var3_nz_05_short $29ED, $29F4
ai_pc_29ef:
    ai_call_ff $683C
ai_pc_29f2:
    ai_jmp_01_short $29F2, $2A16
ai_pc_29f4:
    ai_call_ff $6AE1
ai_pc_29f7:
    ai_if_tgt_not_within_16_34_short $29F7, $29FE
ai_pc_29f9:
    ai_call_ff $2A37
ai_pc_29fc:
    ai_jmp_01_short $29FC, $2A16
ai_pc_29fe:
    ai_if_tgt_not_within_32_4c_short $29FE, $2A05
ai_pc_2a00:
    ai_call_ff $2AD7
ai_pc_2a03:
    ai_jmp_01_short $2A03, $2A16
ai_pc_2a05:
    ai_if_tgt_not_within_48_51_short $2A05, $2A0C
ai_pc_2a07:
    ai_call_ff $2A4C
ai_pc_2a0a:
    ai_jmp_01_short $2A0A, $2A16
ai_pc_2a0c:
    ai_if_tgt_not_within_64_56_short $2A0C, $2A13
ai_pc_2a0e:
    ai_call_ff $2AB3
ai_pc_2a11:
    ai_jmp_01_short $2A11, $2A16
ai_pc_2a13:
    ai_call_ff $2AB3
ai_pc_2a16:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $2A16, $29EB
ai_pc_2a1b:
    ai_jmp_01_short $2A1B, $29EB
