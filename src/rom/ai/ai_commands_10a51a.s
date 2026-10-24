.setcpu "65816"
.segment "CODE"
.org $A51A
.include "ai_command_macros.inc"
ai_pc_5605:
    ai_call_ff $5641
ai_pc_5608:
    ai_if_word_lt_bc_short $0080, $0002, $0001, $0000, $5608, $5640
ai_pc_560e:
    ai_call_ff $6AE1
ai_pc_5611:
    ai_if_field_gt_30_short $0080, $002C, $00FE, $5611, $5638
ai_pc_5616:
    ai_call_ff $57E7
ai_pc_5619:
    ai_call_ff $5820
ai_pc_561c:
    ai_call_ff $6AE1
ai_pc_561f:
    ai_if_field_gt_30_short $0080, $0067, $0020, $561F, $5629
ai_pc_5624:
    ai_call_ff $5681
ai_pc_5627:
    ai_jmp_01_short $5627, $5636
ai_pc_5629:
    ai_if_field_gt_30_short $0080, $0067, $002E, $5629, $5633
ai_pc_562e:
    ai_call_ff $56B4
ai_pc_5631:
    ai_jmp_01_short $5631, $5636
ai_pc_5633:
    ai_call_ff $56D8
ai_pc_5636:
    ai_jmp_01_short $5636, $5611
ai_pc_5638:
    ai_call_ff $57E7
ai_pc_563b:
    ai_call_ff $5820
ai_pc_563e:
    ai_jmp_01_short $563E, $5608
ai_pc_5640:
    ai_ret_00
ai_pc_5641:
    ai_turn_facing_e3 $0000, $0005
ai_pc_5644:
    ai_field_set_dc $0080, $002A, $00FC
ai_pc_5648:
    ai_field_set_dc $0080, $002B, $007F
ai_pc_564c:
    ai_set_var0_25 $0000
ai_pc_564e:
    ai_call_ff $6AE1
ai_pc_5651:
    ai_if_var0_nz_02_short $5651, $5659
ai_pc_5653:
    ai_call_ff $595E
ai_pc_5656:
    ai_inc_var0_1a
ai_pc_5657:
    ai_jmp_01_short $5657, $5670
ai_pc_5659:
    ai_if_var0_ne_0a_short $0001, $5659, $5662
ai_pc_565c:
    ai_call_ff $596B
ai_pc_565f:
    ai_inc_var0_1a
ai_pc_5660:
    ai_jmp_01_short $5660, $5670
ai_pc_5662:
    ai_if_var0_ne_0a_short $0002, $5662, $566B
ai_pc_5665:
    ai_call_ff $596B
ai_pc_5668:
    ai_inc_var0_1a
ai_pc_5669:
    ai_jmp_01_short $5669, $5670
ai_pc_566b:
    ai_call_ff $595E
ai_pc_566e:
    ai_set_var0_25 $0000
ai_pc_5670:
    ai_if_tgt_not_within_64_56_short $5670, $564E
ai_pc_5672:
    ai_move_toward_e4 $0003, $000F
ai_pc_5675:
    ai_call_ff $6AE1
ai_pc_5678:
    ai_move_toward_e4 $0000, $0005
ai_pc_567b:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_567f:
    ai_swing_e8
ai_pc_5680:
    ai_ret_00
ai_pc_5681:
    ai_if_field_gt_30_short $0080, $002C, $00FE, $5681, $56B3
ai_pc_5686:
    ai_call_ff $6AE1
ai_pc_5689:
    ai_call_ff $57E7
ai_pc_568c:
    ai_call_ff $5812
ai_pc_568f:
    ai_if_field_gt_30_short $0080, $006D, $0000, $568F, $56AE
ai_pc_5694:
    ai_rnd_var3_2c $000F
ai_pc_5696:
    ai_call_ff $56FC
ai_pc_5699:
    ai_if_tgt_not_lane_v64_66_short $5699, $56A1
ai_pc_569b:
    ai_move_toward_card_be $0003, $0005
ai_pc_569e:
    ai_swing_e8
ai_pc_569f:
    ai_jmp_01_short $569F, $56AC
ai_pc_56a1:
    ai_if_tgt_not_lane_h64_6f_short $56A1, $56A9
ai_pc_56a3:
    ai_move_toward_card_be $0003, $0005
ai_pc_56a6:
    ai_swing_e8
ai_pc_56a7:
    ai_jmp_01_short $56A7, $56AC
ai_pc_56a9:
    ai_call_ff $593D
ai_pc_56ac:
    ai_jmp_01_short $56AC, $56B1
ai_pc_56ae:
    ai_call_ff $571A
ai_pc_56b1:
    ai_jmp_01_short $56B1, $5681
ai_pc_56b3:
    ai_ret_00
ai_pc_56b4:
    ai_if_field_gt_30_short $0080, $002C, $00FE, $56B4, $56D7
ai_pc_56b9:
    ai_call_ff $6AE1
ai_pc_56bc:
    ai_call_ff $57E7
ai_pc_56bf:
    ai_call_ff $57F6
ai_pc_56c2:
    ai_if_field_gt_30_short $0080, $006D, $0000, $56C2, $56D2
ai_pc_56c7:
    ai_rnd_var3_2c $000F
ai_pc_56c9:
    ai_call_ff $573F
ai_pc_56cc:
    ai_move_toward_e4 $0003, $0005
ai_pc_56cf:
    ai_swing_e8
ai_pc_56d0:
    ai_jmp_01_short $56D0, $56D5
ai_pc_56d2:
    ai_call_ff $5769
ai_pc_56d5:
    ai_jmp_01_short $56D5, $56B4
ai_pc_56d7:
    ai_ret_00
ai_pc_56d8:
    ai_if_field_gt_30_short $0080, $002C, $00FE, $56D8, $56FB
ai_pc_56dd:
    ai_call_ff $6AE1
ai_pc_56e0:
    ai_call_ff $57E7
ai_pc_56e3:
    ai_call_ff $5804
ai_pc_56e6:
    ai_if_field_gt_30_short $0080, $006D, $0000, $56E6, $56F6
ai_pc_56eb:
    ai_rnd_var3_2c $000F
ai_pc_56ed:
    ai_call_ff $578E
ai_pc_56f0:
    ai_move_toward_e4 $0003, $0005
ai_pc_56f3:
    ai_swing_e8
ai_pc_56f4:
    ai_jmp_01_short $56F4, $56F9
ai_pc_56f6:
    ai_call_ff $57C2
ai_pc_56f9:
    ai_jmp_01_short $56F9, $56D8
ai_pc_56fb:
    ai_ret_00
ai_pc_56fc:
    ai_call_ff $6AE1
ai_pc_56ff:
    ai_call_ff $57E7
ai_pc_5702:
    ai_call_ff $5812
ai_pc_5705:
    ai_if_pos_same_9d_short $5705, $570D
ai_pc_5707:
    ai_pos_save_9f
ai_pc_5708:
    ai_move_toward_card_be $000B, $000A
ai_pc_570b:
    ai_jmp_01_short $570B, $5711
ai_pc_570d:
    ai_pos_save_9f
ai_pc_570e:
    ai_move_toward_alt_fd $000B, $000A
ai_pc_5711:
    ai_if_var3_gt_15_short $000B, $5711, $5717
ai_pc_5714:
    ai_jmp_01_long $5714, $5719
ai_pc_5717:
    ai_if_tgt_not_within_48_51_short $5717, $56FC
ai_pc_5719:
    ai_ret_00
ai_pc_571a:
    ai_if_tgt_not_within_48_51_short $571A, $573E
ai_pc_571c:
    ai_call_ff $6AE1
ai_pc_571f:
    ai_call_ff $57E7
ai_pc_5722:
    ai_call_ff $5812
ai_pc_5725:
    ai_if_tgt_not_within_64_56_short $5725, $5730
ai_pc_5727:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5727, $5730
ai_pc_572c:
    ai_move_toward_card_be $0003, $0005
ai_pc_572f:
    ai_swing_e8
ai_pc_5730:
    ai_if_pos_same_9d_short $5730, $5738
ai_pc_5732:
    ai_pos_save_9f
ai_pc_5733:
    ai_move_toward_card_be $000C, $000A
ai_pc_5736:
    ai_jmp_01_short $5736, $573C
ai_pc_5738:
    ai_pos_save_9f
ai_pc_5739:
    ai_move_toward_alt_fd $000C, $000A
ai_pc_573c:
    ai_jmp_01_short $573C, $571A
ai_pc_573e:
    ai_ret_00
ai_pc_573f:
    ai_call_ff $6AE1
ai_pc_5742:
    ai_call_ff $57E7
ai_pc_5745:
    ai_call_ff $57F6
ai_pc_5748:
    ai_if_pos_same_9d_short $5748, $5750
ai_pc_574a:
    ai_pos_save_9f
ai_pc_574b:
    ai_move_toward_e4 $000B, $000A
ai_pc_574e:
    ai_jmp_01_short $574E, $5754
ai_pc_5750:
    ai_pos_save_9f
ai_pc_5751:
    ai_move_toward_alt_fd $000B, $000A
ai_pc_5754:
    ai_if_var3_gt_15_short $0003, $5754, $575E
ai_pc_5757:
    ai_if_tgt_not_within_64_56_short $5757, $575C
ai_pc_5759:
    ai_jmp_01_long $5759, $5768
ai_pc_575c:
    ai_jmp_01_short $575C, $5766
ai_pc_575e:
    ai_if_var3_gt_15_short $0008, $575E, $5766
ai_pc_5761:
    ai_if_tgt_not_within_48_51_short $5761, $5766
ai_pc_5763:
    ai_jmp_01_long $5763, $5768
ai_pc_5766:
    ai_if_tgt_not_within_32_4c_short $5766, $573F
ai_pc_5768:
    ai_ret_00
ai_pc_5769:
    ai_if_tgt_not_within_48_51_short $5769, $578D
ai_pc_576b:
    ai_call_ff $6AE1
ai_pc_576e:
    ai_call_ff $57E7
ai_pc_5771:
    ai_call_ff $57F6
ai_pc_5774:
    ai_if_tgt_not_within_48_51_short $5774, $577F
ai_pc_5776:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5776, $577F
ai_pc_577b:
    ai_move_toward_e4 $0003, $0005
ai_pc_577e:
    ai_swing_e8
ai_pc_577f:
    ai_if_pos_same_9d_short $577F, $5787
ai_pc_5781:
    ai_pos_save_9f
ai_pc_5782:
    ai_move_toward_card_be $000C, $000A
ai_pc_5785:
    ai_jmp_01_short $5785, $578B
ai_pc_5787:
    ai_pos_save_9f
ai_pc_5788:
    ai_move_toward_alt_fd $000C, $000A
ai_pc_578b:
    ai_jmp_01_short $578B, $5769
ai_pc_578d:
    ai_ret_00
ai_pc_578e:
    ai_call_ff $6AE1
ai_pc_5791:
    ai_call_ff $57E7
ai_pc_5794:
    ai_call_ff $5804
ai_pc_5797:
    ai_if_pos_same_9d_short $5797, $579F
ai_pc_5799:
    ai_pos_save_9f
ai_pc_579a:
    ai_move_toward_e4 $000B, $000A
ai_pc_579d:
    ai_jmp_01_short $579D, $57A3
ai_pc_579f:
    ai_pos_save_9f
ai_pc_57a0:
    ai_move_toward_alt_fd $000B, $000A
ai_pc_57a3:
    ai_if_var3_gt_15_short $0003, $57A3, $57AD
ai_pc_57a6:
    ai_if_tgt_not_within_64_56_short $57A6, $57AB
ai_pc_57a8:
    ai_jmp_01_long $57A8, $57C1
ai_pc_57ab:
    ai_jmp_01_short $57AB, $57BF
ai_pc_57ad:
    ai_if_var3_gt_15_short $0007, $57AD, $57B7
ai_pc_57b0:
    ai_if_tgt_not_within_48_51_short $57B0, $57B5
ai_pc_57b2:
    ai_jmp_01_long $57B2, $57C1
ai_pc_57b5:
    ai_jmp_01_short $57B5, $57BF
ai_pc_57b7:
    ai_if_var3_gt_15_short $000B, $57B7, $57BF
ai_pc_57ba:
    ai_if_tgt_not_within_32_4c_short $57BA, $57BF
ai_pc_57bc:
    ai_jmp_01_long $57BC, $57C1
ai_pc_57bf:
    ai_if_tgt_not_within_16_34_short $57BF, $578E
ai_pc_57c1:
    ai_ret_00
ai_pc_57c2:
    ai_if_tgt_not_within_48_51_short $57C2, $57E6
ai_pc_57c4:
    ai_call_ff $6AE1
ai_pc_57c7:
    ai_call_ff $57E7
ai_pc_57ca:
    ai_call_ff $5804
ai_pc_57cd:
    ai_if_tgt_not_within_32_4c_short $57CD, $57D8
ai_pc_57cf:
    ai_if_field_gt_30_short $0080, $006D, $0000, $57CF, $57D8
ai_pc_57d4:
    ai_move_toward_e4 $0003, $0005
ai_pc_57d7:
    ai_swing_e8
ai_pc_57d8:
    ai_if_pos_same_9d_short $57D8, $57E0
ai_pc_57da:
    ai_pos_save_9f
ai_pc_57db:
    ai_move_toward_card_be $000C, $000A
ai_pc_57de:
    ai_jmp_01_short $57DE, $57E4
ai_pc_57e0:
    ai_pos_save_9f
ai_pc_57e1:
    ai_move_toward_alt_fd $000C, $000A
ai_pc_57e4:
    ai_jmp_01_short $57E4, $57C2
ai_pc_57e6:
    ai_ret_00
ai_pc_57e7:
    ai_if_word_gt_bd_short $0080, $0002, $0000, $0000, $57E7, $57F5
ai_pc_57ed:
    ai_field_set_dc $0080, $0011, $0080
ai_pc_57f1:
    ai_turn_facing_e3 $0031, $0000
ai_pc_57f4:
    ai_cmd04_ee
ai_pc_57f5:
    ai_ret_00
ai_pc_57f6:
    ai_if_field_and_z_2e_short $0000, $0011, $0080, $57F6, $5803
ai_pc_57fb:
    ai_field_set_dc $0080, $0011, $0080
ai_pc_57ff:
    ai_turn_facing_e3 $0031, $0000
ai_pc_5802:
    ai_cmd04_ee
ai_pc_5803:
    ai_ret_00
ai_pc_5804:
    ai_if_field_and_z_2e_short $0001, $0011, $0080, $5804, $5811
ai_pc_5809:
    ai_field_set_dc $0080, $0011, $0080
ai_pc_580d:
    ai_turn_facing_e3 $0031, $0000
ai_pc_5810:
    ai_cmd04_ee
ai_pc_5811:
    ai_ret_00
ai_pc_5812:
    ai_if_field_and_z_2e_short $0002, $0011, $0080, $5812, $581F
ai_pc_5817:
    ai_field_set_dc $0080, $0011, $0080
ai_pc_581b:
    ai_turn_facing_e3 $0031, $0000
ai_pc_581e:
    ai_cmd04_ee
ai_pc_581f:
    ai_ret_00
ai_pc_5820:
    ai_if_field_gt_30_short $0080, $0067, $0020, $5820, $5835
ai_pc_5825:
    ai_if_word_gt_bd_short $0002, $0002, $0000, $0000, $5825, $5833
ai_pc_582b:
    ai_field_set_dc $0080, $0011, $0080
ai_pc_582f:
    ai_turn_facing_e3 $0031, $0000
ai_pc_5832:
    ai_cmd04_ee
ai_pc_5833:
    ai_jmp_01_short $5833, $585D
ai_pc_5835:
    ai_if_field_gt_30_short $0080, $0067, $002E, $5835, $584A
ai_pc_583a:
    ai_if_word_gt_bd_short $0000, $0002, $0000, $0000, $583A, $5848
ai_pc_5840:
    ai_field_set_dc $0080, $0011, $0080
ai_pc_5844:
    ai_turn_facing_e3 $0031, $0000
ai_pc_5847:
    ai_cmd04_ee
ai_pc_5848:
    ai_jmp_01_short $5848, $585D
ai_pc_584a:
    ai_if_field_gt_30_short $0080, $0067, $003F, $584A, $585D
ai_pc_584f:
    ai_if_word_gt_bd_short $0001, $0002, $0000, $0000, $584F, $585D
ai_pc_5855:
    ai_field_set_dc $0080, $0011, $0080
ai_pc_5859:
    ai_turn_facing_e3 $0031, $0000
ai_pc_585c:
    ai_cmd04_ee
ai_pc_585d:
    ai_ret_00
