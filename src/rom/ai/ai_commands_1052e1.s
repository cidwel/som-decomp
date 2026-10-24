.setcpu "65816"
.segment "CODE"
.org $52E1
.include "ai_command_macros.inc"
ai_pc_03cc:
    ai_pose_e2 $0000
ai_pc_03ce:
    ai_rnd_var3_2c $0001
ai_pc_03d0:
    ai_if_var3_nz_05_short $03D0, $03D4
ai_pc_03d2:
    ai_pose_e2 $0000
ai_pc_03d4:
    ai_ret_00
ai_pc_03d5:
    ai_move_toward_e4 $0000, $0000
ai_pc_03d8:
    ai_if_field_gt_30_short $0080, $006D, $0000, $03D8, $03E3
ai_pc_03dd:
    ai_move_toward_e4 $0000, $0000
ai_pc_03e0:
    ai_call_ff $6B0F
ai_pc_03e3:
    ai_move_away_e6 $0001, $0000
ai_pc_03e6:
    ai_ret_00
ai_pc_03e7:
    ai_move_toward_e4 $0000, $0000
ai_pc_03ea:
    ai_if_field_gt_30_short $0080, $006D, $0000, $03EA, $03F5
ai_pc_03ef:
    ai_move_toward_e4 $0000, $0000
ai_pc_03f2:
    ai_call_ff $6B0F
ai_pc_03f5:
    ai_rnd_var3_2c $0001
ai_pc_03f7:
    ai_if_var3_nz_05_short $03F7, $03FE
ai_pc_03f9:
    ai_move_toward_e4 $0000, $0000
ai_pc_03fc:
    ai_jmp_01_short $03FC, $0401
ai_pc_03fe:
    ai_call_ff $04A6
ai_pc_0401:
    ai_ret_00
ai_pc_0402:
    ai_move_toward_e4 $0000, $0000
ai_pc_0405:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0405, $042D
ai_pc_040a:
    ai_if_tgt_not_lane_v64_66_short $040A, $0419
ai_pc_040c:
    ai_flash_fc
ai_pc_040d:
    ai_move_toward_e4 $0003, $0005
ai_pc_0410:
    ai_call_ff $6B0F
ai_pc_0413:
    ai_flash_fc
ai_pc_0414:
    ai_move_toward_e4 $0003, $0005
ai_pc_0417:
    ai_jmp_01_short $0417, $042B
ai_pc_0419:
    ai_if_tgt_not_lane_h64_6f_short $0419, $0428
ai_pc_041b:
    ai_flash_fc
ai_pc_041c:
    ai_move_toward_e4 $0003, $0005
ai_pc_041f:
    ai_call_ff $6B0F
ai_pc_0422:
    ai_flash_fc
ai_pc_0423:
    ai_move_toward_e4 $0003, $0005
ai_pc_0426:
    ai_jmp_01_short $0426, $042B
ai_pc_0428:
    ai_call_ff $0494
ai_pc_042b:
    ai_jmp_01_short $042B, $0430
ai_pc_042d:
    ai_move_toward_e4 $0000, $0000
ai_pc_0430:
    ai_ret_00
ai_pc_0431:
    ai_rnd_var3_2c $0007
ai_pc_0433:
    ai_if_var3_nz_05_short $0433, $046E
ai_pc_0435:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0435, $0458
ai_pc_043a:
    ai_if_tgt_not_lane_v64_66_short $043A, $0449
ai_pc_043c:
    ai_flash_fc
ai_pc_043d:
    ai_move_toward_e4 $0003, $0005
ai_pc_0440:
    ai_call_ff $6B0F
ai_pc_0443:
    ai_flash_fc
ai_pc_0444:
    ai_move_toward_e4 $0003, $0005
ai_pc_0447:
    ai_jmp_01_short $0447, $0456
ai_pc_0449:
    ai_if_tgt_not_lane_h64_6f_short $0449, $0456
ai_pc_044b:
    ai_flash_fc
ai_pc_044c:
    ai_move_toward_e4 $0003, $0005
ai_pc_044f:
    ai_call_ff $6B0F
ai_pc_0452:
    ai_flash_fc
ai_pc_0453:
    ai_move_toward_e4 $0003, $0005
ai_pc_0456:
    ai_jmp_01_short $0456, $046C
ai_pc_0458:
    ai_rnd_var3_2c $0003
ai_pc_045a:
    ai_if_var3_nz_05_short $045A, $046C
ai_pc_045c:
    ai_if_obj_outside_5f_short $0080, $045C, $0469
ai_pc_045f:
    ai_move_toward_e4 $0000, $0000
ai_pc_0462:
    ai_tgt2_cur_c1
ai_pc_0463:
    ai_cast_e9 $0007, $0007
ai_pc_0466:
    ai_tgt2_none_c0
ai_pc_0467:
    ai_jmp_01_short $0467, $046C
ai_pc_0469:
    ai_move_toward_e4 $0000, $0000
ai_pc_046c:
    ai_jmp_01_short $046C, $0471
ai_pc_046e:
    ai_call_ff $0494
ai_pc_0471:
    ai_ret_00
ai_pc_0472:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0472, $0493
ai_pc_0477:
    ai_move_toward_e4 $0000, $0000
ai_pc_047a:
    ai_if_tgt_not_within_32_4c_short $047A, $0481
ai_pc_047c:
    ai_move_toward_e4 $000E, $0000
ai_pc_047f:
    ai_jmp_01_short $047F, $0493
ai_pc_0481:
    ai_pose_e2 $0006
ai_pc_0483:
    ai_call_ff $6AE1
ai_pc_0486:
    ai_pose_e2 $0006
ai_pc_0488:
    ai_if_tgt_not_within_32_4c_short $0488, $0483
ai_pc_048a:
    ai_move_toward_e4 $0000, $0000
ai_pc_048d:
    ai_call_ff $6B0F
ai_pc_0490:
    ai_call_ff $04A6
ai_pc_0493:
    ai_ret_00
ai_pc_0494:
    ai_call_ff $6AE1
ai_pc_0497:
    ai_if_pos_same_9d_short $0497, $049F
ai_pc_0499:
    ai_pos_save_9f
ai_pc_049a:
    ai_move_toward_e4 $0004, $0000
ai_pc_049d:
    ai_jmp_01_short $049D, $04A3
ai_pc_049f:
    ai_pos_save_9f
ai_pc_04a0:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_04a3:
    ai_if_tgt_not_within_64_56_short $04A3, $0494
ai_pc_04a5:
    ai_ret_00
ai_pc_04a6:
    ai_if_tgt_not_within_48_51_short $04A6, $04B9
ai_pc_04a8:
    ai_call_ff $6AE1
ai_pc_04ab:
    ai_if_pos_same_9d_short $04AB, $04B3
ai_pc_04ad:
    ai_pos_save_9f
ai_pc_04ae:
    ai_move_away_e6 $0004, $0000
ai_pc_04b1:
    ai_jmp_01_short $04B1, $04B7
ai_pc_04b3:
    ai_pos_save_9f
ai_pc_04b4:
    ai_move_away_alt_fe $0004, $0000
ai_pc_04b7:
    ai_jmp_01_short $04B7, $04A6
ai_pc_04b9:
    ai_ret_00
ai_pc_04ba:
    ai_call_ff $04E9
ai_pc_04bd:
    ai_rnd_var3_2c $0007
ai_pc_04bf:
    ai_if_var3_nz_05_short $04BF, $04C6
ai_pc_04c1:
    ai_call_ff $66AB
ai_pc_04c4:
    ai_jmp_01_short $04C4, $04E1
ai_pc_04c6:
    ai_call_ff $6AE1
ai_pc_04c9:
    ai_if_tgt_not_within_32_4c_short $04C9, $04D0
ai_pc_04cb:
    ai_call_ff $0517
ai_pc_04ce:
    ai_jmp_01_short $04CE, $04E1
ai_pc_04d0:
    ai_if_tgt_not_within_48_51_short $04D0, $04D7
ai_pc_04d2:
    ai_call_ff $052C
ai_pc_04d5:
    ai_jmp_01_short $04D5, $04E1
ai_pc_04d7:
    ai_if_tgt_not_within_64_56_short $04D7, $04DE
ai_pc_04d9:
    ai_call_ff $053E
ai_pc_04dc:
    ai_jmp_01_short $04DC, $04E1
ai_pc_04de:
    ai_call_ff $0563
ai_pc_04e1:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $04E1, $04BD
ai_pc_04e6:
    ai_jmp_01_short $04E6, $04BD
