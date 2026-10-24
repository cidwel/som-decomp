.setcpu "65816"
.segment "CODE"
.org $92B9
.include "ai_command_macros.inc"
ai_pc_43a4:
    ai_pose_e2 $000B
ai_pc_43a6:
    ai_ret_00
ai_pc_43a7:
    ai_move_toward_e4 $000E, $0000
ai_pc_43aa:
    ai_if_field_gt_30_short $0080, $006D, $0000, $43AA, $43B5
ai_pc_43af:
    ai_move_toward_e4 $0000, $0000
ai_pc_43b2:
    ai_call_ff $6B19
ai_pc_43b5:
    ai_move_toward_e4 $000E, $0000
ai_pc_43b8:
    ai_call_ff $44C9
ai_pc_43bb:
    ai_ret_00
ai_pc_43bc:
    ai_move_toward_e4 $0000, $0000
ai_pc_43bf:
    ai_if_field_gt_30_short $0080, $006D, $0000, $43BF, $43CA
ai_pc_43c4:
    ai_move_toward_e4 $0000, $0000
ai_pc_43c7:
    ai_call_ff $6B19
ai_pc_43ca:
    ai_move_toward_e4 $000E, $0000
ai_pc_43cd:
    ai_move_toward_e4 $000E, $0000
ai_pc_43d0:
    ai_rnd_var3_2c $000F
ai_pc_43d2:
    ai_if_var3_nz_05_short $43D2, $43DC
ai_pc_43d4:
    ai_tgt2_self_c4
ai_pc_43d5:
    ai_cast_e9 $0006, $0004
ai_pc_43d8:
    ai_tgt2_none_c0
ai_pc_43d9:
    ai_turn_facing_e3 $0000, $003C
ai_pc_43dc:
    ai_call_ff $44C9
ai_pc_43df:
    ai_ret_00
ai_pc_43e0:
    ai_move_toward_e4 $0000, $0000
ai_pc_43e3:
    ai_if_field_gt_30_short $0080, $006D, $0000, $43E3, $4401
ai_pc_43e8:
    ai_rnd_var3_2c $0001
ai_pc_43ea:
    ai_if_var3_nz_05_short $43EA, $43F6
ai_pc_43ec:
    ai_move_toward_e4 $0000, $0005
ai_pc_43ef:
    ai_pose_e2 $000B
ai_pc_43f1:
    ai_call_ff $6B19
ai_pc_43f4:
    ai_jmp_01_short $43F4, $4401
ai_pc_43f6:
    ai_flash_fc
ai_pc_43f7:
    ai_move_toward_e4 $0000, $0000
ai_pc_43fa:
    ai_call_ff $6B19
ai_pc_43fd:
    ai_flash_fc
ai_pc_43fe:
    ai_move_toward_e4 $0000, $0005
ai_pc_4401:
    ai_call_ff $44A3
ai_pc_4404:
    ai_ret_00
ai_pc_4405:
    ai_move_toward_e4 $0000, $0000
ai_pc_4408:
    ai_if_field_gt_30_long $0080, $006D, $0000, $4408, $4453
ai_pc_440e:
    ai_pose_e2 $0005
ai_pc_4410:
    ai_pose_e2 $0005
ai_pc_4412:
    ai_rnd_var3_2c $0001
ai_pc_4414:
    ai_if_var3_nz_05_short $4414, $442E
ai_pc_4416:
    ai_if_tgt_not_within_64_56_short $4416, $442C
ai_pc_4418:
    ai_call_ff $6AE1
ai_pc_441b:
    ai_pose_e2 $0007
ai_pc_441d:
    ai_if_tgt_not_within_32_4c_short $441D, $442A
ai_pc_441f:
    ai_pose_e2 $0008
ai_pc_4421:
    ai_move_toward_e4 $0000, $0000
ai_pc_4424:
    ai_call_ff $6B19
ai_pc_4427:
    ai_jmp_01_long $4427, $442C
ai_pc_442a:
    ai_jmp_01_short $442A, $4416
ai_pc_442c:
    ai_jmp_01_short $442C, $4451
ai_pc_442e:
    ai_call_ff $6AE1
ai_pc_4431:
    ai_pose_e2 $0007
ai_pc_4433:
    ai_rnd_var3_2c $000F
ai_pc_4435:
    ai_if_var3_nz_05_short $4435, $442E
ai_pc_4437:
    ai_pose_e2 $0008
ai_pc_4439:
    ai_if_obj_outside_5f_short $0080, $4439, $4448
ai_pc_443c:
    ai_rnd_var3_2c $000F
ai_pc_443e:
    ai_if_var3_nz_05_short $443E, $4448
ai_pc_4440:
    ai_tgt2_cur_c1
ai_pc_4441:
    ai_cast_e9 $0006, $0002
ai_pc_4444:
    ai_tgt2_none_c0
ai_pc_4445:
    ai_turn_facing_e3 $0000, $003C
ai_pc_4448:
    ai_call_ff $4484
ai_pc_444b:
    ai_move_toward_e4 $0000, $0000
ai_pc_444e:
    ai_call_ff $6B19
ai_pc_4451:
    ai_jmp_01_short $4451, $4456
ai_pc_4453:
    ai_move_toward_e4 $0000, $0000
ai_pc_4456:
    ai_ret_00
ai_pc_4457:
    ai_call_ff $44EA
ai_pc_445a:
    ai_call_ff $4484
ai_pc_445d:
    ai_if_field_gt_30_short $0080, $006D, $0000, $445D, $4483
ai_pc_4462:
    ai_if_tgt_not_lane_v64_66_short $4462, $4471
ai_pc_4464:
    ai_flash_fc
ai_pc_4465:
    ai_move_toward_card_be $0000, $0000
ai_pc_4468:
    ai_call_ff $6B19
ai_pc_446b:
    ai_flash_fc
ai_pc_446c:
    ai_move_toward_e4 $0000, $0005
ai_pc_446f:
    ai_jmp_01_short $446F, $4483
ai_pc_4471:
    ai_if_tgt_not_lane_h64_6f_short $4471, $4480
ai_pc_4473:
    ai_flash_fc
ai_pc_4474:
    ai_move_toward_card_be $0000, $0000
ai_pc_4477:
    ai_call_ff $6B19
ai_pc_447a:
    ai_flash_fc
ai_pc_447b:
    ai_move_toward_e4 $0000, $0005
ai_pc_447e:
    ai_jmp_01_short $447E, $4483
ai_pc_4480:
    ai_move_toward_e4 $0000, $0000
ai_pc_4483:
    ai_ret_00
ai_pc_4484:
    ai_call_ff $6AE1
ai_pc_4487:
    ai_if_pos_same_9d_short $4487, $448F
ai_pc_4489:
    ai_pos_save_9f
ai_pc_448a:
    ai_move_toward_card_be $0001, $000F
ai_pc_448d:
    ai_jmp_01_short $448D, $4493
ai_pc_448f:
    ai_pos_save_9f
ai_pc_4490:
    ai_move_toward_alt_fd $0001, $000F
ai_pc_4493:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4493, $44A0
ai_pc_4498:
    ai_if_tgt_not_within_32_4c_short $4498, $44A0
ai_pc_449a:
    ai_move_toward_e4 $0000, $0000
ai_pc_449d:
    ai_call_ff $6B19
ai_pc_44a0:
    ai_if_tgt_not_within_32_4c_short $44A0, $4484
ai_pc_44a2:
    ai_ret_00
ai_pc_44a3:
    ai_if_tgt_not_within_48_51_short $44A3, $44C8
ai_pc_44a5:
    ai_call_ff $6AE1
ai_pc_44a8:
    ai_if_pos_same_9d_short $44A8, $44B0
ai_pc_44aa:
    ai_pos_save_9f
ai_pc_44ab:
    ai_move_toward_card_be $0005, $000A
ai_pc_44ae:
    ai_jmp_01_short $44AE, $44B4
ai_pc_44b0:
    ai_pos_save_9f
ai_pc_44b1:
    ai_move_toward_alt_fd $0005, $000A
ai_pc_44b4:
    ai_if_field_gt_30_short $0080, $006D, $0000, $44B4, $44C6
ai_pc_44b9:
    ai_if_tgt_not_within_32_4c_short $44B9, $44C6
ai_pc_44bb:
    ai_flash_fc
ai_pc_44bc:
    ai_move_toward_card_be $0000, $0000
ai_pc_44bf:
    ai_call_ff $6B19
ai_pc_44c2:
    ai_flash_fc
ai_pc_44c3:
    ai_move_toward_e4 $0000, $0005
ai_pc_44c6:
    ai_jmp_01_short $44C6, $44A3
ai_pc_44c8:
    ai_ret_00
ai_pc_44c9:
    ai_if_tgt_not_within_48_51_short $44C9, $44E9
ai_pc_44cb:
    ai_call_ff $6AE1
ai_pc_44ce:
    ai_if_pos_same_9d_short $44CE, $44D6
ai_pc_44d0:
    ai_pos_save_9f
ai_pc_44d1:
    ai_move_away_card_bf $0001, $000F
ai_pc_44d4:
    ai_jmp_01_short $44D4, $44DA
ai_pc_44d6:
    ai_pos_save_9f
ai_pc_44d7:
    ai_move_away_alt_fe $0001, $000F
ai_pc_44da:
    ai_if_field_gt_30_short $0080, $006D, $0000, $44DA, $44E7
ai_pc_44df:
    ai_if_tgt_not_within_32_4c_short $44DF, $44E7
ai_pc_44e1:
    ai_move_toward_e4 $0000, $0000
ai_pc_44e4:
    ai_call_ff $6B19
ai_pc_44e7:
    ai_jmp_01_short $44E7, $44C9
ai_pc_44e9:
    ai_ret_00
ai_pc_44ea:
    ai_if_field_gt_30_short $0080, $001D, $0000, $44EA, $44F7
ai_pc_44ef:
    ai_tgt2_self_c4
ai_pc_44f0:
    ai_cast_e9 $0006, $000F
ai_pc_44f3:
    ai_tgt2_none_c0
ai_pc_44f4:
    ai_turn_facing_e3 $0000, $003C
ai_pc_44f7:
    ai_ret_00
ai_pc_44f8:
    ai_if_word_gt_bd_short $0080, $0002, $004D, $0000, $44F8, $4521
ai_pc_44fe:
    ai_field_set_dc $0080, $0006, $0063
ai_pc_4502:
    ai_call_ff $6AE1
ai_pc_4505:
    ai_if_pos_same_9d_short $4505, $450D
ai_pc_4507:
    ai_pos_save_9f
ai_pc_4508:
    ai_move_toward_card_be $0001, $000F
ai_pc_450b:
    ai_jmp_01_short $450B, $4511
ai_pc_450d:
    ai_pos_save_9f
ai_pc_450e:
    ai_move_toward_alt_fd $0001, $000F
ai_pc_4511:
    ai_if_tgt_not_within_16_34_short $4511, $4502
ai_pc_4513:
    ai_tgt2_cur_c1
ai_pc_4514:
    ai_cast_e9 $0006, $001F
ai_pc_4517:
    ai_tgt2_none_c0
ai_pc_4518:
    ai_move_toward_e4 $0000, $00B4
ai_pc_451b:
    ai_cmd81_ef $0005, $00FE
ai_pc_451e:
    ai_move_toward_e4 $0000, $0005
ai_pc_4521:
    ai_ret_00
ai_pc_4522:
    ai_call_ff $4547
ai_pc_4525:
    ai_rnd_var3_2c $000F
ai_pc_4527:
    ai_if_var3_nz_05_short $4527, $452E
ai_pc_4529:
    ai_call_ff $690F
ai_pc_452c:
    ai_jmp_01_short $452C, $453F
ai_pc_452e:
    ai_call_ff $6AE1
ai_pc_4531:
    ai_if_word_gt_bd_short $0080, $0002, $0014, $0000, $4531, $453C
ai_pc_4537:
    ai_call_ff $4671
ai_pc_453a:
    ai_jmp_01_short $453A, $453F
ai_pc_453c:
    ai_call_ff $455D
ai_pc_453f:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $453F, $4525
ai_pc_4544:
    ai_jmp_01_short $4544, $4525
