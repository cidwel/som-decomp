.setcpu "65816"
.segment "CODE"
.org $6D07
.include "ai_command_macros.inc"
ai_pc_1df2:
    ai_pose_e2 $0000
ai_pc_1df4:
    ai_set_var1_26 $000A
ai_pc_1df6:
    ai_ret_00
ai_pc_1df7:
    ai_call_ff $3B5D
ai_pc_1dfa:
    ai_ret_00
ai_pc_1dfb:
    ai_move_toward_e4 $0000, $0005
ai_pc_1dfe:
    ai_rnd_var3_2c $0007
ai_pc_1e00:
    ai_if_var3_nz_05_short $1E00, $1E07
ai_pc_1e02:
    ai_call_ff $1E22
ai_pc_1e05:
    ai_jmp_01_short $1E05, $1E0A
ai_pc_1e07:
    ai_move_toward_e4 $0000, $0005
ai_pc_1e0a:
    ai_ret_00
ai_pc_1e0b:
    ai_if_obj_outside_5f_short $0080, $1E0B, $1E21
ai_pc_1e0e:
    ai_if_var1_lt_17_short $0001, $1E0E, $1E21
ai_pc_1e11:
    ai_if_crowd_gt_f5_short $0002, $1E11, $1E1E
ai_pc_1e14:
    ai_move_toward_card_be $0000, $0005
ai_pc_1e17:
    ai_pose_e2 $0003
ai_pc_1e19:
    ai_cmd43_ed $0012
ai_pc_1e1b:
    ai_dec_var1_1f
ai_pc_1e1c:
    ai_jmp_01_short $1E1C, $1E21
ai_pc_1e1e:
    ai_move_toward_e4 $0000, $0005
ai_pc_1e21:
    ai_ret_00
ai_pc_1e22:
    ai_rnd_var3_2c $0007
ai_pc_1e24:
    ai_if_obj_outside_5f_short $0080, $1E24, $1E4E
ai_pc_1e27:
    ai_if_no_ally_64_54_short $1E27, $1E4B
ai_pc_1e29:
    ai_tgt2_ally_d8
ai_pc_1e2a:
    ai_if_word_gt_bd_short $0082, $003D, $0000, $0000, $1E2A, $1E35
ai_pc_1e30:
    ai_call_ff $1E4F
ai_pc_1e33:
    ai_jmp_01_short $1E33, $1E49
ai_pc_1e35:
    ai_if_word_and_z_bb_short $0082, $0010, $00FC, $007F, $1E35, $1E40
ai_pc_1e3b:
    ai_call_ff $1E81
ai_pc_1e3e:
    ai_jmp_01_short $1E3E, $1E49
ai_pc_1e40:
    ai_if_word_gt_bd_short $0082, $0002, $00A0, $0000, $1E40, $1E49
ai_pc_1e46:
    ai_call_ff $1E68
ai_pc_1e49:
    ai_jmp_01_short $1E49, $1E4E
ai_pc_1e4b:
    ai_call_ff $1E9A
ai_pc_1e4e:
    ai_ret_00
ai_pc_1e4f:
    ai_if_var3_nz_05_short $1E4F, $1E60
ai_pc_1e51:
    ai_call_ff $6AE1
ai_pc_1e54:
    ai_tgt2_cur_c1
ai_pc_1e55:
    ai_cast_e9 $0001, $0005
ai_pc_1e58:
    ai_tgt2_none_c0
ai_pc_1e59:
    ai_turn_facing_e3 $0000, $003C
ai_pc_1e5c:
    ai_pose_e2 $0002
ai_pc_1e5e:
    ai_jmp_01_short $1E5E, $1E67
ai_pc_1e60:
    ai_cast_e9 $0001, $0005
ai_pc_1e63:
    ai_tgt2_none_c0
ai_pc_1e64:
    ai_turn_facing_e3 $0000, $003C
ai_pc_1e67:
    ai_ret_00
ai_pc_1e68:
    ai_if_var3_nz_05_short $1E68, $1E79
ai_pc_1e6a:
    ai_call_ff $6AE1
ai_pc_1e6d:
    ai_tgt2_cur_c1
ai_pc_1e6e:
    ai_cast_e9 $0001, $000B
ai_pc_1e71:
    ai_tgt2_none_c0
ai_pc_1e72:
    ai_turn_facing_e3 $0000, $003C
ai_pc_1e75:
    ai_pose_e2 $0002
ai_pc_1e77:
    ai_jmp_01_short $1E77, $1E80
ai_pc_1e79:
    ai_cast_e9 $0001, $000B
ai_pc_1e7c:
    ai_tgt2_none_c0
ai_pc_1e7d:
    ai_turn_facing_e3 $0000, $003C
ai_pc_1e80:
    ai_ret_00
ai_pc_1e81:
    ai_if_var3_nz_05_short $1E81, $1E92
ai_pc_1e83:
    ai_call_ff $6AE1
ai_pc_1e86:
    ai_tgt2_cur_c1
ai_pc_1e87:
    ai_cast_e9 $0001, $000A
ai_pc_1e8a:
    ai_tgt2_none_c0
ai_pc_1e8b:
    ai_turn_facing_e3 $0000, $003C
ai_pc_1e8e:
    ai_pose_e2 $0002
ai_pc_1e90:
    ai_jmp_01_short $1E90, $1E99
ai_pc_1e92:
    ai_cast_e9 $0001, $000A
ai_pc_1e95:
    ai_tgt2_none_c0
ai_pc_1e96:
    ai_turn_facing_e3 $0000, $003C
ai_pc_1e99:
    ai_ret_00
ai_pc_1e9a:
    ai_if_var3_gt_15_short $0003, $1E9A, $1EA6
ai_pc_1e9d:
    ai_pose_e2 $0003
ai_pc_1e9f:
    ai_turn_facing_e3 $0000, $003C
ai_pc_1ea2:
    ai_pose_e2 $0002
ai_pc_1ea4:
    ai_jmp_01_short $1EA4, $1EAE
ai_pc_1ea6:
    ai_tgt2_cur_c1
ai_pc_1ea7:
    ai_cast_e9 $0001, $000C
ai_pc_1eaa:
    ai_tgt2_none_c0
ai_pc_1eab:
    ai_turn_facing_e3 $0000, $003C
ai_pc_1eae:
    ai_ret_00
ai_pc_1eaf:
    ai_call_ff $1EDE
ai_pc_1eb2:
    ai_rnd_var3_2c $000F
ai_pc_1eb4:
    ai_if_var3_nz_05_short $1EB4, $1EBB
ai_pc_1eb6:
    ai_call_ff $65CA
ai_pc_1eb9:
    ai_jmp_01_short $1EB9, $1ED6
ai_pc_1ebb:
    ai_call_ff $6AE1
ai_pc_1ebe:
    ai_if_tgt_not_within_32_4c_short $1EBE, $1EC5
ai_pc_1ec0:
    ai_call_ff $1EF3
ai_pc_1ec3:
    ai_jmp_01_short $1EC3, $1ED6
ai_pc_1ec5:
    ai_if_tgt_not_within_48_51_short $1EC5, $1ECC
ai_pc_1ec7:
    ai_call_ff $1F08
ai_pc_1eca:
    ai_jmp_01_short $1ECA, $1ED6
ai_pc_1ecc:
    ai_if_tgt_not_within_64_56_short $1ECC, $1ED3
ai_pc_1ece:
    ai_call_ff $1F0F
ai_pc_1ed1:
    ai_jmp_01_short $1ED1, $1ED6
ai_pc_1ed3:
    ai_call_ff $1F32
ai_pc_1ed6:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $1ED6, $1EB2
ai_pc_1edb:
    ai_jmp_01_short $1EDB, $1EB2
