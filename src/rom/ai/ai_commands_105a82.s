.setcpu "65816"
.segment "CODE"
.org $5A82
.include "ai_command_macros.inc"
ai_pc_0b6d:
    ai_turn_facing_e3 $0000, $0000
ai_pc_0b70:
    ai_call_ff $6AE1
ai_pc_0b73:
    ai_turn_facing_e3 $0000, $0000
ai_pc_0b76:
    ai_if_word_gt_bd_short $0080, $0002, $007F, $0000, $0B76, $0B7F
ai_pc_0b7c:
    ai_jmp_01_long $0B7C, $0B81
ai_pc_0b7f:
    ai_if_tgt_not_within_16_34_short $0B7F, $0B70
ai_pc_0b81:
    ai_pose_e2 $0000
ai_pc_0b83:
    ai_ret_00
ai_pc_0b84:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0B84, $0B94
ai_pc_0b89:
    ai_move_toward_card_be $0000, $0000
ai_pc_0b8c:
    ai_turn_facing_e3 $0005, $0000
ai_pc_0b8f:
    ai_call_ff $6B0F
ai_pc_0b92:
    ai_jmp_01_short $0B92, $0BA0
ai_pc_0b94:
    ai_if_pos_same_9d_short $0B94, $0B9C
ai_pc_0b96:
    ai_pos_save_9f
ai_pc_0b97:
    ai_move_toward_card_be $0005, $0000
ai_pc_0b9a:
    ai_jmp_01_short $0B9A, $0BA0
ai_pc_0b9c:
    ai_pos_save_9f
ai_pc_0b9d:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_0ba0:
    ai_ret_00
ai_pc_0ba1:
    ai_move_toward_e4 $0000, $0000
ai_pc_0ba4:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0BA4, $0BB4
ai_pc_0ba9:
    ai_move_toward_card_be $0000, $0000
ai_pc_0bac:
    ai_turn_facing_e3 $0005, $0000
ai_pc_0baf:
    ai_call_ff $6B19
ai_pc_0bb2:
    ai_jmp_01_short $0BB2, $0BD2
ai_pc_0bb4:
    ai_rnd_var3_2c $0001
ai_pc_0bb6:
    ai_if_var3_nz_05_short $0BB6, $0BC6
ai_pc_0bb8:
    ai_if_pos_same_9d_short $0BB8, $0BC0
ai_pc_0bba:
    ai_pos_save_9f
ai_pc_0bbb:
    ai_move_away_card_bf $0001, $0000
ai_pc_0bbe:
    ai_jmp_01_short $0BBE, $0BC4
ai_pc_0bc0:
    ai_pos_save_9f
ai_pc_0bc1:
    ai_move_away_alt_fe $0001, $0000
ai_pc_0bc4:
    ai_jmp_01_short $0BC4, $0BD2
ai_pc_0bc6:
    ai_if_pos_same_9d_short $0BC6, $0BCE
ai_pc_0bc8:
    ai_pos_save_9f
ai_pc_0bc9:
    ai_move_away_card_bf $0002, $0000
ai_pc_0bcc:
    ai_jmp_01_short $0BCC, $0BD2
ai_pc_0bce:
    ai_pos_save_9f
ai_pc_0bcf:
    ai_move_away_alt_fe $0002, $0000
ai_pc_0bd2:
    ai_ret_00
ai_pc_0bd3:
    ai_move_toward_card_be $0000, $0000
ai_pc_0bd6:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0BD6, $0BE3
ai_pc_0bdb:
    ai_move_toward_card_be $0000, $0000
ai_pc_0bde:
    ai_call_ff $6B0F
ai_pc_0be1:
    ai_jmp_01_short $0BE1, $0BE6
ai_pc_0be3:
    ai_move_toward_card_be $0000, $0000
ai_pc_0be6:
    ai_ret_00
ai_pc_0be7:
    ai_call_ff $6AE1
ai_pc_0bea:
    ai_rnd_var3_2c $0002
ai_pc_0bec:
    ai_if_var3_nz_05_short $0BEC, $0BFC
ai_pc_0bee:
    ai_if_pos_same_9d_short $0BEE, $0BF6
ai_pc_0bf0:
    ai_pos_save_9f
ai_pc_0bf1:
    ai_move_toward_card_be $0002, $0000
ai_pc_0bf4:
    ai_jmp_01_short $0BF4, $0BFA
ai_pc_0bf6:
    ai_pos_save_9f
ai_pc_0bf7:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_0bfa:
    ai_jmp_01_short $0BFA, $0C19
ai_pc_0bfc:
    ai_if_var3_ne_0d_short $0001, $0BFC, $0C0D
ai_pc_0bff:
    ai_if_pos_same_9d_short $0BFF, $0C07
ai_pc_0c01:
    ai_pos_save_9f
ai_pc_0c02:
    ai_move_toward_card_be $0004, $0000
ai_pc_0c05:
    ai_jmp_01_short $0C05, $0C0B
ai_pc_0c07:
    ai_pos_save_9f
ai_pc_0c08:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_0c0b:
    ai_jmp_01_short $0C0B, $0C19
ai_pc_0c0d:
    ai_if_pos_same_9d_short $0C0D, $0C15
ai_pc_0c0f:
    ai_pos_save_9f
ai_pc_0c10:
    ai_move_toward_card_be $0001, $0000
ai_pc_0c13:
    ai_jmp_01_short $0C13, $0C19
ai_pc_0c15:
    ai_pos_save_9f
ai_pc_0c16:
    ai_move_toward_alt_fd $0001, $0000
ai_pc_0c19:
    ai_if_tgt_not_within_64_56_short $0C19, $0BE7
ai_pc_0c1b:
    ai_ret_00
ai_pc_0c1c:
    ai_call_ff $0C52
ai_pc_0c1f:
    ai_rnd_var3_2c $0007
ai_pc_0c21:
    ai_if_var3_nz_05_short $0C21, $0C28
ai_pc_0c23:
    ai_call_ff $667F
ai_pc_0c26:
    ai_jmp_01_short $0C26, $0C4A
ai_pc_0c28:
    ai_call_ff $6AE1
ai_pc_0c2b:
    ai_if_tgt_not_within_16_34_short $0C2B, $0C32
ai_pc_0c2d:
    ai_call_ff $0C67
ai_pc_0c30:
    ai_jmp_01_short $0C30, $0C4A
ai_pc_0c32:
    ai_if_tgt_not_within_32_4c_short $0C32, $0C39
ai_pc_0c34:
    ai_call_ff $0C7C
ai_pc_0c37:
    ai_jmp_01_short $0C37, $0C4A
ai_pc_0c39:
    ai_if_tgt_not_within_48_51_short $0C39, $0C40
ai_pc_0c3b:
    ai_call_ff $0C8E
ai_pc_0c3e:
    ai_jmp_01_short $0C3E, $0C4A
ai_pc_0c40:
    ai_if_tgt_not_within_64_56_short $0C40, $0C47
ai_pc_0c42:
    ai_call_ff $0CC0
ai_pc_0c45:
    ai_jmp_01_short $0C45, $0C4A
ai_pc_0c47:
    ai_call_ff $0CDE
ai_pc_0c4a:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $0C4A, $0C1F
ai_pc_0c4f:
    ai_jmp_01_short $0C4F, $0C1F
