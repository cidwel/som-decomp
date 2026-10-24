; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

build_map_palette_row_ramps = $BD56

.segment "CODE"
.org $BD38
prepare_map_palette_fixed_source_ramp:
    phx
    phy
    rep #$20
    .a16
    lda #$BEFD
    sta $14
    .a16
    lda #$0001
    sta $16
    bra build_map_palette_row_ramps
