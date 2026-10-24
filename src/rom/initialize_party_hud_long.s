; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_party_hud = $E104

.segment "CODE"
.org $E0D7
initialize_party_hud_long:
    jsr initialize_party_hud
    rtl
