; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2EAF
derive_boss_direction_quadrant_from_signed_differences:
    stz $6A
    lda $4E
    bpl derive_boss_direction_quadrant_from_signed_differences_c22eb9
    inc $6A
    inc $6A
derive_boss_direction_quadrant_from_signed_differences_c22eb9:
    lda $46
    bpl derive_boss_direction_quadrant_from_signed_differences_c22ebf
    inc $6A
derive_boss_direction_quadrant_from_signed_differences_c22ebf:
    lda $6A
    .a16
    cmp #$0002
    bcc derive_boss_direction_quadrant_from_signed_differences_c22ecb
    .a16
    eor #$0001
    sta $6A
derive_boss_direction_quadrant_from_signed_differences_c22ecb:
    rts
