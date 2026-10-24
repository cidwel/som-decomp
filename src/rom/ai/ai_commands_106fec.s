.setcpu "65816"
.segment "CODE"
.org $6FEC
.include "ai_command_macros.inc"
ai_pc_20d7:
    ai_pose_e2 $0000
ai_pc_20d9:
    ai_ret_00
ai_pc_20da:
    ai_call_ff $216F
ai_pc_20dd:
    ai_set_var2_27 $0000
ai_pc_20df:
    ai_ret_00
ai_pc_20e0:
    ai_if_var2_nz_04_short $20E0, $20E5
ai_pc_20e2:
    ai_move_toward_card_be $0000, $0005
ai_pc_20e5:
    ai_pose_e2 $0005
ai_pc_20e7:
    ai_if_field_gt_30_short $0080, $006D, $0000, $20E7, $2114
ai_pc_20ec:
    ai_if_tgt_not_lane_v64_66_short $20EC, $20F8
ai_pc_20ee:
    ai_move_toward_card_be $0000, $0005
ai_pc_20f1:
    ai_call_ff $6B0F
ai_pc_20f4:
    ai_pose_e2 $0005
ai_pc_20f6:
    ai_jmp_01_short $20F6, $2114
ai_pc_20f8:
    ai_if_tgt_not_lane_h64_6f_short $20F8, $2104
ai_pc_20fa:
    ai_move_toward_card_be $0000, $0005
ai_pc_20fd:
    ai_call_ff $6B0F
ai_pc_2100:
    ai_pose_e2 $0005
ai_pc_2102:
    ai_jmp_01_short $2102, $2114
ai_pc_2104:
    ai_pose_e2 $0005
ai_pc_2106:
    ai_if_obj_outside_5f_short $0080, $2106, $2114
ai_pc_2109:
    ai_if_crowd_gt_f5_short $0002, $2109, $2114
ai_pc_210c:
    ai_call_ff $215D
ai_pc_210f:
    ai_cmd43_ed $0017
ai_pc_2111:
    ai_call_ff $216F
ai_pc_2114:
    ai_ret_00
ai_pc_2115:
    ai_call_ff $6AE1
ai_pc_2118:
    ai_if_pos_same_9d_short $2118, $2120
ai_pc_211a:
    ai_pos_save_9f
ai_pc_211b:
    ai_move_toward_card_be $0004, $000A
ai_pc_211e:
    ai_jmp_01_short $211E, $2124
ai_pc_2120:
    ai_pos_save_9f
ai_pc_2121:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_2124:
    ai_if_tgt_not_within_64_56_short $2124, $2115
ai_pc_2126:
    ai_set_var2_27 $0001
ai_pc_2128:
    ai_ret_00
ai_pc_2129:
    ai_if_pos_same_9d_short $2129, $2131
ai_pc_212b:
    ai_pos_save_9f
ai_pc_212c:
    ai_move_away_card_bf $0002, $0005
ai_pc_212f:
    ai_jmp_01_short $212F, $2135
ai_pc_2131:
    ai_pos_save_9f
ai_pc_2132:
    ai_move_away_alt_fe $0002, $0005
ai_pc_2135:
    ai_call_ff $6AE1
ai_pc_2138:
    ai_if_tgt_not_beyond_64_5a_short $2138, $2129
ai_pc_213a:
    ai_move_away_card_bf $0000, $0005
ai_pc_213d:
    ai_pose_e2 $0005
ai_pc_213f:
    ai_call_ff $6AE1
ai_pc_2142:
    ai_if_tgt_not_within_48_51_short $2142, $213D
ai_pc_2144:
    ai_pose_e2 $0007
ai_pc_2146:
    ai_if_crowd_gt_f5_short $0002, $2146, $214E
ai_pc_2149:
    ai_cmd43_ed $0017
ai_pc_214b:
    ai_turn_facing_e3 $0000, $0005
ai_pc_214e:
    ai_jmp_01_short $214E, $2129
