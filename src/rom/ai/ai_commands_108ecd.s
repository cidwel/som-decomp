.setcpu "65816"
.segment "CODE"
.org $8ECD
.include "ai_command_macros.inc"
ai_pc_3fb8:
    ai_pose_e2 $0000
ai_pc_3fba:
    ai_set_var1_26 $000A
ai_pc_3fbc:
    ai_ret_00
ai_pc_3fbd:
    ai_move_toward_e4 $0000, $0000
ai_pc_3fc0:
    ai_if_field_gt_30_short $0080, $006D, $0000, $3FC0, $3FDC
ai_pc_3fc5:
    ai_rnd_var3_2c $0001
ai_pc_3fc7:
    ai_if_var3_nz_05_short $3FC7, $3FD6
ai_pc_3fc9:
    ai_move_toward_e4 $0000, $0000
ai_pc_3fcc:
    ai_flash_fc
ai_pc_3fcd:
    ai_call_ff $6B23
ai_pc_3fd0:
    ai_flash_fc
ai_pc_3fd1:
    ai_move_toward_e4 $0000, $0005
ai_pc_3fd4:
    ai_jmp_01_short $3FD4, $3FDC
ai_pc_3fd6:
    ai_move_toward_e4 $0000, $0000
ai_pc_3fd9:
    ai_call_ff $6B23
ai_pc_3fdc:
    ai_move_toward_alt_fd $000E, $0000
ai_pc_3fdf:
    ai_call_ff $40B1
ai_pc_3fe2:
    ai_ret_00
ai_pc_3fe3:
    ai_move_toward_e4 $0000, $0000
ai_pc_3fe6:
    ai_if_field_gt_30_short $0080, $006D, $0000, $3FE6, $3FF1
ai_pc_3feb:
    ai_move_toward_e4 $0000, $0000
ai_pc_3fee:
    ai_call_ff $6B23
ai_pc_3ff1:
    ai_call_ff $409A
ai_pc_3ff4:
    ai_ret_00
ai_pc_3ff5:
    ai_move_toward_e4 $0000, $0000
ai_pc_3ff8:
    ai_rnd_var3_2c $0004
ai_pc_3ffa:
    ai_if_var3_nz_05_short $3FFA, $4003
ai_pc_3ffc:
    ai_move_toward_e4 $0000, $0000
ai_pc_3fff:
    ai_pose_e2 $0004
ai_pc_4001:
    ai_jmp_01_short $4001, $400E
ai_pc_4003:
    ai_move_toward_e4 $0000, $0000
ai_pc_4006:
    ai_flash_fc
ai_pc_4007:
    ai_call_ff $6B23
ai_pc_400a:
    ai_flash_fc
ai_pc_400b:
    ai_move_toward_e4 $0000, $0005
ai_pc_400e:
    ai_ret_00
ai_pc_400f:
    ai_rnd_var3_2c $000F
ai_pc_4011:
    ai_if_var3_nz_05_short $4011, $4023
ai_pc_4013:
    ai_move_toward_e4 $0000, $0000
ai_pc_4016:
    ai_hop_e0 $0001, $0000, $003C
ai_pc_401a:
    ai_hop_e0 $0002, $0000, $003C
ai_pc_401e:
    ai_call_ff $4056
ai_pc_4021:
    ai_jmp_01_short $4021, $402F
ai_pc_4023:
    ai_if_pos_same_9d_short $4023, $402B
ai_pc_4025:
    ai_pos_save_9f
ai_pc_4026:
    ai_move_toward_e4 $0001, $0000
ai_pc_4029:
    ai_jmp_01_short $4029, $402F
ai_pc_402b:
    ai_pos_save_9f
ai_pc_402c:
    ai_move_toward_alt_fd $0001, $0000
ai_pc_402f:
    ai_ret_00
ai_pc_4030:
    ai_call_ff $6AE1
ai_pc_4033:
    ai_rnd_var3_2c $000F
ai_pc_4035:
    ai_if_var3_nz_05_short $4035, $4047
ai_pc_4037:
    ai_move_toward_e4 $0000, $0000
ai_pc_403a:
    ai_hop_e0 $0001, $0000, $003C
ai_pc_403e:
    ai_hop_e0 $0002, $0000, $003C
ai_pc_4042:
    ai_call_ff $4077
ai_pc_4045:
    ai_jmp_01_short $4045, $4053
ai_pc_4047:
    ai_if_pos_same_9d_short $4047, $404F
ai_pc_4049:
    ai_pos_save_9f
ai_pc_404a:
    ai_move_toward_e4 $0002, $0000
ai_pc_404d:
    ai_jmp_01_short $404D, $4053
ai_pc_404f:
    ai_pos_save_9f
ai_pc_4050:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_4053:
    ai_if_tgt_not_within_64_56_short $4053, $4030
ai_pc_4055:
    ai_ret_00
ai_pc_4056:
    ai_if_obj_outside_5f_short $0080, $4056, $4076
ai_pc_4059:
    ai_rnd_var3_2c $0001
ai_pc_405b:
    ai_if_var3_nz_05_short $405B, $406E
ai_pc_405d:
    ai_rnd_var3_2c $000F
ai_pc_405f:
    ai_if_var3_nz_05_short $405F, $4064
ai_pc_4061:
    ai_tgt2_self_c4
ai_pc_4062:
    ai_jmp_01_short $4062, $4065
ai_pc_4064:
    ai_tgt2_cur_c1
ai_pc_4065:
    ai_cast_e9 $0003, $0001
ai_pc_4068:
    ai_tgt2_none_c0
ai_pc_4069:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_406c:
    ai_jmp_01_short $406C, $4076
ai_pc_406e:
    ai_tgt2_cur_c1
ai_pc_406f:
    ai_cast_e9 $0003, $0000
ai_pc_4072:
    ai_tgt2_none_c0
ai_pc_4073:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_4076:
    ai_ret_00
ai_pc_4077:
    ai_if_obj_outside_5f_short $0080, $4077, $408C
ai_pc_407a:
    ai_rnd_var3_2c $000F
ai_pc_407c:
    ai_if_var3_nz_05_short $407C, $408C
ai_pc_407e:
    ai_if_word_and_nz_ba_short $0081, $0010, $0004, $0000, $407E, $408C
ai_pc_4084:
    ai_tgt2_cur_c1
ai_pc_4085:
    ai_cast_e9 $0003, $0002
ai_pc_4088:
    ai_tgt2_none_c0
ai_pc_4089:
    ai_turn_facing_e3 $0000, $0078
ai_pc_408c:
    ai_ret_00
ai_pc_408d:
    ai_if_obj_outside_5f_short $0080, $408D, $4099
ai_pc_4090:
    ai_if_var1_lt_17_short $0001, $4090, $4099
ai_pc_4093:
    ai_if_crowd_gt_f5_short $0002, $4093, $4099
ai_pc_4096:
    ai_cmd43_ed $0028
ai_pc_4098:
    ai_dec_var1_1f
ai_pc_4099:
    ai_ret_00
ai_pc_409a:
    ai_if_tgt_not_within_32_4c_short $409A, $40B0
ai_pc_409c:
    ai_call_ff $6AE1
ai_pc_409f:
    ai_if_pos_same_9d_short $409F, $40A7
ai_pc_40a1:
    ai_pos_save_9f
ai_pc_40a2:
    ai_move_away_e6 $0004, $0000
ai_pc_40a5:
    ai_jmp_01_short $40A5, $40AB
ai_pc_40a7:
    ai_pos_save_9f
ai_pc_40a8:
    ai_move_away_alt_fe $0004, $0000
ai_pc_40ab:
    ai_call_ff $408D
ai_pc_40ae:
    ai_jmp_01_short $40AE, $409A
ai_pc_40b0:
    ai_ret_00
ai_pc_40b1:
    ai_if_tgt_not_within_48_51_short $40B1, $40C7
ai_pc_40b3:
    ai_call_ff $6AE1
ai_pc_40b6:
    ai_if_pos_same_9d_short $40B6, $40BE
ai_pc_40b8:
    ai_pos_save_9f
ai_pc_40b9:
    ai_move_away_e6 $0002, $0000
ai_pc_40bc:
    ai_jmp_01_short $40BC, $40C2
ai_pc_40be:
    ai_pos_save_9f
ai_pc_40bf:
    ai_move_away_alt_fe $0002, $0000
ai_pc_40c2:
    ai_call_ff $408D
ai_pc_40c5:
    ai_jmp_01_short $40C5, $40B1
ai_pc_40c7:
    ai_ret_00
ai_pc_40c8:
    ai_rnd_var3_2c $0004
ai_pc_40ca:
    ai_if_var3_nz_05_short $40CA, $40D2
ai_pc_40cc:
    ai_hop_e0 $0008, $0001, $0000
ai_pc_40d0:
    ai_jmp_01_short $40D0, $40F0
ai_pc_40d2:
    ai_if_var3_ne_0d_short $0001, $40D2, $40DB
ai_pc_40d5:
    ai_hop_e0 $0004, $0001, $0000
ai_pc_40d9:
    ai_jmp_01_short $40D9, $40F0
ai_pc_40db:
    ai_if_var3_ne_0d_short $0002, $40DB, $40E4
ai_pc_40de:
    ai_hop_e0 $0001, $0001, $0000
ai_pc_40e2:
    ai_jmp_01_short $40E2, $40F0
ai_pc_40e4:
    ai_if_var3_ne_0d_short $0003, $40E4, $40ED
ai_pc_40e7:
    ai_hop_e0 $0002, $0001, $0000
ai_pc_40eb:
    ai_jmp_01_short $40EB, $40F0
ai_pc_40ed:
    ai_turn_facing_e3 $0000, $0000
ai_pc_40f0:
    ai_ret_00
ai_pc_40f1:
    ai_call_ff $4120
ai_pc_40f4:
    ai_rnd_var3_2c $000F
ai_pc_40f6:
    ai_if_var3_nz_05_short $40F6, $40FD
ai_pc_40f8:
    ai_call_ff $6AB5
ai_pc_40fb:
    ai_jmp_01_short $40FB, $4118
ai_pc_40fd:
    ai_call_ff $6AE1
ai_pc_4100:
    ai_if_tgt_not_within_32_4c_short $4100, $4107
ai_pc_4102:
    ai_call_ff $4123
ai_pc_4105:
    ai_jmp_01_short $4105, $4118
ai_pc_4107:
    ai_if_tgt_not_within_48_51_short $4107, $410E
ai_pc_4109:
    ai_call_ff $4142
ai_pc_410c:
    ai_jmp_01_short $410C, $4118
ai_pc_410e:
    ai_if_tgt_not_within_64_56_short $410E, $4115
ai_pc_4110:
    ai_call_ff $416D
ai_pc_4113:
    ai_jmp_01_short $4113, $4118
ai_pc_4115:
    ai_call_ff $322B
ai_pc_4118:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $4118, $40F4
ai_pc_411d:
    ai_jmp_01_short $411D, $40F4
