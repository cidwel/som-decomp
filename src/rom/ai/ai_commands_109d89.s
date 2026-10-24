.setcpu "65816"
.segment "CODE"
.org $9D89
.include "ai_command_macros.inc"
ai_pc_4e74:
    ai_pose_e2 $0006
ai_pc_4e76:
    ai_rnd_var3_2c $0001
ai_pc_4e78:
    ai_if_var3_nz_05_short $4E78, $4E7D
ai_pc_4e7a:
    ai_call_ff $4F25
ai_pc_4e7d:
    ai_ret_00
ai_pc_4e7e:
    ai_move_toward_e4 $0000, $0005
ai_pc_4e81:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4E81, $4E8C
ai_pc_4e86:
    ai_move_toward_e4 $0003, $0005
ai_pc_4e89:
    ai_call_ff $6B23
ai_pc_4e8c:
    ai_if_tgt_not_within_16_34_short $4E8C, $4E91
ai_pc_4e8e:
    ai_move_toward_alt_fd $000E, $0000
ai_pc_4e91:
    ai_call_ff $4F6D
ai_pc_4e94:
    ai_ret_00
ai_pc_4e95:
    ai_move_toward_e4 $0000, $0005
ai_pc_4e98:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4E98, $4EBD
ai_pc_4e9d:
    ai_rnd_var3_2c $0001
ai_pc_4e9f:
    ai_if_var3_nz_05_short $4E9F, $4EA4
ai_pc_4ea1:
    ai_call_ff $4F25
ai_pc_4ea4:
    ai_move_toward_e4 $0000, $0005
ai_pc_4ea7:
    ai_rnd_var3_2c $0002
ai_pc_4ea9:
    ai_if_var3_nz_05_short $4EA9, $4EB0
ai_pc_4eab:
    ai_call_ff $4EF8
ai_pc_4eae:
    ai_jmp_01_short $4EAE, $4EBB
ai_pc_4eb0:
    ai_if_var3_ne_0d_short $0001, $4EB0, $4EB8
ai_pc_4eb3:
    ai_call_ff $4F42
ai_pc_4eb6:
    ai_jmp_01_short $4EB6, $4EBB
ai_pc_4eb8:
    ai_move_toward_e4 $0000, $0005
ai_pc_4ebb:
    ai_jmp_01_short $4EBB, $4EC6
ai_pc_4ebd:
    ai_move_toward_e4 $0004, $0000
ai_pc_4ec0:
    ai_move_toward_e4 $000E, $0000
ai_pc_4ec3:
    ai_move_toward_e4 $0004, $0000
ai_pc_4ec6:
    ai_ret_00
ai_pc_4ec7:
    ai_rnd_var3_2c $0007
ai_pc_4ec9:
    ai_if_var3_nz_05_short $4EC9, $4ED3
ai_pc_4ecb:
    ai_tgt2_self_c4
ai_pc_4ecc:
    ai_cast_e9 $0008, $001C
ai_pc_4ecf:
    ai_tgt2_none_c0
ai_pc_4ed0:
    ai_turn_facing_e3 $0000, $003C
ai_pc_4ed3:
    ai_call_ff $6AE1
ai_pc_4ed6:
    ai_if_pos_same_9d_short $4ED6, $4EDE
ai_pc_4ed8:
    ai_pos_save_9f
ai_pc_4ed9:
    ai_move_toward_e4 $0001, $0005
ai_pc_4edc:
    ai_jmp_01_short $4EDC, $4EE2
ai_pc_4ede:
    ai_pos_save_9f
ai_pc_4edf:
    ai_move_toward_alt_fd $0001, $0005
ai_pc_4ee2:
    ai_if_tgt_not_within_64_56_short $4EE2, $4ED3
ai_pc_4ee4:
    ai_rnd_var3_2c $0007
ai_pc_4ee6:
    ai_if_var3_nz_05_short $4EE6, $4EF7
ai_pc_4ee8:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4EE8, $4EF7
ai_pc_4eed:
    ai_move_toward_e4 $0000, $0000
ai_pc_4ef0:
    ai_call_ff $6B23
ai_pc_4ef3:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_4ef7:
    ai_ret_00
ai_pc_4ef8:
    ai_move_toward_e4 $0003, $0005
ai_pc_4efb:
    ai_call_ff $6B23
ai_pc_4efe:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_4f02:
    ai_move_toward_alt_fd $000E, $0000
ai_pc_4f05:
    ai_call_ff $6B23
ai_pc_4f08:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_4f0c:
    ai_move_toward_e4 $0003, $0005
ai_pc_4f0f:
    ai_pose_e2 $0002
ai_pc_4f11:
    ai_call_ff $6B23
ai_pc_4f14:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_4f18:
    ai_move_toward_e4 $0003, $0005
ai_pc_4f1b:
    ai_call_ff $6B23
ai_pc_4f1e:
    ai_move_toward_e4 $000E, $0000
ai_pc_4f21:
    ai_call_ff $4F6D
ai_pc_4f24:
    ai_ret_00
ai_pc_4f25:
    ai_if_field_gt_30_short $0080, $001D, $0000, $4F25, $4F32
ai_pc_4f2a:
    ai_tgt2_self_c4
ai_pc_4f2b:
    ai_cast_e9 $0008, $001B
ai_pc_4f2e:
    ai_tgt2_none_c0
ai_pc_4f2f:
    ai_turn_facing_e3 $0000, $003C
ai_pc_4f32:
    ai_ret_00
ai_pc_4f33:
    ai_if_word_gt_bd_short $0080, $0002, $00E8, $0003, $4F33, $4F41
ai_pc_4f39:
    ai_tgt2_self_c4
ai_pc_4f3a:
    ai_cast_e9 $0008, $000B
ai_pc_4f3d:
    ai_tgt2_none_c0
ai_pc_4f3e:
    ai_turn_facing_e3 $0000, $003C
ai_pc_4f41:
    ai_ret_00
ai_pc_4f42:
    ai_rnd_var3_2c $0001
ai_pc_4f44:
    ai_call_ff $6AE1
ai_pc_4f47:
    ai_if_pos_same_9d_short $4F47, $4F4F
ai_pc_4f49:
    ai_pos_save_9f
ai_pc_4f4a:
    ai_move_toward_e4 $0002, $0005
ai_pc_4f4d:
    ai_jmp_01_short $4F4D, $4F53
ai_pc_4f4f:
    ai_pos_save_9f
ai_pc_4f50:
    ai_move_toward_alt_fd $0002, $0005
ai_pc_4f53:
    ai_if_var3_nz_05_short $4F53, $4F5A
ai_pc_4f55:
    ai_if_tgt_not_within_48_51_short $4F55, $4F5A
ai_pc_4f57:
    ai_jmp_01_long $4F57, $4F5C
ai_pc_4f5a:
    ai_if_tgt_not_within_32_4c_short $4F5A, $4F44
ai_pc_4f5c:
    ai_move_toward_e4 $0003, $0005
ai_pc_4f5f:
    ai_call_ff $6B23
ai_pc_4f62:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_4f66:
    ai_move_toward_e4 $0003, $0005
ai_pc_4f69:
    ai_call_ff $6B23
ai_pc_4f6c:
    ai_ret_00
ai_pc_4f6d:
    ai_if_tgt_not_within_48_51_short $4F6D, $4F8D
ai_pc_4f6f:
    ai_call_ff $6AE1
ai_pc_4f72:
    ai_if_tgt_not_within_48_51_short $4F72, $4F7F
ai_pc_4f74:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4F74, $4F7F
ai_pc_4f79:
    ai_move_toward_e4 $0003, $0005
ai_pc_4f7c:
    ai_call_ff $6B23
ai_pc_4f7f:
    ai_if_pos_same_9d_short $4F7F, $4F87
ai_pc_4f81:
    ai_pos_save_9f
ai_pc_4f82:
    ai_move_toward_e4 $0005, $000A
ai_pc_4f85:
    ai_jmp_01_short $4F85, $4F8B
ai_pc_4f87:
    ai_pos_save_9f
ai_pc_4f88:
    ai_move_toward_alt_fd $0005, $000A
ai_pc_4f8b:
    ai_jmp_01_short $4F8B, $4F6D
ai_pc_4f8d:
    ai_ret_00
ai_pc_4f8e:
    ai_call_ff $4FC7
ai_pc_4f91:
    ai_rnd_var3_2c $000F
ai_pc_4f93:
    ai_if_var3_nz_05_short $4F93, $4F9A
ai_pc_4f95:
    ai_call_ff $683C
ai_pc_4f98:
    ai_jmp_01_short $4F98, $4FBF
ai_pc_4f9a:
    ai_call_ff $6AE1
ai_pc_4f9d:
    ai_call_ff $5098
ai_pc_4fa0:
    ai_if_tgt_not_within_16_34_short $4FA0, $4FA7
ai_pc_4fa2:
    ai_call_ff $4FDC
ai_pc_4fa5:
    ai_jmp_01_short $4FA5, $4FBF
ai_pc_4fa7:
    ai_if_tgt_not_within_32_4c_short $4FA7, $4FAE
ai_pc_4fa9:
    ai_call_ff $4FFF
ai_pc_4fac:
    ai_jmp_01_short $4FAC, $4FBF
ai_pc_4fae:
    ai_if_tgt_not_within_48_51_short $4FAE, $4FB5
ai_pc_4fb0:
    ai_call_ff $5018
ai_pc_4fb3:
    ai_jmp_01_short $4FB3, $4FBF
ai_pc_4fb5:
    ai_if_tgt_not_within_64_56_short $4FB5, $4FBC
ai_pc_4fb7:
    ai_call_ff $5034
ai_pc_4fba:
    ai_jmp_01_short $4FBA, $4FBF
ai_pc_4fbc:
    ai_call_ff $5105
ai_pc_4fbf:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $4FBF, $4F91
ai_pc_4fc4:
    ai_jmp_01_short $4FC4, $4F91
