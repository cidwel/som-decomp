; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F702
upload_map_mirrored_pattern_tiles:
    sep #$30
    .a8
    lda #$80
    sta a:$2115
    rep #$20
    .a16
    lda #$6000
    sta $02
    sep #$10
    .i8
    ldx #$00
    txy
upload_map_mirrored_pattern_tiles_c1f715:
    lda $02
    sta a:$2116
    .i8
    ldy #$08
upload_map_mirrored_pattern_tiles_c1f71c:
    lda f:$D1F5B0,X
    .a16
    and #$00FF
    sta a:$2118
    inx
    dey
    bne upload_map_mirrored_pattern_tiles_c1f71c
    dex
    .i8
    ldy #$08
upload_map_mirrored_pattern_tiles_c1f72d:
    stz a:$2118
    dey
    bne upload_map_mirrored_pattern_tiles_c1f72d
    lda $02
    clc
    .a16
    adc #$0100
    sta a:$2116
    .i8
    ldy #$08
upload_map_mirrored_pattern_tiles_c1f73e:
    lda f:$D1F5B0,X
    .a16
    and #$00FF
    sta a:$2118
    dex
    dey
    bne upload_map_mirrored_pattern_tiles_c1f73e
    .i8
    ldy #$08
upload_map_mirrored_pattern_tiles_c1f74e:
    stz a:$2118
    dey
    bne upload_map_mirrored_pattern_tiles_c1f74e
    txa
    clc
    .a16
    adc #$0009
    tax
    lda $02
    clc
    .a16
    adc #$0010
    sta $02
    .i8
    cpx #$50
    bcc upload_map_mirrored_pattern_tiles_c1f715
    rts
