.setcpu "65816"
.segment "CODE"
.org $82B2
.include "ai_command_macros.inc"
ai_pc_339d:
    ai_pose_e2 $0000
ai_pc_339f:
    ai_ret_00
ai_pc_33a0:
    ai_if_var1_nz_03_short $33A0, $33C0
ai_pc_33a2:
    ai_move_toward_e4 $0000, $0000
ai_pc_33a5:
    ai_rnd_var3_2c $0003
ai_pc_33a7:
    ai_if_var3_nz_05_short $33A7, $33BB
ai_pc_33a9:
    ai_if_obj_outside_5f_short $0080, $33A9, $33B6
ai_pc_33ac:
    ai_tgt2_cur_c1
ai_pc_33ad:
    ai_cast_e9 $0001, $0019
ai_pc_33b0:
    ai_tgt2_none_c0
ai_pc_33b1:
    ai_turn_facing_e3 $0003, $003C
ai_pc_33b4:
    ai_jmp_01_short $33B4, $33B9
ai_pc_33b6:
    ai_move_toward_e4 $0000, $0000
ai_pc_33b9:
    ai_jmp_01_short $33B9, $33BE
ai_pc_33bb:
    ai_move_toward_e4 $0000, $0000
ai_pc_33be:
    ai_jmp_01_short $33BE, $33C6
ai_pc_33c0:
    ai_move_toward_e4 $0003, $0000
ai_pc_33c3:
    ai_call_ff $33C7
ai_pc_33c6:
    ai_ret_00
ai_pc_33c7:
    ai_if_obj_outside_5f_short $0080, $33C7, $33F3
ai_pc_33ca:
    ai_if_no_ally_64_54_short $33CA, $33E9
ai_pc_33cc:
    ai_tgt2_ally_d8
ai_pc_33cd:
    ai_if_field_and_nz_2d_short $0082, $002E, $00F0, $33CD, $33DD
ai_pc_33d2:
    ai_cast_e9 $0003, $001D
ai_pc_33d5:
    ai_tgt2_none_c0
ai_pc_33d6:
    ai_set_var1_26 $0000
ai_pc_33d8:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_33db:
    ai_jmp_01_short $33DB, $33E7
ai_pc_33dd:
    ai_tgt2_cur_c1
ai_pc_33de:
    ai_cast_e9 $0003, $001A
ai_pc_33e1:
    ai_tgt2_none_c0
ai_pc_33e2:
    ai_set_var1_26 $0000
ai_pc_33e4:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_33e7:
    ai_jmp_01_short $33E7, $33F3
ai_pc_33e9:
    ai_tgt2_cur_c1
ai_pc_33ea:
    ai_cast_e9 $0003, $001A
ai_pc_33ed:
    ai_tgt2_none_c0
ai_pc_33ee:
    ai_set_var1_26 $0000
ai_pc_33f0:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_33f3:
    ai_ret_00
ai_pc_33f4:
    ai_set_var3_28 $000F
ai_pc_33f6:
    ai_if_tgt_not_within_48_51_short $33F6, $341F
ai_pc_33f8:
    ai_call_ff $6AE1
ai_pc_33fb:
    ai_if_var1_nz_03_short $33FB, $340B
ai_pc_33fd:
    ai_if_pos_same_9d_short $33FD, $3405
ai_pc_33ff:
    ai_pos_save_9f
ai_pc_3400:
    ai_move_away_e6 $0001, $0000
ai_pc_3403:
    ai_jmp_01_short $3403, $3409
ai_pc_3405:
    ai_pos_save_9f
ai_pc_3406:
    ai_move_away_alt_fe $0001, $0000
ai_pc_3409:
    ai_jmp_01_short $3409, $3417
ai_pc_340b:
    ai_if_pos_same_9d_short $340B, $3413
ai_pc_340d:
    ai_pos_save_9f
ai_pc_340e:
    ai_move_away_e6 $0002, $0000
ai_pc_3411:
    ai_jmp_01_short $3411, $3417
ai_pc_3413:
    ai_pos_save_9f
ai_pc_3414:
    ai_move_away_alt_fe $0002, $0000
ai_pc_3417:
    ai_dec_var3_21
ai_pc_3418:
    ai_if_var3_nz_05_short $3418, $341D
ai_pc_341a:
    ai_jmp_01_long $341A, $341F
ai_pc_341d:
    ai_jmp_01_short $341D, $33F6
ai_pc_341f:
    ai_ret_00
ai_pc_3420:
    ai_set_var3_28 $000F
ai_pc_3422:
    ai_call_ff $6AE1
ai_pc_3425:
    ai_if_var1_nz_03_short $3425, $3435
ai_pc_3427:
    ai_if_pos_same_9d_short $3427, $342F
ai_pc_3429:
    ai_pos_save_9f
ai_pc_342a:
    ai_move_toward_card_be $0004, $0000
ai_pc_342d:
    ai_jmp_01_short $342D, $3433
ai_pc_342f:
    ai_pos_save_9f
ai_pc_3430:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_3433:
    ai_jmp_01_short $3433, $3441
ai_pc_3435:
    ai_if_pos_same_9d_short $3435, $343D
ai_pc_3437:
    ai_pos_save_9f
ai_pc_3438:
    ai_move_toward_card_be $0002, $0000
ai_pc_343b:
    ai_jmp_01_short $343B, $3441
ai_pc_343d:
    ai_pos_save_9f
ai_pc_343e:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_3441:
    ai_dec_var3_21
ai_pc_3442:
    ai_if_var3_nz_05_short $3442, $3447
ai_pc_3444:
    ai_jmp_01_long $3444, $3449
ai_pc_3447:
    ai_if_tgt_not_within_64_56_short $3447, $3422
ai_pc_3449:
    ai_ret_00
ai_pc_344a:
    ai_rnd_var3_2c $0003
ai_pc_344c:
    ai_if_var1_nz_03_short $344C, $346E
ai_pc_344e:
    ai_if_var3_nz_05_short $344E, $3456
ai_pc_3450:
    ai_hop_e0 $0008, $0004, $0000
ai_pc_3454:
    ai_jmp_01_short $3454, $346C
ai_pc_3456:
    ai_if_var3_ne_0d_short $0001, $3456, $345F
ai_pc_3459:
    ai_hop_e0 $0004, $0004, $0000
ai_pc_345d:
    ai_jmp_01_short $345D, $346C
ai_pc_345f:
    ai_if_var3_ne_0d_short $0002, $345F, $3468
ai_pc_3462:
    ai_hop_e0 $0002, $0004, $0000
ai_pc_3466:
    ai_jmp_01_short $3466, $346C
ai_pc_3468:
    ai_hop_e0 $0001, $0004, $0000
ai_pc_346c:
    ai_jmp_01_short $346C, $348C
ai_pc_346e:
    ai_if_var3_nz_05_short $346E, $3476
ai_pc_3470:
    ai_hop_e0 $0008, $0002, $0000
ai_pc_3474:
    ai_jmp_01_short $3474, $348C
ai_pc_3476:
    ai_if_var3_ne_0d_short $0001, $3476, $347F
ai_pc_3479:
    ai_hop_e0 $0004, $0002, $0000
ai_pc_347d:
    ai_jmp_01_short $347D, $348C
ai_pc_347f:
    ai_if_var3_ne_0d_short $0002, $347F, $3488
ai_pc_3482:
    ai_hop_e0 $0002, $0002, $0000
ai_pc_3486:
    ai_jmp_01_short $3486, $348C
ai_pc_3488:
    ai_hop_e0 $0001, $0002, $0000
ai_pc_348c:
    ai_ret_00
ai_pc_348d:
    ai_call_ff $34B5
ai_pc_3490:
    ai_rnd_var3_2c $000F
ai_pc_3492:
    ai_if_var3_nz_05_short $3492, $3499
ai_pc_3494:
    ai_call_ff $6653
ai_pc_3497:
    ai_jmp_01_short $3497, $34AD
ai_pc_3499:
    ai_call_ff $6AE1
ai_pc_349c:
    ai_if_tgt_not_within_48_51_short $349C, $34A3
ai_pc_349e:
    ai_call_ff $34BC
ai_pc_34a1:
    ai_jmp_01_short $34A1, $34AD
ai_pc_34a3:
    ai_if_tgt_not_within_64_56_short $34A3, $34AA
ai_pc_34a5:
    ai_call_ff $34E6
ai_pc_34a8:
    ai_jmp_01_short $34A8, $34AD
ai_pc_34aa:
    ai_call_ff $3511
ai_pc_34ad:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $34AD, $3490
ai_pc_34b2:
    ai_jmp_01_short $34B2, $3490
