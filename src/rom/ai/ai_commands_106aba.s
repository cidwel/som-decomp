.setcpu "65816"
.segment "CODE"
.org $6ABA
.include "ai_command_macros.inc"
ai_pc_1ba5:
    ai_turn_facing_e3 $0000, $0005
ai_pc_1ba8:
    ai_pose_e2 $0000
ai_pc_1baa:
    ai_ret_00
ai_pc_1bab:
    ai_move_toward_e4 $0000, $0005
ai_pc_1bae:
    ai_if_field_gt_30_short $0080, $006D, $0000, $1BAE, $1BB9
ai_pc_1bb3:
    ai_move_toward_e4 $0003, $0005
ai_pc_1bb6:
    ai_call_ff $6B0F
ai_pc_1bb9:
    ai_if_tgt_not_within_16_34_short $1BB9, $1BBE
ai_pc_1bbb:
    ai_move_toward_alt_fd $000E, $0000
ai_pc_1bbe:
    ai_call_ff $1C7D
ai_pc_1bc1:
    ai_ret_00
ai_pc_1bc2:
    ai_move_toward_e4 $0000, $0005
ai_pc_1bc5:
    ai_if_field_gt_30_short $0080, $006D, $0000, $1BC5, $1BE3
ai_pc_1bca:
    ai_move_toward_e4 $0000, $0005
ai_pc_1bcd:
    ai_rnd_var3_2c $0002
ai_pc_1bcf:
    ai_if_var3_nz_05_short $1BCF, $1BD6
ai_pc_1bd1:
    ai_call_ff $1C1E
ai_pc_1bd4:
    ai_jmp_01_short $1BD4, $1BE1
ai_pc_1bd6:
    ai_if_var3_ne_0d_short $0001, $1BD6, $1BDE
ai_pc_1bd9:
    ai_call_ff $1C52
ai_pc_1bdc:
    ai_jmp_01_short $1BDC, $1BE1
ai_pc_1bde:
    ai_move_toward_e4 $0000, $0005
ai_pc_1be1:
    ai_jmp_01_short $1BE1, $1BEC
ai_pc_1be3:
    ai_move_toward_e4 $0004, $0000
ai_pc_1be6:
    ai_move_toward_e4 $000E, $0000
ai_pc_1be9:
    ai_move_toward_e4 $0004, $0000
ai_pc_1bec:
    ai_ret_00
ai_pc_1bed:
    ai_rnd_var3_2c $000F
ai_pc_1bef:
    ai_if_var3_nz_05_short $1BEF, $1BF9
ai_pc_1bf1:
    ai_tgt2_self_c4
ai_pc_1bf2:
    ai_cast_e9 $0008, $001C
ai_pc_1bf5:
    ai_tgt2_none_c0
ai_pc_1bf6:
    ai_turn_facing_e3 $0000, $003C
ai_pc_1bf9:
    ai_call_ff $6AE1
ai_pc_1bfc:
    ai_if_pos_same_9d_short $1BFC, $1C04
ai_pc_1bfe:
    ai_pos_save_9f
ai_pc_1bff:
    ai_move_toward_e4 $0001, $0005
ai_pc_1c02:
    ai_jmp_01_short $1C02, $1C08
ai_pc_1c04:
    ai_pos_save_9f
ai_pc_1c05:
    ai_move_toward_alt_fd $0001, $0005
ai_pc_1c08:
    ai_if_tgt_not_within_64_56_short $1C08, $1BF9
ai_pc_1c0a:
    ai_rnd_var3_2c $000F
ai_pc_1c0c:
    ai_if_var3_nz_05_short $1C0C, $1C1D
ai_pc_1c0e:
    ai_if_field_gt_30_short $0080, $006D, $0000, $1C0E, $1C1D
ai_pc_1c13:
    ai_move_toward_e4 $0000, $0000
ai_pc_1c16:
    ai_call_ff $6B0F
ai_pc_1c19:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_1c1d:
    ai_ret_00
ai_pc_1c1e:
    ai_move_toward_e4 $0003, $0005
ai_pc_1c21:
    ai_call_ff $6B0F
ai_pc_1c24:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_1c28:
    ai_move_toward_alt_fd $000E, $0000
ai_pc_1c2b:
    ai_call_ff $6B0F
ai_pc_1c2e:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_1c32:
    ai_move_toward_e4 $0003, $0005
ai_pc_1c35:
    ai_pose_e2 $0002
ai_pc_1c37:
    ai_call_ff $6B0F
ai_pc_1c3a:
    ai_move_toward_e4 $000E, $0000
ai_pc_1c3d:
    ai_call_ff $1C7D
ai_pc_1c40:
    ai_ret_00
ai_pc_1c41:
    ai_if_no_ally_64_54_short $1C41, $1C51
ai_pc_1c43:
    ai_tgt2_ally_d8
ai_pc_1c44:
    ai_if_word_gt_bd_short $0082, $0002, $0045, $0000, $1C44, $1C51
ai_pc_1c4a:
    ai_cast_e9 $0008, $000B
ai_pc_1c4d:
    ai_tgt2_none_c0
ai_pc_1c4e:
    ai_turn_facing_e3 $0000, $003C
ai_pc_1c51:
    ai_ret_00
ai_pc_1c52:
    ai_rnd_var3_2c $0001
ai_pc_1c54:
    ai_call_ff $6AE1
ai_pc_1c57:
    ai_if_pos_same_9d_short $1C57, $1C5F
ai_pc_1c59:
    ai_pos_save_9f
ai_pc_1c5a:
    ai_move_toward_e4 $0002, $0005
ai_pc_1c5d:
    ai_jmp_01_short $1C5D, $1C63
ai_pc_1c5f:
    ai_pos_save_9f
ai_pc_1c60:
    ai_move_toward_alt_fd $0002, $0005
ai_pc_1c63:
    ai_if_var3_nz_05_short $1C63, $1C6A
ai_pc_1c65:
    ai_if_tgt_not_within_48_51_short $1C65, $1C6A
ai_pc_1c67:
    ai_jmp_01_long $1C67, $1C6C
ai_pc_1c6a:
    ai_if_tgt_not_within_32_4c_short $1C6A, $1C54
ai_pc_1c6c:
    ai_move_toward_e4 $0003, $0005
ai_pc_1c6f:
    ai_call_ff $6B0F
ai_pc_1c72:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_1c76:
    ai_move_toward_e4 $0003, $0005
ai_pc_1c79:
    ai_call_ff $6B0F
ai_pc_1c7c:
    ai_ret_00
ai_pc_1c7d:
    ai_if_tgt_not_within_48_51_short $1C7D, $1C94
ai_pc_1c7f:
    ai_call_ff $6AE1
ai_pc_1c82:
    ai_if_tgt_not_within_48_51_short $1C82, $1C8F
ai_pc_1c84:
    ai_if_field_gt_30_short $0080, $006D, $0000, $1C84, $1C8F
ai_pc_1c89:
    ai_move_toward_e4 $0003, $0005
ai_pc_1c8c:
    ai_call_ff $6B0F
ai_pc_1c8f:
    ai_move_toward_alt_fd $0005, $000A
ai_pc_1c92:
    ai_jmp_01_short $1C92, $1C7D
ai_pc_1c94:
    ai_ret_00
ai_pc_1c95:
    ai_call_ff $1CC4
ai_pc_1c98:
    ai_rnd_var3_2c $0007
ai_pc_1c9a:
    ai_if_var3_nz_05_short $1C9A, $1CA1
ai_pc_1c9c:
    ai_call_ff $685D
ai_pc_1c9f:
    ai_jmp_01_short $1C9F, $1CBC
ai_pc_1ca1:
    ai_call_ff $6AE1
ai_pc_1ca4:
    ai_if_tgt_not_within_32_4c_short $1CA4, $1CAB
ai_pc_1ca6:
    ai_call_ff $1CF6
ai_pc_1ca9:
    ai_jmp_01_short $1CA9, $1CBC
ai_pc_1cab:
    ai_if_tgt_not_within_48_51_short $1CAB, $1CB2
ai_pc_1cad:
    ai_call_ff $1D0F
ai_pc_1cb0:
    ai_jmp_01_short $1CB0, $1CBC
ai_pc_1cb2:
    ai_if_tgt_not_within_64_56_short $1CB2, $1CB9
ai_pc_1cb4:
    ai_call_ff $1D3F
ai_pc_1cb7:
    ai_jmp_01_short $1CB7, $1CBC
ai_pc_1cb9:
    ai_call_ff $1D7D
ai_pc_1cbc:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $1CBC, $1C98
ai_pc_1cc1:
    ai_jmp_01_short $1CC1, $1C98
