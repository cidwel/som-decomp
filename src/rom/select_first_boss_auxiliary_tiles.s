; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

upload_guarded_boss_auxiliary_tiles = $9579

.segment "CODE"
.org $9566
select_first_boss_auxiliary_tiles:
    rep #$10
    .i16
    ldx #$0600
    bra upload_guarded_boss_auxiliary_tiles
