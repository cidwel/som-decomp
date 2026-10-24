; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

set_fade_interval_and_enable = $8B36

.segment "CODE"
.org $8B16
request_slow_black_fade:
    sep #$20
    rep #$10
    .a8
    lda #$00
    sta $E7
    .i16
    ldy #$0401
    bra set_fade_interval_and_enable
