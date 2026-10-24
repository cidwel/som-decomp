; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B00F
release_128_byte_unit_suffix:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0006
    tcd
    tcs
    stx $02
    txa
    beq release_128_byte_unit_suffix_b078
    sec
    .a16
    sbc #$0000
    .a16
    and #$007F
    bne release_128_byte_unit_suffix_b078
    lda $02
    sec
    .a16
    sbc #$0000
    lsr
    lsr
    lsr
    lsr
    lsr
    lsr
    lsr
    sep #$20
    sta $01
    rep #$20
    .a16
    and #$00FF
    tax
    sep #$20
    lda a:$00C4,X
    sta $04
    beq release_128_byte_unit_suffix_b076
    lda a:$00C4,X
    sta $06
    phx
release_128_byte_unit_suffix_b04e:
    stz a:$00C4,X
    stz a:$01C4,X
    inx
    dec $06
    bne release_128_byte_unit_suffix_b04e
    plx
    lda $04
release_128_byte_unit_suffix_b05c:
    dex
    lda a:$00C4,X
    sec
    sbc $04
    beq release_128_byte_unit_suffix_b06c
    bcc release_128_byte_unit_suffix_b06c
    sta a:$00C4,X
    bra release_128_byte_unit_suffix_b05c
release_128_byte_unit_suffix_b06c:
    lda $01
    cmp a:$00C2
    bcs release_128_byte_unit_suffix_b076
    sta a:$00C2
release_128_byte_unit_suffix_b076:
    rep #$20
release_128_byte_unit_suffix_b078:
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts
