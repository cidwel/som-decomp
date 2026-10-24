.setcpu "65816"
.segment "CODE"
.org $7EF0
.include "ai_command_macros.inc"
ai_pc_2fdb:
    ai_pose_e2 $0002
ai_pc_2fdd:
    ai_ret_00
ai_pc_2fde:
    ai_move_toward_e4 $0003, $0000
ai_pc_2fe1:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2FE1, $2FEC
ai_pc_2fe6:
    ai_move_toward_e4 $0000, $0000
ai_pc_2fe9:
    ai_call_ff $6B19
ai_pc_2fec:
    ai_call_ff $3058
ai_pc_2fef:
    ai_ret_00
ai_pc_2ff0:
    ai_move_toward_e4 $0000, $0000
ai_pc_2ff3:
    ai_if_field_gt_30_short $0080, $006D, $0000, $2FF3, $3003
ai_pc_2ff8:
    ai_move_toward_e4 $0003, $0000
ai_pc_2ffb:
    ai_call_ff $6B19
ai_pc_2ffe:
    ai_call_ff $3058
ai_pc_3001:
    ai_jmp_01_short $3001, $301A
ai_pc_3003:
    ai_move_toward_e4 $0000, $0000
ai_pc_3006:
    ai_if_obj_outside_5f_short $0080, $3006, $301A
ai_pc_3009:
    ai_rnd_var3_2c $000F
ai_pc_300b:
    ai_if_var3_nz_05_short $300B, $3017
ai_pc_300d:
    ai_move_toward_e4 $0000, $0000
ai_pc_3010:
    ai_tgt2_cur_c1
ai_pc_3011:
    ai_cast_e9 $0005, $0007
ai_pc_3014:
    ai_tgt2_none_c0
ai_pc_3015:
    ai_jmp_01_short $3015, $301A
ai_pc_3017:
    ai_move_toward_e4 $0000, $0000
ai_pc_301a:
    ai_ret_00
ai_pc_301b:
    ai_rnd_var3_2c $000F
ai_pc_301d:
    ai_if_var3_nz_05_short $301D, $3027
ai_pc_301f:
    ai_move_toward_e4 $0000, $0000
ai_pc_3022:
    ai_move_toward_e4 $0003, $003C
ai_pc_3025:
    ai_jmp_01_short $3025, $3033
ai_pc_3027:
    ai_if_pos_same_9d_short $3027, $302F
ai_pc_3029:
    ai_pos_save_9f
ai_pc_302a:
    ai_move_toward_e4 $0004, $0000
ai_pc_302d:
    ai_jmp_01_short $302D, $3033
ai_pc_302f:
    ai_pos_save_9f
ai_pc_3030:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_3033:
    ai_ret_00
ai_pc_3034:
    ai_move_toward_e4 $0000, $0000
ai_pc_3037:
    ai_if_obj_outside_5f_short $0080, $3037, $3046
ai_pc_303a:
    ai_rnd_var3_2c $000F
ai_pc_303c:
    ai_if_var3_nz_05_short $303C, $3046
ai_pc_303e:
    ai_move_toward_e4 $0000, $0000
ai_pc_3041:
    ai_tgt2_cur_c1
ai_pc_3042:
    ai_cast_e9 $0005, $0002
ai_pc_3045:
    ai_tgt2_none_c0
ai_pc_3046:
    ai_call_ff $6AE1
ai_pc_3049:
    ai_if_pos_same_9d_short $3049, $3051
ai_pc_304b:
    ai_pos_save_9f
ai_pc_304c:
    ai_move_toward_e4 $0004, $0000
ai_pc_304f:
    ai_jmp_01_short $304F, $3055
ai_pc_3051:
    ai_pos_save_9f
ai_pc_3052:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_3055:
    ai_if_tgt_not_within_64_56_short $3055, $3046
ai_pc_3057:
    ai_ret_00
ai_pc_3058:
    ai_if_tgt_not_within_48_51_short $3058, $306B
ai_pc_305a:
    ai_call_ff $6AE1
ai_pc_305d:
    ai_if_pos_same_9d_short $305D, $3065
ai_pc_305f:
    ai_pos_save_9f
ai_pc_3060:
    ai_move_away_e6 $0002, $0000
ai_pc_3063:
    ai_jmp_01_short $3063, $3069
ai_pc_3065:
    ai_pos_save_9f
ai_pc_3066:
    ai_move_away_alt_fe $0002, $0000
ai_pc_3069:
    ai_jmp_01_short $3069, $3058
ai_pc_306b:
    ai_ret_00
ai_pc_306c:
    ai_call_ff $3094
ai_pc_306f:
    ai_rnd_var3_2c $000F
ai_pc_3071:
    ai_if_var3_nz_05_short $3071, $3078
ai_pc_3073:
    ai_call_ff $672F
ai_pc_3076:
    ai_jmp_01_short $3076, $308C
ai_pc_3078:
    ai_call_ff $6AE1
ai_pc_307b:
    ai_if_tgt_not_within_16_34_short $307B, $3082
ai_pc_307d:
    ai_call_ff $30BD
ai_pc_3080:
    ai_jmp_01_short $3080, $308C
ai_pc_3082:
    ai_if_tgt_not_within_32_4c_short $3082, $3089
ai_pc_3084:
    ai_call_ff $30E2
ai_pc_3087:
    ai_jmp_01_short $3087, $308C
ai_pc_3089:
    ai_call_ff $30FD
ai_pc_308c:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $308C, $306F
ai_pc_3091:
    ai_jmp_01_short $3091, $306F
