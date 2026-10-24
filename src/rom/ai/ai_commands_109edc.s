.setcpu "65816"
.segment "CODE"
.org $9EDC
.include "ai_command_macros.inc"
ai_pc_4fc7:
    ai_pose_e2 $0006
ai_pc_4fc9:
    ai_call_ff $6AE1
ai_pc_4fcc:
    ai_pose_e2 $0006
ai_pc_4fce:
    ai_if_word_gt_bd_short $0080, $0002, $009A, $0001, $4FCE, $4FD7
ai_pc_4fd4:
    ai_jmp_01_long $4FD4, $4FD9
ai_pc_4fd7:
    ai_if_tgt_not_within_32_4c_short $4FD7, $4FC9
ai_pc_4fd9:
    ai_pose_e2 $0000
ai_pc_4fdb:
    ai_ret_00
ai_pc_4fdc:
    ai_move_toward_e4 $0000, $0005
ai_pc_4fdf:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4FDF, $4FFB
ai_pc_4fe4:
    ai_if_tgt_not_within_32_4c_short $4FE4, $4FEE
ai_pc_4fe6:
    ai_call_ff $6AE1
ai_pc_4fe9:
    ai_move_away_alt_fe $0002, $0005
ai_pc_4fec:
    ai_jmp_01_short $4FEC, $4FE4
ai_pc_4fee:
    ai_move_toward_e4 $0000, $0005
ai_pc_4ff1:
    ai_call_ff $6B23
ai_pc_4ff4:
    ai_if_field_gt_30_short $0080, $001D, $0000, $4FF4, $4FFB
ai_pc_4ff9:
    ai_pose_e2 $000C
ai_pc_4ffb:
    ai_call_ff $5190
ai_pc_4ffe:
    ai_ret_00
ai_pc_4fff:
    ai_move_toward_e4 $0000, $0005
ai_pc_5002:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5002, $5014
ai_pc_5007:
    ai_move_toward_e4 $0000, $0005
ai_pc_500a:
    ai_call_ff $6B23
ai_pc_500d:
    ai_if_field_gt_30_short $0080, $001D, $0000, $500D, $5014
ai_pc_5012:
    ai_pose_e2 $000C
ai_pc_5014:
    ai_call_ff $5190
ai_pc_5017:
    ai_ret_00
ai_pc_5018:
    ai_move_toward_e4 $0000, $0005
ai_pc_501b:
    ai_if_field_gt_30_short $0080, $006D, $0000, $501B, $5030
ai_pc_5020:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_5023:
    ai_move_toward_e4 $0000, $0005
ai_pc_5026:
    ai_call_ff $6B23
ai_pc_5029:
    ai_if_field_gt_30_short $0080, $001D, $0000, $5029, $5030
ai_pc_502e:
    ai_pose_e2 $000C
ai_pc_5030:
    ai_call_ff $5171
ai_pc_5033:
    ai_ret_00
ai_pc_5034:
    ai_move_toward_e4 $0000, $0005
ai_pc_5037:
    ai_if_field_gt_30_long $0080, $006D, $0000, $5037, $5094
ai_pc_503d:
    ai_rnd_var3_2c $000F
ai_pc_503f:
    ai_if_var3_nz_05_short $503F, $5053
ai_pc_5041:
    ai_call_ff $5121
ai_pc_5044:
    ai_move_toward_e4 $0000, $0005
ai_pc_5047:
    ai_call_ff $6B23
ai_pc_504a:
    ai_if_field_gt_30_short $0080, $001D, $0000, $504A, $5051
ai_pc_504f:
    ai_pose_e2 $000C
ai_pc_5051:
    ai_jmp_01_short $5051, $5092
ai_pc_5053:
    ai_if_var3_ne_0d_short $0001, $5053, $5068
ai_pc_5056:
    ai_call_ff $5133
ai_pc_5059:
    ai_move_toward_e4 $0000, $0005
ai_pc_505c:
    ai_call_ff $6B23
ai_pc_505f:
    ai_if_field_gt_30_short $0080, $001D, $0000, $505F, $5066
ai_pc_5064:
    ai_pose_e2 $000C
ai_pc_5066:
    ai_jmp_01_short $5066, $5092
ai_pc_5068:
    ai_if_var3_ne_0d_short $0002, $5068, $507D
ai_pc_506b:
    ai_call_ff $5145
ai_pc_506e:
    ai_move_toward_e4 $0000, $0005
ai_pc_5071:
    ai_call_ff $6B23
ai_pc_5074:
    ai_if_field_gt_30_short $0080, $001D, $0000, $5074, $507B
ai_pc_5079:
    ai_pose_e2 $000C
ai_pc_507b:
    ai_jmp_01_short $507B, $5092
ai_pc_507d:
    ai_if_var3_ne_0d_short $0003, $507D, $508F
ai_pc_5080:
    ai_move_toward_e4 $0000, $0005
ai_pc_5083:
    ai_call_ff $6B23
ai_pc_5086:
    ai_if_field_gt_30_short $0080, $001D, $0000, $5086, $508D
ai_pc_508b:
    ai_pose_e2 $000C
ai_pc_508d:
    ai_jmp_01_short $508D, $5092
ai_pc_508f:
    ai_move_toward_e4 $0000, $0005
ai_pc_5092:
    ai_jmp_01_short $5092, $5097
ai_pc_5094:
    ai_move_toward_e4 $0000, $0005
ai_pc_5097:
    ai_ret_00
ai_pc_5098:
    ai_if_obj_outside_5f_long $0080, $5098, $5100
ai_pc_509c:
    ai_if_word_and_nz_ba_short $0081, $002A, $0040, $0000, $509C, $50B7
ai_pc_50a2:
    ai_if_word_and_nz_ba_short $0080, $0019, $0040, $0000, $50A2, $50B1
ai_pc_50a8:
    ai_tgt2_self_c4
ai_pc_50a9:
    ai_cast_e9 $0004, $0003
ai_pc_50ac:
    ai_tgt2_none_c0
ai_pc_50ad:
    ai_pose_e2 $000B
ai_pc_50af:
    ai_jmp_01_short $50AF, $50B4
ai_pc_50b1:
    ai_move_toward_e4 $0000, $0005
ai_pc_50b4:
    ai_jmp_01_long $50B4, $50FD
ai_pc_50b7:
    ai_if_word_and_nz_ba_short $0081, $002A, $0000, $0040, $50B7, $50D1
ai_pc_50bd:
    ai_if_word_and_nz_ba_short $0080, $0019, $0000, $0040, $50BD, $50CC
ai_pc_50c3:
    ai_tgt2_self_c4
ai_pc_50c4:
    ai_cast_e9 $0004, $000F
ai_pc_50c7:
    ai_tgt2_none_c0
ai_pc_50c8:
    ai_pose_e2 $0008
ai_pc_50ca:
    ai_jmp_01_short $50CA, $50CF
ai_pc_50cc:
    ai_move_toward_e4 $0000, $0005
ai_pc_50cf:
    ai_jmp_01_short $50CF, $50FD
ai_pc_50d1:
    ai_if_word_and_nz_ba_short $0081, $002A, $0020, $0000, $50D1, $50EB
ai_pc_50d7:
    ai_if_word_and_nz_ba_short $0080, $0019, $0020, $0000, $50D7, $50E6
ai_pc_50dd:
    ai_tgt2_self_c4
ai_pc_50de:
    ai_cast_e9 $0004, $0009
ai_pc_50e1:
    ai_tgt2_none_c0
ai_pc_50e2:
    ai_pose_e2 $0009
ai_pc_50e4:
    ai_jmp_01_short $50E4, $50E9
ai_pc_50e6:
    ai_move_toward_e4 $0000, $0005
ai_pc_50e9:
    ai_jmp_01_short $50E9, $50FD
ai_pc_50eb:
    ai_if_word_and_nz_ba_short $0080, $0019, $0020, $0000, $50EB, $50FA
ai_pc_50f1:
    ai_tgt2_self_c4
ai_pc_50f2:
    ai_cast_e9 $0004, $0015
ai_pc_50f5:
    ai_tgt2_none_c0
ai_pc_50f6:
    ai_pose_e2 $000A
ai_pc_50f8:
    ai_jmp_01_short $50F8, $50FD
ai_pc_50fa:
    ai_move_toward_e4 $0000, $0005
ai_pc_50fd:
    ai_turn_facing_e3 $0000, $003C
ai_pc_5100:
    ai_pose_e2 $0003
ai_pc_5102:
    ai_pose_e2 $0003
ai_pc_5104:
    ai_ret_00
ai_pc_5105:
    ai_rnd_var3_2c $000F
ai_pc_5107:
    ai_if_var3_nz_05_short $5107, $511B
ai_pc_5109:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5109, $511B
ai_pc_510e:
    ai_move_toward_e4 $0000, $0005
ai_pc_5111:
    ai_call_ff $6B23
ai_pc_5114:
    ai_if_field_gt_30_short $0080, $001D, $0000, $5114, $511B
ai_pc_5119:
    ai_pose_e2 $000C
ai_pc_511b:
    ai_call_ff $5157
ai_pc_511e:
    ai_if_tgt_not_within_64_56_short $511E, $5105
ai_pc_5120:
    ai_ret_00
ai_pc_5121:
    ai_call_ff $6AE1
ai_pc_5124:
    ai_if_pos_same_9d_short $5124, $512C
ai_pc_5126:
    ai_pos_save_9f
ai_pc_5127:
    ai_move_toward_e4 $0004, $0005
ai_pc_512a:
    ai_jmp_01_short $512A, $5130
ai_pc_512c:
    ai_pos_save_9f
ai_pc_512d:
    ai_move_toward_alt_fd $0004, $0005
ai_pc_5130:
    ai_if_tgt_not_within_32_4c_short $5130, $5121
ai_pc_5132:
    ai_ret_00
ai_pc_5133:
    ai_call_ff $6AE1
ai_pc_5136:
    ai_if_pos_same_9d_short $5136, $513E
ai_pc_5138:
    ai_pos_save_9f
ai_pc_5139:
    ai_move_toward_e4 $0001, $0005
ai_pc_513c:
    ai_jmp_01_short $513C, $5142
ai_pc_513e:
    ai_pos_save_9f
ai_pc_513f:
    ai_move_toward_alt_fd $0001, $0005
ai_pc_5142:
    ai_if_tgt_not_within_32_4c_short $5142, $5133
ai_pc_5144:
    ai_ret_00
ai_pc_5145:
    ai_call_ff $6AE1
ai_pc_5148:
    ai_if_pos_same_9d_short $5148, $5150
ai_pc_514a:
    ai_pos_save_9f
ai_pc_514b:
    ai_move_toward_e4 $0002, $0005
ai_pc_514e:
    ai_jmp_01_short $514E, $5154
ai_pc_5150:
    ai_pos_save_9f
ai_pc_5151:
    ai_move_toward_alt_fd $0002, $0005
ai_pc_5154:
    ai_if_tgt_not_within_32_4c_short $5154, $5145
ai_pc_5156:
    ai_ret_00
ai_pc_5157:
    ai_set_var2_27 $0008
ai_pc_5159:
    ai_call_ff $6AE1
ai_pc_515c:
    ai_if_pos_same_9d_short $515C, $5164
ai_pc_515e:
    ai_pos_save_9f
ai_pc_515f:
    ai_move_toward_e4 $0002, $0005
ai_pc_5162:
    ai_jmp_01_short $5162, $5168
ai_pc_5164:
    ai_pos_save_9f
ai_pc_5165:
    ai_move_toward_alt_fd $0002, $0005
ai_pc_5168:
    ai_dec_var2_20
ai_pc_5169:
    ai_if_var2_nz_04_short $5169, $516E
ai_pc_516b:
    ai_jmp_01_long $516B, $5170
ai_pc_516e:
    ai_if_tgt_not_within_64_56_short $516E, $5159
ai_pc_5170:
    ai_ret_00
ai_pc_5171:
    ai_if_tgt_not_within_48_51_short $5171, $518F
ai_pc_5173:
    ai_call_ff $6AE1
ai_pc_5176:
    ai_move_toward_alt_fd $0005, $0005
ai_pc_5179:
    ai_if_tgt_not_within_32_4c_short $5179, $518D
ai_pc_517b:
    ai_if_field_gt_30_short $0080, $006D, $0000, $517B, $518D
ai_pc_5180:
    ai_move_toward_e4 $0000, $0005
ai_pc_5183:
    ai_call_ff $6B23
ai_pc_5186:
    ai_if_field_gt_30_short $0080, $001D, $0000, $5186, $518D
ai_pc_518b:
    ai_pose_e2 $000C
ai_pc_518d:
    ai_jmp_01_short $518D, $5171
ai_pc_518f:
    ai_ret_00
ai_pc_5190:
    ai_if_tgt_not_within_48_51_short $5190, $51A3
ai_pc_5192:
    ai_call_ff $6AE1
ai_pc_5195:
    ai_if_pos_same_9d_short $5195, $519D
ai_pc_5197:
    ai_pos_save_9f
ai_pc_5198:
    ai_move_away_e6 $0002, $0005
ai_pc_519b:
    ai_jmp_01_short $519B, $51A1
ai_pc_519d:
    ai_pos_save_9f
ai_pc_519e:
    ai_move_away_alt_fe $0002, $0005
ai_pc_51a1:
    ai_jmp_01_short $51A1, $5190
ai_pc_51a3:
    ai_ret_00
ai_pc_51a4:
    ai_call_ff $51CC
ai_pc_51a7:
    ai_rnd_var3_2c $000F
ai_pc_51a9:
    ai_if_var3_nz_05_short $51A9, $51B0
ai_pc_51ab:
    ai_call_ff $675B
ai_pc_51ae:
    ai_jmp_01_short $51AE, $51C4
ai_pc_51b0:
    ai_call_ff $6AE1
ai_pc_51b3:
    ai_if_tgt_not_within_48_51_short $51B3, $51BA
ai_pc_51b5:
    ai_call_ff $51DA
ai_pc_51b8:
    ai_jmp_01_short $51B8, $51C4
ai_pc_51ba:
    ai_if_tgt_not_within_64_56_short $51BA, $51C1
ai_pc_51bc:
    ai_call_ff $51FE
ai_pc_51bf:
    ai_jmp_01_short $51BF, $51C4
ai_pc_51c1:
    ai_call_ff $5214
ai_pc_51c4:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $51C4, $51A7
ai_pc_51c9:
    ai_jmp_01_short $51C9, $51A7
