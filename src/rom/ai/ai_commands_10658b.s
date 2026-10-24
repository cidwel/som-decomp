.setcpu "65816"
.segment "CODE"
.org $658B
.include "ai_command_macros.inc"
ai_pc_1676:
    ai_turn_facing_e3 $0000, $0005
ai_pc_1679:
    ai_if_tgt_not_within_32_4c_short $1679, $168C
ai_pc_167b:
    ai_call_ff $6AE1
ai_pc_167e:
    ai_turn_facing_e3 $0000, $0005
ai_pc_1681:
    ai_if_word_gt_bd_short $0080, $0002, $0086, $0000, $1681, $168A
ai_pc_1687:
    ai_jmp_01_long $1687, $168C
ai_pc_168a:
    ai_jmp_01_short $168A, $1679
ai_pc_168c:
    ai_set_var1_26 $0000
ai_pc_168e:
    ai_pose_e2 $0002
ai_pc_1690:
    ai_pose_e2 $0000
ai_pc_1692:
    ai_ret_00
ai_pc_1693:
    ai_if_var1_lt_17_short $0001, $1693, $16A3
ai_pc_1696:
    ai_move_toward_card_be $0000, $0005
ai_pc_1699:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_169d:
    ai_call_ff $6B0F
ai_pc_16a0:
    ai_dec_var1_1f
ai_pc_16a1:
    ai_jmp_01_short $16A1, $16B4
ai_pc_16a3:
    ai_move_toward_card_be $0000, $0000
ai_pc_16a6:
    ai_if_field_gt_30_short $0080, $006D, $0000, $16A6, $16B1
ai_pc_16ab:
    ai_move_toward_card_be $0000, $0000
ai_pc_16ae:
    ai_call_ff $6B0F
ai_pc_16b1:
    ai_call_ff $178D
ai_pc_16b4:
    ai_ret_00
ai_pc_16b5:
    ai_if_var1_lt_17_short $0001, $16B5, $16D1
ai_pc_16b8:
    ai_move_toward_card_be $0000, $0005
ai_pc_16bb:
    ai_rnd_var3_2c $0001
ai_pc_16bd:
    ai_if_var3_nz_05_short $16BD, $16C4
ai_pc_16bf:
    ai_call_ff $1774
ai_pc_16c2:
    ai_jmp_01_short $16C2, $16CF
ai_pc_16c4:
    ai_move_toward_card_be $0000, $0005
ai_pc_16c7:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_16cb:
    ai_call_ff $6B0F
ai_pc_16ce:
    ai_dec_var1_1f
ai_pc_16cf:
    ai_jmp_01_short $16CF, $16EB
ai_pc_16d1:
    ai_move_toward_card_be $0000, $0000
ai_pc_16d4:
    ai_call_ff $1749
ai_pc_16d7:
    ai_if_field_gt_30_short $0080, $006D, $0000, $16D7, $16EB
ai_pc_16dc:
    ai_rnd_var3_2c $0001
ai_pc_16de:
    ai_if_var3_nz_05_short $16DE, $16E5
ai_pc_16e0:
    ai_call_ff $175B
ai_pc_16e3:
    ai_jmp_01_short $16E3, $16EB
ai_pc_16e5:
    ai_move_toward_card_be $0000, $0000
ai_pc_16e8:
    ai_call_ff $6B0F
ai_pc_16eb:
    ai_ret_00
ai_pc_16ec:
    ai_if_var1_lt_17_short $0001, $16EC, $1701
ai_pc_16ef:
    ai_move_toward_card_be $0000, $0005
ai_pc_16f2:
    ai_move_toward_card_be $0002, $0000
ai_pc_16f5:
    ai_turn_facing_e3 $0000, $000F
ai_pc_16f8:
    ai_if_tgt_not_beyond_64_5a_short $16F8, $16FD
ai_pc_16fa:
    ai_jmp_01_long $16FA, $16FF
ai_pc_16fd:
    ai_if_tgt_not_within_48_51_short $16FD, $16F2
ai_pc_16ff:
    ai_jmp_01_short $16FF, $1711
ai_pc_1701:
    ai_move_toward_card_be $0000, $0000
ai_pc_1704:
    ai_move_toward_card_be $0004, $0000
ai_pc_1707:
    ai_turn_facing_e3 $0000, $001E
ai_pc_170a:
    ai_if_tgt_not_beyond_64_5a_short $170A, $170F
ai_pc_170c:
    ai_jmp_01_long $170C, $1711
ai_pc_170f:
    ai_if_tgt_not_within_48_51_short $170F, $1704
ai_pc_1711:
    ai_ret_00
ai_pc_1712:
    ai_pose_e2 $0002
ai_pc_1714:
    ai_pose_e2 $0002
ai_pc_1716:
    ai_hop_e0 $0002, $0000, $000F
ai_pc_171a:
    ai_hop_e0 $0008, $0000, $000F
ai_pc_171e:
    ai_hop_e0 $0001, $0000, $000F
ai_pc_1722:
    ai_hop_e0 $0004, $0000, $000F
ai_pc_1726:
    ai_hop_e0 $0002, $0000, $001E
ai_pc_172a:
    ai_hop_e0 $0008, $0000, $001E
ai_pc_172e:
    ai_hop_e0 $0001, $0000, $001E
ai_pc_1732:
    ai_hop_e0 $0004, $0000, $001E
ai_pc_1736:
    ai_call_ff $6AE1
ai_pc_1739:
    ai_hop_e0 $0004, $0000, $0000
ai_pc_173d:
    ai_set_var1_26 $0000
ai_pc_173f:
    ai_if_tgt_not_within_64_56_short $173F, $1736
ai_pc_1741:
    ai_pose_e2 $0002
ai_pc_1743:
    ai_pose_e2 $0000
ai_pc_1745:
    ai_call_ff $175B
ai_pc_1748:
    ai_ret_00
ai_pc_1749:
    ai_move_toward_card_be $0000, $0000
ai_pc_174c:
    ai_if_var1_ne_0b_short $0000, $174C, $175A
ai_pc_174f:
    ai_rnd_var3_2c $0001
ai_pc_1751:
    ai_if_var3_nz_05_short $1751, $175A
ai_pc_1753:
    ai_tgt2_self_c4
ai_pc_1754:
    ai_cast_e9 $0003, $0004
ai_pc_1757:
    ai_tgt2_none_c0
ai_pc_1758:
    ai_set_var1_26 $0008
ai_pc_175a:
    ai_ret_00
ai_pc_175b:
    ai_move_toward_card_be $0004, $0000
ai_pc_175e:
    ai_turn_facing_e3 $0000, $001E
ai_pc_1761:
    ai_if_tgt_not_beyond_64_5a_short $1761, $1766
ai_pc_1763:
    ai_jmp_01_long $1763, $1768
ai_pc_1766:
    ai_if_tgt_not_within_32_4c_short $1766, $175B
ai_pc_1768:
    ai_if_field_gt_30_short $0080, $006D, $0000, $1768, $1773
ai_pc_176d:
    ai_move_toward_card_be $0000, $0000
ai_pc_1770:
    ai_call_ff $6B0F
ai_pc_1773:
    ai_ret_00
ai_pc_1774:
    ai_move_toward_card_be $0002, $0000
ai_pc_1777:
    ai_turn_facing_e3 $0000, $000F
ai_pc_177a:
    ai_if_tgt_not_beyond_64_5a_short $177A, $177F
ai_pc_177c:
    ai_jmp_01_long $177C, $1781
ai_pc_177f:
    ai_if_tgt_not_within_32_4c_short $177F, $1774
ai_pc_1781:
    ai_move_toward_card_be $0000, $0005
ai_pc_1784:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_1788:
    ai_call_ff $6B0F
ai_pc_178b:
    ai_dec_var1_1f
ai_pc_178c:
    ai_ret_00
ai_pc_178d:
    ai_if_tgt_not_within_32_4c_short $178D, $17A1
ai_pc_178f:
    ai_move_toward_card_be $0005, $0000
ai_pc_1792:
    ai_turn_facing_e3 $0000, $001E
ai_pc_1795:
    ai_if_field_gt_30_short $0080, $006D, $0000, $1795, $179F
ai_pc_179a:
    ai_if_tgt_not_within_32_4c_short $179A, $179F
ai_pc_179c:
    ai_jmp_01_long $179C, $17A1
ai_pc_179f:
    ai_jmp_01_short $179F, $178D
ai_pc_17a1:
    ai_ret_00
ai_pc_17a2:
    ai_call_ff $17C7
ai_pc_17a5:
    ai_call_ff $6AE1
ai_pc_17a8:
    ai_call_ff $1863
ai_pc_17ab:
    ai_call_ff $180C
ai_pc_17ae:
    ai_if_tgt_not_within_32_4c_short $17AE, $17B5
ai_pc_17b0:
    ai_call_ff $17CC
ai_pc_17b3:
    ai_jmp_01_short $17B3, $17BF
ai_pc_17b5:
    ai_if_tgt_not_within_64_56_short $17B5, $17BC
ai_pc_17b7:
    ai_call_ff $17EC
ai_pc_17ba:
    ai_jmp_01_short $17BA, $17BF
ai_pc_17bc:
    ai_move_toward_e4 $0000, $0000
ai_pc_17bf:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $17BF, $17A5
ai_pc_17c4:
    ai_jmp_01_short $17C4, $17A5
