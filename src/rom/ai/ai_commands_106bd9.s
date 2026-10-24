.setcpu "65816"
.segment "CODE"
.org $6BD9
.include "ai_command_macros.inc"
ai_pc_1cc4:
    ai_pose_e2 $0006
ai_pc_1cc6:
    ai_call_ff $6AE1
ai_pc_1cc9:
    ai_pose_e2 $0006
ai_pc_1ccb:
    ai_if_word_gt_bd_short $0080, $0002, $007C, $0000, $1CCB, $1CD4
ai_pc_1cd1:
    ai_jmp_01_long $1CD1, $1CD6
ai_pc_1cd4:
    ai_if_tgt_not_within_32_4c_short $1CD4, $1CC6
ai_pc_1cd6:
    ai_pose_e2 $0000
ai_pc_1cd8:
    ai_set_var2_27 $0004
ai_pc_1cda:
    ai_hop_e0 $0004, $0000, $0005
ai_pc_1cde:
    ai_hop_e0 $0002, $0000, $0005
ai_pc_1ce2:
    ai_hop_e0 $0008, $0000, $0005
ai_pc_1ce6:
    ai_hop_e0 $0001, $0000, $0005
ai_pc_1cea:
    ai_call_ff $6AE1
ai_pc_1ced:
    ai_dec_var2_20
ai_pc_1cee:
    ai_if_var2_nz_04_short $1CEE, $1CF3
ai_pc_1cf0:
    ai_jmp_01_long $1CF0, $1CF5
ai_pc_1cf3:
    ai_if_tgt_not_within_48_51_short $1CF3, $1CDA
ai_pc_1cf5:
    ai_ret_00
ai_pc_1cf6:
    ai_move_toward_card_be $0000, $0000
ai_pc_1cf9:
    ai_if_field_gt_30_short $0080, $006D, $0000, $1CF9, $1D0B
ai_pc_1cfe:
    ai_move_toward_card_be $0000, $0000
ai_pc_1d01:
    ai_call_ff $6B0F
ai_pc_1d04:
    ai_if_field_gt_30_short $0080, $001D, $0000, $1D04, $1D0B
ai_pc_1d09:
    ai_pose_e2 $000C
ai_pc_1d0b:
    ai_call_ff $1DB3
ai_pc_1d0e:
    ai_ret_00
ai_pc_1d0f:
    ai_move_toward_card_be $0000, $0000
ai_pc_1d12:
    ai_if_tgt_not_within_48_51_short $1D12, $1D3E
ai_pc_1d14:
    ai_call_ff $6AE1
ai_pc_1d17:
    ai_if_pos_same_9d_short $1D17, $1D1F
ai_pc_1d19:
    ai_pos_save_9f
ai_pc_1d1a:
    ai_move_toward_card_be $0005, $0005
ai_pc_1d1d:
    ai_jmp_01_short $1D1D, $1D23
ai_pc_1d1f:
    ai_pos_save_9f
ai_pc_1d20:
    ai_move_toward_alt_fd $0005, $0005
ai_pc_1d23:
    ai_if_field_gt_30_short $0080, $006D, $0000, $1D23, $1D3C
ai_pc_1d28:
    ai_rnd_var3_2c $0001
ai_pc_1d2a:
    ai_if_var3_nz_05_short $1D2A, $1D3C
ai_pc_1d2c:
    ai_move_toward_card_be $0000, $0000
ai_pc_1d2f:
    ai_call_ff $6B0F
ai_pc_1d32:
    ai_if_field_gt_30_short $0080, $001D, $0000, $1D32, $1D39
ai_pc_1d37:
    ai_pose_e2 $000C
ai_pc_1d39:
    ai_call_ff $1DB3
ai_pc_1d3c:
    ai_jmp_01_short $1D3C, $1D12
ai_pc_1d3e:
    ai_ret_00
ai_pc_1d3f:
    ai_move_toward_card_be $0000, $0000
ai_pc_1d42:
    ai_if_field_gt_30_short $0080, $006D, $0000, $1D42, $1D79
ai_pc_1d47:
    ai_if_field_gt_30_short $0080, $001D, $0000, $1D47, $1D55
ai_pc_1d4c:
    ai_tgt2_self_c4
ai_pc_1d4d:
    ai_cast_e9 $0004, $001B
ai_pc_1d50:
    ai_tgt2_none_c0
ai_pc_1d51:
    ai_pose_e2 $0007
ai_pc_1d53:
    ai_jmp_01_short $1D53, $1D58
ai_pc_1d55:
    ai_move_toward_card_be $0000, $0000
ai_pc_1d58:
    ai_rnd_var3_2c $0007
ai_pc_1d5a:
    ai_if_var3_nz_05_short $1D5A, $1D74
ai_pc_1d5c:
    ai_move_toward_card_be $0000, $0000
ai_pc_1d5f:
    ai_move_toward_card_be $0005, $0000
ai_pc_1d62:
    ai_call_ff $1DA1
ai_pc_1d65:
    ai_move_toward_card_be $0000, $0005
ai_pc_1d68:
    ai_call_ff $6B0F
ai_pc_1d6b:
    ai_if_field_gt_30_short $0080, $001D, $0000, $1D6B, $1D72
ai_pc_1d70:
    ai_pose_e2 $000C
ai_pc_1d72:
    ai_jmp_01_short $1D72, $1D77
ai_pc_1d74:
    ai_move_toward_card_be $0000, $0000
ai_pc_1d77:
    ai_jmp_01_short $1D77, $1D7C
ai_pc_1d79:
    ai_move_toward_card_be $0000, $0000
ai_pc_1d7c:
    ai_ret_00
ai_pc_1d7d:
    ai_call_ff $6AE1
ai_pc_1d80:
    ai_if_pos_same_9d_short $1D80, $1D88
ai_pc_1d82:
    ai_pos_save_9f
ai_pc_1d83:
    ai_move_toward_card_be $0002, $0005
ai_pc_1d86:
    ai_jmp_01_short $1D86, $1D8C
ai_pc_1d88:
    ai_pos_save_9f
ai_pc_1d89:
    ai_move_toward_alt_fd $0002, $0005
ai_pc_1d8c:
    ai_rnd_var3_2c $000F
ai_pc_1d8e:
    ai_if_var3_nz_05_short $1D8E, $1D9E
ai_pc_1d90:
    ai_rnd_var3_2c $0001
ai_pc_1d92:
    ai_if_var3_nz_05_short $1D92, $1D9E
ai_pc_1d94:
    ai_move_toward_card_be $0000, $0000
ai_pc_1d97:
    ai_pose_e2 $0003
ai_pc_1d99:
    ai_pose_e2 $0003
ai_pc_1d9b:
    ai_move_toward_card_be $0000, $0000
ai_pc_1d9e:
    ai_if_tgt_not_within_64_56_short $1D9E, $1D7D
ai_pc_1da0:
    ai_ret_00
ai_pc_1da1:
    ai_call_ff $6AE1
ai_pc_1da4:
    ai_if_pos_same_9d_short $1DA4, $1DAC
ai_pc_1da6:
    ai_pos_save_9f
ai_pc_1da7:
    ai_move_toward_card_be $0002, $0005
ai_pc_1daa:
    ai_jmp_01_short $1DAA, $1DB0
ai_pc_1dac:
    ai_pos_save_9f
ai_pc_1dad:
    ai_move_toward_alt_fd $0002, $0005
ai_pc_1db0:
    ai_if_tgt_not_within_32_4c_short $1DB0, $1DA1
ai_pc_1db2:
    ai_ret_00
ai_pc_1db3:
    ai_if_tgt_not_within_48_51_short $1DB3, $1DC6
ai_pc_1db5:
    ai_call_ff $6AE1
ai_pc_1db8:
    ai_if_pos_same_9d_short $1DB8, $1DC0
ai_pc_1dba:
    ai_pos_save_9f
ai_pc_1dbb:
    ai_move_away_card_bf $0002, $0005
ai_pc_1dbe:
    ai_jmp_01_short $1DBE, $1DC4
ai_pc_1dc0:
    ai_pos_save_9f
ai_pc_1dc1:
    ai_move_away_alt_fe $0002, $0005
ai_pc_1dc4:
    ai_jmp_01_short $1DC4, $1DB3
ai_pc_1dc6:
    ai_ret_00
ai_pc_1dc7:
    ai_call_ff $1DF2
ai_pc_1dca:
    ai_rnd_var3_2c $000F
ai_pc_1dcc:
    ai_if_var3_nz_05_short $1DCC, $1DD3
ai_pc_1dce:
    ai_call_ff $693B
ai_pc_1dd1:
    ai_jmp_01_short $1DD1, $1DEA
ai_pc_1dd3:
    ai_call_ff $6AE1
ai_pc_1dd6:
    ai_call_ff $1E0B
ai_pc_1dd9:
    ai_if_tgt_not_within_48_51_short $1DD9, $1DE0
ai_pc_1ddb:
    ai_call_ff $1DF7
ai_pc_1dde:
    ai_jmp_01_short $1DDE, $1DEA
ai_pc_1de0:
    ai_if_tgt_not_within_64_56_short $1DE0, $1DE7
ai_pc_1de2:
    ai_call_ff $1DFB
ai_pc_1de5:
    ai_jmp_01_short $1DE5, $1DEA
ai_pc_1de7:
    ai_call_ff $3B4B
ai_pc_1dea:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $1DEA, $1DCA
ai_pc_1def:
    ai_jmp_01_short $1DEF, $1DCA
