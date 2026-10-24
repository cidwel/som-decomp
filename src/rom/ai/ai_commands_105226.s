.setcpu "65816"
.segment "CODE"
.org $5226
.include "ai_command_macros.inc"
ai_pc_0311:
    ai_pose_e2 $0006
ai_pc_0313:
    ai_call_ff $6AE1
ai_pc_0316:
    ai_pose_e2 $0006
ai_pc_0318:
    ai_if_word_gt_bd_short $0080, $0002, $0023, $0000, $0318, $0321
ai_pc_031e:
    ai_jmp_01_long $031E, $0323
ai_pc_0321:
    ai_if_tgt_not_within_32_4c_short $0321, $0313
ai_pc_0323:
    ai_pose_e2 $0000
ai_pc_0325:
    ai_ret_00
ai_pc_0326:
    ai_move_toward_e4 $0000, $0000
ai_pc_0329:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0329, $0334
ai_pc_032e:
    ai_move_toward_e4 $0000, $0000
ai_pc_0331:
    ai_call_ff $6B0F
ai_pc_0334:
    ai_call_ff $037E
ai_pc_0337:
    ai_ret_00
ai_pc_0338:
    ai_move_toward_e4 $0000, $0000
ai_pc_033b:
    ai_if_field_gt_30_short $0080, $006D, $0000, $033B, $0346
ai_pc_0340:
    ai_move_toward_e4 $0000, $0000
ai_pc_0343:
    ai_call_ff $6B0F
ai_pc_0346:
    ai_call_ff $037E
ai_pc_0349:
    ai_ret_00
ai_pc_034a:
    ai_move_toward_e4 $0000, $0000
ai_pc_034d:
    ai_if_obj_outside_5f_short $0080, $034D, $0368
ai_pc_0350:
    ai_if_word_and_nz_ba_short $0081, $0010, $0010, $0000, $0350, $0368
ai_pc_0356:
    ai_rnd_var3_2c $000F
ai_pc_0358:
    ai_if_var3_nz_05_short $0358, $0366
ai_pc_035a:
    ai_tgt2_cur_c1
ai_pc_035b:
    ai_cast_e9 $0003, $001E
ai_pc_035e:
    ai_tgt2_none_c0
ai_pc_035f:
    ai_move_toward_e4 $0000, $0000
ai_pc_0362:
    ai_pose_e2 $0004
ai_pc_0364:
    ai_jmp_01_short $0364, $0368
ai_pc_0366:
    ai_pose_e2 $0000
ai_pc_0368:
    ai_call_ff $036C
ai_pc_036b:
    ai_ret_00
ai_pc_036c:
    ai_call_ff $6AE1
ai_pc_036f:
    ai_if_pos_same_9d_short $036F, $0377
ai_pc_0371:
    ai_pos_save_9f
ai_pc_0372:
    ai_move_toward_e4 $0004, $000A
ai_pc_0375:
    ai_jmp_01_short $0375, $037B
ai_pc_0377:
    ai_pos_save_9f
ai_pc_0378:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_037b:
    ai_if_tgt_not_within_32_4c_short $037B, $036C
ai_pc_037d:
    ai_ret_00
ai_pc_037e:
    ai_if_tgt_not_within_48_51_short $037E, $0391
ai_pc_0380:
    ai_call_ff $6AE1
ai_pc_0383:
    ai_if_pos_same_9d_short $0383, $038B
ai_pc_0385:
    ai_pos_save_9f
ai_pc_0386:
    ai_move_away_e6 $0004, $000A
ai_pc_0389:
    ai_jmp_01_short $0389, $038F
ai_pc_038b:
    ai_pos_save_9f
ai_pc_038c:
    ai_move_away_alt_fe $0004, $000A
ai_pc_038f:
    ai_jmp_01_short $038F, $037E
ai_pc_0391:
    ai_ret_00
ai_pc_0392:
    ai_call_ff $03CC
ai_pc_0395:
    ai_if_word_gt_bd_short $0080, $0002, $000F, $0000, $0395, $03A0
ai_pc_039b:
    ai_call_ff $0472
ai_pc_039e:
    ai_jmp_01_short $039E, $03C4
ai_pc_03a0:
    ai_rnd_var3_2c $0007
ai_pc_03a2:
    ai_if_var3_nz_05_short $03A2, $03A9
ai_pc_03a4:
    ai_call_ff $67DF
ai_pc_03a7:
    ai_jmp_01_short $03A7, $03C4
ai_pc_03a9:
    ai_call_ff $6AE1
ai_pc_03ac:
    ai_if_tgt_not_within_16_34_short $03AC, $03B3
ai_pc_03ae:
    ai_call_ff $03D5
ai_pc_03b1:
    ai_jmp_01_short $03B1, $03C4
ai_pc_03b3:
    ai_if_tgt_not_within_32_4c_short $03B3, $03BA
ai_pc_03b5:
    ai_call_ff $03E7
ai_pc_03b8:
    ai_jmp_01_short $03B8, $03C4
ai_pc_03ba:
    ai_if_tgt_not_within_64_56_short $03BA, $03C1
ai_pc_03bc:
    ai_call_ff $0402
ai_pc_03bf:
    ai_jmp_01_short $03BF, $03C4
ai_pc_03c1:
    ai_call_ff $0431
ai_pc_03c4:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $03C4, $0395
ai_pc_03c9:
    ai_jmp_01_short $03C9, $0395
