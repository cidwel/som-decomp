; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16

await_survey_nmi_and_clear_complete_vram_page = $B00D
decode_and_pack_complete_world_map_survey_tile_groups = $AE35
decode_last_two_world_map_survey_tile_groups = $AFF9
routine_c0afc4 = $AFC4

.segment "CODE"
.org $AFAE
construct_and_save_both_world_map_survey_vram_pages:
    jsr decode_last_two_world_map_survey_tile_groups
    rep #$20
    .a16
    lda #$2000
    jsr routine_c0afc4
    jsr await_survey_nmi_and_clear_complete_vram_page
    jsr decode_and_pack_complete_world_map_survey_tile_groups
    rep #$20
    .a16
    lda #$1000
    sta a:$4372
    .a16
    lda #$3981
    sta a:$4370
    .a16
    lda #$1000
    sta a:$4375
    sep #$20
    .a8
    lda #$7F
    sta a:$4374
    .a8
    lda #$80
    sta $0E
construct_and_save_both_world_map_survey_vram_pages_c0afde:
    bit $0E
    bne construct_and_save_both_world_map_survey_vram_pages_c0afde
    stz a:$2116
    stz a:$2117
    .a8
    lda #$80
    sta a:$2115
    lda a:$213A
    lda a:$213B
    .a8
    lda #$80
    sta a:$420B
    rts
