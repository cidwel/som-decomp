.setcpu "65816"
.segment "CODE"
.org $7D49
.include "ai_command_macros.inc"
ai_pc_2e34:
    ai_move_toward_e4 $000B, $0000
ai_pc_2e37:
    ai_ret_00
ai_pc_2e38:
    ai_move_toward_card_be $0000, $0000
ai_pc_2e3b:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2E3B, $2E46
ai_pc_2e40:
    ai_call_ff $2EE4
ai_pc_2e43:
    ai_call_ff $2EF6
ai_pc_2e46:
    ai_rnd_var3_2c $0001
ai_pc_2e48:
    ai_if_var3_nz_05_short $2E48, $2E4F
ai_pc_2e4a:
    ai_call_ff $2F81
ai_pc_2e4d:
    ai_jmp_01_short $2E4D, $2E52
ai_pc_2e4f:
    ai_call_ff $2F95
ai_pc_2e52:
    ai_ret_00
ai_pc_2e53:
    ai_move_toward_card_be $0000, $0000
ai_pc_2e56:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2E56, $2E63
ai_pc_2e5b:
    ai_call_ff $2EE4
ai_pc_2e5e:
    ai_call_ff $2EF6
ai_pc_2e61:
    ai_jmp_01_short $2E61, $2E66
ai_pc_2e63:
    ai_move_toward_card_be $0000, $0000
ai_pc_2e66:
    ai_ret_00
ai_pc_2e67:
    ai_move_toward_card_be $0000, $0000
ai_pc_2e6a:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2E6A, $2EAE
ai_pc_2e6f:
    ai_if_tgt_not_lane_v64_66_short $2E6F, $2E8C
ai_pc_2e71:
    ai_flash_fc
ai_pc_2e72:
    ai_move_toward_card_be $0000, $0000
ai_pc_2e75:
    ai_call_ff $6B19
ai_pc_2e78:
    ai_flash_fc
ai_pc_2e79:
    ai_move_toward_card_be $0000, $0000
ai_pc_2e7c:
    ai_rnd_var3_2c $0007
ai_pc_2e7e:
    ai_if_var3_nz_05_short $2E7E, $2E8A
ai_pc_2e80:
    ai_move_toward_card_be $0007, $0000
ai_pc_2e83:
    ai_pose_e2 $0004
ai_pc_2e85:
    ai_pose_e2 $0004
ai_pc_2e87:
    ai_move_toward_card_be $000B, $0000
ai_pc_2e8a:
    ai_jmp_01_short $2E8A, $2EAC
ai_pc_2e8c:
    ai_if_tgt_not_lane_h64_6f_short $2E8C, $2EA9
ai_pc_2e8e:
    ai_flash_fc
ai_pc_2e8f:
    ai_move_toward_card_be $0000, $0000
ai_pc_2e92:
    ai_call_ff $6B19
ai_pc_2e95:
    ai_flash_fc
ai_pc_2e96:
    ai_move_toward_card_be $0000, $0000
ai_pc_2e99:
    ai_rnd_var3_2c $0007
ai_pc_2e9b:
    ai_if_var3_nz_05_short $2E9B, $2EA7
ai_pc_2e9d:
    ai_move_toward_card_be $0007, $0000
ai_pc_2ea0:
    ai_pose_e2 $0004
ai_pc_2ea2:
    ai_pose_e2 $0004
ai_pc_2ea4:
    ai_move_toward_card_be $000B, $0000
ai_pc_2ea7:
    ai_jmp_01_short $2EA7, $2EAC
ai_pc_2ea9:
    ai_call_ff $2F67
ai_pc_2eac:
    ai_jmp_01_short $2EAC, $2EB1
ai_pc_2eae:
    ai_call_ff $2F67
ai_pc_2eb1:
    ai_ret_00
ai_pc_2eb2:
    ai_call_ff $6AE1
ai_pc_2eb5:
    ai_rnd_var3_2c $0007
ai_pc_2eb7:
    ai_if_var3_nz_05_short $2EB7, $2ECC
ai_pc_2eb9:
    ai_move_toward_card_be $0000, $0000
ai_pc_2ebc:
    ai_pose_e2 $0003
ai_pc_2ebe:
    ai_rnd_var3_2c $0007
ai_pc_2ec0:
    ai_if_var3_nz_05_short $2EC0, $2ECA
ai_pc_2ec2:
    ai_move_toward_card_be $0007, $0000
ai_pc_2ec5:
    ai_pose_e2 $0004
ai_pc_2ec7:
    ai_move_toward_card_be $000B, $0000
ai_pc_2eca:
    ai_jmp_01_short $2ECA, $2EE1
ai_pc_2ecc:
    ai_rnd_var3_2c $000F
ai_pc_2ece:
    ai_if_var3_nz_05_short $2ECE, $2EDE
ai_pc_2ed0:
    ai_if_word_gt_bd_short $0080, $0002, $0035, $0001, $2ED0, $2EDE
ai_pc_2ed6:
    ai_tgt2_self_c4
ai_pc_2ed7:
    ai_cast_e9 $0005, $000B
ai_pc_2eda:
    ai_tgt2_none_c0
ai_pc_2edb:
    ai_turn_facing_e3 $0000, $0078
ai_pc_2ede:
    ai_call_ff $2F67
ai_pc_2ee1:
    ai_if_tgt_not_within_64_56_short $2EE1, $2EB2
ai_pc_2ee3:
    ai_ret_00
ai_pc_2ee4:
    ai_rnd_var3_2c $0007
ai_pc_2ee6:
    ai_if_var3_nz_05_short $2EE6, $2EF5
ai_pc_2ee8:
    ai_if_field_gt_30_short $0080, $001D, $0000, $2EE8, $2EF5
ai_pc_2eed:
    ai_tgt2_self_c4
ai_pc_2eee:
    ai_cast_e9 $0005, $0009
ai_pc_2ef1:
    ai_tgt2_none_c0
ai_pc_2ef2:
    ai_turn_facing_e3 $0000, $0078
ai_pc_2ef5:
    ai_ret_00
ai_pc_2ef6:
    ai_call_ff $6AE1
ai_pc_2ef9:
    ai_if_tgt_not_lane_v64_66_short $2EF9, $2F06
ai_pc_2efb:
    ai_move_toward_card_be $0000, $0000
ai_pc_2efe:
    ai_call_ff $6B19
ai_pc_2f01:
    ai_jmp_01_long $2F01, $2F18
