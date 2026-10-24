; Typed AI instructions; docs/ai-command-numeric.md.
.macro ai_call_ff target_pc
    .byte $FF, target_pc >> 8, target_pc & $FF
.endmacro
.macro ai_cast_all_ea arg1, arg2
    .byte $EA, arg1, arg2
.endmacro
.macro ai_cast_e9 arg1, arg2
    .byte $E9, arg1, arg2
.endmacro
.macro ai_charge_release_f4
    .byte $F4
.endmacro
.macro ai_charge_start_f3
    .byte $F3
.endmacro
.macro ai_cmd04_ee
    .byte $EE
.endmacro
.macro ai_cmd43_ed arg1
    .byte $ED, arg1
.endmacro
.macro ai_cmd81_ef arg1, arg2
    .byte $EF, arg1, arg2
.endmacro
.macro ai_dec_var0_1e
    .byte $1E
.endmacro
.macro ai_dec_var1_1f
    .byte $1F
.endmacro
.macro ai_dec_var2_20
    .byte $20
.endmacro
.macro ai_dec_var3_21
    .byte $21
.endmacro
.macro ai_field_set_dc arg1, arg2, arg3
    .byte $DC, arg1, arg2, arg3
.endmacro
.macro ai_flash_fc
    .byte $FC
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
.macro ai_if_crowd_gt_f5_short arg1, source_pc, target_pc
    .byte $F5, arg1
    .byte $80 | ((target_pc - (source_pc + 3)) & $7F)
.endmacro
.macro ai_if_field_and_nz_2d_short arg1, arg2, arg3, source_pc, target_pc
    .byte $2D, arg1, arg2, arg3
    .byte $80 | ((target_pc - (source_pc + 5)) & $7F)
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
.macro ai_if_fight_62_short source_pc, target_pc
    .byte $62
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_no_ally_64_54_short source_pc, target_pc
    .byte $54
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_no_hero_16_31_short source_pc, target_pc
    .byte $31
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_no_hero_32_49_short source_pc, target_pc
    .byte $49
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_no_hero_48_4e_short source_pc, target_pc
    .byte $4E
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_no_hero_64_53_short source_pc, target_pc
    .byte $53
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_no_hero_onscreen_58_short source_pc, target_pc
    .byte $58
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_no_monster_16_32_short source_pc, target_pc
    .byte $32
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_no_monster_32_4a_short source_pc, target_pc
    .byte $4A
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_no_monster_48_4f_short source_pc, target_pc
    .byte $4F
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_obj_inside_60_short arg1, source_pc, target_pc
    .byte $60, arg1
    .byte $80 | ((target_pc - (source_pc + 3)) & $7F)
.endmacro
.macro ai_if_obj_outside_5f_long arg1, source_pc, target_pc
    .byte $5F, arg1
    .byte ((target_pc - (source_pc + 4)) & $7FFF) >> 8, (target_pc - (source_pc + 4)) & $FF
.endmacro
.macro ai_if_obj_outside_5f_short arg1, source_pc, target_pc
    .byte $5F, arg1
    .byte $80 | ((target_pc - (source_pc + 3)) & $7F)
.endmacro
.macro ai_if_pos_moved_9e_short source_pc, target_pc
    .byte $9E
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_pos_same_9d_short source_pc, target_pc
    .byte $9D
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_tgt_not_above_75_short source_pc, target_pc
    .byte $75
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_tgt_not_band_64_46_short source_pc, target_pc
    .byte $46
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_tgt_not_below_77_short source_pc, target_pc
    .byte $77
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_tgt_not_beyond_64_5a_short source_pc, target_pc
    .byte $5A
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_tgt_not_lane_h48_71_short source_pc, target_pc
    .byte $71
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_tgt_not_lane_h64_6f_short source_pc, target_pc
    .byte $6F
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_tgt_not_lane_h_73_short source_pc, target_pc
    .byte $73
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_tgt_not_lane_v48_68_short source_pc, target_pc
    .byte $68
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_tgt_not_lane_v64_66_short source_pc, target_pc
    .byte $66
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_tgt_not_lane_v_6a_short source_pc, target_pc
    .byte $6A
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_tgt_not_left_79_short source_pc, target_pc
    .byte $79
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_tgt_not_right_7b_short source_pc, target_pc
    .byte $7B
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
.macro ai_if_tgt_not_within_64_56_long source_pc, target_pc
    .byte $56
    .byte ((target_pc - (source_pc + 3)) & $7FFF) >> 8, (target_pc - (source_pc + 3)) & $FF
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
.macro ai_if_var1_lt_17_short arg1, source_pc, target_pc
    .byte $17, arg1
    .byte $80 | ((target_pc - (source_pc + 3)) & $7F)
.endmacro
.macro ai_if_var1_ne_0b_short arg1, source_pc, target_pc
    .byte $0B, arg1
    .byte $80 | ((target_pc - (source_pc + 3)) & $7F)
.endmacro
.macro ai_if_var1_nz_03_short source_pc, target_pc
    .byte $03
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_var2_gt_14_short arg1, source_pc, target_pc
    .byte $14, arg1
    .byte $80 | ((target_pc - (source_pc + 3)) & $7F)
.endmacro
.macro ai_if_var2_lt_18_short arg1, source_pc, target_pc
    .byte $18, arg1
    .byte $80 | ((target_pc - (source_pc + 3)) & $7F)
.endmacro
.macro ai_if_var2_ne_0c_short arg1, source_pc, target_pc
    .byte $0C, arg1
    .byte $80 | ((target_pc - (source_pc + 3)) & $7F)
.endmacro
.macro ai_if_var2_nz_04_short source_pc, target_pc
    .byte $04
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_var2_z_08_short source_pc, target_pc
    .byte $08
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_var3_gt_15_short arg1, source_pc, target_pc
    .byte $15, arg1
    .byte $80 | ((target_pc - (source_pc + 3)) & $7F)
.endmacro
.macro ai_if_var3_ne_0d_short arg1, source_pc, target_pc
    .byte $0D, arg1
    .byte $80 | ((target_pc - (source_pc + 3)) & $7F)
.endmacro
.macro ai_if_var3_nz_05_short source_pc, target_pc
    .byte $05
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_var3_z_09_short source_pc, target_pc
    .byte $09
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
.endmacro
.macro ai_if_word_and_nz_ba_short arg1, arg2, arg3, arg4, source_pc, target_pc
    .byte $BA, arg1, arg2, arg3, arg4
    .byte $80 | ((target_pc - (source_pc + 6)) & $7F)
.endmacro
.macro ai_if_word_and_z_bb_short arg1, arg2, arg3, arg4, source_pc, target_pc
    .byte $BB, arg1, arg2, arg3, arg4
    .byte $80 | ((target_pc - (source_pc + 6)) & $7F)
.endmacro
.macro ai_if_word_gt_bd_short arg1, arg2, arg3, arg4, source_pc, target_pc
    .byte $BD, arg1, arg2, arg3, arg4
    .byte $80 | ((target_pc - (source_pc + 6)) & $7F)
.endmacro
.macro ai_if_word_lt_bc_short arg1, arg2, arg3, arg4, source_pc, target_pc
    .byte $BC, arg1, arg2, arg3, arg4
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
.macro ai_move_toward2_e5 arg1, arg2
    .byte $E5, arg1, arg2
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
.macro ai_pose_e2 arg1
    .byte $E2, arg1
.endmacro
.macro ai_ret_00
    .byte $00
.endmacro
.macro ai_rnd_var0_29 arg1
    .byte $29, arg1
.endmacro
.macro ai_rnd_var1_2a arg1
    .byte $2A, arg1
.endmacro
.macro ai_rnd_var2_2b arg1
    .byte $2B, arg1
.endmacro
.macro ai_rnd_var3_2c arg1
    .byte $2C, arg1
.endmacro
.macro ai_set_var0_25 arg1
    .byte $25, arg1
.endmacro
.macro ai_set_var1_26 arg1
    .byte $26, arg1
.endmacro
.macro ai_set_var2_27 arg1
    .byte $27, arg1
.endmacro
.macro ai_set_var3_28 arg1
    .byte $28, arg1
.endmacro
.macro ai_swing_e8
    .byte $E8
.endmacro
.macro ai_swing_plain_df
    .byte $DF
.endmacro
.macro ai_tgt2_ally_d8
    .byte $D8
.endmacro
.macro ai_tgt2_cur_c1
    .byte $C1
.endmacro
.macro ai_tgt2_none_c0
    .byte $C0
.endmacro
.macro ai_tgt2_self_c4
    .byte $C4
.endmacro
.macro ai_tgt_far_5d
    .byte $5D
.endmacro
.macro ai_tgt_monster_16_a6
    .byte $A6
.endmacro
.macro ai_tgt_monster_32_b2
    .byte $B2
.endmacro
.macro ai_tgt_monster_48_b5
    .byte $B5
.endmacro
.macro ai_tgt_monster_64_b8
    .byte $B8
.endmacro
.macro ai_tgt_none_a0
    .byte $A0
.endmacro
.macro ai_tgt_within_16_a5
    .byte $A5
.endmacro
.macro ai_tgt_within_32_b1
    .byte $B1
.endmacro
.macro ai_tgt_within_48_b4
    .byte $B4
.endmacro
.macro ai_tgt_within_64_b7
    .byte $B7
.endmacro
.macro ai_turn_facing_e3 arg1, arg2
    .byte $E3, arg1, arg2
.endmacro
