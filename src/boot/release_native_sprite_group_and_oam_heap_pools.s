; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-heap-release-wrappers.md.
.setcpu "65816"
.smart
.a8
.i16

release_native_heap_suffix_through_bank_7f_api = $B0D6

.segment "CODE"
.org $B51C
release_native_sprite_group_and_oam_heap_pools:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    ldx a:$02C8
    jsr release_native_heap_suffix_through_bank_7f_api
    ldx a:$02CA
    jsr release_native_heap_suffix_through_bank_7f_api
    ldx a:$02CC
    jsr release_native_heap_suffix_through_bank_7f_api
    plb
    plp
    pld
    rts
