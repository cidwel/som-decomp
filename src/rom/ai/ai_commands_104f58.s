.setcpu "65816"
.segment "CODE"
.org $4F58
.include "ai_command_macros.inc"
ai_pc_0043:
    ai_pose_e2 $0000
ai_pc_0045:
    ai_pose_e2 $0000
ai_pc_0047:
    ai_pose_e2 $0000
ai_pc_0049:
    ai_ret_00
ai_pc_004a:
    ai_if_field_gt_30_short $0080, $006D, $0000, $004A, $0059
ai_pc_004f:
    ai_rnd_var3_2c $0003
ai_pc_0051:
    ai_if_var3_z_09_short $0051, $0059
ai_pc_0053:
    ai_move_toward_e4 $0000, $0000
ai_pc_0056:
    ai_call_ff $6B0F
ai_pc_0059:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_005c:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_005f:
    ai_call_ff $009C
ai_pc_0062:
    ai_ret_00
ai_pc_0063:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0063, $0070
ai_pc_0068:
    ai_move_toward_e4 $0000, $0000
ai_pc_006b:
    ai_call_ff $6B0F
ai_pc_006e:
    ai_jmp_01_short $006E, $0073
ai_pc_0070:
    ai_move_toward_e4 $0000, $0000
ai_pc_0073:
    ai_ret_00
ai_pc_0074:
    ai_rnd_var3_2c $0002
ai_pc_0076:
    ai_if_var3_nz_05_short $0076, $007D
ai_pc_0078:
    ai_move_toward_e4 $0000, $0000
ai_pc_007b:
    ai_jmp_01_short $007B, $0080
ai_pc_007d:
    ai_call_ff $6902
ai_pc_0080:
    ai_ret_00
ai_pc_0081:
    ai_call_ff $6AE1
ai_pc_0084:
    ai_if_pos_same_9d_short $0084, $008C
ai_pc_0086:
    ai_pos_save_9f
ai_pc_0087:
    ai_move_away_e6 $0002, $0000
ai_pc_008a:
    ai_jmp_01_short $008A, $0090
ai_pc_008c:
    ai_pos_save_9f
ai_pc_008d:
    ai_move_away_alt_fe $0002, $0000
ai_pc_0090:
    ai_if_tgt_not_within_32_4c_short $0090, $0099
ai_pc_0092:
    ai_call_ff $6AE1
ai_pc_0095:
    ai_pose_e2 $0005
ai_pc_0097:
    ai_jmp_01_short $0097, $0090
ai_pc_0099:
    ai_jmp_01_short $0099, $0081
