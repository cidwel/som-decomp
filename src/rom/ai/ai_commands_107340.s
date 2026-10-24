.setcpu "65816"
.segment "CODE"
.org $7340
.include "ai_command_macros.inc"
ai_pc_242b:
    ai_pose_e2 $0000
ai_pc_242d:
    ai_ret_00
ai_pc_242e:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_2431:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_2434:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2434, $243F
ai_pc_2439:
    ai_move_toward_e4 $0000, $0000
ai_pc_243c:
    ai_call_ff $6B19
ai_pc_243f:
    ai_call_ff $24E5
ai_pc_2442:
    ai_ret_00
ai_pc_2443:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_2446:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_2449:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2449, $246F
ai_pc_244e:
    ai_if_tgt_not_lane_v64_66_short $244E, $2469
ai_pc_2450:
    ai_if_tgt_not_below_77_short $2450, $2461
ai_pc_2452:
    ai_flash_fc
ai_pc_2453:
    ai_hop_e0 $0004, $0000, $0005
ai_pc_2457:
    ai_call_ff $6B0F
ai_pc_245a:
    ai_flash_fc
ai_pc_245b:
    ai_hop_e0 $0004, $0000, $0005
ai_pc_245f:
    ai_jmp_01_short $245F, $2467
ai_pc_2461:
    ai_move_toward_e4 $0000, $0000
ai_pc_2464:
    ai_call_ff $6B19
ai_pc_2467:
    ai_jmp_01_short $2467, $246F
ai_pc_2469:
    ai_move_toward_e4 $0000, $0000
ai_pc_246c:
    ai_call_ff $6B19
ai_pc_246f:
    ai_call_ff $24E5
ai_pc_2472:
    ai_ret_00
ai_pc_2473:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_2476:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_2479:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2479, $24B5
ai_pc_247e:
    ai_if_tgt_not_lane_v64_66_short $247E, $24A8
ai_pc_2480:
    ai_if_tgt_not_below_77_short $2480, $2491
ai_pc_2482:
    ai_flash_fc
ai_pc_2483:
    ai_hop_e0 $0004, $0000, $0005
ai_pc_2487:
    ai_call_ff $6B0F
ai_pc_248a:
    ai_flash_fc
ai_pc_248b:
    ai_hop_e0 $0004, $0000, $0005
ai_pc_248f:
    ai_jmp_01_short $248F, $24A6
ai_pc_2491:
    ai_if_obj_outside_5f_short $0080, $2491, $24A0
ai_pc_2494:
    ai_rnd_var3_2c $000F
ai_pc_2496:
    ai_if_var3_nz_05_short $2496, $24A0
ai_pc_2498:
    ai_tgt2_cur_c1
ai_pc_2499:
    ai_cast_e9 $0004, $000D
ai_pc_249c:
    ai_tgt2_none_c0
ai_pc_249d:
    ai_turn_facing_e3 $0000, $0078
ai_pc_24a0:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_24a3:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_24a6:
    ai_jmp_01_short $24A6, $24B5
ai_pc_24a8:
    ai_move_toward_e4 $0000, $0000
ai_pc_24ab:
    ai_rnd_var3_2c $000F
ai_pc_24ad:
    ai_if_var3_nz_05_short $24AD, $24B5
ai_pc_24af:
    ai_call_ff $24CA
ai_pc_24b2:
    ai_call_ff $6B19
ai_pc_24b5:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_24b8:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_24bb:
    ai_ret_00
ai_pc_24bc:
    ai_rnd_var3_2c $0003
ai_pc_24be:
    ai_if_var3_nz_05_short $24BE, $24C6
ai_pc_24c0:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_24c3:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_24c6:
    ai_call_ff $6A17
ai_pc_24c9:
    ai_ret_00
ai_pc_24ca:
    ai_rnd_var3_2c $0002
ai_pc_24cc:
    ai_call_ff $6AE1
ai_pc_24cf:
    ai_if_pos_same_9d_short $24CF, $24D7
ai_pc_24d1:
    ai_pos_save_9f
ai_pc_24d2:
    ai_move_toward_e4 $0002, $0000
ai_pc_24d5:
    ai_jmp_01_short $24D5, $24DB
ai_pc_24d7:
    ai_pos_save_9f
ai_pc_24d8:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_24db:
    ai_if_var3_nz_05_short $24DB, $24E2
ai_pc_24dd:
    ai_if_tgt_not_within_48_51_short $24DD, $24E2
ai_pc_24df:
    ai_jmp_01_long $24DF, $24E4
ai_pc_24e2:
    ai_if_tgt_not_within_32_4c_short $24E2, $24CC
ai_pc_24e4:
    ai_ret_00
ai_pc_24e5:
    ai_if_tgt_not_within_32_4c_short $24E5, $24FC
ai_pc_24e7:
    ai_if_tgt_not_within_48_51_short $24E7, $24FA
ai_pc_24e9:
    ai_call_ff $6AE1
ai_pc_24ec:
    ai_if_pos_same_9d_short $24EC, $24F4
ai_pc_24ee:
    ai_pos_save_9f
ai_pc_24ef:
    ai_move_away_e6 $0002, $0000
ai_pc_24f2:
    ai_jmp_01_short $24F2, $24F8
ai_pc_24f4:
    ai_pos_save_9f
ai_pc_24f5:
    ai_move_away_alt_fe $0002, $0000
ai_pc_24f8:
    ai_jmp_01_short $24F8, $24E7
ai_pc_24fa:
    ai_jmp_01_short $24FA, $250F
ai_pc_24fc:
    ai_if_tgt_not_within_48_51_short $24FC, $250F
ai_pc_24fe:
    ai_call_ff $6AE1
ai_pc_2501:
    ai_if_pos_same_9d_short $2501, $2509
ai_pc_2503:
    ai_pos_save_9f
ai_pc_2504:
    ai_move_away_e6 $0002, $0000
ai_pc_2507:
    ai_jmp_01_short $2507, $250D
ai_pc_2509:
    ai_pos_save_9f
ai_pc_250a:
    ai_move_away_alt_fe $0002, $0000
ai_pc_250d:
    ai_jmp_01_short $250D, $24FC
ai_pc_250f:
    ai_ret_00
ai_pc_2510:
    ai_call_ff $253F
ai_pc_2513:
    ai_rnd_var3_2c $000F
ai_pc_2515:
    ai_if_var3_nz_05_short $2515, $251C
ai_pc_2517:
    ai_call_ff $6627
ai_pc_251a:
    ai_jmp_01_short $251A, $2537
ai_pc_251c:
    ai_call_ff $6AE1
ai_pc_251f:
    ai_if_tgt_not_within_32_4c_short $251F, $2526
ai_pc_2521:
    ai_call_ff $2545
ai_pc_2524:
    ai_jmp_01_short $2524, $2537
ai_pc_2526:
    ai_if_tgt_not_within_48_51_short $2526, $252D
ai_pc_2528:
    ai_call_ff $256E
ai_pc_252b:
    ai_jmp_01_short $252B, $2537
ai_pc_252d:
    ai_if_tgt_not_within_64_56_short $252D, $2534
ai_pc_252f:
    ai_call_ff $2583
ai_pc_2532:
    ai_jmp_01_short $2532, $2537
ai_pc_2534:
    ai_call_ff $25B9
ai_pc_2537:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $2537, $2513
ai_pc_253c:
    ai_jmp_01_short $253C, $2513
