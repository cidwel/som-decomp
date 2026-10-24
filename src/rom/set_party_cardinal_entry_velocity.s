; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DEF3
set_party_cardinal_entry_velocity:
    sta a:$E006
    sta a:$E206
    sta a:$E406
    sep #$20
    .a8
    lda #$24
    sta a:$E00A
    sta a:$E20A
    sta a:$E40A
    rts
