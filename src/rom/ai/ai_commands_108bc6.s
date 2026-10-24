.setcpu "65816"
.segment "CODE"
.org $8BC6
.include "ai_command_macros.inc"
ai_pc_3cb1:
    ai_pose_e2 $0000
ai_pc_3cb3:
    ai_turn_facing_e3 $000E, $0000
ai_pc_3cb6:
    ai_turn_facing_e3 $000E, $0000
ai_pc_3cb9:
    ai_tgt2_self_c4
ai_pc_3cba:
    ai_cast_e9 $0002, $0022
ai_pc_3cbd:
    ai_tgt2_none_c0
ai_pc_3cbe:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_3cc1:
    ai_ret_00
ai_pc_3cc2:
    ai_move_toward_e4 $0000, $0000
ai_pc_3cc5:
    ai_pose_e2 $0001
ai_pc_3cc7:
    ai_pose_e2 $0001
ai_pc_3cc9:
    ai_tgt2_cur_c1
ai_pc_3cca:
    ai_cast_e9 $0002, $001F
ai_pc_3ccd:
    ai_tgt2_none_c0
ai_pc_3cce:
    ai_turn_facing_e3 $0000, $00F0
ai_pc_3cd1:
    ai_call_ff $3D4C
ai_pc_3cd4:
    ai_ret_00
ai_pc_3cd5:
    ai_move_toward_e4 $0000, $0000
ai_pc_3cd8:
    ai_rnd_var3_2c $0003
ai_pc_3cda:
    ai_if_var3_nz_05_short $3CDA, $3CF6
ai_pc_3cdc:
    ai_move_toward_e4 $000E, $0000
ai_pc_3cdf:
    ai_move_toward_e4 $000E, $0000
ai_pc_3ce2:
    ai_move_toward_e4 $000E, $0000
ai_pc_3ce5:
    ai_call_ff $3D1F
ai_pc_3ce8:
    ai_if_word_and_z_bb_short $0081, $0010, $0010, $0000, $3CE8, $3CF4
ai_pc_3cee:
    ai_call_ff $3D3A
ai_pc_3cf1:
    ai_call_ff $3CFA
ai_pc_3cf4:
    ai_jmp_01_short $3CF4, $3CF9
ai_pc_3cf6:
    ai_move_toward_e4 $0000, $0000
ai_pc_3cf9:
    ai_ret_00
ai_pc_3cfa:
    ai_pose_e2 $0001
ai_pc_3cfc:
    ai_pose_e2 $0001
ai_pc_3cfe:
    ai_rnd_var3_2c $0003
ai_pc_3d00:
    ai_if_var3_nz_05_short $3D00, $3D09
ai_pc_3d02:
    ai_pose_e2 $0003
ai_pc_3d04:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_3d07:
    ai_jmp_01_short $3D07, $3D1E
ai_pc_3d09:
    ai_field_set_dc $0080, $0006, $0063
ai_pc_3d0d:
    ai_tgt2_cur_c1
ai_pc_3d0e:
    ai_cast_e9 $0002, $001F
ai_pc_3d11:
    ai_tgt2_none_c0
ai_pc_3d12:
    ai_turn_facing_e3 $0000, $00F0
ai_pc_3d15:
    ai_pose_e2 $0001
ai_pc_3d17:
    ai_pose_e2 $0001
ai_pc_3d19:
    ai_cmd43_ed $0017
ai_pc_3d1b:
    ai_cmd81_ef $0005, $00FE
ai_pc_3d1e:
    ai_ret_00
ai_pc_3d1f:
    ai_if_obj_outside_5f_short $0080, $3D1F, $3D30
ai_pc_3d22:
    ai_if_word_and_nz_ba_short $0081, $0010, $0010, $0000, $3D22, $3D30
ai_pc_3d28:
    ai_tgt2_cur_c1
ai_pc_3d29:
    ai_cast_e9 $0002, $001E
ai_pc_3d2c:
    ai_tgt2_none_c0
ai_pc_3d2d:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_3d30:
    ai_ret_00
ai_pc_3d31:
    ai_call_ff $6AE1
ai_pc_3d34:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_3d37:
    ai_if_tgt_not_within_64_56_short $3D37, $3D31
ai_pc_3d39:
    ai_ret_00
ai_pc_3d3a:
    ai_call_ff $6AE1
ai_pc_3d3d:
    ai_if_pos_same_9d_short $3D3D, $3D45
ai_pc_3d3f:
    ai_pos_save_9f
ai_pc_3d40:
    ai_move_toward_e4 $0001, $0005
ai_pc_3d43:
    ai_jmp_01_short $3D43, $3D49
ai_pc_3d45:
    ai_pos_save_9f
ai_pc_3d46:
    ai_move_toward_alt_fd $0001, $0005
ai_pc_3d49:
    ai_if_tgt_not_within_16_34_short $3D49, $3D3A
ai_pc_3d4b:
    ai_ret_00
ai_pc_3d4c:
    ai_if_tgt_not_within_48_51_short $3D4C, $3D56
ai_pc_3d4e:
    ai_call_ff $6AE1
ai_pc_3d51:
    ai_move_toward_alt_fd $0005, $000A
ai_pc_3d54:
    ai_jmp_01_short $3D54, $3D4C
ai_pc_3d56:
    ai_ret_00
ai_pc_3d57:
    ai_call_ff $3D86
ai_pc_3d5a:
    ai_rnd_var3_2c $000F
ai_pc_3d5c:
    ai_if_var3_nz_05_short $3D5C, $3D63
ai_pc_3d5e:
    ai_call_ff $6653
ai_pc_3d61:
    ai_jmp_01_short $3D61, $3D7E
ai_pc_3d63:
    ai_call_ff $6AE1
ai_pc_3d66:
    ai_if_tgt_not_within_32_4c_short $3D66, $3D6D
ai_pc_3d68:
    ai_call_ff $3D9C
ai_pc_3d6b:
    ai_jmp_01_short $3D6B, $3D7E
ai_pc_3d6d:
    ai_if_tgt_not_within_48_51_short $3D6D, $3D74
ai_pc_3d6f:
    ai_call_ff $3DB1
ai_pc_3d72:
    ai_jmp_01_short $3D72, $3D7E
ai_pc_3d74:
    ai_if_tgt_not_within_64_56_short $3D74, $3D7B
ai_pc_3d76:
    ai_call_ff $3DDB
ai_pc_3d79:
    ai_jmp_01_short $3D79, $3D7E
ai_pc_3d7b:
    ai_call_ff $3E04
ai_pc_3d7e:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $3D7E, $3D5A
ai_pc_3d83:
    ai_jmp_01_short $3D83, $3D5A
