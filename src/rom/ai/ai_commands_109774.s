.setcpu "65816"
.segment "CODE"
.org $9774
.include "ai_command_macros.inc"
ai_pc_485f:
    ai_pose_e2 $0000
ai_pc_4861:
    ai_set_var1_26 $000A
ai_pc_4863:
    ai_rnd_var2_2b $0002
ai_pc_4865:
    ai_ret_00
ai_pc_4866:
    ai_move_toward_e4 $0000, $0005
ai_pc_4869:
    ai_rnd_var3_2c $0002
ai_pc_486b:
    ai_if_var3_nz_05_short $486B, $4870
ai_pc_486d:
    ai_call_ff $48B9
ai_pc_4870:
    ai_call_ff $4926
ai_pc_4873:
    ai_ret_00
ai_pc_4874:
    ai_move_toward_e4 $0000, $0005
ai_pc_4877:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4877, $487F
ai_pc_487c:
    ai_call_ff $48A1
ai_pc_487f:
    ai_call_ff $4926
ai_pc_4882:
    ai_ret_00
ai_pc_4883:
    ai_move_toward_e4 $0000, $0005
ai_pc_4886:
    ai_call_ff $48E1
ai_pc_4889:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4889, $489D
ai_pc_488e:
    ai_move_toward_e4 $0000, $0005
ai_pc_4891:
    ai_rnd_var3_2c $000F
ai_pc_4893:
    ai_if_var3_nz_05_short $4893, $489A
ai_pc_4895:
    ai_call_ff $48A1
ai_pc_4898:
    ai_jmp_01_short $4898, $489D
ai_pc_489a:
    ai_move_toward_e4 $0000, $0005
ai_pc_489d:
    ai_move_toward_e4 $0000, $0005
ai_pc_48a0:
    ai_ret_00
ai_pc_48a1:
    ai_if_tgt_not_lane_v64_66_short $48A1, $48AB
ai_pc_48a3:
    ai_move_toward_card_be $0002, $0000
ai_pc_48a6:
    ai_call_ff $6B23
ai_pc_48a9:
    ai_jmp_01_short $48A9, $48B8
ai_pc_48ab:
    ai_if_tgt_not_lane_h64_6f_short $48AB, $48B5
ai_pc_48ad:
    ai_move_toward_card_be $0002, $0000
ai_pc_48b0:
    ai_call_ff $6B23
ai_pc_48b3:
    ai_jmp_01_short $48B3, $48B8
ai_pc_48b5:
    ai_move_toward_e4 $0000, $0005
ai_pc_48b8:
    ai_ret_00
ai_pc_48b9:
    ai_if_var2_nz_04_short $48B9, $48C7
ai_pc_48bb:
    ai_tgt2_cur_c1
ai_pc_48bc:
    ai_cast_e9 $0003, $000D
ai_pc_48bf:
    ai_tgt2_none_c0
ai_pc_48c0:
    ai_move_toward_e4 $0000, $00F0
ai_pc_48c3:
    ai_set_var2_27 $0001
ai_pc_48c5:
    ai_jmp_01_short $48C5, $48E0
ai_pc_48c7:
    ai_if_var2_ne_0c_short $0001, $48C7, $48D6
ai_pc_48ca:
    ai_tgt2_cur_c1
ai_pc_48cb:
    ai_cast_e9 $0003, $0025
ai_pc_48ce:
    ai_tgt2_none_c0
ai_pc_48cf:
    ai_move_toward_e4 $0000, $00F0
ai_pc_48d2:
    ai_set_var2_27 $0002
ai_pc_48d4:
    ai_jmp_01_short $48D4, $48E0
ai_pc_48d6:
    ai_tgt2_cur_c1
ai_pc_48d7:
    ai_cast_e9 $0003, $000E
ai_pc_48da:
    ai_tgt2_none_c0
ai_pc_48db:
    ai_move_toward_e4 $0000, $00F0
ai_pc_48de:
    ai_set_var2_27 $0000
ai_pc_48e0:
    ai_ret_00
ai_pc_48e1:
    ai_if_obj_outside_5f_short $0080, $48E1, $4913
ai_pc_48e4:
    ai_if_var1_lt_17_short $0001, $48E4, $4913
ai_pc_48e7:
    ai_if_crowd_gt_f5_short $0002, $48E7, $4910
ai_pc_48ea:
    ai_move_toward_card_be $0005, $0000
ai_pc_48ed:
    ai_set_var2_27 $0008
ai_pc_48ef:
    ai_turn_facing_e3 $0002, $0005
ai_pc_48f2:
    ai_call_ff $6AE1
ai_pc_48f5:
    ai_if_tgt_not_within_48_51_short $48F5, $48FA
ai_pc_48f7:
    ai_jmp_01_long $48F7, $48FD
ai_pc_48fa:
    ai_dec_var2_20
ai_pc_48fb:
    ai_if_var2_nz_04_short $48FB, $48EF
ai_pc_48fd:
    ai_if_crowd_gt_f5_short $0002, $48FD, $4907
ai_pc_4900:
    ai_pose_e2 $0004
ai_pc_4902:
    ai_cmd43_ed $004D
ai_pc_4904:
    ai_dec_var1_1f
ai_pc_4905:
    ai_jmp_01_short $4905, $490E
ai_pc_4907:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_490b:
    ai_call_ff $6B23
ai_pc_490e:
    ai_jmp_01_short $490E, $4913
ai_pc_4910:
    ai_move_toward_e4 $0000, $0005
ai_pc_4913:
    ai_ret_00
ai_pc_4914:
    ai_call_ff $6AE1
ai_pc_4917:
    ai_if_pos_same_9d_short $4917, $491F
ai_pc_4919:
    ai_pos_save_9f
ai_pc_491a:
    ai_move_toward_card_be $0004, $000A
ai_pc_491d:
    ai_jmp_01_short $491D, $4923
ai_pc_491f:
    ai_pos_save_9f
ai_pc_4920:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_4923:
    ai_if_tgt_not_within_64_56_short $4923, $4914
ai_pc_4925:
    ai_ret_00
ai_pc_4926:
    ai_if_tgt_not_within_48_51_short $4926, $4943
ai_pc_4928:
    ai_call_ff $6AE1
ai_pc_492b:
    ai_if_pos_same_9d_short $492B, $4933
ai_pc_492d:
    ai_pos_save_9f
ai_pc_492e:
    ai_move_toward_card_be $0005, $000A
ai_pc_4931:
    ai_jmp_01_short $4931, $4937
ai_pc_4933:
    ai_pos_save_9f
ai_pc_4934:
    ai_move_toward_alt_fd $0005, $000A
ai_pc_4937:
    ai_if_tgt_not_within_32_4c_short $4937, $4941
ai_pc_4939:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4939, $4941
ai_pc_493e:
    ai_call_ff $48A1
ai_pc_4941:
    ai_jmp_01_short $4941, $4926
ai_pc_4943:
    ai_ret_00
ai_pc_4944:
    ai_call_ff $4973
ai_pc_4947:
    ai_rnd_var3_2c $000F
ai_pc_4949:
    ai_if_var3_nz_05_short $4949, $4950
ai_pc_494b:
    ai_call_ff $67DF
ai_pc_494e:
    ai_jmp_01_short $494E, $496B
ai_pc_4950:
    ai_call_ff $6AE1
ai_pc_4953:
    ai_if_tgt_not_within_32_4c_short $4953, $495A
ai_pc_4955:
    ai_call_ff $498A
ai_pc_4958:
    ai_jmp_01_short $4958, $496B
ai_pc_495a:
    ai_if_tgt_not_within_48_51_short $495A, $4961
ai_pc_495c:
    ai_call_ff $499C
ai_pc_495f:
    ai_jmp_01_short $495F, $496B
ai_pc_4961:
    ai_if_tgt_not_within_64_56_short $4961, $4968
ai_pc_4963:
    ai_call_ff $49A3
ai_pc_4966:
    ai_jmp_01_short $4966, $496B
ai_pc_4968:
    ai_call_ff $4AB0
ai_pc_496b:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $496B, $4947
ai_pc_4970:
    ai_jmp_01_short $4970, $4947
