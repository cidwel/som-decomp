.setcpu "65816"
.segment "CODE"
.org $754C
.include "ai_command_macros.inc"
ai_pc_2637:
    ai_if_word_gt_bd_short $0080, $0002, $0026, $0001, $2637, $2640
ai_pc_263d:
    ai_jmp_01_long $263D, $2642
ai_pc_2640:
    ai_if_tgt_not_within_32_4c_short $2640, $262B
ai_pc_2642:
    ai_pose_e2 $0000
ai_pc_2644:
    ai_if_obj_outside_5f_short $0080, $2644, $2657
ai_pc_2647:
    ai_if_word_and_nz_ba_short $0081, $0010, $0010, $0000, $2647, $2657
ai_pc_264d:
    ai_tgt2_cur_c1
ai_pc_264e:
    ai_cast_e9 $0003, $001E
ai_pc_2651:
    ai_tgt2_none_c0
ai_pc_2652:
    ai_move_toward_e4 $0000, $0000
ai_pc_2655:
    ai_pose_e2 $0004
ai_pc_2657:
    ai_ret_00
ai_pc_2658:
    ai_move_toward_e4 $0000, $0000
ai_pc_265b:
    ai_if_obj_outside_5f_short $0080, $265B, $267B
ai_pc_265e:
    ai_if_word_gt_bd_short $0080, $0002, $0026, $0001, $265E, $266B
ai_pc_2664:
    ai_tgt2_cur_c1
ai_pc_2665:
    ai_cast_e9 $0003, $0008
ai_pc_2668:
    ai_tgt2_none_c0
ai_pc_2669:
    ai_jmp_01_short $2669, $267B
ai_pc_266b:
    ai_if_field_gt_30_short $0080, $006D, $0000, $266B, $2678
ai_pc_2670:
    ai_move_toward_e4 $0000, $0000
ai_pc_2673:
    ai_call_ff $6B19
ai_pc_2676:
    ai_jmp_01_short $2676, $267B
ai_pc_2678:
    ai_move_toward_e4 $0000, $0000
ai_pc_267b:
    ai_call_ff $273E
ai_pc_267e:
    ai_ret_00
ai_pc_267f:
    ai_move_toward_e4 $0000, $0000
ai_pc_2682:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2682, $268D
ai_pc_2687:
    ai_move_toward_e4 $0000, $0000
ai_pc_268a:
    ai_call_ff $6B19
ai_pc_268d:
    ai_call_ff $273E
ai_pc_2690:
    ai_ret_00
ai_pc_2691:
    ai_move_toward_e4 $0000, $0000
ai_pc_2694:
    ai_if_obj_outside_5f_short $0080, $2694, $26B4
ai_pc_2697:
    ai_if_word_and_nz_ba_short $0081, $0010, $0010, $0000, $2697, $26B2
ai_pc_269d:
    ai_rnd_var3_2c $000F
ai_pc_269f:
    ai_if_var3_nz_05_short $269F, $26AD
ai_pc_26a1:
    ai_tgt2_cur_c1
ai_pc_26a2:
    ai_cast_e9 $0003, $001E
ai_pc_26a5:
    ai_tgt2_none_c0
ai_pc_26a6:
    ai_move_toward_e4 $0000, $0000
ai_pc_26a9:
    ai_pose_e2 $0004
ai_pc_26ab:
    ai_jmp_01_short $26AB, $26B0
ai_pc_26ad:
    ai_move_toward_e4 $0000, $0000
ai_pc_26b0:
    ai_jmp_01_short $26B0, $26B4
ai_pc_26b2:
    ai_pose_e2 $0000
ai_pc_26b4:
    ai_if_field_gt_30_short $0080, $006D, $0000, $26B4, $26BE
ai_pc_26b9:
    ai_call_ff $2714
ai_pc_26bc:
    ai_jmp_01_short $26BC, $26C1
ai_pc_26be:
    ai_call_ff $273E
ai_pc_26c1:
    ai_ret_00
ai_pc_26c2:
    ai_move_toward_e4 $0000, $0000
ai_pc_26c5:
    ai_if_field_gt_30_long $0080, $006D, $0000, $26C5, $2710
ai_pc_26cb:
    ai_move_toward_e4 $0000, $0000
ai_pc_26ce:
    ai_rnd_var3_2c $000F
ai_pc_26d0:
    ai_if_var3_nz_05_short $26D0, $270B
ai_pc_26d2:
    ai_if_word_and_nz_ba_short $0081, $0010, $0010, $0000, $26D2, $2706
ai_pc_26d8:
    ai_move_toward_e4 $0000, $0005
ai_pc_26db:
    ai_if_obj_outside_5f_short $0080, $26DB, $2701
ai_pc_26de:
    ai_tgt2_cur_c1
ai_pc_26df:
    ai_cast_e9 $0003, $001E
ai_pc_26e2:
    ai_tgt2_none_c0
ai_pc_26e3:
    ai_if_word_and_z_bb_short $0081, $0010, $0010, $0000, $26E3, $26FC
ai_pc_26e9:
    ai_call_ff $2726
ai_pc_26ec:
    ai_if_word_and_z_bb_short $0081, $0010, $0010, $0000, $26EC, $26F7
ai_pc_26f2:
    ai_tgt2_cur_c1
ai_pc_26f3:
    ai_cast_e9 $0003, $0008
ai_pc_26f6:
    ai_tgt2_none_c0
ai_pc_26f7:
    ai_call_ff $273E
ai_pc_26fa:
    ai_jmp_01_short $26FA, $26FF
ai_pc_26fc:
    ai_move_toward_e4 $0000, $0000
ai_pc_26ff:
    ai_jmp_01_short $26FF, $2704
ai_pc_2701:
    ai_move_toward_e4 $0000, $0000
ai_pc_2704:
    ai_jmp_01_short $2704, $2709
ai_pc_2706:
    ai_call_ff $2714
ai_pc_2709:
    ai_jmp_01_short $2709, $270E
ai_pc_270b:
    ai_move_toward_e4 $0000, $0000
ai_pc_270e:
    ai_jmp_01_short $270E, $2713
ai_pc_2710:
    ai_move_toward_e4 $0000, $0000
ai_pc_2713:
    ai_ret_00
ai_pc_2714:
    ai_call_ff $6AE1
ai_pc_2717:
    ai_if_pos_same_9d_short $2717, $271F
ai_pc_2719:
    ai_pos_save_9f
ai_pc_271a:
    ai_move_toward_e4 $0004, $000A
ai_pc_271d:
    ai_jmp_01_short $271D, $2723
ai_pc_271f:
    ai_pos_save_9f
ai_pc_2720:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_2723:
    ai_if_tgt_not_within_32_4c_short $2723, $2714
ai_pc_2725:
    ai_ret_00
ai_pc_2726:
    ai_if_pos_same_9d_short $2726, $272E
ai_pc_2728:
    ai_pos_save_9f
ai_pc_2729:
    ai_move_toward_e4 $0002, $000A
ai_pc_272c:
    ai_jmp_01_short $272C, $2732
ai_pc_272e:
    ai_pos_save_9f
ai_pc_272f:
    ai_move_toward_alt_fd $0002, $000A
ai_pc_2732:
    ai_if_word_and_nz_ba_short $0081, $0010, $0010, $0000, $2732, $273B
ai_pc_2738:
    ai_jmp_01_long $2738, $273D
ai_pc_273b:
    ai_if_tgt_not_within_16_34_short $273B, $2726
ai_pc_273d:
    ai_ret_00
ai_pc_273e:
    ai_if_tgt_not_within_48_51_short $273E, $2751
ai_pc_2740:
    ai_call_ff $6AE1
ai_pc_2743:
    ai_if_pos_same_9d_short $2743, $274B
ai_pc_2745:
    ai_pos_save_9f
ai_pc_2746:
    ai_move_toward_e4 $0005, $000A
ai_pc_2749:
    ai_jmp_01_short $2749, $274F
ai_pc_274b:
    ai_pos_save_9f
ai_pc_274c:
    ai_move_toward_alt_fd $0005, $000A
ai_pc_274f:
    ai_jmp_01_short $274F, $273E
ai_pc_2751:
    ai_ret_00
ai_pc_2752:
    ai_call_ff $2784
ai_pc_2755:
    ai_rnd_var3_2c $000F
ai_pc_2757:
    ai_if_var3_nz_05_short $2757, $275E
ai_pc_2759:
    ai_call_ff $687E
ai_pc_275c:
    ai_jmp_01_short $275C, $277C
ai_pc_275e:
    ai_call_ff $6AE1
ai_pc_2761:
    ai_call_ff $2813
ai_pc_2764:
    ai_if_tgt_not_within_32_4c_short $2764, $276B
ai_pc_2766:
    ai_call_ff $2787
ai_pc_2769:
    ai_jmp_01_short $2769, $277C
ai_pc_276b:
    ai_if_tgt_not_within_48_51_short $276B, $2772
ai_pc_276d:
    ai_call_ff $27B5
ai_pc_2770:
    ai_jmp_01_short $2770, $277C
ai_pc_2772:
    ai_if_tgt_not_within_64_56_short $2772, $2779
ai_pc_2774:
    ai_call_ff $27C6
ai_pc_2777:
    ai_jmp_01_short $2777, $277C
ai_pc_2779:
    ai_call_ff $27D7
ai_pc_277c:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $277C, $2755
ai_pc_2781:
    ai_jmp_01_short $2781, $2755
