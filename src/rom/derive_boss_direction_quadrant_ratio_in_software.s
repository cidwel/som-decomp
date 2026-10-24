; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

divide_unsigned_word_by_word_in_software = $2CBF

.segment "CODE"
.org $2F1A
derive_boss_direction_quadrant_ratio_in_software:
    .a16
    lda #$001F
    sta $6C
    lda $46
    cmp $4E
    bcc derive_boss_direction_quadrant_ratio_in_software_c22f3c
    jsr divide_unsigned_word_by_word_in_software
    lda $56
    .a16
    cmp #$0020
    bcc derive_boss_direction_quadrant_ratio_in_software_c22f32
    .a16
    lda #$001F
derive_boss_direction_quadrant_ratio_in_software_c22f32:
    sta $56
    lda $6C
    sec
    sbc $56
    sta $6C
    rts
derive_boss_direction_quadrant_ratio_in_software_c22f3c:
    lda $46
    beq derive_boss_direction_quadrant_ratio_in_software_c22f54
    sta $56
    lda $4E
    sta $46
    lda $56
    sta $4E
    jsr divide_unsigned_word_by_word_in_software
    lda $56
    .a16
    cmp #$0020
    bcc derive_boss_direction_quadrant_ratio_in_software_c22f57
derive_boss_direction_quadrant_ratio_in_software_c22f54:
    .a16
    lda #$001F
derive_boss_direction_quadrant_ratio_in_software_c22f57:
    sta $56
    lda $6C
    clc
    adc $56
    sta $6C
    rts
