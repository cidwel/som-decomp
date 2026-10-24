; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-tile-rows.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9881
publish_scene_tile_row_with_horizontal_page_wrap:
    sep #$10
    rep #$20
    ldx $2E
    bmi publish_scene_tile_row_with_horizontal_page_wrap_c0988a
    rts
publish_scene_tile_row_with_horizontal_page_wrap_c0988a:
    .i8
    ldx #$00
    stx $2E
    .i8
    ldx #$00
    stx a:$2115
    .a16
    lda #$1800
    sta a:$4370
    .i8
    ldx #$7F
    stx a:$4374
    lda $74
    sta a:$4372
    lda $76
    sta a:$2116
    .a16
    and #$007F
    .a16
    eor #$007F
    inc
    sta a:$4375
    .i8
    ldx #$80
    stx a:$420B
    .a16
    cmp #$0080
    bne publish_scene_tile_row_with_horizontal_page_wrap_c098bd
    rts
publish_scene_tile_row_with_horizontal_page_wrap_c098bd:
    .a16
    eor #$007F
    inc
    sta a:$4375
    lda $76
    .a16
    and #$3F80
    sta a:$2116
    lda $74
    .a16
    and #$01FF
    .a16
    cmp #$0180
    bcc publish_scene_tile_row_with_horizontal_page_wrap_c098de
    lda $74
    .a16
    and #$FE00
    sta a:$4372
publish_scene_tile_row_with_horizontal_page_wrap_c098de:
    .i8
    ldx #$80
    stx a:$420B
    rts
