.setcpu "65816"
.segment "CODE"
.org $6090
.include "ai_command_macros.inc"
ai_pc_117b:
    ai_pose_e2 $0000
ai_pc_117d:
    ai_set_var1_26 $000A
ai_pc_117f:
    ai_ret_00
ai_pc_1180:
    ai_move_toward_e4 $0000, $0005
ai_pc_1183:
    ai_call_ff $11D8
ai_pc_1186:
    ai_rnd_var3_2c $000F
ai_pc_1188:
    ai_if_var3_nz_05_short $1188, $11A6
ai_pc_118a:
    ai_move_toward_e4 $0000, $0005
ai_pc_118d:
    ai_rnd_var3_2c $0003
ai_pc_118f:
    ai_if_var3_nz_05_short $118F, $11A1
ai_pc_1191:
    ai_if_word_and_nz_ba_short $0081, $0010, $0080, $0000, $1191, $119C
ai_pc_1197:
    ai_call_ff $11AA
ai_pc_119a:
    ai_jmp_01_short $119A, $119F
ai_pc_119c:
    ai_call_ff $11BB
ai_pc_119f:
    ai_jmp_01_short $119F, $11A4
ai_pc_11a1:
    ai_call_ff $11BB
ai_pc_11a4:
    ai_jmp_01_short $11A4, $11A9
ai_pc_11a6:
    ai_move_toward_e4 $0000, $0005
ai_pc_11a9:
    ai_ret_00
ai_pc_11aa:
    ai_if_obj_outside_5f_short $0080, $11AA, $11B7
ai_pc_11ad:
    ai_tgt2_cur_c1
ai_pc_11ae:
    ai_cast_e9 $0001, $0014
ai_pc_11b1:
    ai_tgt2_none_c0
ai_pc_11b2:
    ai_move_toward_e4 $0000, $00B4
ai_pc_11b5:
    ai_jmp_01_short $11B5, $11BA
ai_pc_11b7:
    ai_move_toward_e4 $0000, $0005
ai_pc_11ba:
    ai_ret_00
ai_pc_11bb:
    ai_if_obj_outside_5f_short $0080, $11BB, $11D4
ai_pc_11be:
    ai_rnd_var3_2c $0001
ai_pc_11c0:
    ai_if_var3_nz_05_short $11C0, $11CC
ai_pc_11c2:
    ai_tgt2_cur_c1
ai_pc_11c3:
    ai_cast_e9 $0001, $0013
ai_pc_11c6:
    ai_tgt2_none_c0
ai_pc_11c7:
    ai_move_toward_e4 $0000, $00B4
ai_pc_11ca:
    ai_jmp_01_short $11CA, $11D4
ai_pc_11cc:
    ai_tgt2_cur_c1
ai_pc_11cd:
    ai_cast_e9 $0001, $0012
ai_pc_11d0:
    ai_tgt2_none_c0
ai_pc_11d1:
    ai_move_toward_e4 $0000, $00B4
ai_pc_11d4:
    ai_move_toward_e4 $0000, $0005
ai_pc_11d7:
    ai_ret_00
ai_pc_11d8:
    ai_if_obj_outside_5f_short $0080, $11D8, $11EE
ai_pc_11db:
    ai_if_var1_lt_17_short $0001, $11DB, $11EE
ai_pc_11de:
    ai_if_crowd_gt_f5_short $0002, $11DE, $11EB
ai_pc_11e1:
    ai_pose_e2 $0003
ai_pc_11e3:
    ai_move_toward_card_be $0000, $0005
ai_pc_11e6:
    ai_cmd43_ed $0016
ai_pc_11e8:
    ai_dec_var1_1f
ai_pc_11e9:
    ai_jmp_01_short $11E9, $11EE
ai_pc_11eb:
    ai_move_toward_e4 $0000, $0005
ai_pc_11ee:
    ai_ret_00
ai_pc_11ef:
    ai_call_ff $6AE1
ai_pc_11f2:
    ai_if_pos_same_9d_short $11F2, $11FA
ai_pc_11f4:
    ai_pos_save_9f
ai_pc_11f5:
    ai_move_toward_e4 $0004, $000F
ai_pc_11f8:
    ai_jmp_01_short $11F8, $11FE
ai_pc_11fa:
    ai_pos_save_9f
ai_pc_11fb:
    ai_move_toward_alt_fd $0004, $000F
ai_pc_11fe:
    ai_if_tgt_not_within_64_56_short $11FE, $11EF
ai_pc_1200:
    ai_ret_00
ai_pc_1201:
    ai_if_tgt_not_within_48_51_short $1201, $1214
ai_pc_1203:
    ai_call_ff $6AE1
ai_pc_1206:
    ai_if_pos_same_9d_short $1206, $120E
ai_pc_1208:
    ai_pos_save_9f
ai_pc_1209:
    ai_move_toward_e4 $0005, $000F
ai_pc_120c:
    ai_jmp_01_short $120C, $1212
ai_pc_120e:
    ai_pos_save_9f
ai_pc_120f:
    ai_move_toward_alt_fd $0005, $000F
ai_pc_1212:
    ai_jmp_01_short $1212, $1201
ai_pc_1214:
    ai_ret_00
ai_pc_1215:
    ai_call_ff $1244
ai_pc_1218:
    ai_rnd_var3_2c $000F
ai_pc_121a:
    ai_if_var3_nz_05_short $121A, $1221
ai_pc_121c:
    ai_call_ff $683C
ai_pc_121f:
    ai_jmp_01_short $121F, $123C
ai_pc_1221:
    ai_call_ff $6AE1
ai_pc_1224:
    ai_if_tgt_not_within_32_4c_short $1224, $122B
ai_pc_1226:
    ai_call_ff $1247
ai_pc_1229:
    ai_jmp_01_short $1229, $123C
ai_pc_122b:
    ai_if_tgt_not_within_48_51_short $122B, $1232
ai_pc_122d:
    ai_call_ff $1278
ai_pc_1230:
    ai_jmp_01_short $1230, $123C
ai_pc_1232:
    ai_if_tgt_not_within_64_56_short $1232, $1239
ai_pc_1234:
    ai_call_ff $12A3
ai_pc_1237:
    ai_jmp_01_short $1237, $123C
ai_pc_1239:
    ai_call_ff $12CA
ai_pc_123c:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $123C, $1218
ai_pc_1241:
    ai_jmp_01_short $1241, $1218
