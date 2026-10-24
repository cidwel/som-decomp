.setcpu "65816"
.segment "CODE"
.org $7FA9
.include "ai_command_macros.inc"
ai_pc_3094:
    ai_pose_e2 $0000
ai_pc_3096:
    ai_rnd_var3_2c $0001
ai_pc_3098:
    ai_if_var3_nz_05_short $3098, $30A8
ai_pc_309a:
    ai_hop_e0 $0001, $0000, $0005
ai_pc_309e:
    ai_pose_e2 $0004
ai_pc_30a0:
    ai_hop_e0 $0002, $0000, $0005
ai_pc_30a4:
    ai_pose_e2 $0004
ai_pc_30a6:
    ai_jmp_01_short $30A6, $30B4
ai_pc_30a8:
    ai_hop_e0 $0002, $0000, $0005
ai_pc_30ac:
    ai_pose_e2 $0004
ai_pc_30ae:
    ai_hop_e0 $0001, $0000, $0005
ai_pc_30b2:
    ai_pose_e2 $0004
ai_pc_30b4:
    ai_call_ff $6AE1
ai_pc_30b7:
    ai_move_toward_e4 $0000, $0005
ai_pc_30ba:
    ai_pose_e2 $0003
ai_pc_30bc:
    ai_ret_00
ai_pc_30bd:
    ai_move_toward_e4 $0000, $0000
ai_pc_30c0:
    ai_if_field_gt_30_short $0080, $006D, $0000, $30C0, $30DE
ai_pc_30c5:
    ai_rnd_var3_2c $0001
ai_pc_30c7:
    ai_if_var3_nz_05_short $30C7, $30D1
ai_pc_30c9:
    ai_move_toward_e4 $0003, $0000
ai_pc_30cc:
    ai_call_ff $6B19
ai_pc_30cf:
    ai_jmp_01_short $30CF, $30DC
ai_pc_30d1:
    ai_flash_fc
ai_pc_30d2:
    ai_move_toward_e4 $0000, $0000
ai_pc_30d5:
    ai_call_ff $6B0F
ai_pc_30d8:
    ai_flash_fc
ai_pc_30d9:
    ai_move_toward_e4 $0000, $0005
ai_pc_30dc:
    ai_jmp_01_short $30DC, $30E1
ai_pc_30de:
    ai_move_toward_e4 $0000, $003C
ai_pc_30e1:
    ai_ret_00
ai_pc_30e2:
    ai_set_var1_26 $0000
ai_pc_30e4:
    ai_move_toward_e4 $0000, $0000
ai_pc_30e7:
    ai_if_field_gt_30_short $0080, $006D, $0000, $30E7, $30F9
ai_pc_30ec:
    ai_flash_fc
ai_pc_30ed:
    ai_move_toward_e4 $0003, $0000
ai_pc_30f0:
    ai_call_ff $6B19
ai_pc_30f3:
    ai_flash_fc
ai_pc_30f4:
    ai_move_toward_e4 $0000, $0005
ai_pc_30f7:
    ai_jmp_01_short $30F7, $30FC
ai_pc_30f9:
    ai_move_toward_e4 $0000, $003C
ai_pc_30fc:
    ai_ret_00
ai_pc_30fd:
    ai_set_var1_26 $0000
ai_pc_30ff:
    ai_call_ff $3113
ai_pc_3102:
    ai_call_ff $6AE1
ai_pc_3105:
    ai_if_var1_ne_0b_short $0001, $3105, $310D
ai_pc_3108:
    ai_call_ff $3149
ai_pc_310b:
    ai_jmp_01_short $310B, $3110
ai_pc_310d:
    ai_call_ff $3132
ai_pc_3110:
    ai_if_tgt_not_within_32_4c_short $3110, $3102
ai_pc_3112:
    ai_ret_00
ai_pc_3113:
    ai_if_obj_outside_5f_short $0080, $3113, $3131
ai_pc_3116:
    ai_rnd_var3_2c $0007
ai_pc_3118:
    ai_if_var3_gt_15_short $0001, $3118, $3124
ai_pc_311b:
    ai_tgt2_self_c4
ai_pc_311c:
    ai_cast_e9 $0004, $0004
ai_pc_311f:
    ai_tgt2_none_c0
ai_pc_3120:
    ai_set_var1_26 $0001
ai_pc_3122:
    ai_jmp_01_short $3122, $3131
ai_pc_3124:
    ai_if_var3_ne_0d_short $0002, $3124, $3131
ai_pc_3127:
    ai_tgt2_cur_c1
ai_pc_3128:
    ai_cast_e9 $0004, $0002
ai_pc_312b:
    ai_tgt2_none_c0
ai_pc_312c:
    ai_set_var1_26 $0000
ai_pc_312e:
    ai_turn_facing_e3 $0000, $003C
ai_pc_3131:
    ai_ret_00
ai_pc_3132:
    ai_set_var2_27 $0004
ai_pc_3134:
    ai_if_pos_same_9d_short $3134, $313C
ai_pc_3136:
    ai_pos_save_9f
ai_pc_3137:
    ai_move_toward_e4 $0004, $000A
ai_pc_313a:
    ai_jmp_01_short $313A, $3140
ai_pc_313c:
    ai_pos_save_9f
ai_pc_313d:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_3140:
    ai_if_tgt_not_within_32_4c_short $3140, $3145
ai_pc_3142:
    ai_jmp_01_long $3142, $3148
ai_pc_3145:
    ai_dec_var2_20
ai_pc_3146:
    ai_if_var2_nz_04_short $3146, $3134
ai_pc_3148:
    ai_ret_00
ai_pc_3149:
    ai_set_var2_27 $0004
ai_pc_314b:
    ai_if_pos_same_9d_short $314B, $3153
ai_pc_314d:
    ai_pos_save_9f
ai_pc_314e:
    ai_move_toward_e4 $0002, $000A
ai_pc_3151:
    ai_jmp_01_short $3151, $3157
ai_pc_3153:
    ai_pos_save_9f
ai_pc_3154:
    ai_move_toward_alt_fd $0002, $000A
ai_pc_3157:
    ai_if_tgt_not_within_32_4c_short $3157, $315C
ai_pc_3159:
    ai_jmp_01_long $3159, $315F
ai_pc_315c:
    ai_dec_var2_20
ai_pc_315d:
    ai_if_var2_nz_04_short $315D, $314B
ai_pc_315f:
    ai_ret_00
ai_pc_3160:
    ai_call_ff $318F
ai_pc_3163:
    ai_rnd_var3_2c $000F
ai_pc_3165:
    ai_if_var3_nz_05_short $3165, $316C
ai_pc_3167:
    ai_call_ff $6A5D
ai_pc_316a:
    ai_jmp_01_short $316A, $3187
ai_pc_316c:
    ai_call_ff $6AE1
ai_pc_316f:
    ai_if_tgt_not_within_32_4c_short $316F, $3176
ai_pc_3171:
    ai_call_ff $3192
ai_pc_3174:
    ai_jmp_01_short $3174, $3187
ai_pc_3176:
    ai_if_tgt_not_within_48_51_short $3176, $317D
ai_pc_3178:
    ai_call_ff $31B3
ai_pc_317b:
    ai_jmp_01_short $317B, $3187
ai_pc_317d:
    ai_if_tgt_not_within_64_56_short $317D, $3184
ai_pc_317f:
    ai_call_ff $31E3
ai_pc_3182:
    ai_jmp_01_short $3182, $3187
ai_pc_3184:
    ai_call_ff $322B
ai_pc_3187:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $3187, $3163
ai_pc_318c:
    ai_jmp_01_short $318C, $3163
