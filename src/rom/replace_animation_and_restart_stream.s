; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1802
replace_animation_and_restart_stream:
    ldx $87
    lda [$76],Y
    sta a:$009A,X
    stz a:$009C,X
    asl
    tax
    lda f:$DBF9A8,X
    sta $76
    .i16
    ldy #$0000
    ldx $87
    rts
