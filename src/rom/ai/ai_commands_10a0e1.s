.setcpu "65816"
.segment "CODE"
.org $A0E1
.include "ai_command_macros.inc"
ai_pc_51cc:
    ai_pose_e2 $0003
ai_pc_51ce:
    ai_call_ff $6AE1
ai_pc_51d1:
    ai_pose_e2 $0003
ai_pc_51d3:
    ai_move_toward_card_be $0003, $0005
ai_pc_51d6:
    ai_call_ff $6B2D
ai_pc_51d9:
    ai_ret_00
ai_pc_51da:
    ai_move_toward_card_be $0003, $0005
ai_pc_51dd:
    ai_if_field_gt_30_short $0080, $006D, $0000, $51DD, $51F3
ai_pc_51e2:
    ai_if_tgt_not_lane_v64_66_short $51E2, $51E9
ai_pc_51e4:
    ai_call_ff $5236
ai_pc_51e7:
    ai_jmp_01_short $51E7, $51F3
ai_pc_51e9:
    ai_if_tgt_not_lane_h64_6f_short $51E9, $51F0
ai_pc_51eb:
    ai_call_ff $5236
ai_pc_51ee:
    ai_jmp_01_short $51EE, $51F3
ai_pc_51f0:
    ai_call_ff $675B
ai_pc_51f3:
    ai_if_tgt_not_within_32_4c_short $51F3, $51FA
ai_pc_51f5:
    ai_call_ff $5285
ai_pc_51f8:
    ai_jmp_01_short $51F8, $51FD
ai_pc_51fa:
    ai_move_toward_card_be $0000, $0000
ai_pc_51fd:
    ai_ret_00
ai_pc_51fe:
    ai_move_toward_e4 $0000, $0005
ai_pc_5201:
    ai_if_obj_outside_5f_short $0080, $5201, $5210
ai_pc_5204:
    ai_rnd_var3_2c $000F
ai_pc_5206:
    ai_if_var3_nz_05_short $5206, $5210
ai_pc_5208:
    ai_tgt2_cur_c1
ai_pc_5209:
    ai_cast_e9 $0002, $0028
ai_pc_520c:
    ai_tgt2_none_c0
ai_pc_520d:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_5210:
    ai_call_ff $526F
ai_pc_5213:
    ai_ret_00
ai_pc_5214:
    ai_call_ff $5260
ai_pc_5217:
    ai_set_var2_27 $0008
ai_pc_5219:
    ai_call_ff $524B
ai_pc_521c:
    ai_if_var1_nz_03_short $521C, $5223
ai_pc_521e:
    ai_jmp_01_long $521E, $5235
