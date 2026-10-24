.setcpu "65816"
.segment "CODE"
.org $56FF
.include "ai_command_macros.inc"
ai_pc_07ea:
    ai_pose_e2 $0000
ai_pc_07ec:
    ai_ret_00
ai_pc_07ed:
    ai_move_toward_e4 $0000, $0000
ai_pc_07f0:
    ai_if_field_gt_30_short $0080, $006D, $0000, $07F0, $07FA
ai_pc_07f5:
    ai_set_var1_26 $0002
ai_pc_07f7:
    ai_call_ff $085C
ai_pc_07fa:
    ai_call_ff $0894
ai_pc_07fd:
    ai_ret_00
ai_pc_07fe:
    ai_move_toward_e4 $0000, $0000
ai_pc_0801:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0801, $0820
ai_pc_0806:
    ai_move_toward_e4 $0000, $0000
ai_pc_0809:
    ai_rnd_var3_2c $0007
ai_pc_080b:
    ai_if_var3_nz_05_short $080B, $081B
ai_pc_080d:
    ai_call_ff $0824
ai_pc_0810:
    ai_move_toward_e4 $0000, $0005
ai_pc_0813:
    ai_call_ff $6B0F
ai_pc_0816:
    ai_call_ff $0894
ai_pc_0819:
    ai_jmp_01_short $0819, $081E
ai_pc_081b:
    ai_move_toward_e4 $0000, $0000
ai_pc_081e:
    ai_jmp_01_short $081E, $0823
ai_pc_0820:
    ai_move_toward_e4 $0000, $0000
ai_pc_0823:
    ai_ret_00
ai_pc_0824:
    ai_if_obj_outside_5f_short $0080, $0824, $083A
ai_pc_0827:
    ai_if_word_and_nz_ba_short $0081, $0010, $0000, $0001, $0827, $0837
ai_pc_082d:
    ai_tgt2_cur_c1
ai_pc_082e:
    ai_cast_e9 $0003, $0016
ai_pc_0831:
    ai_tgt2_none_c0
ai_pc_0832:
    ai_move_toward_e4 $0000, $0078
ai_pc_0835:
    ai_jmp_01_short $0835, $083A
ai_pc_0837:
    ai_move_toward_e4 $0000, $0000
ai_pc_083a:
    ai_ret_00
ai_pc_083b:
    ai_rnd_var3_2c $0007
ai_pc_083d:
    ai_if_var3_nz_05_short $083D, $0842
ai_pc_083f:
    ai_move_toward_e4 $0000, $003C
ai_pc_0842:
    ai_set_var2_27 $0004
ai_pc_0844:
    ai_call_ff $6AE1
ai_pc_0847:
    ai_if_pos_same_9d_short $0847, $084F
ai_pc_0849:
    ai_pos_save_9f
ai_pc_084a:
    ai_move_toward_card_be $0004, $000A
ai_pc_084d:
    ai_jmp_01_short $084D, $0853
ai_pc_084f:
    ai_pos_save_9f
ai_pc_0850:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_0853:
    ai_dec_var2_20
ai_pc_0854:
    ai_if_var2_nz_04_short $0854, $0859
ai_pc_0856:
    ai_jmp_01_long $0856, $085B
ai_pc_0859:
    ai_if_tgt_not_within_64_56_short $0859, $0844
ai_pc_085b:
    ai_ret_00
ai_pc_085c:
    ai_call_ff $6AE1
ai_pc_085f:
    ai_if_pos_same_9d_short $085F, $0867
ai_pc_0861:
    ai_pos_save_9f
ai_pc_0862:
    ai_move_toward_e4 $0002, $0005
ai_pc_0865:
    ai_jmp_01_short $0865, $086B
ai_pc_0867:
    ai_pos_save_9f
ai_pc_0868:
    ai_move_toward_alt_fd $0002, $0005
ai_pc_086b:
    ai_if_tgt_not_within_16_34_short $086B, $085C
ai_pc_086d:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_0871:
    ai_call_ff $6B0F
ai_pc_0874:
    ai_dec_var1_1f
ai_pc_0875:
    ai_if_var1_nz_03_short $0875, $085C
ai_pc_0877:
    ai_ret_00
ai_pc_0878:
    ai_set_var0_25 $000F
ai_pc_087a:
    ai_if_tgt_not_within_48_51_short $087A, $0893
ai_pc_087c:
    ai_call_ff $6AE1
ai_pc_087f:
    ai_if_pos_same_9d_short $087F, $0887
ai_pc_0881:
    ai_pos_save_9f
ai_pc_0882:
    ai_move_toward_e4 $0005, $000A
ai_pc_0885:
    ai_jmp_01_short $0885, $088B
ai_pc_0887:
    ai_pos_save_9f
ai_pc_0888:
    ai_move_toward_alt_fd $0005, $000A
ai_pc_088b:
    ai_dec_var0_1e
ai_pc_088c:
    ai_if_var0_nz_02_short $088C, $0891
ai_pc_088e:
    ai_jmp_01_long $088E, $0893
ai_pc_0891:
    ai_jmp_01_short $0891, $087A
ai_pc_0893:
    ai_ret_00
ai_pc_0894:
    ai_set_var0_25 $000F
ai_pc_0896:
    ai_if_tgt_not_within_48_51_short $0896, $08AF
ai_pc_0898:
    ai_call_ff $6AE1
ai_pc_089b:
    ai_if_pos_same_9d_short $089B, $08A3
ai_pc_089d:
    ai_pos_save_9f
ai_pc_089e:
    ai_move_away_e6 $0002, $0005
ai_pc_08a1:
    ai_jmp_01_short $08A1, $08A7
ai_pc_08a3:
    ai_pos_save_9f
ai_pc_08a4:
    ai_move_away_alt_fe $0002, $0005
ai_pc_08a7:
    ai_dec_var0_1e
ai_pc_08a8:
    ai_if_var0_nz_02_short $08A8, $08AD
ai_pc_08aa:
    ai_jmp_01_long $08AA, $08AF
ai_pc_08ad:
    ai_jmp_01_short $08AD, $0896
ai_pc_08af:
    ai_ret_00
ai_pc_08b0:
    ai_call_ff $08E2
ai_pc_08b3:
    ai_rnd_var3_2c $000F
ai_pc_08b5:
    ai_if_var3_nz_05_short $08B5, $08BC
ai_pc_08b7:
    ai_call_ff $6627
ai_pc_08ba:
    ai_jmp_01_short $08BA, $08DA
ai_pc_08bc:
    ai_call_ff $6AE1
ai_pc_08bf:
    ai_call_ff $09B3
ai_pc_08c2:
    ai_if_tgt_not_within_32_4c_short $08C2, $08C9
ai_pc_08c4:
    ai_call_ff $0901
ai_pc_08c7:
    ai_jmp_01_short $08C7, $08DA
ai_pc_08c9:
    ai_if_tgt_not_within_48_51_short $08C9, $08D0
ai_pc_08cb:
    ai_call_ff $0916
ai_pc_08ce:
    ai_jmp_01_short $08CE, $08DA
ai_pc_08d0:
    ai_if_tgt_not_within_64_56_short $08D0, $08D7
ai_pc_08d2:
    ai_call_ff $091D
ai_pc_08d5:
    ai_jmp_01_short $08D5, $08DA
ai_pc_08d7:
    ai_call_ff $0948
ai_pc_08da:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $08DA, $08B3
ai_pc_08df:
    ai_jmp_01_short $08DF, $08B3
