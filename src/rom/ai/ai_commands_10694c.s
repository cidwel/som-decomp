.setcpu "65816"
.segment "CODE"
.org $694C
.include "ai_command_macros.inc"
ai_pc_1a37:
    ai_pose_e2 $0000
ai_pc_1a39:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_1a3c:
    ai_ret_00
ai_pc_1a3d:
    ai_move_toward_e4 $0000, $0000
ai_pc_1a40:
    ai_if_field_gt_30_short $0080, $006D, $0000, $1A40, $1A7A
ai_pc_1a45:
    ai_if_tgt_not_lane_h48_71_short $1A45, $1A4F
ai_pc_1a47:
    ai_move_toward_card_be $0000, $0000
ai_pc_1a4a:
    ai_call_ff $6B0F
ai_pc_1a4d:
    ai_jmp_01_short $1A4D, $1A78
ai_pc_1a4f:
    ai_move_toward_e4 $0000, $0000
ai_pc_1a52:
    ai_if_obj_outside_5f_short $0080, $1A52, $1A75
ai_pc_1a55:
    ai_rnd_var3_2c $000F
ai_pc_1a57:
    ai_if_var3_nz_05_short $1A57, $1A63
ai_pc_1a59:
    ai_tgt2_cur_c1
ai_pc_1a5a:
    ai_cast_e9 $0004, $0007
ai_pc_1a5d:
    ai_tgt2_none_c0
ai_pc_1a5e:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_1a61:
    ai_jmp_01_short $1A61, $1A73
ai_pc_1a63:
    ai_if_var3_ne_0d_short $0001, $1A63, $1A70
ai_pc_1a66:
    ai_tgt2_cur_c1
ai_pc_1a67:
    ai_cast_e9 $0004, $0006
ai_pc_1a6a:
    ai_tgt2_none_c0
ai_pc_1a6b:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_1a6e:
    ai_jmp_01_short $1A6E, $1A73
ai_pc_1a70:
    ai_move_toward_e4 $0000, $0000
ai_pc_1a73:
    ai_jmp_01_short $1A73, $1A78
ai_pc_1a75:
    ai_move_toward_e4 $0000, $0000
ai_pc_1a78:
    ai_jmp_01_short $1A78, $1A7D
ai_pc_1a7a:
    ai_move_toward_e4 $0000, $0000
ai_pc_1a7d:
    ai_ret_00
ai_pc_1a7e:
    ai_if_word_gt_bd_short $0080, $0002, $0050, $0000, $1A7E, $1A8D
ai_pc_1a84:
    ai_pose_e2 $0000
ai_pc_1a86:
    ai_pose_e2 $0000
ai_pc_1a88:
    ai_cmd43_ed $001D
ai_pc_1a8a:
    ai_cmd81_ef $0005, $00FB
ai_pc_1a8d:
    ai_ret_00
ai_pc_1a8e:
    ai_call_ff $1AC4
ai_pc_1a91:
    ai_rnd_var3_2c $000F
ai_pc_1a93:
    ai_if_var3_nz_05_short $1A93, $1A9A
ai_pc_1a95:
    ai_call_ff $65CA
ai_pc_1a98:
    ai_jmp_01_short $1A98, $1ABC
ai_pc_1a9a:
    ai_call_ff $6AE1
ai_pc_1a9d:
    ai_if_tgt_not_within_16_34_short $1A9D, $1AA4
ai_pc_1a9f:
    ai_call_ff $1ACD
ai_pc_1aa2:
    ai_jmp_01_short $1AA2, $1ABC
ai_pc_1aa4:
    ai_if_tgt_not_within_32_4c_short $1AA4, $1AAB
ai_pc_1aa6:
    ai_call_ff $0894
ai_pc_1aa9:
    ai_jmp_01_short $1AA9, $1ABC
ai_pc_1aab:
    ai_if_tgt_not_within_48_51_short $1AAB, $1AB2
ai_pc_1aad:
    ai_call_ff $0878
ai_pc_1ab0:
    ai_jmp_01_short $1AB0, $1ABC
ai_pc_1ab2:
    ai_if_tgt_not_within_64_56_short $1AB2, $1AB9
ai_pc_1ab4:
    ai_call_ff $1AEB
ai_pc_1ab7:
    ai_jmp_01_short $1AB7, $1ABC
ai_pc_1ab9:
    ai_call_ff $1B4D
ai_pc_1abc:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $1ABC, $1A91
ai_pc_1ac1:
    ai_jmp_01_short $1AC1, $1A91
