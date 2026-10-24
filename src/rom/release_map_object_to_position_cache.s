; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E2E1
release_map_object_to_position_cache:
    rep #$20
    lda a:$E002,X
    lsr
    lsr
    lsr
    lsr
    .a16
    and #$007F
    sta $00
    lda a:$E004,X
    lsr
    lsr
    lsr
    lsr
    xba
    .a16
    and #$7F00
    ora $00
    phy
    ldy a:$E034,X
    sta a:$C80A,Y
    sep #$20
    lda a:$E00B,X
    .a8
    and #$80
    lsr
    lsr
    lsr
    lsr
    sta $00
    lda a:$C80C,Y
    .a8
    and #$F7
    ora $00
    sta a:$C80C,Y
    lda a:$C800,Y
    .a8
    and #$7F
    sta a:$C800,Y
    ply
    rts
