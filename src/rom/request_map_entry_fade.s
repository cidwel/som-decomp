; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8B30
request_map_entry_fade:
    sep #$20
    rep #$10
    stx $E6
