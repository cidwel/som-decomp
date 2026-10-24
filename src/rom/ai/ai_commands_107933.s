.setcpu "65816"
.segment "CODE"
.org $7933
.include "ai_command_macros.inc"
ai_pc_2a1e:
    ai_pose_e2 $0000
ai_pc_2a20:
    ai_rnd_var3_2c $0001
ai_pc_2a22:
    ai_if_var3_nz_05_short $2A22, $2A2E
ai_pc_2a24:
    ai_hop_e0 $0002, $0000, $001E
ai_pc_2a28:
    ai_hop_e0 $0001, $0000, $001E
ai_pc_2a2c:
    ai_jmp_01_short $2A2C, $2A36
ai_pc_2a2e:
    ai_hop_e0 $0001, $0000, $001E
ai_pc_2a32:
    ai_hop_e0 $0002, $0000, $001E
ai_pc_2a36:
    ai_ret_00
ai_pc_2a37:
    ai_move_toward_e4 $0000, $0000
ai_pc_2a3a:
    ai_if_word_gt_bd_short $0080, $0002, $0077, $0002, $2A3A, $2A48
ai_pc_2a40:
    ai_move_toward_e4 $0003, $0000
ai_pc_2a43:
    ai_tgt2_cur_c1
ai_pc_2a44:
    ai_cast_e9 $0001, $0008
ai_pc_2a47:
    ai_tgt2_none_c0
ai_pc_2a48:
    ai_call_ff $2AD7
ai_pc_2a4b:
    ai_ret_00
ai_pc_2a4c:
    ai_move_toward_e4 $0000, $0000
ai_pc_2a4f:
    ai_rnd_var3_2c $000F
ai_pc_2a51:
    ai_if_var3_nz_05_short $2A51, $2A58
ai_pc_2a53:
    ai_call_ff $2A6B
ai_pc_2a56:
    ai_jmp_01_short $2A56, $2A6A
ai_pc_2a58:
    ai_move_toward_e4 $0000, $0000
ai_pc_2a5b:
    ai_rnd_var3_2c $0007
ai_pc_2a5d:
    ai_if_var3_nz_05_short $2A5D, $2A6A
ai_pc_2a5f:
    ai_hop_e0 $0002, $0003, $001E
ai_pc_2a63:
    ai_hop_e0 $0001, $0003, $001E
ai_pc_2a67:
    ai_move_toward_e4 $0000, $0000
ai_pc_2a6a:
    ai_ret_00
ai_pc_2a6b:
    ai_move_away_e6 $0004, $0000
ai_pc_2a6e:
    ai_move_away_e6 $0004, $0000
ai_pc_2a71:
    ai_call_ff $2AC5
ai_pc_2a74:
    ai_pose_e2 $0003
ai_pc_2a76:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $2A76, $2A80
ai_pc_2a7b:
    ai_set_var1_26 $0000
ai_pc_2a7d:
    ai_jmp_01_long $2A7D, $2A86
ai_pc_2a80:
    ai_pose_e2 $0003
ai_pc_2a82:
    ai_set_var1_26 $0001
ai_pc_2a84:
    ai_if_tgt_not_beyond_64_5a_short $2A84, $2A76
ai_pc_2a86:
    ai_move_toward_e4 $000B, $0000
ai_pc_2a89:
    ai_if_var1_ne_0b_short $0001, $2A89, $2AB2
ai_pc_2a8c:
    ai_if_obj_outside_5f_short $0080, $2A8C, $2AAF
ai_pc_2a8f:
    ai_if_word_gt_bd_short $0080, $0002, $0077, $0002, $2A8F, $2AA2
ai_pc_2a95:
    ai_move_toward_e4 $0000, $0000
ai_pc_2a98:
    ai_tgt2_cur_c1
ai_pc_2a99:
    ai_cast_e9 $0002, $0008
ai_pc_2a9c:
    ai_tgt2_none_c0
ai_pc_2a9d:
    ai_move_toward_e4 $0000, $00B4
ai_pc_2aa0:
    ai_jmp_01_short $2AA0, $2AAD
ai_pc_2aa2:
    ai_move_toward_e4 $0000, $0000
ai_pc_2aa5:
    ai_tgt2_cur_c1
ai_pc_2aa6:
    ai_cast_e9 $0002, $0006
ai_pc_2aa9:
    ai_tgt2_none_c0
ai_pc_2aaa:
    ai_move_toward_e4 $0000, $00B4
ai_pc_2aad:
    ai_jmp_01_short $2AAD, $2AB2
ai_pc_2aaf:
    ai_move_toward_e4 $0000, $0000
ai_pc_2ab2:
    ai_ret_00
ai_pc_2ab3:
    ai_call_ff $6AE1
ai_pc_2ab6:
    ai_if_pos_same_9d_short $2AB6, $2ABE
ai_pc_2ab8:
    ai_pos_save_9f
ai_pc_2ab9:
    ai_move_toward_e4 $0004, $0000
ai_pc_2abc:
    ai_jmp_01_short $2ABC, $2AC2
ai_pc_2abe:
    ai_pos_save_9f
ai_pc_2abf:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_2ac2:
    ai_if_tgt_not_within_48_51_short $2AC2, $2AB3
ai_pc_2ac4:
    ai_ret_00
ai_pc_2ac5:
    ai_call_ff $6AE1
ai_pc_2ac8:
    ai_if_pos_same_9d_short $2AC8, $2AD0
ai_pc_2aca:
    ai_pos_save_9f
ai_pc_2acb:
    ai_move_toward_e4 $0001, $0000
ai_pc_2ace:
    ai_jmp_01_short $2ACE, $2AD4
ai_pc_2ad0:
    ai_pos_save_9f
ai_pc_2ad1:
    ai_move_toward_alt_fd $0001, $0000
ai_pc_2ad4:
    ai_if_tgt_not_within_16_34_short $2AD4, $2AC5
ai_pc_2ad6:
    ai_ret_00
ai_pc_2ad7:
    ai_if_tgt_not_within_32_4c_short $2AD7, $2AEA
ai_pc_2ad9:
    ai_call_ff $6AE1
ai_pc_2adc:
    ai_if_pos_same_9d_short $2ADC, $2AE4
ai_pc_2ade:
    ai_pos_save_9f
ai_pc_2adf:
    ai_move_away_e6 $0001, $0000
ai_pc_2ae2:
    ai_jmp_01_short $2AE2, $2AE8
ai_pc_2ae4:
    ai_pos_save_9f
ai_pc_2ae5:
    ai_move_away_alt_fe $0001, $0000
ai_pc_2ae8:
    ai_jmp_01_short $2AE8, $2AD7
ai_pc_2aea:
    ai_ret_00
ai_pc_2aeb:
    ai_call_ff $2B1A
ai_pc_2aee:
    ai_rnd_var3_2c $000F
ai_pc_2af0:
    ai_if_var3_nz_05_short $2AF0, $2AF7
ai_pc_2af2:
    ai_call_ff $6993
ai_pc_2af5:
    ai_jmp_01_short $2AF5, $2B12
ai_pc_2af7:
    ai_call_ff $6AE1
ai_pc_2afa:
    ai_if_tgt_not_within_32_4c_short $2AFA, $2B01
ai_pc_2afc:
    ai_call_ff $2B44
ai_pc_2aff:
    ai_jmp_01_short $2AFF, $2B12
ai_pc_2b01:
    ai_if_tgt_not_within_48_51_short $2B01, $2B08
ai_pc_2b03:
    ai_call_ff $2B6A
ai_pc_2b06:
    ai_jmp_01_short $2B06, $2B12
ai_pc_2b08:
    ai_if_tgt_not_within_64_56_short $2B08, $2B0F
ai_pc_2b0a:
    ai_call_ff $2B8A
ai_pc_2b0d:
    ai_jmp_01_short $2B0D, $2B12
ai_pc_2b0f:
    ai_call_ff $2BB7
ai_pc_2b12:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $2B12, $2AEE
ai_pc_2b17:
    ai_jmp_01_short $2B17, $2AEE
