.setcpu "65816"
.segment "CODE"
.org $687B
.include "ai_command_macros.inc"
ai_pc_1966:
    ai_pose_e2 $0000
ai_pc_1968:
    ai_call_ff $6AE1
ai_pc_196b:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_196f:
    ai_call_ff $6B19
ai_pc_1972:
    ai_ret_00
ai_pc_1973:
    ai_if_tgt_not_within_32_4c_short $1973, $1978
ai_pc_1975:
    ai_move_toward_e4 $000E, $0000
ai_pc_1978:
    ai_if_tgt_not_within_48_51_short $1978, $19A2
ai_pc_197a:
    ai_call_ff $6AE1
ai_pc_197d:
    ai_if_field_gt_30_short $0080, $006D, $0000, $197D, $1994
ai_pc_1982:
    ai_if_tgt_not_lane_v64_66_short $1982, $198C
ai_pc_1984:
    ai_move_toward_card_be $0000, $0005
ai_pc_1987:
    ai_call_ff $6B19
ai_pc_198a:
    ai_jmp_01_short $198A, $1994
ai_pc_198c:
    ai_if_tgt_not_lane_h64_6f_short $198C, $1994
ai_pc_198e:
    ai_move_toward_card_be $0000, $0005
ai_pc_1991:
    ai_call_ff $6B19
ai_pc_1994:
    ai_if_pos_same_9d_short $1994, $199C
ai_pc_1996:
    ai_pos_save_9f
ai_pc_1997:
    ai_move_away_card_bf $0002, $0005
ai_pc_199a:
    ai_jmp_01_short $199A, $19A0
ai_pc_199c:
    ai_pos_save_9f
ai_pc_199d:
    ai_move_away_alt_fe $0002, $0005
ai_pc_19a0:
    ai_jmp_01_short $19A0, $1978
ai_pc_19a2:
    ai_ret_00
ai_pc_19a3:
    ai_move_toward_e4 $0000, $0005
ai_pc_19a6:
    ai_rnd_var3_2c $0007
ai_pc_19a8:
    ai_if_var3_nz_05_short $19A8, $19B7
ai_pc_19aa:
    ai_if_field_gt_30_short $0080, $001D, $0000, $19AA, $19B7
ai_pc_19af:
    ai_tgt2_self_c4
ai_pc_19b0:
    ai_cast_e9 $0002, $000F
ai_pc_19b3:
    ai_tgt2_none_c0
ai_pc_19b4:
    ai_move_toward_e4 $0000, $003C
ai_pc_19b7:
    ai_move_toward_e4 $0000, $0005
ai_pc_19ba:
    ai_if_field_gt_30_short $0080, $006D, $0000, $19BA, $19D8
ai_pc_19bf:
    ai_if_tgt_not_lane_v64_66_short $19BF, $19C9
ai_pc_19c1:
    ai_move_toward_card_be $0000, $0005
ai_pc_19c4:
    ai_call_ff $6B19
ai_pc_19c7:
    ai_jmp_01_short $19C7, $19D6
ai_pc_19c9:
    ai_if_tgt_not_lane_h64_6f_short $19C9, $19D3
ai_pc_19cb:
    ai_move_toward_card_be $0000, $0005
ai_pc_19ce:
    ai_call_ff $6B19
ai_pc_19d1:
    ai_jmp_01_short $19D1, $19D6
ai_pc_19d3:
    ai_call_ff $6653
ai_pc_19d6:
    ai_jmp_01_short $19D6, $19DB
ai_pc_19d8:
    ai_move_toward_e4 $0000, $0000
ai_pc_19db:
    ai_ret_00
ai_pc_19dc:
    ai_call_ff $6AE1
ai_pc_19df:
    ai_if_pos_same_9d_short $19DF, $19E7
ai_pc_19e1:
    ai_pos_save_9f
ai_pc_19e2:
    ai_move_toward_card_be $0002, $0005
ai_pc_19e5:
    ai_jmp_01_short $19E5, $19EB
ai_pc_19e7:
    ai_pos_save_9f
ai_pc_19e8:
    ai_move_toward_alt_fd $0002, $0005
ai_pc_19eb:
    ai_if_field_gt_30_short $0080, $006D, $0000, $19EB, $1A02
ai_pc_19f0:
    ai_if_tgt_not_lane_v_6a_short $19F0, $19FA
ai_pc_19f2:
    ai_move_toward_card_be $0000, $0005
ai_pc_19f5:
    ai_call_ff $6B19
ai_pc_19f8:
    ai_jmp_01_short $19F8, $1A02
ai_pc_19fa:
    ai_if_tgt_not_lane_h_73_short $19FA, $1A02
ai_pc_19fc:
    ai_move_toward_card_be $0000, $0005
ai_pc_19ff:
    ai_call_ff $6B19
ai_pc_1a02:
    ai_if_tgt_not_within_64_56_short $1A02, $19DC
ai_pc_1a04:
    ai_ret_00
ai_pc_1a05:
    ai_call_ff $1A37
ai_pc_1a08:
    ai_call_ff $1A7E
ai_pc_1a0b:
    ai_rnd_var3_2c $000F
ai_pc_1a0d:
    ai_if_var3_nz_05_short $1A0D, $1A14
ai_pc_1a0f:
    ai_call_ff $693B
ai_pc_1a12:
    ai_jmp_01_short $1A12, $1A2F
ai_pc_1a14:
    ai_call_ff $6AE1
ai_pc_1a17:
    ai_if_tgt_not_within_32_4c_short $1A17, $1A1E
ai_pc_1a19:
    ai_call_ff $0D5C
ai_pc_1a1c:
    ai_jmp_01_short $1A1C, $1A2F
ai_pc_1a1e:
    ai_if_tgt_not_within_48_51_short $1A1E, $1A25
ai_pc_1a20:
    ai_call_ff $1A3D
ai_pc_1a23:
    ai_jmp_01_short $1A23, $1A2F
ai_pc_1a25:
    ai_if_tgt_not_within_64_56_short $1A25, $1A2C
ai_pc_1a27:
    ai_call_ff $0DB1
ai_pc_1a2a:
    ai_jmp_01_short $1A2A, $1A2F
ai_pc_1a2c:
    ai_call_ff $0DB1
ai_pc_1a2f:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $1A2F, $1A08
ai_pc_1a34:
    ai_jmp_01_short $1A34, $1A08
