; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-random.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C25B
advance_native_fifteen_byte_subtractive_random_ring:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    .a8
    lda #$00
    xba
    lda a:$02E4
    tay
    sep #$20
    inc
    .a8
    cmp #$0F
    bcc advance_native_fifteen_byte_subtractive_random_ring_c276
    .a8
    lda #$00
advance_native_fifteen_byte_subtractive_random_ring_c276:
    sta a:$02E4
    tax
    lda a:$02E5,Y
    sec
    sbc a:$02E5,X
    sta a:$02E5,X
    plb
    plp
    pld
    rts
