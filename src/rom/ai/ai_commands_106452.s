.setcpu "65816"
.segment "CODE"
.org $6452
.include "ai_command_macros.inc"
ai_pc_153d:
    ai_pose_e2 $0000
ai_pc_153f:
    ai_ret_00
ai_pc_1540:
    ai_call_ff $6AE1
ai_pc_1543:
    ai_if_pos_same_9d_short $1543, $154B
ai_pc_1545:
    ai_pos_save_9f
ai_pc_1546:
    ai_move_toward_card_be $0004, $000A
ai_pc_1549:
    ai_jmp_01_short $1549, $154F
ai_pc_154b:
    ai_pos_save_9f
ai_pc_154c:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_154f:
    ai_if_tgt_not_within_16_34_short $154F, $1540
ai_pc_1551:
    ai_pose_e2 $0001
ai_pc_1553:
    ai_pose_e2 $0001
ai_pc_1555:
    ai_rnd_var3_2c $0001
ai_pc_1557:
    ai_if_var3_nz_05_short $1557, $1560
ai_pc_1559:
    ai_pose_e2 $0003
ai_pc_155b:
    ai_move_toward_e4 $0000, $00B4
ai_pc_155e:
    ai_jmp_01_short $155E, $1568
ai_pc_1560:
    ai_tgt2_cur_c1
ai_pc_1561:
    ai_cast_e9 $0002, $001F
ai_pc_1564:
    ai_tgt2_none_c0
ai_pc_1565:
    ai_cmd81_ef $0005, $00FE
ai_pc_1568:
    ai_ret_00
ai_pc_1569:
    ai_call_ff $1598
ai_pc_156c:
    ai_rnd_var3_2c $0007
ai_pc_156e:
    ai_if_var3_nz_05_short $156E, $1575
ai_pc_1570:
    ai_call_ff $6993
ai_pc_1573:
    ai_jmp_01_short $1573, $1590
ai_pc_1575:
    ai_call_ff $6AE1
ai_pc_1578:
    ai_if_tgt_not_within_32_4c_short $1578, $157F
ai_pc_157a:
    ai_call_ff $159B
ai_pc_157d:
    ai_jmp_01_short $157D, $1590
ai_pc_157f:
    ai_if_tgt_not_within_48_51_short $157F, $1586
ai_pc_1581:
    ai_call_ff $15D8
ai_pc_1584:
    ai_jmp_01_short $1584, $1590
ai_pc_1586:
    ai_if_tgt_not_within_64_56_short $1586, $158D
ai_pc_1588:
    ai_call_ff $1601
ai_pc_158b:
    ai_jmp_01_short $158B, $1590
ai_pc_158d:
    ai_call_ff $1637
ai_pc_1590:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $1590, $156C
ai_pc_1595:
    ai_jmp_01_short $1595, $156C
