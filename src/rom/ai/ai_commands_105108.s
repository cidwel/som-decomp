.setcpu "65816"
.segment "CODE"
.org $5108
.include "ai_command_macros.inc"
ai_pc_01f3:
    ai_pose_e2 $0000
ai_pc_01f5:
    ai_ret_00
ai_pc_01f6:
    ai_move_toward_e4 $0000, $0000
ai_pc_01f9:
    ai_if_field_gt_30_short $0080, $006D, $0000, $01F9, $0217
ai_pc_01fe:
    ai_if_word_and_nz_ba_short $0081, $0010, $0010, $0000, $01FE, $0211
ai_pc_0204:
    ai_flash_fc
ai_pc_0205:
    ai_move_toward_e4 $0000, $0000
ai_pc_0208:
    ai_call_ff $6B0F
ai_pc_020b:
    ai_flash_fc
ai_pc_020c:
    ai_move_toward_e4 $0000, $0005
ai_pc_020f:
    ai_jmp_01_short $020F, $0217
ai_pc_0211:
    ai_move_toward_e4 $0000, $0000
ai_pc_0214:
    ai_call_ff $6B0F
ai_pc_0217:
    ai_move_toward_e4 $000E, $0000
ai_pc_021a:
    ai_call_ff $024D
ai_pc_021d:
    ai_ret_00
ai_pc_021e:
    ai_move_toward_e4 $0000, $0000
ai_pc_0221:
    ai_if_field_gt_30_short $0080, $006D, $0000, $0221, $0237
ai_pc_0226:
    ai_rnd_var3_2c $0001
ai_pc_0228:
    ai_if_var3_nz_05_short $0228, $0232
ai_pc_022a:
    ai_move_toward_e4 $0000, $0000
ai_pc_022d:
    ai_call_ff $6B0F
ai_pc_0230:
    ai_jmp_01_short $0230, $0235
ai_pc_0232:
    ai_call_ff $023B
ai_pc_0235:
    ai_jmp_01_short $0235, $023A
ai_pc_0237:
    ai_move_toward_e4 $0000, $0000
ai_pc_023a:
    ai_ret_00
ai_pc_023b:
    ai_call_ff $6AE1
ai_pc_023e:
    ai_if_pos_same_9d_short $023E, $0246
ai_pc_0240:
    ai_pos_save_9f
ai_pc_0241:
    ai_move_toward_e4 $0004, $000A
ai_pc_0244:
    ai_jmp_01_short $0244, $024A
ai_pc_0246:
    ai_pos_save_9f
ai_pc_0247:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_024a:
    ai_if_tgt_not_within_32_4c_short $024A, $023B
ai_pc_024c:
    ai_ret_00
ai_pc_024d:
    ai_if_tgt_not_within_32_4c_short $024D, $0260
ai_pc_024f:
    ai_call_ff $6AE1
ai_pc_0252:
    ai_if_pos_same_9d_short $0252, $025A
ai_pc_0254:
    ai_pos_save_9f
ai_pc_0255:
    ai_move_away_e6 $0004, $000A
ai_pc_0258:
    ai_jmp_01_short $0258, $025E
ai_pc_025a:
    ai_pos_save_9f
ai_pc_025b:
    ai_move_away_alt_fe $0004, $000A
ai_pc_025e:
    ai_jmp_01_short $025E, $024D
ai_pc_0260:
    ai_ret_00
ai_pc_0261:
    ai_call_ff $0280
ai_pc_0264:
    ai_call_ff $6AE1
ai_pc_0267:
    ai_if_tgt_not_within_48_51_short $0267, $026E
ai_pc_0269:
    ai_call_ff $028D
ai_pc_026c:
    ai_jmp_01_short $026C, $0278
ai_pc_026e:
    ai_if_tgt_not_within_64_56_short $026E, $0275
ai_pc_0270:
    ai_call_ff $02A1
ai_pc_0273:
    ai_jmp_01_short $0273, $0278
ai_pc_0275:
    ai_call_ff $02B2
ai_pc_0278:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $0278, $0264
ai_pc_027d:
    ai_jmp_01_short $027D, $0264
