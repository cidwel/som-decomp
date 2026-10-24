; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $BD9F
release_third_party_controller:
    rep #$10
    .i16
    ldx #$0400
