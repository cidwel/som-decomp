; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c0ae43 = $AE43

.segment "CODE"
.org $AFF9
decode_last_two_world_map_survey_tile_groups:
    rep #$20
    .a16
    lda #$0002
    sta $12
    .a16
    lda #$01F0
    sta $14
    .a16
    lda #$01E0
    sta $10
    brl routine_c0ae43
