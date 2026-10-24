; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


object_status_low = $E190

.segment "CODE"
.org $EFD0
lunar_sleep_all_actors:
    .i16
    ldy #$0A00
    sty $CC
lunar_sleep_all_actors_c8efd5:
    ldy $CC
    lda a:object_status_low,Y
    .a8
    ora #$10
    sta a:object_status_low,Y
    dec $CD
    dec $CD
    bpl lunar_sleep_all_actors_c8efd5
    rts
