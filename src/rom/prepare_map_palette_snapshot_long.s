; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

copy_map_palette_snapshot_and_hdma_records = $F2AC

display_effect_flags = $E2

.segment "CODE"
.org $F29C
prepare_map_palette_snapshot_long:
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    .a8
    lda #$10
    trb display_effect_flags
    jsr copy_map_palette_snapshot_and_hdma_records
    plb
    rtl
