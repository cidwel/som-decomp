.setcpu "65816"
.segment "CODE"
.org $70E5
.include "ai_command_macros.inc"
ai_pc_21d0:
    ai_pose_e2 $0000
ai_pc_21d2:
    ai_pose_e2 $0001
ai_pc_21d4:
    ai_pose_e2 $0001
ai_pc_21d6:
    ai_set_var1_26 $0003
ai_pc_21d8:
    ai_ret_00
ai_pc_21d9:
    ai_move_toward_card_be $0000, $0000
ai_pc_21dc:
    ai_if_field_gt_30_short $0080, $006D, $0000, $21DC, $21E7
ai_pc_21e1:
    ai_move_toward_card_be $0000, $0000
ai_pc_21e4:
    ai_call_ff $6B19
ai_pc_21e7:
    ai_call_ff $223C
ai_pc_21ea:
    ai_ret_00
ai_pc_21eb:
    ai_move_toward_card_be $0000, $0000
ai_pc_21ee:
    ai_if_field_gt_30_short $0080, $006D, $0000, $21EE, $2209
ai_pc_21f3:
    ai_if_obj_outside_5f_short $0080, $21F3, $2204
ai_pc_21f6:
    ai_rnd_var3_2c $000F
ai_pc_21f8:
    ai_if_var3_nz_05_short $21F8, $2204
ai_pc_21fa:
    ai_tgt2_cur_c1
ai_pc_21fb:
    ai_cast_e9 $0004, $000E
ai_pc_21fe:
    ai_tgt2_none_c0
ai_pc_21ff:
    ai_turn_facing_e3 $0000, $0078
ai_pc_2202:
    ai_pose_e2 $0005
ai_pc_2204:
    ai_call_ff $221C
ai_pc_2207:
    ai_jmp_01_short $2207, $220C
ai_pc_2209:
    ai_move_toward_card_be $0000, $0000
ai_pc_220c:
    ai_ret_00
ai_pc_220d:
    ai_if_obj_outside_5f_short $0080, $220D, $221B
ai_pc_2210:
    ai_if_var1_lt_17_short $0001, $2210, $221B
ai_pc_2213:
    ai_if_crowd_gt_f5_short $0002, $2213, $221B
ai_pc_2216:
    ai_pose_e2 $0000
ai_pc_2218:
    ai_cmd43_ed $0026
ai_pc_221a:
    ai_dec_var1_1f
ai_pc_221b:
    ai_ret_00
ai_pc_221c:
    ai_set_var2_27 $0004
ai_pc_221e:
    ai_call_ff $6AE1
ai_pc_2221:
    ai_if_pos_same_9d_short $2221, $2229
ai_pc_2223:
    ai_pos_save_9f
ai_pc_2224:
    ai_move_toward_card_be $0004, $000A
ai_pc_2227:
    ai_jmp_01_short $2227, $222D
ai_pc_2229:
    ai_pos_save_9f
ai_pc_222a:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_222d:
    ai_dec_var2_20
ai_pc_222e:
    ai_if_var2_nz_04_short $222E, $2239
ai_pc_2230:
    ai_move_away_alt_fe $000E, $0000
ai_pc_2233:
    ai_move_away_alt_fe $000E, $0000
ai_pc_2236:
    ai_jmp_01_long $2236, $223B
ai_pc_2239:
    ai_if_tgt_not_within_48_51_short $2239, $221E
ai_pc_223b:
    ai_ret_00
ai_pc_223c:
    ai_set_var2_27 $0004
ai_pc_223e:
    ai_if_tgt_not_within_48_51_short $223E, $225D
ai_pc_2240:
    ai_call_ff $6AE1
ai_pc_2243:
    ai_if_pos_same_9d_short $2243, $224B
ai_pc_2245:
    ai_pos_save_9f
ai_pc_2246:
    ai_move_toward_card_be $0005, $000A
ai_pc_2249:
    ai_jmp_01_short $2249, $224F
ai_pc_224b:
    ai_pos_save_9f
ai_pc_224c:
    ai_move_toward_alt_fd $0005, $000A
ai_pc_224f:
    ai_dec_var2_20
ai_pc_2250:
    ai_if_var2_nz_04_short $2250, $225B
ai_pc_2252:
    ai_move_toward_alt_fd $000E, $0000
ai_pc_2255:
    ai_move_toward_alt_fd $000E, $0000
ai_pc_2258:
    ai_jmp_01_long $2258, $225D
ai_pc_225b:
    ai_jmp_01_short $225B, $223E
ai_pc_225d:
    ai_ret_00
ai_pc_225e:
    ai_call_ff $2289
ai_pc_2261:
    ai_rnd_var3_2c $000F
ai_pc_2263:
    ai_if_var3_nz_05_short $2263, $226A
ai_pc_2265:
    ai_call_ff $672F
ai_pc_2268:
    ai_jmp_01_short $2268, $2281
ai_pc_226a:
    ai_call_ff $22BE
ai_pc_226d:
    ai_call_ff $6AE1
ai_pc_2270:
    ai_if_tgt_not_within_32_4c_short $2270, $2277
ai_pc_2272:
    ai_call_ff $228E
ai_pc_2275:
    ai_jmp_01_short $2275, $2281
ai_pc_2277:
    ai_if_tgt_not_within_64_56_short $2277, $227E
ai_pc_2279:
    ai_call_ff $22A0
ai_pc_227c:
    ai_jmp_01_short $227C, $2281
ai_pc_227e:
    ai_call_ff $22AC
ai_pc_2281:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $2281, $2261
ai_pc_2286:
    ai_jmp_01_short $2286, $2261
