.setcpu "65816"
.segment "CODE"
.org $627E
.include "ai_command_macros.inc"
ai_pc_1369:
    ai_pose_e2 $0000
ai_pc_136b:
    ai_call_ff $6AE1
ai_pc_136e:
    ai_if_obj_outside_5f_short $0080, $136E, $137F
ai_pc_1371:
    ai_if_word_and_nz_ba_short $0081, $0010, $0080, $0000, $1371, $137F
ai_pc_1377:
    ai_move_toward_e4 $0000, $0005
ai_pc_137a:
    ai_tgt2_cur_c1
ai_pc_137b:
    ai_cast_e9 $0002, $0014
ai_pc_137e:
    ai_tgt2_none_c0
ai_pc_137f:
    ai_ret_00
ai_pc_1380:
    ai_move_toward_e4 $0000, $0005
ai_pc_1383:
    ai_set_var2_27 $0003
ai_pc_1385:
    ai_if_word_and_z_bb_short $0081, $0010, $0080, $0000, $1385, $13A4
ai_pc_138b:
    ai_call_ff $1450
ai_pc_138e:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_1392:
    ai_move_toward_e4 $0000, $0005
ai_pc_1395:
    ai_call_ff $6B0F
ai_pc_1398:
    ai_dec_var2_20
ai_pc_1399:
    ai_if_var2_nz_04_short $1399, $13A2
ai_pc_139b:
    ai_field_set_dc $0080, $006D, $0062
ai_pc_139f:
    ai_jmp_01_long $139F, $13A4
ai_pc_13a2:
    ai_jmp_01_short $13A2, $1385
ai_pc_13a4:
    ai_if_field_gt_30_short $0080, $006D, $0000, $13A4, $13AF
ai_pc_13a9:
    ai_move_toward_e4 $0000, $0005
ai_pc_13ac:
    ai_call_ff $6B0F
ai_pc_13af:
    ai_call_ff $146B
ai_pc_13b2:
    ai_ret_00
ai_pc_13b3:
    ai_move_toward_e4 $0000, $0005
ai_pc_13b6:
    ai_set_var2_27 $0003
ai_pc_13b8:
    ai_if_word_and_z_bb_short $0081, $0010, $0080, $0000, $13B8, $13D7
ai_pc_13be:
    ai_call_ff $1450
ai_pc_13c1:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_13c5:
    ai_move_toward_e4 $0000, $0005
ai_pc_13c8:
    ai_call_ff $6B0F
ai_pc_13cb:
    ai_dec_var2_20
ai_pc_13cc:
    ai_if_var2_nz_04_short $13CC, $13D5
ai_pc_13ce:
    ai_field_set_dc $0080, $006D, $0062
ai_pc_13d2:
    ai_jmp_01_long $13D2, $13D7
ai_pc_13d5:
    ai_jmp_01_short $13D5, $13B8
ai_pc_13d7:
    ai_call_ff $146B
ai_pc_13da:
    ai_ret_00
ai_pc_13db:
    ai_move_toward_e4 $0000, $0005
ai_pc_13de:
    ai_if_word_and_z_bb_short $0081, $0010, $0080, $0000, $13DE, $140A
ai_pc_13e4:
    ai_set_var2_27 $0003
ai_pc_13e6:
    ai_if_word_and_z_bb_short $0081, $0010, $0080, $0000, $13E6, $1405
ai_pc_13ec:
    ai_call_ff $1450
ai_pc_13ef:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_13f3:
    ai_move_toward_e4 $0000, $0005
ai_pc_13f6:
    ai_call_ff $6B0F
ai_pc_13f9:
    ai_dec_var2_20
ai_pc_13fa:
    ai_if_var2_nz_04_short $13FA, $1403
ai_pc_13fc:
    ai_field_set_dc $0080, $006D, $0062
ai_pc_1400:
    ai_jmp_01_long $1400, $1405
ai_pc_1403:
    ai_jmp_01_short $1403, $13E6
ai_pc_1405:
    ai_call_ff $146B
ai_pc_1408:
    ai_jmp_01_short $1408, $143D
ai_pc_140a:
    ai_move_toward_e4 $0000, $0005
ai_pc_140d:
    ai_if_obj_outside_5f_short $0080, $140D, $143A
ai_pc_1410:
    ai_rnd_var3_2c $000F
ai_pc_1412:
    ai_if_word_and_nz_ba_short $0081, $0010, $0080, $0000, $1412, $1429
ai_pc_1418:
    ai_if_var3_nz_05_short $1418, $1424
ai_pc_141a:
    ai_move_toward_e4 $0000, $0005
ai_pc_141d:
    ai_tgt2_cur_c1
ai_pc_141e:
    ai_cast_e9 $0002, $0014
ai_pc_1421:
    ai_tgt2_none_c0
ai_pc_1422:
    ai_jmp_01_short $1422, $1427
ai_pc_1424:
    ai_move_toward_e4 $0000, $0005
ai_pc_1427:
    ai_jmp_01_short $1427, $1438
ai_pc_1429:
    ai_if_var3_nz_05_short $1429, $1435
ai_pc_142b:
    ai_move_toward_e4 $0000, $0005
ai_pc_142e:
    ai_tgt2_cur_c1
ai_pc_142f:
    ai_cast_e9 $0002, $0012
ai_pc_1432:
    ai_tgt2_none_c0
ai_pc_1433:
    ai_jmp_01_short $1433, $1438
ai_pc_1435:
    ai_move_toward_e4 $0000, $0005
ai_pc_1438:
    ai_jmp_01_short $1438, $143D
ai_pc_143a:
    ai_move_toward_e4 $0000, $0005
ai_pc_143d:
    ai_ret_00
ai_pc_143e:
    ai_call_ff $6AE1
ai_pc_1441:
    ai_if_pos_same_9d_short $1441, $1449
ai_pc_1443:
    ai_pos_save_9f
ai_pc_1444:
    ai_move_toward_e4 $0004, $000A
ai_pc_1447:
    ai_jmp_01_short $1447, $144D
ai_pc_1449:
    ai_pos_save_9f
ai_pc_144a:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_144d:
    ai_if_tgt_not_within_64_56_short $144D, $143E
ai_pc_144f:
    ai_ret_00
ai_pc_1450:
    ai_call_ff $6AE1
ai_pc_1453:
    ai_if_pos_same_9d_short $1453, $145B
ai_pc_1455:
    ai_pos_save_9f
ai_pc_1456:
    ai_move_toward_e4 $0002, $0005
ai_pc_1459:
    ai_jmp_01_short $1459, $145F
ai_pc_145b:
    ai_pos_save_9f
ai_pc_145c:
    ai_move_toward_e4 $0002, $0005
ai_pc_145f:
    ai_if_word_and_nz_ba_short $0081, $0010, $0080, $0000, $145F, $1468
ai_pc_1465:
    ai_jmp_01_long $1465, $146A
ai_pc_1468:
    ai_if_tgt_not_within_32_4c_short $1468, $1450
ai_pc_146a:
    ai_ret_00
ai_pc_146b:
    ai_if_tgt_not_within_64_56_short $146B, $1488
ai_pc_146d:
    ai_call_ff $6AE1
ai_pc_1470:
    ai_if_word_and_z_bb_short $0081, $0010, $0080, $0000, $1470, $147B
ai_pc_1476:
    ai_jmp_01_long $1476, $1488
