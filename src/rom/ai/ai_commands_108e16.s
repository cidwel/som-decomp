.setcpu "65816"
.segment "CODE"
.org $8E16
.include "ai_command_macros.inc"
ai_pc_3f01:
    ai_pose_e2 $0000
ai_pc_3f03:
    ai_rnd_var3_2c $0001
ai_pc_3f05:
    ai_if_var3_nz_05_short $3F05, $3F09
ai_pc_3f07:
    ai_pose_e2 $0005
ai_pc_3f09:
    ai_set_var1_26 $0003
ai_pc_3f0b:
    ai_ret_00
ai_pc_3f0c:
    ai_move_toward_e4 $0000, $0000
ai_pc_3f0f:
    ai_set_var3_28 $0001
ai_pc_3f11:
    ai_if_field_gt_30_short $0080, $006D, $0000, $3F11, $3F30
ai_pc_3f16:
    ai_rnd_var3_2c $0001
ai_pc_3f18:
    ai_if_var3_nz_05_short $3F18, $3F26
ai_pc_3f1a:
    ai_move_toward_e4 $0000, $0000
ai_pc_3f1d:
    ai_tgt2_cur_c1
ai_pc_3f1e:
    ai_cast_e9 $0004, $0008
ai_pc_3f21:
    ai_tgt2_none_c0
ai_pc_3f22:
    ai_set_var3_28 $0000
ai_pc_3f24:
    ai_jmp_01_short $3F24, $3F30
ai_pc_3f26:
    ai_move_toward_e4 $0000, $0000
ai_pc_3f29:
    ai_tgt2_cur_c1
ai_pc_3f2a:
    ai_cast_e9 $0004, $0007
ai_pc_3f2d:
    ai_tgt2_none_c0
ai_pc_3f2e:
    ai_set_var3_28 $0000
ai_pc_3f30:
    ai_call_ff $223C
ai_pc_3f33:
    ai_if_var3_nz_05_short $3F33, $3F37
ai_pc_3f35:
    ai_pose_e2 $0005
ai_pc_3f37:
    ai_ret_00
ai_pc_3f38:
    ai_move_toward_e4 $0000, $0000
ai_pc_3f3b:
    ai_if_field_gt_30_short $0080, $006D, $0000, $3F3B, $3F46
ai_pc_3f40:
    ai_move_toward_e4 $0000, $0000
ai_pc_3f43:
    ai_call_ff $6B23
ai_pc_3f46:
    ai_call_ff $223C
ai_pc_3f49:
    ai_ret_00
ai_pc_3f4a:
    ai_move_toward_e4 $0000, $0000
ai_pc_3f4d:
    ai_if_field_gt_30_short $0080, $006D, $0000, $3F4D, $3F57
ai_pc_3f52:
    ai_call_ff $221C
ai_pc_3f55:
    ai_jmp_01_short $3F55, $3F72
ai_pc_3f57:
    ai_move_toward_e4 $0000, $0000
ai_pc_3f5a:
    ai_if_obj_outside_5f_short $0080, $3F5A, $3F6F
ai_pc_3f5d:
    ai_rnd_var3_2c $000F
ai_pc_3f5f:
    ai_if_var3_nz_05_short $3F5F, $3F6A
ai_pc_3f61:
    ai_tgt2_cur_c1
ai_pc_3f62:
    ai_cast_e9 $0004, $0006
ai_pc_3f65:
    ai_tgt2_none_c0
ai_pc_3f66:
    ai_pose_e2 $0005
ai_pc_3f68:
    ai_jmp_01_short $3F68, $3F6D
ai_pc_3f6a:
    ai_move_toward_e4 $0000, $0000
ai_pc_3f6d:
    ai_jmp_01_short $3F6D, $3F72
ai_pc_3f6f:
    ai_move_toward_e4 $0000, $0000
ai_pc_3f72:
    ai_ret_00
ai_pc_3f73:
    ai_if_obj_outside_5f_short $0080, $3F73, $3F81
ai_pc_3f76:
    ai_if_var1_lt_17_short $0001, $3F76, $3F81
ai_pc_3f79:
    ai_if_crowd_gt_f5_short $0002, $3F79, $3F81
ai_pc_3f7c:
    ai_pose_e2 $0000
ai_pc_3f7e:
    ai_cmd43_ed $0044
ai_pc_3f80:
    ai_dec_var1_1f
ai_pc_3f81:
    ai_ret_00
ai_pc_3f82:
    ai_call_ff $3FB8
ai_pc_3f85:
    ai_rnd_var3_2c $0007
ai_pc_3f87:
    ai_if_var3_nz_05_short $3F87, $3F8E
ai_pc_3f89:
    ai_call_ff $40C8
ai_pc_3f8c:
    ai_jmp_01_short $3F8C, $3FB0
ai_pc_3f8e:
    ai_call_ff $6AE1
ai_pc_3f91:
    ai_if_tgt_not_within_16_34_short $3F91, $3F98
ai_pc_3f93:
    ai_call_ff $3FBD
ai_pc_3f96:
    ai_jmp_01_short $3F96, $3FB0
ai_pc_3f98:
    ai_if_tgt_not_within_32_4c_short $3F98, $3F9F
ai_pc_3f9a:
    ai_call_ff $3FE3
ai_pc_3f9d:
    ai_jmp_01_short $3F9D, $3FB0
ai_pc_3f9f:
    ai_if_tgt_not_within_48_51_short $3F9F, $3FA6
ai_pc_3fa1:
    ai_call_ff $3FF5
ai_pc_3fa4:
    ai_jmp_01_short $3FA4, $3FB0
ai_pc_3fa6:
    ai_if_tgt_not_within_64_56_short $3FA6, $3FAD
ai_pc_3fa8:
    ai_call_ff $400F
ai_pc_3fab:
    ai_jmp_01_short $3FAB, $3FB0
ai_pc_3fad:
    ai_call_ff $4030
ai_pc_3fb0:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $3FB0, $3F85
ai_pc_3fb5:
    ai_jmp_01_short $3FB5, $3F85
