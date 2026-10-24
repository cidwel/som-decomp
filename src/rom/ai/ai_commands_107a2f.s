.setcpu "65816"
.segment "CODE"
.org $7A2F
.include "ai_command_macros.inc"
ai_pc_2b1a:
    ai_pose_e2 $0000
ai_pc_2b1c:
    ai_set_var2_27 $0002
ai_pc_2b1e:
    ai_rnd_var3_2c $0003
ai_pc_2b20:
    ai_if_var3_nz_05_short $2B20, $2B28
ai_pc_2b22:
    ai_hop_e0 $0002, $0000, $0005
ai_pc_2b26:
    ai_jmp_01_short $2B26, $2B3E
ai_pc_2b28:
    ai_if_var3_ne_0d_short $0001, $2B28, $2B31
ai_pc_2b2b:
    ai_hop_e0 $0001, $0000, $0005
ai_pc_2b2f:
    ai_jmp_01_short $2B2F, $2B3E
ai_pc_2b31:
    ai_if_var3_ne_0d_short $0002, $2B31, $2B3A
ai_pc_2b34:
    ai_hop_e0 $0008, $0000, $0005
ai_pc_2b38:
    ai_jmp_01_short $2B38, $2B3E
ai_pc_2b3a:
    ai_hop_e0 $0004, $0000, $0005
ai_pc_2b3e:
    ai_pose_e2 $0003
ai_pc_2b40:
    ai_dec_var2_20
ai_pc_2b41:
    ai_if_var2_nz_04_short $2B41, $2B1E
ai_pc_2b43:
    ai_ret_00
ai_pc_2b44:
    ai_move_toward_card_be $0000, $0000
ai_pc_2b47:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2B47, $2B63
ai_pc_2b4c:
    ai_rnd_var3_2c $0001
ai_pc_2b4e:
    ai_if_var3_nz_05_short $2B4E, $2B58
ai_pc_2b50:
    ai_move_toward_card_be $0000, $0000
ai_pc_2b53:
    ai_call_ff $6B19
ai_pc_2b56:
    ai_jmp_01_short $2B56, $2B63
ai_pc_2b58:
    ai_flash_fc
ai_pc_2b59:
    ai_move_toward_card_be $0000, $0005
ai_pc_2b5c:
    ai_call_ff $6B19
ai_pc_2b5f:
    ai_flash_fc
ai_pc_2b60:
    ai_move_toward_e4 $0000, $0005
ai_pc_2b63:
    ai_move_toward_card_be $000E, $0000
ai_pc_2b66:
    ai_call_ff $2C09
ai_pc_2b69:
    ai_ret_00
ai_pc_2b6a:
    ai_move_toward_card_be $0000, $0005
ai_pc_2b6d:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2B6D, $2B86
ai_pc_2b72:
    ai_rnd_var3_2c $0001
ai_pc_2b74:
    ai_if_var3_nz_05_short $2B74, $2B7B
ai_pc_2b76:
    ai_call_ff $2BF7
ai_pc_2b79:
    ai_jmp_01_short $2B79, $2B84
ai_pc_2b7b:
    ai_move_toward_card_be $0000, $0005
ai_pc_2b7e:
    ai_call_ff $6B19
ai_pc_2b81:
    ai_call_ff $2C09
ai_pc_2b84:
    ai_jmp_01_short $2B84, $2B89
ai_pc_2b86:
    ai_move_toward_card_be $0000, $0000
ai_pc_2b89:
    ai_ret_00
ai_pc_2b8a:
    ai_move_toward_card_be $0000, $0000
ai_pc_2b8d:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2B8D, $2BA9
ai_pc_2b92:
    ai_if_tgt_not_lane_v64_66_short $2B92, $2B9C
ai_pc_2b94:
    ai_move_toward_card_be $000E, $0000
ai_pc_2b97:
    ai_call_ff $6B19
ai_pc_2b9a:
    ai_jmp_01_short $2B9A, $2BA9
ai_pc_2b9c:
    ai_if_tgt_not_lane_h64_6f_short $2B9C, $2BA6
ai_pc_2b9e:
    ai_move_toward_card_be $000E, $0000
ai_pc_2ba1:
    ai_call_ff $6B19
ai_pc_2ba4:
    ai_jmp_01_short $2BA4, $2BA9
ai_pc_2ba6:
    ai_move_toward_card_be $0000, $000F
ai_pc_2ba9:
    ai_if_field_gt_30_short $0080, $0038, $0000, $2BA9, $2BB6
ai_pc_2bae:
    ai_tgt2_self_c4
ai_pc_2baf:
    ai_cast_e9 $0005, $0022
ai_pc_2bb2:
    ai_tgt2_none_c0
ai_pc_2bb3:
    ai_move_toward_e4 $0000, $00B4
ai_pc_2bb6:
    ai_ret_00
ai_pc_2bb7:
    ai_call_ff $6AE1
ai_pc_2bba:
    ai_rnd_var3_2c $0003
ai_pc_2bbc:
    ai_if_var3_nz_05_short $2BBC, $2BC3
ai_pc_2bbe:
    ai_call_ff $2BE0
ai_pc_2bc1:
    ai_jmp_01_short $2BC1, $2BC6
ai_pc_2bc3:
    ai_call_ff $2BC9
ai_pc_2bc6:
    ai_if_tgt_not_within_64_56_short $2BC6, $2BB7
ai_pc_2bc8:
    ai_ret_00
ai_pc_2bc9:
    ai_set_var2_27 $0002
ai_pc_2bcb:
    ai_if_pos_same_9d_short $2BCB, $2BD3
ai_pc_2bcd:
    ai_pos_save_9f
ai_pc_2bce:
    ai_move_toward_card_be $0004, $000F
ai_pc_2bd1:
    ai_jmp_01_short $2BD1, $2BD7
ai_pc_2bd3:
    ai_pos_save_9f
ai_pc_2bd4:
    ai_move_toward_alt_fd $0004, $000F
ai_pc_2bd7:
    ai_dec_var2_20
ai_pc_2bd8:
    ai_if_var2_nz_04_short $2BD8, $2BDD
ai_pc_2bda:
    ai_jmp_01_long $2BDA, $2BDF
ai_pc_2bdd:
    ai_if_tgt_not_within_64_56_short $2BDD, $2BCB
ai_pc_2bdf:
    ai_ret_00
ai_pc_2be0:
    ai_set_var2_27 $0002
ai_pc_2be2:
    ai_if_pos_same_9d_short $2BE2, $2BEA
ai_pc_2be4:
    ai_pos_save_9f
ai_pc_2be5:
    ai_move_toward_card_be $0001, $000A
ai_pc_2be8:
    ai_jmp_01_short $2BE8, $2BEE
ai_pc_2bea:
    ai_pos_save_9f
ai_pc_2beb:
    ai_move_toward_alt_fd $0001, $000A
ai_pc_2bee:
    ai_dec_var2_20
ai_pc_2bef:
    ai_if_var2_nz_04_short $2BEF, $2BF4
ai_pc_2bf1:
    ai_jmp_01_long $2BF1, $2BF6
ai_pc_2bf4:
    ai_if_tgt_not_within_64_56_short $2BF4, $2BE2
ai_pc_2bf6:
    ai_ret_00
ai_pc_2bf7:
    ai_call_ff $6AE1
ai_pc_2bfa:
    ai_if_pos_same_9d_short $2BFA, $2C02
ai_pc_2bfc:
    ai_pos_save_9f
ai_pc_2bfd:
    ai_move_toward_card_be $0004, $000F
ai_pc_2c00:
    ai_jmp_01_short $2C00, $2C06
ai_pc_2c02:
    ai_pos_save_9f
ai_pc_2c03:
    ai_move_toward_alt_fd $0004, $000F
ai_pc_2c06:
    ai_if_tgt_not_within_32_4c_short $2C06, $2BF7
ai_pc_2c08:
    ai_ret_00
ai_pc_2c09:
    ai_if_tgt_not_within_32_4c_short $2C09, $2C2E
ai_pc_2c0b:
    ai_call_ff $6AE1
ai_pc_2c0e:
    ai_if_pos_same_9d_short $2C0E, $2C16
ai_pc_2c10:
    ai_pos_save_9f
ai_pc_2c11:
    ai_move_toward_card_be $0005, $000F
ai_pc_2c14:
    ai_jmp_01_short $2C14, $2C1A
ai_pc_2c16:
    ai_pos_save_9f
ai_pc_2c17:
    ai_move_toward_alt_fd $0005, $000F
ai_pc_2c1a:
    ai_if_tgt_not_within_32_4c_short $2C1A, $2C2C
ai_pc_2c1c:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2C1C, $2C2C
ai_pc_2c21:
    ai_flash_fc
ai_pc_2c22:
    ai_move_toward_card_be $0000, $0005
ai_pc_2c25:
    ai_call_ff $6B19
ai_pc_2c28:
    ai_flash_fc
ai_pc_2c29:
    ai_move_toward_e4 $0000, $0005
ai_pc_2c2c:
    ai_jmp_01_short $2C2C, $2C09
ai_pc_2c2e:
    ai_ret_00
ai_pc_2c2f:
    ai_call_ff $2C5C
ai_pc_2c32:
    ai_call_ff $6AE1
ai_pc_2c35:
    ai_if_tgt_not_within_16_34_short $2C35, $2C3C
ai_pc_2c37:
    ai_call_ff $2C7D
ai_pc_2c3a:
    ai_jmp_01_short $2C3A, $2C54
ai_pc_2c3c:
    ai_if_tgt_not_within_32_4c_short $2C3C, $2C43
ai_pc_2c3e:
    ai_call_ff $2C8E
ai_pc_2c41:
    ai_jmp_01_short $2C41, $2C54
ai_pc_2c43:
    ai_if_tgt_not_within_48_51_short $2C43, $2C4A
ai_pc_2c45:
    ai_call_ff $2CA3
ai_pc_2c48:
    ai_jmp_01_short $2C48, $2C54
ai_pc_2c4a:
    ai_if_tgt_not_within_64_56_short $2C4A, $2C51
ai_pc_2c4c:
    ai_call_ff $2CB8
ai_pc_2c4f:
    ai_jmp_01_short $2C4F, $2C54
ai_pc_2c51:
    ai_turn_facing_e3 $0000, $0005
ai_pc_2c54:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $2C54, $2C32
ai_pc_2c59:
    ai_jmp_01_short $2C59, $2C32
