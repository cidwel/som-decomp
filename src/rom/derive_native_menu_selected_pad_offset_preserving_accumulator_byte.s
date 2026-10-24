; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-menu-input.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3269
derive_native_menu_selected_pad_offset_preserving_accumulator_byte:
    pha
    .a8
    lda #$00
    xba
    lda f:$0019FD
    asl
    tax
    pla
    rts
