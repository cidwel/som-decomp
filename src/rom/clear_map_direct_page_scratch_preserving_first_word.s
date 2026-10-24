; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-map-entry-requests.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $BC9B
clear_map_direct_page_scratch_preserving_first_word:
    sep #$30
    .i8
    ldx #$CE
    rep #$20
    .a16
    lda #$0000
clear_map_direct_page_scratch_preserving_first_word_c0bca4:
    sta $00,X
    dex
    dex
    bne clear_map_direct_page_scratch_preserving_first_word_c0bca4
    rts
