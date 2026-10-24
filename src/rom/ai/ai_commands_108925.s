.setcpu "65816"
.segment "CODE"
.org $8925
.include "ai_command_macros.inc"
ai_pc_3a10:
    ai_turn_facing_e3 $0013, $0000
ai_pc_3a13:
    ai_call_ff $6AE1
ai_pc_3a16:
    ai_turn_facing_e3 $0000, $003C
ai_pc_3a19:
    ai_if_word_gt_bd_short $0080, $0002, $0067, $0001, $3A19, $3A22
ai_pc_3a1f:
    ai_jmp_01_long $3A1F, $3A24
ai_pc_3a22:
    ai_if_tgt_not_within_64_56_short $3A22, $3A13
ai_pc_3a24:
    ai_turn_facing_e3 $0014, $0000
ai_pc_3a27:
    ai_turn_facing_e3 $0003, $000F
ai_pc_3a2a:
    ai_set_var2_27 $0003
ai_pc_3a2c:
    ai_call_ff $3A60
ai_pc_3a2f:
    ai_ret_00
ai_pc_3a30:
    ai_move_toward_card_be $0000, $0000
ai_pc_3a33:
    ai_if_field_gt_30_short $0080, $006D, $0000, $3A33, $3A49
ai_pc_3a38:
    ai_if_tgt_not_lane_v64_66_short $3A38, $3A3F
ai_pc_3a3a:
    ai_call_ff $3A54
ai_pc_3a3d:
    ai_jmp_01_short $3A3D, $3A49
ai_pc_3a3f:
    ai_if_tgt_not_lane_h64_6f_short $3A3F, $3A46
ai_pc_3a41:
    ai_call_ff $3A54
ai_pc_3a44:
    ai_jmp_01_short $3A44, $3A49
ai_pc_3a46:
    ai_call_ff $675B
ai_pc_3a49:
    ai_if_tgt_not_within_32_4c_short $3A49, $3A50
ai_pc_3a4b:
    ai_call_ff $3A84
ai_pc_3a4e:
    ai_jmp_01_short $3A4E, $3A53
ai_pc_3a50:
    ai_move_toward_card_be $0000, $0000
ai_pc_3a53:
    ai_ret_00
ai_pc_3a54:
    ai_move_toward_card_be $0000, $0000
ai_pc_3a57:
    ai_set_var2_27 $0001
ai_pc_3a59:
    ai_call_ff $3A60
ai_pc_3a5c:
    ai_call_ff $6B19
ai_pc_3a5f:
    ai_ret_00
ai_pc_3a60:
    ai_pose_e2 $0003
ai_pc_3a62:
    ai_dec_var2_20
ai_pc_3a63:
    ai_if_var2_nz_04_short $3A63, $3A60
ai_pc_3a65:
    ai_ret_00
ai_pc_3a66:
    ai_rnd_var3_2c $0007
ai_pc_3a68:
    ai_if_var3_nz_05_short $3A68, $3A72
ai_pc_3a6a:
    ai_tgt2_self_c4
ai_pc_3a6b:
    ai_cast_e9 $0002, $0005
ai_pc_3a6e:
    ai_tgt2_none_c0
ai_pc_3a6f:
    ai_turn_facing_e3 $0000, $003C
ai_pc_3a72:
    ai_call_ff $6AE1
ai_pc_3a75:
    ai_call_ff $3A98
ai_pc_3a78:
    ai_call_ff $52AD
ai_pc_3a7b:
    ai_call_ff $3A98
ai_pc_3a7e:
    ai_call_ff $52AD
ai_pc_3a81:
    ai_if_tgt_not_within_48_51_short $3A81, $3A72
ai_pc_3a83:
    ai_ret_00
ai_pc_3a84:
    ai_if_tgt_not_within_48_51_short $3A84, $3A97
ai_pc_3a86:
    ai_call_ff $6AE1
ai_pc_3a89:
    ai_call_ff $3A98
ai_pc_3a8c:
    ai_call_ff $52C6
ai_pc_3a8f:
    ai_call_ff $3A98
ai_pc_3a92:
    ai_call_ff $52C6
ai_pc_3a95:
    ai_jmp_01_short $3A95, $3A84
ai_pc_3a97:
    ai_ret_00
ai_pc_3a98:
    ai_if_field_gt_30_short $0080, $006D, $0000, $3A98, $3AA9
ai_pc_3a9d:
    ai_if_tgt_not_lane_v64_66_short $3A9D, $3AA4
ai_pc_3a9f:
    ai_call_ff $3A54
ai_pc_3aa2:
    ai_jmp_01_short $3AA2, $3AA9
ai_pc_3aa4:
    ai_if_tgt_not_lane_h64_6f_short $3AA4, $3AA9
ai_pc_3aa6:
    ai_call_ff $3A54
ai_pc_3aa9:
    ai_ret_00
ai_pc_3aaa:
    ai_call_ff $3AD5
ai_pc_3aad:
    ai_rnd_var3_2c $000F
ai_pc_3aaf:
    ai_if_var3_nz_05_short $3AAF, $3AB6
ai_pc_3ab1:
    ai_call_ff $690F
ai_pc_3ab4:
    ai_jmp_01_short $3AB4, $3ACD
ai_pc_3ab6:
    ai_call_ff $6AE1
ai_pc_3ab9:
    ai_call_ff $3B29
ai_pc_3abc:
    ai_if_tgt_not_within_48_51_short $3ABC, $3AC3
ai_pc_3abe:
    ai_call_ff $3ADA
ai_pc_3ac1:
    ai_jmp_01_short $3AC1, $3ACD
ai_pc_3ac3:
    ai_if_tgt_not_within_64_56_short $3AC3, $3ACA
ai_pc_3ac5:
    ai_call_ff $3AEF
ai_pc_3ac8:
    ai_jmp_01_short $3AC8, $3ACD
ai_pc_3aca:
    ai_call_ff $3B4B
ai_pc_3acd:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $3ACD, $3AAD
ai_pc_3ad2:
    ai_jmp_01_short $3AD2, $3AAD
