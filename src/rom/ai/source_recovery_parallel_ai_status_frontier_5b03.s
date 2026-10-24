.setcpu "65816"
.segment "CODE"
.org $AA18
.include "source_recovery_parallel_ai_status_frontier_macros.inc"
ai_pc_5b03:
    ai_if_pos_same_9d_short $5B03, $5B0B
ai_pc_5b05:
    ai_pos_save_9f
ai_pc_5b06:
    ai_move_toward_e4 $000B, $000A
ai_pc_5b09:
    ai_jmp_01_short $5B09, $5B0F
ai_pc_5b0b:
    ai_pos_save_9f
ai_pc_5b0c:
    ai_move_toward_alt_fd $000B, $000A
ai_pc_5b0f:
    ai_if_tgt_not_within_64_56_short $5B0F, $5B03
ai_pc_5b11:
    ai_ret_00
ai_pc_5b12:
    ai_if_pos_same_9d_short $5B12, $5B1A
ai_pc_5b14:
    ai_pos_save_9f
ai_pc_5b15:
    ai_move_toward_card_be $000B, $000A
ai_pc_5b18:
    ai_jmp_01_short $5B18, $5B1E
ai_pc_5b1a:
    ai_pos_save_9f
ai_pc_5b1b:
    ai_move_toward_alt_fd $000B, $000A
ai_pc_5b1e:
    ai_if_tgt_not_within_64_56_short $5B1E, $5B12
ai_pc_5b20:
    ai_ret_00
ai_pc_5b21:
    ai_set_var0_25 $0000
ai_pc_5b23:
    ai_set_var1_26 $0004
ai_pc_5b25:
    ai_call_ff $5913
ai_pc_5b28:
    ai_if_var0_nz_02_short $5B28, $5B30
ai_pc_5b2a:
    ai_call_ff $595E
ai_pc_5b2d:
    ai_inc_var0_1a
ai_pc_5b2e:
    ai_jmp_01_short $5B2E, $5B47
ai_pc_5b30:
    ai_if_var0_ne_0a_short $0001, $5B30, $5B39
ai_pc_5b33:
    ai_call_ff $596B
ai_pc_5b36:
    ai_inc_var0_1a
ai_pc_5b37:
    ai_jmp_01_short $5B37, $5B47
ai_pc_5b39:
    ai_if_var0_ne_0a_short $0002, $5B39, $5B42
ai_pc_5b3c:
    ai_call_ff $596B
ai_pc_5b3f:
    ai_inc_var0_1a
ai_pc_5b40:
    ai_jmp_01_short $5B40, $5B47
ai_pc_5b42:
    ai_call_ff $595E
ai_pc_5b45:
    ai_set_var0_25 $0000
ai_pc_5b47:
    ai_if_var2_gt_14_short $0001, $5B47, $5B51
ai_pc_5b4a:
    ai_if_tgt_not_within_64_56_short $5B4A, $5B4F
ai_pc_5b4c:
    ai_jmp_01_long $5B4C, $5B61
ai_pc_5b4f:
    ai_jmp_01_short $5B4F, $5B59
ai_pc_5b51:
    ai_if_var2_gt_14_short $0005, $5B51, $5B59
ai_pc_5b54:
    ai_if_tgt_not_within_48_51_short $5B54, $5B59
ai_pc_5b56:
    ai_jmp_01_long $5B56, $5B61
ai_pc_5b59:
    ai_dec_var1_1f
ai_pc_5b5a:
    ai_if_var1_nz_03_short $5B5A, $5B5F
ai_pc_5b5c:
    ai_jmp_01_long $5B5C, $5B61
ai_pc_5b5f:
    ai_if_tgt_not_within_32_4c_short $5B5F, $5B25
ai_pc_5b61:
    ai_ret_00
ai_pc_5b62:
    ai_if_tgt_not_within_48_51_short $5B62, $5B84
ai_pc_5b64:
    ai_if_tgt_not_within_32_4c_short $5B64, $5B6E
ai_pc_5b66:
    ai_move_toward_e4 $0003, $0005
ai_pc_5b69:
    ai_swing_plain_df
ai_pc_5b6a:
    ai_move_toward_e4 $0013, $0000
ai_pc_5b6d:
    ai_charge_start_f3
ai_pc_5b6e:
    ai_if_pos_same_9d_short $5B6E, $5B76
ai_pc_5b70:
    ai_pos_save_9f
ai_pc_5b71:
    ai_move_toward_e4 $000C, $000A
ai_pc_5b74:
    ai_jmp_01_short $5B74, $5B7A
ai_pc_5b76:
    ai_pos_save_9f
ai_pc_5b77:
    ai_move_toward_alt_fd $000C, $000A
ai_pc_5b7a:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5B7A, $5B82
ai_pc_5b7f:
    ai_jmp_01_long $5B7F, $5B84
ai_pc_5b82:
    ai_jmp_01_short $5B82, $5B62
ai_pc_5b84:
    ai_ret_00
ai_pc_5b85:
    ai_set_var0_25 $0000
ai_pc_5b87:
    ai_set_var1_26 $0004
ai_pc_5b89:
    ai_call_ff $5913
ai_pc_5b8c:
    ai_if_var0_nz_02_short $5B8C, $5B94
ai_pc_5b8e:
    ai_call_ff $595E
ai_pc_5b91:
    ai_inc_var0_1a
ai_pc_5b92:
    ai_jmp_01_short $5B92, $5BAB
ai_pc_5b94:
    ai_if_var0_ne_0a_short $0001, $5B94, $5B9D
ai_pc_5b97:
    ai_call_ff $596B
ai_pc_5b9a:
    ai_inc_var0_1a
ai_pc_5b9b:
    ai_jmp_01_short $5B9B, $5BAB
ai_pc_5b9d:
    ai_if_var0_ne_0a_short $0002, $5B9D, $5BA6
ai_pc_5ba0:
    ai_call_ff $596B
ai_pc_5ba3:
    ai_inc_var0_1a
ai_pc_5ba4:
    ai_jmp_01_short $5BA4, $5BAB
ai_pc_5ba6:
    ai_call_ff $595E
ai_pc_5ba9:
    ai_set_var0_25 $0000
ai_pc_5bab:
    ai_if_var2_gt_14_short $0002, $5BAB, $5BB5
ai_pc_5bae:
    ai_if_tgt_not_within_64_56_short $5BAE, $5BB3
ai_pc_5bb0:
    ai_jmp_01_long $5BB0, $5BC5
ai_pc_5bb3:
    ai_jmp_01_short $5BB3, $5BBD
ai_pc_5bb5:
    ai_if_var2_gt_14_short $0007, $5BB5, $5BBD
ai_pc_5bb8:
    ai_if_tgt_not_within_48_51_short $5BB8, $5BBD
ai_pc_5bba:
    ai_jmp_01_long $5BBA, $5BC5
ai_pc_5bbd:
    ai_dec_var1_1f
ai_pc_5bbe:
    ai_if_var1_nz_03_short $5BBE, $5BC3
ai_pc_5bc0:
    ai_jmp_01_long $5BC0, $5BC5
ai_pc_5bc3:
    ai_if_tgt_not_within_32_4c_short $5BC3, $5B89
ai_pc_5bc5:
    ai_ret_00
ai_pc_5bc6:
    ai_if_tgt_not_within_48_51_short $5BC6, $5BE5
ai_pc_5bc8:
    ai_if_tgt_not_within_32_4c_short $5BC8, $5BCF
ai_pc_5bca:
    ai_move_toward_e4 $0003, $0005
ai_pc_5bcd:
    ai_swing_plain_df
ai_pc_5bce:
    ai_charge_start_f3
ai_pc_5bcf:
    ai_if_pos_same_9d_short $5BCF, $5BD7
ai_pc_5bd1:
    ai_pos_save_9f
ai_pc_5bd2:
    ai_move_toward_e4 $000C, $000A
ai_pc_5bd5:
    ai_jmp_01_short $5BD5, $5BDB
ai_pc_5bd7:
    ai_pos_save_9f
ai_pc_5bd8:
    ai_move_toward_alt_fd $000C, $000A
ai_pc_5bdb:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5BDB, $5BE3
ai_pc_5be0:
    ai_jmp_01_long $5BE0, $5BE5
ai_pc_5be3:
    ai_jmp_01_short $5BE3, $5BC6
ai_pc_5be5:
    ai_ret_00
ai_pc_5be6:
    ai_if_tgt_not_within_48_51_short $5BE6, $5C05
ai_pc_5be8:
    ai_if_tgt_not_within_32_4c_short $5BE8, $5BEF
ai_pc_5bea:
    ai_move_toward_card_be $0003, $0005
ai_pc_5bed:
    ai_swing_plain_df
ai_pc_5bee:
    ai_charge_start_f3
ai_pc_5bef:
    ai_if_pos_same_9d_short $5BEF, $5BF7
ai_pc_5bf1:
    ai_pos_save_9f
ai_pc_5bf2:
    ai_move_toward_card_be $000C, $000A
ai_pc_5bf5:
    ai_jmp_01_short $5BF5, $5BFB
ai_pc_5bf7:
    ai_pos_save_9f
ai_pc_5bf8:
    ai_move_toward_alt_fd $000C, $000A
ai_pc_5bfb:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5BFB, $5C03
ai_pc_5c00:
    ai_jmp_01_long $5C00, $5C05
ai_pc_5c03:
    ai_jmp_01_short $5C03, $5BE6
ai_pc_5c05:
    ai_ret_00
