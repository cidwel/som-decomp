.setcpu "65816"
.segment "CODE"
.org $A138
.include "ai_command_macros.inc"
ai_pc_5223:
    ai_pose_e2 $0004
ai_pc_5225:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_5229:
    ai_move_toward_card_be $0003, $0005
ai_pc_522c:
    ai_call_ff $6B2D
ai_pc_522f:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_5233:
    ai_if_tgt_not_within_64_56_short $5233, $5217
ai_pc_5235:
    ai_ret_00
ai_pc_5236:
    ai_move_toward_card_be $0003, $0005
ai_pc_5239:
    ai_pose_e2 $0003
ai_pc_523b:
    ai_pose_e2 $0003
ai_pc_523d:
    ai_call_ff $6B2D
ai_pc_5240:
    ai_field_set_dc $0080, $006D, $0000
ai_pc_5244:
    ai_move_toward_card_be $0003, $0005
ai_pc_5247:
    ai_call_ff $6B2D
ai_pc_524a:
    ai_ret_00
ai_pc_524b:
    ai_set_var1_26 $0001
ai_pc_524d:
    ai_pose_e2 $0003
ai_pc_524f:
    ai_dec_var2_20
ai_pc_5250:
    ai_call_ff $6AE1
ai_pc_5253:
    ai_if_tgt_not_within_64_56_short $5253, $525A
ai_pc_5255:
    ai_set_var1_26 $0000
ai_pc_5257:
    ai_jmp_01_long $5257, $525C
ai_pc_525a:
    ai_if_var2_nz_04_short $525A, $524D
ai_pc_525c:
    ai_move_toward_e4 $0000, $0005
ai_pc_525f:
    ai_ret_00
ai_pc_5260:
    ai_if_word_gt_bd_short $0080, $003D, $0001, $0000, $5260, $526E
ai_pc_5266:
    ai_tgt2_self_c4
ai_pc_5267:
    ai_cast_e9 $0002, $0029
ai_pc_526a:
    ai_tgt2_none_c0
ai_pc_526b:
    ai_turn_facing_e3 $0000, $003C
ai_pc_526e:
    ai_ret_00
ai_pc_526f:
    ai_call_ff $6AE1
ai_pc_5272:
    ai_call_ff $52AD
ai_pc_5275:
    ai_if_tgt_not_beyond_64_5a_short $5275, $527A
ai_pc_5277:
    ai_jmp_01_long $5277, $5284
ai_pc_527a:
    ai_call_ff $52AD
ai_pc_527d:
    ai_if_tgt_not_beyond_64_5a_short $527D, $5282
ai_pc_527f:
    ai_jmp_01_long $527F, $5284
ai_pc_5282:
    ai_if_tgt_not_within_48_51_short $5282, $526F
ai_pc_5284:
    ai_ret_00
ai_pc_5285:
    ai_if_tgt_not_within_48_51_short $5285, $52AC
ai_pc_5287:
    ai_call_ff $6AE1
ai_pc_528a:
    ai_call_ff $52C6
ai_pc_528d:
    ai_if_tgt_not_within_48_51_short $528D, $529A
ai_pc_528f:
    ai_if_field_gt_30_short $0080, $006D, $0000, $528F, $529A
ai_pc_5294:
    ai_move_toward_card_be $0003, $0005
ai_pc_5297:
    ai_call_ff $6B2D
ai_pc_529a:
    ai_call_ff $52C6
ai_pc_529d:
    ai_if_tgt_not_within_48_51_short $529D, $52AA
ai_pc_529f:
    ai_if_field_gt_30_short $0080, $006D, $0000, $529F, $52AA
ai_pc_52a4:
    ai_move_toward_card_be $0003, $0005
ai_pc_52a7:
    ai_call_ff $6B2D
ai_pc_52aa:
    ai_jmp_01_short $52AA, $5285
ai_pc_52ac:
    ai_ret_00
ai_pc_52ad:
    ai_if_pos_same_9d_short $52AD, $52B5
ai_pc_52af:
    ai_pos_save_9f
ai_pc_52b0:
    ai_move_toward_card_be $0004, $000A
ai_pc_52b3:
    ai_jmp_01_short $52B3, $52B9
ai_pc_52b5:
    ai_pos_save_9f
ai_pc_52b6:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_52b9:
    ai_if_pos_same_9d_short $52B9, $52C1
ai_pc_52bb:
    ai_pos_save_9f
ai_pc_52bc:
    ai_move_toward_card_be $0004, $000F
ai_pc_52bf:
    ai_jmp_01_short $52BF, $52C5
ai_pc_52c1:
    ai_pos_save_9f
ai_pc_52c2:
    ai_move_toward_alt_fd $0004, $000F
ai_pc_52c5:
    ai_ret_00
ai_pc_52c6:
    ai_if_pos_same_9d_short $52C6, $52CE
ai_pc_52c8:
    ai_pos_save_9f
ai_pc_52c9:
    ai_move_toward_card_be $0005, $000A
ai_pc_52cc:
    ai_jmp_01_short $52CC, $52D2
ai_pc_52ce:
    ai_pos_save_9f
ai_pc_52cf:
    ai_move_toward_alt_fd $0005, $000A
ai_pc_52d2:
    ai_if_pos_same_9d_short $52D2, $52DA
ai_pc_52d4:
    ai_pos_save_9f
ai_pc_52d5:
    ai_move_toward_card_be $0005, $000F
ai_pc_52d8:
    ai_jmp_01_short $52D8, $52DE
ai_pc_52da:
    ai_pos_save_9f
ai_pc_52db:
    ai_move_toward_alt_fd $0005, $000F
ai_pc_52de:
    ai_ret_00
ai_pc_52df:
    ai_call_ff $530C
ai_pc_52e2:
    ai_call_ff $6AE1
ai_pc_52e5:
    ai_if_tgt_not_within_16_34_short $52E5, $52EC
ai_pc_52e7:
    ai_call_ff $5314
ai_pc_52ea:
    ai_jmp_01_short $52EA, $5304
ai_pc_52ec:
    ai_if_tgt_not_within_32_4c_short $52EC, $52F3
ai_pc_52ee:
    ai_call_ff $5329
ai_pc_52f1:
    ai_jmp_01_short $52F1, $5304
ai_pc_52f3:
    ai_if_tgt_not_within_48_51_short $52F3, $52FA
ai_pc_52f5:
    ai_call_ff $533B
ai_pc_52f8:
    ai_jmp_01_short $52F8, $5304
ai_pc_52fa:
    ai_if_tgt_not_within_64_56_short $52FA, $5301
ai_pc_52fc:
    ai_call_ff $5353
ai_pc_52ff:
    ai_jmp_01_short $52FF, $5304
ai_pc_5301:
    ai_call_ff $5399
ai_pc_5304:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $5304, $52E2
ai_pc_5309:
    ai_jmp_01_short $5309, $52E2
