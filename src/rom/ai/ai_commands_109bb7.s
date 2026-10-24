.setcpu "65816"
.segment "CODE"
.org $9BB7
.include "ai_command_macros.inc"
ai_pc_4ca2:
    ai_turn_facing_e3 $0000, $0000
ai_pc_4ca5:
    ai_pose_e2 $0001
ai_pc_4ca7:
    ai_turn_facing_e3 $0003, $0000
ai_pc_4caa:
    ai_call_ff $4D01
ai_pc_4cad:
    ai_ret_00
ai_pc_4cae:
    ai_call_ff $4CE8
ai_pc_4cb1:
    ai_rnd_var3_2c $000F
ai_pc_4cb3:
    ai_if_var3_nz_05_short $4CB3, $4CB8
ai_pc_4cb5:
    ai_call_ff $4D0F
ai_pc_4cb8:
    ai_ret_00
ai_pc_4cb9:
    ai_call_ff $4D01
ai_pc_4cbc:
    ai_move_toward_e4 $0003, $0005
ai_pc_4cbf:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4CBF, $4CDD
ai_pc_4cc4:
    ai_if_tgt_not_lane_v64_66_short $4CC4, $4CCE
ai_pc_4cc6:
    ai_call_ff $4CE1
ai_pc_4cc9:
    ai_call_ff $4CE8
ai_pc_4ccc:
    ai_jmp_01_short $4CCC, $4CDB
ai_pc_4cce:
    ai_if_tgt_not_lane_h64_6f_short $4CCE, $4CD8
ai_pc_4cd0:
    ai_call_ff $4CE1
ai_pc_4cd3:
    ai_call_ff $4CE8
ai_pc_4cd6:
    ai_jmp_01_short $4CD6, $4CDB
ai_pc_4cd8:
    ai_call_ff $675B
ai_pc_4cdb:
    ai_jmp_01_short $4CDB, $4CE0
ai_pc_4cdd:
    ai_call_ff $4CE8
ai_pc_4ce0:
    ai_ret_00
ai_pc_4ce1:
    ai_move_toward_card_be $0003, $0005
ai_pc_4ce4:
    ai_call_ff $6B23
ai_pc_4ce7:
    ai_ret_00
ai_pc_4ce8:
    ai_move_toward_e4 $000E, $0000
ai_pc_4ceb:
    ai_move_away_card_bf $0000, $0005
ai_pc_4cee:
    ai_pose_e2 $0003
ai_pc_4cf0:
    ai_pose_e2 $0004
ai_pc_4cf2:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_4cf6:
    ai_move_toward_card_be $0003, $0005
ai_pc_4cf9:
    ai_call_ff $6B23
ai_pc_4cfc:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_4d00:
    ai_ret_00
ai_pc_4d01:
    ai_if_field_gt_30_short $0080, $0038, $0000, $4D01, $4D0E
ai_pc_4d06:
    ai_tgt2_self_c4
ai_pc_4d07:
    ai_cast_e9 $0002, $0022
ai_pc_4d0a:
    ai_tgt2_none_c0
ai_pc_4d0b:
    ai_turn_facing_e3 $0000, $003C
ai_pc_4d0e:
    ai_ret_00
ai_pc_4d0f:
    ai_if_obj_outside_5f_short $0080, $4D0F, $4D1A
ai_pc_4d12:
    ai_tgt2_cur_c1
ai_pc_4d13:
    ai_cast_e9 $0002, $0025
ai_pc_4d16:
    ai_tgt2_none_c0
ai_pc_4d17:
    ai_turn_facing_e3 $0000, $0078
ai_pc_4d1a:
    ai_ret_00
ai_pc_4d1b:
    ai_call_ff $6AE1
ai_pc_4d1e:
    ai_call_ff $52AD
ai_pc_4d21:
    ai_call_ff $52AD
ai_pc_4d24:
    ai_if_tgt_not_within_48_51_short $4D24, $4D1B
ai_pc_4d26:
    ai_ret_00
ai_pc_4d27:
    ai_call_ff $4D56
ai_pc_4d2a:
    ai_rnd_var3_2c $000F
ai_pc_4d2c:
    ai_if_var3_nz_05_short $4D2C, $4D33
ai_pc_4d2e:
    ai_call_ff $672F
ai_pc_4d31:
    ai_jmp_01_short $4D31, $4D4E
ai_pc_4d33:
    ai_call_ff $6AE1
ai_pc_4d36:
    ai_if_tgt_not_within_32_4c_short $4D36, $4D3D
ai_pc_4d38:
    ai_call_ff $4DB0
ai_pc_4d3b:
    ai_jmp_01_short $4D3B, $4D4E
ai_pc_4d3d:
    ai_if_tgt_not_within_48_51_short $4D3D, $4D44
ai_pc_4d3f:
    ai_call_ff $4E32
ai_pc_4d42:
    ai_jmp_01_short $4D42, $4D4E
ai_pc_4d44:
    ai_if_tgt_not_within_64_56_short $4D44, $4D4B
ai_pc_4d46:
    ai_call_ff $4D64
ai_pc_4d49:
    ai_jmp_01_short $4D49, $4D4E
ai_pc_4d4b:
    ai_call_ff $4D7D
ai_pc_4d4e:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $4D4E, $4D2A
ai_pc_4d53:
    ai_jmp_01_short $4D53, $4D2A
