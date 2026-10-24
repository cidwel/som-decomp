; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-effect-preparation.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CB1A
prepare_event_radial_window_hdma:
    rep #$20
    .a16
    lda #$2641
    sta f:$004320
    .a16
    lda #$F018
    sta f:$004322
    .a16
    lda #$007E
    sta f:$004324
    .a16
    lda #$7E00
    sta f:$004326
    .a16
    lda #$F020
    sta a:$F019
    .a16
    lda #$F11E
    sta a:$F01C
    .a16
    lda #$0000
    sta a:$F01E
    lda a:$E020
    sta $1E
    lda a:$E074
    .a16
    and #$007F
    clc
    adc a:$E045
    .a16
    eor #$FFFF
    sec
    adc a:$E022
    sep #$20
    sta $1F
    .a8
    lda #$FF
    sta a:$F018
    .a8
    lda #$E0
    sta a:$F01B
    rts
