.setcpu "65816"
.segment "CODE"
.org $821E
.include "ai_command_macros.inc"
ai_pc_3309:
    ai_pose_e2 $0000
ai_pc_330b:
    ai_pose_e2 $0006
ai_pc_330d:
    ai_set_var1_26 $0003
ai_pc_330f:
    ai_ret_00
ai_pc_3310:
    ai_move_toward_e4 $0000, $0000
ai_pc_3313:
    ai_if_field_gt_30_short $0080, $006D, $0000, $3313, $331E
ai_pc_3318:
    ai_move_toward_e4 $0000, $0000
ai_pc_331b:
    ai_call_ff $6B19
ai_pc_331e:
    ai_call_ff $06E9
ai_pc_3321:
    ai_ret_00
ai_pc_3322:
    ai_move_toward_e4 $0000, $0000
ai_pc_3325:
    ai_if_field_gt_30_short $0080, $006D, $0000, $3325, $333E
ai_pc_332a:
    ai_rnd_var3_2c $000F
ai_pc_332c:
    ai_if_var3_nz_05_short $332C, $3339
ai_pc_332e:
    ai_call_ff $3363
ai_pc_3331:
    ai_move_toward_e4 $0000, $0005
ai_pc_3334:
    ai_call_ff $6B19
ai_pc_3337:
    ai_jmp_01_short $3337, $333C
ai_pc_3339:
    ai_move_toward_e4 $0000, $0000
ai_pc_333c:
    ai_jmp_01_short $333C, $3341
ai_pc_333e:
    ai_move_toward_e4 $0000, $0000
ai_pc_3341:
    ai_ret_00
ai_pc_3342:
    ai_call_ff $6AE1
ai_pc_3345:
    ai_rnd_var3_2c $0002
ai_pc_3347:
    ai_if_var3_nz_05_short $3347, $334E
ai_pc_3349:
    ai_call_ff $22E7
ai_pc_334c:
    ai_jmp_01_short $334C, $3351
ai_pc_334e:
    ai_call_ff $22CD
ai_pc_3351:
    ai_if_tgt_not_within_64_56_short $3351, $3342
ai_pc_3353:
    ai_ret_00
ai_pc_3354:
    ai_if_obj_outside_5f_short $0080, $3354, $3362
ai_pc_3357:
    ai_if_var1_lt_17_short $0001, $3357, $3362
ai_pc_335a:
    ai_if_crowd_gt_f5_short $0002, $335A, $3362
ai_pc_335d:
    ai_pose_e2 $0006
ai_pc_335f:
    ai_cmd43_ed $0038
ai_pc_3361:
    ai_dec_var1_1f
ai_pc_3362:
    ai_ret_00
ai_pc_3363:
    ai_call_ff $6AE1
ai_pc_3366:
    ai_if_pos_same_9d_short $3366, $336E
ai_pc_3368:
    ai_pos_save_9f
ai_pc_3369:
    ai_move_toward_e4 $0002, $000A
ai_pc_336c:
    ai_jmp_01_short $336C, $3372
ai_pc_336e:
    ai_pos_save_9f
ai_pc_336f:
    ai_move_toward_alt_fd $0002, $000A
ai_pc_3372:
    ai_if_tgt_not_within_16_34_short $3372, $3363
ai_pc_3374:
    ai_ret_00
ai_pc_3375:
    ai_call_ff $339D
ai_pc_3378:
    ai_rnd_var3_2c $000F
ai_pc_337a:
    ai_if_var3_nz_05_short $337A, $3381
ai_pc_337c:
    ai_call_ff $344A
ai_pc_337f:
    ai_jmp_01_short $337F, $3395
ai_pc_3381:
    ai_call_ff $6AE1
ai_pc_3384:
    ai_if_tgt_not_within_48_51_short $3384, $338B
ai_pc_3386:
    ai_call_ff $33F4
ai_pc_3389:
    ai_jmp_01_short $3389, $3395
ai_pc_338b:
    ai_if_tgt_not_within_64_56_short $338B, $3392
ai_pc_338d:
    ai_call_ff $33A0
ai_pc_3390:
    ai_jmp_01_short $3390, $3395
ai_pc_3392:
    ai_call_ff $3420
ai_pc_3395:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $3395, $3378
ai_pc_339a:
    ai_jmp_01_short $339A, $3378
