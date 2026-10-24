.setcpu "65816"
.segment "CODE"
.org $84F3
.include "ai_command_macros.inc"
ai_pc_35de:
    ai_pose_e2 $0000
ai_pc_35e0:
    ai_ret_00
ai_pc_35e1:
    ai_move_toward_e4 $0000, $0000
ai_pc_35e4:
    ai_if_field_gt_30_short $0080, $006D, $0000, $35E4, $35FD
ai_pc_35e9:
    ai_rnd_var3_2c $000F
ai_pc_35eb:
    ai_if_var3_nz_05_short $35EB, $35F7
ai_pc_35ed:
    ai_pose_e2 $0005
ai_pc_35ef:
    ai_pose_e2 $0005
ai_pc_35f1:
    ai_pose_e2 $0005
ai_pc_35f3:
    ai_pose_e2 $0005
ai_pc_35f5:
    ai_jmp_01_short $35F5, $35FD
ai_pc_35f7:
    ai_move_toward_e4 $0000, $0005
ai_pc_35fa:
    ai_call_ff $6B23
ai_pc_35fd:
    ai_move_toward_alt_fd $000E, $0000
ai_pc_3600:
    ai_call_ff $3720
ai_pc_3603:
    ai_ret_00
ai_pc_3604:
    ai_move_toward_e4 $0000, $0000
ai_pc_3607:
    ai_if_field_gt_30_short $0080, $006D, $0000, $3607, $3620
ai_pc_360c:
    ai_rnd_var3_2c $000F
ai_pc_360e:
    ai_if_var3_nz_05_short $360E, $361A
ai_pc_3610:
    ai_pose_e2 $0005
ai_pc_3612:
    ai_pose_e2 $0005
ai_pc_3614:
    ai_pose_e2 $0005
ai_pc_3616:
    ai_pose_e2 $0005
ai_pc_3618:
    ai_jmp_01_short $3618, $3620
ai_pc_361a:
    ai_move_toward_e4 $0000, $0005
ai_pc_361d:
    ai_call_ff $6B23
ai_pc_3620:
    ai_call_ff $3734
ai_pc_3623:
    ai_ret_00
ai_pc_3624:
    ai_move_toward_e4 $0000, $0000
ai_pc_3627:
    ai_if_field_gt_30_long $0080, $006D, $0000, $3627, $3680
ai_pc_362d:
    ai_rnd_var3_2c $000F
ai_pc_362f:
    ai_if_var3_nz_05_short $362F, $3636
ai_pc_3631:
    ai_call_ff $369D
ai_pc_3634:
    ai_jmp_01_short $3634, $3639
ai_pc_3636:
    ai_move_toward_e4 $0000, $0000
ai_pc_3639:
    ai_if_word_and_z_bb_short $0081, $0010, $0000, $0001, $3639, $364A
ai_pc_363f:
    ai_call_ff $36EA
ai_pc_3642:
    ai_move_toward_e4 $0000, $0005
ai_pc_3645:
    ai_call_ff $6B23
ai_pc_3648:
    ai_jmp_01_short $3648, $367E
ai_pc_364a:
    ai_if_word_and_z_bb_short $0081, $0010, $0010, $0000, $364A, $365B
ai_pc_3650:
    ai_call_ff $36EA
ai_pc_3653:
    ai_move_toward_e4 $0000, $0005
ai_pc_3656:
    ai_call_ff $6B23
ai_pc_3659:
    ai_jmp_01_short $3659, $367E
ai_pc_365b:
    ai_move_toward_e4 $0000, $0000
ai_pc_365e:
    ai_rnd_var3_2c $000F
ai_pc_3660:
    ai_if_var3_nz_05_short $3660, $366D
ai_pc_3662:
    ai_call_ff $36EA
ai_pc_3665:
    ai_move_toward_e4 $0000, $0005
ai_pc_3668:
    ai_call_ff $6B23
ai_pc_366b:
    ai_jmp_01_short $366B, $367E
ai_pc_366d:
    ai_if_var3_ne_0d_short $0001, $366D, $367B
ai_pc_3670:
    ai_call_ff $3705
ai_pc_3673:
    ai_move_toward_e4 $0000, $0005
ai_pc_3676:
    ai_call_ff $6B23
ai_pc_3679:
    ai_jmp_01_short $3679, $367E
ai_pc_367b:
    ai_move_toward_e4 $0000, $0000
ai_pc_367e:
    ai_jmp_01_short $367E, $3683
ai_pc_3680:
    ai_move_toward_e4 $0000, $0000
ai_pc_3683:
    ai_ret_00
ai_pc_3684:
    ai_call_ff $6AE1
ai_pc_3687:
    ai_if_pos_same_9d_short $3687, $368F
ai_pc_3689:
    ai_pos_save_9f
ai_pc_368a:
    ai_move_toward_e4 $0001, $0000
ai_pc_368d:
    ai_jmp_01_short $368D, $3693
ai_pc_368f:
    ai_pos_save_9f
ai_pc_3690:
    ai_move_toward_alt_fd $0001, $0000
ai_pc_3693:
    ai_rnd_var3_2c $0005
ai_pc_3695:
    ai_if_var3_nz_05_short $3695, $369A
ai_pc_3697:
    ai_move_toward_e4 $0000, $003C
ai_pc_369a:
    ai_if_tgt_not_within_64_56_short $369A, $3684
ai_pc_369c:
    ai_ret_00
ai_pc_369d:
    ai_if_obj_outside_5f_long $0080, $369D, $36E9
ai_pc_36a1:
    ai_if_var2_nz_04_short $36A1, $36BA
ai_pc_36a3:
    ai_if_word_and_nz_ba_short $0081, $0010, $0080, $0000, $36A3, $36B3
ai_pc_36a9:
    ai_tgt2_cur_c1
ai_pc_36aa:
    ai_cast_e9 $0004, $0014
ai_pc_36ad:
    ai_tgt2_none_c0
ai_pc_36ae:
    ai_move_toward_e4 $0000, $00B4
ai_pc_36b1:
    ai_jmp_01_short $36B1, $36B6
ai_pc_36b3:
    ai_move_toward_e4 $0000, $0000
ai_pc_36b6:
    ai_set_var2_27 $0001
ai_pc_36b8:
    ai_jmp_01_short $36B8, $36E9
ai_pc_36ba:
    ai_if_var2_ne_0c_short $0001, $36BA, $36D4
ai_pc_36bd:
    ai_if_word_and_nz_ba_short $0081, $0010, $0010, $0000, $36BD, $36CD
ai_pc_36c3:
    ai_tgt2_cur_c1
ai_pc_36c4:
    ai_cast_e9 $0004, $001E
ai_pc_36c7:
    ai_tgt2_none_c0
ai_pc_36c8:
    ai_move_toward_e4 $0000, $00B4
ai_pc_36cb:
    ai_jmp_01_short $36CB, $36D0
ai_pc_36cd:
    ai_move_toward_e4 $0000, $0000
ai_pc_36d0:
    ai_set_var2_27 $0002
ai_pc_36d2:
    ai_jmp_01_short $36D2, $36E9
ai_pc_36d4:
    ai_if_word_and_nz_ba_short $0081, $0010, $0000, $0001, $36D4, $36E4
ai_pc_36da:
    ai_tgt2_cur_c1
ai_pc_36db:
    ai_cast_e9 $0004, $0016
ai_pc_36de:
    ai_tgt2_none_c0
ai_pc_36df:
    ai_move_toward_e4 $0000, $00B4
ai_pc_36e2:
    ai_jmp_01_short $36E2, $36E7
ai_pc_36e4:
    ai_move_toward_e4 $0000, $0000
ai_pc_36e7:
    ai_set_var2_27 $0000
ai_pc_36e9:
    ai_ret_00
ai_pc_36ea:
    ai_rnd_var3_2c $0001
ai_pc_36ec:
    ai_call_ff $6AE1
ai_pc_36ef:
    ai_if_pos_same_9d_short $36EF, $36F7
ai_pc_36f1:
    ai_pos_save_9f
ai_pc_36f2:
    ai_move_toward_e4 $0002, $0000
ai_pc_36f5:
    ai_jmp_01_short $36F5, $36FB
ai_pc_36f7:
    ai_pos_save_9f
ai_pc_36f8:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_36fb:
    ai_if_var3_nz_05_short $36FB, $3702
ai_pc_36fd:
    ai_if_tgt_not_within_32_4c_short $36FD, $3702
ai_pc_36ff:
    ai_jmp_01_long $36FF, $3704
ai_pc_3702:
    ai_if_tgt_not_within_48_51_short $3702, $36EC
ai_pc_3704:
    ai_ret_00
ai_pc_3705:
    ai_rnd_var3_2c $0001
ai_pc_3707:
    ai_call_ff $6AE1
ai_pc_370a:
    ai_if_pos_same_9d_short $370A, $3712
ai_pc_370c:
    ai_pos_save_9f
ai_pc_370d:
    ai_move_toward_e4 $0001, $0000
ai_pc_3710:
    ai_jmp_01_short $3710, $3716
ai_pc_3712:
    ai_pos_save_9f
ai_pc_3713:
    ai_move_toward_alt_fd $0001, $0000
ai_pc_3716:
    ai_if_var3_nz_05_short $3716, $371D
ai_pc_3718:
    ai_if_tgt_not_within_32_4c_short $3718, $371D
ai_pc_371a:
    ai_jmp_01_long $371A, $371F
ai_pc_371d:
    ai_if_tgt_not_within_48_51_short $371D, $3707
ai_pc_371f:
    ai_ret_00
ai_pc_3720:
    ai_if_tgt_not_within_48_51_short $3720, $3733
ai_pc_3722:
    ai_call_ff $6AE1
ai_pc_3725:
    ai_if_pos_same_9d_short $3725, $372D
ai_pc_3727:
    ai_pos_save_9f
ai_pc_3728:
    ai_move_away_e6 $0002, $0000
ai_pc_372b:
    ai_jmp_01_short $372B, $3731
ai_pc_372d:
    ai_pos_save_9f
ai_pc_372e:
    ai_move_away_alt_fe $0002, $0000
ai_pc_3731:
    ai_jmp_01_short $3731, $3720
ai_pc_3733:
    ai_ret_00
ai_pc_3734:
    ai_if_tgt_not_within_48_51_short $3734, $3747
ai_pc_3736:
    ai_call_ff $6AE1
ai_pc_3739:
    ai_if_pos_same_9d_short $3739, $3741
ai_pc_373b:
    ai_pos_save_9f
ai_pc_373c:
    ai_move_toward_e4 $0005, $0000
ai_pc_373f:
    ai_jmp_01_short $373F, $3745
ai_pc_3741:
    ai_pos_save_9f
ai_pc_3742:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_3745:
    ai_jmp_01_short $3745, $3734
ai_pc_3747:
    ai_ret_00
ai_pc_3748:
    ai_call_ff $3770
ai_pc_374b:
    ai_rnd_var3_2c $000F
ai_pc_374d:
    ai_if_var3_nz_05_short $374D, $3754
ai_pc_374f:
    ai_call_ff $683C
ai_pc_3752:
    ai_jmp_01_short $3752, $3768
ai_pc_3754:
    ai_call_ff $6AE1
ai_pc_3757:
    ai_if_tgt_not_within_48_51_short $3757, $375E
ai_pc_3759:
    ai_call_ff $3773
ai_pc_375c:
    ai_jmp_01_short $375C, $3768
ai_pc_375e:
    ai_if_tgt_not_within_64_56_short $375E, $3765
ai_pc_3760:
    ai_call_ff $37A5
ai_pc_3763:
    ai_jmp_01_short $3763, $3768
ai_pc_3765:
    ai_call_ff $3815
ai_pc_3768:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $3768, $374B
ai_pc_376d:
    ai_jmp_01_short $376D, $374B
