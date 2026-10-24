; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

decode_transform_image_group = $9DB6
mix_convert_submit_image_group = $9F74
request_image_row_and_replace_graphics = $9FA4

.segment "CODE"
.org $A009
generate_twelve_row_image:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    lda $05,S
    sep #$20
    phb
    pha
    .a8
    lda #$00
    pha
    plb
    pla
    rep #$20
    sta $05
    stx a:$0116
    xba
    .a16
    and #$00FF
    sta a:$0110
    stz a:$0112
    stz a:$0114
    stz $03
    .a16
    lda #$0000
generate_twelve_row_image_a039:
    ldx $05
    jsr request_image_row_and_replace_graphics
    .a16
    lda #$0010
    sta $01
generate_twelve_row_image_a043:
    jsr decode_transform_image_group
    jsr mix_convert_submit_image_group
    dec $01
    bne generate_twelve_row_image_a043
    lda $03
    inc
    sta $03
    .a16
    cmp #$000C
    bne generate_twelve_row_image_a039
    plb
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts
