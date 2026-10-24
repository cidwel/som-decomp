.setcpu "65816"
.segment "CODE"
.org $AD47
.include "ai_command_macros.inc"
ai_pc_5e32:
    ai_if_field_gt_30_short $0080, $002C, $00FE, $5E32, $5E6C
ai_pc_5e37:
    ai_call_ff $5913
ai_pc_5e3a:
    ai_if_tgt_not_within_64_56_short $5E3A, $5E5D
ai_pc_5e3c:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5E3C, $5E58
ai_pc_5e41:
    ai_if_charge_set_f2_short $0000, $5E41, $5E53
ai_pc_5e44:
    ai_rnd_var2_2b $000F
ai_pc_5e46:
    ai_call_ff $5F31
ai_pc_5e49:
    ai_move_toward_e4 $0003, $0005
ai_pc_5e4c:
    ai_swing_plain_df
ai_pc_5e4d:
    ai_move_toward_e4 $0013, $0000
ai_pc_5e50:
    ai_charge_start_f3
ai_pc_5e51:
    ai_jmp_01_short $5E51, $5E56
ai_pc_5e53:
    ai_call_ff $5F72
ai_pc_5e56:
    ai_jmp_01_short $5E56, $5E5B
ai_pc_5e58:
    ai_call_ff $5F72
ai_pc_5e5b:
    ai_jmp_01_short $5E5B, $5E6A
ai_pc_5e5d:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5E5D, $5E67
ai_pc_5e62:
    ai_call_ff $5EF8
ai_pc_5e65:
    ai_jmp_01_short $5E65, $5E6A
ai_pc_5e67:
    ai_move_toward_e4 $0000, $0005
ai_pc_5e6a:
    ai_jmp_01_short $5E6A, $5E32
ai_pc_5e6c:
    ai_ret_00
ai_pc_5e6d:
    ai_if_field_gt_30_short $0080, $002C, $00FE, $5E6D, $5EA4
ai_pc_5e72:
    ai_call_ff $5913
ai_pc_5e75:
    ai_if_tgt_not_within_64_56_short $5E75, $5E95
ai_pc_5e77:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5E77, $5E90
ai_pc_5e7c:
    ai_if_charge_set_f2_short $0000, $5E7C, $5E8B
ai_pc_5e7f:
    ai_rnd_var2_2b $000F
ai_pc_5e81:
    ai_call_ff $5FAD
ai_pc_5e84:
    ai_move_toward_e4 $0003, $0005
ai_pc_5e87:
    ai_swing_plain_df
ai_pc_5e88:
    ai_charge_start_f3
ai_pc_5e89:
    ai_jmp_01_short $5E89, $5E8E
ai_pc_5e8b:
    ai_call_ff $5FEE
ai_pc_5e8e:
    ai_jmp_01_short $5E8E, $5E93
ai_pc_5e90:
    ai_call_ff $5FEE
ai_pc_5e93:
    ai_jmp_01_short $5E93, $5EA2
ai_pc_5e95:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5E95, $5E9F
ai_pc_5e9a:
    ai_call_ff $5EF8
ai_pc_5e9d:
    ai_jmp_01_short $5E9D, $5EA2
ai_pc_5e9f:
    ai_move_toward_e4 $0000, $0005
ai_pc_5ea2:
    ai_jmp_01_short $5EA2, $5E6D
ai_pc_5ea4:
    ai_ret_00
ai_pc_5ea5:
    ai_if_field_gt_30_long $0080, $002C, $00FE, $5EA5, $5EF7
ai_pc_5eab:
    ai_call_ff $5913
ai_pc_5eae:
    ai_if_tgt_not_within_64_56_short $5EAE, $5EE7
ai_pc_5eb0:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5EB0, $5EDB
ai_pc_5eb5:
    ai_if_charge_set_f2_short $0000, $5EB5, $5ECF
ai_pc_5eb8:
    ai_if_tgt_not_lane_v64_66_short $5EB8, $5EC1
ai_pc_5eba:
    ai_move_toward_card_be $0003, $0005
ai_pc_5ebd:
    ai_swing_plain_df
ai_pc_5ebe:
    ai_charge_start_f3
ai_pc_5ebf:
    ai_jmp_01_short $5EBF, $5ECD
ai_pc_5ec1:
    ai_if_tgt_not_lane_h64_6f_short $5EC1, $5ECA
ai_pc_5ec3:
    ai_move_toward_card_be $0003, $0005
ai_pc_5ec6:
    ai_swing_plain_df
ai_pc_5ec7:
    ai_charge_start_f3
ai_pc_5ec8:
    ai_jmp_01_short $5EC8, $5ECD
ai_pc_5eca:
    ai_call_ff $593D
ai_pc_5ecd:
    ai_jmp_01_short $5ECD, $5ED9
ai_pc_5ecf:
    ai_if_tgt_not_band_64_46_short $5ECF, $5ED6
ai_pc_5ed1:
    ai_move_toward_card_be $0003, $0005
ai_pc_5ed4:
    ai_jmp_01_short $5ED4, $5ED9
ai_pc_5ed6:
    ai_call_ff $6026
ai_pc_5ed9:
    ai_jmp_01_short $5ED9, $5EE5
ai_pc_5edb:
    ai_if_tgt_not_band_64_46_short $5EDB, $5EE2
ai_pc_5edd:
    ai_move_toward_card_be $0003, $0005
ai_pc_5ee0:
    ai_jmp_01_short $5EE0, $5EE5
ai_pc_5ee2:
    ai_call_ff $6026
ai_pc_5ee5:
    ai_jmp_01_short $5EE5, $5EF4
ai_pc_5ee7:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5EE7, $5EF1
ai_pc_5eec:
    ai_call_ff $5F1F
ai_pc_5eef:
    ai_jmp_01_short $5EEF, $5EF4
ai_pc_5ef1:
    ai_move_toward_card_be $0000, $0005
ai_pc_5ef4:
    ai_jmp_01_long $5EF4, $5EA5
ai_pc_5ef7:
    ai_ret_00
ai_pc_5ef8:
    ai_set_var0_25 $0000
ai_pc_5efa:
    ai_call_ff $5913
ai_pc_5efd:
    ai_if_var0_nz_02_short $5EFD, $5F05
ai_pc_5eff:
    ai_call_ff $595E
ai_pc_5f02:
    ai_inc_var0_1a
ai_pc_5f03:
    ai_jmp_01_short $5F03, $5F1C
ai_pc_5f05:
    ai_if_var0_ne_0a_short $0001, $5F05, $5F0E
ai_pc_5f08:
    ai_call_ff $596B
ai_pc_5f0b:
    ai_inc_var0_1a
ai_pc_5f0c:
    ai_jmp_01_short $5F0C, $5F1C
ai_pc_5f0e:
    ai_if_var0_ne_0a_short $0002, $5F0E, $5F17
ai_pc_5f11:
    ai_call_ff $596B
ai_pc_5f14:
    ai_inc_var0_1a
ai_pc_5f15:
    ai_jmp_01_short $5F15, $5F1C
ai_pc_5f17:
    ai_call_ff $595E
ai_pc_5f1a:
    ai_set_var0_25 $0000
ai_pc_5f1c:
    ai_if_tgt_not_within_64_56_short $5F1C, $5EFA
ai_pc_5f1e:
    ai_ret_00
ai_pc_5f1f:
    ai_call_ff $5913
ai_pc_5f22:
    ai_if_pos_same_9d_short $5F22, $5F2A
ai_pc_5f24:
    ai_pos_save_9f
ai_pc_5f25:
    ai_move_toward_card_be $000B, $000A
ai_pc_5f28:
    ai_jmp_01_short $5F28, $5F2E
ai_pc_5f2a:
    ai_pos_save_9f
ai_pc_5f2b:
    ai_move_toward_alt_fd $000B, $000A
ai_pc_5f2e:
    ai_if_tgt_not_within_64_56_short $5F2E, $5F1F
ai_pc_5f30:
    ai_ret_00
ai_pc_5f31:
    ai_set_var0_25 $0000
ai_pc_5f33:
    ai_set_var1_26 $0004
ai_pc_5f35:
    ai_call_ff $5913
ai_pc_5f38:
    ai_if_var0_nz_02_short $5F38, $5F40
ai_pc_5f3a:
    ai_call_ff $595E
ai_pc_5f3d:
    ai_inc_var0_1a
ai_pc_5f3e:
    ai_jmp_01_short $5F3E, $5F57
ai_pc_5f40:
    ai_if_var0_ne_0a_short $0001, $5F40, $5F49
ai_pc_5f43:
    ai_call_ff $596B
ai_pc_5f46:
    ai_inc_var0_1a
ai_pc_5f47:
    ai_jmp_01_short $5F47, $5F57
ai_pc_5f49:
    ai_if_var0_ne_0a_short $0002, $5F49, $5F52
ai_pc_5f4c:
    ai_call_ff $596B
ai_pc_5f4f:
    ai_inc_var0_1a
ai_pc_5f50:
    ai_jmp_01_short $5F50, $5F57
ai_pc_5f52:
    ai_call_ff $595E
ai_pc_5f55:
    ai_set_var0_25 $0000
ai_pc_5f57:
    ai_if_var2_gt_14_short $0001, $5F57, $5F61
ai_pc_5f5a:
    ai_if_tgt_not_within_64_56_short $5F5A, $5F5F
ai_pc_5f5c:
    ai_jmp_01_long $5F5C, $5F71
ai_pc_5f5f:
    ai_jmp_01_short $5F5F, $5F69
ai_pc_5f61:
    ai_if_var2_gt_14_short $0005, $5F61, $5F69
ai_pc_5f64:
    ai_if_tgt_not_within_48_51_short $5F64, $5F69
ai_pc_5f66:
    ai_jmp_01_long $5F66, $5F71
ai_pc_5f69:
    ai_dec_var1_1f
ai_pc_5f6a:
    ai_if_var1_nz_03_short $5F6A, $5F6F
ai_pc_5f6c:
    ai_jmp_01_long $5F6C, $5F71
ai_pc_5f6f:
    ai_if_tgt_not_within_32_4c_short $5F6F, $5F35
ai_pc_5f71:
    ai_ret_00
ai_pc_5f72:
    ai_set_var0_25 $0000
ai_pc_5f74:
    ai_if_tgt_not_within_48_51_short $5F74, $5FAC
ai_pc_5f76:
    ai_call_ff $5913
ai_pc_5f79:
    ai_if_tgt_not_within_32_4c_short $5F79, $5F83
ai_pc_5f7b:
    ai_move_toward_e4 $0003, $0005
ai_pc_5f7e:
    ai_swing_plain_df
ai_pc_5f7f:
    ai_move_toward_e4 $0013, $0000
ai_pc_5f82:
    ai_charge_start_f3
ai_pc_5f83:
    ai_if_var0_nz_02_short $5F83, $5F8B
ai_pc_5f85:
    ai_call_ff $5978
ai_pc_5f88:
    ai_inc_var0_1a
ai_pc_5f89:
    ai_jmp_01_short $5F89, $5FA2
ai_pc_5f8b:
    ai_if_var0_ne_0a_short $0001, $5F8B, $5F94
ai_pc_5f8e:
    ai_call_ff $5985
ai_pc_5f91:
    ai_inc_var0_1a
ai_pc_5f92:
    ai_jmp_01_short $5F92, $5FA2
ai_pc_5f94:
    ai_if_var0_ne_0a_short $0002, $5F94, $5F9D
ai_pc_5f97:
    ai_call_ff $5985
ai_pc_5f9a:
    ai_inc_var0_1a
ai_pc_5f9b:
    ai_jmp_01_short $5F9B, $5FA2
ai_pc_5f9d:
    ai_call_ff $5978
ai_pc_5fa0:
    ai_set_var0_25 $0000
ai_pc_5fa2:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5FA2, $5FAA
ai_pc_5fa7:
    ai_jmp_01_long $5FA7, $5FAC
ai_pc_5faa:
    ai_jmp_01_short $5FAA, $5F74
ai_pc_5fac:
    ai_ret_00
ai_pc_5fad:
    ai_set_var0_25 $0000
ai_pc_5faf:
    ai_set_var1_26 $0004
ai_pc_5fb1:
    ai_call_ff $5913
ai_pc_5fb4:
    ai_if_var0_nz_02_short $5FB4, $5FBC
ai_pc_5fb6:
    ai_call_ff $595E
ai_pc_5fb9:
    ai_inc_var0_1a
ai_pc_5fba:
    ai_jmp_01_short $5FBA, $5FD3
ai_pc_5fbc:
    ai_if_var0_ne_0a_short $0001, $5FBC, $5FC5
ai_pc_5fbf:
    ai_call_ff $596B
ai_pc_5fc2:
    ai_inc_var0_1a
ai_pc_5fc3:
    ai_jmp_01_short $5FC3, $5FD3
ai_pc_5fc5:
    ai_if_var0_ne_0a_short $0002, $5FC5, $5FCE
ai_pc_5fc8:
    ai_call_ff $596B
ai_pc_5fcb:
    ai_inc_var0_1a
ai_pc_5fcc:
    ai_jmp_01_short $5FCC, $5FD3
ai_pc_5fce:
    ai_call_ff $595E
ai_pc_5fd1:
    ai_set_var0_25 $0000
ai_pc_5fd3:
    ai_if_var2_gt_14_short $0002, $5FD3, $5FDD
ai_pc_5fd6:
    ai_if_tgt_not_within_64_56_short $5FD6, $5FDB
ai_pc_5fd8:
    ai_jmp_01_long $5FD8, $5FED
ai_pc_5fdb:
    ai_jmp_01_short $5FDB, $5FE5
ai_pc_5fdd:
    ai_if_var2_gt_14_short $0007, $5FDD, $5FE5
ai_pc_5fe0:
    ai_if_tgt_not_within_48_51_short $5FE0, $5FE5
ai_pc_5fe2:
    ai_jmp_01_long $5FE2, $5FED
ai_pc_5fe5:
    ai_dec_var1_1f
ai_pc_5fe6:
    ai_if_var1_nz_03_short $5FE6, $5FEB
ai_pc_5fe8:
    ai_jmp_01_long $5FE8, $5FED
ai_pc_5feb:
    ai_if_tgt_not_within_32_4c_short $5FEB, $5FB1
ai_pc_5fed:
    ai_ret_00
ai_pc_5fee:
    ai_set_var0_25 $0000
ai_pc_5ff0:
    ai_if_tgt_not_within_48_51_short $5FF0, $6025
ai_pc_5ff2:
    ai_call_ff $5913
ai_pc_5ff5:
    ai_if_tgt_not_within_32_4c_short $5FF5, $5FFC
ai_pc_5ff7:
    ai_move_toward_e4 $0003, $0005
ai_pc_5ffa:
    ai_swing_plain_df
ai_pc_5ffb:
    ai_charge_start_f3
ai_pc_5ffc:
    ai_if_var0_nz_02_short $5FFC, $6004
ai_pc_5ffe:
    ai_call_ff $5978
ai_pc_6001:
    ai_inc_var0_1a
ai_pc_6002:
    ai_jmp_01_short $6002, $601B
ai_pc_6004:
    ai_if_var0_ne_0a_short $0001, $6004, $600D
ai_pc_6007:
    ai_call_ff $5985
ai_pc_600a:
    ai_inc_var0_1a
ai_pc_600b:
    ai_jmp_01_short $600B, $601B
ai_pc_600d:
    ai_if_var0_ne_0a_short $0002, $600D, $6016
ai_pc_6010:
    ai_call_ff $5985
ai_pc_6013:
    ai_inc_var0_1a
ai_pc_6014:
    ai_jmp_01_short $6014, $601B
ai_pc_6016:
    ai_call_ff $5978
ai_pc_6019:
    ai_set_var0_25 $0000
ai_pc_601b:
    ai_if_field_gt_30_short $0080, $006D, $0000, $601B, $6023
ai_pc_6020:
    ai_jmp_01_long $6020, $6025
ai_pc_6023:
    ai_jmp_01_short $6023, $5FF0
ai_pc_6025:
    ai_ret_00
ai_pc_6026:
    ai_set_var0_25 $0000
ai_pc_6028:
    ai_if_tgt_not_within_48_51_short $6028, $605D
ai_pc_602a:
    ai_call_ff $5913
ai_pc_602d:
    ai_if_tgt_not_within_32_4c_short $602D, $6034
ai_pc_602f:
    ai_move_toward_card_be $0003, $0005
ai_pc_6032:
    ai_swing_plain_df
ai_pc_6033:
    ai_charge_start_f3
ai_pc_6034:
    ai_if_var0_nz_02_short $6034, $603C
ai_pc_6036:
    ai_call_ff $59AC
ai_pc_6039:
    ai_inc_var0_1a
ai_pc_603a:
    ai_jmp_01_short $603A, $6053
ai_pc_603c:
    ai_if_var0_ne_0a_short $0001, $603C, $6045
ai_pc_603f:
    ai_call_ff $59B9
ai_pc_6042:
    ai_inc_var0_1a
ai_pc_6043:
    ai_jmp_01_short $6043, $6053
ai_pc_6045:
    ai_if_var0_ne_0a_short $0002, $6045, $604E
ai_pc_6048:
    ai_call_ff $59B9
ai_pc_604b:
    ai_inc_var0_1a
ai_pc_604c:
    ai_jmp_01_short $604C, $6053
ai_pc_604e:
    ai_call_ff $59AC
ai_pc_6051:
    ai_set_var0_25 $0000
ai_pc_6053:
    ai_if_field_gt_30_short $0080, $006D, $0000, $6053, $605B
ai_pc_6058:
    ai_jmp_01_long $6058, $605D
ai_pc_605b:
    ai_jmp_01_short $605B, $6028
ai_pc_605d:
    ai_ret_00
ai_pc_605e:
    ai_call_ff $590F
ai_pc_6061:
    ai_call_ff $5913
ai_pc_6064:
    ai_if_field_gt_30_short $0080, $002C, $00FE, $6064, $6085
ai_pc_6069:
    ai_call_ff $5913
ai_pc_606c:
    ai_if_field_gt_30_short $0080, $0064, $0000, $606C, $6076
ai_pc_6071:
    ai_call_ff $6088
ai_pc_6074:
    ai_jmp_01_short $6074, $6083
ai_pc_6076:
    ai_if_field_gt_30_short $0080, $0064, $0002, $6076, $6080
ai_pc_607b:
    ai_call_ff $60BD
ai_pc_607e:
    ai_jmp_01_short $607E, $6083
ai_pc_6080:
    ai_call_ff $60EF
ai_pc_6083:
    ai_jmp_01_short $6083, $6064
ai_pc_6085:
    ai_jmp_01_short $6085, $6061
