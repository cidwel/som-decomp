; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

decode_scale_transform_image_block = $9D0E

.segment "CODE"
.org $9DB6
decode_transform_image_group:
    phd
    .a16
    lda #$1600
    tcd
    ldx a:$0110
    jsr decode_scale_transform_image_block
    .a16
    lda #$1700
    tcd
    jsr decode_scale_transform_image_block
    .a16
    lda #$1800
    tcd
    jsr decode_scale_transform_image_block
    .a16
    lda #$1900
    tcd
    jsr decode_scale_transform_image_block
    stx a:$0110
    .a16
    lda #$1A00
    tcd
    ldx a:$0112
    jsr decode_scale_transform_image_block
    stx a:$0112
    .a16
    lda #$1B00
    tcd
    ldx a:$0114
    jsr decode_scale_transform_image_block
    stx a:$0114
    pld
    rts
