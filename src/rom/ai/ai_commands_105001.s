.setcpu "65816"
.segment "CODE"
.org $5001
.include "ai_command_macros.inc"
ai_pc_00ec:
    ai_pose_e2 $0000
ai_pc_00ee:
    ai_ret_00
ai_pc_00ef:
    ai_move_toward_card_be $0004, $0000
ai_pc_00f2:
    ai_move_toward_card_be $0005, $0000
ai_pc_00f5:
    ai_if_field_gt_30_short $0080, $006D, $0000, $00F5, $0100
ai_pc_00fa:
    ai_move_toward_e4 $0000, $0000
ai_pc_00fd:
    ai_call_ff $6B0F
ai_pc_0100:
    ai_call_ff $01B0
ai_pc_0103:
    ai_ret_00
ai_pc_0104:
    ai_move_toward_card_be $0004, $0000
ai_pc_0107:
    ai_move_toward_card_be $0005, $0000
ai_pc_010a:
    ai_if_field_gt_30_short $0080, $006D, $0000, $010A, $0133
ai_pc_010f:
    ai_if_tgt_not_lane_v64_66_short $010F, $012D
ai_pc_0111:
    ai_if_tgt_not_below_77_short $0111, $0125
ai_pc_0113:
    ai_hop_e0 $0004, $0000, $0005
ai_pc_0117:
    ai_flash_fc
ai_pc_0118:
    ai_hop_e0 $0004, $0000, $0005
ai_pc_011c:
    ai_call_ff $6B0F
ai_pc_011f:
    ai_flash_fc
ai_pc_0120:
    ai_move_toward_e4 $0000, $0005
ai_pc_0123:
    ai_jmp_01_short $0123, $012B
ai_pc_0125:
    ai_move_toward_e4 $0000, $0000
ai_pc_0128:
    ai_call_ff $6B0F
ai_pc_012b:
    ai_jmp_01_short $012B, $0133
ai_pc_012d:
    ai_move_toward_e4 $0000, $0000
ai_pc_0130:
    ai_call_ff $6B0F
ai_pc_0133:
    ai_call_ff $01B0
ai_pc_0136:
    ai_ret_00
ai_pc_0137:
    ai_move_toward_card_be $0004, $0000
ai_pc_013a:
    ai_move_toward_card_be $0005, $0000
ai_pc_013d:
    ai_if_field_gt_30_short $0080, $006D, $0000, $013D, $0180
ai_pc_0142:
    ai_if_tgt_not_lane_v64_66_short $0142, $016C
ai_pc_0144:
    ai_if_tgt_not_below_77_short $0144, $0158
ai_pc_0146:
    ai_hop_e0 $0004, $0000, $0005
ai_pc_014a:
    ai_flash_fc
ai_pc_014b:
    ai_hop_e0 $0004, $0000, $0005
ai_pc_014f:
    ai_call_ff $6B0F
ai_pc_0152:
    ai_flash_fc
ai_pc_0153:
    ai_move_toward_e4 $0000, $0005
ai_pc_0156:
    ai_jmp_01_short $0156, $016A
ai_pc_0158:
    ai_rnd_var3_2c $000F
ai_pc_015a:
    ai_if_var3_nz_05_short $015A, $0164
ai_pc_015c:
    ai_call_ff $0195
ai_pc_015f:
    ai_call_ff $6B0F
ai_pc_0162:
    ai_jmp_01_short $0162, $016A
ai_pc_0164:
    ai_move_toward_card_be $0004, $0000
ai_pc_0167:
    ai_move_toward_card_be $0005, $0000
ai_pc_016a:
    ai_jmp_01_short $016A, $017E
ai_pc_016c:
    ai_rnd_var3_2c $000F
ai_pc_016e:
    ai_if_var3_nz_05_short $016E, $0178
ai_pc_0170:
    ai_call_ff $0195
ai_pc_0173:
    ai_call_ff $6B0F
ai_pc_0176:
    ai_jmp_01_short $0176, $017E
ai_pc_0178:
    ai_move_toward_card_be $0004, $0000
ai_pc_017b:
    ai_move_toward_card_be $0005, $0000
ai_pc_017e:
    ai_jmp_01_short $017E, $0186
ai_pc_0180:
    ai_move_toward_card_be $0004, $0000
ai_pc_0183:
    ai_move_toward_card_be $0005, $0000
ai_pc_0186:
    ai_ret_00
ai_pc_0187:
    ai_rnd_var3_2c $0003
ai_pc_0189:
    ai_if_var3_nz_05_short $0189, $0191
ai_pc_018b:
    ai_move_toward_card_be $0004, $0000
ai_pc_018e:
    ai_move_toward_card_be $0005, $0000
ai_pc_0191:
    ai_call_ff $6A17
ai_pc_0194:
    ai_ret_00
ai_pc_0195:
    ai_rnd_var3_2c $0001
ai_pc_0197:
    ai_call_ff $6AE1
ai_pc_019a:
    ai_if_pos_same_9d_short $019A, $01A2
ai_pc_019c:
    ai_pos_save_9f
ai_pc_019d:
    ai_move_toward_e4 $0001, $0000
ai_pc_01a0:
    ai_jmp_01_short $01A0, $01A6
ai_pc_01a2:
    ai_pos_save_9f
ai_pc_01a3:
    ai_move_toward_alt_fd $0001, $0000
ai_pc_01a6:
    ai_if_var3_nz_05_short $01A6, $01AD
ai_pc_01a8:
    ai_if_tgt_not_within_48_51_short $01A8, $01AD
ai_pc_01aa:
    ai_jmp_01_long $01AA, $01AF
ai_pc_01ad:
    ai_if_tgt_not_within_32_4c_short $01AD, $0197
ai_pc_01af:
    ai_ret_00
ai_pc_01b0:
    ai_if_tgt_not_within_48_51_short $01B0, $01C3
ai_pc_01b2:
    ai_call_ff $6AE1
ai_pc_01b5:
    ai_if_pos_same_9d_short $01B5, $01BD
ai_pc_01b7:
    ai_pos_save_9f
ai_pc_01b8:
    ai_move_toward_e4 $0005, $0000
ai_pc_01bb:
    ai_jmp_01_short $01BB, $01C1
ai_pc_01bd:
    ai_pos_save_9f
ai_pc_01be:
    ai_move_toward_alt_fd $0005, $0000
ai_pc_01c1:
    ai_jmp_01_short $01C1, $01B0
ai_pc_01c3:
    ai_ret_00
ai_pc_01c4:
    ai_call_ff $01F3
ai_pc_01c7:
    ai_rnd_var3_2c $0007
ai_pc_01c9:
    ai_if_var3_nz_05_short $01C9, $01D0
ai_pc_01cb:
    ai_call_ff $6653
ai_pc_01ce:
    ai_jmp_01_short $01CE, $01EB
ai_pc_01d0:
    ai_call_ff $6AE1
ai_pc_01d3:
    ai_if_tgt_not_within_32_4c_short $01D3, $01DA
ai_pc_01d5:
    ai_call_ff $01F6
ai_pc_01d8:
    ai_jmp_01_short $01D8, $01EB
ai_pc_01da:
    ai_if_tgt_not_within_48_51_short $01DA, $01E1
ai_pc_01dc:
    ai_call_ff $021E
ai_pc_01df:
    ai_jmp_01_short $01DF, $01EB
ai_pc_01e1:
    ai_if_tgt_not_within_64_56_short $01E1, $01E8
ai_pc_01e3:
    ai_call_ff $023B
ai_pc_01e6:
    ai_jmp_01_short $01E6, $01EB
ai_pc_01e8:
    ai_call_ff $023B
ai_pc_01eb:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $01EB, $01C7
ai_pc_01f0:
    ai_jmp_01_short $01F0, $01C7
