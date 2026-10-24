.setcpu "65816"
.segment "CODE"
.org $8ABC
.include "ai_command_macros.inc"
ai_pc_3ba7:
    ai_pose_e2 $0000
ai_pc_3ba9:
    ai_ret_00
ai_pc_3baa:
    ai_move_toward_e4 $0000, $0000
ai_pc_3bad:
    ai_if_field_gt_30_short $0080, $006D, $0000, $3BAD, $3BBA
ai_pc_3bb2:
    ai_call_ff $3C6A
ai_pc_3bb5:
    ai_call_ff $3C1A
ai_pc_3bb8:
    ai_jmp_01_short $3BB8, $3BBD
ai_pc_3bba:
    ai_call_ff $3C6A
ai_pc_3bbd:
    ai_ret_00
ai_pc_3bbe:
    ai_call_ff $3C6A
ai_pc_3bc1:
    ai_ret_00
ai_pc_3bc2:
    ai_call_ff $3C49
ai_pc_3bc5:
    ai_ret_00
ai_pc_3bc6:
    ai_move_toward_e4 $0000, $0000
ai_pc_3bc9:
    ai_if_field_gt_30_short $0080, $006D, $0000, $3BC9, $3BF0
ai_pc_3bce:
    ai_rnd_var3_2c $000F
ai_pc_3bd0:
    ai_if_var3_nz_05_short $3BD0, $3BEB
ai_pc_3bd2:
    ai_if_tgt_not_lane_v64_66_short $3BD2, $3BDC
ai_pc_3bd4:
    ai_move_toward_card_be $0000, $0000
ai_pc_3bd7:
    ai_call_ff $6B23
ai_pc_3bda:
    ai_jmp_01_short $3BDA, $3BE9
ai_pc_3bdc:
    ai_if_tgt_not_lane_h64_6f_short $3BDC, $3BE6
ai_pc_3bde:
    ai_move_toward_card_be $0000, $0000
ai_pc_3be1:
    ai_call_ff $6B23
ai_pc_3be4:
    ai_jmp_01_short $3BE4, $3BE9
ai_pc_3be6:
    ai_call_ff $667F
ai_pc_3be9:
    ai_jmp_01_short $3BE9, $3BEE
ai_pc_3beb:
    ai_move_toward_e4 $0000, $0000
ai_pc_3bee:
    ai_jmp_01_short $3BEE, $3BF3
ai_pc_3bf0:
    ai_move_toward_e4 $0000, $0000
ai_pc_3bf3:
    ai_ret_00
ai_pc_3bf4:
    ai_set_var2_27 $0004
ai_pc_3bf6:
    ai_call_ff $6AE1
ai_pc_3bf9:
    ai_if_pos_same_9d_short $3BF9, $3C01
ai_pc_3bfb:
    ai_pos_save_9f
ai_pc_3bfc:
    ai_move_toward_e4 $0001, $0005
ai_pc_3bff:
    ai_jmp_01_short $3BFF, $3C05
ai_pc_3c01:
    ai_pos_save_9f
ai_pc_3c02:
    ai_move_toward_alt_fd $0001, $0005
ai_pc_3c05:
    ai_dec_var2_20
ai_pc_3c06:
    ai_if_var2_nz_04_short $3C06, $3C17
ai_pc_3c08:
    ai_rnd_var3_2c $0002
ai_pc_3c0a:
    ai_if_var3_nz_05_short $3C0A, $3C17
ai_pc_3c0c:
    ai_hop_e0 $0002, $0000, $000F
ai_pc_3c10:
    ai_hop_e0 $0001, $0000, $000F
ai_pc_3c14:
    ai_jmp_01_long $3C14, $3C19
ai_pc_3c17:
    ai_if_tgt_not_within_64_56_short $3C17, $3BF6
ai_pc_3c19:
    ai_ret_00
ai_pc_3c1a:
    ai_hop_e0 $0000, $0004, $000F
ai_pc_3c1e:
    ai_hop_e0 $0000, $0002, $000F
ai_pc_3c22:
    ai_hop_e0 $0000, $0001, $000F
ai_pc_3c26:
    ai_if_obj_outside_5f_short $0080, $3C26, $3C45
ai_pc_3c29:
    ai_tgt2_cur_c1
ai_pc_3c2a:
    ai_cast_e9 $0002, $000D
ai_pc_3c2d:
    ai_tgt2_none_c0
ai_pc_3c2e:
    ai_move_toward_e4 $0000, $0005
ai_pc_3c31:
    ai_set_var3_28 $000F
ai_pc_3c33:
    ai_pose_e2 $0005
ai_pc_3c35:
    ai_pose_e2 $0005
ai_pc_3c37:
    ai_pose_e2 $0005
ai_pc_3c39:
    ai_pose_e2 $0005
ai_pc_3c3b:
    ai_dec_var3_21
ai_pc_3c3c:
    ai_if_var3_nz_05_short $3C3C, $3C33
ai_pc_3c3e:
    ai_pose_e2 $0005
ai_pc_3c40:
    ai_move_toward_e4 $000E, $0000
ai_pc_3c43:
    ai_jmp_01_short $3C43, $3C48
ai_pc_3c45:
    ai_move_toward_e4 $0000, $0000
ai_pc_3c48:
    ai_ret_00
ai_pc_3c49:
    ai_if_tgt_not_within_48_51_short $3C49, $3C69
ai_pc_3c4b:
    ai_call_ff $6AE1
ai_pc_3c4e:
    ai_if_pos_same_9d_short $3C4E, $3C56
ai_pc_3c50:
    ai_pos_save_9f
ai_pc_3c51:
    ai_move_away_e6 $0001, $0005
ai_pc_3c54:
    ai_jmp_01_short $3C54, $3C5A
ai_pc_3c56:
    ai_pos_save_9f
ai_pc_3c57:
    ai_move_away_alt_fe $0001, $0005
ai_pc_3c5a:
    ai_if_tgt_not_within_16_34_short $3C5A, $3C67
ai_pc_3c5c:
    ai_if_field_gt_30_short $0080, $006D, $0000, $3C5C, $3C64
ai_pc_3c61:
    ai_call_ff $3C1A
ai_pc_3c64:
    ai_jmp_01_long $3C64, $3C69
ai_pc_3c67:
    ai_jmp_01_short $3C67, $3C49
ai_pc_3c69:
    ai_ret_00
ai_pc_3c6a:
    ai_if_tgt_not_within_48_51_short $3C6A, $3C8A
ai_pc_3c6c:
    ai_call_ff $6AE1
ai_pc_3c6f:
    ai_if_pos_same_9d_short $3C6F, $3C77
ai_pc_3c71:
    ai_pos_save_9f
ai_pc_3c72:
    ai_move_away_e6 $0002, $0005
ai_pc_3c75:
    ai_jmp_01_short $3C75, $3C7B
ai_pc_3c77:
    ai_pos_save_9f
ai_pc_3c78:
    ai_move_away_alt_fe $0002, $0005
ai_pc_3c7b:
    ai_if_tgt_not_within_16_34_short $3C7B, $3C88
ai_pc_3c7d:
    ai_if_field_gt_30_short $0080, $006D, $0000, $3C7D, $3C85
ai_pc_3c82:
    ai_call_ff $3C1A
ai_pc_3c85:
    ai_jmp_01_long $3C85, $3C8A
ai_pc_3c88:
    ai_jmp_01_short $3C88, $3C6A
ai_pc_3c8a:
    ai_ret_00
ai_pc_3c8b:
    ai_call_ff $3CB1
ai_pc_3c8e:
    ai_call_ff $6AE1
ai_pc_3c91:
    ai_if_tgt_not_within_16_34_short $3C91, $3C98
ai_pc_3c93:
    ai_call_ff $3CC2
ai_pc_3c96:
    ai_jmp_01_short $3C96, $3CA9
ai_pc_3c98:
    ai_if_tgt_not_within_48_51_short $3C98, $3C9F
ai_pc_3c9a:
    ai_call_ff $3D4C
ai_pc_3c9d:
    ai_jmp_01_short $3C9D, $3CA9
ai_pc_3c9f:
    ai_if_tgt_not_within_64_56_short $3C9F, $3CA6
ai_pc_3ca1:
    ai_call_ff $3CD5
ai_pc_3ca4:
    ai_jmp_01_short $3CA4, $3CA9
ai_pc_3ca6:
    ai_call_ff $3D31
ai_pc_3ca9:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $3CA9, $3C8E
ai_pc_3cae:
    ai_jmp_01_short $3CAE, $3C8E
