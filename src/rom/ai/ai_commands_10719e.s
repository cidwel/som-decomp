.setcpu "65816"
.segment "CODE"
.org $719E
.include "ai_command_macros.inc"
ai_pc_2289:
    ai_pose_e2 $0000
ai_pc_228b:
    ai_set_var1_26 $0003
ai_pc_228d:
    ai_ret_00
ai_pc_228e:
    ai_move_toward_e4 $0000, $0000
ai_pc_2291:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2291, $229C
ai_pc_2296:
    ai_move_toward_e4 $0000, $0000
ai_pc_2299:
    ai_call_ff $6B19
ai_pc_229c:
    ai_call_ff $06E9
ai_pc_229f:
    ai_ret_00
ai_pc_22a0:
    ai_move_toward_e4 $0000, $0000
ai_pc_22a3:
    ai_if_field_gt_30_short $0080, $006D, $0000, $22A3, $22AB
ai_pc_22a8:
    ai_call_ff $06BC
ai_pc_22ab:
    ai_ret_00
ai_pc_22ac:
    ai_call_ff $6AE1
ai_pc_22af:
    ai_rnd_var3_2c $0002
ai_pc_22b1:
    ai_if_var3_nz_05_short $22B1, $22B8
ai_pc_22b3:
    ai_call_ff $22E7
ai_pc_22b6:
    ai_jmp_01_short $22B6, $22BB
ai_pc_22b8:
    ai_call_ff $22CD
ai_pc_22bb:
    ai_if_tgt_not_within_64_56_short $22BB, $22AC
ai_pc_22bd:
    ai_ret_00
ai_pc_22be:
    ai_if_obj_outside_5f_short $0080, $22BE, $22CC
ai_pc_22c1:
    ai_if_var1_lt_17_short $0001, $22C1, $22CC
ai_pc_22c4:
    ai_if_crowd_gt_f5_short $0002, $22C4, $22CC
ai_pc_22c7:
    ai_pose_e2 $0006
ai_pc_22c9:
    ai_cmd43_ed $0027
ai_pc_22cb:
    ai_dec_var1_1f
ai_pc_22cc:
    ai_ret_00
ai_pc_22cd:
    ai_set_var2_27 $0004
ai_pc_22cf:
    ai_call_ff $6AE1
ai_pc_22d2:
    ai_if_pos_same_9d_short $22D2, $22DA
ai_pc_22d4:
    ai_pos_save_9f
ai_pc_22d5:
    ai_move_toward_e4 $0004, $000A
ai_pc_22d8:
    ai_jmp_01_short $22D8, $22DE
ai_pc_22da:
    ai_pos_save_9f
ai_pc_22db:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_22de:
    ai_dec_var2_20
ai_pc_22df:
    ai_if_var2_nz_04_short $22DF, $22E4
ai_pc_22e1:
    ai_jmp_01_long $22E1, $22E6
ai_pc_22e4:
    ai_if_tgt_not_within_64_56_short $22E4, $22CF
ai_pc_22e6:
    ai_ret_00
ai_pc_22e7:
    ai_set_var2_27 $0004
ai_pc_22e9:
    ai_call_ff $6AE1
ai_pc_22ec:
    ai_if_pos_same_9d_short $22EC, $22F4
ai_pc_22ee:
    ai_pos_save_9f
ai_pc_22ef:
    ai_move_toward_e4 $0001, $000A
ai_pc_22f2:
    ai_jmp_01_short $22F2, $22F8
ai_pc_22f4:
    ai_pos_save_9f
ai_pc_22f5:
    ai_move_toward_alt_fd $0001, $000A
ai_pc_22f8:
    ai_dec_var2_20
ai_pc_22f9:
    ai_if_var2_nz_04_short $22F9, $22FE
ai_pc_22fb:
    ai_jmp_01_long $22FB, $2300
ai_pc_22fe:
    ai_if_tgt_not_within_64_56_short $22FE, $22E9
ai_pc_2300:
    ai_ret_00
ai_pc_2301:
    ai_call_ff $232C
ai_pc_2304:
    ai_rnd_var3_2c $0007
ai_pc_2306:
    ai_if_var3_nz_05_short $2306, $230D
ai_pc_2308:
    ai_call_ff $67B3
ai_pc_230b:
    ai_jmp_01_short $230B, $2324
ai_pc_230d:
    ai_call_ff $6AE1
ai_pc_2310:
    ai_call_ff $232F
ai_pc_2313:
    ai_if_tgt_not_within_48_51_short $2313, $231A
ai_pc_2315:
    ai_call_ff $233D
ai_pc_2318:
    ai_jmp_01_short $2318, $2324
ai_pc_231a:
    ai_if_tgt_not_within_64_56_short $231A, $2321
ai_pc_231c:
    ai_call_ff $235B
ai_pc_231f:
    ai_jmp_01_short $231F, $2324
ai_pc_2321:
    ai_call_ff $237E
ai_pc_2324:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $2324, $2304
ai_pc_2329:
    ai_jmp_01_short $2329, $2304
