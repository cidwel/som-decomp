; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-sorted-word-array.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C583
search_native_sorted_word_array_and_return_insertion_position:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0002
    tcd
    tcs
    lda $03,S
    stx $01
    asl
    beq search_native_sorted_word_array_and_return_insertion_position_c5c5
    clc
    adc $01
    sta $03
    clc
    adc $01
search_native_sorted_word_array_and_return_insertion_position_c59e:
    ror
    .a16
    and #$FFFE
    tax
    tya
    cmp a:$0000,X
    beq search_native_sorted_word_array_and_return_insertion_position_c5c8
    bcc search_native_sorted_word_array_and_return_insertion_position_c5b9
    inx
    inx
    stx $01
    txa
    cmp $03
    beq search_native_sorted_word_array_and_return_insertion_position_c5c5
    clc
    adc $03
    bra search_native_sorted_word_array_and_return_insertion_position_c59e
search_native_sorted_word_array_and_return_insertion_position_c5b9:
    stx $03
    txa
    cmp $01
    beq search_native_sorted_word_array_and_return_insertion_position_c5c5
    clc
    adc $01
    bra search_native_sorted_word_array_and_return_insertion_position_c59e
search_native_sorted_word_array_and_return_insertion_position_c5c5:
    .i16
    ldy #$0000
search_native_sorted_word_array_and_return_insertion_position_c5c8:
    sep #$20
    pla
    pla
    pla
    pla
    plp
    pld
    rts
