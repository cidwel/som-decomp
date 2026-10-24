.setcpu "65816"
.segment "CODE"
.org $9035
.include "ai_command_macros.inc"
ai_pc_4120:
    ai_pose_e2 $0000
ai_pc_4122:
    ai_ret_00
ai_pc_4123:
    ai_move_toward_e4 $0000, $0000
ai_pc_4126:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4126, $413B
ai_pc_412b:
    ai_flash_fc
ai_pc_412c:
    ai_move_toward_e4 $0000, $0000
ai_pc_412f:
    ai_call_ff $6B23
ai_pc_4132:
    ai_flash_fc
ai_pc_4133:
    ai_move_toward_e4 $0000, $0005
ai_pc_4136:
    ai_call_ff $32B3
ai_pc_4139:
    ai_jmp_01_short $4139, $4141
ai_pc_413b:
    ai_call_ff $41DC
ai_pc_413e:
    ai_call_ff $41AB
ai_pc_4141:
    ai_ret_00
ai_pc_4142:
    ai_move_toward_e4 $0000, $0000
ai_pc_4145:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4145, $4166
ai_pc_414a:
    ai_move_toward_e4 $0000, $0000
ai_pc_414d:
    ai_if_tgt_not_lane_h64_6f_short $414D, $4157
ai_pc_414f:
    ai_move_toward_card_be $0000, $0000
ai_pc_4152:
    ai_call_ff $6B23
ai_pc_4155:
    ai_jmp_01_short $4155, $4166
ai_pc_4157:
    ai_if_tgt_not_lane_v64_66_short $4157, $4166
ai_pc_4159:
    ai_if_tgt_not_above_75_short $4159, $4160
ai_pc_415b:
    ai_call_ff $6A31
ai_pc_415e:
    ai_jmp_01_short $415E, $4166
ai_pc_4160:
    ai_move_toward_card_be $0000, $0000
ai_pc_4163:
    ai_call_ff $6B23
ai_pc_4166:
    ai_move_toward_alt_fd $000E, $0000
ai_pc_4169:
    ai_call_ff $32B3
ai_pc_416c:
    ai_ret_00
ai_pc_416d:
    ai_move_toward_e4 $0000, $0000
ai_pc_4170:
    ai_if_field_gt_30_short $0080, $006D, $0000, $4170, $41A7
ai_pc_4175:
    ai_move_toward_e4 $0000, $0000
ai_pc_4178:
    ai_if_tgt_not_lane_h64_6f_short $4178, $4182
ai_pc_417a:
    ai_move_toward_card_be $0000, $0000
ai_pc_417d:
    ai_call_ff $6B23
ai_pc_4180:
    ai_jmp_01_short $4180, $41A7
ai_pc_4182:
    ai_if_tgt_not_lane_v64_66_short $4182, $4193
ai_pc_4184:
    ai_if_tgt_not_above_75_short $4184, $418B
ai_pc_4186:
    ai_call_ff $6A31
ai_pc_4189:
    ai_jmp_01_short $4189, $4191
ai_pc_418b:
    ai_move_toward_card_be $0000, $0000
ai_pc_418e:
    ai_call_ff $6B23
ai_pc_4191:
    ai_jmp_01_short $4191, $41A7
ai_pc_4193:
    ai_rnd_var3_2c $000F
ai_pc_4195:
    ai_if_var3_nz_05_short $4195, $419C
ai_pc_4197:
    ai_call_ff $327D
ai_pc_419a:
    ai_jmp_01_short $419A, $41A7
ai_pc_419c:
    ai_if_var3_ne_0d_short $0001, $419C, $41A4
ai_pc_419f:
    ai_call_ff $3298
ai_pc_41a2:
    ai_jmp_01_short $41A2, $41A7
ai_pc_41a4:
    ai_move_toward_e4 $0000, $0000
ai_pc_41a7:
    ai_move_toward_e4 $0000, $0000
ai_pc_41aa:
    ai_ret_00
ai_pc_41ab:
    ai_if_obj_outside_5f_short $0080, $41AB, $41DB
ai_pc_41ae:
    ai_move_toward_e4 $0000, $0000
ai_pc_41b1:
    ai_if_word_gt_bd_short $0080, $0002, $0032, $0000, $41B1, $41C1
ai_pc_41b7:
    ai_tgt2_cur_c1
ai_pc_41b8:
    ai_cast_e9 $0005, $0024
ai_pc_41bb:
    ai_tgt2_none_c0
ai_pc_41bc:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_41bf:
    ai_jmp_01_short $41BF, $41DB
ai_pc_41c1:
    ai_rnd_var3_2c $000F
ai_pc_41c3:
    ai_if_var3_nz_05_short $41C3, $41DB
ai_pc_41c5:
    ai_rnd_var3_2c $0001
ai_pc_41c7:
    ai_if_var3_nz_05_short $41C7, $41D3
ai_pc_41c9:
    ai_tgt2_cur_c1
ai_pc_41ca:
    ai_cast_e9 $0005, $0007
ai_pc_41cd:
    ai_tgt2_none_c0
ai_pc_41ce:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_41d1:
    ai_jmp_01_short $41D1, $41DB
ai_pc_41d3:
    ai_tgt2_cur_c1
ai_pc_41d4:
    ai_cast_e9 $0005, $0006
ai_pc_41d7:
    ai_tgt2_none_c0
ai_pc_41d8:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_41db:
    ai_ret_00
ai_pc_41dc:
    ai_if_tgt_not_within_48_51_short $41DC, $41EF
ai_pc_41de:
    ai_call_ff $6AE1
ai_pc_41e1:
    ai_if_pos_same_9d_short $41E1, $41E9
ai_pc_41e3:
    ai_pos_save_9f
ai_pc_41e4:
    ai_move_toward_e4 $000E, $0000
ai_pc_41e7:
    ai_jmp_01_short $41E7, $41ED
ai_pc_41e9:
    ai_pos_save_9f
ai_pc_41ea:
    ai_move_toward_alt_fd $000E, $0000
ai_pc_41ed:
    ai_jmp_01_short $41ED, $41DC
ai_pc_41ef:
    ai_ret_00
ai_pc_41f0:
    ai_call_ff $421C
ai_pc_41f3:
    ai_rnd_var3_2c $000F
ai_pc_41f5:
    ai_if_var3_nz_05_short $41F5, $41FC
ai_pc_41f7:
    ai_call_ff $67B3
ai_pc_41fa:
    ai_jmp_01_short $41FA, $4214
ai_pc_41fc:
    ai_if_tgt_not_within_16_34_short $41FC, $4203
ai_pc_41fe:
    ai_call_ff $4228
ai_pc_4201:
    ai_jmp_01_short $4201, $4214
ai_pc_4203:
    ai_if_tgt_not_within_48_51_short $4203, $420A
ai_pc_4205:
    ai_call_ff $4232
ai_pc_4208:
    ai_jmp_01_short $4208, $4214
ai_pc_420a:
    ai_if_tgt_not_within_64_56_short $420A, $4211
ai_pc_420c:
    ai_call_ff $4239
ai_pc_420f:
    ai_jmp_01_short $420F, $4214
ai_pc_4211:
    ai_call_ff $42AA
ai_pc_4214:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $4214, $41F3
ai_pc_4219:
    ai_jmp_01_short $4219, $41F3
