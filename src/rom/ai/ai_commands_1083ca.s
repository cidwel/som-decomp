.setcpu "65816"
.segment "CODE"
.org $83CA
.include "ai_command_macros.inc"
ai_pc_34b5:
    ai_pose_e2 $0000
ai_pc_34b7:
    ai_set_var1_26 $000A
ai_pc_34b9:
    ai_rnd_var2_2b $0002
ai_pc_34bb:
    ai_ret_00
ai_pc_34bc:
    ai_move_toward_e4 $0000, $0000
ai_pc_34bf:
    ai_if_field_gt_30_short $0080, $006D, $0000, $34BF, $34C7
ai_pc_34c4:
    ai_call_ff $3525
ai_pc_34c7:
    ai_if_crowd_gt_f5_short $0001, $34C7, $34E2
ai_pc_34ca:
    ai_if_var1_nz_03_short $34CA, $34DD
ai_pc_34cc:
    ai_move_toward_e4 $0000, $0000
ai_pc_34cf:
    ai_rnd_var3_2c $0002
ai_pc_34d1:
    ai_if_var3_nz_05_short $34D1, $34D8
ai_pc_34d3:
    ai_call_ff $48B9
ai_pc_34d6:
    ai_jmp_01_short $34D6, $34DB
ai_pc_34d8:
    ai_move_toward_e4 $0000, $0000
ai_pc_34db:
    ai_jmp_01_short $34DB, $34E0
ai_pc_34dd:
    ai_call_ff $359C
ai_pc_34e0:
    ai_jmp_01_short $34E0, $34E5
ai_pc_34e2:
    ai_call_ff $359C
ai_pc_34e5:
    ai_ret_00
ai_pc_34e6:
    ai_move_toward_e4 $0000, $0000
ai_pc_34e9:
    ai_call_ff $3577
ai_pc_34ec:
    ai_if_field_gt_30_short $0080, $006D, $0000, $34EC, $350D
ai_pc_34f1:
    ai_move_toward_e4 $0000, $0000
ai_pc_34f4:
    ai_if_crowd_gt_f5_short $0001, $34F4, $34FC
ai_pc_34f7:
    ai_call_ff $358B
ai_pc_34fa:
    ai_jmp_01_short $34FA, $350D
ai_pc_34fc:
    ai_rnd_var3_2c $0007
ai_pc_34fe:
    ai_if_var3_nz_05_short $34FE, $350A
ai_pc_3500:
    ai_rnd_var3_2c $0001
ai_pc_3502:
    ai_if_var3_nz_05_short $3502, $3507
ai_pc_3504:
    ai_call_ff $48B9
ai_pc_3507:
    ai_move_toward_e4 $0000, $0000
ai_pc_350a:
    ai_move_toward_e4 $0000, $0000
ai_pc_350d:
    ai_move_toward_e4 $0000, $0000
ai_pc_3510:
    ai_ret_00
ai_pc_3511:
    ai_set_var3_28 $0004
ai_pc_3513:
    ai_call_ff $6AE1
ai_pc_3516:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_3519:
    ai_dec_var3_21
ai_pc_351a:
    ai_if_var3_nz_05_short $351A, $3522
ai_pc_351c:
    ai_move_toward_e4 $0000, $003C
ai_pc_351f:
    ai_jmp_01_long $351F, $3524
ai_pc_3522:
    ai_if_tgt_not_within_64_56_short $3522, $3513
ai_pc_3524:
    ai_ret_00
ai_pc_3525:
    ai_if_word_and_nz_ba_short $0081, $0010, $0000, $0002, $3525, $354E
ai_pc_352b:
    ai_if_tgt_not_lane_v48_68_short $352B, $353A
ai_pc_352d:
    ai_flash_fc
ai_pc_352e:
    ai_move_toward_card_be $0000, $0000
ai_pc_3531:
    ai_call_ff $6B19
ai_pc_3534:
    ai_flash_fc
ai_pc_3535:
    ai_move_toward_e4 $0000, $0000
ai_pc_3538:
    ai_jmp_01_short $3538, $354C
ai_pc_353a:
    ai_if_tgt_not_lane_h48_71_short $353A, $3549
ai_pc_353c:
    ai_flash_fc
ai_pc_353d:
    ai_move_toward_card_be $0000, $0000
ai_pc_3540:
    ai_call_ff $6B19
ai_pc_3543:
    ai_flash_fc
ai_pc_3544:
    ai_move_toward_e4 $0000, $0000
ai_pc_3547:
    ai_jmp_01_short $3547, $354C
ai_pc_3549:
    ai_move_toward_e4 $0000, $0000
ai_pc_354c:
    ai_jmp_01_short $354C, $3576
ai_pc_354e:
    ai_if_word_and_nz_ba_short $0081, $0010, $0000, $0020, $354E, $3573
ai_pc_3554:
    ai_if_tgt_not_lane_v48_68_short $3554, $3561
ai_pc_3556:
    ai_move_toward_card_be $0000, $0000
ai_pc_3559:
    ai_call_ff $6B19
ai_pc_355c:
    ai_move_toward_e4 $0000, $0000
ai_pc_355f:
    ai_jmp_01_short $355F, $3571
ai_pc_3561:
    ai_if_tgt_not_lane_h48_71_short $3561, $356E
ai_pc_3563:
    ai_move_toward_card_be $0000, $0000
ai_pc_3566:
    ai_call_ff $6B19
ai_pc_3569:
    ai_move_toward_e4 $0000, $0000
ai_pc_356c:
    ai_jmp_01_short $356C, $3571
ai_pc_356e:
    ai_move_toward_e4 $0000, $0000
ai_pc_3571:
    ai_jmp_01_short $3571, $3576
ai_pc_3573:
    ai_move_toward_e4 $0000, $0000
ai_pc_3576:
    ai_ret_00
ai_pc_3577:
    ai_if_obj_outside_5f_short $0080, $3577, $358A
ai_pc_357a:
    ai_if_var1_lt_17_short $0001, $357A, $358A
ai_pc_357d:
    ai_if_crowd_gt_f5_short $0002, $357D, $3587
ai_pc_3580:
    ai_pose_e2 $0004
ai_pc_3582:
    ai_cmd43_ed $001E
ai_pc_3584:
    ai_dec_var1_1f
ai_pc_3585:
    ai_jmp_01_short $3585, $358A
ai_pc_3587:
    ai_move_toward_e4 $0000, $0000
ai_pc_358a:
    ai_ret_00
ai_pc_358b:
    ai_set_var3_28 $0004
ai_pc_358d:
    ai_call_ff $6AE1
ai_pc_3590:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_3593:
    ai_dec_var3_21
ai_pc_3594:
    ai_if_var3_nz_05_short $3594, $3599
ai_pc_3596:
    ai_jmp_01_long $3596, $359B
ai_pc_3599:
    ai_if_tgt_not_within_48_51_short $3599, $358D
ai_pc_359b:
    ai_ret_00
ai_pc_359c:
    ai_set_var3_28 $0004
ai_pc_359e:
    ai_if_tgt_not_within_48_51_short $359E, $35AE
ai_pc_35a0:
    ai_call_ff $6AE1
ai_pc_35a3:
    ai_move_toward_alt_fd $0005, $000A
ai_pc_35a6:
    ai_dec_var3_21
ai_pc_35a7:
    ai_if_var3_nz_05_short $35A7, $35AC
ai_pc_35a9:
    ai_jmp_01_long $35A9, $35AE
ai_pc_35ac:
    ai_jmp_01_short $35AC, $359E
ai_pc_35ae:
    ai_ret_00
ai_pc_35af:
    ai_call_ff $35DE
ai_pc_35b2:
    ai_rnd_var3_2c $000F
ai_pc_35b4:
    ai_if_var3_nz_05_short $35B4, $35BB
ai_pc_35b6:
    ai_call_ff $683C
ai_pc_35b9:
    ai_jmp_01_short $35B9, $35D6
ai_pc_35bb:
    ai_call_ff $6AE1
ai_pc_35be:
    ai_if_tgt_not_within_16_34_short $35BE, $35C5
ai_pc_35c0:
    ai_call_ff $35E1
ai_pc_35c3:
    ai_jmp_01_short $35C3, $35D6
ai_pc_35c5:
    ai_if_tgt_not_within_48_51_short $35C5, $35CC
ai_pc_35c7:
    ai_call_ff $3604
ai_pc_35ca:
    ai_jmp_01_short $35CA, $35D6
ai_pc_35cc:
    ai_if_tgt_not_within_64_56_short $35CC, $35D3
ai_pc_35ce:
    ai_call_ff $3624
ai_pc_35d1:
    ai_jmp_01_short $35D1, $35D6
ai_pc_35d3:
    ai_call_ff $3684
ai_pc_35d6:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $35D6, $35B2
ai_pc_35db:
    ai_jmp_01_short $35DB, $35B2
