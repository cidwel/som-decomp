.setcpu "65816"
.segment "CODE"
.org $7454
.include "ai_command_macros.inc"
ai_pc_253f:
    ai_pose_e2 $0001
ai_pc_2541:
    ai_call_ff $25DF
ai_pc_2544:
    ai_ret_00
ai_pc_2545:
    ai_move_toward_e4 $0000, $0000
ai_pc_2548:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2548, $2564
ai_pc_254d:
    ai_rnd_var3_2c $0001
ai_pc_254f:
    ai_if_var3_nz_05_short $254F, $255E
ai_pc_2551:
    ai_flash_fc
ai_pc_2552:
    ai_move_toward_e4 $0000, $0000
ai_pc_2555:
    ai_call_ff $6B0F
ai_pc_2558:
    ai_flash_fc
ai_pc_2559:
    ai_move_toward_e4 $0000, $0005
ai_pc_255c:
    ai_jmp_01_short $255C, $2564
ai_pc_255e:
    ai_move_toward_e4 $0000, $0000
ai_pc_2561:
    ai_call_ff $6B0F
ai_pc_2564:
    ai_move_toward_e4 $000E, $0000
ai_pc_2567:
    ai_move_toward_e4 $000E, $0000
ai_pc_256a:
    ai_call_ff $25CB
ai_pc_256d:
    ai_ret_00
ai_pc_256e:
    ai_move_toward_e4 $0000, $0000
ai_pc_2571:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2571, $257C
ai_pc_2576:
    ai_move_toward_e4 $0000, $0000
ai_pc_2579:
    ai_call_ff $6B0F
ai_pc_257c:
    ai_move_toward_e4 $000E, $0000
ai_pc_257f:
    ai_call_ff $25CB
ai_pc_2582:
    ai_ret_00
ai_pc_2583:
    ai_move_toward_e4 $0000, $0000
ai_pc_2586:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2586, $25B5
ai_pc_258b:
    ai_rnd_var3_2c $0007
ai_pc_258d:
    ai_if_var3_nz_05_short $258D, $25AD
ai_pc_258f:
    ai_call_ff $6AE1
ai_pc_2592:
    ai_if_pos_same_9d_short $2592, $259A
ai_pc_2594:
    ai_pos_save_9f
ai_pc_2595:
    ai_move_toward_e4 $0002, $0005
ai_pc_2598:
    ai_jmp_01_short $2598, $259E
ai_pc_259a:
    ai_pos_save_9f
ai_pc_259b:
    ai_move_toward_e4 $0002, $0005
ai_pc_259e:
    ai_if_tgt_not_within_32_4c_short $259E, $258F
ai_pc_25a0:
    ai_flash_fc
ai_pc_25a1:
    ai_move_toward_e4 $0000, $0000
ai_pc_25a4:
    ai_call_ff $6B0F
ai_pc_25a7:
    ai_flash_fc
ai_pc_25a8:
    ai_move_toward_e4 $0000, $0005
ai_pc_25ab:
    ai_jmp_01_short $25AB, $25B3
ai_pc_25ad:
    ai_move_toward_e4 $0000, $0000
ai_pc_25b0:
    ai_call_ff $25DF
ai_pc_25b3:
    ai_jmp_01_short $25B3, $25B8
ai_pc_25b5:
    ai_move_toward_e4 $0000, $0000
ai_pc_25b8:
    ai_ret_00
ai_pc_25b9:
    ai_call_ff $6AE1
ai_pc_25bc:
    ai_if_pos_same_9d_short $25BC, $25C4
ai_pc_25be:
    ai_pos_save_9f
ai_pc_25bf:
    ai_move_toward_e4 $0001, $0005
ai_pc_25c2:
    ai_jmp_01_short $25C2, $25C8
ai_pc_25c4:
    ai_pos_save_9f
ai_pc_25c5:
    ai_move_toward_alt_fd $0001, $0005
ai_pc_25c8:
    ai_if_tgt_not_within_64_56_short $25C8, $25B9
ai_pc_25ca:
    ai_ret_00
ai_pc_25cb:
    ai_if_tgt_not_within_48_51_short $25CB, $25DE
ai_pc_25cd:
    ai_call_ff $6AE1
ai_pc_25d0:
    ai_if_pos_same_9d_short $25D0, $25D8
ai_pc_25d2:
    ai_pos_save_9f
ai_pc_25d3:
    ai_move_away_e6 $0001, $0005
ai_pc_25d6:
    ai_jmp_01_short $25D6, $25DC
ai_pc_25d8:
    ai_pos_save_9f
ai_pc_25d9:
    ai_move_away_alt_fe $0001, $0005
ai_pc_25dc:
    ai_jmp_01_short $25DC, $25CB
ai_pc_25de:
    ai_ret_00
ai_pc_25df:
    ai_if_field_gt_30_short $0080, $0038, $0000, $25DF, $25E9
ai_pc_25e4:
    ai_tgt2_self_c4
ai_pc_25e5:
    ai_cast_e9 $0006, $0022
ai_pc_25e8:
    ai_tgt2_none_c0
ai_pc_25e9:
    ai_ret_00
ai_pc_25ea:
    ai_call_ff $2620
ai_pc_25ed:
    ai_rnd_var3_2c $000F
ai_pc_25ef:
    ai_if_var3_nz_05_short $25EF, $25F6
ai_pc_25f1:
    ai_call_ff $672F
ai_pc_25f4:
    ai_jmp_01_short $25F4, $2618
ai_pc_25f6:
    ai_call_ff $6AE1
ai_pc_25f9:
    ai_if_tgt_not_within_16_34_short $25F9, $2600
ai_pc_25fb:
    ai_call_ff $2658
ai_pc_25fe:
    ai_jmp_01_short $25FE, $2618
ai_pc_2600:
    ai_if_tgt_not_within_32_4c_short $2600, $2607
ai_pc_2602:
    ai_call_ff $267F
ai_pc_2605:
    ai_jmp_01_short $2605, $2618
ai_pc_2607:
    ai_if_tgt_not_within_48_51_short $2607, $260E
ai_pc_2609:
    ai_call_ff $2691
ai_pc_260c:
    ai_jmp_01_short $260C, $2618
ai_pc_260e:
    ai_if_tgt_not_within_64_56_short $260E, $2615
ai_pc_2610:
    ai_call_ff $26C2
ai_pc_2613:
    ai_jmp_01_short $2613, $2618
ai_pc_2615:
    ai_call_ff $2714
ai_pc_2618:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $2618, $25ED
ai_pc_261d:
    ai_jmp_01_short $261D, $25ED
