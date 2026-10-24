; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2EF4
classify_boss_direction_by_half_axis_thresholds:
    .a16
    lda #$0002
    sta $6C
    lda $4E
    sta $5E
    lsr $5E
    sec
    lda $5E
    sbc $46
    bcc classify_boss_direction_by_half_axis_thresholds_c22f0a
    stz $6C
    bra classify_boss_direction_by_half_axis_thresholds_c22f19
classify_boss_direction_by_half_axis_thresholds_c22f0a:
    lda $46
    sta $56
    lsr $56
    sec
    lda $56
    sbc $4E
    bcs classify_boss_direction_by_half_axis_thresholds_c22f19
    dec $6C
classify_boss_direction_by_half_axis_thresholds_c22f19:
    rts
