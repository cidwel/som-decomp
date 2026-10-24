.setcpu "65816"
.segment "CODE"
.org $B42B
.include "ai_command_macros.inc"
ai_pc_6516:
    ai_rnd_var1_2a $0003
ai_pc_6518:
    ai_ret_00
ai_pc_6519:
    ai_rnd_var3_2c $000F
ai_pc_651b:
    ai_if_var3_nz_05_short $651B, $653D
ai_pc_651d:
    ai_if_var1_nz_03_short $651D, $6525
ai_pc_651f:
    ai_hop_e0 $0008, $0000, $003C
ai_pc_6523:
    ai_jmp_01_short $6523, $653B
ai_pc_6525:
    ai_if_var1_ne_0b_short $0001, $6525, $652E
ai_pc_6528:
    ai_hop_e0 $0004, $0000, $003C
ai_pc_652c:
    ai_jmp_01_short $652C, $653B
ai_pc_652e:
    ai_if_var1_ne_0b_short $0002, $652E, $6537
ai_pc_6531:
    ai_hop_e0 $0001, $0000, $003C
ai_pc_6535:
    ai_jmp_01_short $6535, $653B
ai_pc_6537:
    ai_hop_e0 $0002, $0000, $003C
ai_pc_653b:
    ai_jmp_01_short $653B, $6559
ai_pc_653d:
    ai_rnd_var0_29 $0003
ai_pc_653f:
    ai_if_var0_nz_02_short $653F, $6546
ai_pc_6541:
    ai_call_ff $655A
ai_pc_6544:
    ai_jmp_01_short $6544, $6559
ai_pc_6546:
    ai_if_var0_ne_0a_short $0001, $6546, $654E
ai_pc_6549:
    ai_call_ff $6576
ai_pc_654c:
    ai_jmp_01_short $654C, $6559
ai_pc_654e:
    ai_if_var0_ne_0a_short $0002, $654E, $6556
ai_pc_6551:
    ai_call_ff $6592
ai_pc_6554:
    ai_jmp_01_short $6554, $6559
ai_pc_6556:
    ai_call_ff $65AE
ai_pc_6559:
    ai_ret_00
ai_pc_655a:
    ai_set_var1_26 $0000
ai_pc_655c:
    ai_set_var2_27 $0006
ai_pc_655e:
    ai_if_var2_z_08_short $655E, $6575
ai_pc_6560:
    ai_if_pos_same_9d_short $6560, $6569
ai_pc_6562:
    ai_pos_save_9f
ai_pc_6563:
    ai_hop_e0 $0008, $0001, $000A
ai_pc_6567:
    ai_jmp_01_short $6567, $6572
ai_pc_6569:
    ai_hop_e0 $0008, $0001, $000A
ai_pc_656d:
    ai_set_var2_27 $0000
ai_pc_656f:
    ai_jmp_01_long $656F, $6575
ai_pc_6572:
    ai_dec_var2_20
ai_pc_6573:
    ai_jmp_01_short $6573, $655E
ai_pc_6575:
    ai_ret_00
ai_pc_6576:
    ai_set_var1_26 $0001
ai_pc_6578:
    ai_set_var2_27 $0006
ai_pc_657a:
    ai_if_var2_z_08_short $657A, $6591
ai_pc_657c:
    ai_if_pos_same_9d_short $657C, $6585
ai_pc_657e:
    ai_pos_save_9f
ai_pc_657f:
    ai_hop_e0 $0004, $0001, $000A
ai_pc_6583:
    ai_jmp_01_short $6583, $658E
ai_pc_6585:
    ai_hop_e0 $0004, $0001, $000A
ai_pc_6589:
    ai_set_var2_27 $0000
ai_pc_658b:
    ai_jmp_01_long $658B, $6591
ai_pc_658e:
    ai_dec_var2_20
ai_pc_658f:
    ai_jmp_01_short $658F, $657A
ai_pc_6591:
    ai_ret_00
ai_pc_6592:
    ai_set_var1_26 $0002
ai_pc_6594:
    ai_set_var2_27 $0006
ai_pc_6596:
    ai_if_var2_z_08_short $6596, $65AD
ai_pc_6598:
    ai_if_pos_same_9d_short $6598, $65A1
ai_pc_659a:
    ai_pos_save_9f
ai_pc_659b:
    ai_hop_e0 $0001, $0001, $000A
ai_pc_659f:
    ai_jmp_01_short $659F, $65AA
ai_pc_65a1:
    ai_hop_e0 $0001, $0001, $000A
ai_pc_65a5:
    ai_set_var2_27 $0000
ai_pc_65a7:
    ai_jmp_01_long $65A7, $65AD
ai_pc_65aa:
    ai_dec_var2_20
ai_pc_65ab:
    ai_jmp_01_short $65AB, $6596
ai_pc_65ad:
    ai_ret_00
ai_pc_65ae:
    ai_set_var1_26 $0003
ai_pc_65b0:
    ai_set_var2_27 $0006
ai_pc_65b2:
    ai_if_var2_z_08_short $65B2, $65C9
ai_pc_65b4:
    ai_if_pos_same_9d_short $65B4, $65BD
ai_pc_65b6:
    ai_pos_save_9f
ai_pc_65b7:
    ai_hop_e0 $0002, $0001, $000A
ai_pc_65bb:
    ai_jmp_01_short $65BB, $65C6
ai_pc_65bd:
    ai_hop_e0 $0002, $0001, $000A
ai_pc_65c1:
    ai_set_var2_27 $0000
ai_pc_65c3:
    ai_jmp_01_long $65C3, $65C9
ai_pc_65c6:
    ai_dec_var2_20
ai_pc_65c7:
    ai_jmp_01_short $65C7, $65B2
ai_pc_65c9:
    ai_ret_00
ai_pc_65ca:
    ai_rnd_var3_2c $0002
ai_pc_65cc:
    ai_if_var3_nz_05_short $65CC, $65EB
ai_pc_65ce:
    ai_rnd_var3_2c $0007
ai_pc_65d0:
    ai_if_var3_nz_05_short $65D0, $65D7
ai_pc_65d2:
    ai_call_ff $6627
ai_pc_65d5:
    ai_jmp_01_short $65D5, $65E9
ai_pc_65d7:
    ai_rnd_var3_2c $0004
ai_pc_65d9:
    ai_if_var3_nz_05_short $65D9, $65E6
ai_pc_65db:
    ai_turn_facing_e3 $0000, $0000
ai_pc_65de:
    ai_turn_facing_e3 $0000, $0000
ai_pc_65e1:
    ai_turn_facing_e3 $0000, $0000
ai_pc_65e4:
    ai_jmp_01_short $65E4, $65E9
ai_pc_65e6:
    ai_call_ff $6653
ai_pc_65e9:
    ai_jmp_01_short $65E9, $6626
ai_pc_65eb:
    ai_if_var3_ne_0d_short $0001, $65EB, $660B
ai_pc_65ee:
    ai_rnd_var3_2c $0007
ai_pc_65f0:
    ai_if_var3_nz_05_short $65F0, $65F7
ai_pc_65f2:
    ai_call_ff $667F
ai_pc_65f5:
    ai_jmp_01_short $65F5, $6609
ai_pc_65f7:
    ai_rnd_var3_2c $0004
ai_pc_65f9:
    ai_if_var3_nz_05_short $65F9, $6606
ai_pc_65fb:
    ai_turn_facing_e3 $0000, $0000
ai_pc_65fe:
    ai_turn_facing_e3 $0000, $0000
ai_pc_6601:
    ai_turn_facing_e3 $0000, $0000
ai_pc_6604:
    ai_jmp_01_short $6604, $6609
ai_pc_6606:
    ai_call_ff $66AB
ai_pc_6609:
    ai_jmp_01_short $6609, $6626
ai_pc_660b:
    ai_rnd_var3_2c $0007
ai_pc_660d:
    ai_if_var3_nz_05_short $660D, $6614
ai_pc_660f:
    ai_call_ff $66D7
ai_pc_6612:
    ai_jmp_01_short $6612, $6626
ai_pc_6614:
    ai_rnd_var3_2c $0004
ai_pc_6616:
    ai_if_var3_nz_05_short $6616, $6623
ai_pc_6618:
    ai_turn_facing_e3 $0000, $0000
ai_pc_661b:
    ai_turn_facing_e3 $0000, $0000
ai_pc_661e:
    ai_turn_facing_e3 $0000, $0000
ai_pc_6621:
    ai_jmp_01_short $6621, $6626
ai_pc_6623:
    ai_call_ff $6703
ai_pc_6626:
    ai_ret_00
ai_pc_6627:
    ai_rnd_var3_2c $0003
ai_pc_6629:
    ai_set_var2_27 $0004
ai_pc_662b:
    ai_pos_save_9f
ai_pc_662c:
    ai_if_var3_nz_05_short $662C, $6634
ai_pc_662e:
    ai_hop_e0 $0009, $0004, $000A
ai_pc_6632:
    ai_jmp_01_short $6632, $664A
ai_pc_6634:
    ai_if_var3_ne_0d_short $0001, $6634, $663D
ai_pc_6637:
    ai_hop_e0 $000A, $0004, $000A
ai_pc_663b:
    ai_jmp_01_short $663B, $664A
ai_pc_663d:
    ai_if_var3_ne_0d_short $0002, $663D, $6646
ai_pc_6640:
    ai_hop_e0 $0005, $0004, $000A
ai_pc_6644:
    ai_jmp_01_short $6644, $664A
ai_pc_6646:
    ai_hop_e0 $0006, $0004, $000A
ai_pc_664a:
    ai_if_pos_moved_9e_short $664A, $664F
ai_pc_664c:
    ai_jmp_01_long $664C, $6652
ai_pc_664f:
    ai_dec_var2_20
ai_pc_6650:
    ai_if_var2_nz_04_short $6650, $662B
ai_pc_6652:
    ai_ret_00
ai_pc_6653:
    ai_rnd_var3_2c $0003
ai_pc_6655:
    ai_set_var2_27 $0004
ai_pc_6657:
    ai_pos_save_9f
ai_pc_6658:
    ai_if_var3_nz_05_short $6658, $6660
ai_pc_665a:
    ai_hop_e0 $0008, $0004, $000A
ai_pc_665e:
    ai_jmp_01_short $665E, $6676
ai_pc_6660:
    ai_if_var3_ne_0d_short $0001, $6660, $6669
ai_pc_6663:
    ai_hop_e0 $0004, $0004, $000A
ai_pc_6667:
    ai_jmp_01_short $6667, $6676
ai_pc_6669:
    ai_if_var3_ne_0d_short $0002, $6669, $6672
ai_pc_666c:
    ai_hop_e0 $0001, $0004, $000A
ai_pc_6670:
    ai_jmp_01_short $6670, $6676
ai_pc_6672:
    ai_hop_e0 $0002, $0004, $000A
ai_pc_6676:
    ai_if_pos_moved_9e_short $6676, $667B
ai_pc_6678:
    ai_jmp_01_long $6678, $667E
ai_pc_667b:
    ai_dec_var2_20
ai_pc_667c:
    ai_if_var2_nz_04_short $667C, $6657
ai_pc_667e:
    ai_ret_00
ai_pc_667f:
    ai_rnd_var3_2c $0003
ai_pc_6681:
    ai_set_var2_27 $0004
ai_pc_6683:
    ai_pos_save_9f
ai_pc_6684:
    ai_if_var3_nz_05_short $6684, $668C
ai_pc_6686:
    ai_hop_e0 $0009, $0001, $0005
ai_pc_668a:
    ai_jmp_01_short $668A, $66A2
ai_pc_668c:
    ai_if_var3_ne_0d_short $0001, $668C, $6695
ai_pc_668f:
    ai_hop_e0 $000A, $0001, $0005
ai_pc_6693:
    ai_jmp_01_short $6693, $66A2
ai_pc_6695:
    ai_if_var3_ne_0d_short $0002, $6695, $669E
ai_pc_6698:
    ai_hop_e0 $0005, $0001, $0005
ai_pc_669c:
    ai_jmp_01_short $669C, $66A2
ai_pc_669e:
    ai_hop_e0 $0006, $0001, $0005
ai_pc_66a2:
    ai_if_pos_moved_9e_short $66A2, $66A7
ai_pc_66a4:
    ai_jmp_01_long $66A4, $66AA
ai_pc_66a7:
    ai_dec_var2_20
ai_pc_66a8:
    ai_if_var2_nz_04_short $66A8, $6683
ai_pc_66aa:
    ai_ret_00
ai_pc_66ab:
    ai_rnd_var3_2c $0003
ai_pc_66ad:
    ai_set_var2_27 $0004
ai_pc_66af:
    ai_pos_save_9f
ai_pc_66b0:
    ai_if_var3_nz_05_short $66B0, $66B8
ai_pc_66b2:
    ai_hop_e0 $0008, $0001, $0005
ai_pc_66b6:
    ai_jmp_01_short $66B6, $66CE
ai_pc_66b8:
    ai_if_var3_ne_0d_short $0001, $66B8, $66C1
ai_pc_66bb:
    ai_hop_e0 $0004, $0001, $0005
ai_pc_66bf:
    ai_jmp_01_short $66BF, $66CE
ai_pc_66c1:
    ai_if_var3_ne_0d_short $0002, $66C1, $66CA
ai_pc_66c4:
    ai_hop_e0 $0001, $0001, $0005
ai_pc_66c8:
    ai_jmp_01_short $66C8, $66CE
ai_pc_66ca:
    ai_hop_e0 $0002, $0001, $0005
ai_pc_66ce:
    ai_if_pos_moved_9e_short $66CE, $66D3
ai_pc_66d0:
    ai_jmp_01_long $66D0, $66D6
ai_pc_66d3:
    ai_dec_var2_20
ai_pc_66d4:
    ai_if_var2_nz_04_short $66D4, $66AF
ai_pc_66d6:
    ai_ret_00
ai_pc_66d7:
    ai_rnd_var3_2c $0003
ai_pc_66d9:
    ai_set_var2_27 $0004
ai_pc_66db:
    ai_pos_save_9f
ai_pc_66dc:
    ai_if_var3_nz_05_short $66DC, $66E4
ai_pc_66de:
    ai_hop_e0 $0009, $0002, $0005
ai_pc_66e2:
    ai_jmp_01_short $66E2, $66FA
ai_pc_66e4:
    ai_if_var3_ne_0d_short $0001, $66E4, $66ED
ai_pc_66e7:
    ai_hop_e0 $000A, $0002, $0005
ai_pc_66eb:
    ai_jmp_01_short $66EB, $66FA
ai_pc_66ed:
    ai_if_var3_ne_0d_short $0002, $66ED, $66F6
ai_pc_66f0:
    ai_hop_e0 $0005, $0002, $0005
ai_pc_66f4:
    ai_jmp_01_short $66F4, $66FA
ai_pc_66f6:
    ai_hop_e0 $0006, $0002, $0005
ai_pc_66fa:
    ai_if_pos_moved_9e_short $66FA, $66FF
ai_pc_66fc:
    ai_jmp_01_long $66FC, $6702
ai_pc_66ff:
    ai_dec_var2_20
ai_pc_6700:
    ai_if_var2_nz_04_short $6700, $66DB
ai_pc_6702:
    ai_ret_00
ai_pc_6703:
    ai_rnd_var3_2c $0003
ai_pc_6705:
    ai_set_var2_27 $0004
ai_pc_6707:
    ai_pos_save_9f
ai_pc_6708:
    ai_if_var3_nz_05_short $6708, $6710
ai_pc_670a:
    ai_hop_e0 $0008, $0002, $0005
ai_pc_670e:
    ai_jmp_01_short $670E, $6726
ai_pc_6710:
    ai_if_var3_ne_0d_short $0001, $6710, $6719
ai_pc_6713:
    ai_hop_e0 $0004, $0002, $0005
ai_pc_6717:
    ai_jmp_01_short $6717, $6726
ai_pc_6719:
    ai_if_var3_ne_0d_short $0002, $6719, $6722
ai_pc_671c:
    ai_hop_e0 $0001, $0002, $0005
ai_pc_6720:
    ai_jmp_01_short $6720, $6726
ai_pc_6722:
    ai_hop_e0 $0002, $0002, $0005
ai_pc_6726:
    ai_if_pos_moved_9e_short $6726, $672B
ai_pc_6728:
    ai_jmp_01_long $6728, $672E
ai_pc_672b:
    ai_dec_var2_20
ai_pc_672c:
    ai_if_var2_nz_04_short $672C, $6707
ai_pc_672e:
    ai_ret_00
ai_pc_672f:
    ai_rnd_var3_2c $0003
ai_pc_6731:
    ai_set_var2_27 $0004
ai_pc_6733:
    ai_pos_save_9f
ai_pc_6734:
    ai_if_var3_nz_05_short $6734, $673C
ai_pc_6736:
    ai_hop_e0 $0009, $0004, $000A
ai_pc_673a:
    ai_jmp_01_short $673A, $6752
ai_pc_673c:
    ai_if_var3_ne_0d_short $0001, $673C, $6745
ai_pc_673f:
    ai_hop_e0 $000A, $0004, $000A
ai_pc_6743:
    ai_jmp_01_short $6743, $6752
ai_pc_6745:
    ai_if_var3_ne_0d_short $0002, $6745, $674E
ai_pc_6748:
    ai_hop_e0 $0005, $0004, $000A
ai_pc_674c:
    ai_jmp_01_short $674C, $6752
ai_pc_674e:
    ai_hop_e0 $0006, $0004, $000A
ai_pc_6752:
    ai_if_pos_moved_9e_short $6752, $6757
ai_pc_6754:
    ai_jmp_01_long $6754, $675A
ai_pc_6757:
    ai_dec_var2_20
ai_pc_6758:
    ai_if_var2_nz_04_short $6758, $6733
ai_pc_675a:
    ai_ret_00
ai_pc_675b:
    ai_rnd_var3_2c $0003
ai_pc_675d:
    ai_set_var2_27 $0004
ai_pc_675f:
    ai_pos_save_9f
ai_pc_6760:
    ai_if_var3_nz_05_short $6760, $6768
ai_pc_6762:
    ai_hop_e0 $0008, $0004, $000A
ai_pc_6766:
    ai_jmp_01_short $6766, $677E
ai_pc_6768:
    ai_if_var3_ne_0d_short $0001, $6768, $6771
ai_pc_676b:
    ai_hop_e0 $0004, $0004, $000A
ai_pc_676f:
    ai_jmp_01_short $676F, $677E
ai_pc_6771:
    ai_if_var3_ne_0d_short $0002, $6771, $677A
ai_pc_6774:
    ai_hop_e0 $0001, $0004, $000A
ai_pc_6778:
    ai_jmp_01_short $6778, $677E
ai_pc_677a:
    ai_hop_e0 $0002, $0004, $000A
ai_pc_677e:
    ai_if_pos_moved_9e_short $677E, $6783
ai_pc_6780:
    ai_jmp_01_long $6780, $6786
ai_pc_6783:
    ai_dec_var2_20
ai_pc_6784:
    ai_if_var2_nz_04_short $6784, $675F
ai_pc_6786:
    ai_ret_00
