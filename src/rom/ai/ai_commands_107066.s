.setcpu "65816"
.segment "CODE"
.org $7066
.include "ai_command_macros.inc"
ai_pc_2151:
    ai_if_obj_outside_5f_short $0080, $2151, $215C
ai_pc_2154:
    ai_if_crowd_gt_f5_short $0002, $2154, $215C
ai_pc_2157:
    ai_cmd43_ed $0017
ai_pc_2159:
    ai_move_away_e6 $0000, $0005
ai_pc_215c:
    ai_ret_00
ai_pc_215d:
    ai_call_ff $6AE1
ai_pc_2160:
    ai_if_pos_same_9d_short $2160, $2168
ai_pc_2162:
    ai_pos_save_9f
ai_pc_2163:
    ai_move_toward_card_be $0002, $0005
ai_pc_2166:
    ai_jmp_01_short $2166, $216C
ai_pc_2168:
    ai_pos_save_9f
ai_pc_2169:
    ai_move_toward_alt_fd $0002, $0005
ai_pc_216c:
    ai_if_tgt_not_within_32_4c_short $216C, $215D
ai_pc_216e:
    ai_ret_00
ai_pc_216f:
    ai_set_var2_27 $0000
ai_pc_2171:
    ai_if_tgt_not_within_64_56_short $2171, $21A0
ai_pc_2173:
    ai_call_ff $6AE1
ai_pc_2176:
    ai_if_pos_same_9d_short $2176, $217E
ai_pc_2178:
    ai_pos_save_9f
ai_pc_2179:
    ai_move_away_card_bf $0002, $0005
ai_pc_217c:
    ai_jmp_01_short $217C, $2182
ai_pc_217e:
    ai_pos_save_9f
ai_pc_217f:
    ai_move_away_alt_fe $0002, $0005
ai_pc_2182:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2182, $219B
ai_pc_2187:
    ai_if_tgt_not_lane_v64_66_short $2187, $2191
ai_pc_2189:
    ai_move_toward_card_be $0000, $0005
ai_pc_218c:
    ai_call_ff $6B0F
ai_pc_218f:
    ai_jmp_01_short $218F, $2199
ai_pc_2191:
    ai_if_tgt_not_lane_h64_6f_short $2191, $2199
ai_pc_2193:
    ai_move_toward_card_be $0000, $0005
ai_pc_2196:
    ai_call_ff $6B0F
ai_pc_2199:
    ai_jmp_01_short $2199, $219E
ai_pc_219b:
    ai_call_ff $2151
ai_pc_219e:
    ai_jmp_01_short $219E, $2171
ai_pc_21a0:
    ai_ret_00
ai_pc_21a1:
    ai_call_ff $21D0
ai_pc_21a4:
    ai_rnd_var3_2c $0007
ai_pc_21a6:
    ai_if_var3_nz_05_short $21A6, $21B1
ai_pc_21a8:
    ai_call_ff $675B
ai_pc_21ab:
    ai_hop_e0 $0008, $0004, $0000
ai_pc_21af:
    ai_jmp_01_short $21AF, $21C8
ai_pc_21b1:
    ai_call_ff $6AE1
ai_pc_21b4:
    ai_call_ff $220D
ai_pc_21b7:
    ai_if_tgt_not_within_48_51_short $21B7, $21BE
ai_pc_21b9:
    ai_call_ff $21D9
ai_pc_21bc:
    ai_jmp_01_short $21BC, $21C8
ai_pc_21be:
    ai_if_tgt_not_within_64_56_short $21BE, $21C5
ai_pc_21c0:
    ai_call_ff $21EB
ai_pc_21c3:
    ai_jmp_01_short $21C3, $21C8
ai_pc_21c5:
    ai_call_ff $221C
ai_pc_21c8:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $21C8, $21A4
ai_pc_21cd:
    ai_jmp_01_short $21CD, $21A4
