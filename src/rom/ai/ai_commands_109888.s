.setcpu "65816"
.segment "CODE"
.org $9888
.include "ai_command_macros.inc"
ai_pc_4973:
    ai_pose_e2 $0004
ai_pc_4975:
    ai_call_ff $6AE1
ai_pc_4978:
    ai_pose_e2 $0004
ai_pc_497a:
    ai_if_word_gt_bd_short $0080, $0002, $0075, $0002, $497A, $4983
ai_pc_4980:
    ai_jmp_01_long $4980, $4985
ai_pc_4983:
    ai_if_tgt_not_within_32_4c_short $4983, $4975
ai_pc_4985:
    ai_pose_e2 $0000
ai_pc_4987:
    ai_set_var1_26 $000A
ai_pc_4989:
    ai_ret_00
ai_pc_498a:
    ai_move_toward_e4 $0000, $0005
ai_pc_498d:
    ai_if_field_gt_30_short $0080, $006D, $0000, $498D, $4998
ai_pc_4992:
    ai_call_ff $4A95
ai_pc_4995:
    ai_call_ff $6B23
ai_pc_4998:
    ai_call_ff $4AD1
ai_pc_499b:
    ai_ret_00
ai_pc_499c:
    ai_move_toward_e4 $0000, $0005
ai_pc_499f:
    ai_call_ff $4AD1
ai_pc_49a2:
    ai_ret_00
ai_pc_49a3:
    ai_move_toward_e4 $0000, $0005
ai_pc_49a6:
    ai_call_ff $4A76
ai_pc_49a9:
    ai_if_field_lt_2f_short $0080, $0006, $0008, $49A9, $49B3
ai_pc_49ae:
    ai_call_ff $49CE
ai_pc_49b1:
    ai_jmp_01_short $49B1, $49CD
ai_pc_49b3:
    ai_if_var1_nz_03_short $49B3, $49CA
ai_pc_49b5:
    ai_if_field_gt_30_short $0080, $006D, $0000, $49B5, $49C5
ai_pc_49ba:
    ai_call_ff $4A95
ai_pc_49bd:
    ai_call_ff $6B23
ai_pc_49c0:
    ai_call_ff $4AD1
ai_pc_49c3:
    ai_jmp_01_short $49C3, $49C8
ai_pc_49c5:
    ai_move_toward_e4 $0000, $0005
ai_pc_49c8:
    ai_jmp_01_short $49C8, $49CD
ai_pc_49ca:
    ai_move_toward_e4 $0000, $0005
ai_pc_49cd:
    ai_ret_00
ai_pc_49ce:
    ai_set_var2_27 $0000
ai_pc_49d0:
    ai_if_field_gt_30_short $0080, $0038, $0000, $49D0, $49DA
ai_pc_49d5:
    ai_call_ff $4A0D
ai_pc_49d8:
    ai_jmp_01_short $49D8, $4A09
ai_pc_49da:
    ai_if_field_lt_2f_short $0081, $0038, $0001, $49DA, $49E1
ai_pc_49df:
    ai_set_var2_27 $0001
ai_pc_49e1:
    ai_if_word_lt_bc_short $0081, $003D, $0001, $0000, $49E1, $49E9
ai_pc_49e7:
    ai_set_var2_27 $0001
ai_pc_49e9:
    ai_if_field_lt_2f_short $0081, $001D, $0001, $49E9, $49F0
ai_pc_49ee:
    ai_set_var2_27 $0001
ai_pc_49f0:
    ai_if_field_and_z_2e_short $0081, $002E, $00F0, $49F0, $49F7
ai_pc_49f5:
    ai_set_var2_27 $0001
ai_pc_49f7:
    ai_if_var2_lt_18_short $0001, $49F7, $49FF
ai_pc_49fa:
    ai_call_ff $4A30
ai_pc_49fd:
    ai_jmp_01_short $49FD, $4A09
ai_pc_49ff:
    ai_rnd_var3_2c $000F
ai_pc_4a01:
    ai_if_var3_nz_05_short $4A01, $4A06
ai_pc_4a03:
    ai_call_ff $4A53
ai_pc_4a06:
    ai_move_toward_e4 $0000, $0005
ai_pc_4a09:
    ai_move_toward_e4 $0000, $0005
ai_pc_4a0c:
    ai_ret_00
ai_pc_4a0d:
    ai_pose_e2 $0002
ai_pc_4a0f:
    ai_rnd_var3_2c $000F
ai_pc_4a11:
    ai_if_var3_nz_05_short $4A11, $4A28
ai_pc_4a13:
    ai_pose_e2 $0003
ai_pc_4a15:
    ai_pose_e2 $0007
ai_pc_4a17:
    ai_rnd_var3_2c $0007
ai_pc_4a19:
    ai_if_var3_nz_05_short $4A19, $4A22
ai_pc_4a1b:
    ai_tgt2_self_c4
ai_pc_4a1c:
    ai_cast_e9 $0005, $0022
ai_pc_4a1f:
    ai_tgt2_none_c0
ai_pc_4a20:
    ai_jmp_01_short $4A20, $4A26
ai_pc_4a22:
    ai_pose_e2 $0003
ai_pc_4a24:
    ai_pose_e2 $0007
ai_pc_4a26:
    ai_jmp_01_short $4A26, $4A2D
ai_pc_4a28:
    ai_tgt2_self_c4
ai_pc_4a29:
    ai_cast_e9 $0005, $0022
ai_pc_4a2c:
    ai_tgt2_none_c0
ai_pc_4a2d:
    ai_pose_e2 $0008
ai_pc_4a2f:
    ai_ret_00
ai_pc_4a30:
    ai_pose_e2 $0002
ai_pc_4a32:
    ai_rnd_var3_2c $000F
ai_pc_4a34:
    ai_if_var3_nz_05_short $4A34, $4A4B
ai_pc_4a36:
    ai_pose_e2 $0003
ai_pc_4a38:
    ai_pose_e2 $0007
ai_pc_4a3a:
    ai_rnd_var3_2c $0007
ai_pc_4a3c:
    ai_if_var3_nz_05_short $4A3C, $4A45
ai_pc_4a3e:
    ai_tgt2_cur_c1
ai_pc_4a3f:
    ai_cast_e9 $0005, $0026
ai_pc_4a42:
    ai_tgt2_none_c0
ai_pc_4a43:
    ai_jmp_01_short $4A43, $4A49
ai_pc_4a45:
    ai_pose_e2 $0003
ai_pc_4a47:
    ai_pose_e2 $0007
ai_pc_4a49:
    ai_jmp_01_short $4A49, $4A50
ai_pc_4a4b:
    ai_tgt2_cur_c1
ai_pc_4a4c:
    ai_cast_e9 $0005, $0026
ai_pc_4a4f:
    ai_tgt2_none_c0
ai_pc_4a50:
    ai_pose_e2 $0008
ai_pc_4a52:
    ai_ret_00
ai_pc_4a53:
    ai_pose_e2 $0002
ai_pc_4a55:
    ai_rnd_var3_2c $000F
ai_pc_4a57:
    ai_if_var3_nz_05_short $4A57, $4A6E
ai_pc_4a59:
    ai_pose_e2 $0003
ai_pc_4a5b:
    ai_pose_e2 $0007
ai_pc_4a5d:
    ai_rnd_var3_2c $0007
ai_pc_4a5f:
    ai_if_var3_nz_05_short $4A5F, $4A68
ai_pc_4a61:
    ai_tgt2_cur_c1
ai_pc_4a62:
    ai_cast_e9 $0005, $0024
ai_pc_4a65:
    ai_tgt2_none_c0
ai_pc_4a66:
    ai_jmp_01_short $4A66, $4A6C
ai_pc_4a68:
    ai_pose_e2 $0003
ai_pc_4a6a:
    ai_pose_e2 $0007
ai_pc_4a6c:
    ai_jmp_01_short $4A6C, $4A73
ai_pc_4a6e:
    ai_tgt2_cur_c1
ai_pc_4a6f:
    ai_cast_e9 $0005, $0024
ai_pc_4a72:
    ai_tgt2_none_c0
ai_pc_4a73:
    ai_pose_e2 $0008
ai_pc_4a75:
    ai_ret_00
ai_pc_4a76:
    ai_if_obj_outside_5f_short $0080, $4A76, $4A94
ai_pc_4a79:
    ai_if_var1_lt_17_short $0001, $4A79, $4A94
ai_pc_4a7c:
    ai_if_crowd_gt_f5_short $0002, $4A7C, $4A91
ai_pc_4a7f:
    ai_pose_e2 $0002
ai_pc_4a81:
    ai_if_crowd_gt_f5_short $0002, $4A81, $4A8B
ai_pc_4a84:
    ai_pose_e2 $0006
ai_pc_4a86:
    ai_cmd43_ed $0037
ai_pc_4a88:
    ai_dec_var1_1f
ai_pc_4a89:
    ai_jmp_01_short $4A89, $4A8D
ai_pc_4a8b:
    ai_pose_e2 $0007
ai_pc_4a8d:
    ai_pose_e2 $0008
ai_pc_4a8f:
    ai_jmp_01_short $4A8F, $4A94
ai_pc_4a91:
    ai_move_toward_e4 $0000, $0005
ai_pc_4a94:
    ai_ret_00
ai_pc_4a95:
    ai_rnd_var3_2c $0001
ai_pc_4a97:
    ai_call_ff $6AE1
ai_pc_4a9a:
    ai_if_pos_same_9d_short $4A9A, $4AA2
ai_pc_4a9c:
    ai_pos_save_9f
ai_pc_4a9d:
    ai_move_toward_e4 $0002, $0000
ai_pc_4aa0:
    ai_jmp_01_short $4AA0, $4AA6
ai_pc_4aa2:
    ai_pos_save_9f
ai_pc_4aa3:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_4aa6:
    ai_if_var3_nz_05_short $4AA6, $4AAD
ai_pc_4aa8:
    ai_if_tgt_not_within_48_51_short $4AA8, $4AAD
ai_pc_4aaa:
    ai_jmp_01_long $4AAA, $4AAF
ai_pc_4aad:
    ai_if_tgt_not_within_32_4c_short $4AAD, $4A97
ai_pc_4aaf:
    ai_ret_00
ai_pc_4ab0:
    ai_call_ff $6AE1
ai_pc_4ab3:
    ai_if_pos_same_9d_short $4AB3, $4ABB
ai_pc_4ab5:
    ai_pos_save_9f
ai_pc_4ab6:
    ai_move_toward_e4 $0004, $0000
ai_pc_4ab9:
    ai_jmp_01_short $4AB9, $4ABF
ai_pc_4abb:
    ai_pos_save_9f
ai_pc_4abc:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_4abf:
    ai_rnd_var3_2c $000F
ai_pc_4ac1:
    ai_if_var3_nz_05_short $4AC1, $4ACE
ai_pc_4ac3:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4AC3, $4ACE
ai_pc_4ac8:
    ai_move_toward_alt_fd $0000, $0005
ai_pc_4acb:
    ai_call_ff $6B23
ai_pc_4ace:
    ai_if_tgt_not_within_64_56_short $4ACE, $4AB0
ai_pc_4ad0:
    ai_ret_00
ai_pc_4ad1:
    ai_if_tgt_not_within_48_51_short $4AD1, $4AE4
ai_pc_4ad3:
    ai_call_ff $6AE1
ai_pc_4ad6:
    ai_if_pos_same_9d_short $4AD6, $4ADE
ai_pc_4ad8:
    ai_pos_save_9f
ai_pc_4ad9:
    ai_move_away_e6 $0002, $0000
ai_pc_4adc:
    ai_jmp_01_short $4ADC, $4AE2
ai_pc_4ade:
    ai_pos_save_9f
ai_pc_4adf:
    ai_move_away_alt_fe $0002, $0000
ai_pc_4ae2:
    ai_jmp_01_short $4AE2, $4AD1
ai_pc_4ae4:
    ai_ret_00
ai_pc_4ae5:
    ai_call_ff $4B14
ai_pc_4ae8:
    ai_rnd_var3_2c $000F
ai_pc_4aea:
    ai_if_var3_nz_05_short $4AEA, $4AF1
ai_pc_4aec:
    ai_move_toward_e4 $0000, $001E
ai_pc_4aef:
    ai_jmp_01_short $4AEF, $4B0C
ai_pc_4af1:
    ai_call_ff $6AE1
ai_pc_4af4:
    ai_if_tgt_not_within_32_4c_short $4AF4, $4AFB
ai_pc_4af6:
    ai_call_ff $4B36
ai_pc_4af9:
    ai_jmp_01_short $4AF9, $4B0C
ai_pc_4afb:
    ai_if_tgt_not_within_48_51_short $4AFB, $4B02
ai_pc_4afd:
    ai_call_ff $4B48
ai_pc_4b00:
    ai_jmp_01_short $4B00, $4B0C
ai_pc_4b02:
    ai_if_tgt_not_within_64_56_short $4B02, $4B09
ai_pc_4b04:
    ai_call_ff $4B6D
ai_pc_4b07:
    ai_jmp_01_short $4B07, $4B0C
ai_pc_4b09:
    ai_call_ff $4BAA
ai_pc_4b0c:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $4B0C, $4AE8
ai_pc_4b11:
    ai_jmp_01_short $4B11, $4AE8
