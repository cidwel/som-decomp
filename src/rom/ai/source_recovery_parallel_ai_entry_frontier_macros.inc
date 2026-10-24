; Typed program commands; no opaque script payload.
.macro ai_apply_selected_actor_effect_61
    .byte $61
.endmacro

.macro ai_call_ff target_pc
    .byte $FF, target_pc >> 8, target_pc & $FF
.endmacro

.macro ai_cmd04_ee
    .byte $EE
.endmacro

.macro ai_cmd81_ef arg1, arg2
    .byte $EF, arg1, arg2
.endmacro

.macro ai_hop_e0 arg1, arg2, arg3
    .byte $E0, arg1, arg2, arg3
.endmacro

.macro ai_if_field_and_z_2e_short arg1, arg2, arg3, source_pc, target_pc
    .byte $2E, arg1, arg2, arg3
    .byte $80 | ((target_pc - (source_pc + 5)) & $7F)
.endmacro

.macro ai_if_field_gt_30_long arg1, arg2, arg3, source_pc, target_pc
    .byte $30, arg1, arg2, arg3
    .byte ((target_pc - (source_pc + 6)) & $7FFF) >> 8, (target_pc - (source_pc + 6)) & $FF
.endmacro

.macro ai_if_field_gt_30_short arg1, arg2, arg3, source_pc, target_pc
    .byte $30, arg1, arg2, arg3
    .byte $80 | ((target_pc - (source_pc + 5)) & $7F)
.endmacro

.macro ai_if_field_lt_2f_short arg1, arg2, arg3, source_pc, target_pc
    .byte $2F, arg1, arg2, arg3
    .byte $80 | ((target_pc - (source_pc + 5)) & $7F)
.endmacro

.macro ai_if_pos_same_9d_short source_pc, target_pc
    .byte $9D
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro

.macro ai_if_tgt_not_within_16_34_short source_pc, target_pc
    .byte $34
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro

.macro ai_if_tgt_not_within_48_51_short source_pc, target_pc
    .byte $51
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro

.macro ai_if_var3_nz_05_short source_pc, target_pc
    .byte $05
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro

.macro ai_if_word_and_z_bb_long arg1, arg2, arg3, arg4, source_pc, target_pc
    .byte $BB, arg1, arg2, arg3, arg4
    .byte ((target_pc - (source_pc + 7)) & $7FFF) >> 8, (target_pc - (source_pc + 7)) & $FF
.endmacro

.macro ai_if_word_and_z_bb_short arg1, arg2, arg3, arg4, source_pc, target_pc
    .byte $BB, arg1, arg2, arg3, arg4
    .byte $80 | ((target_pc - (source_pc + 6)) & $7F)
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

.macro ai_pos_save_9f
    .byte $9F
.endmacro

.macro ai_ret_00
    .byte $00
.endmacro

.macro ai_rnd_var3_2c arg1
    .byte $2C, arg1
.endmacro

.macro ai_turn_facing_e3 arg1, arg2
    .byte $E3, arg1, arg2
.endmacro
