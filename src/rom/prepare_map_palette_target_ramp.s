; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $BD48
prepare_map_palette_target_ramp:
    phx
    phy
    rep #$20
    lda a:$D208,Y
    sta $14
    .a16
    lda #$00C8
    sta $16
