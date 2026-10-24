; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2EE3
classify_boss_direction_by_larger_absolute_axis:
    sec
    lda $4E
    sbc $46
    bcc classify_boss_direction_by_larger_absolute_axis_c22eee
    stz $6C
    bra classify_boss_direction_by_larger_absolute_axis_c22ef3
classify_boss_direction_by_larger_absolute_axis_c22eee:
    .a16
    lda #$0001
    sta $6C
classify_boss_direction_by_larger_absolute_axis_c22ef3:
    rts
