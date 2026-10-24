.setcpu "65816"
.segment "CODE"
.org $57F7
.include "ai_command_macros.inc"
ai_pc_08e2:
    ai_pose_e2 $0000
ai_pc_08e4:
    ai_if_crowd_gt_f5_short $0001, $08E4, $08EF
ai_pc_08e7:
    ai_call_ff $08F8
ai_pc_08ea:
    ai_call_ff $08F8
ai_pc_08ed:
    ai_jmp_01_short $08ED, $08F5
ai_pc_08ef:
    ai_if_crowd_gt_f5_short $0002, $08EF, $08F5
ai_pc_08f2:
    ai_call_ff $08F8
ai_pc_08f5:
    ai_set_var1_26 $000A
ai_pc_08f7:
    ai_ret_00
ai_pc_08f8:
    ai_pose_e2 $0007
ai_pc_08fa:
    ai_cmd43_ed $000E
ai_pc_08fc:
    ai_hop_e0 $0004, $000E, $0000
ai_pc_0900:
    ai_ret_00
ai_pc_0901:
    ai_move_toward_e4 $0000, $0000
ai_pc_0904:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0904, $090F
ai_pc_0909:
    ai_move_toward_e4 $0000, $0000
ai_pc_090c:
    ai_call_ff $6B0F
ai_pc_090f:
    ai_move_toward_alt_fd $000E, $0000
ai_pc_0912:
    ai_call_ff $09C6
ai_pc_0915:
    ai_ret_00
ai_pc_0916:
    ai_move_toward_e4 $0000, $0000
ai_pc_0919:
    ai_call_ff $09C6
ai_pc_091c:
    ai_ret_00
ai_pc_091d:
    ai_move_toward_e4 $0000, $0000
ai_pc_0920:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0920, $0947
ai_pc_0925:
    ai_if_tgt_not_lane_v64_66_short $0925, $0931
ai_pc_0927:
    ai_flash_fc
ai_pc_0928:
    ai_move_toward_card_be $0000, $0000
ai_pc_092b:
    ai_call_ff $6B0F
ai_pc_092e:
    ai_flash_fc
ai_pc_092f:
    ai_jmp_01_short $092F, $0940
ai_pc_0931:
    ai_if_tgt_not_lane_h64_6f_short $0931, $093D
ai_pc_0933:
    ai_flash_fc
ai_pc_0934:
    ai_move_toward_card_be $0000, $0000
ai_pc_0937:
    ai_call_ff $6B0F
ai_pc_093a:
    ai_flash_fc
ai_pc_093b:
    ai_jmp_01_short $093B, $0940
ai_pc_093d:
    ai_move_toward_card_be $0000, $0000
ai_pc_0940:
    ai_rnd_var3_2c $000F
ai_pc_0942:
    ai_if_var3_nz_05_short $0942, $0947
ai_pc_0944:
    ai_call_ff $0988
ai_pc_0947:
    ai_ret_00
ai_pc_0948:
    ai_set_var2_27 $0004
ai_pc_094a:
    ai_call_ff $6AE1
ai_pc_094d:
    ai_if_pos_same_9d_short $094D, $0955
ai_pc_094f:
    ai_pos_save_9f
ai_pc_0950:
    ai_move_toward_e4 $0004, $000A
ai_pc_0953:
    ai_jmp_01_short $0953, $0959
ai_pc_0955:
    ai_pos_save_9f
ai_pc_0956:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_0959:
    ai_dec_var2_20
ai_pc_095a:
    ai_if_var2_nz_04_short $095A, $095F
ai_pc_095c:
    ai_jmp_01_long $095C, $0961
ai_pc_095f:
    ai_if_tgt_not_within_64_56_short $095F, $094A
ai_pc_0961:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0961, $0987
ai_pc_0966:
    ai_if_tgt_not_lane_v_6a_short $0966, $0975
ai_pc_0968:
    ai_flash_fc
ai_pc_0969:
    ai_move_toward_card_be $0000, $0000
ai_pc_096c:
    ai_call_ff $6B0F
ai_pc_096f:
    ai_flash_fc
ai_pc_0970:
    ai_move_toward_e4 $0000, $0000
ai_pc_0973:
    ai_jmp_01_short $0973, $0987
ai_pc_0975:
    ai_if_tgt_not_lane_h_73_short $0975, $0984
ai_pc_0977:
    ai_flash_fc
ai_pc_0978:
    ai_move_toward_card_be $0000, $0000
ai_pc_097b:
    ai_call_ff $6B0F
ai_pc_097e:
    ai_flash_fc
ai_pc_097f:
    ai_move_toward_e4 $0000, $0000
ai_pc_0982:
    ai_jmp_01_short $0982, $0987
ai_pc_0984:
    ai_move_toward_e4 $0000, $0000
ai_pc_0987:
    ai_ret_00
ai_pc_0988:
    ai_if_obj_outside_5f_short $0080, $0988, $09B2
ai_pc_098b:
    ai_move_toward_e4 $0000, $0005
ai_pc_098e:
    ai_if_no_ally_64_54_short $098E, $099F
ai_pc_0990:
    ai_tgt2_ally_d8
ai_pc_0991:
    ai_if_obj_outside_5f_short $0082, $0991, $099A
ai_pc_0994:
    ai_cast_e9 $0003, $000B
ai_pc_0997:
    ai_tgt2_none_c0
ai_pc_0998:
    ai_jmp_01_short $0998, $099D
ai_pc_099a:
    ai_move_toward_e4 $0000, $0005
ai_pc_099d:
    ai_jmp_01_short $099D, $09B2
ai_pc_099f:
    ai_move_toward_e4 $0000, $0000
ai_pc_09a2:
    ai_rnd_var3_2c $0001
ai_pc_09a4:
    ai_if_var3_nz_05_short $09A4, $09AD
ai_pc_09a6:
    ai_tgt2_cur_c1
ai_pc_09a7:
    ai_cast_e9 $0003, $0002
ai_pc_09aa:
    ai_tgt2_none_c0
ai_pc_09ab:
    ai_jmp_01_short $09AB, $09B2
ai_pc_09ad:
    ai_tgt2_cur_c1
ai_pc_09ae:
    ai_cast_e9 $0003, $0001
ai_pc_09b1:
    ai_tgt2_none_c0
ai_pc_09b2:
    ai_ret_00
ai_pc_09b3:
    ai_if_obj_outside_5f_short $0080, $09B3, $09C5
ai_pc_09b6:
    ai_if_var1_lt_17_short $0001, $09B6, $09C5
ai_pc_09b9:
    ai_if_crowd_gt_f5_short $0002, $09B9, $09C5
ai_pc_09bc:
    ai_pose_e2 $0007
ai_pc_09be:
    ai_cmd43_ed $000E
ai_pc_09c0:
    ai_hop_e0 $0004, $000E, $0000
ai_pc_09c4:
    ai_dec_var1_1f
ai_pc_09c5:
    ai_ret_00
ai_pc_09c6:
    ai_if_tgt_not_within_48_51_short $09C6, $09E9
ai_pc_09c8:
    ai_call_ff $6AE1
ai_pc_09cb:
    ai_if_pos_same_9d_short $09CB, $09D3
ai_pc_09cd:
    ai_pos_save_9f
ai_pc_09ce:
    ai_move_away_e6 $0004, $000A
ai_pc_09d1:
    ai_jmp_01_short $09D1, $09D7
ai_pc_09d3:
    ai_pos_save_9f
ai_pc_09d4:
    ai_move_away_alt_fe $0004, $000A
ai_pc_09d7:
    ai_if_tgt_not_within_32_4c_short $09D7, $09E7
ai_pc_09d9:
    ai_if_field_gt_30_short $0080, $006D, $0000, $09D9, $09E7
ai_pc_09de:
    ai_move_toward_e4 $0000, $0000
ai_pc_09e1:
    ai_call_ff $6B0F
ai_pc_09e4:
    ai_move_toward_alt_fd $000E, $0000
ai_pc_09e7:
    ai_jmp_01_short $09E7, $09C6
ai_pc_09e9:
    ai_ret_00
ai_pc_09ea:
    ai_call_ff $0A19
ai_pc_09ed:
    ai_rnd_var3_2c $0007
ai_pc_09ef:
    ai_if_var3_nz_05_short $09EF, $09F6
ai_pc_09f1:
    ai_call_ff $6653
ai_pc_09f4:
    ai_jmp_01_short $09F4, $0A11
ai_pc_09f6:
    ai_call_ff $6AE1
ai_pc_09f9:
    ai_if_tgt_not_within_16_34_short $09F9, $0A00
ai_pc_09fb:
    ai_call_ff $0A1C
ai_pc_09fe:
    ai_jmp_01_short $09FE, $0A11
ai_pc_0a00:
    ai_if_tgt_not_within_48_51_short $0A00, $0A07
ai_pc_0a02:
    ai_call_ff $0A3A
ai_pc_0a05:
    ai_jmp_01_short $0A05, $0A11
ai_pc_0a07:
    ai_if_tgt_not_within_64_56_short $0A07, $0A0E
ai_pc_0a09:
    ai_call_ff $0A4C
ai_pc_0a0c:
    ai_jmp_01_short $0A0C, $0A11
ai_pc_0a0e:
    ai_call_ff $0A94
ai_pc_0a11:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $0A11, $09ED
ai_pc_0a16:
    ai_jmp_01_short $0A16, $09ED
