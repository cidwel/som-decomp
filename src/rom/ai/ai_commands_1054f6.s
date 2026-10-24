.setcpu "65816"
.segment "CODE"
.org $54F6
.include "ai_command_macros.inc"
ai_pc_05e1:
    ai_pose_e2 $0000
ai_pc_05e3:
    ai_set_var1_26 $000F
ai_pc_05e5:
    ai_ret_00
ai_pc_05e6:
    ai_move_toward_e4 $0000, $0000
ai_pc_05e9:
    ai_if_field_gt_30_short $0080, $006D, $0000, $05E9, $0605
ai_pc_05ee:
    ai_if_tgt_not_lane_v48_68_short $05EE, $05F8
ai_pc_05f0:
    ai_move_toward_e4 $0000, $0000
ai_pc_05f3:
    ai_call_ff $6B0F
ai_pc_05f6:
    ai_jmp_01_short $05F6, $0605
ai_pc_05f8:
    ai_if_tgt_not_lane_h48_71_short $05F8, $0602
ai_pc_05fa:
    ai_move_toward_e4 $0000, $0000
ai_pc_05fd:
    ai_call_ff $6B0F
ai_pc_0600:
    ai_jmp_01_short $0600, $0605
ai_pc_0602:
    ai_move_toward_e4 $0000, $0005
ai_pc_0605:
    ai_ret_00
ai_pc_0606:
    ai_move_toward_e4 $0000, $0000
ai_pc_0609:
    ai_ret_00
ai_pc_060a:
    ai_if_obj_outside_5f_short $0080, $060A, $063C
ai_pc_060d:
    ai_if_no_ally_64_54_short $060D, $0637
ai_pc_060f:
    ai_tgt2_ally_d8
ai_pc_0610:
    ai_if_word_and_z_bb_short $0082, $0010, $00FC, $007F, $0610, $061C
ai_pc_0616:
    ai_cast_e9 $0002, $000A
ai_pc_0619:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_061c:
    ai_turn_facing_e3 $0000, $0005
ai_pc_061f:
    ai_rnd_var3_2c $0007
ai_pc_0621:
    ai_if_var3_nz_05_short $0621, $0634
ai_pc_0623:
    ai_if_word_gt_bd_short $0082, $0002, $001E, $0000, $0623, $0631
ai_pc_0629:
    ai_cast_e9 $0002, $000B
ai_pc_062c:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_062f:
    ai_jmp_01_short $062F, $0634
ai_pc_0631:
    ai_move_toward_e4 $0000, $0005
ai_pc_0634:
    ai_tgt2_none_c0
ai_pc_0635:
    ai_jmp_01_short $0635, $063A
ai_pc_0637:
    ai_move_toward_e4 $0000, $0005
ai_pc_063a:
    ai_jmp_01_short $063A, $063F
ai_pc_063c:
    ai_move_toward_e4 $0000, $0005
ai_pc_063f:
    ai_ret_00
ai_pc_0640:
    ai_if_obj_outside_5f_short $0080, $0640, $0656
ai_pc_0643:
    ai_if_var1_lt_17_short $0001, $0643, $0656
ai_pc_0646:
    ai_if_crowd_gt_f5_short $0002, $0646, $0653
ai_pc_0649:
    ai_move_toward_card_be $0000, $0005
ai_pc_064c:
    ai_pose_e2 $0003
ai_pc_064e:
    ai_cmd43_ed $0003
ai_pc_0650:
    ai_dec_var1_1f
ai_pc_0651:
    ai_jmp_01_short $0651, $0656
ai_pc_0653:
    ai_move_toward_e4 $0000, $0005
ai_pc_0656:
    ai_ret_00
ai_pc_0657:
    ai_call_ff $0682
ai_pc_065a:
    ai_rnd_var3_2c $0007
ai_pc_065c:
    ai_if_var3_nz_05_short $065C, $0663
ai_pc_065e:
    ai_call_ff $675B
ai_pc_0661:
    ai_jmp_01_short $0661, $067A
ai_pc_0663:
    ai_call_ff $6AE1
ai_pc_0666:
    ai_call_ff $06AD
ai_pc_0669:
    ai_if_tgt_not_within_32_4c_short $0669, $0670
ai_pc_066b:
    ai_call_ff $0687
ai_pc_066e:
    ai_jmp_01_short $066E, $067A
ai_pc_0670:
    ai_if_tgt_not_within_64_56_short $0670, $0677
ai_pc_0672:
    ai_call_ff $0699
ai_pc_0675:
    ai_jmp_01_short $0675, $067A
ai_pc_0677:
    ai_call_ff $06D7
ai_pc_067a:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $067A, $065A
ai_pc_067f:
    ai_jmp_01_short $067F, $065A
