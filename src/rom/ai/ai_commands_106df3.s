.setcpu "65816"
.segment "CODE"
.org $6DF3
.include "ai_command_macros.inc"
ai_pc_1ede:
    ai_pose_e2 $0004
ai_pc_1ee0:
    ai_call_ff $6AE1
ai_pc_1ee3:
    ai_pose_e2 $0004
ai_pc_1ee5:
    ai_if_word_gt_bd_short $0080, $0002, $00BD, $0000, $1EE5, $1EEE
ai_pc_1eeb:
    ai_jmp_01_long $1EEB, $1EF0
ai_pc_1eee:
    ai_if_tgt_not_within_64_56_short $1EEE, $1EE0
ai_pc_1ef0:
    ai_pose_e2 $0000
ai_pc_1ef2:
    ai_ret_00
ai_pc_1ef3:
    ai_move_toward_e4 $0000, $0000
ai_pc_1ef6:
    ai_if_field_gt_30_short $0080, $006D, $0000, $1EF6, $1F01
ai_pc_1efb:
    ai_move_toward_e4 $0000, $0000
ai_pc_1efe:
    ai_call_ff $6B19
ai_pc_1f01:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_1f04:
    ai_call_ff $1FD1
ai_pc_1f07:
    ai_ret_00
ai_pc_1f08:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_1f0b:
    ai_call_ff $1FD1
ai_pc_1f0e:
    ai_ret_00
ai_pc_1f0f:
    ai_move_toward_card_be $0000, $0000
ai_pc_1f12:
    ai_call_ff $1F44
ai_pc_1f15:
    ai_if_field_gt_30_short $0080, $006D, $0000, $1F15, $1F31
ai_pc_1f1a:
    ai_if_crowd_gt_f5_short $0001, $1F1A, $1F2E
ai_pc_1f1d:
    ai_rnd_var3_2c $000F
ai_pc_1f1f:
    ai_if_var3_nz_05_short $1F1F, $1F29
ai_pc_1f21:
    ai_call_ff $1FB6
ai_pc_1f24:
    ai_call_ff $6B19
ai_pc_1f27:
    ai_jmp_01_short $1F27, $1F2C
ai_pc_1f29:
    ai_move_toward_card_be $0000, $0000
ai_pc_1f2c:
    ai_jmp_01_short $1F2C, $1F31
ai_pc_1f2e:
    ai_move_toward_card_be $0000, $0000
ai_pc_1f31:
    ai_ret_00
ai_pc_1f32:
    ai_call_ff $6AE1
ai_pc_1f35:
    ai_if_pos_same_9d_short $1F35, $1F3D
ai_pc_1f37:
    ai_pos_save_9f
ai_pc_1f38:
    ai_move_toward_card_be $0004, $0000
ai_pc_1f3b:
    ai_jmp_01_short $1F3B, $1F41
ai_pc_1f3d:
    ai_pos_save_9f
ai_pc_1f3e:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_1f41:
    ai_if_tgt_not_within_64_56_short $1F41, $1F32
ai_pc_1f43:
    ai_ret_00
ai_pc_1f44:
    ai_if_obj_outside_5f_short $0080, $1F44, $1F64
ai_pc_1f47:
    ai_if_word_gt_bd_short $0080, $003D, $0000, $0000, $1F47, $1F52
ai_pc_1f4d:
    ai_call_ff $1F65
ai_pc_1f50:
    ai_jmp_01_short $1F50, $1F64
ai_pc_1f52:
    ai_if_word_gt_bd_short $0080, $0002, $00BD, $0000, $1F52, $1F5D
ai_pc_1f58:
    ai_call_ff $1F79
ai_pc_1f5b:
    ai_jmp_01_short $1F5B, $1F64
ai_pc_1f5d:
    ai_rnd_var3_2c $0001
ai_pc_1f5f:
    ai_if_var3_nz_05_short $1F5F, $1F64
ai_pc_1f61:
    ai_call_ff $1F8D
ai_pc_1f64:
    ai_ret_00
ai_pc_1f65:
    ai_pose_e2 $0002
ai_pc_1f67:
    ai_rnd_var3_2c $0007
ai_pc_1f69:
    ai_if_var3_nz_05_short $1F69, $1F71
ai_pc_1f6b:
    ai_pose_e2 $0003
ai_pc_1f6d:
    ai_pose_e2 $0007
ai_pc_1f6f:
    ai_jmp_01_short $1F6F, $1F76
ai_pc_1f71:
    ai_tgt2_self_c4
ai_pc_1f72:
    ai_cast_e9 $0005, $0029
ai_pc_1f75:
    ai_tgt2_none_c0
ai_pc_1f76:
    ai_pose_e2 $0008
ai_pc_1f78:
    ai_ret_00
ai_pc_1f79:
    ai_pose_e2 $0002
ai_pc_1f7b:
    ai_rnd_var3_2c $0007
ai_pc_1f7d:
    ai_if_var3_nz_05_short $1F7D, $1F85
ai_pc_1f7f:
    ai_pose_e2 $0003
ai_pc_1f81:
    ai_pose_e2 $0007
ai_pc_1f83:
    ai_jmp_01_short $1F83, $1F8A
ai_pc_1f85:
    ai_tgt2_cur_c1
ai_pc_1f86:
    ai_cast_e9 $0005, $0008
ai_pc_1f89:
    ai_tgt2_none_c0
ai_pc_1f8a:
    ai_pose_e2 $0008
ai_pc_1f8c:
    ai_ret_00
ai_pc_1f8d:
    ai_pose_e2 $0002
ai_pc_1f8f:
    ai_rnd_var3_2c $0007
ai_pc_1f91:
    ai_if_var3_nz_05_short $1F91, $1F99
ai_pc_1f93:
    ai_pose_e2 $0003
ai_pc_1f95:
    ai_pose_e2 $0007
ai_pc_1f97:
    ai_jmp_01_short $1F97, $1FB3
ai_pc_1f99:
    ai_rnd_var3_2c $0003
ai_pc_1f9b:
    ai_if_var3_nz_05_short $1F9B, $1FA4
ai_pc_1f9d:
    ai_tgt2_cur_c1
ai_pc_1f9e:
    ai_cast_e9 $0005, $0012
ai_pc_1fa1:
    ai_tgt2_none_c0
ai_pc_1fa2:
    ai_jmp_01_short $1FA2, $1FB3
ai_pc_1fa4:
    ai_if_var3_ne_0d_short $0001, $1FA4, $1FAE
ai_pc_1fa7:
    ai_tgt2_cur_c1
ai_pc_1fa8:
    ai_cast_e9 $0005, $0006
ai_pc_1fab:
    ai_tgt2_none_c0
ai_pc_1fac:
    ai_jmp_01_short $1FAC, $1FB3
ai_pc_1fae:
    ai_tgt2_cur_c1
ai_pc_1faf:
    ai_cast_e9 $0005, $0013
ai_pc_1fb2:
    ai_tgt2_none_c0
ai_pc_1fb3:
    ai_pose_e2 $0008
ai_pc_1fb5:
    ai_ret_00
ai_pc_1fb6:
    ai_rnd_var3_2c $0001
ai_pc_1fb8:
    ai_call_ff $6AE1
ai_pc_1fbb:
    ai_if_pos_same_9d_short $1FBB, $1FC3
ai_pc_1fbd:
    ai_pos_save_9f
ai_pc_1fbe:
    ai_move_toward_card_be $0002, $0000
ai_pc_1fc1:
    ai_jmp_01_short $1FC1, $1FC7
ai_pc_1fc3:
    ai_pos_save_9f
ai_pc_1fc4:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_1fc7:
    ai_if_var3_nz_05_short $1FC7, $1FCE
ai_pc_1fc9:
    ai_if_tgt_not_within_48_51_short $1FC9, $1FCE
ai_pc_1fcb:
    ai_jmp_01_long $1FCB, $1FD0
ai_pc_1fce:
    ai_if_tgt_not_within_32_4c_short $1FCE, $1FB8
ai_pc_1fd0:
    ai_ret_00
ai_pc_1fd1:
    ai_if_tgt_not_within_48_51_short $1FD1, $1FE4
ai_pc_1fd3:
    ai_call_ff $6AE1
ai_pc_1fd6:
    ai_if_pos_same_9d_short $1FD6, $1FDE
ai_pc_1fd8:
    ai_pos_save_9f
ai_pc_1fd9:
    ai_move_away_card_bf $0004, $0000
ai_pc_1fdc:
    ai_jmp_01_short $1FDC, $1FE2
ai_pc_1fde:
    ai_pos_save_9f
ai_pc_1fdf:
    ai_move_away_alt_fe $0004, $0000
ai_pc_1fe2:
    ai_jmp_01_short $1FE2, $1FD1
ai_pc_1fe4:
    ai_ret_00
ai_pc_1fe5:
    ai_call_ff $2014
ai_pc_1fe8:
    ai_rnd_var3_2c $0007
ai_pc_1fea:
    ai_if_var3_nz_05_short $1FEA, $1FF1
ai_pc_1fec:
    ai_call_ff $67B3
ai_pc_1fef:
    ai_jmp_01_short $1FEF, $200C
ai_pc_1ff1:
    ai_call_ff $6AE1
ai_pc_1ff4:
    ai_if_tgt_not_within_16_34_short $1FF4, $1FFB
ai_pc_1ff6:
    ai_call_ff $2017
ai_pc_1ff9:
    ai_jmp_01_short $1FF9, $200C
ai_pc_1ffb:
    ai_if_tgt_not_within_48_51_short $1FFB, $2002
ai_pc_1ffd:
    ai_call_ff $2021
ai_pc_2000:
    ai_jmp_01_short $2000, $200C
ai_pc_2002:
    ai_if_tgt_not_within_64_56_short $2002, $2009
ai_pc_2004:
    ai_call_ff $2028
ai_pc_2007:
    ai_jmp_01_short $2007, $200C
ai_pc_2009:
    ai_call_ff $42AA
ai_pc_200c:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $200C, $1FE8
ai_pc_2011:
    ai_jmp_01_short $2011, $1FE8
