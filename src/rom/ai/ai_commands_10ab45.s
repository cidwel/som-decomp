.setcpu "65816"
.segment "CODE"
.org $AB45
.include "ai_command_macros.inc"
ai_pc_5c30:
    ai_if_field_gt_30_short $0080, $002C, $00FE, $5C30, $5C6A
ai_pc_5c35:
    ai_call_ff $5913
ai_pc_5c38:
    ai_if_tgt_not_within_64_56_short $5C38, $5C5B
ai_pc_5c3a:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5C3A, $5C56
ai_pc_5c3f:
    ai_if_charge_set_f2_short $0000, $5C3F, $5C51
ai_pc_5c42:
    ai_rnd_var2_2b $000F
ai_pc_5c44:
    ai_call_ff $5D1A
ai_pc_5c47:
    ai_move_toward_e4 $0003, $0005
ai_pc_5c4a:
    ai_swing_plain_df
ai_pc_5c4b:
    ai_move_toward_e4 $0013, $0000
ai_pc_5c4e:
    ai_charge_start_f3
ai_pc_5c4f:
    ai_jmp_01_short $5C4F, $5C54
ai_pc_5c51:
    ai_call_ff $5D5B
ai_pc_5c54:
    ai_jmp_01_short $5C54, $5C59
ai_pc_5c56:
    ai_call_ff $5D5B
ai_pc_5c59:
    ai_jmp_01_short $5C59, $5C68
ai_pc_5c5b:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5C5B, $5C65
ai_pc_5c60:
    ai_call_ff $5CF6
ai_pc_5c63:
    ai_jmp_01_short $5C63, $5C68
ai_pc_5c65:
    ai_move_toward_e4 $0000, $0005
ai_pc_5c68:
    ai_jmp_01_short $5C68, $5C30
ai_pc_5c6a:
    ai_ret_00
ai_pc_5c6b:
    ai_if_field_gt_30_short $0080, $002C, $00FE, $5C6B, $5CA2
ai_pc_5c70:
    ai_call_ff $5913
ai_pc_5c73:
    ai_if_tgt_not_within_64_56_short $5C73, $5C93
ai_pc_5c75:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5C75, $5C8E
ai_pc_5c7a:
    ai_if_charge_set_f2_short $0000, $5C7A, $5C89
ai_pc_5c7d:
    ai_rnd_var2_2b $000F
ai_pc_5c7f:
    ai_call_ff $5D81
ai_pc_5c82:
    ai_move_toward_e4 $0003, $0005
ai_pc_5c85:
    ai_swing_plain_df
ai_pc_5c86:
    ai_charge_start_f3
ai_pc_5c87:
    ai_jmp_01_short $5C87, $5C8C
ai_pc_5c89:
    ai_call_ff $5DC2
ai_pc_5c8c:
    ai_jmp_01_short $5C8C, $5C91
ai_pc_5c8e:
    ai_call_ff $5DC2
ai_pc_5c91:
    ai_jmp_01_short $5C91, $5CA0
ai_pc_5c93:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5C93, $5C9D
ai_pc_5c98:
    ai_call_ff $5CF6
ai_pc_5c9b:
    ai_jmp_01_short $5C9B, $5CA0
ai_pc_5c9d:
    ai_move_toward_e4 $0000, $0005
ai_pc_5ca0:
    ai_jmp_01_short $5CA0, $5C6B
ai_pc_5ca2:
    ai_ret_00
ai_pc_5ca3:
    ai_if_field_gt_30_long $0080, $002C, $00FE, $5CA3, $5CF5
ai_pc_5ca9:
    ai_call_ff $5913
ai_pc_5cac:
    ai_if_tgt_not_within_64_56_short $5CAC, $5CE5
ai_pc_5cae:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5CAE, $5CD9
ai_pc_5cb3:
    ai_if_charge_set_f2_short $0000, $5CB3, $5CCD
ai_pc_5cb6:
    ai_if_tgt_not_lane_v64_66_short $5CB6, $5CBF
ai_pc_5cb8:
    ai_move_toward_card_be $0003, $0005
ai_pc_5cbb:
    ai_swing_plain_df
ai_pc_5cbc:
    ai_charge_start_f3
ai_pc_5cbd:
    ai_jmp_01_short $5CBD, $5CCB
ai_pc_5cbf:
    ai_if_tgt_not_lane_h64_6f_short $5CBF, $5CC8
ai_pc_5cc1:
    ai_move_toward_card_be $0003, $0005
ai_pc_5cc4:
    ai_swing_plain_df
ai_pc_5cc5:
    ai_charge_start_f3
ai_pc_5cc6:
    ai_jmp_01_short $5CC6, $5CCB
ai_pc_5cc8:
    ai_call_ff $593D
ai_pc_5ccb:
    ai_jmp_01_short $5CCB, $5CD7
ai_pc_5ccd:
    ai_if_tgt_not_band_64_46_short $5CCD, $5CD4
ai_pc_5ccf:
    ai_move_toward_card_be $0003, $0005
ai_pc_5cd2:
    ai_jmp_01_short $5CD2, $5CD7
ai_pc_5cd4:
    ai_call_ff $5DE5
ai_pc_5cd7:
    ai_jmp_01_short $5CD7, $5CE3
ai_pc_5cd9:
    ai_if_tgt_not_band_64_46_short $5CD9, $5CE0
ai_pc_5cdb:
    ai_move_toward_card_be $0003, $0005
ai_pc_5cde:
    ai_jmp_01_short $5CDE, $5CE3
ai_pc_5ce0:
    ai_call_ff $5DE5
ai_pc_5ce3:
    ai_jmp_01_short $5CE3, $5CF2
ai_pc_5ce5:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5CE5, $5CEF
ai_pc_5cea:
    ai_call_ff $5D08
ai_pc_5ced:
    ai_jmp_01_short $5CED, $5CF2
ai_pc_5cef:
    ai_move_toward_card_be $0000, $0005
ai_pc_5cf2:
    ai_jmp_01_long $5CF2, $5CA3
ai_pc_5cf5:
    ai_ret_00
ai_pc_5cf6:
    ai_call_ff $5913
ai_pc_5cf9:
    ai_if_pos_same_9d_short $5CF9, $5D01
ai_pc_5cfb:
    ai_pos_save_9f
ai_pc_5cfc:
    ai_move_toward_e4 $000B, $000A
ai_pc_5cff:
    ai_jmp_01_short $5CFF, $5D05
ai_pc_5d01:
    ai_pos_save_9f
ai_pc_5d02:
    ai_move_toward_alt_fd $000B, $000A
ai_pc_5d05:
    ai_if_tgt_not_within_64_56_short $5D05, $5CF6
ai_pc_5d07:
    ai_ret_00
ai_pc_5d08:
    ai_call_ff $5913
ai_pc_5d0b:
    ai_if_pos_same_9d_short $5D0B, $5D13
ai_pc_5d0d:
    ai_pos_save_9f
ai_pc_5d0e:
    ai_move_toward_card_be $000B, $000A
ai_pc_5d11:
    ai_jmp_01_short $5D11, $5D17
ai_pc_5d13:
    ai_pos_save_9f
ai_pc_5d14:
    ai_move_toward_alt_fd $000B, $000A
ai_pc_5d17:
    ai_if_tgt_not_within_64_56_short $5D17, $5D08
ai_pc_5d19:
    ai_ret_00
ai_pc_5d1a:
    ai_set_var0_25 $0000
ai_pc_5d1c:
    ai_set_var1_26 $0004
ai_pc_5d1e:
    ai_call_ff $5913
ai_pc_5d21:
    ai_if_var0_nz_02_short $5D21, $5D29
ai_pc_5d23:
    ai_call_ff $595E
ai_pc_5d26:
    ai_inc_var0_1a
ai_pc_5d27:
    ai_jmp_01_short $5D27, $5D40
ai_pc_5d29:
    ai_if_var0_ne_0a_short $0001, $5D29, $5D32
ai_pc_5d2c:
    ai_call_ff $596B
ai_pc_5d2f:
    ai_inc_var0_1a
ai_pc_5d30:
    ai_jmp_01_short $5D30, $5D40
ai_pc_5d32:
    ai_if_var0_ne_0a_short $0002, $5D32, $5D3B
ai_pc_5d35:
    ai_call_ff $596B
ai_pc_5d38:
    ai_inc_var0_1a
ai_pc_5d39:
    ai_jmp_01_short $5D39, $5D40
ai_pc_5d3b:
    ai_call_ff $595E
ai_pc_5d3e:
    ai_set_var0_25 $0000
ai_pc_5d40:
    ai_if_var2_gt_14_short $0001, $5D40, $5D4A
ai_pc_5d43:
    ai_if_tgt_not_within_64_56_short $5D43, $5D48
ai_pc_5d45:
    ai_jmp_01_long $5D45, $5D5A
ai_pc_5d48:
    ai_jmp_01_short $5D48, $5D52
ai_pc_5d4a:
    ai_if_var2_gt_14_short $0005, $5D4A, $5D52
ai_pc_5d4d:
    ai_if_tgt_not_within_48_51_short $5D4D, $5D52
ai_pc_5d4f:
    ai_jmp_01_long $5D4F, $5D5A
ai_pc_5d52:
    ai_dec_var1_1f
ai_pc_5d53:
    ai_if_var1_nz_03_short $5D53, $5D58
ai_pc_5d55:
    ai_jmp_01_long $5D55, $5D5A
ai_pc_5d58:
    ai_if_tgt_not_within_32_4c_short $5D58, $5D1E
ai_pc_5d5a:
    ai_ret_00
ai_pc_5d5b:
    ai_if_tgt_not_within_48_51_short $5D5B, $5D80
ai_pc_5d5d:
    ai_call_ff $5913
ai_pc_5d60:
    ai_if_tgt_not_within_32_4c_short $5D60, $5D6A
ai_pc_5d62:
    ai_move_toward_e4 $0003, $0005
ai_pc_5d65:
    ai_swing_plain_df
ai_pc_5d66:
    ai_move_toward_e4 $0013, $0000
ai_pc_5d69:
    ai_charge_start_f3
ai_pc_5d6a:
    ai_if_pos_same_9d_short $5D6A, $5D72
ai_pc_5d6c:
    ai_pos_save_9f
ai_pc_5d6d:
    ai_move_toward_e4 $000C, $000A
ai_pc_5d70:
    ai_jmp_01_short $5D70, $5D76
ai_pc_5d72:
    ai_pos_save_9f
ai_pc_5d73:
    ai_move_toward_alt_fd $000C, $000A
ai_pc_5d76:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5D76, $5D7E
ai_pc_5d7b:
    ai_jmp_01_long $5D7B, $5D80
ai_pc_5d7e:
    ai_jmp_01_short $5D7E, $5D5B
ai_pc_5d80:
    ai_ret_00
ai_pc_5d81:
    ai_set_var0_25 $0000
ai_pc_5d83:
    ai_set_var1_26 $0004
ai_pc_5d85:
    ai_call_ff $5913
ai_pc_5d88:
    ai_if_var0_nz_02_short $5D88, $5D90
ai_pc_5d8a:
    ai_call_ff $595E
ai_pc_5d8d:
    ai_inc_var0_1a
ai_pc_5d8e:
    ai_jmp_01_short $5D8E, $5DA7
ai_pc_5d90:
    ai_if_var0_ne_0a_short $0001, $5D90, $5D99
ai_pc_5d93:
    ai_call_ff $596B
ai_pc_5d96:
    ai_inc_var0_1a
ai_pc_5d97:
    ai_jmp_01_short $5D97, $5DA7
ai_pc_5d99:
    ai_if_var0_ne_0a_short $0002, $5D99, $5DA2
ai_pc_5d9c:
    ai_call_ff $596B
ai_pc_5d9f:
    ai_inc_var0_1a
ai_pc_5da0:
    ai_jmp_01_short $5DA0, $5DA7
ai_pc_5da2:
    ai_call_ff $595E
ai_pc_5da5:
    ai_set_var0_25 $0000
ai_pc_5da7:
    ai_if_var2_gt_14_short $0002, $5DA7, $5DB1
ai_pc_5daa:
    ai_if_tgt_not_within_64_56_short $5DAA, $5DAF
ai_pc_5dac:
    ai_jmp_01_long $5DAC, $5DC1
ai_pc_5daf:
    ai_jmp_01_short $5DAF, $5DB9
ai_pc_5db1:
    ai_if_var2_gt_14_short $0007, $5DB1, $5DB9
ai_pc_5db4:
    ai_if_tgt_not_within_48_51_short $5DB4, $5DB9
ai_pc_5db6:
    ai_jmp_01_long $5DB6, $5DC1
ai_pc_5db9:
    ai_dec_var1_1f
ai_pc_5dba:
    ai_if_var1_nz_03_short $5DBA, $5DBF
ai_pc_5dbc:
    ai_jmp_01_long $5DBC, $5DC1
ai_pc_5dbf:
    ai_if_tgt_not_within_32_4c_short $5DBF, $5D85
ai_pc_5dc1:
    ai_ret_00
ai_pc_5dc2:
    ai_if_tgt_not_within_48_51_short $5DC2, $5DE4
ai_pc_5dc4:
    ai_call_ff $5913
ai_pc_5dc7:
    ai_if_tgt_not_within_32_4c_short $5DC7, $5DCE
ai_pc_5dc9:
    ai_move_toward_e4 $0003, $0005
ai_pc_5dcc:
    ai_swing_plain_df
ai_pc_5dcd:
    ai_charge_start_f3
ai_pc_5dce:
    ai_if_pos_same_9d_short $5DCE, $5DD6
ai_pc_5dd0:
    ai_pos_save_9f
ai_pc_5dd1:
    ai_move_toward_e4 $000C, $000A
ai_pc_5dd4:
    ai_jmp_01_short $5DD4, $5DDA
ai_pc_5dd6:
    ai_pos_save_9f
ai_pc_5dd7:
    ai_move_toward_alt_fd $000C, $000A
ai_pc_5dda:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5DDA, $5DE2
ai_pc_5ddf:
    ai_jmp_01_long $5DDF, $5DE4
ai_pc_5de2:
    ai_jmp_01_short $5DE2, $5DC2
ai_pc_5de4:
    ai_ret_00
ai_pc_5de5:
    ai_if_tgt_not_within_48_51_short $5DE5, $5E07
ai_pc_5de7:
    ai_call_ff $5913
ai_pc_5dea:
    ai_if_tgt_not_within_32_4c_short $5DEA, $5DF1
ai_pc_5dec:
    ai_move_toward_card_be $0003, $0005
ai_pc_5def:
    ai_swing_plain_df
ai_pc_5df0:
    ai_charge_start_f3
ai_pc_5df1:
    ai_if_pos_same_9d_short $5DF1, $5DF9
ai_pc_5df3:
    ai_pos_save_9f
ai_pc_5df4:
    ai_move_toward_card_be $000C, $000A
ai_pc_5df7:
    ai_jmp_01_short $5DF7, $5DFD
ai_pc_5df9:
    ai_pos_save_9f
ai_pc_5dfa:
    ai_move_toward_alt_fd $000C, $000A
ai_pc_5dfd:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5DFD, $5E05
ai_pc_5e02:
    ai_jmp_01_long $5E02, $5E07
ai_pc_5e05:
    ai_jmp_01_short $5E05, $5DE5
ai_pc_5e07:
    ai_ret_00
ai_pc_5e08:
    ai_call_ff $590F
ai_pc_5e0b:
    ai_call_ff $5913
ai_pc_5e0e:
    ai_if_field_gt_30_short $0080, $002C, $00FE, $5E0E, $5E2F
ai_pc_5e13:
    ai_call_ff $5913
ai_pc_5e16:
    ai_if_field_gt_30_short $0080, $0064, $0000, $5E16, $5E20
ai_pc_5e1b:
    ai_call_ff $5E32
ai_pc_5e1e:
    ai_jmp_01_short $5E1E, $5E2D
ai_pc_5e20:
    ai_if_field_gt_30_short $0080, $0064, $0002, $5E20, $5E2A
ai_pc_5e25:
    ai_call_ff $5E6D
ai_pc_5e28:
    ai_jmp_01_short $5E28, $5E2D
ai_pc_5e2a:
    ai_call_ff $5EA5
ai_pc_5e2d:
    ai_jmp_01_short $5E2D, $5E0E
ai_pc_5e2f:
    ai_jmp_01_short $5E2F, $5E0B
