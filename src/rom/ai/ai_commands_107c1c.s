.setcpu "65816"
.segment "CODE"
.org $7C1C
.include "ai_command_macros.inc"
ai_pc_2d07:
    ai_pose_e2 $0000
ai_pc_2d09:
    ai_ret_00
ai_pc_2d0a:
    ai_call_ff $2D84
ai_pc_2d0d:
    ai_call_ff $2DC8
ai_pc_2d10:
    ai_ret_00
ai_pc_2d11:
    ai_move_toward_card_be $0000, $0005
ai_pc_2d14:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2D14, $2D32
ai_pc_2d19:
    ai_if_tgt_not_lane_v64_66_short $2D19, $2D23
ai_pc_2d1b:
    ai_move_toward_card_be $0000, $0005
ai_pc_2d1e:
    ai_call_ff $6B19
ai_pc_2d21:
    ai_jmp_01_short $2D21, $2D30
ai_pc_2d23:
    ai_if_tgt_not_lane_h64_6f_short $2D23, $2D2D
ai_pc_2d25:
    ai_move_toward_card_be $0000, $0005
ai_pc_2d28:
    ai_call_ff $6B19
ai_pc_2d2b:
    ai_jmp_01_short $2D2B, $2D30
ai_pc_2d2d:
    ai_move_toward_card_be $0000, $0005
ai_pc_2d30:
    ai_jmp_01_short $2D30, $2D35
ai_pc_2d32:
    ai_call_ff $2DA4
ai_pc_2d35:
    ai_ret_00
ai_pc_2d36:
    ai_move_toward_card_be $0000, $0005
ai_pc_2d39:
    ai_if_obj_outside_5f_short $0080, $2D39, $2D67
ai_pc_2d3c:
    ai_rnd_var3_2c $0007
ai_pc_2d3e:
    ai_if_var3_nz_05_short $2D3E, $2D5A
ai_pc_2d40:
    ai_move_toward_card_be $0000, $0000
ai_pc_2d43:
    ai_tgt2_cur_c1
ai_pc_2d44:
    ai_cast_e9 $0003, $0028
ai_pc_2d47:
    ai_tgt2_none_c0
ai_pc_2d48:
    ai_move_toward_card_be $0000, $0078
ai_pc_2d4b:
    ai_call_ff $2DB6
ai_pc_2d4e:
    ai_move_toward_card_be $0000, $0005
ai_pc_2d51:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_2d55:
    ai_call_ff $6B19
ai_pc_2d58:
    ai_jmp_01_short $2D58, $2D65
ai_pc_2d5a:
    ai_move_toward_card_be $0000, $0000
ai_pc_2d5d:
    ai_rnd_var3_2c $000F
ai_pc_2d5f:
    ai_if_var3_nz_05_short $2D5F, $2D65
ai_pc_2d61:
    ai_pose_e2 $0002
ai_pc_2d63:
    ai_pose_e2 $0002
ai_pc_2d65:
    ai_jmp_01_short $2D65, $2D6A
ai_pc_2d67:
    ai_move_toward_card_be $0000, $0000
ai_pc_2d6a:
    ai_ret_00
ai_pc_2d6b:
    ai_call_ff $6AE1
ai_pc_2d6e:
    ai_if_pos_same_9d_short $2D6E, $2D76
ai_pc_2d70:
    ai_pos_save_9f
ai_pc_2d71:
    ai_move_toward_card_be $0004, $000F
ai_pc_2d74:
    ai_jmp_01_short $2D74, $2D7A
ai_pc_2d76:
    ai_pos_save_9f
ai_pc_2d77:
    ai_move_toward_alt_fd $0004, $000F
ai_pc_2d7a:
    ai_if_tgt_not_within_64_56_short $2D7A, $2D6B
ai_pc_2d7c:
    ai_move_toward_card_be $0000, $0005
ai_pc_2d7f:
    ai_pose_e2 $0002
ai_pc_2d81:
    ai_pose_e2 $0002
ai_pc_2d83:
    ai_ret_00
ai_pc_2d84:
    ai_move_toward_card_be $0000, $0005
ai_pc_2d87:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2D87, $2DA3
ai_pc_2d8c:
    ai_if_tgt_not_lane_v64_66_short $2D8C, $2D96
ai_pc_2d8e:
    ai_move_toward_card_be $0000, $0005
ai_pc_2d91:
    ai_call_ff $6B19
ai_pc_2d94:
    ai_jmp_01_short $2D94, $2DA3
ai_pc_2d96:
    ai_if_tgt_not_lane_h64_6f_short $2D96, $2DA0
ai_pc_2d98:
    ai_move_toward_card_be $0000, $0005
ai_pc_2d9b:
    ai_call_ff $6B19
ai_pc_2d9e:
    ai_jmp_01_short $2D9E, $2DA3
ai_pc_2da0:
    ai_move_toward_card_be $0000, $0005
ai_pc_2da3:
    ai_ret_00
ai_pc_2da4:
    ai_call_ff $6AE1
ai_pc_2da7:
    ai_if_pos_same_9d_short $2DA7, $2DAF
ai_pc_2da9:
    ai_pos_save_9f
ai_pc_2daa:
    ai_move_toward_card_be $0004, $000F
ai_pc_2dad:
    ai_jmp_01_short $2DAD, $2DB3
ai_pc_2daf:
    ai_pos_save_9f
ai_pc_2db0:
    ai_move_toward_alt_fd $0004, $000F
ai_pc_2db3:
    ai_if_tgt_not_within_32_4c_short $2DB3, $2DA4
ai_pc_2db5:
    ai_ret_00
ai_pc_2db6:
    ai_call_ff $6AE1
ai_pc_2db9:
    ai_if_pos_same_9d_short $2DB9, $2DC1
ai_pc_2dbb:
    ai_pos_save_9f
ai_pc_2dbc:
    ai_move_toward_card_be $0002, $000A
ai_pc_2dbf:
    ai_jmp_01_short $2DBF, $2DC5
ai_pc_2dc1:
    ai_pos_save_9f
ai_pc_2dc2:
    ai_move_toward_alt_fd $0002, $000A
ai_pc_2dc5:
    ai_if_tgt_not_within_32_4c_short $2DC5, $2DB6
ai_pc_2dc7:
    ai_ret_00
ai_pc_2dc8:
    ai_if_tgt_not_within_48_51_short $2DC8, $2DE3
ai_pc_2dca:
    ai_call_ff $6AE1
ai_pc_2dcd:
    ai_if_pos_same_9d_short $2DCD, $2DD5
ai_pc_2dcf:
    ai_pos_save_9f
ai_pc_2dd0:
    ai_move_away_card_bf $0004, $000F
ai_pc_2dd3:
    ai_jmp_01_short $2DD3, $2DD9
ai_pc_2dd5:
    ai_pos_save_9f
ai_pc_2dd6:
    ai_move_away_alt_fe $0004, $000F
ai_pc_2dd9:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2DD9, $2DE1
ai_pc_2dde:
    ai_jmp_01_long $2DDE, $2DE3
ai_pc_2de1:
    ai_jmp_01_short $2DE1, $2DC8
ai_pc_2de3:
    ai_ret_00
ai_pc_2de4:
    ai_call_ff $2E22
ai_pc_2de7:
    ai_if_word_gt_bd_short $0080, $0002, $0014, $0000, $2DE7, $2DF2
ai_pc_2ded:
    ai_call_ff $2F19
ai_pc_2df0:
    ai_jmp_01_short $2DF0, $2DFE
ai_pc_2df2:
    ai_rnd_var3_2c $0007
ai_pc_2df4:
    ai_if_var3_nz_05_short $2DF4, $2DFB
ai_pc_2df6:
    ai_call_ff $6653
ai_pc_2df9:
    ai_jmp_01_short $2DF9, $2DFE
ai_pc_2dfb:
    ai_call_ff $2E06
ai_pc_2dfe:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $2DFE, $2DE7
ai_pc_2e03:
    ai_jmp_01_short $2E03, $2DE7
