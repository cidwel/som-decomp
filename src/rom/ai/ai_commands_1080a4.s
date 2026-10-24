.setcpu "65816"
.segment "CODE"
.org $80A4
.include "ai_command_macros.inc"
ai_pc_318f:
    ai_pose_e2 $0000
ai_pc_3191:
    ai_ret_00
ai_pc_3192:
    ai_move_toward_e4 $0000, $0005
ai_pc_3195:
    ai_if_field_gt_30_short $0080, $006D, $0000, $3195, $31AF
ai_pc_319a:
    ai_if_tgt_not_lane_h64_6f_short $319A, $31AC
ai_pc_319c:
    ai_flash_fc
ai_pc_319d:
    ai_move_toward_e4 $0000, $0005
ai_pc_31a0:
    ai_call_ff $6B19
ai_pc_31a3:
    ai_flash_fc
ai_pc_31a4:
    ai_move_toward_e4 $0000, $0005
ai_pc_31a7:
    ai_call_ff $32B3
ai_pc_31aa:
    ai_jmp_01_short $31AA, $31AF
ai_pc_31ac:
    ai_call_ff $324F
ai_pc_31af:
    ai_call_ff $32C7
ai_pc_31b2:
    ai_ret_00
ai_pc_31b3:
    ai_move_toward_e4 $0000, $0005
ai_pc_31b6:
    ai_if_field_gt_30_short $0080, $006D, $0000, $31B6, $31DC
ai_pc_31bb:
    ai_move_toward_e4 $0000, $0005
ai_pc_31be:
    ai_if_tgt_not_lane_h64_6f_short $31BE, $31C8
ai_pc_31c0:
    ai_move_toward_card_be $0000, $0005
ai_pc_31c3:
    ai_call_ff $6B19
ai_pc_31c6:
    ai_jmp_01_short $31C6, $31DC
ai_pc_31c8:
    ai_if_tgt_not_lane_v64_66_short $31C8, $31D9
ai_pc_31ca:
    ai_if_tgt_not_above_75_short $31CA, $31D1
ai_pc_31cc:
    ai_call_ff $6A31
ai_pc_31cf:
    ai_jmp_01_short $31CF, $31D7
ai_pc_31d1:
    ai_move_toward_card_be $0000, $0005
ai_pc_31d4:
    ai_call_ff $6B19
ai_pc_31d7:
    ai_jmp_01_short $31D7, $31DC
ai_pc_31d9:
    ai_call_ff $324F
ai_pc_31dc:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_31df:
    ai_call_ff $32B3
ai_pc_31e2:
    ai_ret_00
ai_pc_31e3:
    ai_move_toward_e4 $0000, $0005
ai_pc_31e6:
    ai_if_field_gt_30_short $0080, $006D, $0000, $31E6, $3227
ai_pc_31eb:
    ai_move_toward_e4 $0000, $0005
ai_pc_31ee:
    ai_if_tgt_not_lane_h64_6f_short $31EE, $31F8
ai_pc_31f0:
    ai_move_toward_card_be $0000, $0005
ai_pc_31f3:
    ai_call_ff $6B19
ai_pc_31f6:
    ai_jmp_01_short $31F6, $3225
ai_pc_31f8:
    ai_if_tgt_not_lane_v64_66_short $31F8, $3209
ai_pc_31fa:
    ai_if_tgt_not_above_75_short $31FA, $3201
ai_pc_31fc:
    ai_call_ff $6A31
ai_pc_31ff:
    ai_jmp_01_short $31FF, $3207
ai_pc_3201:
    ai_move_toward_card_be $0000, $0005
ai_pc_3204:
    ai_call_ff $6B19
ai_pc_3207:
    ai_jmp_01_short $3207, $3225
ai_pc_3209:
    ai_rnd_var3_2c $0007
ai_pc_320b:
    ai_if_var3_nz_05_short $320B, $3212
ai_pc_320d:
    ai_call_ff $327D
ai_pc_3210:
    ai_jmp_01_short $3210, $3225
ai_pc_3212:
    ai_if_var3_ne_0d_short $0001, $3212, $321A
ai_pc_3215:
    ai_call_ff $3298
ai_pc_3218:
    ai_jmp_01_short $3218, $3225
ai_pc_321a:
    ai_if_var3_ne_0d_short $0002, $321A, $3222
ai_pc_321d:
    ai_call_ff $324F
ai_pc_3220:
    ai_jmp_01_short $3220, $3225
ai_pc_3222:
    ai_move_toward_e4 $0000, $0005
ai_pc_3225:
    ai_jmp_01_short $3225, $322A
ai_pc_3227:
    ai_move_toward_e4 $0000, $0005
ai_pc_322a:
    ai_ret_00
ai_pc_322b:
    ai_call_ff $6AE1
ai_pc_322e:
    ai_rnd_var3_2c $0004
ai_pc_3230:
    ai_if_var3_nz_05_short $3230, $3240
ai_pc_3232:
    ai_if_pos_same_9d_short $3232, $323A
ai_pc_3234:
    ai_pos_save_9f
ai_pc_3235:
    ai_move_toward_e4 $0002, $0000
ai_pc_3238:
    ai_jmp_01_short $3238, $323E
ai_pc_323a:
    ai_pos_save_9f
ai_pc_323b:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_323e:
    ai_jmp_01_short $323E, $324C
ai_pc_3240:
    ai_if_pos_same_9d_short $3240, $3248
ai_pc_3242:
    ai_pos_save_9f
ai_pc_3243:
    ai_move_toward_e4 $0004, $0000
ai_pc_3246:
    ai_jmp_01_short $3246, $324C
ai_pc_3248:
    ai_pos_save_9f
ai_pc_3249:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_324c:
    ai_if_tgt_not_within_64_56_short $324C, $322B
ai_pc_324e:
    ai_ret_00
ai_pc_324f:
    ai_if_obj_outside_5f_short $0080, $324F, $327C
ai_pc_3252:
    ai_move_toward_e4 $0000, $0005
ai_pc_3255:
    ai_rnd_var3_2c $0003
ai_pc_3257:
    ai_if_var3_nz_05_short $3257, $327C
ai_pc_3259:
    ai_rnd_var3_2c $0002
ai_pc_325b:
    ai_if_var3_nz_05_short $325B, $3267
ai_pc_325d:
    ai_tgt2_cur_c1
ai_pc_325e:
    ai_cast_e9 $0005, $000C
ai_pc_3261:
    ai_tgt2_none_c0
ai_pc_3262:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_3265:
    ai_jmp_01_short $3265, $327C
ai_pc_3267:
    ai_if_var3_ne_0d_short $0001, $3267, $3274
ai_pc_326a:
    ai_tgt2_cur_c1
ai_pc_326b:
    ai_cast_e9 $0005, $000D
ai_pc_326e:
    ai_tgt2_none_c0
ai_pc_326f:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_3272:
    ai_jmp_01_short $3272, $327C
ai_pc_3274:
    ai_tgt2_cur_c1
ai_pc_3275:
    ai_cast_e9 $0005, $0010
ai_pc_3278:
    ai_tgt2_none_c0
ai_pc_3279:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_327c:
    ai_ret_00
ai_pc_327d:
    ai_rnd_var3_2c $0001
ai_pc_327f:
    ai_call_ff $6AE1
ai_pc_3282:
    ai_if_pos_same_9d_short $3282, $328A
ai_pc_3284:
    ai_pos_save_9f
ai_pc_3285:
    ai_move_away_e6 $000E, $0000
ai_pc_3288:
    ai_jmp_01_short $3288, $328E
ai_pc_328a:
    ai_pos_save_9f
ai_pc_328b:
    ai_move_away_alt_fe $000E, $0000
ai_pc_328e:
    ai_if_var3_nz_05_short $328E, $3295
ai_pc_3290:
    ai_if_tgt_not_within_48_51_short $3290, $3295
ai_pc_3292:
    ai_jmp_01_long $3292, $3297
ai_pc_3295:
    ai_if_tgt_not_within_32_4c_short $3295, $327F
ai_pc_3297:
    ai_ret_00
ai_pc_3298:
    ai_rnd_var3_2c $0001
ai_pc_329a:
    ai_call_ff $6AE1
ai_pc_329d:
    ai_if_pos_same_9d_short $329D, $32A5
ai_pc_329f:
    ai_pos_save_9f
ai_pc_32a0:
    ai_move_toward_e4 $0004, $0000
ai_pc_32a3:
    ai_jmp_01_short $32A3, $32A9
ai_pc_32a5:
    ai_pos_save_9f
ai_pc_32a6:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_32a9:
    ai_if_var3_nz_05_short $32A9, $32B0
ai_pc_32ab:
    ai_if_tgt_not_within_48_51_short $32AB, $32B0
ai_pc_32ad:
    ai_jmp_01_long $32AD, $32B2
ai_pc_32b0:
    ai_if_tgt_not_within_32_4c_short $32B0, $329A
ai_pc_32b2:
    ai_ret_00
ai_pc_32b3:
    ai_if_tgt_not_within_48_51_short $32B3, $32C6
ai_pc_32b5:
    ai_call_ff $6AE1
ai_pc_32b8:
    ai_if_pos_same_9d_short $32B8, $32C0
ai_pc_32ba:
    ai_pos_save_9f
ai_pc_32bb:
    ai_move_away_e6 $0004, $0000
ai_pc_32be:
    ai_jmp_01_short $32BE, $32C4
ai_pc_32c0:
    ai_pos_save_9f
ai_pc_32c1:
    ai_move_away_alt_fe $0004, $0000
ai_pc_32c4:
    ai_jmp_01_short $32C4, $32B3
ai_pc_32c6:
    ai_ret_00
ai_pc_32c7:
    ai_move_toward_e4 $000E, $0000
ai_pc_32ca:
    ai_if_tgt_not_within_48_51_short $32CA, $32DD
ai_pc_32cc:
    ai_call_ff $6AE1
ai_pc_32cf:
    ai_if_pos_same_9d_short $32CF, $32D7
ai_pc_32d1:
    ai_pos_save_9f
ai_pc_32d2:
    ai_move_away_e6 $0002, $0000
ai_pc_32d5:
    ai_jmp_01_short $32D5, $32DB
ai_pc_32d7:
    ai_pos_save_9f
ai_pc_32d8:
    ai_move_away_alt_fe $0002, $0000
ai_pc_32db:
    ai_jmp_01_short $32DB, $32CA
ai_pc_32dd:
    ai_ret_00
ai_pc_32de:
    ai_call_ff $3309
ai_pc_32e1:
    ai_rnd_var3_2c $000F
ai_pc_32e3:
    ai_if_var3_nz_05_short $32E3, $32EA
ai_pc_32e5:
    ai_call_ff $672F
ai_pc_32e8:
    ai_jmp_01_short $32E8, $3301
ai_pc_32ea:
    ai_call_ff $6AE1
ai_pc_32ed:
    ai_call_ff $3354
ai_pc_32f0:
    ai_if_tgt_not_within_32_4c_short $32F0, $32F7
ai_pc_32f2:
    ai_call_ff $3310
ai_pc_32f5:
    ai_jmp_01_short $32F5, $3301
ai_pc_32f7:
    ai_if_tgt_not_within_64_56_short $32F7, $32FE
ai_pc_32f9:
    ai_call_ff $3322
ai_pc_32fc:
    ai_jmp_01_short $32FC, $3301
ai_pc_32fe:
    ai_call_ff $3342
ai_pc_3301:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $3301, $32E1
ai_pc_3306:
    ai_jmp_01_short $3306, $32E1
