; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-spells.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c29411 = $9411
select_native7f_status_gated_spell_or_skip = $93EE
select_nearest_living_target_and_eight_way_direction = $3A41

.segment "CODE"
.org $93CB
select_native7f_nearest_target_and_primary_spell_gate:
    jsr select_nearest_living_target_and_eight_way_direction
    ldx $87
    lda a:$01B1,X
    .a16
    bit #$0040
    bne select_native7f_status_gated_spell_or_skip
    .a16
    lda #$0000
    bra routine_c29411
