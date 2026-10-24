.setcpu "65816"
.segment "CODE"
.org $A7FF
.include "ai_command_macros.inc"
ai_pc_58ea:
    ai_call_ff $590F
ai_pc_58ed:
    ai_if_field_gt_30_short $00FF, $0073, $0000, $58ED, $58F7
ai_pc_58f2:
    ai_call_ff $5C06
ai_pc_58f5:
    ai_jmp_01_short $58F5, $590E
ai_pc_58f7:
    ai_if_field_gt_30_short $00FF, $0073, $0001, $58F7, $5901
ai_pc_58fc:
    ai_call_ff $5E08
ai_pc_58ff:
    ai_jmp_01_short $58FF, $590E
ai_pc_5901:
    ai_if_field_gt_30_short $00FF, $0073, $0002, $5901, $590B
ai_pc_5906:
    ai_call_ff $61D8
ai_pc_5909:
    ai_jmp_01_short $5909, $590E
ai_pc_590b:
    ai_call_ff $605E
ai_pc_590e:
    ai_ret_00
ai_pc_590f:
    ai_turn_facing_e3 $0000, $0005
ai_pc_5912:
    ai_ret_00
ai_pc_5913:
    ai_if_fight_62_short $5913, $591B
ai_pc_5915:
    ai_follow_e1
ai_pc_5916:
    ai_charge_release_f4
ai_pc_5917:
    ai_tgt_none_a0
ai_pc_5918:
    ai_tgt2_none_c0
ai_pc_5919:
    ai_jmp_01_short $5919, $5913
ai_pc_591b:
    ai_if_no_monster_48_4f_short $591B, $5930
ai_pc_591d:
    ai_if_no_monster_16_32_short $591D, $5923
ai_pc_591f:
    ai_tgt_monster_16_a6
ai_pc_5920:
    ai_charge_start_f3
ai_pc_5921:
    ai_jmp_01_short $5921, $592B
ai_pc_5923:
    ai_if_no_monster_32_4a_short $5923, $5929
ai_pc_5925:
    ai_tgt_monster_32_b2
ai_pc_5926:
    ai_charge_start_f3
ai_pc_5927:
    ai_jmp_01_short $5927, $592B
ai_pc_5929:
    ai_tgt_monster_48_b5
ai_pc_592a:
    ai_charge_start_f3
ai_pc_592b:
    ai_move_toward_e4 $0003, $0005
ai_pc_592e:
    ai_jmp_01_short $592E, $593C
ai_pc_5930:
    ai_if_no_ally_64_54_short $5930, $5939
ai_pc_5932:
    ai_tgt_monster_64_b8
ai_pc_5933:
    ai_charge_start_f3
ai_pc_5934:
    ai_move_toward_e4 $0003, $0005
ai_pc_5937:
    ai_jmp_01_short $5937, $593C
ai_pc_5939:
    ai_follow_e1
ai_pc_593a:
    ai_tgt_none_a0
ai_pc_593b:
    ai_tgt2_none_c0
ai_pc_593c:
    ai_ret_00
ai_pc_593d:
    ai_rnd_var3_2c $0003
ai_pc_593f:
    ai_if_var3_nz_05_short $593F, $5947
ai_pc_5941:
    ai_hop_e0 $000A, $000B, $000A
ai_pc_5945:
    ai_jmp_01_short $5945, $595D
ai_pc_5947:
    ai_if_var3_ne_0d_short $0001, $5947, $5950
ai_pc_594a:
    ai_hop_e0 $0009, $000B, $000A
ai_pc_594e:
    ai_jmp_01_short $594E, $595D
ai_pc_5950:
    ai_if_var3_ne_0d_short $0002, $5950, $5959
ai_pc_5953:
    ai_hop_e0 $0006, $000B, $000A
ai_pc_5957:
    ai_jmp_01_short $5957, $595D
ai_pc_5959:
    ai_hop_e0 $0005, $000B, $000A
ai_pc_595d:
    ai_ret_00
ai_pc_595e:
    ai_if_pos_same_9d_short $595E, $5966
ai_pc_5960:
    ai_pos_save_9f
ai_pc_5961:
    ai_move_toward_e4 $000A, $000A
ai_pc_5964:
    ai_jmp_01_short $5964, $596A
ai_pc_5966:
    ai_pos_save_9f
ai_pc_5967:
    ai_move_toward_alt_fd $000A, $000A
ai_pc_596a:
    ai_ret_00
ai_pc_596b:
    ai_if_pos_same_9d_short $596B, $5973
ai_pc_596d:
    ai_pos_save_9f
ai_pc_596e:
    ai_move_toward_e4 $000A, $0005
ai_pc_5971:
    ai_jmp_01_short $5971, $5977
ai_pc_5973:
    ai_pos_save_9f
ai_pc_5974:
    ai_move_toward_alt_fd $000A, $0005
ai_pc_5977:
    ai_ret_00
ai_pc_5978:
    ai_if_pos_same_9d_short $5978, $5980
ai_pc_597a:
    ai_pos_save_9f
ai_pc_597b:
    ai_move_away_e6 $000A, $000A
ai_pc_597e:
    ai_jmp_01_short $597E, $5984
ai_pc_5980:
    ai_pos_save_9f
ai_pc_5981:
    ai_move_away_alt_fe $000A, $000A
ai_pc_5984:
    ai_ret_00
ai_pc_5985:
    ai_if_pos_same_9d_short $5985, $598D
ai_pc_5987:
    ai_pos_save_9f
ai_pc_5988:
    ai_move_away_e6 $000A, $0005
ai_pc_598b:
    ai_jmp_01_short $598B, $5991
ai_pc_598d:
    ai_pos_save_9f
ai_pc_598e:
    ai_move_away_alt_fe $000A, $0005
ai_pc_5991:
    ai_ret_00
