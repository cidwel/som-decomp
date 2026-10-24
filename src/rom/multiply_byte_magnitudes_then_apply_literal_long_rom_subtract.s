; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-byte-magnitude-product.md.
.setcpu "65816"
.smart
.a8
.i16

multiply_boss_terrain_row_stride = $2AA6

.segment "CODE"
.org $2B68
multiply_byte_magnitudes_then_apply_literal_long_rom_subtract:
    sep #$20
    lda $46
    eor $4E
    pha
    lda $46
    bpl multiply_byte_magnitudes_then_apply_literal_long_rom_subtract_c22b7a
    sec
    lda $C5
    sbc $46
    sta $46
multiply_byte_magnitudes_then_apply_literal_long_rom_subtract_c22b7a:
    lda $4E
    bpl multiply_byte_magnitudes_then_apply_literal_long_rom_subtract_c22b85
    sec
    lda $C5
    sbc $4E
    sta $4E
multiply_byte_magnitudes_then_apply_literal_long_rom_subtract_c22b85:
    jsr multiply_boss_terrain_row_stride
    pla
    bpl multiply_byte_magnitudes_then_apply_literal_long_rom_subtract_c22b93
    lda $56
    .a8
    eor #$FF
    sbc f:$56851A,X
multiply_byte_magnitudes_then_apply_literal_long_rom_subtract_c22b93:
    rts
