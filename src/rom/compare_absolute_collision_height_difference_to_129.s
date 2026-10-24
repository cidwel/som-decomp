; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $06EF
compare_absolute_collision_height_difference_to_129:
    lda $62
    sec
    sbc $64
    bpl compare_absolute_collision_height_difference_to_129_c206fa
    .a16
    eor #$FFFF
    inc
compare_absolute_collision_height_difference_to_129_c206fa:
    .a16
    cmp #$0081
    rts
