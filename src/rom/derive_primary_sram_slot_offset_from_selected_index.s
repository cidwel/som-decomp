; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-write.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $57C6
derive_primary_sram_slot_offset_from_selected_index:
    rep #$20
    lda a:$A211
    .a16
    and #$00FF
    xba
    asl
    asl
    tax
    sep #$20
    rts
