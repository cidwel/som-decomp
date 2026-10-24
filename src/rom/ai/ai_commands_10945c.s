.setcpu "65816"
.segment "CODE"
.org $945C
.include "ai_command_macros.inc"
ai_pc_4547:
    ai_pose_e2 $0000
ai_pc_4549:
    ai_rnd_var3_2c $0001
ai_pc_454b:
    ai_if_var3_nz_05_short $454B, $4553
ai_pc_454d:
    ai_pose_e2 $0002
ai_pc_454f:
    ai_pose_e2 $0002
ai_pc_4551:
    ai_jmp_01_short $4551, $4557
ai_pc_4553:
    ai_pose_e2 $0004
ai_pc_4555:
    ai_pose_e2 $0004
ai_pc_4557:
    ai_tgt2_self_c4
ai_pc_4558:
    ai_cast_e9 $0003, $0022
ai_pc_455b:
    ai_tgt2_none_c0
ai_pc_455c:
    ai_ret_00
ai_pc_455d:
    ai_if_tgt_not_within_32_4c_short $455D, $4564
ai_pc_455f:
    ai_call_ff $4576
ai_pc_4562:
    ai_jmp_01_short $4562, $4575
ai_pc_4564:
    ai_if_tgt_not_within_48_51_short $4564, $456B
ai_pc_4566:
    ai_call_ff $45A1
ai_pc_4569:
    ai_jmp_01_short $4569, $4575
ai_pc_456b:
    ai_if_tgt_not_within_64_56_short $456B, $4572
ai_pc_456d:
    ai_call_ff $45CC
ai_pc_4570:
    ai_jmp_01_short $4570, $4575
ai_pc_4572:
    ai_call_ff $4648
ai_pc_4575:
    ai_ret_00
ai_pc_4576:
    ai_move_toward_card_be $0000, $0005
ai_pc_4579:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4579, $459D
ai_pc_457e:
    ai_if_tgt_not_lane_v64_66_short $457E, $4588
ai_pc_4580:
    ai_move_toward_card_be $0000, $0005
ai_pc_4583:
    ai_call_ff $6B23
ai_pc_4586:
    ai_jmp_01_short $4586, $459D
ai_pc_4588:
    ai_if_tgt_not_lane_h64_6f_short $4588, $4592
ai_pc_458a:
    ai_move_toward_card_be $0000, $0005
ai_pc_458d:
    ai_call_ff $6B23
ai_pc_4590:
    ai_jmp_01_short $4590, $459D
ai_pc_4592:
    ai_move_toward_card_be $0000, $0005
ai_pc_4595:
    ai_if_obj_outside_5f_short $0080, $4595, $459D
ai_pc_4598:
    ai_tgt2_cur_c1
ai_pc_4599:
    ai_cast_e9 $0003, $0000
ai_pc_459c:
    ai_tgt2_none_c0
ai_pc_459d:
    ai_call_ff $46C1
ai_pc_45a0:
    ai_ret_00
ai_pc_45a1:
    ai_move_toward_card_be $0000, $0005
ai_pc_45a4:
    ai_if_field_gt_30_short $0080, $006D, $0000, $45A4, $45C8
ai_pc_45a9:
    ai_if_tgt_not_lane_v64_66_short $45A9, $45B3
ai_pc_45ab:
    ai_move_toward_card_be $0000, $0005
ai_pc_45ae:
    ai_call_ff $6B23
ai_pc_45b1:
    ai_jmp_01_short $45B1, $45C8
ai_pc_45b3:
    ai_if_tgt_not_lane_h64_6f_short $45B3, $45BD
ai_pc_45b5:
    ai_move_toward_card_be $0000, $0005
ai_pc_45b8:
    ai_call_ff $6B23
ai_pc_45bb:
    ai_jmp_01_short $45BB, $45C8
ai_pc_45bd:
    ai_move_toward_card_be $0000, $0005
ai_pc_45c0:
    ai_if_obj_outside_5f_short $0080, $45C0, $45C8
ai_pc_45c3:
    ai_tgt2_cur_c1
ai_pc_45c4:
    ai_cast_e9 $0003, $001E
ai_pc_45c7:
    ai_tgt2_none_c0
ai_pc_45c8:
    ai_call_ff $46C1
ai_pc_45cb:
    ai_ret_00
ai_pc_45cc:
    ai_move_toward_card_be $0000, $0005
ai_pc_45cf:
    ai_if_field_gt_30_long $0080, $006D, $0000, $45CF, $4630
ai_pc_45d5:
    ai_rnd_var3_2c $000F
ai_pc_45d7:
    ai_if_var3_nz_05_short $45D7, $4617
ai_pc_45d9:
    ai_move_toward_card_be $0000, $0005
ai_pc_45dc:
    ai_if_obj_outside_5f_short $0080, $45DC, $4615
ai_pc_45df:
    ai_tgt2_cur_c1
ai_pc_45e0:
    ai_cast_e9 $0003, $001E
ai_pc_45e3:
    ai_tgt2_none_c0
ai_pc_45e4:
    ai_move_toward_card_be $0000, $00B4
ai_pc_45e7:
    ai_if_word_and_z_bb_short $0081, $0010, $0010, $0000, $45E7, $4611
ai_pc_45ed:
    ai_call_ff $46AF
ai_pc_45f0:
    ai_if_tgt_not_lane_v64_66_short $45F0, $45FA
ai_pc_45f2:
    ai_move_toward_card_be $0000, $0005
ai_pc_45f5:
    ai_call_ff $6B23
ai_pc_45f8:
    ai_jmp_01_short $45F8, $460C
ai_pc_45fa:
    ai_if_tgt_not_lane_h64_6f_short $45FA, $4604
ai_pc_45fc:
    ai_move_toward_card_be $0000, $0005
ai_pc_45ff:
    ai_call_ff $6B23
ai_pc_4602:
    ai_jmp_01_short $4602, $460C
ai_pc_4604:
    ai_move_toward_card_be $0000, $0005
ai_pc_4607:
    ai_tgt2_cur_c1
ai_pc_4608:
    ai_cast_e9 $0003, $0000
ai_pc_460b:
    ai_tgt2_none_c0
ai_pc_460c:
    ai_call_ff $46D5
ai_pc_460f:
    ai_jmp_01_short $460F, $4615
ai_pc_4611:
    ai_pose_e2 $0004
ai_pc_4613:
    ai_pose_e2 $0004
ai_pc_4615:
    ai_jmp_01_short $4615, $462E
ai_pc_4617:
    ai_if_var3_nz_05_short $4617, $4621
ai_pc_4619:
    ai_hop_e0 $0002, $000E, $0000
ai_pc_461d:
    ai_hop_e0 $0001, $000E, $0000
ai_pc_4621:
    ai_move_toward_card_be $0000, $0000
ai_pc_4624:
    ai_if_field_gt_30_short $0080, $0038, $0000, $4624, $462E
ai_pc_4629:
    ai_tgt2_self_c4
ai_pc_462a:
    ai_cast_e9 $0003, $0022
ai_pc_462d:
    ai_tgt2_none_c0
ai_pc_462e:
    ai_jmp_01_short $462E, $4647
ai_pc_4630:
    ai_if_var3_nz_05_short $4630, $463A
ai_pc_4632:
    ai_hop_e0 $0002, $000E, $0000
ai_pc_4636:
    ai_hop_e0 $0001, $000E, $0000
ai_pc_463a:
    ai_move_toward_card_be $0000, $0000
ai_pc_463d:
    ai_if_field_gt_30_short $0080, $0038, $0000, $463D, $4647
ai_pc_4642:
    ai_tgt2_self_c4
ai_pc_4643:
    ai_cast_e9 $0003, $0022
ai_pc_4646:
    ai_tgt2_none_c0
ai_pc_4647:
    ai_ret_00
ai_pc_4648:
    ai_set_var2_27 $0004
ai_pc_464a:
    ai_call_ff $6AE1
ai_pc_464d:
    ai_if_pos_same_9d_short $464D, $4655
ai_pc_464f:
    ai_pos_save_9f
ai_pc_4650:
    ai_move_toward_card_be $0004, $000F
ai_pc_4653:
    ai_jmp_01_short $4653, $4659
ai_pc_4655:
    ai_pos_save_9f
ai_pc_4656:
    ai_move_toward_alt_fd $0004, $000F
ai_pc_4659:
    ai_dec_var2_20
ai_pc_465a:
    ai_if_var2_nz_04_short $465A, $465F
ai_pc_465c:
    ai_jmp_01_long $465C, $4661
ai_pc_465f:
    ai_if_tgt_not_within_64_56_short $465F, $464A
ai_pc_4661:
    ai_rnd_var3_2c $0007
ai_pc_4663:
    ai_if_var3_nz_05_short $4663, $466D
ai_pc_4665:
    ai_hop_e0 $0002, $000E, $0000
ai_pc_4669:
    ai_hop_e0 $0001, $000E, $0000
ai_pc_466d:
    ai_move_toward_card_be $0000, $0000
ai_pc_4670:
    ai_ret_00
ai_pc_4671:
    ai_if_tgt_not_within_64_56_short $4671, $46AE
ai_pc_4673:
    ai_call_ff $46D5
ai_pc_4676:
    ai_pose_e2 $0004
ai_pc_4678:
    ai_call_ff $6AE1
ai_pc_467b:
    ai_pose_e2 $0004
ai_pc_467d:
    ai_if_field_gt_30_short $0080, $0038, $0000, $467D, $4687
ai_pc_4682:
    ai_tgt2_self_c4
ai_pc_4683:
    ai_cast_e9 $0003, $0022
ai_pc_4686:
    ai_tgt2_none_c0
ai_pc_4687:
    ai_if_tgt_not_within_32_4c_short $4687, $4678
ai_pc_4689:
    ai_pose_e2 $0002
ai_pc_468b:
    ai_if_field_gt_30_short $0080, $006D, $0000, $468B, $46AC
ai_pc_4690:
    ai_if_tgt_not_lane_v64_66_short $4690, $469A
ai_pc_4692:
    ai_move_toward_card_be $0000, $0005
ai_pc_4695:
    ai_call_ff $6B23
ai_pc_4698:
    ai_jmp_01_short $4698, $46AC
ai_pc_469a:
    ai_if_tgt_not_lane_h64_6f_short $469A, $46A4
ai_pc_469c:
    ai_move_toward_card_be $0000, $0005
ai_pc_469f:
    ai_call_ff $6B23
ai_pc_46a2:
    ai_jmp_01_short $46A2, $46AC
ai_pc_46a4:
    ai_move_toward_card_be $0000, $0005
ai_pc_46a7:
    ai_tgt2_cur_c1
ai_pc_46a8:
    ai_cast_e9 $0003, $001E
ai_pc_46ab:
    ai_tgt2_none_c0
ai_pc_46ac:
    ai_jmp_01_short $46AC, $4671
ai_pc_46ae:
    ai_ret_00
ai_pc_46af:
    ai_call_ff $6AE1
ai_pc_46b2:
    ai_if_pos_same_9d_short $46B2, $46BA
ai_pc_46b4:
    ai_pos_save_9f
ai_pc_46b5:
    ai_move_toward_card_be $0002, $000A
ai_pc_46b8:
    ai_jmp_01_short $46B8, $46BE
ai_pc_46ba:
    ai_pos_save_9f
ai_pc_46bb:
    ai_move_toward_alt_fd $0002, $000A
ai_pc_46be:
    ai_if_tgt_not_within_32_4c_short $46BE, $46AF
ai_pc_46c0:
    ai_ret_00
ai_pc_46c1:
    ai_if_tgt_not_within_48_51_short $46C1, $46D4
ai_pc_46c3:
    ai_call_ff $6AE1
ai_pc_46c6:
    ai_if_pos_same_9d_short $46C6, $46CE
ai_pc_46c8:
    ai_pos_save_9f
ai_pc_46c9:
    ai_move_toward_card_be $0005, $000F
ai_pc_46cc:
    ai_jmp_01_short $46CC, $46D2
ai_pc_46ce:
    ai_pos_save_9f
ai_pc_46cf:
    ai_move_toward_alt_fd $0005, $000F
ai_pc_46d2:
    ai_jmp_01_short $46D2, $46C1
ai_pc_46d4:
    ai_ret_00
ai_pc_46d5:
    ai_if_tgt_not_within_48_51_short $46D5, $46E8
ai_pc_46d7:
    ai_call_ff $6AE1
ai_pc_46da:
    ai_if_pos_same_9d_short $46DA, $46E2
ai_pc_46dc:
    ai_pos_save_9f
ai_pc_46dd:
    ai_move_away_card_bf $0002, $000A
ai_pc_46e0:
    ai_jmp_01_short $46E0, $46E6
ai_pc_46e2:
    ai_pos_save_9f
ai_pc_46e3:
    ai_move_away_alt_fe $0002, $000A
ai_pc_46e6:
    ai_jmp_01_short $46E6, $46D5
ai_pc_46e8:
    ai_ret_00
ai_pc_46e9:
    ai_call_ff $4722
ai_pc_46ec:
    ai_rnd_var3_2c $000F
ai_pc_46ee:
    ai_if_var3_nz_05_short $46EE, $46F5
ai_pc_46f0:
    ai_call_ff $67DF
ai_pc_46f3:
    ai_jmp_01_short $46F3, $471A
ai_pc_46f5:
    ai_call_ff $477F
ai_pc_46f8:
    ai_call_ff $6AE1
ai_pc_46fb:
    ai_if_tgt_not_within_32_4c_short $46FB, $4702
ai_pc_46fd:
    ai_call_ff $472C
ai_pc_4700:
    ai_jmp_01_short $4700, $471A
ai_pc_4702:
    ai_if_tgt_not_within_48_51_short $4702, $4709
ai_pc_4704:
    ai_call_ff $47DC
ai_pc_4707:
    ai_jmp_01_short $4707, $471A
ai_pc_4709:
    ai_if_tgt_not_within_64_56_short $4709, $4710
ai_pc_470b:
    ai_call_ff $4744
ai_pc_470e:
    ai_jmp_01_short $470E, $471A
ai_pc_4710:
    ai_call_ff $47C2
ai_pc_4713:
    ai_rnd_var3_2c $000F
ai_pc_4715:
    ai_if_var3_ne_0d_short $000F, $4715, $471A
ai_pc_4718:
    ai_pose_e2 $0003
ai_pc_471a:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $471A, $46EC
ai_pc_471f:
    ai_jmp_01_short $471F, $46EC
