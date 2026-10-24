; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9574
select_third_boss_auxiliary_tiles:
    rep #$10
    .i16
    ldx #$0A00
