; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-spells.md.
.setcpu "65816"
.smart
.a8
.i16

draw_boss_frame_random_number = $300B
routine_c29411 = $9411
select_native7f_status_gated_spell_or_skip = $93EE

.segment "CODE"
.org $93DD
evaluate_native7f_detached_secondary_spell_fragment:
    lda a:$01B0,X
    .a16
    and #$00FF
    bne select_native7f_status_gated_spell_or_skip
    .a16
    lda #$0003
    jsr draw_boss_frame_random_number
    inc
    bra routine_c29411
