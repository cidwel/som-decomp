.setcpu "65816"
.segment "CODE"
.org $7E28
.include "ai_command_macros.inc"
ai_pc_2f13:
    ai_call_ff $6653
ai_pc_2f16:
    ai_if_tgt_not_within_16_34_short $2F16, $2EF6
ai_pc_2f18:
    ai_ret_00
ai_pc_2f19:
    ai_pose_e2 $0007
ai_pc_2f1b:
    ai_call_ff $6AE1
ai_pc_2f1e:
    ai_pose_e2 $0007
ai_pc_2f20:
    ai_if_tgt_not_within_32_4c_short $2F20, $2F1B
ai_pc_2f22:
    ai_move_toward_e4 $000B, $0000
ai_pc_2f25:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2F25, $2F3C
ai_pc_2f2a:
    ai_if_tgt_not_lane_v64_66_short $2F2A, $2F34
ai_pc_2f2c:
    ai_move_toward_card_be $0000, $0000
ai_pc_2f2f:
    ai_call_ff $6B19
ai_pc_2f32:
    ai_jmp_01_short $2F32, $2F3C
ai_pc_2f34:
    ai_if_tgt_not_lane_h64_6f_short $2F34, $2F3C
ai_pc_2f36:
    ai_move_toward_card_be $0000, $0000
ai_pc_2f39:
    ai_call_ff $6B19
ai_pc_2f3c:
    ai_rnd_var3_2c $0001
ai_pc_2f3e:
    ai_if_var3_nz_05_short $2F3E, $2F55
ai_pc_2f40:
    ai_if_tgt_not_within_64_56_short $2F40, $2F53
ai_pc_2f42:
    ai_call_ff $6AE1
ai_pc_2f45:
    ai_if_pos_same_9d_short $2F45, $2F4D
ai_pc_2f47:
    ai_pos_save_9f
ai_pc_2f48:
    ai_move_away_card_bf $0001, $0005
ai_pc_2f4b:
    ai_jmp_01_short $2F4B, $2F51
ai_pc_2f4d:
    ai_pos_save_9f
ai_pc_2f4e:
    ai_move_away_alt_fe $0001, $0005
ai_pc_2f51:
    ai_jmp_01_short $2F51, $2F40
ai_pc_2f53:
    ai_jmp_01_short $2F53, $2F63
ai_pc_2f55:
    ai_if_tgt_not_within_64_56_short $2F55, $2F63
ai_pc_2f57:
    ai_call_ff $6AE1
ai_pc_2f5a:
    ai_flash_fc
ai_pc_2f5b:
    ai_move_away_card_bf $0000, $0000
ai_pc_2f5e:
    ai_pose_e2 $0003
ai_pc_2f60:
    ai_flash_fc
ai_pc_2f61:
    ai_jmp_01_short $2F61, $2F55
ai_pc_2f63:
    ai_jmp_01_long $2F63, $2F1B
