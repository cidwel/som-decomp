; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16

average_four_world_map_pixels_and_pack_all_eight_bitplanes = $AE96
routine_c09a06 = $9A06

.segment "CODE"
.org $AE35
decode_and_pack_complete_world_map_survey_tile_groups:
    rep #$20
    .a16
    lda #$001E
    sta $12
    .a16
    lda #$0010
    sta $14
    stz $10
    sep #$20
    .a8
    lda #$80
    sta a:$2115
    .a8
    lda #$7F
    sta a:$4374
    rep #$20
    .a16
    lda #$1801
    sta a:$4370
    .a16
    lda #$0040
    sta a:$4372
decode_and_pack_complete_world_map_survey_tile_groups_c0ae5d:
    sep #$20
    .a8
    lda #$01
    sta a:$2183
    rep #$30
    lda $10
    tay
    .a16
    and #$000F
    xba
    asl
    clc
    .a16
    adc #$E000
    sta a:$2181
    phb
    rep #$30
    .a16
    lda #$0B00
    tcd
    jsr routine_c09a06
    plb
    rep #$30
    lda $10
    inc
    sta $10
    .a16
    and #$000F
    bne decode_and_pack_complete_world_map_survey_tile_groups_c0ae5d
    jsr average_four_world_map_pixels_and_pack_all_eight_bitplanes
    sep #$20
    dec $12
    bne decode_and_pack_complete_world_map_survey_tile_groups_c0ae5d
    rts
