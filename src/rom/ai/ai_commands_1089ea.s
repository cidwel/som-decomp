.setcpu "65816"
.segment "CODE"
.org $89EA
.include "ai_command_macros.inc"
ai_pc_3ad5:
    ai_pose_e2 $0000
ai_pc_3ad7:
    ai_set_var1_26 $000C
ai_pc_3ad9:
    ai_ret_00
ai_pc_3ada:
    ai_move_toward_e4 $0000, $0005
ai_pc_3add:
    ai_if_word_gt_bd_short $0080, $003D, $0000, $0000, $3ADD, $3AEB
ai_pc_3ae3:
    ai_tgt2_self_c4
ai_pc_3ae4:
    ai_cast_e9 $0001, $0029
ai_pc_3ae7:
    ai_tgt2_none_c0
ai_pc_3ae8:
    ai_move_toward_e4 $0000, $003C
ai_pc_3aeb:
    ai_call_ff $3B5D
ai_pc_3aee:
    ai_ret_00
ai_pc_3aef:
    ai_move_toward_e4 $0000, $0005
ai_pc_3af2:
    ai_rnd_var3_2c $0007
ai_pc_3af4:
    ai_if_var3_nz_05_short $3AF4, $3AFB
ai_pc_3af6:
    ai_call_ff $3AFF
ai_pc_3af9:
    ai_jmp_01_short $3AF9, $3AFE
ai_pc_3afb:
    ai_move_toward_e4 $0000, $0005
ai_pc_3afe:
    ai_ret_00
ai_pc_3aff:
    ai_rnd_var3_2c $000F
ai_pc_3b01:
    ai_if_no_ally_64_54_short $3B01, $3B28
ai_pc_3b03:
    ai_tgt2_ally_d8
ai_pc_3b04:
    ai_if_field_gt_30_short $0082, $0038, $0000, $3B04, $3B28
ai_pc_3b09:
    ai_if_word_gt_bd_short $0082, $003D, $0000, $0000, $3B09, $3B14
ai_pc_3b0f:
    ai_call_ff $1E4F
ai_pc_3b12:
    ai_jmp_01_short $3B12, $3B28
ai_pc_3b14:
    ai_if_word_and_z_bb_short $0082, $0010, $00FC, $007F, $3B14, $3B1F
ai_pc_3b1a:
    ai_call_ff $1E81
ai_pc_3b1d:
    ai_jmp_01_short $3B1D, $3B28
ai_pc_3b1f:
    ai_if_word_gt_bd_short $0082, $0002, $00B2, $0002, $3B1F, $3B28
ai_pc_3b25:
    ai_call_ff $1E68
ai_pc_3b28:
    ai_ret_00
ai_pc_3b29:
    ai_if_obj_outside_5f_short $0080, $3B29, $3B4A
ai_pc_3b2c:
    ai_if_var1_lt_17_short $0001, $3B2C, $3B4A
ai_pc_3b2f:
    ai_if_crowd_gt_f5_short $0002, $3B2F, $3B47
ai_pc_3b32:
    ai_pose_e2 $0003
ai_pc_3b34:
    ai_rnd_var3_2c $0007
ai_pc_3b36:
    ai_if_var3_nz_05_short $3B36, $3B42
ai_pc_3b38:
    ai_cmd43_ed $0000
ai_pc_3b3a:
    ai_cmd43_ed $0000
ai_pc_3b3c:
    ai_pose_e2 $0002
ai_pc_3b3e:
    ai_pose_e2 $0002
ai_pc_3b40:
    ai_jmp_01_short $3B40, $3B45
ai_pc_3b42:
    ai_cmd43_ed $003C
ai_pc_3b44:
    ai_dec_var1_1f
ai_pc_3b45:
    ai_jmp_01_short $3B45, $3B4A
ai_pc_3b47:
    ai_move_toward_e4 $0000, $0005
ai_pc_3b4a:
    ai_ret_00
ai_pc_3b4b:
    ai_call_ff $6AE1
ai_pc_3b4e:
    ai_if_pos_same_9d_short $3B4E, $3B56
ai_pc_3b50:
    ai_pos_save_9f
ai_pc_3b51:
    ai_move_toward_e4 $0001, $000A
ai_pc_3b54:
    ai_jmp_01_short $3B54, $3B5A
ai_pc_3b56:
    ai_pos_save_9f
ai_pc_3b57:
    ai_move_toward_alt_fd $0001, $000A
ai_pc_3b5a:
    ai_if_tgt_not_within_64_56_short $3B5A, $3B4B
ai_pc_3b5c:
    ai_ret_00
ai_pc_3b5d:
    ai_if_tgt_not_within_48_51_short $3B5D, $3B70
ai_pc_3b5f:
    ai_call_ff $6AE1
ai_pc_3b62:
    ai_if_pos_same_9d_short $3B62, $3B6A
ai_pc_3b64:
    ai_pos_save_9f
ai_pc_3b65:
    ai_move_away_e6 $0001, $000A
ai_pc_3b68:
    ai_jmp_01_short $3B68, $3B6E
ai_pc_3b6a:
    ai_pos_save_9f
ai_pc_3b6b:
    ai_move_away_alt_fe $0001, $000A
ai_pc_3b6e:
    ai_jmp_01_short $3B6E, $3B5D
ai_pc_3b70:
    ai_ret_00
ai_pc_3b71:
    ai_call_ff $3BA7
ai_pc_3b74:
    ai_rnd_var3_2c $000F
ai_pc_3b76:
    ai_if_var3_nz_05_short $3B76, $3B7D
ai_pc_3b78:
    ai_call_ff $66AB
ai_pc_3b7b:
    ai_jmp_01_short $3B7B, $3B9F
ai_pc_3b7d:
    ai_call_ff $6AE1
ai_pc_3b80:
    ai_if_tgt_not_within_16_34_short $3B80, $3B87
ai_pc_3b82:
    ai_call_ff $3BAA
ai_pc_3b85:
    ai_jmp_01_short $3B85, $3B9F
ai_pc_3b87:
    ai_if_tgt_not_within_32_4c_short $3B87, $3B8E
ai_pc_3b89:
    ai_call_ff $3BBE
ai_pc_3b8c:
    ai_jmp_01_short $3B8C, $3B9F
ai_pc_3b8e:
    ai_if_tgt_not_within_48_51_short $3B8E, $3B95
ai_pc_3b90:
    ai_call_ff $3BC2
ai_pc_3b93:
    ai_jmp_01_short $3B93, $3B9F
ai_pc_3b95:
    ai_if_tgt_not_within_64_56_short $3B95, $3B9C
ai_pc_3b97:
    ai_call_ff $3BC6
ai_pc_3b9a:
    ai_jmp_01_short $3B9A, $3B9F
ai_pc_3b9c:
    ai_call_ff $3BF4
ai_pc_3b9f:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $3B9F, $3B74
ai_pc_3ba4:
    ai_jmp_01_short $3BA4, $3B74
