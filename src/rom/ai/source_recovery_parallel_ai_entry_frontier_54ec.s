.setcpu "65816"
.segment "CODE"
.org $A401
.include "source_recovery_parallel_ai_entry_frontier_macros.inc"
ai_pc_54ec:
    ai_hop_e0 $0004, $0000, $000A
ai_pc_54f0:
    ai_ret_00
ai_pc_54f1:
    ai_call_ff $550A
ai_pc_54f4:
    ai_if_field_gt_30_short $0080, $0003, $00FE, $54F4, $54FF
ai_pc_54f9:
    ai_call_ff $5581
ai_pc_54fc:
    ai_cmd04_ee
ai_pc_54fd:
    ai_jmp_01_short $54FD, $5509
ai_pc_54ff:
    ai_hop_e0 $0008, $0002, $003C
ai_pc_5503:
    ai_hop_e0 $0001, $0002, $0000
ai_pc_5507:
    ai_apply_selected_actor_effect_61
ai_pc_5508:
    ai_cmd04_ee
ai_pc_5509:
    ai_ret_00
ai_pc_550a:
    ai_hop_e0 $0008, $0000, $0005
ai_pc_550e:
    ai_if_field_lt_2f_short $0080, $0002, $00FF, $550E, $5519
ai_pc_5513:
    ai_call_ff $5530
ai_pc_5516:
    ai_jmp_01_long $5516, $552B
ai_pc_5519:
    ai_if_field_lt_2f_short $0080, $0004, $00FF, $5519, $5522
ai_pc_551e:
    ai_hop_e0 $0004, $0002, $0005
ai_pc_5522:
    ai_hop_e0 $0008, $0000, $0005
ai_pc_5526:
    ai_if_field_lt_2f_short $0080, $0001, $00FF, $5526, $550E
ai_pc_552b:
    ai_hop_e0 $0008, $0002, $0000
ai_pc_552f:
    ai_ret_00
ai_pc_5530:
    ai_if_field_gt_30_long $0080, $0001, $00FE, $5530, $5580
ai_pc_5536:
    ai_call_ff $6AE1
ai_pc_5539:
    ai_hop_e0 $0008, $0000, $0005
ai_pc_553d:
    ai_if_tgt_not_within_48_51_short $553D, $557D
ai_pc_553f:
    ai_call_ff $6AE1
ai_pc_5542:
    ai_if_field_lt_2f_short $0080, $0001, $00FF, $5542, $554A
ai_pc_5547:
    ai_jmp_01_long $5547, $557D
ai_pc_554a:
    ai_if_field_lt_2f_short $0080, $0004, $00FF, $554A, $5553
ai_pc_554f:
    ai_hop_e0 $0004, $0002, $0005
ai_pc_5553:
    ai_if_pos_same_9d_short $5553, $555B
ai_pc_5555:
    ai_pos_save_9f
ai_pc_5556:
    ai_move_away_card_bf $0007, $000A
ai_pc_5559:
    ai_jmp_01_short $5559, $555F
ai_pc_555b:
    ai_pos_save_9f
ai_pc_555c:
    ai_move_away_alt_fe $0007, $000A
ai_pc_555f:
    ai_if_tgt_not_within_16_34_short $555F, $557B
ai_pc_5561:
    ai_call_ff $6AE1
ai_pc_5564:
    ai_if_field_lt_2f_short $0080, $0001, $00FF, $5564, $556C
ai_pc_5569:
    ai_jmp_01_long $5569, $557B
ai_pc_556c:
    ai_if_field_lt_2f_short $0080, $0004, $00FF, $556C, $5575
ai_pc_5571:
    ai_hop_e0 $0004, $0002, $0005
ai_pc_5575:
    ai_hop_e0 $0008, $0000, $0005
ai_pc_5579:
    ai_jmp_01_short $5579, $555F
ai_pc_557b:
    ai_jmp_01_short $557B, $553D
ai_pc_557d:
    ai_jmp_01_long $557D, $5530
ai_pc_5580:
    ai_ret_00
ai_pc_5581:
    ai_if_field_gt_30_short $0080, $0048, $0000, $5581, $5599
ai_pc_5586:
    ai_rnd_var3_2c $0007
ai_pc_5588:
    ai_if_var3_nz_05_short $5588, $5591
ai_pc_558a:
    ai_hop_e0 $0004, $0004, $0000
ai_pc_558e:
    ai_apply_selected_actor_effect_61
ai_pc_558f:
    ai_jmp_01_short $558F, $5596
ai_pc_5591:
    ai_hop_e0 $0008, $0004, $0000
ai_pc_5595:
    ai_apply_selected_actor_effect_61
ai_pc_5596:
    ai_jmp_01_long $5596, $5604
ai_pc_5599:
    ai_if_field_gt_30_short $0080, $0048, $0001, $5599, $55AA
ai_pc_559e:
    ai_hop_e0 $0001, $0004, $0000
ai_pc_55a2:
    ai_apply_selected_actor_effect_61
ai_pc_55a3:
    ai_hop_e0 $0001, $0002, $0000
ai_pc_55a7:
    ai_jmp_01_long $55A7, $5604
ai_pc_55aa:
    ai_if_field_gt_30_short $0080, $0048, $0002, $55AA, $55BB
ai_pc_55af:
    ai_hop_e0 $0008, $0005, $0000
ai_pc_55b3:
    ai_apply_selected_actor_effect_61
ai_pc_55b4:
    ai_hop_e0 $0001, $0002, $0000
ai_pc_55b8:
    ai_jmp_01_long $55B8, $5604
ai_pc_55bb:
    ai_if_field_gt_30_short $0080, $0048, $0003, $55BB, $55CB
ai_pc_55c0:
    ai_hop_e0 $0004, $0005, $0000
ai_pc_55c4:
    ai_apply_selected_actor_effect_61
ai_pc_55c5:
    ai_hop_e0 $0001, $0002, $0000
ai_pc_55c9:
    ai_jmp_01_short $55C9, $5604
ai_pc_55cb:
    ai_if_field_gt_30_short $0080, $0048, $0004, $55CB, $55DB
ai_pc_55d0:
    ai_hop_e0 $0001, $0005, $0000
ai_pc_55d4:
    ai_apply_selected_actor_effect_61
ai_pc_55d5:
    ai_hop_e0 $0001, $0002, $0000
ai_pc_55d9:
    ai_jmp_01_short $55D9, $5604
ai_pc_55db:
    ai_if_field_gt_30_short $0080, $0048, $0005, $55DB, $55EB
ai_pc_55e0:
    ai_hop_e0 $0008, $0006, $0000
ai_pc_55e4:
    ai_apply_selected_actor_effect_61
ai_pc_55e5:
    ai_hop_e0 $0001, $0002, $0000
ai_pc_55e9:
    ai_jmp_01_short $55E9, $5604
ai_pc_55eb:
    ai_if_field_gt_30_short $0080, $0048, $0006, $55EB, $55FB
ai_pc_55f0:
    ai_hop_e0 $0004, $0006, $0000
ai_pc_55f4:
    ai_apply_selected_actor_effect_61
ai_pc_55f5:
    ai_hop_e0 $0001, $0002, $0000
ai_pc_55f9:
    ai_jmp_01_short $55F9, $5604
ai_pc_55fb:
    ai_if_field_gt_30_short $0080, $0048, $0007, $55FB, $5604
ai_pc_5600:
    ai_apply_selected_actor_effect_61
ai_pc_5601:
    ai_cmd81_ef $0005, $002D
ai_pc_5604:
    ai_ret_00
