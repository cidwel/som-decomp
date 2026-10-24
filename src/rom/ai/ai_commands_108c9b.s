.setcpu "65816"
.segment "CODE"
.org $8C9B
.include "ai_command_macros.inc"
ai_pc_3d86:
    ai_pose_e2 $0007
ai_pc_3d88:
    ai_call_ff $6AE1
ai_pc_3d8b:
    ai_pose_e2 $0007
ai_pc_3d8d:
    ai_if_word_gt_bd_short $0080, $0002, $002F, $0002, $3D8D, $3D96
ai_pc_3d93:
    ai_jmp_01_long $3D93, $3D98
ai_pc_3d96:
    ai_if_tgt_not_within_32_4c_short $3D96, $3D88
ai_pc_3d98:
    ai_move_toward_e4 $000B, $0000
ai_pc_3d9b:
    ai_ret_00
ai_pc_3d9c:
    ai_move_toward_card_be $0000, $0000
ai_pc_3d9f:
    ai_if_field_gt_30_short $0080, $006D, $0000, $3D9F, $3DAA
ai_pc_3da4:
    ai_call_ff $3E32
ai_pc_3da7:
    ai_call_ff $2EF6
ai_pc_3daa:
    ai_call_ff $3E71
ai_pc_3dad:
    ai_call_ff $3E8D
ai_pc_3db0:
    ai_ret_00
ai_pc_3db1:
    ai_move_toward_card_be $0000, $0000
ai_pc_3db4:
    ai_if_field_gt_30_short $0080, $006D, $0000, $3DB4, $3DD7
ai_pc_3db9:
    ai_if_tgt_not_lane_h64_6f_short $3DB9, $3DC8
ai_pc_3dbb:
    ai_flash_fc
ai_pc_3dbc:
    ai_move_toward_card_be $0000, $0000
ai_pc_3dbf:
    ai_call_ff $6B23
ai_pc_3dc2:
    ai_flash_fc
ai_pc_3dc3:
    ai_move_toward_card_be $0000, $0000
ai_pc_3dc6:
    ai_jmp_01_short $3DC6, $3DD5
ai_pc_3dc8:
    ai_if_tgt_not_lane_v64_66_short $3DC8, $3DD2
ai_pc_3dca:
    ai_move_toward_card_be $0000, $0000
ai_pc_3dcd:
    ai_call_ff $6B23
ai_pc_3dd0:
    ai_jmp_01_short $3DD0, $3DD5
ai_pc_3dd2:
    ai_call_ff $6653
ai_pc_3dd5:
    ai_jmp_01_short $3DD5, $3DDA
ai_pc_3dd7:
    ai_move_toward_card_be $0000, $0000
ai_pc_3dda:
    ai_ret_00
ai_pc_3ddb:
    ai_move_toward_card_be $0000, $0000
ai_pc_3dde:
    ai_if_field_gt_30_short $0080, $006D, $0000, $3DDE, $3E00
ai_pc_3de3:
    ai_if_tgt_not_lane_h64_6f_short $3DE3, $3DF2
ai_pc_3de5:
    ai_flash_fc
ai_pc_3de6:
    ai_move_toward_card_be $0000, $0000
ai_pc_3de9:
    ai_call_ff $6B23
ai_pc_3dec:
    ai_flash_fc
ai_pc_3ded:
    ai_move_toward_card_be $0000, $0000
ai_pc_3df0:
    ai_jmp_01_short $3DF0, $3DFE
ai_pc_3df2:
    ai_if_tgt_not_lane_v64_66_short $3DF2, $3DFB
ai_pc_3df4:
    ai_move_toward_card_be $0000, $0000
ai_pc_3df7:
    ai_pose_e2 $0003
ai_pc_3df9:
    ai_jmp_01_short $3DF9, $3DFE
ai_pc_3dfb:
    ai_call_ff $3E52
ai_pc_3dfe:
    ai_jmp_01_short $3DFE, $3E03
ai_pc_3e00:
    ai_move_toward_card_be $0000, $0000
ai_pc_3e03:
    ai_ret_00
ai_pc_3e04:
    ai_call_ff $6AE1
ai_pc_3e07:
    ai_if_tgt_not_lane_h_73_short $3E07, $3E10
ai_pc_3e09:
    ai_move_toward_card_be $0000, $0000
ai_pc_3e0c:
    ai_pose_e2 $0002
ai_pc_3e0e:
    ai_jmp_01_short $3E0E, $3E2F
ai_pc_3e10:
    ai_if_tgt_not_lane_v_6a_short $3E10, $3E19
ai_pc_3e12:
    ai_move_toward_card_be $0000, $0000
ai_pc_3e15:
    ai_pose_e2 $0003
ai_pc_3e17:
    ai_jmp_01_short $3E17, $3E2F
ai_pc_3e19:
    ai_set_var2_27 $0004
ai_pc_3e1b:
    ai_if_pos_same_9d_short $3E1B, $3E23
ai_pc_3e1d:
    ai_pos_save_9f
ai_pc_3e1e:
    ai_move_toward_card_be $0004, $000A
ai_pc_3e21:
    ai_jmp_01_short $3E21, $3E27
ai_pc_3e23:
    ai_pos_save_9f
ai_pc_3e24:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_3e27:
    ai_if_tgt_not_within_64_56_short $3E27, $3E2C
ai_pc_3e29:
    ai_jmp_01_long $3E29, $3E2F
ai_pc_3e2c:
    ai_dec_var2_20
ai_pc_3e2d:
    ai_if_var2_nz_04_short $3E2D, $3E1B
ai_pc_3e2f:
    ai_if_tgt_not_within_64_56_short $3E2F, $3E04
ai_pc_3e31:
    ai_ret_00
ai_pc_3e32:
    ai_rnd_var3_2c $0007
ai_pc_3e34:
    ai_if_var3_nz_05_short $3E34, $3E51
ai_pc_3e36:
    ai_if_field_gt_30_short $0080, $001D, $0000, $3E36, $3E51
ai_pc_3e3b:
    ai_rnd_var3_2c $0001
ai_pc_3e3d:
    ai_if_var3_nz_05_short $3E3D, $3E49
ai_pc_3e3f:
    ai_tgt2_self_c4
ai_pc_3e40:
    ai_cast_e9 $0005, $001B
ai_pc_3e43:
    ai_tgt2_none_c0
ai_pc_3e44:
    ai_turn_facing_e3 $0000, $0078
ai_pc_3e47:
    ai_jmp_01_short $3E47, $3E51
ai_pc_3e49:
    ai_tgt2_self_c4
ai_pc_3e4a:
    ai_cast_e9 $0005, $0027
ai_pc_3e4d:
    ai_tgt2_none_c0
ai_pc_3e4e:
    ai_turn_facing_e3 $0000, $0078
ai_pc_3e51:
    ai_ret_00
ai_pc_3e52:
    ai_call_ff $6AE1
ai_pc_3e55:
    ai_if_pos_same_9d_short $3E55, $3E5D
ai_pc_3e57:
    ai_pos_save_9f
ai_pc_3e58:
    ai_move_toward_card_be $0004, $000A
ai_pc_3e5b:
    ai_jmp_01_short $3E5B, $3E61
ai_pc_3e5d:
    ai_pos_save_9f
ai_pc_3e5e:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_3e61:
    ai_if_tgt_not_lane_h64_6f_short $3E61, $3E6E
ai_pc_3e63:
    ai_flash_fc
ai_pc_3e64:
    ai_move_toward_card_be $0000, $0000
ai_pc_3e67:
    ai_call_ff $6B23
ai_pc_3e6a:
    ai_flash_fc
ai_pc_3e6b:
    ai_move_toward_card_be $0000, $0000
ai_pc_3e6e:
    ai_if_tgt_not_within_48_51_short $3E6E, $3E52
ai_pc_3e70:
    ai_ret_00
ai_pc_3e71:
    ai_set_var2_27 $0004
ai_pc_3e73:
    ai_if_tgt_not_within_32_4c_short $3E73, $3E8C
ai_pc_3e75:
    ai_call_ff $6AE1
ai_pc_3e78:
    ai_if_pos_same_9d_short $3E78, $3E80
ai_pc_3e7a:
    ai_pos_save_9f
ai_pc_3e7b:
    ai_move_toward_card_be $0005, $000A
ai_pc_3e7e:
    ai_jmp_01_short $3E7E, $3E84
ai_pc_3e80:
    ai_pos_save_9f
ai_pc_3e81:
    ai_move_toward_alt_fd $0005, $000A
ai_pc_3e84:
    ai_dec_var2_20
ai_pc_3e85:
    ai_if_var2_nz_04_short $3E85, $3E8A
ai_pc_3e87:
    ai_jmp_01_long $3E87, $3E8C
ai_pc_3e8a:
    ai_jmp_01_short $3E8A, $3E73
ai_pc_3e8c:
    ai_ret_00
ai_pc_3e8d:
    ai_if_tgt_not_lane_h64_6f_short $3E8D, $3E9B
ai_pc_3e8f:
    ai_flash_fc
ai_pc_3e90:
    ai_move_away_card_bf $0000, $0000
ai_pc_3e93:
    ai_pose_e2 $0002
ai_pc_3e95:
    ai_flash_fc
ai_pc_3e96:
    ai_move_away_card_bf $0000, $0000
ai_pc_3e99:
    ai_jmp_01_short $3E99, $3ECA
ai_pc_3e9b:
    ai_if_tgt_not_lane_v64_66_short $3E9B, $3EA9
ai_pc_3e9d:
    ai_flash_fc
ai_pc_3e9e:
    ai_move_away_card_bf $0000, $0000
ai_pc_3ea1:
    ai_pose_e2 $0003
ai_pc_3ea3:
    ai_flash_fc
ai_pc_3ea4:
    ai_move_away_card_bf $0000, $0000
ai_pc_3ea7:
    ai_jmp_01_short $3EA7, $3ECA
ai_pc_3ea9:
    ai_if_tgt_not_within_48_51_short $3EA9, $3EBC
ai_pc_3eab:
    ai_call_ff $6AE1
ai_pc_3eae:
    ai_if_pos_same_9d_short $3EAE, $3EB6
ai_pc_3eb0:
    ai_pos_save_9f
ai_pc_3eb1:
    ai_move_away_card_bf $0002, $0005
ai_pc_3eb4:
    ai_jmp_01_short $3EB4, $3EBA
ai_pc_3eb6:
    ai_pos_save_9f
ai_pc_3eb7:
    ai_move_away_card_bf $0002, $0005
ai_pc_3eba:
    ai_jmp_01_short $3EBA, $3EA9
ai_pc_3ebc:
    ai_rnd_var3_2c $0007
ai_pc_3ebe:
    ai_if_var3_nz_05_short $3EBE, $3ECA
ai_pc_3ec0:
    ai_move_toward_e4 $0007, $0000
ai_pc_3ec3:
    ai_pose_e2 $0004
ai_pc_3ec5:
    ai_pose_e2 $0004
ai_pc_3ec7:
    ai_move_toward_e4 $000B, $0000
ai_pc_3eca:
    ai_ret_00
ai_pc_3ecb:
    ai_call_ff $3F01
ai_pc_3ece:
    ai_rnd_var3_2c $000F
ai_pc_3ed0:
    ai_if_var3_nz_05_short $3ED0, $3EDB
ai_pc_3ed2:
    ai_call_ff $672F
ai_pc_3ed5:
    ai_hop_e0 $0008, $0004, $0000
ai_pc_3ed9:
    ai_jmp_01_short $3ED9, $3EF9
ai_pc_3edb:
    ai_call_ff $6AE1
ai_pc_3ede:
    ai_call_ff $3F73
ai_pc_3ee1:
    ai_if_tgt_not_within_16_34_short $3EE1, $3EE8
ai_pc_3ee3:
    ai_call_ff $3F0C
ai_pc_3ee6:
    ai_jmp_01_short $3EE6, $3EF9
ai_pc_3ee8:
    ai_if_tgt_not_within_48_51_short $3EE8, $3EEF
ai_pc_3eea:
    ai_call_ff $3F38
ai_pc_3eed:
    ai_jmp_01_short $3EED, $3EF9
ai_pc_3eef:
    ai_if_tgt_not_within_64_56_short $3EEF, $3EF6
ai_pc_3ef1:
    ai_call_ff $3F4A
ai_pc_3ef4:
    ai_jmp_01_short $3EF4, $3EF9
ai_pc_3ef6:
    ai_call_ff $221C
ai_pc_3ef9:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $3EF9, $3ECE
ai_pc_3efe:
    ai_jmp_01_short $3EFE, $3ECE
