.setcpu "65816"
.segment "CODE"
.org $64AD
.include "ai_command_macros.inc"
ai_pc_1598:
    ai_pose_e2 $0000
ai_pc_159a:
    ai_ret_00
ai_pc_159b:
    ai_move_toward_e4 $0000, $0000
ai_pc_159e:
    ai_if_field_gt_30_short $0080, $006D, $0000, $159E, $15AE
ai_pc_15a3:
    ai_flash_fc
ai_pc_15a4:
    ai_move_toward_e4 $0000, $0000
ai_pc_15a7:
    ai_call_ff $6B0F
ai_pc_15aa:
    ai_flash_fc
ai_pc_15ab:
    ai_move_toward_e4 $0000, $0005
ai_pc_15ae:
    ai_if_tgt_not_left_79_short $15AE, $15B5
ai_pc_15b0:
    ai_move_away_card_bf $0002, $0000
ai_pc_15b3:
    ai_jmp_01_short $15B3, $15CA
ai_pc_15b5:
    ai_if_tgt_not_right_7b_short $15B5, $15BC
ai_pc_15b7:
    ai_move_away_card_bf $0002, $0000
ai_pc_15ba:
    ai_jmp_01_short $15BA, $15CA
ai_pc_15bc:
    ai_rnd_var3_2c $0001
ai_pc_15be:
    ai_if_var3_nz_05_short $15BE, $15C6
ai_pc_15c0:
    ai_hop_e0 $0002, $0002, $0000
ai_pc_15c4:
    ai_jmp_01_short $15C4, $15CA
ai_pc_15c6:
    ai_hop_e0 $0001, $0002, $0000
ai_pc_15ca:
    ai_if_tgt_not_within_48_51_short $15CA, $15D7
ai_pc_15cc:
    ai_pos_save_9f
ai_pc_15cd:
    ai_turn_facing_e3 $0004, $0000
ai_pc_15d0:
    ai_if_pos_moved_9e_short $15D0, $15D5
ai_pc_15d2:
    ai_jmp_01_long $15D2, $15D7
ai_pc_15d5:
    ai_jmp_01_short $15D5, $15CA
ai_pc_15d7:
    ai_ret_00
ai_pc_15d8:
    ai_move_toward_e4 $0000, $0000
ai_pc_15db:
    ai_if_field_gt_30_short $0080, $006D, $0000, $15DB, $15F7
ai_pc_15e0:
    ai_move_toward_e4 $0000, $0000
ai_pc_15e3:
    ai_rnd_var3_2c $0007
ai_pc_15e5:
    ai_if_var3_nz_05_short $15E5, $15F4
ai_pc_15e7:
    ai_pose_e2 $0004
ai_pc_15e9:
    ai_move_toward_e4 $0008, $0000
ai_pc_15ec:
    ai_move_away_e6 $0000, $000F
ai_pc_15ef:
    ai_move_toward_e4 $0000, $000F
ai_pc_15f2:
    ai_jmp_01_short $15F2, $15F7
ai_pc_15f4:
    ai_call_ff $6B0F
ai_pc_15f7:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_15fa:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_15fd:
    ai_move_toward_e4 $0000, $0000
ai_pc_1600:
    ai_ret_00
ai_pc_1601:
    ai_move_toward_e4 $0000, $0000
ai_pc_1604:
    ai_if_field_gt_30_short $0080, $006D, $0000, $1604, $162D
ai_pc_1609:
    ai_if_field_gt_30_short $0080, $001D, $0000, $1609, $1616
ai_pc_160e:
    ai_tgt2_self_c4
ai_pc_160f:
    ai_cast_e9 $0003, $0015
ai_pc_1612:
    ai_tgt2_none_c0
ai_pc_1613:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_1616:
    ai_move_toward_e4 $0000, $0000
ai_pc_1619:
    ai_rnd_var3_2c $0007
ai_pc_161b:
    ai_if_var3_nz_05_short $161B, $162A
ai_pc_161d:
    ai_pose_e2 $0004
ai_pc_161f:
    ai_move_toward_e4 $0008, $0000
ai_pc_1622:
    ai_move_away_e6 $0000, $000F
ai_pc_1625:
    ai_move_toward_e4 $0000, $000F
ai_pc_1628:
    ai_jmp_01_short $1628, $162D
ai_pc_162a:
    ai_call_ff $6B0F
ai_pc_162d:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_1630:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_1633:
    ai_move_toward_e4 $0000, $0000
ai_pc_1636:
    ai_ret_00
ai_pc_1637:
    ai_call_ff $6AE1
ai_pc_163a:
    ai_if_tgt_not_left_79_short $163A, $1642
ai_pc_163c:
    ai_hop_e0 $0002, $0002, $0000
ai_pc_1640:
    ai_jmp_01_short $1640, $164D
ai_pc_1642:
    ai_if_tgt_not_right_7b_short $1642, $164A
ai_pc_1644:
    ai_hop_e0 $0001, $0002, $0000
ai_pc_1648:
    ai_jmp_01_short $1648, $164D
ai_pc_164a:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_164d:
    ai_if_tgt_not_within_64_56_short $164D, $1637
ai_pc_164f:
    ai_ret_00
ai_pc_1650:
    ai_call_ff $1676
ai_pc_1653:
    ai_call_ff $6AE1
ai_pc_1656:
    ai_if_tgt_not_within_32_4c_short $1656, $165D
ai_pc_1658:
    ai_call_ff $1693
ai_pc_165b:
    ai_jmp_01_short $165B, $166E
ai_pc_165d:
    ai_if_tgt_not_within_48_51_short $165D, $1664
ai_pc_165f:
    ai_call_ff $16B5
ai_pc_1662:
    ai_jmp_01_short $1662, $166E
ai_pc_1664:
    ai_if_tgt_not_within_64_56_short $1664, $166B
ai_pc_1666:
    ai_call_ff $16EC
ai_pc_1669:
    ai_jmp_01_short $1669, $166E
ai_pc_166b:
    ai_call_ff $1712
ai_pc_166e:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $166E, $1653
ai_pc_1673:
    ai_jmp_01_short $1673, $1653
