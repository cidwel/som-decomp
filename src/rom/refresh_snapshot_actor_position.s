; Recovered Secret of Mana USA routine; behaviour documented in docs/cutscene-engine.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CCBA
refresh_snapshot_actor_position:
    phy
    ldy a:$C802,X
    rep #$20
    lda a:$E002,Y
    lsr
    lsr
    lsr
    lsr
    .a16
    and #$007F
    sta $00
    lda a:$E004,Y
    lsr
    lsr
    lsr
    lsr
    xba
    .a16
    and #$7F00
    ora $00
    sta a:$C80A,X
    sep #$20
    lda a:$E00B,Y
    .a8
    and #$80
    lsr
    lsr
    lsr
    lsr
    sta $00
    lda a:$C80C,X
    .a8
    and #$F7
    ora $00
    sta a:$C80C,X
    ply
    rts
