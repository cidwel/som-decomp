; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-animation-special-helpers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C000
copy_actor_charge_effect_secondary_records:
    rep #$20
    lda a:$D001,Y
    sta a:$D011,Y
    sta a:$D021,Y
    phy
    phx
    .i16
    ldx #$0007
copy_actor_charge_effect_secondary_records_c2c010:
    lda a:$D002,Y
    sta a:$D012,Y
    sta a:$D022,Y
    iny
    iny
    dex
    bne copy_actor_charge_effect_secondary_records_c2c010
    plx
    ply
    rts
