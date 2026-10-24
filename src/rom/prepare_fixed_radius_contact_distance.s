; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-map-contacts.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c1ce72 = $CE72

.segment "CODE"
.org $CE59
prepare_fixed_radius_contact_distance:
    rep #$20
    .a16
    lda #$000A
    sta $04
    bra routine_c1ce72
