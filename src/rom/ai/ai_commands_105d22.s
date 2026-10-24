.setcpu "65816"
.segment "CODE"
.org $5D22
.include "ai_command_macros.inc"
ai_pc_0e0d:
    ai_pose_e2 $0000
ai_pc_0e0f:
    ai_ret_00
ai_pc_0e10:
    ai_move_toward_card_be $0000, $0000
ai_pc_0e13:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0E13, $0E1E
ai_pc_0e18:
    ai_move_toward_card_be $0000, $0000
ai_pc_0e1b:
    ai_call_ff $6B0F
ai_pc_0e1e:
    ai_call_ff $0EDB
ai_pc_0e21:
    ai_ret_00
ai_pc_0e22:
    ai_move_toward_card_be $0000, $0000
ai_pc_0e25:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0E25, $0E2F
ai_pc_0e2a:
    ai_call_ff $0EC0
ai_pc_0e2d:
    ai_jmp_01_short $0E2D, $0E32
ai_pc_0e2f:
    ai_call_ff $0EDB
ai_pc_0e32:
    ai_ret_00
ai_pc_0e33:
    ai_move_toward_card_be $0000, $0000
ai_pc_0e36:
    ai_if_field_gt_30_long $0080, $006D, $0000, $0E36, $0E7E
ai_pc_0e3c:
    ai_if_obj_outside_5f_short $0080, $0E3C, $0E79
ai_pc_0e3f:
    ai_move_toward_card_be $0000, $0000
ai_pc_0e42:
    ai_rnd_var3_2c $000F
ai_pc_0e44:
    ai_if_var3_nz_05_short $0E44, $0E69
ai_pc_0e46:
    ai_if_word_and_nz_ba_short $0081, $0010, $0010, $0000, $0E46, $0E64
ai_pc_0e4c:
    ai_tgt2_cur_c1
ai_pc_0e4d:
    ai_cast_e9 $0005, $001E
ai_pc_0e50:
    ai_tgt2_none_c0
ai_pc_0e51:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_0e54:
    ai_if_word_and_z_bb_short $0081, $0010, $0010, $0000, $0E54, $0E5F
ai_pc_0e5a:
    ai_call_ff $0E94
ai_pc_0e5d:
    ai_jmp_01_short $0E5D, $0E62
ai_pc_0e5f:
    ai_call_ff $0EB3
ai_pc_0e62:
    ai_jmp_01_short $0E62, $0E67
ai_pc_0e64:
    ai_call_ff $0E94
ai_pc_0e67:
    ai_jmp_01_short $0E67, $0E77
ai_pc_0e69:
    ai_if_word_and_z_bb_short $0081, $0010, $0010, $0000, $0E69, $0E74
ai_pc_0e6f:
    ai_call_ff $0E94
ai_pc_0e72:
    ai_jmp_01_short $0E72, $0E77
ai_pc_0e74:
    ai_move_toward_card_be $0000, $0000
ai_pc_0e77:
    ai_jmp_01_short $0E77, $0E7C
ai_pc_0e79:
    ai_move_toward_card_be $0000, $0000
ai_pc_0e7c:
    ai_jmp_01_short $0E7C, $0E81
ai_pc_0e7e:
    ai_move_toward_card_be $0000, $0000
ai_pc_0e81:
    ai_ret_00
ai_pc_0e82:
    ai_call_ff $6AE1
ai_pc_0e85:
    ai_if_pos_same_9d_short $0E85, $0E8D
ai_pc_0e87:
    ai_pos_save_9f
ai_pc_0e88:
    ai_move_toward_card_be $0004, $0000
ai_pc_0e8b:
    ai_jmp_01_short $0E8B, $0E91
ai_pc_0e8d:
    ai_pos_save_9f
ai_pc_0e8e:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_0e91:
    ai_if_tgt_not_within_64_56_short $0E91, $0E82
ai_pc_0e93:
    ai_ret_00
ai_pc_0e94:
    ai_call_ff $0EC0
ai_pc_0e97:
    ai_if_word_and_z_bb_short $0081, $0010, $0010, $0000, $0E97, $0EAF
ai_pc_0e9d:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0E9D, $0EAA
ai_pc_0ea2:
    ai_move_toward_card_be $0000, $0005
ai_pc_0ea5:
    ai_call_ff $6B0F
ai_pc_0ea8:
    ai_jmp_01_short $0EA8, $0EAD
ai_pc_0eaa:
    ai_move_toward_card_be $0000, $0005
ai_pc_0ead:
    ai_jmp_01_short $0EAD, $0E97
ai_pc_0eaf:
    ai_call_ff $0EDB
ai_pc_0eb2:
    ai_ret_00
ai_pc_0eb3:
    ai_call_ff $0EC0
ai_pc_0eb6:
    ai_move_toward_card_be $0000, $0005
ai_pc_0eb9:
    ai_call_ff $6B0F
ai_pc_0ebc:
    ai_call_ff $0EDB
ai_pc_0ebf:
    ai_ret_00
ai_pc_0ec0:
    ai_rnd_var3_2c $0001
ai_pc_0ec2:
    ai_call_ff $6AE1
ai_pc_0ec5:
    ai_if_pos_same_9d_short $0EC5, $0ECD
ai_pc_0ec7:
    ai_pos_save_9f
ai_pc_0ec8:
    ai_move_toward_card_be $0004, $000F
ai_pc_0ecb:
    ai_jmp_01_short $0ECB, $0ED1
ai_pc_0ecd:
    ai_pos_save_9f
ai_pc_0ece:
    ai_move_toward_alt_fd $0004, $000F
ai_pc_0ed1:
    ai_if_var3_nz_05_short $0ED1, $0ED8
ai_pc_0ed3:
    ai_if_tgt_not_within_32_4c_short $0ED3, $0ED8
ai_pc_0ed5:
    ai_jmp_01_long $0ED5, $0EDA
ai_pc_0ed8:
    ai_if_tgt_not_within_16_34_short $0ED8, $0EC2
ai_pc_0eda:
    ai_ret_00
ai_pc_0edb:
    ai_if_tgt_not_within_48_51_short $0EDB, $0EEE
ai_pc_0edd:
    ai_call_ff $6AE1
ai_pc_0ee0:
    ai_if_pos_same_9d_short $0EE0, $0EE8
ai_pc_0ee2:
    ai_pos_save_9f
ai_pc_0ee3:
    ai_move_toward_card_be $0005, $000F
ai_pc_0ee6:
    ai_jmp_01_short $0EE6, $0EEC
ai_pc_0ee8:
    ai_pos_save_9f
ai_pc_0ee9:
    ai_move_toward_alt_fd $0005, $000F
ai_pc_0eec:
    ai_jmp_01_short $0EEC, $0EDB
ai_pc_0eee:
    ai_ret_00
ai_pc_0eef:
    ai_call_ff $0F1E
ai_pc_0ef2:
    ai_rnd_var3_2c $000F
ai_pc_0ef4:
    ai_if_var3_nz_05_short $0EF4, $0EFB
ai_pc_0ef6:
    ai_call_ff $6627
ai_pc_0ef9:
    ai_jmp_01_short $0EF9, $0F16
ai_pc_0efb:
    ai_call_ff $6AE1
ai_pc_0efe:
    ai_if_tgt_not_within_16_34_short $0EFE, $0F05
ai_pc_0f00:
    ai_call_ff $0F21
ai_pc_0f03:
    ai_jmp_01_short $0F03, $0F16
ai_pc_0f05:
    ai_if_tgt_not_within_48_51_short $0F05, $0F0C
ai_pc_0f07:
    ai_call_ff $0F33
ai_pc_0f0a:
    ai_jmp_01_short $0F0A, $0F16
ai_pc_0f0c:
    ai_if_tgt_not_within_64_56_short $0F0C, $0F13
ai_pc_0f0e:
    ai_call_ff $0F56
ai_pc_0f11:
    ai_jmp_01_short $0F11, $0F16
ai_pc_0f13:
    ai_call_ff $0F8A
ai_pc_0f16:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $0F16, $0EF2
ai_pc_0f1b:
    ai_jmp_01_short $0F1B, $0EF2
