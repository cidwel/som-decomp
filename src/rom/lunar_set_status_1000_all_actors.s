; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


object_status_high = $E191

.segment "CODE"
.org $EF8A
lunar_set_status_1000_all_actors:
    .i16
    ldy #$0A00
    sty $CC
lunar_set_status_1000_all_actors_c8ef8f:
    ldy $CC
    lda a:object_status_high,Y
    .a8
    ora #$10
    sta a:object_status_high,Y
    dec $CD
    dec $CD
    bpl lunar_set_status_1000_all_actors_c8ef8f
    rts
