.setcpu "65816"
.segment "CODE"
.org $5B67
.include "ai_command_macros.inc"
ai_pc_0c52:
    ai_pose_e2 $0007
ai_pc_0c54:
    ai_call_ff $6AE1
ai_pc_0c57:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_0c5b:
    ai_flash_fc
ai_pc_0c5c:
    ai_move_toward_card_be $0000, $0000
ai_pc_0c5f:
    ai_call_ff $6B0F
ai_pc_0c62:
    ai_flash_fc
ai_pc_0c63:
    ai_move_toward_card_be $0000, $0000
ai_pc_0c66:
    ai_ret_00
ai_pc_0c67:
    ai_move_toward_e4 $0000, $0000
ai_pc_0c6a:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0C6A, $0C75
ai_pc_0c6f:
    ai_move_toward_e4 $0000, $0000
ai_pc_0c72:
    ai_call_ff $6B0F
ai_pc_0c75:
    ai_move_toward_alt_fd $000E, $0000
ai_pc_0c78:
    ai_call_ff $0D16
ai_pc_0c7b:
    ai_ret_00
ai_pc_0c7c:
    ai_move_toward_e4 $0000, $0000
ai_pc_0c7f:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0C7F, $0C8A
ai_pc_0c84:
    ai_move_toward_e4 $0000, $0000
ai_pc_0c87:
    ai_call_ff $6B0F
ai_pc_0c8a:
    ai_call_ff $0D16
ai_pc_0c8d:
    ai_ret_00
ai_pc_0c8e:
    ai_move_toward_e4 $0000, $0000
ai_pc_0c91:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0C91, $0CBC
ai_pc_0c96:
    ai_rnd_var3_2c $0002
ai_pc_0c98:
    ai_if_var3_nz_05_short $0C98, $0CB7
ai_pc_0c9a:
    ai_if_tgt_not_lane_v64_66_short $0C9A, $0CA6
ai_pc_0c9c:
    ai_flash_fc
ai_pc_0c9d:
    ai_move_toward_card_be $0000, $0000
ai_pc_0ca0:
    ai_call_ff $6B0F
ai_pc_0ca3:
    ai_flash_fc
ai_pc_0ca4:
    ai_jmp_01_short $0CA4, $0CB5
ai_pc_0ca6:
    ai_if_tgt_not_lane_h64_6f_short $0CA6, $0CB2
ai_pc_0ca8:
    ai_flash_fc
ai_pc_0ca9:
    ai_move_toward_card_be $0000, $0000
ai_pc_0cac:
    ai_call_ff $6B0F
ai_pc_0caf:
    ai_flash_fc
ai_pc_0cb0:
    ai_jmp_01_short $0CB0, $0CB5
ai_pc_0cb2:
    ai_call_ff $0CFC
ai_pc_0cb5:
    ai_jmp_01_short $0CB5, $0CBA
ai_pc_0cb7:
    ai_call_ff $0CFC
ai_pc_0cba:
    ai_jmp_01_short $0CBA, $0CBF
ai_pc_0cbc:
    ai_move_toward_e4 $0000, $0000
ai_pc_0cbf:
    ai_ret_00
ai_pc_0cc0:
    ai_move_toward_e4 $0000, $0000
ai_pc_0cc3:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0CC3, $0CDA
ai_pc_0cc8:
    ai_rnd_var3_2c $000F
ai_pc_0cca:
    ai_if_var3_nz_05_short $0CCA, $0CD5
ai_pc_0ccc:
    ai_rnd_var3_2c $0002
ai_pc_0cce:
    ai_if_var3_nz_05_short $0CCE, $0CD5
ai_pc_0cd0:
    ai_tgt2_self_c4
ai_pc_0cd1:
    ai_cast_e9 $0003, $0005
ai_pc_0cd4:
    ai_tgt2_none_c0
ai_pc_0cd5:
    ai_call_ff $0CFC
ai_pc_0cd8:
    ai_jmp_01_short $0CD8, $0CDD
ai_pc_0cda:
    ai_move_toward_e4 $0000, $0000
ai_pc_0cdd:
    ai_ret_00
ai_pc_0cde:
    ai_rnd_var3_2c $000F
ai_pc_0ce0:
    ai_if_var3_nz_05_short $0CE0, $0CF8
ai_pc_0ce2:
    ai_if_tgt_not_lane_v_6a_short $0CE2, $0CEE
ai_pc_0ce4:
    ai_flash_fc
ai_pc_0ce5:
    ai_move_toward_card_be $0000, $0005
ai_pc_0ce8:
    ai_call_ff $6B0F
ai_pc_0ceb:
    ai_flash_fc
ai_pc_0cec:
    ai_jmp_01_short $0CEC, $0CF8
ai_pc_0cee:
    ai_if_tgt_not_lane_h_73_short $0CEE, $0CF8
ai_pc_0cf0:
    ai_flash_fc
ai_pc_0cf1:
    ai_move_toward_card_be $0000, $0005
ai_pc_0cf4:
    ai_call_ff $6B0F
ai_pc_0cf7:
    ai_flash_fc
ai_pc_0cf8:
    ai_call_ff $0CFC
ai_pc_0cfb:
    ai_ret_00
ai_pc_0cfc:
    ai_set_var2_27 $0004
ai_pc_0cfe:
    ai_call_ff $6AE1
ai_pc_0d01:
    ai_if_pos_same_9d_short $0D01, $0D09
ai_pc_0d03:
    ai_pos_save_9f
ai_pc_0d04:
    ai_move_toward_e4 $0001, $0005
ai_pc_0d07:
    ai_jmp_01_short $0D07, $0D0D
ai_pc_0d09:
    ai_pos_save_9f
ai_pc_0d0a:
    ai_move_toward_alt_fd $0001, $0005
ai_pc_0d0d:
    ai_dec_var2_20
ai_pc_0d0e:
    ai_if_var2_nz_04_short $0D0E, $0D13
ai_pc_0d10:
    ai_jmp_01_long $0D10, $0D15
ai_pc_0d13:
    ai_if_tgt_not_within_64_56_short $0D13, $0CFE
ai_pc_0d15:
    ai_ret_00
ai_pc_0d16:
    ai_if_tgt_not_within_32_4c_short $0D16, $0D29
ai_pc_0d18:
    ai_call_ff $6AE1
ai_pc_0d1b:
    ai_if_pos_same_9d_short $0D1B, $0D23
ai_pc_0d1d:
    ai_pos_save_9f
ai_pc_0d1e:
    ai_move_toward_e4 $0005, $000A
ai_pc_0d21:
    ai_jmp_01_short $0D21, $0D27
ai_pc_0d23:
    ai_pos_save_9f
ai_pc_0d24:
    ai_move_toward_alt_fd $0005, $000A
ai_pc_0d27:
    ai_jmp_01_short $0D27, $0D16
ai_pc_0d29:
    ai_ret_00
ai_pc_0d2a:
    ai_call_ff $0D59
ai_pc_0d2d:
    ai_rnd_var3_2c $000F
ai_pc_0d2f:
    ai_if_var3_nz_05_short $0D2F, $0D36
ai_pc_0d31:
    ai_call_ff $693B
ai_pc_0d34:
    ai_jmp_01_short $0D34, $0D51
ai_pc_0d36:
    ai_call_ff $6AE1
ai_pc_0d39:
    ai_if_tgt_not_within_32_4c_short $0D39, $0D40
ai_pc_0d3b:
    ai_call_ff $0D5C
ai_pc_0d3e:
    ai_jmp_01_short $0D3E, $0D51
ai_pc_0d40:
    ai_if_tgt_not_within_48_51_short $0D40, $0D47
ai_pc_0d42:
    ai_call_ff $0D70
ai_pc_0d45:
    ai_jmp_01_short $0D45, $0D51
ai_pc_0d47:
    ai_if_tgt_not_within_64_56_short $0D47, $0D4E
ai_pc_0d49:
    ai_call_ff $0DB1
ai_pc_0d4c:
    ai_jmp_01_short $0D4C, $0D51
ai_pc_0d4e:
    ai_call_ff $0DB1
ai_pc_0d51:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $0D51, $0D2D
ai_pc_0d56:
    ai_jmp_01_short $0D56, $0D2D
