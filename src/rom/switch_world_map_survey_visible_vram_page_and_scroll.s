; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $ADE3
switch_world_map_survey_visible_vram_page_and_scroll:
    sep #$20
    .a8
    lda #$01
    sta $15
    rep #$20
    .a16
    lda #$2000
    bra switch_world_map_survey_visible_vram_page_and_scroll_c0adf9
    sep #$20
    stz $15
    rep #$20
    .a16
    lda #$1000
switch_world_map_survey_visible_vram_page_and_scroll_c0adf9:
    sta a:$4372
    .a16
    lda #$1801
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
switch_world_map_survey_visible_vram_page_and_scroll_c0ae13:
    bit $0E
    bne switch_world_map_survey_visible_vram_page_and_scroll_c0ae13
    .a8
    lda #$80
    sta a:$2115
    stz a:$2116
    stz a:$2117
    .a8
    lda #$80
    sta a:$420B
    lda $15
    asl
    asl
    asl
    asl
    asl
    sta a:$210E
    stz a:$210E
    rts
