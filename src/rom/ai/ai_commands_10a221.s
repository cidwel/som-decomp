.setcpu "65816"
.segment "CODE"
.org $A221
.include "ai_command_macros.inc"
ai_pc_530c:
    ai_pose_e2 $0001
ai_pc_530e:
    ai_pose_e2 $0000
ai_pc_5310:
    ai_call_ff $544E
ai_pc_5313:
    ai_ret_00
ai_pc_5314:
    ai_move_toward_e4 $000E, $0000
ai_pc_5317:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5317, $5325
ai_pc_531c:
    ai_move_toward_e4 $0003, $0005
ai_pc_531f:
    ai_call_ff $6B23
ai_pc_5322:
    ai_move_toward_e4 $000E, $0000
ai_pc_5325:
    ai_call_ff $5480
ai_pc_5328:
    ai_ret_00
ai_pc_5329:
    ai_move_toward_e4 $0000, $0005
ai_pc_532c:
    ai_if_field_gt_30_short $0080, $006D, $0000, $532C, $5337
ai_pc_5331:
    ai_move_toward_e4 $0003, $0005
ai_pc_5334:
    ai_call_ff $6B23
ai_pc_5337:
    ai_call_ff $5480
ai_pc_533a:
    ai_ret_00
ai_pc_533b:
    ai_move_toward_e4 $0000, $0005
ai_pc_533e:
    ai_if_field_gt_30_short $0080, $006D, $0000, $533E, $534F
ai_pc_5343:
    ai_rnd_var3_2c $0001
ai_pc_5345:
    ai_if_var3_nz_05_short $5345, $5349
ai_pc_5347:
    ai_pose_e2 $000B
ai_pc_5349:
    ai_move_toward_e4 $0003, $0005
ai_pc_534c:
    ai_call_ff $6B23
ai_pc_534f:
    ai_move_toward_e4 $0000, $0005
ai_pc_5352:
    ai_ret_00
ai_pc_5353:
    ai_move_toward_e4 $0000, $0005
ai_pc_5356:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5356, $5395
ai_pc_535b:
    ai_rnd_var3_2c $000F
ai_pc_535d:
    ai_if_var3_gt_15_short $0002, $535D, $536D
ai_pc_5360:
    ai_flash_fc
ai_pc_5361:
    ai_move_toward_e4 $0003, $0005
ai_pc_5364:
    ai_call_ff $6B23
ai_pc_5367:
    ai_flash_fc
ai_pc_5368:
    ai_move_toward_e4 $0000, $0005
ai_pc_536b:
    ai_jmp_01_short $536B, $5393
ai_pc_536d:
    ai_if_var3_gt_15_short $0004, $536D, $5375
ai_pc_5370:
    ai_call_ff $53C6
ai_pc_5373:
    ai_jmp_01_short $5373, $5393
ai_pc_5375:
    ai_if_var3_gt_15_short $0006, $5375, $537D
ai_pc_5378:
    ai_call_ff $53F6
ai_pc_537b:
    ai_jmp_01_short $537B, $5393
ai_pc_537d:
    ai_if_var3_gt_15_short $0009, $537D, $5388
ai_pc_5380:
    ai_move_toward_e4 $0003, $0005
ai_pc_5383:
    ai_call_ff $6B23
ai_pc_5386:
    ai_jmp_01_short $5386, $5393
ai_pc_5388:
    ai_if_var3_gt_15_short $000B, $5388, $5390
ai_pc_538b:
    ai_call_ff $545C
ai_pc_538e:
    ai_jmp_01_short $538E, $5393
ai_pc_5390:
    ai_move_toward_e4 $0003, $0005
ai_pc_5393:
    ai_jmp_01_short $5393, $5398
ai_pc_5395:
    ai_move_toward_e4 $0000, $0005
ai_pc_5398:
    ai_ret_00
ai_pc_5399:
    ai_rnd_var3_2c $0002
ai_pc_539b:
    ai_if_var3_nz_05_short $539B, $53A2
ai_pc_539d:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_53a0:
    ai_jmp_01_short $53A0, $53C2
ai_pc_53a2:
    ai_if_var3_ne_0d_short $0001, $53A2, $53BC
ai_pc_53a5:
    ai_if_field_gt_30_short $0080, $006D, $0000, $53A5, $53B7
ai_pc_53aa:
    ai_flash_fc
ai_pc_53ab:
    ai_move_toward_e4 $0003, $0005
ai_pc_53ae:
    ai_call_ff $6B23
ai_pc_53b1:
    ai_flash_fc
ai_pc_53b2:
    ai_move_toward_e4 $0000, $0005
ai_pc_53b5:
    ai_jmp_01_short $53B5, $53BA
ai_pc_53b7:
    ai_move_toward_e4 $0000, $0005
ai_pc_53ba:
    ai_jmp_01_short $53BA, $53C2
ai_pc_53bc:
    ai_move_toward_e4 $0000, $0005
ai_pc_53bf:
    ai_call_ff $544E
ai_pc_53c2:
    ai_call_ff $546E
ai_pc_53c5:
    ai_ret_00
ai_pc_53c6:
    ai_pose_e2 $0005
ai_pc_53c8:
    ai_call_ff $6AE1
ai_pc_53cb:
    ai_pose_e2 $0007
ai_pc_53cd:
    ai_if_tgt_not_beyond_64_5a_short $53CD, $53E9
ai_pc_53cf:
    ai_if_obj_outside_5f_short $0080, $53CF, $53E4
ai_pc_53d2:
    ai_rnd_var3_2c $0007
ai_pc_53d4:
    ai_if_var3_nz_05_short $53D4, $53E0
ai_pc_53d6:
    ai_tgt2_cur_c1
ai_pc_53d7:
    ai_cast_e9 $0006, $000D
ai_pc_53da:
    ai_tgt2_none_c0
ai_pc_53db:
    ai_turn_facing_e3 $0000, $0078
ai_pc_53de:
    ai_jmp_01_short $53DE, $53E2
ai_pc_53e0:
    ai_pose_e2 $0007
ai_pc_53e2:
    ai_jmp_01_short $53E2, $53E6
ai_pc_53e4:
    ai_pose_e2 $0007
ai_pc_53e6:
    ai_jmp_01_long $53E6, $53EB
ai_pc_53e9:
    ai_if_tgt_not_within_32_4c_short $53E9, $53C8
ai_pc_53eb:
    ai_pose_e2 $0008
ai_pc_53ed:
    ai_if_tgt_not_within_48_51_short $53ED, $53F5
ai_pc_53ef:
    ai_move_toward_e4 $0003, $0005
ai_pc_53f2:
    ai_call_ff $6B23
ai_pc_53f5:
    ai_ret_00
ai_pc_53f6:
    ai_move_toward_e4 $0000, $0000
ai_pc_53f9:
    ai_move_toward_e4 $0003, $0000
ai_pc_53fc:
    ai_if_tgt_not_within_64_56_long $53FC, $544D
ai_pc_53ff:
    ai_call_ff $6AE1
ai_pc_5402:
    ai_if_field_gt_30_short $0080, $0038, $0000, $5402, $540F
ai_pc_5407:
    ai_tgt2_self_c4
ai_pc_5408:
    ai_cast_e9 $0006, $0022
ai_pc_540b:
    ai_tgt2_none_c0
ai_pc_540c:
    ai_turn_facing_e3 $0000, $003C
ai_pc_540f:
    ai_hop_e0 $0001, $0000, $0005
ai_pc_5413:
    ai_hop_e0 $0004, $0000, $0005
ai_pc_5417:
    ai_hop_e0 $0002, $0000, $0005
ai_pc_541b:
    ai_hop_e0 $0008, $0000, $0005
ai_pc_541f:
    ai_if_field_gt_30_short $0080, $006D, $0000, $541F, $544A
ai_pc_5424:
    ai_if_tgt_not_within_32_4c_short $5424, $542E
ai_pc_5426:
    ai_move_toward_e4 $0003, $0005
ai_pc_5429:
    ai_call_ff $6B23
ai_pc_542c:
    ai_jmp_01_short $542C, $544A
ai_pc_542e:
    ai_if_tgt_not_lane_v64_66_short $542E, $543D
ai_pc_5430:
    ai_flash_fc
ai_pc_5431:
    ai_move_toward_e4 $0003, $0005
ai_pc_5434:
    ai_call_ff $6B23
ai_pc_5437:
    ai_flash_fc
ai_pc_5438:
    ai_move_toward_e4 $0000, $0005
ai_pc_543b:
    ai_jmp_01_short $543B, $544A
ai_pc_543d:
    ai_if_tgt_not_lane_h64_6f_short $543D, $544A
ai_pc_543f:
    ai_flash_fc
ai_pc_5440:
    ai_move_toward_e4 $0003, $0005
ai_pc_5443:
    ai_call_ff $6B23
ai_pc_5446:
    ai_flash_fc
ai_pc_5447:
    ai_move_toward_e4 $0000, $0005
ai_pc_544a:
    ai_jmp_01_long $544A, $53FC
ai_pc_544d:
    ai_ret_00
ai_pc_544e:
    ai_if_field_gt_30_short $0080, $001D, $0000, $544E, $545B
ai_pc_5453:
    ai_tgt2_self_c4
ai_pc_5454:
    ai_cast_e9 $0006, $0003
ai_pc_5457:
    ai_tgt2_none_c0
ai_pc_5458:
    ai_turn_facing_e3 $0000, $003C
ai_pc_545b:
    ai_ret_00
ai_pc_545c:
    ai_call_ff $6AE1
ai_pc_545f:
    ai_if_pos_same_9d_short $545F, $5467
ai_pc_5461:
    ai_pos_save_9f
ai_pc_5462:
    ai_move_toward_e4 $0002, $0000
ai_pc_5465:
    ai_jmp_01_short $5465, $546B
ai_pc_5467:
    ai_pos_save_9f
ai_pc_5468:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_546b:
    ai_if_tgt_not_within_32_4c_short $546B, $545C
ai_pc_546d:
    ai_ret_00
ai_pc_546e:
    ai_call_ff $6AE1
ai_pc_5471:
    ai_if_pos_same_9d_short $5471, $5479
ai_pc_5473:
    ai_pos_save_9f
ai_pc_5474:
    ai_move_toward_e4 $0001, $000F
ai_pc_5477:
    ai_jmp_01_short $5477, $547D
ai_pc_5479:
    ai_pos_save_9f
ai_pc_547a:
    ai_move_toward_e4 $0001, $000F
ai_pc_547d:
    ai_if_tgt_not_within_64_56_short $547D, $546E
ai_pc_547f:
    ai_ret_00
ai_pc_5480:
    ai_if_tgt_not_within_32_4c_short $5480, $54A0
ai_pc_5482:
    ai_call_ff $6AE1
ai_pc_5485:
    ai_if_pos_same_9d_short $5485, $548D
ai_pc_5487:
    ai_pos_save_9f
ai_pc_5488:
    ai_move_toward_e4 $0005, $000A
ai_pc_548b:
    ai_jmp_01_short $548B, $5491
ai_pc_548d:
    ai_pos_save_9f
ai_pc_548e:
    ai_move_toward_alt_fd $0005, $000A
ai_pc_5491:
    ai_if_tgt_not_within_32_4c_short $5491, $549E
ai_pc_5493:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5493, $549E
ai_pc_5498:
    ai_move_toward_e4 $0003, $0000
ai_pc_549b:
    ai_call_ff $6B23
ai_pc_549e:
    ai_jmp_01_short $549E, $5480
ai_pc_54a0:
    ai_ret_00
ai_pc_54a1:
    ai_rnd_var3_2c $0003
ai_pc_54a3:
    ai_set_var2_27 $0004
ai_pc_54a5:
    ai_pos_save_9f
ai_pc_54a6:
    ai_if_var3_nz_05_short $54A6, $54AE
ai_pc_54a8:
    ai_hop_e0 $0008, $0004, $000A
ai_pc_54ac:
    ai_jmp_01_short $54AC, $54C4
ai_pc_54ae:
    ai_if_var3_ne_0d_short $0001, $54AE, $54B7
ai_pc_54b1:
    ai_hop_e0 $0004, $0004, $000A
ai_pc_54b5:
    ai_jmp_01_short $54B5, $54C4
ai_pc_54b7:
    ai_if_var3_ne_0d_short $0002, $54B7, $54C0
ai_pc_54ba:
    ai_hop_e0 $0001, $0004, $000A
ai_pc_54be:
    ai_jmp_01_short $54BE, $54C4
ai_pc_54c0:
    ai_hop_e0 $0002, $0004, $000A
ai_pc_54c4:
    ai_if_pos_moved_9e_short $54C4, $54C9
ai_pc_54c6:
    ai_jmp_01_long $54C6, $54CC
ai_pc_54c9:
    ai_dec_var2_20
ai_pc_54ca:
    ai_if_var2_nz_04_short $54CA, $54A5
ai_pc_54cc:
    ai_ret_00
ai_pc_54cd:
    ai_call_ff $6516
ai_pc_54d0:
    ai_call_ff $6519
ai_pc_54d3:
    ai_jmp_01_short $54D3, $54D0
