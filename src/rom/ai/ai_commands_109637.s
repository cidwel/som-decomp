.setcpu "65816"
.segment "CODE"
.org $9637
.include "ai_command_macros.inc"
ai_pc_4722:
    ai_pose_e2 $0004
ai_pc_4724:
    ai_call_ff $6AE1
ai_pc_4727:
    ai_set_var1_26 $0002
ai_pc_4729:
    ai_rnd_var2_2b $0001
ai_pc_472b:
    ai_ret_00
ai_pc_472c:
    ai_move_toward_e4 $0000, $0005
ai_pc_472f:
    ai_if_field_gt_30_short $0080, $006D, $0000, $472F, $4740
ai_pc_4734:
    ai_if_word_and_z_bb_short $0081, $0010, $0000, $0040, $4734, $4740
ai_pc_473a:
    ai_move_toward_e4 $0003, $0005
ai_pc_473d:
    ai_call_ff $6B23
ai_pc_4740:
    ai_call_ff $480C
ai_pc_4743:
    ai_ret_00
ai_pc_4744:
    ai_move_toward_e4 $0000, $0005
ai_pc_4747:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4747, $4769
ai_pc_474c:
    ai_rnd_var3_2c $0007
ai_pc_474e:
    ai_if_var3_nz_05_short $474E, $4753
ai_pc_4750:
    ai_call_ff $476D
ai_pc_4753:
    ai_if_word_and_z_bb_short $0081, $0010, $0000, $0040, $4753, $4764
ai_pc_4759:
    ai_call_ff $47A8
ai_pc_475c:
    ai_call_ff $6B23
ai_pc_475f:
    ai_call_ff $480C
ai_pc_4762:
    ai_jmp_01_short $4762, $4767
ai_pc_4764:
    ai_move_toward_e4 $0000, $0005
ai_pc_4767:
    ai_jmp_01_short $4767, $476C
ai_pc_4769:
    ai_move_toward_e4 $0000, $0005
ai_pc_476c:
    ai_ret_00
ai_pc_476d:
    ai_if_obj_outside_5f_short $0080, $476D, $477E
ai_pc_4770:
    ai_if_word_and_nz_ba_short $0081, $0010, $0000, $0040, $4770, $477E
ai_pc_4776:
    ai_tgt2_cur_c1
ai_pc_4777:
    ai_cast_e9 $0005, $0011
ai_pc_477a:
    ai_tgt2_none_c0
ai_pc_477b:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_477e:
    ai_ret_00
ai_pc_477f:
    ai_if_obj_outside_5f_short $0080, $477F, $47A7
ai_pc_4782:
    ai_if_var1_lt_17_short $0001, $4782, $47A7
ai_pc_4785:
    ai_if_crowd_gt_f5_short $0002, $4785, $47A4
ai_pc_4788:
    ai_move_toward_card_be $0000, $0005
ai_pc_478b:
    ai_pose_e2 $0004
ai_pc_478d:
    ai_if_var2_nz_04_short $478D, $4793
ai_pc_478f:
    ai_cmd43_ed $001B
ai_pc_4791:
    ai_jmp_01_short $4791, $4795
ai_pc_4793:
    ai_cmd43_ed $0035
ai_pc_4795:
    ai_dec_var1_1f
ai_pc_4796:
    ai_if_crowd_gt_f5_short $0002, $4796, $47A2
ai_pc_4799:
    ai_if_var2_nz_04_short $4799, $479F
ai_pc_479b:
    ai_cmd43_ed $001B
ai_pc_479d:
    ai_jmp_01_short $479D, $47A1
ai_pc_479f:
    ai_cmd43_ed $0035
ai_pc_47a1:
    ai_dec_var1_1f
ai_pc_47a2:
    ai_jmp_01_short $47A2, $47A7
ai_pc_47a4:
    ai_move_toward_e4 $0000, $0000
ai_pc_47a7:
    ai_ret_00
ai_pc_47a8:
    ai_set_var2_27 $000F
ai_pc_47aa:
    ai_call_ff $6AE1
ai_pc_47ad:
    ai_if_pos_same_9d_short $47AD, $47B5
ai_pc_47af:
    ai_pos_save_9f
ai_pc_47b0:
    ai_move_toward_e4 $0002, $0000
ai_pc_47b3:
    ai_jmp_01_short $47B3, $47B9
ai_pc_47b5:
    ai_pos_save_9f
ai_pc_47b6:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_47b9:
    ai_dec_var2_20
ai_pc_47ba:
    ai_if_var2_nz_04_short $47BA, $47BF
ai_pc_47bc:
    ai_jmp_01_long $47BC, $47C1
ai_pc_47bf:
    ai_if_tgt_not_within_32_4c_short $47BF, $47AA
ai_pc_47c1:
    ai_ret_00
ai_pc_47c2:
    ai_set_var2_27 $000F
ai_pc_47c4:
    ai_call_ff $6AE1
ai_pc_47c7:
    ai_if_pos_same_9d_short $47C7, $47CF
ai_pc_47c9:
    ai_pos_save_9f
ai_pc_47ca:
    ai_move_toward_e4 $0002, $0000
ai_pc_47cd:
    ai_jmp_01_short $47CD, $47D3
ai_pc_47cf:
    ai_pos_save_9f
ai_pc_47d0:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_47d3:
    ai_dec_var2_20
ai_pc_47d4:
    ai_if_var2_nz_04_short $47D4, $47D9
ai_pc_47d6:
    ai_jmp_01_long $47D6, $47DB
ai_pc_47d9:
    ai_if_tgt_not_within_64_56_short $47D9, $47C4
ai_pc_47db:
    ai_ret_00
ai_pc_47dc:
    ai_set_var2_27 $000F
ai_pc_47de:
    ai_if_tgt_not_within_48_51_short $47DE, $480B
ai_pc_47e0:
    ai_call_ff $6AE1
ai_pc_47e3:
    ai_if_field_gt_30_short $0080, $006D, $0000, $47E3, $47F7
ai_pc_47e8:
    ai_if_word_and_z_bb_short $0081, $0010, $0000, $0040, $47E8, $47F7
ai_pc_47ee:
    ai_call_ff $47A8
ai_pc_47f1:
    ai_call_ff $6B23
ai_pc_47f4:
    ai_jmp_01_long $47F4, $480B
ai_pc_47f7:
    ai_if_pos_same_9d_short $47F7, $47FF
ai_pc_47f9:
    ai_pos_save_9f
ai_pc_47fa:
    ai_move_toward_card_be $0005, $0000
ai_pc_47fd:
    ai_jmp_01_short $47FD, $4803
ai_pc_47ff:
    ai_pos_save_9f
ai_pc_4800:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_4803:
    ai_dec_var2_20
ai_pc_4804:
    ai_if_var2_nz_04_short $4804, $4809
ai_pc_4806:
    ai_jmp_01_long $4806, $480B
ai_pc_4809:
    ai_jmp_01_short $4809, $47DE
ai_pc_480b:
    ai_ret_00
ai_pc_480c:
    ai_set_var2_27 $000F
ai_pc_480e:
    ai_if_tgt_not_within_48_51_short $480E, $4827
ai_pc_4810:
    ai_call_ff $6AE1
ai_pc_4813:
    ai_if_pos_same_9d_short $4813, $481B
ai_pc_4815:
    ai_pos_save_9f
ai_pc_4816:
    ai_move_away_card_bf $0002, $0000
ai_pc_4819:
    ai_jmp_01_short $4819, $481F
ai_pc_481b:
    ai_pos_save_9f
ai_pc_481c:
    ai_move_away_alt_fe $0002, $0000
ai_pc_481f:
    ai_dec_var2_20
ai_pc_4820:
    ai_if_var2_nz_04_short $4820, $4825
ai_pc_4822:
    ai_jmp_01_long $4822, $4827
ai_pc_4825:
    ai_jmp_01_short $4825, $480E
ai_pc_4827:
    ai_ret_00
ai_pc_4828:
    ai_call_ff $485F
ai_pc_482b:
    ai_rnd_var3_2c $000F
ai_pc_482d:
    ai_if_var3_nz_05_short $482D, $4834
ai_pc_482f:
    ai_call_ff $6627
ai_pc_4832:
    ai_jmp_01_short $4832, $4857
ai_pc_4834:
    ai_if_var3_ne_0d_short $0001, $4834, $483C
ai_pc_4837:
    ai_turn_facing_e3 $0000, $0078
ai_pc_483a:
    ai_jmp_01_short $483A, $4857
ai_pc_483c:
    ai_call_ff $6AE1
ai_pc_483f:
    ai_if_tgt_not_within_16_34_short $483F, $4846
ai_pc_4841:
    ai_call_ff $4866
ai_pc_4844:
    ai_jmp_01_short $4844, $4857
ai_pc_4846:
    ai_if_tgt_not_within_48_51_short $4846, $484D
ai_pc_4848:
    ai_call_ff $4874
ai_pc_484b:
    ai_jmp_01_short $484B, $4857
ai_pc_484d:
    ai_if_tgt_not_within_64_56_short $484D, $4854
ai_pc_484f:
    ai_call_ff $4883
ai_pc_4852:
    ai_jmp_01_short $4852, $4857
ai_pc_4854:
    ai_call_ff $4914
ai_pc_4857:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $4857, $482B
ai_pc_485c:
    ai_jmp_01_short $485C, $482B
