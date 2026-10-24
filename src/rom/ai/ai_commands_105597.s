.setcpu "65816"
.segment "CODE"
.org $5597
.include "ai_command_macros.inc"
ai_pc_0682:
    ai_pose_e2 $0000
ai_pc_0684:
    ai_set_var1_26 $0003
ai_pc_0686:
    ai_ret_00
ai_pc_0687:
    ai_move_toward_e4 $0000, $0000
ai_pc_068a:
    ai_if_field_gt_30_short $0080, $006D, $0000, $068A, $0695
ai_pc_068f:
    ai_move_toward_e4 $0000, $0000
ai_pc_0692:
    ai_call_ff $6B0F
ai_pc_0695:
    ai_call_ff $06E9
ai_pc_0698:
    ai_ret_00
ai_pc_0699:
    ai_move_toward_e4 $0000, $0000
ai_pc_069c:
    ai_if_field_gt_30_short $0080, $006D, $0000, $069C, $06A9
ai_pc_06a1:
    ai_move_toward_e4 $0000, $0000
ai_pc_06a4:
    ai_call_ff $06BC
ai_pc_06a7:
    ai_jmp_01_short $06A7, $06AC
ai_pc_06a9:
    ai_move_toward_e4 $0000, $0000
ai_pc_06ac:
    ai_ret_00
ai_pc_06ad:
    ai_if_obj_outside_5f_short $0080, $06AD, $06BB
ai_pc_06b0:
    ai_if_var1_lt_17_short $0001, $06B0, $06BB
ai_pc_06b3:
    ai_if_crowd_gt_f5_short $0002, $06B3, $06BB
ai_pc_06b6:
    ai_pose_e2 $0006
ai_pc_06b8:
    ai_cmd43_ed $0008
ai_pc_06ba:
    ai_dec_var1_1f
ai_pc_06bb:
    ai_ret_00
ai_pc_06bc:
    ai_rnd_var3_2c $0001
ai_pc_06be:
    ai_call_ff $6AE1
ai_pc_06c1:
    ai_if_pos_same_9d_short $06C1, $06C9
ai_pc_06c3:
    ai_pos_save_9f
ai_pc_06c4:
    ai_move_toward_e4 $0004, $000A
ai_pc_06c7:
    ai_jmp_01_short $06C7, $06CD
ai_pc_06c9:
    ai_pos_save_9f
ai_pc_06ca:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_06cd:
    ai_if_var3_nz_05_short $06CD, $06D4
ai_pc_06cf:
    ai_if_tgt_not_within_16_34_short $06CF, $06D4
ai_pc_06d1:
    ai_jmp_01_long $06D1, $06D6
ai_pc_06d4:
    ai_if_tgt_not_within_32_4c_short $06D4, $06BE
ai_pc_06d6:
    ai_ret_00
ai_pc_06d7:
    ai_call_ff $6AE1
ai_pc_06da:
    ai_if_pos_same_9d_short $06DA, $06E2
ai_pc_06dc:
    ai_pos_save_9f
ai_pc_06dd:
    ai_move_toward_e4 $0004, $000A
ai_pc_06e0:
    ai_jmp_01_short $06E0, $06E6
ai_pc_06e2:
    ai_pos_save_9f
ai_pc_06e3:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_06e6:
    ai_if_tgt_not_within_64_56_short $06E6, $06D7
ai_pc_06e8:
    ai_ret_00
ai_pc_06e9:
    ai_if_tgt_not_within_48_51_short $06E9, $06FC
ai_pc_06eb:
    ai_call_ff $6AE1
ai_pc_06ee:
    ai_if_pos_same_9d_short $06EE, $06F6
ai_pc_06f0:
    ai_pos_save_9f
ai_pc_06f1:
    ai_move_toward_e4 $0005, $000A
ai_pc_06f4:
    ai_jmp_01_short $06F4, $06FA
ai_pc_06f6:
    ai_pos_save_9f
ai_pc_06f7:
    ai_move_toward_alt_fd $0005, $000A
ai_pc_06fa:
    ai_jmp_01_short $06FA, $06E9
ai_pc_06fc:
    ai_ret_00
ai_pc_06fd:
    ai_call_ff $071E
ai_pc_0700:
    ai_rnd_var3_2c $0007
ai_pc_0702:
    ai_if_var3_nz_05_short $0702, $0709
ai_pc_0704:
    ai_call_ff $693B
ai_pc_0707:
    ai_jmp_01_short $0707, $0716
ai_pc_0709:
    ai_call_ff $6AE1
ai_pc_070c:
    ai_if_tgt_not_within_16_34_short $070C, $0713
ai_pc_070e:
    ai_call_ff $073C
ai_pc_0711:
    ai_jmp_01_short $0711, $0716
ai_pc_0713:
    ai_call_ff $078E
ai_pc_0716:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $0716, $0700
ai_pc_071b:
    ai_jmp_01_short $071B, $0700
