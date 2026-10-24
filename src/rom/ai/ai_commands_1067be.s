.setcpu "65816"
.segment "CODE"
.org $67BE
.include "ai_command_macros.inc"
ai_pc_18a9:
    ai_pose_e2 $0002
ai_pc_18ab:
    ai_ret_00
ai_pc_18ac:
    ai_move_toward_e4 $0000, $0005
ai_pc_18af:
    ai_if_field_gt_30_short $0080, $006D, $0000, $18AF, $18BA
ai_pc_18b4:
    ai_move_toward_e4 $0003, $0000
ai_pc_18b7:
    ai_call_ff $6B0F
ai_pc_18ba:
    ai_move_toward_e4 $000E, $0000
ai_pc_18bd:
    ai_call_ff $1933
ai_pc_18c0:
    ai_ret_00
ai_pc_18c1:
    ai_move_toward_e4 $0000, $0005
ai_pc_18c4:
    ai_if_field_gt_30_short $0080, $006D, $0000, $18C4, $18CF
ai_pc_18c9:
    ai_move_toward_e4 $0003, $0000
ai_pc_18cc:
    ai_call_ff $6B0F
ai_pc_18cf:
    ai_move_toward_e4 $000E, $0000
ai_pc_18d2:
    ai_call_ff $1933
ai_pc_18d5:
    ai_ret_00
ai_pc_18d6:
    ai_move_toward_e4 $0000, $0005
ai_pc_18d9:
    ai_if_field_gt_30_short $0080, $006D, $0000, $18D9, $18EA
ai_pc_18de:
    ai_rnd_var3_2c $000F
ai_pc_18e0:
    ai_if_var3_nz_05_short $18E0, $18E8
ai_pc_18e2:
    ai_move_toward_e4 $0003, $003C
ai_pc_18e5:
    ai_call_ff $1921
ai_pc_18e8:
    ai_jmp_01_short $18E8, $18ED
ai_pc_18ea:
    ai_move_toward_e4 $0000, $0000
ai_pc_18ed:
    ai_ret_00
ai_pc_18ee:
    ai_rnd_var3_2c $000F
ai_pc_18f0:
    ai_if_var3_nz_05_short $18F0, $18F7
ai_pc_18f2:
    ai_call_ff $1921
ai_pc_18f5:
    ai_jmp_01_short $18F5, $190E
ai_pc_18f7:
    ai_move_toward_e4 $0003, $003C
ai_pc_18fa:
    ai_rnd_var3_2c $000F
ai_pc_18fc:
    ai_if_var3_nz_05_short $18FC, $190B
ai_pc_18fe:
    ai_if_obj_outside_5f_short $0080, $18FE, $1908
ai_pc_1901:
    ai_tgt2_cur_c1
ai_pc_1902:
    ai_cast_e9 $0005, $0002
ai_pc_1905:
    ai_tgt2_none_c0
ai_pc_1906:
    ai_jmp_01_short $1906, $190B
ai_pc_1908:
    ai_move_toward_e4 $0000, $0005
ai_pc_190b:
    ai_call_ff $190F
ai_pc_190e:
    ai_ret_00
ai_pc_190f:
    ai_call_ff $6AE1
ai_pc_1912:
    ai_if_pos_same_9d_short $1912, $191A
ai_pc_1914:
    ai_pos_save_9f
ai_pc_1915:
    ai_move_toward_e4 $0004, $0000
ai_pc_1918:
    ai_jmp_01_short $1918, $191E
ai_pc_191a:
    ai_pos_save_9f
ai_pc_191b:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_191e:
    ai_if_tgt_not_within_64_56_short $191E, $190F
ai_pc_1920:
    ai_ret_00
ai_pc_1921:
    ai_call_ff $6AE1
ai_pc_1924:
    ai_if_pos_same_9d_short $1924, $192C
ai_pc_1926:
    ai_pos_save_9f
ai_pc_1927:
    ai_move_toward_e4 $0002, $0000
ai_pc_192a:
    ai_jmp_01_short $192A, $1930
ai_pc_192c:
    ai_pos_save_9f
ai_pc_192d:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_1930:
    ai_if_tgt_not_within_48_51_short $1930, $1921
ai_pc_1932:
    ai_ret_00
ai_pc_1933:
    ai_if_tgt_not_within_48_51_short $1933, $1946
ai_pc_1935:
    ai_call_ff $6AE1
ai_pc_1938:
    ai_if_pos_same_9d_short $1938, $1940
ai_pc_193a:
    ai_pos_save_9f
ai_pc_193b:
    ai_move_toward_e4 $0005, $0000
ai_pc_193e:
    ai_jmp_01_short $193E, $1944
ai_pc_1940:
    ai_pos_save_9f
ai_pc_1941:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_1944:
    ai_jmp_01_short $1944, $1933
ai_pc_1946:
    ai_ret_00
ai_pc_1947:
    ai_call_ff $1966
ai_pc_194a:
    ai_call_ff $6AE1
ai_pc_194d:
    ai_if_tgt_not_within_48_51_short $194D, $1954
ai_pc_194f:
    ai_call_ff $1973
ai_pc_1952:
    ai_jmp_01_short $1952, $195E
ai_pc_1954:
    ai_if_tgt_not_within_64_56_short $1954, $195B
ai_pc_1956:
    ai_call_ff $19A3
ai_pc_1959:
    ai_jmp_01_short $1959, $195E
ai_pc_195b:
    ai_call_ff $19DC
ai_pc_195e:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $195E, $194A
ai_pc_1963:
    ai_jmp_01_short $1963, $194A
