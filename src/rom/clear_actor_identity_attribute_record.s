; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4E31
clear_actor_identity_attribute_record:
    phx
    rep #$20
    .a16
    lda #$0000
    .i16
    ldy #$0009
clear_actor_identity_attribute_record_c04e3a:
    sta a:$E170,X
    sta a:$E182,X
    sta a:$E194,X
    sta a:$E1A6,X
    sta a:$E1B8,X
    sta a:$E1CA,X
    sta a:$E1DC,X
    sta a:$E1EE,X
    inx
    inx
    dey
    bne clear_actor_identity_attribute_record_c04e3a
    sep #$20
    plx
    .a8
    lda #$0F
    sta a:$E1EC,X
    .a8
    lda #$FF
    sta a:$E1F0,X
    sta a:$E1E5,X
    sta a:$E1FC,X
    rts
