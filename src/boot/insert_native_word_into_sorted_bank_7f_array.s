; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-sorted-word-array.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7ec4dc = $C4DC
routine_7ec583 = $C583

.segment "CODE"
.org $C5D1
insert_native_word_into_sorted_bank_7f_array:
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
    lda #$7F
    pha
    plb
    pla
    rep #$20
    stx $01
    sty $03
    sta $05
    .a16
    cmp #$0000
    beq insert_native_word_into_sorted_bank_7f_array_c60f
    jsr routine_7ec583
    txa
    sec
    sbc $01
    lsr
    sec
    sbc $05
    beq insert_native_word_into_sorted_bank_7f_array_c60f
    .a16
    eor #$FFFF
    inc
    asl
    txy
    iny
    iny
    phx
    jsr routine_7ec4dc
    plx
insert_native_word_into_sorted_bank_7f_array_c60f:
    lda $03
    sta a:$0000,X
    plb
    sta $05,S
    tsc
    clc
    .a16
    adc #$0004
    tcs
    pla
    plp
    pld
    rts
