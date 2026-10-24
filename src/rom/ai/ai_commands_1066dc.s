.setcpu "65816"
.segment "CODE"
.org $66DC
.include "ai_command_macros.inc"
ai_pc_17c7:
    ai_pose_e2 $0000
ai_pc_17c9:
    ai_set_var1_26 $000F
ai_pc_17cb:
    ai_ret_00
ai_pc_17cc:
    ai_move_toward_e4 $0000, $0000
ai_pc_17cf:
    ai_if_field_gt_30_short $0080, $006D, $0000, $17CF, $17EB
ai_pc_17d4:
    ai_if_tgt_not_lane_v48_68_short $17D4, $17DE
ai_pc_17d6:
    ai_move_toward_e4 $0000, $0000
ai_pc_17d9:
    ai_call_ff $6B19
ai_pc_17dc:
    ai_jmp_01_short $17DC, $17EB
ai_pc_17de:
    ai_if_tgt_not_lane_h48_71_short $17DE, $17E8
ai_pc_17e0:
    ai_move_toward_e4 $0000, $0000
ai_pc_17e3:
    ai_call_ff $6B19
ai_pc_17e6:
    ai_jmp_01_short $17E6, $17EB
ai_pc_17e8:
    ai_move_toward_e4 $0000, $0005
ai_pc_17eb:
    ai_ret_00
ai_pc_17ec:
    ai_move_toward_e4 $0000, $0000
ai_pc_17ef:
    ai_if_field_gt_30_short $0080, $006D, $0000, $17EF, $180B
ai_pc_17f4:
    ai_if_tgt_not_lane_v64_66_short $17F4, $17FE
ai_pc_17f6:
    ai_move_toward_e4 $0000, $0000
ai_pc_17f9:
    ai_call_ff $6B19
ai_pc_17fc:
    ai_jmp_01_short $17FC, $180B
ai_pc_17fe:
    ai_if_tgt_not_lane_h64_6f_short $17FE, $1808
ai_pc_1800:
    ai_move_toward_e4 $0000, $0000
ai_pc_1803:
    ai_call_ff $6B19
ai_pc_1806:
    ai_jmp_01_short $1806, $180B
ai_pc_1808:
    ai_move_toward_e4 $0000, $0000
ai_pc_180b:
    ai_ret_00
ai_pc_180c:
    ai_if_obj_outside_5f_long $0080, $180C, $185F
ai_pc_1810:
    ai_if_field_lt_2f_short $0081, $001D, $0001, $1810, $181F
ai_pc_1815:
    ai_tgt2_cur_c1
ai_pc_1816:
    ai_cast_e9 $0002, $0026
ai_pc_1819:
    ai_tgt2_none_c0
ai_pc_181a:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_181d:
    ai_jmp_01_short $181D, $1830
ai_pc_181f:
    ai_move_toward_e4 $0000, $0005
ai_pc_1822:
    ai_if_word_lt_bc_short $0081, $003D, $0001, $0000, $1822, $1830
ai_pc_1828:
    ai_tgt2_cur_c1
ai_pc_1829:
    ai_cast_e9 $0002, $0026
ai_pc_182c:
    ai_tgt2_none_c0
ai_pc_182d:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_1830:
    ai_if_no_ally_64_54_short $1830, $185A
ai_pc_1832:
    ai_tgt2_ally_d8
ai_pc_1833:
    ai_if_word_and_z_bb_short $0082, $0010, $00FC, $007F, $1833, $183F
ai_pc_1839:
    ai_cast_e9 $0002, $000A
ai_pc_183c:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_183f:
    ai_turn_facing_e3 $0000, $0005
ai_pc_1842:
    ai_rnd_var3_2c $0007
ai_pc_1844:
    ai_if_var3_nz_05_short $1844, $1857
ai_pc_1846:
    ai_if_word_gt_bd_short $0082, $0002, $00E1, $0000, $1846, $1854
ai_pc_184c:
    ai_cast_e9 $0002, $000B
ai_pc_184f:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_1852:
    ai_jmp_01_short $1852, $1857
ai_pc_1854:
    ai_move_toward_e4 $0000, $0005
ai_pc_1857:
    ai_tgt2_none_c0
ai_pc_1858:
    ai_jmp_01_short $1858, $185D
ai_pc_185a:
    ai_move_toward_e4 $0000, $0005
ai_pc_185d:
    ai_jmp_01_short $185D, $1862
ai_pc_185f:
    ai_move_toward_e4 $0000, $0005
ai_pc_1862:
    ai_ret_00
ai_pc_1863:
    ai_if_obj_outside_5f_short $0080, $1863, $1879
ai_pc_1866:
    ai_if_var1_lt_17_short $0001, $1866, $1879
ai_pc_1869:
    ai_if_crowd_gt_f5_short $0002, $1869, $1876
ai_pc_186c:
    ai_move_toward_card_be $0000, $0005
ai_pc_186f:
    ai_pose_e2 $0003
ai_pc_1871:
    ai_cmd43_ed $0033
ai_pc_1873:
    ai_dec_var1_1f
ai_pc_1874:
    ai_jmp_01_short $1874, $1879
ai_pc_1876:
    ai_move_toward_e4 $0000, $0005
ai_pc_1879:
    ai_ret_00
ai_pc_187a:
    ai_call_ff $18A9
ai_pc_187d:
    ai_rnd_var3_2c $0007
ai_pc_187f:
    ai_if_var3_nz_05_short $187F, $1886
ai_pc_1881:
    ai_call_ff $67DF
ai_pc_1884:
    ai_jmp_01_short $1884, $18A1
ai_pc_1886:
    ai_call_ff $6AE1
ai_pc_1889:
    ai_if_tgt_not_within_16_34_short $1889, $1890
ai_pc_188b:
    ai_call_ff $18AC
ai_pc_188e:
    ai_jmp_01_short $188E, $18A1
ai_pc_1890:
    ai_if_tgt_not_within_48_51_short $1890, $1897
ai_pc_1892:
    ai_call_ff $18C1
ai_pc_1895:
    ai_jmp_01_short $1895, $18A1
ai_pc_1897:
    ai_if_tgt_not_within_64_56_short $1897, $189E
ai_pc_1899:
    ai_call_ff $18D6
ai_pc_189c:
    ai_jmp_01_short $189C, $18A1
ai_pc_189e:
    ai_call_ff $18EE
ai_pc_18a1:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $18A1, $187D
ai_pc_18a6:
    ai_jmp_01_short $18A6, $187D
