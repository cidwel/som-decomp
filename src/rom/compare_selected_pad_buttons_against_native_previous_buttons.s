; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-title-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $325A
compare_selected_pad_buttons_against_native_previous_buttons:
    .a8
    lda #$00
    xba
    lda f:$0019FD
    asl
    tax
    lda $43,X
    cmp a:$A204,X
    rts
