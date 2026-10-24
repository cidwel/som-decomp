; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-geometry.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FC74
multiply_native_ring_quarter_wave_by_radius:
    sep #$20
    lda f:$D97DE0,X
    sta a:$4202
    lda a:$186E
    sta a:$4203
    nop
    nop
    nop
    nop
    lda a:$4217
    rep #$20
    .a16
    and #$00FF
    rts
