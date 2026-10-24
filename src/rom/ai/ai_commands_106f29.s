.setcpu "65816"
.segment "CODE"
.org $6F29
.include "ai_command_macros.inc"
ai_pc_2014:
    ai_pose_e2 $0000
ai_pc_2016:
    ai_ret_00
ai_pc_2017:
    ai_call_ff $2076
ai_pc_201a:
    ai_move_toward_e4 $000E, $0000
ai_pc_201d:
    ai_call_ff $4320
ai_pc_2020:
    ai_ret_00
ai_pc_2021:
    ai_call_ff $2076
ai_pc_2024:
    ai_call_ff $4320
ai_pc_2027:
    ai_ret_00
ai_pc_2028:
    ai_move_toward_card_be $0000, $0000
ai_pc_202b:
    ai_if_field_gt_30_long $0080, $006D, $0000, $202B, $2075
ai_pc_2031:
    ai_rnd_var3_2c $0002
ai_pc_2033:
    ai_if_var3_nz_05_short $2033, $204B
ai_pc_2035:
    ai_move_toward_card_be $0000, $0000
ai_pc_2038:
    ai_if_tgt_not_lane_v64_66_short $2038, $203F
ai_pc_203a:
    ai_call_ff $4305
ai_pc_203d:
    ai_jmp_01_short $203D, $2049
ai_pc_203f:
    ai_if_tgt_not_lane_h64_6f_short $203F, $2046
ai_pc_2041:
    ai_call_ff $4305
ai_pc_2044:
    ai_jmp_01_short $2044, $2049
ai_pc_2046:
    ai_move_toward_card_be $0000, $0000
ai_pc_2049:
    ai_jmp_01_short $2049, $2075
ai_pc_204b:
    ai_if_var3_ne_0d_short $0001, $204B, $2064
ai_pc_204e:
    ai_move_toward_card_be $0000, $0000
ai_pc_2051:
    ai_if_tgt_not_lane_v64_66_short $2051, $2058
ai_pc_2053:
    ai_call_ff $42EA
ai_pc_2056:
    ai_jmp_01_short $2056, $2062
ai_pc_2058:
    ai_if_tgt_not_lane_h64_6f_short $2058, $205F
ai_pc_205a:
    ai_call_ff $42EA
ai_pc_205d:
    ai_jmp_01_short $205D, $2062
ai_pc_205f:
    ai_move_toward_card_be $0000, $0000
ai_pc_2062:
    ai_jmp_01_short $2062, $2075
ai_pc_2064:
    ai_move_toward_card_be $0000, $0000
ai_pc_2067:
    ai_rnd_var3_2c $0002
ai_pc_2069:
    ai_if_var3_nz_05_short $2069, $2072
ai_pc_206b:
    ai_tgt2_self_c4
ai_pc_206c:
    ai_cast_e9 $0004, $0005
ai_pc_206f:
    ai_tgt2_none_c0
ai_pc_2070:
    ai_jmp_01_short $2070, $2075
ai_pc_2072:
    ai_move_toward_card_be $0000, $0000
ai_pc_2075:
    ai_ret_00
ai_pc_2076:
    ai_move_toward_card_be $0000, $0000
ai_pc_2079:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2079, $20AC
ai_pc_207e:
    ai_move_toward_card_be $0000, $0000
ai_pc_2081:
    ai_rnd_var3_2c $0007
ai_pc_2083:
    ai_if_var3_nz_05_short $2083, $2092
ai_pc_2085:
    ai_pose_e2 $0003
ai_pc_2087:
    ai_turn_facing_e3 $0008, $0000
ai_pc_208a:
    ai_move_toward_card_be $0004, $0000
ai_pc_208d:
    ai_move_toward_card_be $0005, $0000
ai_pc_2090:
    ai_jmp_01_short $2090, $20AC
ai_pc_2092:
    ai_move_toward_card_be $0000, $0005
ai_pc_2095:
    ai_if_tgt_not_lane_v48_68_short $2095, $209F
ai_pc_2097:
    ai_move_toward_card_be $0000, $0005
ai_pc_209a:
    ai_call_ff $6B0F
ai_pc_209d:
    ai_jmp_01_short $209D, $20AC
ai_pc_209f:
    ai_if_tgt_not_lane_h48_71_short $209F, $20A9
ai_pc_20a1:
    ai_move_toward_card_be $0000, $0005
ai_pc_20a4:
    ai_call_ff $6B0F
ai_pc_20a7:
    ai_jmp_01_short $20A7, $20AC
ai_pc_20a9:
    ai_move_toward_card_be $0000, $0000
ai_pc_20ac:
    ai_ret_00
ai_pc_20ad:
    ai_call_ff $20D7
ai_pc_20b0:
    ai_call_ff $6AE1
ai_pc_20b3:
    ai_if_word_gt_bd_short $0080, $0002, $0028, $0000, $20B3, $20BE
ai_pc_20b9:
    ai_call_ff $2129
ai_pc_20bc:
    ai_jmp_01_short $20BC, $20CF
ai_pc_20be:
    ai_if_tgt_not_within_48_51_short $20BE, $20C5
ai_pc_20c0:
    ai_call_ff $20DA
ai_pc_20c3:
    ai_jmp_01_short $20C3, $20CF
ai_pc_20c5:
    ai_if_tgt_not_within_64_56_short $20C5, $20CC
ai_pc_20c7:
    ai_call_ff $20E0
ai_pc_20ca:
    ai_jmp_01_short $20CA, $20CF
ai_pc_20cc:
    ai_call_ff $2115
ai_pc_20cf:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $20CF, $20B0
ai_pc_20d4:
    ai_jmp_01_short $20D4, $20B0
