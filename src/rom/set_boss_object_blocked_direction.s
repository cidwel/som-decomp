; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1706
set_boss_object_blocked_direction:
    sep #$20
    lda $70
    lsr
    tax
    lda f:$D97EE0,X
    ldx $87
    and a:$004E,X
    sta a:$004E,X
    rep #$20
    lda $70
    ora a:$004E,X
    sta a:$004E,X
    rts
