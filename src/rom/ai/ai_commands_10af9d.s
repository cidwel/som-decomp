.setcpu "65816"
.segment "CODE"
.org $AF9D
.include "ai_command_macros.inc"
ai_pc_6088:
    ai_if_field_gt_30_short $0080, $002C, $00FE, $6088, $60BC
ai_pc_608d:
    ai_call_ff $5913
ai_pc_6090:
    ai_if_tgt_not_within_16_34_short $6090, $609F
ai_pc_6092:
    ai_move_toward_e4 $0003, $0005
ai_pc_6095:
    ai_swing_plain_df
ai_pc_6096:
    ai_move_toward_e4 $0013, $0000
ai_pc_6099:
    ai_charge_start_f3
ai_pc_609a:
    ai_call_ff $6145
ai_pc_609d:
    ai_jmp_01_short $609D, $60BA
ai_pc_609f:
    ai_if_tgt_not_within_48_51_short $609F, $60A6
ai_pc_60a1:
    ai_call_ff $6145
ai_pc_60a4:
    ai_jmp_01_short $60A4, $60BA
ai_pc_60a6:
    ai_if_tgt_not_within_64_56_short $60A6, $60B7
ai_pc_60a8:
    ai_if_field_gt_30_short $0080, $006D, $0000, $60A8, $60B2
ai_pc_60ad:
    ai_move_toward_e4 $0003, $0005
ai_pc_60b0:
    ai_jmp_01_short $60B0, $60B5
ai_pc_60b2:
    ai_move_toward_e4 $0000, $0005
ai_pc_60b5:
    ai_jmp_01_short $60B5, $60BA
ai_pc_60b7:
    ai_call_ff $6121
ai_pc_60ba:
    ai_jmp_01_short $60BA, $6088
ai_pc_60bc:
    ai_ret_00
ai_pc_60bd:
    ai_if_field_gt_30_short $0080, $002C, $00FE, $60BD, $60EE
ai_pc_60c2:
    ai_call_ff $5913
ai_pc_60c5:
    ai_if_tgt_not_within_32_4c_short $60C5, $60D1
ai_pc_60c7:
    ai_move_toward_e4 $0003, $0005
ai_pc_60ca:
    ai_swing_plain_df
ai_pc_60cb:
    ai_charge_start_f3
ai_pc_60cc:
    ai_call_ff $6178
ai_pc_60cf:
    ai_jmp_01_short $60CF, $60EC
ai_pc_60d1:
    ai_if_tgt_not_within_48_51_short $60D1, $60D8
ai_pc_60d3:
    ai_call_ff $6178
ai_pc_60d6:
    ai_jmp_01_short $60D6, $60EC
ai_pc_60d8:
    ai_if_tgt_not_within_64_56_short $60D8, $60E9
ai_pc_60da:
    ai_if_field_gt_30_short $0080, $006D, $0000, $60DA, $60E4
ai_pc_60df:
    ai_move_toward_e4 $0003, $0005
ai_pc_60e2:
    ai_jmp_01_short $60E2, $60E7
ai_pc_60e4:
    ai_move_toward_e4 $0000, $0005
ai_pc_60e7:
    ai_jmp_01_short $60E7, $60EC
ai_pc_60e9:
    ai_call_ff $6121
ai_pc_60ec:
    ai_jmp_01_short $60EC, $60BD
ai_pc_60ee:
    ai_ret_00
ai_pc_60ef:
    ai_if_field_gt_30_short $0080, $002C, $00FE, $60EF, $6120
ai_pc_60f4:
    ai_call_ff $5913
ai_pc_60f7:
    ai_if_tgt_not_within_32_4c_short $60F7, $6103
ai_pc_60f9:
    ai_move_toward_card_be $0003, $0005
ai_pc_60fc:
    ai_swing_plain_df
ai_pc_60fd:
    ai_charge_start_f3
ai_pc_60fe:
    ai_call_ff $61A8
ai_pc_6101:
    ai_jmp_01_short $6101, $611E
ai_pc_6103:
    ai_if_tgt_not_within_48_51_short $6103, $610A
ai_pc_6105:
    ai_call_ff $61A8
ai_pc_6108:
    ai_jmp_01_short $6108, $611E
ai_pc_610a:
    ai_if_tgt_not_within_64_56_short $610A, $611B
ai_pc_610c:
    ai_if_field_gt_30_short $0080, $006D, $0000, $610C, $6116
ai_pc_6111:
    ai_move_toward_e4 $0003, $0005
ai_pc_6114:
    ai_jmp_01_short $6114, $6119
ai_pc_6116:
    ai_move_toward_e4 $0000, $0005
ai_pc_6119:
    ai_jmp_01_short $6119, $611E
ai_pc_611b:
    ai_call_ff $6133
ai_pc_611e:
    ai_jmp_01_short $611E, $60EF
ai_pc_6120:
    ai_ret_00
ai_pc_6121:
    ai_call_ff $5913
ai_pc_6124:
    ai_if_pos_same_9d_short $6124, $612C
ai_pc_6126:
    ai_pos_save_9f
ai_pc_6127:
    ai_move_toward_e4 $000B, $000A
ai_pc_612a:
    ai_jmp_01_short $612A, $6130
ai_pc_612c:
    ai_pos_save_9f
ai_pc_612d:
    ai_move_toward_alt_fd $000B, $000A
ai_pc_6130:
    ai_if_tgt_not_within_64_56_short $6130, $6121
ai_pc_6132:
    ai_ret_00
ai_pc_6133:
    ai_call_ff $5913
ai_pc_6136:
    ai_if_pos_same_9d_short $6136, $613E
ai_pc_6138:
    ai_pos_save_9f
ai_pc_6139:
    ai_move_toward_card_be $000B, $000A
ai_pc_613c:
    ai_jmp_01_short $613C, $6142
ai_pc_613e:
    ai_pos_save_9f
ai_pc_613f:
    ai_move_toward_alt_fd $000B, $000A
ai_pc_6142:
    ai_if_tgt_not_within_64_56_short $6142, $6133
ai_pc_6144:
    ai_ret_00
ai_pc_6145:
    ai_set_var0_25 $0000
ai_pc_6147:
    ai_if_tgt_not_within_48_51_short $6147, $6177
ai_pc_6149:
    ai_call_ff $5913
ai_pc_614c:
    ai_if_tgt_not_within_16_34_short $614C, $6156
ai_pc_614e:
    ai_move_toward_e4 $0003, $0005
ai_pc_6151:
    ai_swing_plain_df
ai_pc_6152:
    ai_move_toward_e4 $0013, $0000
ai_pc_6155:
    ai_charge_start_f3
ai_pc_6156:
    ai_if_var0_nz_02_short $6156, $615E
ai_pc_6158:
    ai_call_ff $5978
ai_pc_615b:
    ai_inc_var0_1a
ai_pc_615c:
    ai_jmp_01_short $615C, $6175
ai_pc_615e:
    ai_if_var0_ne_0a_short $0001, $615E, $6167
ai_pc_6161:
    ai_call_ff $5985
ai_pc_6164:
    ai_inc_var0_1a
ai_pc_6165:
    ai_jmp_01_short $6165, $6175
ai_pc_6167:
    ai_if_var0_ne_0a_short $0002, $6167, $6170
ai_pc_616a:
    ai_call_ff $5985
ai_pc_616d:
    ai_inc_var0_1a
ai_pc_616e:
    ai_jmp_01_short $616E, $6175
ai_pc_6170:
    ai_call_ff $5978
ai_pc_6173:
    ai_set_var0_25 $0000
ai_pc_6175:
    ai_jmp_01_short $6175, $6147
ai_pc_6177:
    ai_ret_00
ai_pc_6178:
    ai_set_var0_25 $0000
ai_pc_617a:
    ai_if_tgt_not_within_48_51_short $617A, $61A7
ai_pc_617c:
    ai_call_ff $5913
ai_pc_617f:
    ai_if_tgt_not_within_16_34_short $617F, $6186
ai_pc_6181:
    ai_move_toward_e4 $0003, $0005
ai_pc_6184:
    ai_swing_plain_df
ai_pc_6185:
    ai_charge_start_f3
ai_pc_6186:
    ai_if_var0_nz_02_short $6186, $618E
ai_pc_6188:
    ai_call_ff $5978
ai_pc_618b:
    ai_inc_var0_1a
ai_pc_618c:
    ai_jmp_01_short $618C, $61A5
ai_pc_618e:
    ai_if_var0_ne_0a_short $0001, $618E, $6197
ai_pc_6191:
    ai_call_ff $5985
ai_pc_6194:
    ai_inc_var0_1a
ai_pc_6195:
    ai_jmp_01_short $6195, $61A5
ai_pc_6197:
    ai_if_var0_ne_0a_short $0002, $6197, $61A0
ai_pc_619a:
    ai_call_ff $5985
ai_pc_619d:
    ai_inc_var0_1a
ai_pc_619e:
    ai_jmp_01_short $619E, $61A5
ai_pc_61a0:
    ai_call_ff $5978
ai_pc_61a3:
    ai_set_var0_25 $0000
ai_pc_61a5:
    ai_jmp_01_short $61A5, $617A
ai_pc_61a7:
    ai_ret_00
ai_pc_61a8:
    ai_set_var0_25 $0000
ai_pc_61aa:
    ai_if_tgt_not_within_48_51_short $61AA, $61D7
ai_pc_61ac:
    ai_call_ff $5913
ai_pc_61af:
    ai_if_tgt_not_within_16_34_short $61AF, $61B6
ai_pc_61b1:
    ai_move_toward_card_be $0003, $0005
ai_pc_61b4:
    ai_swing_plain_df
ai_pc_61b5:
    ai_charge_start_f3
ai_pc_61b6:
    ai_if_var0_nz_02_short $61B6, $61BE
ai_pc_61b8:
    ai_call_ff $59AC
ai_pc_61bb:
    ai_inc_var0_1a
ai_pc_61bc:
    ai_jmp_01_short $61BC, $61D5
ai_pc_61be:
    ai_if_var0_ne_0a_short $0001, $61BE, $61C7
ai_pc_61c1:
    ai_call_ff $59B9
ai_pc_61c4:
    ai_inc_var0_1a
ai_pc_61c5:
    ai_jmp_01_short $61C5, $61D5
ai_pc_61c7:
    ai_if_var0_ne_0a_short $0002, $61C7, $61D0
ai_pc_61ca:
    ai_call_ff $59B9
ai_pc_61cd:
    ai_inc_var0_1a
ai_pc_61ce:
    ai_jmp_01_short $61CE, $61D5
ai_pc_61d0:
    ai_call_ff $59AC
ai_pc_61d3:
    ai_set_var0_25 $0000
ai_pc_61d5:
    ai_jmp_01_short $61D5, $61AA
ai_pc_61d7:
    ai_ret_00
ai_pc_61d8:
    ai_call_ff $590F
ai_pc_61db:
    ai_call_ff $5913
ai_pc_61de:
    ai_if_field_gt_30_short $0080, $002C, $00FE, $61DE, $61FF
ai_pc_61e3:
    ai_call_ff $5913
ai_pc_61e6:
    ai_if_field_gt_30_short $0080, $0064, $0000, $61E6, $61F0
ai_pc_61eb:
    ai_call_ff $6202
ai_pc_61ee:
    ai_jmp_01_short $61EE, $61FD
ai_pc_61f0:
    ai_if_field_gt_30_short $0080, $0064, $0002, $61F0, $61FA
ai_pc_61f5:
    ai_call_ff $623B
ai_pc_61f8:
    ai_jmp_01_short $61F8, $61FD
ai_pc_61fa:
    ai_call_ff $6271
ai_pc_61fd:
    ai_jmp_01_short $61FD, $61DE
ai_pc_61ff:
    ai_jmp_01_short $61FF, $61DB
