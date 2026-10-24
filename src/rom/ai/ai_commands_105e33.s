.setcpu "65816"
.segment "CODE"
.org $5E33
.include "ai_command_macros.inc"
ai_pc_0f1e:
    ai_pose_e2 $0000
ai_pc_0f20:
    ai_ret_00
ai_pc_0f21:
    ai_move_toward_e4 $000E, $0000
ai_pc_0f24:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0F24, $0F2F
ai_pc_0f29:
    ai_move_toward_e4 $0000, $0000
ai_pc_0f2c:
    ai_call_ff $6B23
ai_pc_0f2f:
    ai_call_ff $0FFB
ai_pc_0f32:
    ai_ret_00
ai_pc_0f33:
    ai_move_toward_e4 $0000, $0000
ai_pc_0f36:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0F36, $0F52
ai_pc_0f3b:
    ai_if_tgt_not_lane_v64_66_short $0F3B, $0F45
ai_pc_0f3d:
    ai_move_toward_card_be $0000, $0005
ai_pc_0f40:
    ai_call_ff $6B23
ai_pc_0f43:
    ai_jmp_01_short $0F43, $0F52
ai_pc_0f45:
    ai_if_tgt_not_lane_h64_6f_short $0F45, $0F4F
ai_pc_0f47:
    ai_move_toward_card_be $0000, $0005
ai_pc_0f4a:
    ai_call_ff $6B23
ai_pc_0f4d:
    ai_jmp_01_short $0F4D, $0F52
ai_pc_0f4f:
    ai_move_away_e6 $0000, $0005
ai_pc_0f52:
    ai_call_ff $0FD0
ai_pc_0f55:
    ai_ret_00
ai_pc_0f56:
    ai_move_toward_e4 $0000, $0000
ai_pc_0f59:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0F59, $0F86
ai_pc_0f5e:
    ai_rnd_var3_2c $000F
ai_pc_0f60:
    ai_if_var3_nz_05_short $0F60, $0F6A
ai_pc_0f62:
    ai_if_obj_outside_5f_short $0080, $0F62, $0F68
ai_pc_0f65:
    ai_call_ff $0F99
ai_pc_0f68:
    ai_jmp_01_short $0F68, $0F6D
ai_pc_0f6a:
    ai_move_toward_e4 $0000, $0000
ai_pc_0f6d:
    ai_if_tgt_not_lane_v_6a_short $0F6D, $0F77
ai_pc_0f6f:
    ai_move_toward_card_be $0000, $0005
ai_pc_0f72:
    ai_call_ff $6B23
ai_pc_0f75:
    ai_jmp_01_short $0F75, $0F84
ai_pc_0f77:
    ai_if_tgt_not_lane_h_73_short $0F77, $0F81
ai_pc_0f79:
    ai_move_toward_card_be $0000, $0005
ai_pc_0f7c:
    ai_call_ff $6B23
ai_pc_0f7f:
    ai_jmp_01_short $0F7F, $0F84
ai_pc_0f81:
    ai_move_toward_e4 $0000, $0000
ai_pc_0f84:
    ai_jmp_01_short $0F84, $0F89
ai_pc_0f86:
    ai_move_toward_e4 $0000, $0000
ai_pc_0f89:
    ai_ret_00
ai_pc_0f8a:
    ai_rnd_var3_2c $0004
ai_pc_0f8c:
    ai_if_var3_nz_05_short $0F8C, $0F93
ai_pc_0f8e:
    ai_call_ff $1029
ai_pc_0f91:
    ai_jmp_01_short $0F91, $0F96
ai_pc_0f93:
    ai_call_ff $100F
ai_pc_0f96:
    ai_if_tgt_not_within_64_56_short $0F96, $0F8A
ai_pc_0f98:
    ai_ret_00
ai_pc_0f99:
    ai_move_toward_e4 $0000, $0000
ai_pc_0f9c:
    ai_if_no_ally_64_54_short $0F9C, $0FC0
ai_pc_0f9e:
    ai_tgt2_ally_d8
ai_pc_0f9f:
    ai_rnd_var3_2c $0001
ai_pc_0fa1:
    ai_if_var3_nz_05_short $0FA1, $0FAC
ai_pc_0fa3:
    ai_cast_e9 $0004, $000B
ai_pc_0fa6:
    ai_tgt2_none_c0
ai_pc_0fa7:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_0faa:
    ai_jmp_01_short $0FAA, $0FBE
ai_pc_0fac:
    ai_if_field_gt_30_short $0082, $001D, $0000, $0FAC, $0FBA
ai_pc_0fb1:
    ai_cast_e9 $0004, $0009
ai_pc_0fb4:
    ai_tgt2_none_c0
ai_pc_0fb5:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_0fb8:
    ai_jmp_01_short $0FB8, $0FBE
ai_pc_0fba:
    ai_move_toward_e4 $0000, $0000
ai_pc_0fbd:
    ai_tgt2_none_c0
ai_pc_0fbe:
    ai_jmp_01_short $0FBE, $0FCF
ai_pc_0fc0:
    ai_move_toward_e4 $0000, $0000
ai_pc_0fc3:
    ai_rnd_var3_2c $0002
ai_pc_0fc5:
    ai_if_var3_nz_05_short $0FC5, $0FCF
ai_pc_0fc7:
    ai_tgt2_cur_c1
ai_pc_0fc8:
    ai_cast_e9 $0004, $0007
ai_pc_0fcb:
    ai_tgt2_none_c0
ai_pc_0fcc:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_0fcf:
    ai_ret_00
ai_pc_0fd0:
    ai_if_tgt_not_within_48_51_short $0FD0, $0FFA
ai_pc_0fd2:
    ai_call_ff $6AE1
ai_pc_0fd5:
    ai_if_pos_same_9d_short $0FD5, $0FDD
ai_pc_0fd7:
    ai_pos_save_9f
ai_pc_0fd8:
    ai_move_toward_e4 $0005, $000A
ai_pc_0fdb:
    ai_jmp_01_short $0FDB, $0FE1
ai_pc_0fdd:
    ai_pos_save_9f
ai_pc_0fde:
    ai_move_toward_alt_fd $0005, $000A
ai_pc_0fe1:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0FE1, $0FF8
ai_pc_0fe6:
    ai_if_tgt_not_lane_v64_66_short $0FE6, $0FF0
ai_pc_0fe8:
    ai_move_toward_card_be $0000, $0005
ai_pc_0feb:
    ai_call_ff $6B23
ai_pc_0fee:
    ai_jmp_01_short $0FEE, $0FF8
ai_pc_0ff0:
    ai_if_tgt_not_lane_h64_6f_short $0FF0, $0FF8
ai_pc_0ff2:
    ai_move_toward_card_be $0000, $0005
ai_pc_0ff5:
    ai_call_ff $6B23
ai_pc_0ff8:
    ai_jmp_01_short $0FF8, $0FD0
ai_pc_0ffa:
    ai_ret_00
ai_pc_0ffb:
    ai_if_tgt_not_within_48_51_short $0FFB, $100E
ai_pc_0ffd:
    ai_call_ff $6AE1
ai_pc_1000:
    ai_if_pos_same_9d_short $1000, $1008
ai_pc_1002:
    ai_pos_save_9f
ai_pc_1003:
    ai_move_away_e6 $0001, $0005
ai_pc_1006:
    ai_jmp_01_short $1006, $100C
ai_pc_1008:
    ai_pos_save_9f
ai_pc_1009:
    ai_move_away_alt_fe $0001, $0005
ai_pc_100c:
    ai_jmp_01_short $100C, $0FFB
ai_pc_100e:
    ai_ret_00
ai_pc_100f:
    ai_set_var2_27 $0004
ai_pc_1011:
    ai_call_ff $6AE1
ai_pc_1014:
    ai_if_pos_same_9d_short $1014, $101C
ai_pc_1016:
    ai_pos_save_9f
ai_pc_1017:
    ai_move_toward_e4 $0004, $000A
ai_pc_101a:
    ai_jmp_01_short $101A, $1020
ai_pc_101c:
    ai_pos_save_9f
ai_pc_101d:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_1020:
    ai_dec_var2_20
ai_pc_1021:
    ai_if_var2_nz_04_short $1021, $1026
ai_pc_1023:
    ai_jmp_01_long $1023, $1028
ai_pc_1026:
    ai_if_tgt_not_within_64_56_short $1026, $1011
ai_pc_1028:
    ai_ret_00
ai_pc_1029:
    ai_set_var2_27 $0004
ai_pc_102b:
    ai_call_ff $6AE1
ai_pc_102e:
    ai_if_pos_same_9d_short $102E, $1036
ai_pc_1030:
    ai_pos_save_9f
ai_pc_1031:
    ai_move_toward_e4 $0001, $0005
ai_pc_1034:
    ai_jmp_01_short $1034, $103A
ai_pc_1036:
    ai_pos_save_9f
ai_pc_1037:
    ai_move_toward_alt_fd $0001, $0005
ai_pc_103a:
    ai_dec_var2_20
ai_pc_103b:
    ai_if_var2_nz_04_short $103B, $1040
ai_pc_103d:
    ai_jmp_01_long $103D, $1042
ai_pc_1040:
    ai_if_tgt_not_within_64_56_short $1040, $102B
ai_pc_1042:
    ai_ret_00
ai_pc_1043:
    ai_call_ff $1079
ai_pc_1046:
    ai_rnd_var3_2c $0007
ai_pc_1048:
    ai_if_var3_nz_05_short $1048, $104F
ai_pc_104a:
    ai_call_ff $675B
ai_pc_104d:
    ai_jmp_01_short $104D, $1071
ai_pc_104f:
    ai_call_ff $6AE1
ai_pc_1052:
    ai_if_tgt_not_within_16_34_short $1052, $1059
ai_pc_1054:
    ai_call_ff $109C
ai_pc_1057:
    ai_jmp_01_short $1057, $1071
ai_pc_1059:
    ai_if_tgt_not_within_32_4c_short $1059, $1060
ai_pc_105b:
    ai_call_ff $10C6
ai_pc_105e:
    ai_jmp_01_short $105E, $1071
ai_pc_1060:
    ai_if_tgt_not_within_64_56_short $1060, $1067
ai_pc_1062:
    ai_call_ff $10F0
ai_pc_1065:
    ai_jmp_01_short $1065, $1071
ai_pc_1067:
    ai_rnd_var3_2c $0007
ai_pc_1069:
    ai_if_var3_nz_05_short $1069, $106E
ai_pc_106b:
    ai_call_ff $113D
ai_pc_106e:
    ai_call_ff $10F0
ai_pc_1071:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $1071, $1046
ai_pc_1076:
    ai_jmp_01_short $1076, $1046
