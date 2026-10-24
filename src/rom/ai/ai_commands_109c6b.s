.setcpu "65816"
.segment "CODE"
.org $9C6B
.include "ai_command_macros.inc"
ai_pc_4d56:
    ai_pose_e2 $0009
ai_pc_4d58:
    ai_set_var2_27 $0004
ai_pc_4d5a:
    ai_pose_e2 $0009
ai_pc_4d5c:
    ai_pose_e2 $0009
ai_pc_4d5e:
    ai_dec_var2_20
ai_pc_4d5f:
    ai_if_var2_nz_04_short $4D5F, $4D5A
ai_pc_4d61:
    ai_pose_e2 $0000
ai_pc_4d63:
    ai_ret_00
ai_pc_4d64:
    ai_move_toward_e4 $0000, $0000
ai_pc_4d67:
    ai_rnd_var3_2c $0001
ai_pc_4d69:
    ai_if_var3_nz_05_short $4D69, $4D79
ai_pc_4d6b:
    ai_rnd_var3_2c $0001
ai_pc_4d6d:
    ai_if_var3_nz_05_short $4D6D, $4D74
ai_pc_4d6f:
    ai_call_ff $4D9A
ai_pc_4d72:
    ai_jmp_01_short $4D72, $4D77
ai_pc_4d74:
    ai_move_toward_e4 $0000, $0000
ai_pc_4d77:
    ai_jmp_01_short $4D77, $4D7C
ai_pc_4d79:
    ai_move_toward_e4 $0000, $0000
ai_pc_4d7c:
    ai_ret_00
ai_pc_4d7d:
    ai_rnd_var3_2c $0002
ai_pc_4d7f:
    ai_set_var2_27 $0004
ai_pc_4d81:
    ai_call_ff $6AE1
ai_pc_4d84:
    ai_if_var3_gt_15_short $0009, $4D84, $4D8C
ai_pc_4d87:
    ai_call_ff $4E02
ai_pc_4d8a:
    ai_jmp_01_short $4D8A, $4D97
ai_pc_4d8c:
    ai_if_var3_gt_15_short $000C, $4D8C, $4D94
ai_pc_4d8f:
    ai_call_ff $4E12
ai_pc_4d92:
    ai_jmp_01_short $4D92, $4D97
ai_pc_4d94:
    ai_call_ff $4E22
ai_pc_4d97:
    ai_if_tgt_not_within_64_56_short $4D97, $4D7F
ai_pc_4d99:
    ai_ret_00
ai_pc_4d9a:
    ai_set_var1_26 $0000
ai_pc_4d9c:
    ai_set_var2_27 $000F
ai_pc_4d9e:
    ai_call_ff $4E22
ai_pc_4da1:
    ai_if_var2_nz_04_short $4DA1, $4DA8
ai_pc_4da3:
    ai_set_var1_26 $0001
ai_pc_4da5:
    ai_jmp_01_long $4DA5, $4DAA
ai_pc_4da8:
    ai_if_tgt_not_within_32_4c_short $4DA8, $4D9A
ai_pc_4daa:
    ai_if_var1_nz_03_short $4DAA, $4DAF
ai_pc_4dac:
    ai_call_ff $4DB0
ai_pc_4daf:
    ai_ret_00
ai_pc_4db0:
    ai_if_obj_outside_5f_long $0080, $4DB0, $4E01
ai_pc_4db4:
    ai_if_crowd_gt_f5_short $0001, $4DB4, $4DCE
ai_pc_4db7:
    ai_hop_e0 $0002, $0000, $001E
ai_pc_4dbb:
    ai_hop_e0 $0002, $0000, $001E
ai_pc_4dbf:
    ai_pose_e2 $0006
ai_pc_4dc1:
    ai_pose_e2 $0006
ai_pc_4dc3:
    ai_pose_e2 $0006
ai_pc_4dc5:
    ai_cmd43_ed $004F
ai_pc_4dc7:
    ai_cmd43_ed $004F
ai_pc_4dc9:
    ai_cmd81_ef $0005, $00FC
ai_pc_4dcc:
    ai_jmp_01_short $4DCC, $4E01
ai_pc_4dce:
    ai_if_crowd_gt_f5_short $0002, $4DCE, $4DFE
ai_pc_4dd1:
    ai_rnd_var3_2c $000D
ai_pc_4dd3:
    ai_turn_facing_e3 $0000, $0005
ai_pc_4dd6:
    ai_pose_e2 $0006
ai_pc_4dd8:
    ai_cmd43_ed $004F
ai_pc_4dda:
    ai_if_var3_nz_05_short $4DDA, $4DE1
ai_pc_4ddc:
    ai_cmd81_ef $0005, $002D
ai_pc_4ddf:
    ai_jmp_01_short $4DDF, $4DFC
ai_pc_4de1:
    ai_if_var3_ne_0d_short $0001, $4DE1, $4DE9
ai_pc_4de4:
    ai_cmd81_ef $0005, $0000
ai_pc_4de7:
    ai_jmp_01_short $4DE7, $4DFC
ai_pc_4de9:
    ai_if_var3_gt_15_short $0005, $4DE9, $4DF1
ai_pc_4dec:
    ai_cmd81_ef $0005, $0040
ai_pc_4def:
    ai_jmp_01_short $4DEF, $4DFC
ai_pc_4df1:
    ai_if_var3_gt_15_short $0009, $4DF1, $4DF9
ai_pc_4df4:
    ai_cmd81_ef $0005, $0041
ai_pc_4df7:
    ai_jmp_01_short $4DF7, $4DFC
ai_pc_4df9:
    ai_cmd81_ef $0005, $0035
ai_pc_4dfc:
    ai_jmp_01_short $4DFC, $4E01
ai_pc_4dfe:
    ai_move_toward_e4 $0000, $0005
ai_pc_4e01:
    ai_ret_00
ai_pc_4e02:
    ai_if_pos_same_9d_short $4E02, $4E0A
ai_pc_4e04:
    ai_pos_save_9f
ai_pc_4e05:
    ai_move_toward_e4 $0004, $000A
ai_pc_4e08:
    ai_jmp_01_short $4E08, $4E0E
ai_pc_4e0a:
    ai_pos_save_9f
ai_pc_4e0b:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_4e0e:
    ai_dec_var2_20
ai_pc_4e0f:
    ai_if_var2_nz_04_short $4E0F, $4E02
ai_pc_4e11:
    ai_ret_00
ai_pc_4e12:
    ai_if_pos_same_9d_short $4E12, $4E1A
ai_pc_4e14:
    ai_pos_save_9f
ai_pc_4e15:
    ai_move_toward_e4 $0001, $000A
ai_pc_4e18:
    ai_jmp_01_short $4E18, $4E1E
ai_pc_4e1a:
    ai_pos_save_9f
ai_pc_4e1b:
    ai_move_toward_alt_fd $0001, $000A
ai_pc_4e1e:
    ai_dec_var2_20
ai_pc_4e1f:
    ai_if_var2_nz_04_short $4E1F, $4E12
ai_pc_4e21:
    ai_ret_00
ai_pc_4e22:
    ai_if_pos_same_9d_short $4E22, $4E2A
ai_pc_4e24:
    ai_pos_save_9f
ai_pc_4e25:
    ai_move_toward_e4 $0002, $000A
ai_pc_4e28:
    ai_jmp_01_short $4E28, $4E2E
ai_pc_4e2a:
    ai_pos_save_9f
ai_pc_4e2b:
    ai_move_toward_alt_fd $0002, $000A
ai_pc_4e2e:
    ai_dec_var2_20
ai_pc_4e2f:
    ai_if_var2_nz_04_short $4E2F, $4E22
ai_pc_4e31:
    ai_ret_00
ai_pc_4e32:
    ai_set_var2_27 $0004
ai_pc_4e34:
    ai_if_tgt_not_within_48_51_short $4E34, $4E48
ai_pc_4e36:
    ai_call_ff $6AE1
ai_pc_4e39:
    ai_if_pos_same_9d_short $4E39, $4E41
ai_pc_4e3b:
    ai_pos_save_9f
ai_pc_4e3c:
    ai_move_away_e6 $0004, $000A
ai_pc_4e3f:
    ai_jmp_01_short $4E3F, $4E45
ai_pc_4e41:
    ai_pos_save_9f
ai_pc_4e42:
    ai_move_away_alt_fe $0004, $000A
ai_pc_4e45:
    ai_dec_var2_20
ai_pc_4e46:
    ai_jmp_01_short $4E46, $4E34
ai_pc_4e48:
    ai_ret_00
ai_pc_4e49:
    ai_call_ff $4E74
ai_pc_4e4c:
    ai_rnd_var3_2c $000F
ai_pc_4e4e:
    ai_if_var3_nz_05_short $4E4E, $4E55
ai_pc_4e50:
    ai_call_ff $6653
ai_pc_4e53:
    ai_jmp_01_short $4E53, $4E6C
ai_pc_4e55:
    ai_call_ff $6AE1
ai_pc_4e58:
    ai_call_ff $4F33
ai_pc_4e5b:
    ai_if_tgt_not_within_48_51_short $4E5B, $4E62
ai_pc_4e5d:
    ai_call_ff $4E7E
ai_pc_4e60:
    ai_jmp_01_short $4E60, $4E6C
ai_pc_4e62:
    ai_if_tgt_not_within_64_56_short $4E62, $4E69
ai_pc_4e64:
    ai_call_ff $4E95
ai_pc_4e67:
    ai_jmp_01_short $4E67, $4E6C
ai_pc_4e69:
    ai_call_ff $4EC7
ai_pc_4e6c:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $4E6C, $4E4C
ai_pc_4e71:
    ai_jmp_01_short $4E71, $4E4C
