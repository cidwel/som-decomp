.setcpu "65816"
.segment "CODE"
.org $7699
.include "ai_command_macros.inc"
ai_pc_2784:
    ai_pose_e2 $0000
ai_pc_2786:
    ai_ret_00
ai_pc_2787:
    ai_move_toward_e4 $0000, $0000
ai_pc_278a:
    ai_if_field_gt_30_short $0080, $006D, $0000, $278A, $2795
ai_pc_278f:
    ai_move_toward_e4 $0000, $0000
ai_pc_2792:
    ai_call_ff $6B19
ai_pc_2795:
    ai_call_ff $285E
ai_pc_2798:
    ai_if_obj_outside_5f_short $0080, $2798, $27B4
ai_pc_279b:
    ai_rnd_var3_2c $000F
ai_pc_279d:
    ai_if_var3_nz_05_short $279D, $27A9
ai_pc_279f:
    ai_tgt2_cur_c1
ai_pc_27a0:
    ai_cast_e9 $0007, $0007
ai_pc_27a3:
    ai_tgt2_none_c0
ai_pc_27a4:
    ai_turn_facing_e3 $0000, $0078
ai_pc_27a7:
    ai_jmp_01_short $27A7, $27B4
ai_pc_27a9:
    ai_if_var3_ne_0d_short $0001, $27A9, $27B4
ai_pc_27ac:
    ai_tgt2_cur_c1
ai_pc_27ad:
    ai_cast_e9 $0007, $0006
ai_pc_27b0:
    ai_tgt2_none_c0
ai_pc_27b1:
    ai_turn_facing_e3 $0000, $0078
ai_pc_27b4:
    ai_ret_00
ai_pc_27b5:
    ai_move_toward_e4 $0000, $0000
ai_pc_27b8:
    ai_if_field_gt_30_short $0080, $006D, $0000, $27B8, $27C2
ai_pc_27bd:
    ai_call_ff $27F1
ai_pc_27c0:
    ai_jmp_01_short $27C0, $27C5
ai_pc_27c2:
    ai_call_ff $283D
ai_pc_27c5:
    ai_ret_00
ai_pc_27c6:
    ai_move_toward_e4 $0000, $0000
ai_pc_27c9:
    ai_if_field_gt_30_short $0080, $006D, $0000, $27C9, $27D3
ai_pc_27ce:
    ai_call_ff $27F1
ai_pc_27d1:
    ai_jmp_01_short $27D1, $27D6
ai_pc_27d3:
    ai_move_toward_e4 $0000, $0000
ai_pc_27d6:
    ai_ret_00
ai_pc_27d7:
    ai_call_ff $6AE1
ai_pc_27da:
    ai_if_pos_same_9d_short $27DA, $27E2
ai_pc_27dc:
    ai_pos_save_9f
ai_pc_27dd:
    ai_move_toward_e4 $0001, $0000
ai_pc_27e0:
    ai_jmp_01_short $27E0, $27E6
ai_pc_27e2:
    ai_pos_save_9f
ai_pc_27e3:
    ai_move_toward_alt_fd $0001, $0000
ai_pc_27e6:
    ai_if_field_gt_30_short $0080, $006D, $0000, $27E6, $27EE
ai_pc_27eb:
    ai_call_ff $27F1
ai_pc_27ee:
    ai_if_tgt_not_within_64_56_short $27EE, $27D7
ai_pc_27f0:
    ai_ret_00
ai_pc_27f1:
    ai_if_tgt_not_lane_v_6a_short $27F1, $2800
ai_pc_27f3:
    ai_flash_fc
ai_pc_27f4:
    ai_move_toward_e4 $0003, $0005
ai_pc_27f7:
    ai_call_ff $6B19
ai_pc_27fa:
    ai_flash_fc
ai_pc_27fb:
    ai_move_toward_e4 $0000, $0005
ai_pc_27fe:
    ai_jmp_01_short $27FE, $2812
ai_pc_2800:
    ai_if_tgt_not_lane_h_73_short $2800, $280F
ai_pc_2802:
    ai_flash_fc
ai_pc_2803:
    ai_move_toward_e4 $0003, $0005
ai_pc_2806:
    ai_call_ff $6B19
ai_pc_2809:
    ai_flash_fc
ai_pc_280a:
    ai_move_toward_e4 $0000, $0005
ai_pc_280d:
    ai_jmp_01_short $280D, $2812
ai_pc_280f:
    ai_move_toward_e4 $0000, $0000
ai_pc_2812:
    ai_ret_00
ai_pc_2813:
    ai_if_word_gt_bd_short $0080, $0002, $0014, $0000, $2813, $283C
ai_pc_2819:
    ai_move_toward_e4 $000E, $0000
ai_pc_281c:
    ai_pose_e2 $0006
ai_pc_281e:
    ai_call_ff $6AE1
ai_pc_2821:
    ai_pose_e2 $0006
ai_pc_2823:
    ai_if_obj_inside_60_short $0080, $2823, $282C
ai_pc_2826:
    ai_cmd81_ef $0005, $002C
ai_pc_2829:
    ai_jmp_01_long $2829, $282E
ai_pc_282c:
    ai_if_tgt_not_within_32_4c_short $282C, $281E
ai_pc_282e:
    ai_if_field_gt_30_short $0080, $006D, $0000, $282E, $283C
ai_pc_2833:
    ai_move_toward_e4 $0003, $0005
ai_pc_2836:
    ai_call_ff $6B19
ai_pc_2839:
    ai_call_ff $04A6
ai_pc_283c:
    ai_ret_00
ai_pc_283d:
    ai_if_tgt_not_within_48_51_short $283D, $285D
ai_pc_283f:
    ai_call_ff $6AE1
ai_pc_2842:
    ai_if_pos_same_9d_short $2842, $284A
ai_pc_2844:
    ai_pos_save_9f
ai_pc_2845:
    ai_move_toward_e4 $0005, $0000
ai_pc_2848:
    ai_jmp_01_short $2848, $284E
ai_pc_284a:
    ai_pos_save_9f
ai_pc_284b:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_284e:
    ai_if_tgt_not_within_32_4c_short $284E, $285B
ai_pc_2850:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2850, $285B
ai_pc_2855:
    ai_move_toward_e4 $0000, $0000
ai_pc_2858:
    ai_call_ff $6B19
ai_pc_285b:
    ai_jmp_01_short $285B, $283D
ai_pc_285d:
    ai_ret_00
ai_pc_285e:
    ai_if_tgt_not_within_48_51_short $285E, $287E
ai_pc_2860:
    ai_call_ff $6AE1
ai_pc_2863:
    ai_if_pos_same_9d_short $2863, $286B
ai_pc_2865:
    ai_pos_save_9f
ai_pc_2866:
    ai_move_away_e6 $0002, $0000
ai_pc_2869:
    ai_jmp_01_short $2869, $286F
ai_pc_286b:
    ai_pos_save_9f
ai_pc_286c:
    ai_move_away_alt_fe $0002, $0000
ai_pc_286f:
    ai_if_tgt_not_within_32_4c_short $286F, $287C
ai_pc_2871:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2871, $287C
ai_pc_2876:
    ai_move_toward_e4 $0000, $0000
ai_pc_2879:
    ai_call_ff $6B19
ai_pc_287c:
    ai_jmp_01_short $287C, $285E
ai_pc_287e:
    ai_ret_00
ai_pc_287f:
    ai_call_ff $289E
ai_pc_2882:
    ai_call_ff $6AE1
ai_pc_2885:
    ai_if_tgt_not_within_16_34_short $2885, $288C
ai_pc_2887:
    ai_call_ff $28B3
ai_pc_288a:
    ai_jmp_01_short $288A, $2896
ai_pc_288c:
    ai_if_tgt_not_within_64_56_short $288C, $2893
ai_pc_288e:
    ai_call_ff $28D3
ai_pc_2891:
    ai_jmp_01_short $2891, $2896
ai_pc_2893:
    ai_call_ff $28F5
ai_pc_2896:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $2896, $2882
ai_pc_289b:
    ai_jmp_01_short $289B, $2882
