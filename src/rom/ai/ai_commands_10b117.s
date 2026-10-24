.setcpu "65816"
.segment "CODE"
.org $B117
.include "ai_command_macros.inc"
ai_pc_6202:
    ai_if_field_gt_30_short $0080, $002C, $00FE, $6202, $623A
ai_pc_6207:
    ai_call_ff $5913
ai_pc_620a:
    ai_if_tgt_not_within_64_56_short $620A, $622B
ai_pc_620c:
    ai_if_field_gt_30_short $0080, $006D, $0000, $620C, $6226
ai_pc_6211:
    ai_if_charge_set_f2_short $0000, $6211, $6221
ai_pc_6214:
    ai_call_ff $62E8
ai_pc_6217:
    ai_move_toward_e4 $0003, $0005
ai_pc_621a:
    ai_swing_plain_df
ai_pc_621b:
    ai_move_toward_e4 $0013, $0000
ai_pc_621e:
    ai_charge_start_f3
ai_pc_621f:
    ai_jmp_01_short $621F, $6224
ai_pc_6221:
    ai_call_ff $62FA
ai_pc_6224:
    ai_jmp_01_short $6224, $6229
ai_pc_6226:
    ai_call_ff $62FA
ai_pc_6229:
    ai_jmp_01_short $6229, $6238
ai_pc_622b:
    ai_if_field_gt_30_short $0080, $006D, $0000, $622B, $6235
ai_pc_6230:
    ai_call_ff $62C4
ai_pc_6233:
    ai_jmp_01_short $6233, $6238
ai_pc_6235:
    ai_move_toward_e4 $0000, $0005
ai_pc_6238:
    ai_jmp_01_short $6238, $6202
ai_pc_623a:
    ai_ret_00
ai_pc_623b:
    ai_if_field_gt_30_short $0080, $002C, $00FE, $623B, $6270
ai_pc_6240:
    ai_call_ff $5913
ai_pc_6243:
    ai_if_tgt_not_within_64_56_short $6243, $6261
ai_pc_6245:
    ai_if_field_gt_30_short $0080, $006D, $0000, $6245, $625C
ai_pc_624a:
    ai_if_charge_set_f2_short $0000, $624A, $6257
ai_pc_624d:
    ai_call_ff $6320
ai_pc_6250:
    ai_move_toward_e4 $0003, $0005
ai_pc_6253:
    ai_swing_plain_df
ai_pc_6254:
    ai_charge_start_f3
ai_pc_6255:
    ai_jmp_01_short $6255, $625A
ai_pc_6257:
    ai_call_ff $6332
ai_pc_625a:
    ai_jmp_01_short $625A, $625F
ai_pc_625c:
    ai_call_ff $6332
ai_pc_625f:
    ai_jmp_01_short $625F, $626E
ai_pc_6261:
    ai_if_field_gt_30_short $0080, $006D, $0000, $6261, $626B
ai_pc_6266:
    ai_call_ff $62C4
ai_pc_6269:
    ai_jmp_01_short $6269, $626E
ai_pc_626b:
    ai_move_toward_e4 $0000, $0005
ai_pc_626e:
    ai_jmp_01_short $626E, $623B
ai_pc_6270:
    ai_ret_00
ai_pc_6271:
    ai_if_field_gt_30_long $0080, $002C, $00FE, $6271, $62C3
ai_pc_6277:
    ai_call_ff $5913
ai_pc_627a:
    ai_if_tgt_not_within_64_56_short $627A, $62B3
ai_pc_627c:
    ai_if_field_gt_30_short $0080, $006D, $0000, $627C, $62A7
ai_pc_6281:
    ai_if_charge_set_f2_short $0000, $6281, $629B
ai_pc_6284:
    ai_if_tgt_not_lane_v64_66_short $6284, $628D
ai_pc_6286:
    ai_move_toward_card_be $0003, $0005
ai_pc_6289:
    ai_swing_plain_df
ai_pc_628a:
    ai_charge_start_f3
ai_pc_628b:
    ai_jmp_01_short $628B, $6299
ai_pc_628d:
    ai_if_tgt_not_lane_h64_6f_short $628D, $6296
ai_pc_628f:
    ai_move_toward_card_be $0003, $0005
ai_pc_6292:
    ai_swing_plain_df
ai_pc_6293:
    ai_charge_start_f3
ai_pc_6294:
    ai_jmp_01_short $6294, $6299
ai_pc_6296:
    ai_call_ff $593D
ai_pc_6299:
    ai_jmp_01_short $6299, $62A5
ai_pc_629b:
    ai_if_tgt_not_band_64_46_short $629B, $62A2
ai_pc_629d:
    ai_move_toward_card_be $0003, $0005
ai_pc_62a0:
    ai_jmp_01_short $62A0, $62A5
ai_pc_62a2:
    ai_call_ff $6355
ai_pc_62a5:
    ai_jmp_01_short $62A5, $62B1
ai_pc_62a7:
    ai_if_tgt_not_band_64_46_short $62A7, $62AE
ai_pc_62a9:
    ai_move_toward_card_be $0003, $0005
ai_pc_62ac:
    ai_jmp_01_short $62AC, $62B1
ai_pc_62ae:
    ai_call_ff $6355
ai_pc_62b1:
    ai_jmp_01_short $62B1, $62C0
ai_pc_62b3:
    ai_if_field_gt_30_short $0080, $006D, $0000, $62B3, $62BD
ai_pc_62b8:
    ai_call_ff $62D6
ai_pc_62bb:
    ai_jmp_01_short $62BB, $62C0
ai_pc_62bd:
    ai_move_toward_card_be $0000, $0005
ai_pc_62c0:
    ai_jmp_01_long $62C0, $6271
ai_pc_62c3:
    ai_ret_00
ai_pc_62c4:
    ai_call_ff $5913
ai_pc_62c7:
    ai_if_pos_same_9d_short $62C7, $62CF
ai_pc_62c9:
    ai_pos_save_9f
ai_pc_62ca:
    ai_move_toward_e4 $000B, $000A
ai_pc_62cd:
    ai_jmp_01_short $62CD, $62D3
ai_pc_62cf:
    ai_pos_save_9f
ai_pc_62d0:
    ai_move_toward_alt_fd $000B, $000A
ai_pc_62d3:
    ai_if_tgt_not_within_64_56_short $62D3, $62C4
ai_pc_62d5:
    ai_ret_00
ai_pc_62d6:
    ai_call_ff $5913
ai_pc_62d9:
    ai_if_pos_same_9d_short $62D9, $62E1
ai_pc_62db:
    ai_pos_save_9f
ai_pc_62dc:
    ai_move_toward_card_be $000B, $000A
ai_pc_62df:
    ai_jmp_01_short $62DF, $62E5
ai_pc_62e1:
    ai_pos_save_9f
ai_pc_62e2:
    ai_move_toward_alt_fd $000B, $000A
ai_pc_62e5:
    ai_if_tgt_not_within_64_56_short $62E5, $62D6
ai_pc_62e7:
    ai_ret_00
ai_pc_62e8:
    ai_call_ff $5913
ai_pc_62eb:
    ai_if_pos_same_9d_short $62EB, $62F3
ai_pc_62ed:
    ai_pos_save_9f
ai_pc_62ee:
    ai_move_toward_e4 $000B, $000A
ai_pc_62f1:
    ai_jmp_01_short $62F1, $62F7
ai_pc_62f3:
    ai_pos_save_9f
ai_pc_62f4:
    ai_move_toward_alt_fd $000B, $000A
ai_pc_62f7:
    ai_if_tgt_not_within_32_4c_short $62F7, $62E8
ai_pc_62f9:
    ai_ret_00
ai_pc_62fa:
    ai_if_tgt_not_within_48_51_short $62FA, $631F
ai_pc_62fc:
    ai_call_ff $5913
ai_pc_62ff:
    ai_if_tgt_not_within_32_4c_short $62FF, $6311
ai_pc_6301:
    ai_if_field_gt_30_short $0080, $006D, $0000, $6301, $6311
ai_pc_6306:
    ai_if_charge_set_f2_short $0000, $6306, $6311
ai_pc_6309:
    ai_move_toward_e4 $0003, $0005
ai_pc_630c:
    ai_swing_plain_df
ai_pc_630d:
    ai_move_toward_e4 $0013, $0000
ai_pc_6310:
    ai_charge_start_f3
ai_pc_6311:
    ai_if_pos_same_9d_short $6311, $6319
ai_pc_6313:
    ai_pos_save_9f
ai_pc_6314:
    ai_move_toward_e4 $000C, $000A
ai_pc_6317:
    ai_jmp_01_short $6317, $631D
ai_pc_6319:
    ai_pos_save_9f
ai_pc_631a:
    ai_move_toward_alt_fd $000C, $000A
ai_pc_631d:
    ai_jmp_01_short $631D, $62FA
ai_pc_631f:
    ai_ret_00
ai_pc_6320:
    ai_call_ff $5913
ai_pc_6323:
    ai_if_pos_same_9d_short $6323, $632B
ai_pc_6325:
    ai_pos_save_9f
ai_pc_6326:
    ai_move_toward_e4 $000B, $000A
ai_pc_6329:
    ai_jmp_01_short $6329, $632F
ai_pc_632b:
    ai_pos_save_9f
ai_pc_632c:
    ai_move_toward_alt_fd $000B, $000A
ai_pc_632f:
    ai_if_tgt_not_within_32_4c_short $632F, $6320
ai_pc_6331:
    ai_ret_00
ai_pc_6332:
    ai_if_tgt_not_within_48_51_short $6332, $6354
ai_pc_6334:
    ai_call_ff $5913
ai_pc_6337:
    ai_if_tgt_not_within_32_4c_short $6337, $6346
ai_pc_6339:
    ai_if_field_gt_30_short $0080, $006D, $0000, $6339, $6346
ai_pc_633e:
    ai_if_charge_set_f2_short $0000, $633E, $6346
ai_pc_6341:
    ai_move_toward_e4 $0003, $0005
ai_pc_6344:
    ai_swing_plain_df
ai_pc_6345:
    ai_charge_start_f3
ai_pc_6346:
    ai_if_pos_same_9d_short $6346, $634E
ai_pc_6348:
    ai_pos_save_9f
ai_pc_6349:
    ai_move_toward_e4 $000C, $000A
ai_pc_634c:
    ai_jmp_01_short $634C, $6352
ai_pc_634e:
    ai_pos_save_9f
ai_pc_634f:
    ai_move_toward_alt_fd $000C, $000A
ai_pc_6352:
    ai_jmp_01_short $6352, $6332
ai_pc_6354:
    ai_ret_00
ai_pc_6355:
    ai_if_tgt_not_within_48_51_short $6355, $6377
ai_pc_6357:
    ai_call_ff $5913
ai_pc_635a:
    ai_if_tgt_not_within_48_51_short $635A, $6369
ai_pc_635c:
    ai_if_field_gt_30_short $0080, $006D, $0000, $635C, $6369
ai_pc_6361:
    ai_if_charge_set_f2_short $0000, $6361, $6369
ai_pc_6364:
    ai_move_toward_e4 $0003, $0005
ai_pc_6367:
    ai_swing_plain_df
ai_pc_6368:
    ai_charge_start_f3
ai_pc_6369:
    ai_if_pos_same_9d_short $6369, $6371
ai_pc_636b:
    ai_pos_save_9f
ai_pc_636c:
    ai_move_toward_card_be $000C, $000A
ai_pc_636f:
    ai_jmp_01_short $636F, $6375
ai_pc_6371:
    ai_pos_save_9f
ai_pc_6372:
    ai_move_toward_alt_fd $000C, $000A
ai_pc_6375:
    ai_jmp_01_short $6375, $6355
ai_pc_6377:
    ai_ret_00
