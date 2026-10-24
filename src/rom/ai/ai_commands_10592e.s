.setcpu "65816"
.segment "CODE"
.org $592E
.include "ai_command_macros.inc"
ai_pc_0a19:
    ai_pose_e2 $0000
ai_pc_0a1b:
    ai_ret_00
ai_pc_0a1c:
    ai_move_toward_e4 $0000, $0000
ai_pc_0a1f:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0A1F, $0A36
ai_pc_0a24:
    ai_move_toward_e4 $0000, $0000
ai_pc_0a27:
    ai_call_ff $6B0F
ai_pc_0a2a:
    ai_rnd_var3_2c $000F
ai_pc_0a2c:
    ai_if_var3_nz_05_short $0A2C, $0A36
ai_pc_0a2e:
    ai_if_obj_outside_5f_short $0080, $0A2E, $0A36
ai_pc_0a31:
    ai_tgt2_cur_c1
ai_pc_0a32:
    ai_cast_e9 $0004, $0007
ai_pc_0a35:
    ai_tgt2_none_c0
ai_pc_0a36:
    ai_call_ff $0AEC
ai_pc_0a39:
    ai_ret_00
ai_pc_0a3a:
    ai_move_toward_e4 $0000, $0000
ai_pc_0a3d:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0A3D, $0A48
ai_pc_0a42:
    ai_move_toward_e4 $0000, $0000
ai_pc_0a45:
    ai_call_ff $6B0F
ai_pc_0a48:
    ai_call_ff $0B15
ai_pc_0a4b:
    ai_ret_00
ai_pc_0a4c:
    ai_move_toward_e4 $0000, $0000
ai_pc_0a4f:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0A4F, $0A90
ai_pc_0a54:
    ai_if_tgt_not_lane_v_6a_short $0A54, $0A5E
ai_pc_0a56:
    ai_move_toward_card_be $0000, $0000
ai_pc_0a59:
    ai_call_ff $6B0F
ai_pc_0a5c:
    ai_jmp_01_short $0A5C, $0A8E
ai_pc_0a5e:
    ai_if_tgt_not_lane_h_73_short $0A5E, $0A68
ai_pc_0a60:
    ai_move_toward_card_be $0000, $0000
ai_pc_0a63:
    ai_call_ff $6B0F
ai_pc_0a66:
    ai_jmp_01_short $0A66, $0A8E
ai_pc_0a68:
    ai_move_toward_e4 $0000, $0000
ai_pc_0a6b:
    ai_if_obj_outside_5f_short $0080, $0A6B, $0A8B
ai_pc_0a6e:
    ai_if_no_ally_64_54_short $0A6E, $0A80
ai_pc_0a70:
    ai_tgt2_ally_d8
ai_pc_0a71:
    ai_rnd_var3_2c $000F
ai_pc_0a73:
    ai_if_var3_nz_05_short $0A73, $0A7B
ai_pc_0a75:
    ai_cast_e9 $0004, $000B
ai_pc_0a78:
    ai_tgt2_none_c0
ai_pc_0a79:
    ai_jmp_01_short $0A79, $0A7E
ai_pc_0a7b:
    ai_move_toward_e4 $0000, $0000
ai_pc_0a7e:
    ai_jmp_01_short $0A7E, $0A89
ai_pc_0a80:
    ai_move_toward_e4 $0000, $0000
ai_pc_0a83:
    ai_call_ff $0AD1
ai_pc_0a86:
    ai_call_ff $6B0F
ai_pc_0a89:
    ai_jmp_01_short $0A89, $0A8E
ai_pc_0a8b:
    ai_move_toward_e4 $0000, $0000
ai_pc_0a8e:
    ai_jmp_01_short $0A8E, $0A93
ai_pc_0a90:
    ai_move_toward_e4 $0000, $0000
ai_pc_0a93:
    ai_ret_00
ai_pc_0a94:
    ai_rnd_var3_2c $0004
ai_pc_0a96:
    ai_if_var3_nz_05_short $0A96, $0AA0
ai_pc_0a98:
    ai_hop_e0 $0001, $0000, $001E
ai_pc_0a9c:
    ai_hop_e0 $0002, $0000, $001E
ai_pc_0aa0:
    ai_set_var2_27 $0004
ai_pc_0aa2:
    ai_call_ff $6AE1
ai_pc_0aa5:
    ai_if_pos_same_9d_short $0AA5, $0AAD
ai_pc_0aa7:
    ai_pos_save_9f
ai_pc_0aa8:
    ai_move_toward_card_be $0004, $000A
ai_pc_0aab:
    ai_jmp_01_short $0AAB, $0AB1
ai_pc_0aad:
    ai_pos_save_9f
ai_pc_0aae:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_0ab1:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0AB1, $0AC8
ai_pc_0ab6:
    ai_if_tgt_not_lane_v_6a_short $0AB6, $0AC0
ai_pc_0ab8:
    ai_move_toward_card_be $0000, $0000
ai_pc_0abb:
    ai_call_ff $6B0F
ai_pc_0abe:
    ai_jmp_01_short $0ABE, $0AC8
ai_pc_0ac0:
    ai_if_tgt_not_lane_h_73_short $0AC0, $0AC8
ai_pc_0ac2:
    ai_move_toward_card_be $0000, $0000
ai_pc_0ac5:
    ai_call_ff $6B0F
ai_pc_0ac8:
    ai_dec_var2_20
ai_pc_0ac9:
    ai_if_var2_nz_04_short $0AC9, $0ACE
ai_pc_0acb:
    ai_jmp_01_long $0ACB, $0AD0
ai_pc_0ace:
    ai_if_tgt_not_within_64_56_short $0ACE, $0AA2
ai_pc_0ad0:
    ai_ret_00
ai_pc_0ad1:
    ai_rnd_var3_2c $0001
ai_pc_0ad3:
    ai_call_ff $6AE1
ai_pc_0ad6:
    ai_if_pos_same_9d_short $0AD6, $0ADE
ai_pc_0ad8:
    ai_pos_save_9f
ai_pc_0ad9:
    ai_move_toward_card_be $0001, $0005
ai_pc_0adc:
    ai_jmp_01_short $0ADC, $0AE2
ai_pc_0ade:
    ai_pos_save_9f
ai_pc_0adf:
    ai_move_toward_alt_fd $0001, $0005
ai_pc_0ae2:
    ai_if_var3_nz_05_short $0AE2, $0AE9
ai_pc_0ae4:
    ai_if_tgt_not_within_32_4c_short $0AE4, $0AE9
ai_pc_0ae6:
    ai_jmp_01_long $0AE6, $0AEB
ai_pc_0ae9:
    ai_if_tgt_not_within_48_51_short $0AE9, $0AD3
ai_pc_0aeb:
    ai_ret_00
ai_pc_0aec:
    ai_set_var2_27 $0004
ai_pc_0aee:
    ai_if_tgt_not_within_48_51_short $0AEE, $0B14
ai_pc_0af0:
    ai_call_ff $6AE1
ai_pc_0af3:
    ai_if_pos_same_9d_short $0AF3, $0AFB
ai_pc_0af5:
    ai_pos_save_9f
ai_pc_0af6:
    ai_move_away_card_bf $0004, $000A
ai_pc_0af9:
    ai_jmp_01_short $0AF9, $0AFF
ai_pc_0afb:
    ai_pos_save_9f
ai_pc_0afc:
    ai_move_away_alt_fe $0004, $000A
ai_pc_0aff:
    ai_dec_var2_20
ai_pc_0b00:
    ai_if_tgt_not_within_48_51_short $0B00, $0B12
ai_pc_0b02:
    ai_if_var2_nz_04_short $0B02, $0B12
ai_pc_0b04:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0B04, $0B12
ai_pc_0b09:
    ai_move_toward_card_be $0000, $0000
ai_pc_0b0c:
    ai_call_ff $6B0F
ai_pc_0b0f:
    ai_move_away_e6 $0000, $0005
ai_pc_0b12:
    ai_jmp_01_short $0B12, $0AEE
ai_pc_0b14:
    ai_ret_00
ai_pc_0b15:
    ai_set_var2_27 $0004
ai_pc_0b17:
    ai_if_tgt_not_within_48_51_short $0B17, $0B3D
ai_pc_0b19:
    ai_call_ff $6AE1
ai_pc_0b1c:
    ai_if_pos_same_9d_short $0B1C, $0B24
ai_pc_0b1e:
    ai_pos_save_9f
ai_pc_0b1f:
    ai_move_toward_card_be $0005, $000A
ai_pc_0b22:
    ai_jmp_01_short $0B22, $0B28
ai_pc_0b24:
    ai_pos_save_9f
ai_pc_0b25:
    ai_move_toward_alt_fd $0005, $000A
ai_pc_0b28:
    ai_dec_var2_20
ai_pc_0b29:
    ai_if_tgt_not_within_48_51_short $0B29, $0B3B
ai_pc_0b2b:
    ai_if_var2_nz_04_short $0B2B, $0B3B
ai_pc_0b2d:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0B2D, $0B3B
ai_pc_0b32:
    ai_move_toward_card_be $0000, $0000
ai_pc_0b35:
    ai_call_ff $6B0F
ai_pc_0b38:
    ai_move_away_e6 $0000, $0005
ai_pc_0b3b:
    ai_jmp_01_short $0B3B, $0B17
ai_pc_0b3d:
    ai_ret_00
ai_pc_0b3e:
    ai_call_ff $0B6D
ai_pc_0b41:
    ai_rnd_var3_2c $0007
ai_pc_0b43:
    ai_if_var3_nz_05_short $0B43, $0B4A
ai_pc_0b45:
    ai_turn_facing_e3 $0000, $003C
ai_pc_0b48:
    ai_jmp_01_short $0B48, $0B65
ai_pc_0b4a:
    ai_call_ff $6AE1
ai_pc_0b4d:
    ai_if_tgt_not_within_16_34_short $0B4D, $0B54
ai_pc_0b4f:
    ai_call_ff $0B84
ai_pc_0b52:
    ai_jmp_01_short $0B52, $0B65
ai_pc_0b54:
    ai_if_tgt_not_within_32_4c_short $0B54, $0B5B
ai_pc_0b56:
    ai_call_ff $0BA1
ai_pc_0b59:
    ai_jmp_01_short $0B59, $0B65
ai_pc_0b5b:
    ai_if_tgt_not_within_64_56_short $0B5B, $0B62
ai_pc_0b5d:
    ai_call_ff $0BD3
ai_pc_0b60:
    ai_jmp_01_short $0B60, $0B65
ai_pc_0b62:
    ai_call_ff $0BE7
ai_pc_0b65:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $0B65, $0B41
ai_pc_0b6a:
    ai_jmp_01_short $0B6A, $0B41
