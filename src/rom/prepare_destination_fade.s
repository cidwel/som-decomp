; Recovered Secret of Mana USA routine; behaviour documented in docs/cutscene-engine.md.
.setcpu "65816"
.smart
.a8
.i16

set_fade_interval_and_enable = $8B36

.segment "CODE"
.org $8B09
prepare_destination_fade:
    sep #$20
    rep #$10
    .a8
    lda #$00
    sta $E7
    .i16
    ldy #$0201
    bra set_fade_interval_and_enable
