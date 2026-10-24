; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native55-gravity.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $52B0
compare_native55_integer_height_against_512:
    lda a:$0066,X
    .a16
    cmp #$0200
    rts
