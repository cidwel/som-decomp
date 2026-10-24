.setcpu "65816"
.segment "CODE"
.org $69D9
.include "ai_command_macros.inc"
ai_pc_1ac4:
    ai_pose_e2 $0000
ai_pc_1ac6:
    ai_call_ff $6AE1
ai_pc_1ac9:
    ai_move_toward_e4 $0002, $0000
ai_pc_1acc:
    ai_ret_00
ai_pc_1acd:
    ai_move_toward_e4 $0000, $0000
ai_pc_1ad0:
    ai_if_field_gt_30_short $0080, $006D, $0000, $1AD0, $1AE7
ai_pc_1ad5:
    ai_set_var1_26 $0003
ai_pc_1ad7:
    ai_call_ff $6AE1
ai_pc_1ada:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_1ade:
    ai_move_toward_e4 $0000, $0005
ai_pc_1ae1:
    ai_call_ff $6B19
ai_pc_1ae4:
    ai_dec_var1_1f
ai_pc_1ae5:
    ai_if_var1_nz_03_short $1AE5, $1AD7
ai_pc_1ae7:
    ai_call_ff $0894
ai_pc_1aea:
    ai_ret_00
ai_pc_1aeb:
    ai_move_toward_e4 $0000, $0000
ai_pc_1aee:
    ai_if_field_gt_30_short $0080, $006D, $0000, $1AEE, $1B04
ai_pc_1af3:
    ai_rnd_var3_2c $0007
ai_pc_1af5:
    ai_if_var3_nz_05_short $1AF5, $1AFF
ai_pc_1af7:
    ai_call_ff $1B1E
ai_pc_1afa:
    ai_call_ff $1B08
ai_pc_1afd:
    ai_jmp_01_short $1AFD, $1B02
ai_pc_1aff:
    ai_move_toward_e4 $0000, $0000
ai_pc_1b02:
    ai_jmp_01_short $1B02, $1B07
ai_pc_1b04:
    ai_move_toward_e4 $0000, $0000
ai_pc_1b07:
    ai_ret_00
ai_pc_1b08:
    ai_set_var1_26 $0002
ai_pc_1b0a:
    ai_call_ff $6AE1
ai_pc_1b0d:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_1b11:
    ai_move_toward_e4 $0000, $0005
ai_pc_1b14:
    ai_call_ff $6B19
ai_pc_1b17:
    ai_dec_var1_1f
ai_pc_1b18:
    ai_call_ff $1B67
ai_pc_1b1b:
    ai_if_var1_nz_03_short $1B1B, $1B0A
ai_pc_1b1d:
    ai_ret_00
ai_pc_1b1e:
    ai_if_obj_outside_5f_short $0080, $1B1E, $1B49
ai_pc_1b21:
    ai_set_var1_26 $0000
ai_pc_1b23:
    ai_if_word_lt_bc_short $0081, $003D, $0001, $0000, $1B23, $1B2B
ai_pc_1b29:
    ai_set_var1_26 $0001
ai_pc_1b2b:
    ai_if_field_lt_2f_short $0081, $001D, $0001, $1B2B, $1B32
ai_pc_1b30:
    ai_set_var1_26 $0001
ai_pc_1b32:
    ai_if_field_lt_2f_short $0081, $0038, $0001, $1B32, $1B39
ai_pc_1b37:
    ai_set_var1_26 $0001
ai_pc_1b39:
    ai_move_toward_e4 $0000, $0000
ai_pc_1b3c:
    ai_if_var1_ne_0b_short $0001, $1B3C, $1B47
ai_pc_1b3f:
    ai_tgt2_cur_c1
ai_pc_1b40:
    ai_cast_e9 $0003, $0026
ai_pc_1b43:
    ai_tgt2_none_c0
ai_pc_1b44:
    ai_move_toward_e4 $0000, $0078
ai_pc_1b47:
    ai_jmp_01_short $1B47, $1B4C
ai_pc_1b49:
    ai_move_toward_e4 $0000, $0000
ai_pc_1b4c:
    ai_ret_00
ai_pc_1b4d:
    ai_set_var3_28 $0004
ai_pc_1b4f:
    ai_call_ff $6AE1
ai_pc_1b52:
    ai_if_pos_same_9d_short $1B52, $1B5A
ai_pc_1b54:
    ai_pos_save_9f
ai_pc_1b55:
    ai_move_toward_e4 $0002, $0005
ai_pc_1b58:
    ai_jmp_01_short $1B58, $1B5E
ai_pc_1b5a:
    ai_pos_save_9f
ai_pc_1b5b:
    ai_move_toward_alt_fd $0002, $0005
ai_pc_1b5e:
    ai_dec_var3_21
ai_pc_1b5f:
    ai_if_var3_nz_05_short $1B5F, $1B64
ai_pc_1b61:
    ai_jmp_01_long $1B61, $1B66
ai_pc_1b64:
    ai_if_tgt_not_within_64_56_short $1B64, $1B4F
ai_pc_1b66:
    ai_ret_00
ai_pc_1b67:
    ai_set_var3_28 $000F
ai_pc_1b69:
    ai_if_tgt_not_within_48_51_short $1B69, $1B79
ai_pc_1b6b:
    ai_call_ff $6AE1
ai_pc_1b6e:
    ai_move_away_alt_fe $0002, $0005
ai_pc_1b71:
    ai_dec_var3_21
ai_pc_1b72:
    ai_if_var3_nz_05_short $1B72, $1B77
ai_pc_1b74:
    ai_jmp_01_long $1B74, $1B79
ai_pc_1b77:
    ai_jmp_01_short $1B77, $1B69
ai_pc_1b79:
    ai_ret_00
ai_pc_1b7a:
    ai_call_ff $1BA5
ai_pc_1b7d:
    ai_rnd_var3_2c $000F
ai_pc_1b7f:
    ai_if_var3_nz_05_short $1B7F, $1B86
ai_pc_1b81:
    ai_call_ff $6653
ai_pc_1b84:
    ai_jmp_01_short $1B84, $1B9D
ai_pc_1b86:
    ai_call_ff $6AE1
ai_pc_1b89:
    ai_call_ff $1C41
ai_pc_1b8c:
    ai_if_tgt_not_within_48_51_short $1B8C, $1B93
ai_pc_1b8e:
    ai_call_ff $1BAB
ai_pc_1b91:
    ai_jmp_01_short $1B91, $1B9D
ai_pc_1b93:
    ai_if_tgt_not_within_64_56_short $1B93, $1B9A
ai_pc_1b95:
    ai_call_ff $1BC2
ai_pc_1b98:
    ai_jmp_01_short $1B98, $1B9D
ai_pc_1b9a:
    ai_call_ff $1BED
ai_pc_1b9d:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $1B9D, $1B7D
ai_pc_1ba2:
    ai_jmp_01_short $1BA2, $1B7D
