; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-exit.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $87B7
start_ui_window_color_transition:
    sep #$30
    lda $F2
    .a8
    ora #$01
    sta $F2
    .a8
    lda #$0E
    sta $51
    rts
