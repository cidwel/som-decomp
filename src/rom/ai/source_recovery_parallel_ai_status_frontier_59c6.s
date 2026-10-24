.setcpu "65816"
.segment "CODE"
.org $A8DB
.include "source_recovery_parallel_ai_status_frontier_macros.inc"
ai_pc_59c6:
    ai_call_ff $5913
ai_pc_59c9:
    ai_if_pos_same_9d_short $59C9, $59D1
ai_pc_59cb:
    ai_pos_save_9f
ai_pc_59cc:
    ai_move_toward_e4 $0009, $000A
ai_pc_59cf:
    ai_jmp_01_short $59CF, $59D5
ai_pc_59d1:
    ai_pos_save_9f
ai_pc_59d2:
    ai_move_toward_alt_fd $0009, $000A
ai_pc_59d5:
    ai_if_tgt_not_within_16_34_short $59D5, $59C6
ai_pc_59d7:
    ai_ret_00
ai_pc_59d8:
    ai_if_tgt_not_within_48_51_short $59D8, $59FA
ai_pc_59da:
    ai_call_ff $5913
ai_pc_59dd:
    ai_if_tgt_not_within_16_34_short $59DD, $59EC
ai_pc_59df:
    ai_if_field_gt_30_short $0080, $006D, $0000, $59DF, $59EC
ai_pc_59e4:
    ai_if_charge_set_f2_short $0000, $59E4, $59EC
ai_pc_59e7:
    ai_move_toward_e4 $0000, $0005
ai_pc_59ea:
    ai_swing_plain_df
ai_pc_59eb:
    ai_charge_start_f3
ai_pc_59ec:
    ai_if_pos_same_9d_short $59EC, $59F4
ai_pc_59ee:
    ai_pos_save_9f
ai_pc_59ef:
    ai_move_away_card_bf $0009, $000A
ai_pc_59f2:
    ai_jmp_01_short $59F2, $59F8
ai_pc_59f4:
    ai_pos_save_9f
ai_pc_59f5:
    ai_move_away_alt_fe $0009, $000A
ai_pc_59f8:
    ai_jmp_01_short $59F8, $59D8
ai_pc_59fa:
    ai_ret_00
ai_pc_59fb:
    ai_call_ff $5913
ai_pc_59fe:
    ai_if_pos_same_9d_short $59FE, $5A06
ai_pc_5a00:
    ai_pos_save_9f
ai_pc_5a01:
    ai_move_toward_card_be $0009, $000A
ai_pc_5a04:
    ai_jmp_01_short $5A04, $5A0A
ai_pc_5a06:
    ai_pos_save_9f
ai_pc_5a07:
    ai_move_toward_alt_fd $0009, $000A
ai_pc_5a0a:
    ai_if_tgt_not_within_64_56_short $5A0A, $59FB
ai_pc_5a0c:
    ai_ret_00
ai_pc_5a0d:
    ai_if_tgt_not_within_48_51_short $5A0D, $5A20
ai_pc_5a0f:
    ai_call_ff $5913
ai_pc_5a12:
    ai_if_pos_same_9d_short $5A12, $5A1A
ai_pc_5a14:
    ai_pos_save_9f
ai_pc_5a15:
    ai_move_away_e6 $000A, $0005
ai_pc_5a18:
    ai_jmp_01_short $5A18, $5A1E
ai_pc_5a1a:
    ai_pos_save_9f
ai_pc_5a1b:
    ai_move_away_alt_fe $000A, $0005
ai_pc_5a1e:
    ai_jmp_01_short $5A1E, $5A0D
ai_pc_5a20:
    ai_ret_00
