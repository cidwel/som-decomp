; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


object_status_high = $E191

.segment "CODE"
.org $EFA0
lunar_set_status_0200_heroes:
    .i16
    ldy #$0400
    sty $CC
lunar_set_status_0200_heroes_c8efa5:
    ldy $CC
    lda a:object_status_high,Y
    .a8
    ora #$02
    sta a:object_status_high,Y
    dec $CD
    dec $CD
    bpl lunar_set_status_0200_heroes_c8efa5
    rts
