.setcpu "65816"
.segment "CODE"
.org $9131
.include "ai_command_macros.inc"
ai_pc_421c:
    ai_pose_e2 $0000
ai_pc_421e:
    ai_rnd_var3_2c $0001
ai_pc_4220:
    ai_if_var3_nz_05_short $4220, $4227
ai_pc_4222:
    ai_tgt2_self_c4
ai_pc_4223:
    ai_cast_e9 $0004, $0005
ai_pc_4226:
    ai_tgt2_none_c0
ai_pc_4227:
    ai_ret_00
ai_pc_4228:
    ai_call_ff $4334
ai_pc_422b:
    ai_move_toward_e4 $000E, $0000
ai_pc_422e:
    ai_call_ff $4320
ai_pc_4231:
    ai_ret_00
ai_pc_4232:
    ai_call_ff $4334
ai_pc_4235:
    ai_call_ff $4320
ai_pc_4238:
    ai_ret_00
ai_pc_4239:
    ai_move_toward_card_be $0000, $0000
ai_pc_423c:
    ai_if_field_gt_30_long $0080, $006D, $0000, $423C, $42A6
ai_pc_4242:
    ai_rnd_var3_2c $000F
ai_pc_4244:
    ai_if_var3_nz_05_short $4244, $425D
ai_pc_4246:
    ai_move_toward_card_be $0000, $0000
ai_pc_4249:
    ai_if_tgt_not_lane_v64_66_short $4249, $4250
ai_pc_424b:
    ai_call_ff $4305
ai_pc_424e:
    ai_jmp_01_short $424E, $425A
ai_pc_4250:
    ai_if_tgt_not_lane_h64_6f_short $4250, $4257
ai_pc_4252:
    ai_call_ff $4305
ai_pc_4255:
    ai_jmp_01_short $4255, $425A
ai_pc_4257:
    ai_move_toward_card_be $0000, $0000
ai_pc_425a:
    ai_jmp_01_long $425A, $42A4
ai_pc_425d:
    ai_if_var3_ne_0d_short $0001, $425D, $4276
ai_pc_4260:
    ai_move_toward_card_be $0000, $0000
ai_pc_4263:
    ai_if_tgt_not_lane_v64_66_short $4263, $426A
ai_pc_4265:
    ai_call_ff $42EA
ai_pc_4268:
    ai_jmp_01_short $4268, $4274
ai_pc_426a:
    ai_if_tgt_not_lane_h64_6f_short $426A, $4271
ai_pc_426c:
    ai_call_ff $42EA
ai_pc_426f:
    ai_jmp_01_short $426F, $4274
ai_pc_4271:
    ai_move_toward_card_be $0000, $0000
ai_pc_4274:
    ai_jmp_01_short $4274, $42A4
ai_pc_4276:
    ai_if_var3_ne_0d_short $0002, $4276, $4294
ai_pc_4279:
    ai_move_toward_card_be $0000, $0000
ai_pc_427c:
    ai_rnd_var3_2c $0002
ai_pc_427e:
    ai_if_var3_nz_05_short $427E, $428F
ai_pc_4280:
    ai_if_obj_outside_5f_short $0080, $4280, $428A
ai_pc_4283:
    ai_tgt2_cur_c1
ai_pc_4284:
    ai_cast_e9 $0004, $0001
ai_pc_4287:
    ai_tgt2_none_c0
ai_pc_4288:
    ai_jmp_01_short $4288, $428D
ai_pc_428a:
    ai_move_toward_card_be $0000, $0000
ai_pc_428d:
    ai_jmp_01_short $428D, $4292
ai_pc_428f:
    ai_move_toward_card_be $0000, $0000
ai_pc_4292:
    ai_jmp_01_short $4292, $42A4
ai_pc_4294:
    ai_if_var3_ne_0d_short $0003, $4294, $42A1
ai_pc_4297:
    ai_move_toward_card_be $0000, $0000
ai_pc_429a:
    ai_tgt2_self_c4
ai_pc_429b:
    ai_cast_e9 $0004, $0005
ai_pc_429e:
    ai_tgt2_none_c0
ai_pc_429f:
    ai_jmp_01_short $429F, $42A4
ai_pc_42a1:
    ai_move_toward_card_be $0000, $0000
ai_pc_42a4:
    ai_jmp_01_short $42A4, $42A9
ai_pc_42a6:
    ai_move_toward_card_be $0000, $0000
ai_pc_42a9:
    ai_ret_00
ai_pc_42aa:
    ai_call_ff $6AE1
ai_pc_42ad:
    ai_rnd_var3_2c $0003
ai_pc_42af:
    ai_if_var3_nz_05_short $42AF, $42B6
ai_pc_42b1:
    ai_call_ff $42BC
ai_pc_42b4:
    ai_jmp_01_short $42B4, $42B9
ai_pc_42b6:
    ai_call_ff $42D3
ai_pc_42b9:
    ai_if_tgt_not_within_64_56_short $42B9, $42AA
ai_pc_42bb:
    ai_ret_00
ai_pc_42bc:
    ai_set_var2_27 $0002
ai_pc_42be:
    ai_if_pos_same_9d_short $42BE, $42C6
ai_pc_42c0:
    ai_pos_save_9f
ai_pc_42c1:
    ai_move_toward_card_be $0001, $000A
ai_pc_42c4:
    ai_jmp_01_short $42C4, $42CA
ai_pc_42c6:
    ai_pos_save_9f
ai_pc_42c7:
    ai_move_toward_alt_fd $0001, $000A
ai_pc_42ca:
    ai_dec_var2_20
ai_pc_42cb:
    ai_if_var2_nz_04_short $42CB, $42D0
ai_pc_42cd:
    ai_jmp_01_long $42CD, $42D2
ai_pc_42d0:
    ai_if_tgt_not_within_64_56_short $42D0, $42BE
ai_pc_42d2:
    ai_ret_00
ai_pc_42d3:
    ai_set_var2_27 $0002
ai_pc_42d5:
    ai_if_pos_same_9d_short $42D5, $42DD
ai_pc_42d7:
    ai_pos_save_9f
ai_pc_42d8:
    ai_move_toward_card_be $0004, $000F
ai_pc_42db:
    ai_jmp_01_short $42DB, $42E1
ai_pc_42dd:
    ai_pos_save_9f
ai_pc_42de:
    ai_move_toward_alt_fd $0004, $000F
ai_pc_42e1:
    ai_dec_var2_20
ai_pc_42e2:
    ai_if_var2_nz_04_short $42E2, $42E7
ai_pc_42e4:
    ai_jmp_01_long $42E4, $42E9
ai_pc_42e7:
    ai_if_tgt_not_within_64_56_short $42E7, $42D5
ai_pc_42e9:
    ai_ret_00
ai_pc_42ea:
    ai_rnd_var3_2c $0001
ai_pc_42ec:
    ai_call_ff $6AE1
ai_pc_42ef:
    ai_if_pos_same_9d_short $42EF, $42F7
ai_pc_42f1:
    ai_pos_save_9f
ai_pc_42f2:
    ai_move_toward_card_be $0004, $000F
ai_pc_42f5:
    ai_jmp_01_short $42F5, $42FB
ai_pc_42f7:
    ai_pos_save_9f
ai_pc_42f8:
    ai_move_toward_alt_fd $0004, $000F
ai_pc_42fb:
    ai_if_var3_nz_05_short $42FB, $4302
ai_pc_42fd:
    ai_if_tgt_not_within_32_4c_short $42FD, $4302
ai_pc_42ff:
    ai_jmp_01_long $42FF, $4304
ai_pc_4302:
    ai_if_tgt_not_within_48_51_short $4302, $42EC
ai_pc_4304:
    ai_ret_00
ai_pc_4305:
    ai_rnd_var3_2c $0001
ai_pc_4307:
    ai_call_ff $6AE1
ai_pc_430a:
    ai_if_pos_same_9d_short $430A, $4312
ai_pc_430c:
    ai_pos_save_9f
ai_pc_430d:
    ai_move_toward_card_be $0002, $000A
ai_pc_4310:
    ai_jmp_01_short $4310, $4316
ai_pc_4312:
    ai_pos_save_9f
ai_pc_4313:
    ai_move_toward_alt_fd $0002, $000A
ai_pc_4316:
    ai_if_var3_nz_05_short $4316, $431D
ai_pc_4318:
    ai_if_tgt_not_within_32_4c_short $4318, $431D
ai_pc_431a:
    ai_jmp_01_long $431A, $431F
ai_pc_431d:
    ai_if_tgt_not_within_48_51_short $431D, $4307
ai_pc_431f:
    ai_ret_00
ai_pc_4320:
    ai_if_tgt_not_within_48_51_short $4320, $4333
ai_pc_4322:
    ai_call_ff $6AE1
ai_pc_4325:
    ai_if_pos_same_9d_short $4325, $432D
ai_pc_4327:
    ai_pos_save_9f
ai_pc_4328:
    ai_move_toward_card_be $0005, $000F
ai_pc_432b:
    ai_jmp_01_short $432B, $4331
ai_pc_432d:
    ai_pos_save_9f
ai_pc_432e:
    ai_move_toward_alt_fd $0005, $000F
ai_pc_4331:
    ai_jmp_01_short $4331, $4320
ai_pc_4333:
    ai_ret_00
ai_pc_4334:
    ai_move_toward_card_be $0000, $0000
ai_pc_4337:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4337, $436A
ai_pc_433c:
    ai_move_toward_card_be $0000, $0000
ai_pc_433f:
    ai_rnd_var3_2c $000F
ai_pc_4341:
    ai_if_var3_nz_05_short $4341, $4350
ai_pc_4343:
    ai_pose_e2 $0003
ai_pc_4345:
    ai_turn_facing_e3 $0008, $0000
ai_pc_4348:
    ai_move_toward_card_be $0004, $0000
ai_pc_434b:
    ai_move_toward_card_be $0005, $0000
ai_pc_434e:
    ai_jmp_01_short $434E, $436A
ai_pc_4350:
    ai_move_toward_card_be $0000, $0005
ai_pc_4353:
    ai_if_tgt_not_lane_v48_68_short $4353, $435D
ai_pc_4355:
    ai_move_toward_card_be $0000, $0005
ai_pc_4358:
    ai_call_ff $6B23
ai_pc_435b:
    ai_jmp_01_short $435B, $436A
ai_pc_435d:
    ai_if_tgt_not_lane_h48_71_short $435D, $4367
ai_pc_435f:
    ai_move_toward_card_be $0000, $0005
ai_pc_4362:
    ai_call_ff $6B23
ai_pc_4365:
    ai_jmp_01_short $4365, $436A
ai_pc_4367:
    ai_move_toward_card_be $0000, $0000
ai_pc_436a:
    ai_ret_00
ai_pc_436b:
    ai_call_ff $43A4
ai_pc_436e:
    ai_call_ff $6AE1
ai_pc_4371:
    ai_call_ff $44F8
ai_pc_4374:
    ai_rnd_var3_2c $000F
ai_pc_4376:
    ai_if_var3_nz_05_short $4376, $437D
ai_pc_4378:
    ai_call_ff $54A1
ai_pc_437b:
    ai_jmp_01_short $437B, $439C
ai_pc_437d:
    ai_if_tgt_not_within_16_34_short $437D, $4384
ai_pc_437f:
    ai_call_ff $43A7
ai_pc_4382:
    ai_jmp_01_short $4382, $439C
ai_pc_4384:
    ai_if_tgt_not_within_32_4c_short $4384, $438B
ai_pc_4386:
    ai_call_ff $43BC
ai_pc_4389:
    ai_jmp_01_short $4389, $439C
ai_pc_438b:
    ai_if_tgt_not_within_48_51_short $438B, $4392
ai_pc_438d:
    ai_call_ff $43E0
ai_pc_4390:
    ai_jmp_01_short $4390, $439C
ai_pc_4392:
    ai_if_tgt_not_within_64_56_short $4392, $4399
ai_pc_4394:
    ai_call_ff $4405
ai_pc_4397:
    ai_jmp_01_short $4397, $439C
ai_pc_4399:
    ai_call_ff $4457
ai_pc_439c:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $439C, $436E
ai_pc_43a1:
    ai_jmp_01_short $43A1, $436E
