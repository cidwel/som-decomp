; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-to-map-reset.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AA17
initialize_ui_transition_state_from_saved_map_flags:
    sep #$10
    rep #$20
    stz $D0
    stz $D2
    stz $D4
    stz $D6
    stz $D7
    stz $E0
    stz $E2
    stz $E4
    stz $E6
    stz $E8
    stz $EA
    stz $F1
    stz $FE
    .a16
    lda #$0000
    sta $F6
    .a16
    lda #$0044
    sta $F8
    .a16
    lda #$0080
    sta $F2
    .a16
    lda #$0200
    sta $FA
    .a16
    lda #$0208
    sta $FC
    sep #$20
    lda f:$7ECF02
    lsr
    ror
    ror
    .a8
    and #$C0
    sta $E3
    rtl
