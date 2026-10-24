; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

expand_convert_submit_image_tile = $9E3D
mix_image_chroma = $9DF5

.segment "CODE"
.org $9F74
mix_convert_submit_image_group:
    phd
    php
    rep #$30
    sep #$20
    jsr mix_image_chroma
    .i16
    ldx #$1600
    .i16
    ldy #$1C00
    jsr expand_convert_submit_image_tile
    .i16
    ldx #$1700
    .i16
    ldy #$1C80
    jsr expand_convert_submit_image_tile
    .i16
    ldx #$1800
    .i16
    ldy #$1C90
    jsr expand_convert_submit_image_tile
    .i16
    ldx #$1900
    .i16
    ldy #$1C10
    jsr expand_convert_submit_image_tile
    plp
    pld
    rts
