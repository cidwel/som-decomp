.setcpu "65816"
.segment "CODE"
.org $6159
.include "ai_command_macros.inc"
ai_pc_1244:
    ai_pose_e2 $0000
ai_pc_1246:
    ai_ret_00
ai_pc_1247:
    ai_move_toward_e4 $0000, $0005
ai_pc_124a:
    ai_if_field_gt_30_short $0080, $006D, $0000, $124A, $1274
ai_pc_124f:
    ai_if_word_gt_bd_short $0080, $0002, $0081, $0000, $124F, $126E
ai_pc_1255:
    ai_rnd_var3_2c $0002
ai_pc_1257:
    ai_if_var3_nz_05_short $1257, $1266
ai_pc_1259:
    ai_move_toward_e4 $0000, $0005
ai_pc_125c:
    ai_tgt2_cur_c1
ai_pc_125d:
    ai_cast_e9 $0004, $0008
ai_pc_1260:
    ai_tgt2_none_c0
ai_pc_1261:
    ai_turn_facing_e3 $0000, $0078
ai_pc_1264:
    ai_jmp_01_short $1264, $126C
ai_pc_1266:
    ai_move_toward_e4 $0000, $0005
ai_pc_1269:
    ai_call_ff $6B0F
ai_pc_126c:
    ai_jmp_01_short $126C, $1274
ai_pc_126e:
    ai_move_toward_e4 $0000, $0005
ai_pc_1271:
    ai_call_ff $6B0F
ai_pc_1274:
    ai_call_ff $1314
ai_pc_1277:
    ai_ret_00
ai_pc_1278:
    ai_move_toward_e4 $0000, $0005
ai_pc_127b:
    ai_if_field_gt_30_short $0080, $006D, $0000, $127B, $129F
ai_pc_1280:
    ai_rnd_var3_2c $0003
ai_pc_1282:
    ai_if_var3_nz_05_short $1282, $1299
ai_pc_1284:
    ai_if_obj_outside_5f_short $0080, $1284, $1294
ai_pc_1287:
    ai_move_toward_e4 $0000, $0005
ai_pc_128a:
    ai_tgt2_cur_c1
ai_pc_128b:
    ai_cast_e9 $0004, $0007
ai_pc_128e:
    ai_tgt2_none_c0
ai_pc_128f:
    ai_turn_facing_e3 $0000, $0078
ai_pc_1292:
    ai_jmp_01_short $1292, $1297
ai_pc_1294:
    ai_move_toward_e4 $0000, $0000
ai_pc_1297:
    ai_jmp_01_short $1297, $129F
ai_pc_1299:
    ai_move_toward_e4 $0000, $0005
ai_pc_129c:
    ai_call_ff $6B0F
ai_pc_129f:
    ai_call_ff $1327
ai_pc_12a2:
    ai_ret_00
ai_pc_12a3:
    ai_move_toward_e4 $0000, $0005
ai_pc_12a6:
    ai_if_field_gt_30_short $0080, $006D, $0000, $12A6, $12C6
ai_pc_12ab:
    ai_if_word_gt_bd_short $0080, $0002, $0081, $0000, $12AB, $12BE
ai_pc_12b1:
    ai_move_toward_e4 $0000, $0005
ai_pc_12b4:
    ai_tgt2_self_c4
ai_pc_12b5:
    ai_cast_e9 $0004, $000B
ai_pc_12b8:
    ai_tgt2_none_c0
ai_pc_12b9:
    ai_turn_facing_e3 $0000, $0078
ai_pc_12bc:
    ai_jmp_01_short $12BC, $12C4
ai_pc_12be:
    ai_call_ff $12DC
ai_pc_12c1:
    ai_call_ff $1302
ai_pc_12c4:
    ai_jmp_01_short $12C4, $12C9
ai_pc_12c6:
    ai_move_toward_e4 $0000, $0000
ai_pc_12c9:
    ai_ret_00
ai_pc_12ca:
    ai_call_ff $6AE1
ai_pc_12cd:
    ai_if_pos_same_9d_short $12CD, $12D5
ai_pc_12cf:
    ai_pos_save_9f
ai_pc_12d0:
    ai_move_toward_e4 $0002, $0000
ai_pc_12d3:
    ai_jmp_01_short $12D3, $12D9
ai_pc_12d5:
    ai_pos_save_9f
ai_pc_12d6:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_12d9:
    ai_if_tgt_not_within_64_56_short $12D9, $12CA
ai_pc_12db:
    ai_ret_00
ai_pc_12dc:
    ai_if_obj_outside_5f_short $0080, $12DC, $1301
ai_pc_12df:
    ai_if_no_ally_64_54_short $12DF, $1301
ai_pc_12e1:
    ai_tgt2_ally_d8
ai_pc_12e2:
    ai_if_word_gt_bd_short $0082, $0002, $0003, $0001, $12E2, $12F1
ai_pc_12e8:
    ai_cast_e9 $0004, $000B
ai_pc_12eb:
    ai_tgt2_none_c0
ai_pc_12ec:
    ai_turn_facing_e3 $0000, $0078
ai_pc_12ef:
    ai_jmp_01_short $12EF, $1301
ai_pc_12f1:
    ai_rnd_var3_2c $0003
ai_pc_12f3:
    ai_if_var3_nz_05_short $12F3, $12FF
ai_pc_12f5:
    ai_tgt2_cur_c1
ai_pc_12f6:
    ai_cast_e9 $0004, $000C
ai_pc_12f9:
    ai_tgt2_none_c0
ai_pc_12fa:
    ai_turn_facing_e3 $0000, $0078
ai_pc_12fd:
    ai_jmp_01_short $12FD, $1301
ai_pc_12ff:
    ai_pose_e2 $0005
ai_pc_1301:
    ai_ret_00
ai_pc_1302:
    ai_call_ff $6AE1
ai_pc_1305:
    ai_if_pos_same_9d_short $1305, $130D
ai_pc_1307:
    ai_pos_save_9f
ai_pc_1308:
    ai_move_toward_e4 $0002, $0000
ai_pc_130b:
    ai_jmp_01_short $130B, $1311
ai_pc_130d:
    ai_pos_save_9f
ai_pc_130e:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_1311:
    ai_if_tgt_not_within_32_4c_short $1311, $1302
ai_pc_1313:
    ai_ret_00
ai_pc_1314:
    ai_if_tgt_not_within_48_51_short $1314, $1326
ai_pc_1316:
    ai_call_ff $6AE1
ai_pc_1319:
    ai_move_away_alt_fe $0002, $0000
ai_pc_131c:
    ai_if_field_gt_30_short $0080, $006D, $0000, $131C, $1324
ai_pc_1321:
    ai_jmp_01_long $1321, $1326
ai_pc_1324:
    ai_jmp_01_short $1324, $1314
ai_pc_1326:
    ai_ret_00
ai_pc_1327:
    ai_if_tgt_not_within_48_51_short $1327, $1339
ai_pc_1329:
    ai_call_ff $6AE1
ai_pc_132c:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_132f:
    ai_if_field_gt_30_short $0080, $006D, $0000, $132F, $1337
ai_pc_1334:
    ai_jmp_01_long $1334, $1339
ai_pc_1337:
    ai_jmp_01_short $1337, $1327
ai_pc_1339:
    ai_ret_00
ai_pc_133a:
    ai_call_ff $1369
ai_pc_133d:
    ai_rnd_var3_2c $000F
ai_pc_133f:
    ai_if_var3_nz_05_short $133F, $1346
ai_pc_1341:
    ai_call_ff $65CA
ai_pc_1344:
    ai_jmp_01_short $1344, $1361
ai_pc_1346:
    ai_call_ff $6AE1
ai_pc_1349:
    ai_if_tgt_not_within_32_4c_short $1349, $1350
ai_pc_134b:
    ai_call_ff $1380
ai_pc_134e:
    ai_jmp_01_short $134E, $1361
ai_pc_1350:
    ai_if_tgt_not_within_48_51_short $1350, $1357
ai_pc_1352:
    ai_call_ff $13B3
ai_pc_1355:
    ai_jmp_01_short $1355, $1361
ai_pc_1357:
    ai_if_tgt_not_within_64_56_short $1357, $135E
ai_pc_1359:
    ai_call_ff $13DB
ai_pc_135c:
    ai_jmp_01_short $135C, $1361
ai_pc_135e:
    ai_call_ff $143E
ai_pc_1361:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $1361, $133D
ai_pc_1366:
    ai_jmp_01_short $1366, $133D
