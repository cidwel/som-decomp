.setcpu "65816"
.segment "CODE"
.org $8685
.include "ai_command_macros.inc"
ai_pc_3770:
    ai_pose_e2 $0000
ai_pc_3772:
    ai_ret_00
ai_pc_3773:
    ai_if_tgt_not_within_16_34_short $3773, $377A
ai_pc_3775:
    ai_move_toward_e4 $000E, $0000
ai_pc_3778:
    ai_jmp_01_short $3778, $377D
ai_pc_377a:
    ai_move_toward_e4 $0000, $0005
ai_pc_377d:
    ai_if_field_gt_30_short $0080, $006D, $0000, $377D, $37A1
ai_pc_3782:
    ai_if_tgt_not_lane_v64_66_short $3782, $378C
ai_pc_3784:
    ai_move_toward_card_be $0000, $0005
ai_pc_3787:
    ai_call_ff $6B19
ai_pc_378a:
    ai_jmp_01_short $378A, $37A1
ai_pc_378c:
    ai_if_tgt_not_lane_h64_6f_short $378C, $3796
ai_pc_378e:
    ai_move_toward_card_be $0000, $0005
ai_pc_3791:
    ai_call_ff $6B19
ai_pc_3794:
    ai_jmp_01_short $3794, $37A1
ai_pc_3796:
    ai_flash_fc
ai_pc_3797:
    ai_move_toward_e4 $0000, $0000
ai_pc_379a:
    ai_call_ff $6B19
ai_pc_379d:
    ai_flash_fc
ai_pc_379e:
    ai_move_toward_e4 $0000, $0005
ai_pc_37a1:
    ai_call_ff $386F
ai_pc_37a4:
    ai_ret_00
ai_pc_37a5:
    ai_move_toward_e4 $0000, $0005
ai_pc_37a8:
    ai_if_field_gt_30_long $0080, $006D, $0000, $37A8, $3811
ai_pc_37ae:
    ai_rnd_var3_2c $000F
ai_pc_37b0:
    ai_if_var3_nz_05_short $37B0, $37C6
ai_pc_37b2:
    ai_call_ff $3834
ai_pc_37b5:
    ai_flash_fc
ai_pc_37b6:
    ai_move_toward_e4 $0000, $0005
ai_pc_37b9:
    ai_call_ff $6B19
ai_pc_37bc:
    ai_flash_fc
ai_pc_37bd:
    ai_move_toward_e4 $0000, $0005
ai_pc_37c0:
    ai_call_ff $3883
ai_pc_37c3:
    ai_jmp_01_long $37C3, $380F
ai_pc_37c6:
    ai_if_var3_ne_0d_short $0001, $37C6, $37DC
ai_pc_37c9:
    ai_call_ff $3822
ai_pc_37cc:
    ai_flash_fc
ai_pc_37cd:
    ai_move_toward_e4 $0000, $0005
ai_pc_37d0:
    ai_call_ff $6B19
ai_pc_37d3:
    ai_flash_fc
ai_pc_37d4:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_37d7:
    ai_call_ff $386F
ai_pc_37da:
    ai_jmp_01_short $37DA, $380F
ai_pc_37dc:
    ai_if_var3_ne_0d_short $0002, $37DC, $37F8
ai_pc_37df:
    ai_if_tgt_not_lane_v64_66_short $37DF, $37E9
ai_pc_37e1:
    ai_move_toward_card_be $0000, $0005
ai_pc_37e4:
    ai_call_ff $6B19
ai_pc_37e7:
    ai_jmp_01_short $37E7, $37F6
ai_pc_37e9:
    ai_if_tgt_not_lane_h64_6f_short $37E9, $37F3
ai_pc_37eb:
    ai_move_toward_card_be $0000, $0005
ai_pc_37ee:
    ai_call_ff $6B19
ai_pc_37f1:
    ai_jmp_01_short $37F1, $37F6
ai_pc_37f3:
    ai_move_toward_e4 $0000, $0000
ai_pc_37f6:
    ai_jmp_01_short $37F6, $380F
ai_pc_37f8:
    ai_move_toward_e4 $0000, $0000
ai_pc_37fb:
    ai_if_obj_outside_5f_short $0080, $37FB, $380F
ai_pc_37fe:
    ai_rnd_var3_2c $000F
ai_pc_3800:
    ai_if_var3_nz_05_short $3800, $380C
ai_pc_3802:
    ai_tgt2_cur_c1
ai_pc_3803:
    ai_cast_e9 $0004, $0000
ai_pc_3806:
    ai_tgt2_none_c0
ai_pc_3807:
    ai_turn_facing_e3 $0000, $003C
ai_pc_380a:
    ai_jmp_01_short $380A, $380F
ai_pc_380c:
    ai_move_toward_e4 $0000, $0000
ai_pc_380f:
    ai_jmp_01_short $380F, $3814
ai_pc_3811:
    ai_move_toward_e4 $0000, $0000
ai_pc_3814:
    ai_ret_00
ai_pc_3815:
    ai_rnd_var3_2c $0001
ai_pc_3817:
    ai_if_var3_nz_05_short $3817, $381E
ai_pc_3819:
    ai_call_ff $3822
ai_pc_381c:
    ai_jmp_01_short $381C, $3821
ai_pc_381e:
    ai_call_ff $3855
ai_pc_3821:
    ai_ret_00
ai_pc_3822:
    ai_call_ff $6AE1
ai_pc_3825:
    ai_if_pos_same_9d_short $3825, $382D
ai_pc_3827:
    ai_pos_save_9f
ai_pc_3828:
    ai_move_toward_e4 $0004, $0000
ai_pc_382b:
    ai_jmp_01_short $382B, $3831
ai_pc_382d:
    ai_pos_save_9f
ai_pc_382e:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_3831:
    ai_if_tgt_not_within_48_51_short $3831, $3822
ai_pc_3833:
    ai_ret_00
ai_pc_3834:
    ai_rnd_var3_2c $0001
ai_pc_3836:
    ai_call_ff $6AE1
ai_pc_3839:
    ai_call_ff $389D
ai_pc_383c:
    ai_if_pos_same_9d_short $383C, $3844
ai_pc_383e:
    ai_pos_save_9f
ai_pc_383f:
    ai_move_toward_e4 $0002, $0000
ai_pc_3842:
    ai_jmp_01_short $3842, $3848
ai_pc_3844:
    ai_pos_save_9f
ai_pc_3845:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_3848:
    ai_call_ff $38CE
ai_pc_384b:
    ai_if_var3_nz_05_short $384B, $3852
ai_pc_384d:
    ai_if_tgt_not_within_48_51_short $384D, $3852
ai_pc_384f:
    ai_jmp_01_long $384F, $3854
ai_pc_3852:
    ai_if_tgt_not_within_32_4c_short $3852, $3836
ai_pc_3854:
    ai_ret_00
ai_pc_3855:
    ai_rnd_var3_2c $0001
ai_pc_3857:
    ai_call_ff $6AE1
ai_pc_385a:
    ai_call_ff $389D
ai_pc_385d:
    ai_if_pos_same_9d_short $385D, $3865
ai_pc_385f:
    ai_pos_save_9f
ai_pc_3860:
    ai_move_toward_e4 $0002, $0000
ai_pc_3863:
    ai_jmp_01_short $3863, $3869
ai_pc_3865:
    ai_pos_save_9f
ai_pc_3866:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_3869:
    ai_call_ff $38CE
ai_pc_386c:
    ai_if_tgt_not_within_64_56_short $386C, $3857
ai_pc_386e:
    ai_ret_00
ai_pc_386f:
    ai_if_tgt_not_within_48_51_short $386F, $3882
ai_pc_3871:
    ai_call_ff $6AE1
ai_pc_3874:
    ai_if_pos_same_9d_short $3874, $387C
ai_pc_3876:
    ai_pos_save_9f
ai_pc_3877:
    ai_move_away_e6 $0004, $0000
ai_pc_387a:
    ai_jmp_01_short $387A, $3880
ai_pc_387c:
    ai_pos_save_9f
ai_pc_387d:
    ai_move_away_alt_fe $0004, $0000
ai_pc_3880:
    ai_jmp_01_short $3880, $386F
ai_pc_3882:
    ai_ret_00
ai_pc_3883:
    ai_if_tgt_not_within_48_51_short $3883, $389C
ai_pc_3885:
    ai_call_ff $6AE1
ai_pc_3888:
    ai_call_ff $389D
ai_pc_388b:
    ai_if_pos_same_9d_short $388B, $3893
ai_pc_388d:
    ai_pos_save_9f
ai_pc_388e:
    ai_move_away_e6 $0002, $0000
ai_pc_3891:
    ai_jmp_01_short $3891, $3897
ai_pc_3893:
    ai_pos_save_9f
ai_pc_3894:
    ai_move_away_alt_fe $0002, $0000
ai_pc_3897:
    ai_call_ff $38CE
ai_pc_389a:
    ai_jmp_01_short $389A, $3883
ai_pc_389c:
    ai_ret_00
ai_pc_389d:
    ai_hop_e0 $0008, $0000, $000F
ai_pc_38a1:
    ai_hop_e0 $0001, $0000, $000F
ai_pc_38a5:
    ai_hop_e0 $0004, $0000, $000F
ai_pc_38a9:
    ai_hop_e0 $0002, $0000, $000F
ai_pc_38ad:
    ai_hop_e0 $0008, $0000, $000A
ai_pc_38b1:
    ai_hop_e0 $0001, $0000, $000A
ai_pc_38b5:
    ai_hop_e0 $0004, $0000, $000A
ai_pc_38b9:
    ai_hop_e0 $0002, $0000, $000A
ai_pc_38bd:
    ai_hop_e0 $0008, $0000, $0005
ai_pc_38c1:
    ai_hop_e0 $0001, $0000, $0005
ai_pc_38c5:
    ai_hop_e0 $0004, $0000, $0005
ai_pc_38c9:
    ai_hop_e0 $0002, $0000, $0005
ai_pc_38cd:
    ai_ret_00
ai_pc_38ce:
    ai_hop_e0 $0002, $0000, $000F
ai_pc_38d2:
    ai_hop_e0 $0004, $0000, $000F
ai_pc_38d6:
    ai_hop_e0 $0001, $0000, $000F
ai_pc_38da:
    ai_hop_e0 $0008, $0000, $000F
ai_pc_38de:
    ai_hop_e0 $0002, $0000, $000A
ai_pc_38e2:
    ai_hop_e0 $0004, $0000, $000A
ai_pc_38e6:
    ai_hop_e0 $0001, $0000, $000A
ai_pc_38ea:
    ai_hop_e0 $0008, $0000, $000A
ai_pc_38ee:
    ai_hop_e0 $0002, $0000, $0005
ai_pc_38f2:
    ai_hop_e0 $0004, $0000, $0005
ai_pc_38f6:
    ai_hop_e0 $0001, $0000, $0005
ai_pc_38fa:
    ai_hop_e0 $0008, $0000, $0005
ai_pc_38fe:
    ai_ret_00
ai_pc_38ff:
    ai_call_ff $392E
ai_pc_3902:
    ai_rnd_var3_2c $000F
ai_pc_3904:
    ai_if_var3_nz_05_short $3904, $390B
ai_pc_3906:
    ai_call_ff $6993
ai_pc_3909:
    ai_jmp_01_short $3909, $3926
ai_pc_390b:
    ai_call_ff $6AE1
ai_pc_390e:
    ai_if_tgt_not_within_32_4c_short $390E, $3915
ai_pc_3910:
    ai_call_ff $3935
ai_pc_3913:
    ai_jmp_01_short $3913, $3926
ai_pc_3915:
    ai_if_tgt_not_within_48_51_short $3915, $391C
ai_pc_3917:
    ai_call_ff $394C
ai_pc_391a:
    ai_jmp_01_short $391A, $3926
ai_pc_391c:
    ai_if_tgt_not_within_64_56_short $391C, $3923
ai_pc_391e:
    ai_call_ff $3974
ai_pc_3921:
    ai_jmp_01_short $3921, $3926
ai_pc_3923:
    ai_call_ff $39B0
ai_pc_3926:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $3926, $3902
ai_pc_392b:
    ai_jmp_01_short $392B, $3902
