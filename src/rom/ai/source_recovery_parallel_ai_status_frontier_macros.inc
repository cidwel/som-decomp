; Typed status-script commands; no opaque payload.
.macro ai_call_ff target_pc
    .byte $FF, target_pc >> 8, target_pc & $FF
.endmacro

.macro ai_charge_start_f3
    .byte $F3
.endmacro

.macro ai_dec_var1_1f
    .byte $1F
.endmacro

.macro ai_follow_e1
    .byte $E1
.endmacro

.macro ai_hop_e0 arg1, arg2, arg3
    .byte $E0, arg1, arg2, arg3
.endmacro

.macro ai_if_charge_set_f2_short arg1, source_pc, target_pc
    .byte $F2, arg1
    .byte $80 | ((target_pc - (source_pc + 3)) & $7F)
.endmacro

.macro ai_if_field_gt_30_long arg1, arg2, arg3, source_pc, target_pc
    .byte $30, arg1, arg2, arg3
    .byte ((target_pc - (source_pc + 6)) & $7FFF) >> 8, (target_pc - (source_pc + 6)) & $FF
.endmacro

.macro ai_if_field_gt_30_short arg1, arg2, arg3, source_pc, target_pc
    .byte $30, arg1, arg2, arg3
    .byte $80 | ((target_pc - (source_pc + 5)) & $7F)
.endmacro

.macro ai_if_obj_outside_5f_long arg1, source_pc, target_pc
    .byte $5F, arg1
    .byte ((target_pc - (source_pc + 4)) & $7FFF) >> 8, (target_pc - (source_pc + 4)) & $FF
.endmacro

.macro ai_if_pos_same_9d_short source_pc, target_pc
    .byte $9D
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro

.macro ai_if_tgt_not_lane_h64_6f_short source_pc, target_pc
    .byte $6F
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro

.macro ai_if_tgt_not_lane_v64_66_short source_pc, target_pc
    .byte $66
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro

.macro ai_if_tgt_not_within_16_34_short source_pc, target_pc
    .byte $34
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro

.macro ai_if_tgt_not_within_32_4c_short source_pc, target_pc
    .byte $4C
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro

.macro ai_if_tgt_not_within_48_51_short source_pc, target_pc
    .byte $51
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro

.macro ai_if_tgt_not_within_64_56_short source_pc, target_pc
    .byte $56
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro

.macro ai_if_var0_ne_0a_short arg1, source_pc, target_pc
    .byte $0A, arg1
    .byte $80 | ((target_pc - (source_pc + 3)) & $7F)
.endmacro

.macro ai_if_var0_nz_02_short source_pc, target_pc
    .byte $02
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro

.macro ai_if_var1_nz_03_short source_pc, target_pc
    .byte $03
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro

.macro ai_if_var2_gt_14_short arg1, source_pc, target_pc
    .byte $14, arg1
    .byte $80 | ((target_pc - (source_pc + 3)) & $7F)
.endmacro

.macro ai_if_word_and_nz_ba_long arg1, arg2, arg3, arg4, source_pc, target_pc
    .byte $BA, arg1, arg2, arg3, arg4
    .byte ((target_pc - (source_pc + 7)) & $7FFF) >> 8, (target_pc - (source_pc + 7)) & $FF
.endmacro

.macro ai_if_word_and_nz_ba_short arg1, arg2, arg3, arg4, source_pc, target_pc
    .byte $BA, arg1, arg2, arg3, arg4
    .byte $80 | ((target_pc - (source_pc + 6)) & $7F)
.endmacro

.macro ai_if_word_and_z_bb_long arg1, arg2, arg3, arg4, source_pc, target_pc
    .byte $BB, arg1, arg2, arg3, arg4
    .byte ((target_pc - (source_pc + 7)) & $7FFF) >> 8, (target_pc - (source_pc + 7)) & $FF
.endmacro

.macro ai_if_word_and_z_bb_short arg1, arg2, arg3, arg4, source_pc, target_pc
    .byte $BB, arg1, arg2, arg3, arg4
    .byte $80 | ((target_pc - (source_pc + 6)) & $7F)
.endmacro

.macro ai_inc_var0_1a
    .byte $1A
.endmacro

.macro ai_jmp_01_long source_pc, target_pc
    .byte $01
    .byte ((target_pc - (source_pc + 3)) & $7FFF) >> 8, (target_pc - (source_pc + 3)) & $FF
.endmacro

.macro ai_jmp_01_short source_pc, target_pc
    .byte $01
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro

.macro ai_move_away_alt_fe arg1, arg2
    .byte $FE, arg1, arg2
.endmacro

.macro ai_move_away_card_bf arg1, arg2
    .byte $BF, arg1, arg2
.endmacro

.macro ai_move_away_e6 arg1, arg2
    .byte $E6, arg1, arg2
.endmacro

.macro ai_move_toward_alt_fd arg1, arg2
    .byte $FD, arg1, arg2
.endmacro

.macro ai_move_toward_card_be arg1, arg2
    .byte $BE, arg1, arg2
.endmacro

.macro ai_move_toward_e4 arg1, arg2
    .byte $E4, arg1, arg2
.endmacro

.macro ai_pos_save_9f
    .byte $9F
.endmacro

.macro ai_ret_00
    .byte $00
.endmacro

.macro ai_rnd_var2_2b arg1
    .byte $2B, arg1
.endmacro

.macro ai_set_var0_25 arg1
    .byte $25, arg1
.endmacro

.macro ai_set_var1_26 arg1
    .byte $26, arg1
.endmacro

.macro ai_swing_plain_df
    .byte $DF
.endmacro

.macro ai_tgt2_none_c0
    .byte $C0
.endmacro

.macro ai_tgt_none_a0
    .byte $A0
.endmacro

.macro ai_turn_facing_e3 arg1, arg2
    .byte $E3, arg1, arg2
.endmacro
