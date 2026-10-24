.setcpu "65816"
.segment "CODE"
.org $7241
.include "ai_command_macros.inc"
ai_pc_232c:
    ai_pose_e2 $0000
ai_pc_232e:
    ai_ret_00
ai_pc_232f:
    ai_rnd_var3_2c $000F
ai_pc_2331:
    ai_if_var3_nz_05_short $2331, $233C
ai_pc_2333:
    ai_turn_facing_e3 $0007, $003C
ai_pc_2336:
    ai_turn_facing_e3 $000B, $0000
ai_pc_2339:
    ai_move_toward_e4 $000E, $0000
ai_pc_233c:
    ai_ret_00
ai_pc_233d:
    ai_move_toward_e4 $0000, $0000
ai_pc_2340:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2340, $234B
ai_pc_2345:
    ai_move_toward_e4 $0000, $0000
ai_pc_2348:
    ai_call_ff $6B19
ai_pc_234b:
    ai_if_tgt_not_within_32_4c_short $234B, $2352
ai_pc_234d:
    ai_move_toward_e4 $000E, $0000
ai_pc_2350:
    ai_jmp_01_short $2350, $2355
ai_pc_2352:
    ai_move_toward_e4 $0000, $0000
ai_pc_2355:
    ai_pose_e2 $0003
ai_pc_2357:
    ai_call_ff $23D1
ai_pc_235a:
    ai_ret_00
ai_pc_235b:
    ai_move_toward_e4 $0000, $0000
ai_pc_235e:
    ai_if_field_gt_30_short $0080, $006D, $0000, $235E, $237A
ai_pc_2363:
    ai_rnd_var3_2c $000F
ai_pc_2365:
    ai_if_var3_nz_05_short $2365, $2375
ai_pc_2367:
    ai_move_toward_e4 $0000, $0000
ai_pc_236a:
    ai_call_ff $23B1
ai_pc_236d:
    ai_move_toward_e4 $0003, $0005
ai_pc_2370:
    ai_call_ff $6B19
ai_pc_2373:
    ai_jmp_01_short $2373, $2378
ai_pc_2375:
    ai_move_toward_e4 $0000, $0000
ai_pc_2378:
    ai_jmp_01_short $2378, $237D
ai_pc_237a:
    ai_move_toward_e4 $0000, $0000
ai_pc_237d:
    ai_ret_00
ai_pc_237e:
    ai_rnd_var3_2c $000F
ai_pc_2380:
    ai_if_var3_nz_05_short $2380, $2388
ai_pc_2382:
    ai_move_away_e6 $0000, $001E
ai_pc_2385:
    ai_move_toward_e4 $0000, $001E
ai_pc_2388:
    ai_call_ff $238C
ai_pc_238b:
    ai_ret_00
ai_pc_238c:
    ai_call_ff $6AE1
ai_pc_238f:
    ai_if_pos_same_9d_short $238F, $2397
ai_pc_2391:
    ai_pos_save_9f
ai_pc_2392:
    ai_move_toward_e4 $0004, $000F
ai_pc_2395:
    ai_jmp_01_short $2395, $239B
ai_pc_2397:
    ai_pos_save_9f
ai_pc_2398:
    ai_move_toward_alt_fd $0004, $000F
ai_pc_239b:
    ai_if_field_gt_30_short $0080, $006D, $0000, $239B, $23AE
ai_pc_23a0:
    ai_if_tgt_not_within_32_4c_short $23A0, $23AE
ai_pc_23a2:
    ai_move_toward_e4 $0000, $0000
ai_pc_23a5:
    ai_call_ff $6B19
ai_pc_23a8:
    ai_move_toward_e4 $000E, $0000
ai_pc_23ab:
    ai_jmp_01_long $23AB, $23B0
ai_pc_23ae:
    ai_if_tgt_not_within_64_56_short $23AE, $238C
ai_pc_23b0:
    ai_ret_00
ai_pc_23b1:
    ai_call_ff $6AE1
ai_pc_23b4:
    ai_if_pos_same_9d_short $23B4, $23BC
ai_pc_23b6:
    ai_pos_save_9f
ai_pc_23b7:
    ai_move_toward_e4 $0002, $000A
ai_pc_23ba:
    ai_jmp_01_short $23BA, $23C0
ai_pc_23bc:
    ai_pos_save_9f
ai_pc_23bd:
    ai_move_toward_alt_fd $0002, $000A
ai_pc_23c0:
    ai_if_tgt_not_beyond_64_5a_short $23C0, $23CE
ai_pc_23c2:
    ai_turn_facing_e3 $0007, $003C
ai_pc_23c5:
    ai_turn_facing_e3 $000B, $0000
ai_pc_23c8:
    ai_move_toward_e4 $000E, $0000
ai_pc_23cb:
    ai_jmp_01_long $23CB, $23D0
ai_pc_23ce:
    ai_if_tgt_not_within_32_4c_short $23CE, $23B1
ai_pc_23d0:
    ai_ret_00
ai_pc_23d1:
    ai_if_tgt_not_within_48_51_short $23D1, $23F7
ai_pc_23d3:
    ai_call_ff $6AE1
ai_pc_23d6:
    ai_if_pos_same_9d_short $23D6, $23DE
ai_pc_23d8:
    ai_pos_save_9f
ai_pc_23d9:
    ai_move_away_e6 $0004, $000F
ai_pc_23dc:
    ai_jmp_01_short $23DC, $23E2
ai_pc_23de:
    ai_pos_save_9f
ai_pc_23df:
    ai_move_away_alt_fe $0004, $000F
ai_pc_23e2:
    ai_if_field_gt_30_short $0080, $006D, $0000, $23E2, $23F5
ai_pc_23e7:
    ai_if_tgt_not_within_32_4c_short $23E7, $23F5
ai_pc_23e9:
    ai_move_toward_e4 $0000, $0000
ai_pc_23ec:
    ai_call_ff $6B19
ai_pc_23ef:
    ai_move_toward_e4 $000E, $0000
ai_pc_23f2:
    ai_jmp_01_long $23F2, $23F7
ai_pc_23f5:
    ai_jmp_01_short $23F5, $23D1
ai_pc_23f7:
    ai_ret_00
ai_pc_23f8:
    ai_call_ff $242B
ai_pc_23fb:
    ai_rnd_var3_2c $0009
ai_pc_23fd:
    ai_if_var3_nz_05_short $23FD, $2408
ai_pc_23ff:
    ai_call_ff $689F
ai_pc_2402:
    ai_hop_e0 $0008, $0002, $0000
ai_pc_2406:
    ai_jmp_01_short $2406, $2423
ai_pc_2408:
    ai_call_ff $6AE1
ai_pc_240b:
    ai_if_tgt_not_within_32_4c_short $240B, $2412
ai_pc_240d:
    ai_call_ff $242E
ai_pc_2410:
    ai_jmp_01_short $2410, $2423
ai_pc_2412:
    ai_if_tgt_not_within_48_51_short $2412, $2419
ai_pc_2414:
    ai_call_ff $2443
ai_pc_2417:
    ai_jmp_01_short $2417, $2423
ai_pc_2419:
    ai_if_tgt_not_within_64_56_short $2419, $2420
ai_pc_241b:
    ai_call_ff $2473
ai_pc_241e:
    ai_jmp_01_short $241E, $2423
ai_pc_2420:
    ai_call_ff $24BC
ai_pc_2423:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $2423, $23FB
ai_pc_2428:
    ai_jmp_01_short $2428, $23FB
