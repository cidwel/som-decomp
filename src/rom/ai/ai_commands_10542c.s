.setcpu "65816"
.segment "CODE"
.org $542C
.include "ai_command_macros.inc"
ai_pc_0517:
    ai_move_toward_e4 $0000, $0000
ai_pc_051a:
    ai_if_field_gt_30_short $0080, $006D, $0000, $051A, $0525
ai_pc_051f:
    ai_move_toward_e4 $0000, $0000
ai_pc_0522:
    ai_call_ff $6B0F
ai_pc_0525:
    ai_move_toward_e4 $000E, $0000
ai_pc_0528:
    ai_call_ff $0597
ai_pc_052b:
    ai_ret_00
ai_pc_052c:
    ai_move_toward_e4 $0000, $0000
ai_pc_052f:
    ai_if_field_gt_30_short $0080, $006D, $0000, $052F, $053A
ai_pc_0534:
    ai_move_toward_e4 $0000, $0000
ai_pc_0537:
    ai_call_ff $6B0F
ai_pc_053a:
    ai_call_ff $0597
ai_pc_053d:
    ai_ret_00
ai_pc_053e:
    ai_if_field_gt_30_short $0080, $006D, $0000, $053E, $055F
ai_pc_0543:
    ai_rnd_var3_2c $0007
ai_pc_0545:
    ai_if_var3_nz_05_short $0545, $0554
ai_pc_0547:
    ai_flash_fc
ai_pc_0548:
    ai_move_toward_e4 $0000, $0000
ai_pc_054b:
    ai_call_ff $6B0F
ai_pc_054e:
    ai_flash_fc
ai_pc_054f:
    ai_move_toward_e4 $0000, $0005
ai_pc_0552:
    ai_jmp_01_short $0552, $055D
ai_pc_0554:
    ai_call_ff $0576
ai_pc_0557:
    ai_move_toward_e4 $0000, $0000
ai_pc_055a:
    ai_call_ff $6B0F
ai_pc_055d:
    ai_jmp_01_short $055D, $0562
ai_pc_055f:
    ai_move_toward_e4 $0000, $0000
ai_pc_0562:
    ai_ret_00
ai_pc_0563:
    ai_call_ff $0576
ai_pc_0566:
    ai_rnd_var3_2c $000F
ai_pc_0568:
    ai_if_var3_nz_05_short $0568, $0575
ai_pc_056a:
    ai_flash_fc
ai_pc_056b:
    ai_move_toward_e4 $0000, $0000
ai_pc_056e:
    ai_call_ff $6B0F
ai_pc_0571:
    ai_flash_fc
ai_pc_0572:
    ai_move_toward_e4 $0000, $0005
ai_pc_0575:
    ai_ret_00
ai_pc_0576:
    ai_set_var2_27 $0004
ai_pc_0578:
    ai_call_ff $6AE1
ai_pc_057b:
    ai_if_pos_same_9d_short $057B, $0583
ai_pc_057d:
    ai_pos_save_9f
ai_pc_057e:
    ai_move_toward_e4 $0001, $0005
ai_pc_0581:
    ai_jmp_01_short $0581, $0587
ai_pc_0583:
    ai_pos_save_9f
ai_pc_0584:
    ai_move_toward_alt_fd $0001, $0005
ai_pc_0587:
    ai_dec_var2_20
ai_pc_0588:
    ai_if_var2_nz_04_short $0588, $0594
ai_pc_058a:
    ai_rnd_var3_2c $0005
ai_pc_058c:
    ai_if_var3_nz_05_short $058C, $0594
ai_pc_058e:
    ai_move_toward_e4 $0000, $001E
ai_pc_0591:
    ai_jmp_01_long $0591, $0596
ai_pc_0594:
    ai_if_tgt_not_within_32_4c_short $0594, $0578
ai_pc_0596:
    ai_ret_00
ai_pc_0597:
    ai_set_var2_27 $0004
ai_pc_0599:
    ai_if_pos_same_9d_short $0599, $05A1
ai_pc_059b:
    ai_pos_save_9f
ai_pc_059c:
    ai_move_away_e6 $0001, $0005
ai_pc_059f:
    ai_jmp_01_short $059F, $05A5
ai_pc_05a1:
    ai_pos_save_9f
ai_pc_05a2:
    ai_move_away_alt_fe $0001, $0005
ai_pc_05a5:
    ai_if_tgt_not_beyond_64_5a_short $05A5, $05AC
ai_pc_05a7:
    ai_jmp_01_long $05A7, $05BB
