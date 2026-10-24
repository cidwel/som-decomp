.setcpu "65816"
.segment "CODE"
.org $5195
.include "ai_command_macros.inc"
ai_pc_0280:
    ai_pose_e2 $0000
ai_pc_0282:
    ai_call_ff $6AE1
ai_pc_0285:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_0289:
    ai_call_ff $6B0F
ai_pc_028c:
    ai_ret_00
ai_pc_028d:
    ai_if_tgt_not_within_48_51_short $028D, $02A0
ai_pc_028f:
    ai_call_ff $6AE1
ai_pc_0292:
    ai_if_pos_same_9d_short $0292, $029A
ai_pc_0294:
    ai_pos_save_9f
ai_pc_0295:
    ai_move_away_e6 $0002, $0005
ai_pc_0298:
    ai_jmp_01_short $0298, $029E
ai_pc_029a:
    ai_pos_save_9f
ai_pc_029b:
    ai_move_away_alt_fe $0002, $0005
ai_pc_029e:
    ai_jmp_01_short $029E, $028D
ai_pc_02a0:
    ai_ret_00
ai_pc_02a1:
    ai_if_field_gt_30_short $0080, $006D, $0000, $02A1, $02AE
ai_pc_02a6:
    ai_move_toward_card_be $0000, $0000
ai_pc_02a9:
    ai_call_ff $6B0F
ai_pc_02ac:
    ai_jmp_01_short $02AC, $02B1
ai_pc_02ae:
    ai_move_toward_card_be $0000, $0000
ai_pc_02b1:
    ai_ret_00
ai_pc_02b2:
    ai_if_field_gt_30_short $0080, $006D, $0000, $02B2, $02C9
ai_pc_02b7:
    ai_if_tgt_not_lane_v_6a_short $02B7, $02C1
ai_pc_02b9:
    ai_move_toward_card_be $0000, $0005
ai_pc_02bc:
    ai_call_ff $6B0F
ai_pc_02bf:
    ai_jmp_01_short $02BF, $02C9
ai_pc_02c1:
    ai_if_tgt_not_lane_h_73_short $02C1, $02C9
ai_pc_02c3:
    ai_move_toward_card_be $0000, $0005
ai_pc_02c6:
    ai_call_ff $6B0F
ai_pc_02c9:
    ai_call_ff $6AE1
ai_pc_02cc:
    ai_if_pos_same_9d_short $02CC, $02D4
ai_pc_02ce:
    ai_pos_save_9f
ai_pc_02cf:
    ai_move_toward_e4 $0002, $0005
ai_pc_02d2:
    ai_jmp_01_short $02D2, $02D8
ai_pc_02d4:
    ai_pos_save_9f
ai_pc_02d5:
    ai_move_toward_alt_fd $0002, $0005
ai_pc_02d8:
    ai_if_tgt_not_within_64_56_short $02D8, $02B2
ai_pc_02da:
    ai_ret_00
ai_pc_02db:
    ai_call_ff $0311
ai_pc_02de:
    ai_rnd_var3_2c $0007
ai_pc_02e0:
    ai_if_var3_nz_05_short $02E0, $02E7
ai_pc_02e2:
    ai_call_ff $675B
ai_pc_02e5:
    ai_jmp_01_short $02E5, $0309
ai_pc_02e7:
    ai_call_ff $6AE1
ai_pc_02ea:
    ai_if_tgt_not_within_16_34_short $02EA, $02F1
ai_pc_02ec:
    ai_call_ff $0326
ai_pc_02ef:
    ai_jmp_01_short $02EF, $0309
ai_pc_02f1:
    ai_if_tgt_not_within_32_4c_short $02F1, $02F8
ai_pc_02f3:
    ai_call_ff $0338
ai_pc_02f6:
    ai_jmp_01_short $02F6, $0309
ai_pc_02f8:
    ai_if_tgt_not_within_48_51_short $02F8, $02FF
ai_pc_02fa:
    ai_call_ff $034A
ai_pc_02fd:
    ai_jmp_01_short $02FD, $0309
ai_pc_02ff:
    ai_if_tgt_not_within_64_56_short $02FF, $0306
ai_pc_0301:
    ai_call_ff $036C
ai_pc_0304:
    ai_jmp_01_short $0304, $0309
ai_pc_0306:
    ai_call_ff $036C
ai_pc_0309:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $0309, $02DE
ai_pc_030e:
    ai_jmp_01_short $030E, $02DE
