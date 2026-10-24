.setcpu "65816"
.segment "CODE"
.org $B337
.include "source_recovery_parallel_ai_status_frontier_macros.inc"
ai_pc_6422:
    ai_if_word_and_z_bb_long $0080, $0010, $0000, $0002, $6422, $6486
ai_pc_6429:
    ai_call_ff $5913
ai_pc_642c:
    ai_if_tgt_not_within_16_34_short $642C, $6447
ai_pc_642e:
    ai_if_field_gt_30_short $0080, $006D, $0000, $642E, $6442
ai_pc_6433:
    ai_if_charge_set_f2_short $0000, $6433, $643D
ai_pc_6436:
    ai_move_toward_e4 $0000, $0005
ai_pc_6439:
    ai_swing_plain_df
ai_pc_643a:
    ai_charge_start_f3
ai_pc_643b:
    ai_jmp_01_short $643B, $6440
ai_pc_643d:
    ai_call_ff $59D8
ai_pc_6440:
    ai_jmp_01_short $6440, $6445
ai_pc_6442:
    ai_call_ff $59D8
ai_pc_6445:
    ai_jmp_01_short $6445, $647A
ai_pc_6447:
    ai_if_tgt_not_within_64_56_short $6447, $6465
ai_pc_6449:
    ai_if_field_gt_30_short $0080, $006D, $0000, $6449, $6460
ai_pc_644e:
    ai_if_charge_set_f2_short $0000, $644E, $645B
ai_pc_6451:
    ai_call_ff $59C6
ai_pc_6454:
    ai_move_toward_e4 $0000, $0005
ai_pc_6457:
    ai_swing_plain_df
ai_pc_6458:
    ai_charge_start_f3
ai_pc_6459:
    ai_jmp_01_short $6459, $645E
ai_pc_645b:
    ai_call_ff $59D8
ai_pc_645e:
    ai_jmp_01_short $645E, $6463
ai_pc_6460:
    ai_call_ff $59D8
ai_pc_6463:
    ai_jmp_01_short $6463, $647A
ai_pc_6465:
    ai_if_field_gt_30_short $0080, $006D, $0000, $6465, $6477
ai_pc_646a:
    ai_if_charge_set_f2_short $0000, $646A, $6472
ai_pc_646d:
    ai_call_ff $59FB
ai_pc_6470:
    ai_jmp_01_short $6470, $6475
ai_pc_6472:
    ai_move_toward_e4 $0000, $0005
ai_pc_6475:
    ai_jmp_01_short $6475, $647A
ai_pc_6477:
    ai_move_toward_e4 $0000, $0005
ai_pc_647a:
    ai_if_word_and_nz_ba_long $0080, $0010, $0000, $0002, $647A, $6429
ai_pc_6481:
    ai_jmp_01_long $6481, $648D
