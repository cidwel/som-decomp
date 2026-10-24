.setcpu "65816"
.segment "CODE"
.org $4FB1
.include "ai_command_macros.inc"
ai_pc_009c:
    ai_if_tgt_not_within_32_4c_short $009C, $00B8
ai_pc_009e:
    ai_call_ff $6AE1
ai_pc_00a1:
    ai_if_pos_same_9d_short $00A1, $00A9
ai_pc_00a3:
    ai_pos_save_9f
ai_pc_00a4:
    ai_move_away_e6 $0002, $0000
ai_pc_00a7:
    ai_jmp_01_short $00A7, $00AD
ai_pc_00a9:
    ai_pos_save_9f
ai_pc_00aa:
    ai_move_away_alt_fe $0002, $0000
ai_pc_00ad:
    ai_if_word_gt_bd_short $0080, $0002, $0009, $0000, $00AD, $00B6
ai_pc_00b3:
    ai_jmp_01_long $00B3, $00B8
ai_pc_00b6:
    ai_jmp_01_short $00B6, $009C
ai_pc_00b8:
    ai_ret_00
ai_pc_00b9:
    ai_call_ff $00EC
ai_pc_00bc:
    ai_rnd_var3_2c $0005
ai_pc_00be:
    ai_if_var3_nz_05_short $00BE, $00C9
ai_pc_00c0:
    ai_call_ff $689F
ai_pc_00c3:
    ai_hop_e0 $0008, $0002, $0000
ai_pc_00c7:
    ai_jmp_01_short $00C7, $00E4
ai_pc_00c9:
    ai_call_ff $6AE1
ai_pc_00cc:
    ai_if_tgt_not_within_32_4c_short $00CC, $00D3
ai_pc_00ce:
    ai_call_ff $00EF
ai_pc_00d1:
    ai_jmp_01_short $00D1, $00E4
ai_pc_00d3:
    ai_if_tgt_not_within_48_51_short $00D3, $00DA
ai_pc_00d5:
    ai_call_ff $0104
ai_pc_00d8:
    ai_jmp_01_short $00D8, $00E4
ai_pc_00da:
    ai_if_tgt_not_within_64_56_short $00DA, $00E1
ai_pc_00dc:
    ai_call_ff $0137
ai_pc_00df:
    ai_jmp_01_short $00DF, $00E4
ai_pc_00e1:
    ai_call_ff $0187
ai_pc_00e4:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $00E4, $00BC
ai_pc_00e9:
    ai_jmp_01_short $00E9, $00BC
