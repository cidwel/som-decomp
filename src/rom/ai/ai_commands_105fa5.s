.setcpu "65816"
.segment "CODE"
.org $5FA5
.include "ai_command_macros.inc"
ai_pc_1090:
    ai_if_word_gt_bd_short $0080, $0002, $0095, $0000, $1090, $1099
ai_pc_1096:
    ai_jmp_01_long $1096, $109B
ai_pc_1099:
    ai_if_tgt_not_within_32_4c_short $1099, $107C
ai_pc_109b:
    ai_ret_00
ai_pc_109c:
    ai_move_toward_e4 $0000, $0000
ai_pc_109f:
    ai_if_field_gt_30_short $0080, $006D, $0000, $109F, $10C2
ai_pc_10a4:
    ai_call_ff $1117
ai_pc_10a7:
    ai_if_word_and_nz_ba_short $0081, $0010, $0000, $0020, $10A7, $10B5
ai_pc_10ad:
    ai_move_toward_e4 $0000, $0000
ai_pc_10b0:
    ai_call_ff $6B0F
ai_pc_10b3:
    ai_jmp_01_short $10B3, $10C0
ai_pc_10b5:
    ai_move_toward_e4 $0000, $0000
ai_pc_10b8:
    ai_flash_fc
ai_pc_10b9:
    ai_call_ff $6B0F
ai_pc_10bc:
    ai_flash_fc
ai_pc_10bd:
    ai_move_toward_e4 $0000, $0005
ai_pc_10c0:
    ai_jmp_01_short $10C0, $10C5
ai_pc_10c2:
    ai_move_toward_e4 $0000, $003C
ai_pc_10c5:
    ai_ret_00
ai_pc_10c6:
    ai_move_toward_e4 $0000, $0000
ai_pc_10c9:
    ai_if_field_gt_30_short $0080, $006D, $0000, $10C9, $10EC
ai_pc_10ce:
    ai_call_ff $1117
ai_pc_10d1:
    ai_if_word_and_nz_ba_short $0081, $0010, $0000, $0020, $10D1, $10DF
ai_pc_10d7:
    ai_move_toward_e4 $0000, $0000
ai_pc_10da:
    ai_call_ff $6B0F
ai_pc_10dd:
    ai_jmp_01_short $10DD, $10EA
ai_pc_10df:
    ai_move_toward_e4 $0000, $0000
ai_pc_10e2:
    ai_flash_fc
ai_pc_10e3:
    ai_call_ff $6B0F
ai_pc_10e6:
    ai_flash_fc
ai_pc_10e7:
    ai_move_toward_e4 $0000, $0005
ai_pc_10ea:
    ai_jmp_01_short $10EA, $10EF
ai_pc_10ec:
    ai_move_toward_e4 $0000, $003C
ai_pc_10ef:
    ai_ret_00
ai_pc_10f0:
    ai_rnd_var3_2c $000F
ai_pc_10f2:
    ai_if_var3_nz_05_short $10F2, $10F7
ai_pc_10f4:
    ai_call_ff $112B
ai_pc_10f7:
    ai_call_ff $10FD
ai_pc_10fa:
    ai_if_tgt_not_within_32_4c_short $10FA, $10F0
ai_pc_10fc:
    ai_ret_00
ai_pc_10fd:
    ai_set_var2_27 $0004
ai_pc_10ff:
    ai_call_ff $6AE1
ai_pc_1102:
    ai_if_pos_same_9d_short $1102, $110A
ai_pc_1104:
    ai_pos_save_9f
ai_pc_1105:
    ai_move_toward_card_be $0004, $000A
ai_pc_1108:
    ai_jmp_01_short $1108, $110E
ai_pc_110a:
    ai_pos_save_9f
ai_pc_110b:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_110e:
    ai_if_tgt_not_within_32_4c_short $110E, $1113
ai_pc_1110:
    ai_jmp_01_long $1110, $1116
ai_pc_1113:
    ai_dec_var2_20
ai_pc_1114:
    ai_if_var2_nz_04_short $1114, $10FF
ai_pc_1116:
    ai_ret_00
ai_pc_1117:
    ai_if_tgt_not_within_16_34_short $1117, $112A
ai_pc_1119:
    ai_call_ff $6AE1
ai_pc_111c:
    ai_if_pos_same_9d_short $111C, $1124
ai_pc_111e:
    ai_pos_save_9f
ai_pc_111f:
    ai_move_toward_card_be $0005, $000A
ai_pc_1122:
    ai_jmp_01_short $1122, $1128
ai_pc_1124:
    ai_pos_save_9f
ai_pc_1125:
    ai_move_toward_alt_fd $0005, $000A
ai_pc_1128:
    ai_jmp_01_short $1128, $1117
ai_pc_112a:
    ai_ret_00
ai_pc_112b:
    ai_pose_e2 $0005
ai_pc_112d:
    ai_call_ff $6AE1
ai_pc_1130:
    ai_pose_e2 $0005
ai_pc_1132:
    ai_if_tgt_not_beyond_64_5a_short $1132, $1137
ai_pc_1134:
    ai_jmp_01_long $1134, $1139
ai_pc_1137:
    ai_if_tgt_not_within_32_4c_short $1137, $112D
ai_pc_1139:
    ai_move_toward_e4 $000B, $0000
ai_pc_113c:
    ai_ret_00
ai_pc_113d:
    ai_if_obj_outside_5f_short $0080, $113D, $1152
ai_pc_1140:
    ai_if_field_gt_30_short $0081, $003B, $0000, $1140, $114F
ai_pc_1145:
    ai_move_toward_e4 $0000, $0000
ai_pc_1148:
    ai_tgt2_cur_c1
ai_pc_1149:
    ai_cast_e9 $0004, $0002
ai_pc_114c:
    ai_tgt2_none_c0
ai_pc_114d:
    ai_jmp_01_short $114D, $1152
ai_pc_114f:
    ai_move_toward_e4 $0000, $003C
ai_pc_1152:
    ai_ret_00
ai_pc_1153:
    ai_call_ff $117B
ai_pc_1156:
    ai_rnd_var3_2c $000F
ai_pc_1158:
    ai_if_var3_nz_05_short $1158, $115F
ai_pc_115a:
    ai_call_ff $690F
ai_pc_115d:
    ai_jmp_01_short $115D, $1173
ai_pc_115f:
    ai_call_ff $6AE1
ai_pc_1162:
    ai_if_tgt_not_within_48_51_short $1162, $1169
ai_pc_1164:
    ai_call_ff $1201
ai_pc_1167:
    ai_jmp_01_short $1167, $1173
ai_pc_1169:
    ai_if_tgt_not_within_64_56_short $1169, $1170
ai_pc_116b:
    ai_call_ff $1180
ai_pc_116e:
    ai_jmp_01_short $116E, $1173
ai_pc_1170:
    ai_call_ff $11EF
ai_pc_1173:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $1173, $1156
ai_pc_1178:
    ai_jmp_01_short $1178, $1156
