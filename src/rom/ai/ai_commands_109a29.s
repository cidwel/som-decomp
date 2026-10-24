.setcpu "65816"
.segment "CODE"
.org $9A29
.include "ai_command_macros.inc"
ai_pc_4b14:
    ai_pose_e2 $0001
ai_pc_4b16:
    ai_call_ff $6AE1
ai_pc_4b19:
    ai_rnd_var3_2c $0005
ai_pc_4b1b:
    ai_if_var3_nz_05_short $4B1B, $4B32
ai_pc_4b1d:
    ai_if_obj_outside_5f_short $0080, $4B1D, $4B2D
ai_pc_4b20:
    ai_move_toward2_e5 $0000, $0000
ai_pc_4b23:
    ai_tgt2_cur_c1
ai_pc_4b24:
    ai_cast_e9 $0006, $0026
ai_pc_4b27:
    ai_tgt2_none_c0
ai_pc_4b28:
    ai_turn_facing_e3 $0000, $003C
ai_pc_4b2b:
    ai_jmp_01_short $4B2B, $4B30
ai_pc_4b2d:
    ai_call_ff $4C47
ai_pc_4b30:
    ai_jmp_01_short $4B30, $4B35
ai_pc_4b32:
    ai_call_ff $4BCC
ai_pc_4b35:
    ai_ret_00
ai_pc_4b36:
    ai_move_toward_e4 $0000, $0000
ai_pc_4b39:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4B39, $4B44
ai_pc_4b3e:
    ai_move_toward_e4 $0000, $0000
ai_pc_4b41:
    ai_call_ff $6B23
ai_pc_4b44:
    ai_call_ff $4C47
ai_pc_4b47:
    ai_ret_00
ai_pc_4b48:
    ai_move_toward_e4 $0000, $0000
ai_pc_4b4b:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4B4B, $4B69
ai_pc_4b50:
    ai_rnd_var3_2c $0002
ai_pc_4b52:
    ai_if_var3_nz_05_short $4B52, $4B5E
ai_pc_4b54:
    ai_move_toward_e4 $0000, $0005
ai_pc_4b57:
    ai_pose_e2 $000B
ai_pc_4b59:
    ai_call_ff $6B23
ai_pc_4b5c:
    ai_jmp_01_short $4B5C, $4B69
ai_pc_4b5e:
    ai_flash_fc
ai_pc_4b5f:
    ai_move_toward_e4 $0000, $0000
ai_pc_4b62:
    ai_call_ff $6B23
ai_pc_4b65:
    ai_flash_fc
ai_pc_4b66:
    ai_move_toward_e4 $0000, $0005
ai_pc_4b69:
    ai_call_ff $4C52
ai_pc_4b6c:
    ai_ret_00
ai_pc_4b6d:
    ai_move_toward_e4 $0000, $0000
ai_pc_4b70:
    ai_call_ff $4C28
ai_pc_4b73:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4B73, $4BA6
ai_pc_4b78:
    ai_move_toward_e4 $0000, $0000
ai_pc_4b7b:
    ai_rnd_var3_2c $000F
ai_pc_4b7d:
    ai_if_var3_nz_05_short $4B7D, $4B91
ai_pc_4b7f:
    ai_if_obj_outside_5f_short $0080, $4B7F, $4B8C
ai_pc_4b82:
    ai_tgt2_cur_c1
ai_pc_4b83:
    ai_cast_e9 $0006, $0007
ai_pc_4b86:
    ai_tgt2_none_c0
ai_pc_4b87:
    ai_turn_facing_e3 $0000, $0078
ai_pc_4b8a:
    ai_jmp_01_short $4B8A, $4B8F
ai_pc_4b8c:
    ai_call_ff $4BCC
ai_pc_4b8f:
    ai_jmp_01_short $4B8F, $4BA4
ai_pc_4b91:
    ai_if_var3_gt_15_short $0009, $4B91, $4BA1
ai_pc_4b94:
    ai_flash_fc
ai_pc_4b95:
    ai_move_toward_e4 $0000, $0000
ai_pc_4b98:
    ai_call_ff $6B23
ai_pc_4b9b:
    ai_flash_fc
ai_pc_4b9c:
    ai_move_toward_e4 $0000, $0005
ai_pc_4b9f:
    ai_jmp_01_short $4B9F, $4BA4
ai_pc_4ba1:
    ai_call_ff $4BCC
ai_pc_4ba4:
    ai_jmp_01_short $4BA4, $4BA9
ai_pc_4ba6:
    ai_move_toward_e4 $0000, $0000
ai_pc_4ba9:
    ai_ret_00
ai_pc_4baa:
    ai_rnd_var3_2c $000F
ai_pc_4bac:
    ai_if_var3_nz_05_short $4BAC, $4BB3
ai_pc_4bae:
    ai_call_ff $4C36
ai_pc_4bb1:
    ai_jmp_01_short $4BB1, $4BCB
ai_pc_4bb3:
    ai_set_var2_27 $0004
ai_pc_4bb5:
    ai_if_tgt_not_within_48_51_short $4BB5, $4BCB
ai_pc_4bb7:
    ai_if_pos_same_9d_short $4BB7, $4BBF
ai_pc_4bb9:
    ai_pos_save_9f
ai_pc_4bba:
    ai_move_toward_e4 $0004, $000A
ai_pc_4bbd:
    ai_jmp_01_short $4BBD, $4BC3
ai_pc_4bbf:
    ai_pos_save_9f
ai_pc_4bc0:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_4bc3:
    ai_dec_var2_20
ai_pc_4bc4:
    ai_if_var2_nz_04_short $4BC4, $4BC9
ai_pc_4bc6:
    ai_jmp_01_long $4BC6, $4BCB
ai_pc_4bc9:
    ai_jmp_01_short $4BC9, $4BB5
ai_pc_4bcb:
    ai_ret_00
ai_pc_4bcc:
    ai_if_tgt_not_within_64_56_short $4BCC, $4C05
ai_pc_4bce:
    ai_call_ff $6AE1
ai_pc_4bd1:
    ai_call_ff $4C06
ai_pc_4bd4:
    ai_hop_e0 $0001, $0000, $0005
ai_pc_4bd8:
    ai_call_ff $4C06
ai_pc_4bdb:
    ai_hop_e0 $0004, $0000, $0005
ai_pc_4bdf:
    ai_call_ff $4C06
ai_pc_4be2:
    ai_hop_e0 $0002, $0000, $0005
ai_pc_4be6:
    ai_call_ff $4C06
ai_pc_4be9:
    ai_hop_e0 $0008, $0000, $0005
ai_pc_4bed:
    ai_if_tgt_not_within_32_4c_short $4BED, $4C03
ai_pc_4bef:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4BEF, $4BFA
ai_pc_4bf4:
    ai_move_toward_e4 $0003, $0000
ai_pc_4bf7:
    ai_call_ff $6B23
ai_pc_4bfa:
    ai_move_toward_e4 $0000, $0005
ai_pc_4bfd:
    ai_call_ff $4C52
ai_pc_4c00:
    ai_jmp_01_long $4C00, $4C05
ai_pc_4c03:
    ai_jmp_01_short $4C03, $4BCC
ai_pc_4c05:
    ai_ret_00
ai_pc_4c06:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4C06, $4C27
ai_pc_4c0b:
    ai_if_tgt_not_lane_v64_66_short $4C0B, $4C1A
ai_pc_4c0d:
    ai_flash_fc
ai_pc_4c0e:
    ai_move_toward_card_be $0000, $0000
ai_pc_4c11:
    ai_call_ff $6B23
ai_pc_4c14:
    ai_flash_fc
ai_pc_4c15:
    ai_move_toward_e4 $0000, $0005
ai_pc_4c18:
    ai_jmp_01_short $4C18, $4C27
ai_pc_4c1a:
    ai_if_tgt_not_lane_h64_6f_short $4C1A, $4C27
ai_pc_4c1c:
    ai_flash_fc
ai_pc_4c1d:
    ai_move_toward_card_be $0000, $0000
ai_pc_4c20:
    ai_call_ff $6B23
ai_pc_4c23:
    ai_flash_fc
ai_pc_4c24:
    ai_move_toward_e4 $0000, $0005
ai_pc_4c27:
    ai_ret_00
ai_pc_4c28:
    ai_if_field_gt_30_short $0080, $001D, $0000, $4C28, $4C35
ai_pc_4c2d:
    ai_tgt2_self_c4
ai_pc_4c2e:
    ai_cast_e9 $0006, $0009
ai_pc_4c31:
    ai_tgt2_none_c0
ai_pc_4c32:
    ai_turn_facing_e3 $0000, $003C
ai_pc_4c35:
    ai_ret_00
ai_pc_4c36:
    ai_set_var3_28 $0003
ai_pc_4c38:
    ai_call_ff $6AE1
ai_pc_4c3b:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_4c3e:
    ai_if_tgt_not_within_64_56_short $4C3E, $4C43
ai_pc_4c40:
    ai_jmp_01_long $4C40, $4C46
ai_pc_4c43:
    ai_dec_var3_21
ai_pc_4c44:
    ai_if_var3_nz_05_short $4C44, $4C38
ai_pc_4c46:
    ai_ret_00
ai_pc_4c47:
    ai_if_tgt_not_within_48_51_short $4C47, $4C51
ai_pc_4c49:
    ai_call_ff $6AE1
ai_pc_4c4c:
    ai_move_away_alt_fe $0002, $0000
ai_pc_4c4f:
    ai_jmp_01_short $4C4F, $4C47
ai_pc_4c51:
    ai_ret_00
ai_pc_4c52:
    ai_if_tgt_not_within_48_51_short $4C52, $4C72
ai_pc_4c54:
    ai_call_ff $6AE1
ai_pc_4c57:
    ai_if_pos_same_9d_short $4C57, $4C5F
ai_pc_4c59:
    ai_pos_save_9f
ai_pc_4c5a:
    ai_move_toward_e4 $0005, $000A
ai_pc_4c5d:
    ai_jmp_01_short $4C5D, $4C63
ai_pc_4c5f:
    ai_pos_save_9f
ai_pc_4c60:
    ai_move_toward_alt_fd $0005, $000A
ai_pc_4c63:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4C63, $4C70
ai_pc_4c68:
    ai_if_tgt_not_within_32_4c_short $4C68, $4C70
ai_pc_4c6a:
    ai_move_toward_e4 $0000, $0000
ai_pc_4c6d:
    ai_call_ff $6B23
ai_pc_4c70:
    ai_jmp_01_short $4C70, $4C52
ai_pc_4c72:
    ai_ret_00
ai_pc_4c73:
    ai_call_ff $4CA2
ai_pc_4c76:
    ai_rnd_var3_2c $000F
ai_pc_4c78:
    ai_if_var3_nz_05_short $4C78, $4C7F
ai_pc_4c7a:
    ai_call_ff $672F
ai_pc_4c7d:
    ai_jmp_01_short $4C7D, $4C9A
ai_pc_4c7f:
    ai_call_ff $6AE1
ai_pc_4c82:
    ai_if_tgt_not_within_32_4c_short $4C82, $4C89
ai_pc_4c84:
    ai_call_ff $4CAE
ai_pc_4c87:
    ai_jmp_01_short $4C87, $4C9A
ai_pc_4c89:
    ai_if_tgt_not_within_48_51_short $4C89, $4C90
ai_pc_4c8b:
    ai_call_ff $4CB9
ai_pc_4c8e:
    ai_jmp_01_short $4C8E, $4C9A
ai_pc_4c90:
    ai_if_tgt_not_within_64_56_short $4C90, $4C97
ai_pc_4c92:
    ai_call_ff $4D1B
ai_pc_4c95:
    ai_jmp_01_short $4C95, $4C9A
ai_pc_4c97:
    ai_call_ff $4D1B
ai_pc_4c9a:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $4C9A, $4C76
ai_pc_4c9f:
    ai_jmp_01_short $4C9F, $4C76
