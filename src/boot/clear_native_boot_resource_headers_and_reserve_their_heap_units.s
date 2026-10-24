; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-resource-memory.md.
.setcpu "65816"
.smart
.a8
.i16

fill_native_boot_memory_using_words_or_forward_copy = $C37D
routine_7eb081 = $B081

.segment "CODE"
.org $AF3C
clear_native_boot_resource_headers_and_reserve_their_heap_units:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    phx
    txy
    .i16
    ldx #$0000
    .a8
    lda #$00
    jsr fill_native_boot_memory_using_words_or_forward_copy
    plx
    jsr routine_7eb081
    plb
    plp
    pld
    rts
