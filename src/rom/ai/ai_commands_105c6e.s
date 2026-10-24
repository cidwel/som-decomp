.setcpu "65816"
.segment "CODE"
.org $5C6E
.include "ai_command_macros.inc"
ai_pc_0d59:
    ai_pose_e2 $0000
ai_pc_0d5b:
    ai_ret_00
ai_pc_0d5c:
    ai_move_toward_e4 $0000, $0000
ai_pc_0d5f:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0D5F, $0D6C
ai_pc_0d64:
    ai_if_tgt_not_lane_h48_71_short $0D64, $0D6C
ai_pc_0d66:
    ai_move_toward_card_be $0000, $0000
ai_pc_0d69:
    ai_call_ff $6B19
ai_pc_0d6c:
    ai_call_ff $0DCA
ai_pc_0d6f:
    ai_ret_00
ai_pc_0d70:
    ai_move_toward_e4 $0000, $0000
ai_pc_0d73:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0D73, $0DAD
ai_pc_0d78:
    ai_if_obj_outside_5f_short $0080, $0D78, $0DA8
ai_pc_0d7b:
    ai_move_toward_e4 $0000, $0000
ai_pc_0d7e:
    ai_rnd_var3_2c $000F
ai_pc_0d80:
    ai_if_var3_nz_05_short $0D80, $0D99
ai_pc_0d82:
    ai_if_word_and_nz_ba_short $0081, $0010, $0000, $0040, $0D82, $0D8F
ai_pc_0d88:
    ai_tgt2_cur_c1
ai_pc_0d89:
    ai_cast_e9 $0004, $0011
ai_pc_0d8c:
    ai_tgt2_none_c0
ai_pc_0d8d:
    ai_jmp_01_short $0D8D, $0D94
ai_pc_0d8f:
    ai_tgt2_cur_c1
ai_pc_0d90:
    ai_cast_e9 $0004, $000C
ai_pc_0d93:
    ai_tgt2_none_c0
ai_pc_0d94:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_0d97:
    ai_jmp_01_short $0D97, $0DA6
ai_pc_0d99:
    ai_if_tgt_not_lane_h48_71_short $0D99, $0DA3
ai_pc_0d9b:
    ai_move_toward_card_be $0000, $0000
ai_pc_0d9e:
    ai_call_ff $6B19
ai_pc_0da1:
    ai_jmp_01_short $0DA1, $0DA6
ai_pc_0da3:
    ai_move_toward_e4 $0000, $0000
ai_pc_0da6:
    ai_jmp_01_short $0DA6, $0DAB
ai_pc_0da8:
    ai_move_toward_e4 $0000, $0000
ai_pc_0dab:
    ai_jmp_01_short $0DAB, $0DB0
ai_pc_0dad:
    ai_move_toward_e4 $0000, $0000
ai_pc_0db0:
    ai_ret_00
ai_pc_0db1:
    ai_rnd_var3_2c $0001
ai_pc_0db3:
    ai_if_var3_nz_05_short $0DB3, $0DB8
ai_pc_0db5:
    ai_move_toward_e4 $0000, $003C
ai_pc_0db8:
    ai_call_ff $6AE1
ai_pc_0dbb:
    ai_if_pos_same_9d_short $0DBB, $0DC3
ai_pc_0dbd:
    ai_pos_save_9f
ai_pc_0dbe:
    ai_move_toward_e4 $0004, $000F
ai_pc_0dc1:
    ai_jmp_01_short $0DC1, $0DC7
ai_pc_0dc3:
    ai_pos_save_9f
ai_pc_0dc4:
    ai_move_toward_alt_fd $0004, $000F
ai_pc_0dc7:
    ai_if_tgt_not_within_48_51_short $0DC7, $0DB8
ai_pc_0dc9:
    ai_ret_00
ai_pc_0dca:
    ai_if_tgt_not_within_32_4c_short $0DCA, $0DDD
ai_pc_0dcc:
    ai_call_ff $6AE1
ai_pc_0dcf:
    ai_if_pos_same_9d_short $0DCF, $0DD7
ai_pc_0dd1:
    ai_pos_save_9f
ai_pc_0dd2:
    ai_move_away_e6 $0004, $000F
ai_pc_0dd5:
    ai_jmp_01_short $0DD5, $0DDB
ai_pc_0dd7:
    ai_pos_save_9f
ai_pc_0dd8:
    ai_move_away_alt_fe $0004, $000F
ai_pc_0ddb:
    ai_jmp_01_short $0DDB, $0DCA
ai_pc_0ddd:
    ai_ret_00
ai_pc_0dde:
    ai_call_ff $0E0D
ai_pc_0de1:
    ai_rnd_var3_2c $000F
ai_pc_0de3:
    ai_if_var3_nz_05_short $0DE3, $0DEA
ai_pc_0de5:
    ai_call_ff $6993
ai_pc_0de8:
    ai_jmp_01_short $0DE8, $0E05
ai_pc_0dea:
    ai_call_ff $6AE1
ai_pc_0ded:
    ai_if_tgt_not_within_32_4c_short $0DED, $0DF4
ai_pc_0def:
    ai_call_ff $0E10
ai_pc_0df2:
    ai_jmp_01_short $0DF2, $0E05
ai_pc_0df4:
    ai_if_tgt_not_within_48_51_short $0DF4, $0DFB
ai_pc_0df6:
    ai_call_ff $0E22
ai_pc_0df9:
    ai_jmp_01_short $0DF9, $0E05
ai_pc_0dfb:
    ai_if_tgt_not_within_64_56_short $0DFB, $0E02
ai_pc_0dfd:
    ai_call_ff $0E33
ai_pc_0e00:
    ai_jmp_01_short $0E00, $0E05
ai_pc_0e02:
    ai_call_ff $0E82
ai_pc_0e05:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $0E05, $0DE1
ai_pc_0e0a:
    ai_jmp_01_short $0E0A, $0DE1
