; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


object_status_low = $E190

.segment "CODE"
.org $EF74
lunar_silence_all_actors:
    .i16
    ldy #$0A00
    sty $CC
lunar_silence_all_actors_c8ef79:
    ldy $CC
    lda a:object_status_low,Y
    .a8
    ora #$80
    sta a:object_status_low,Y
    dec $CD
    dec $CD
    bpl lunar_silence_all_actors_c8ef79
    rts
