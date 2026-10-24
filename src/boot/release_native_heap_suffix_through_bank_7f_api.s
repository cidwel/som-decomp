; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-heap-release-wrappers.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eb00f = $B00F

.segment "CODE"
.org $B0D6
release_native_heap_suffix_through_bank_7f_api:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    jsr routine_7eb00f
    plb
    plp
    pld
    rts
