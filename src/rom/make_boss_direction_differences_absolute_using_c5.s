; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2ECC
make_boss_direction_differences_absolute_using_c5:
    lda $46
    bpl make_boss_direction_differences_absolute_using_c5_c22ed7
    sec
    lda $C5
    sbc $46
    sta $46
make_boss_direction_differences_absolute_using_c5_c22ed7:
    lda $4E
    bpl make_boss_direction_differences_absolute_using_c5_c22ee2
    sec
    lda $C5
    sbc $4E
    sta $4E
make_boss_direction_differences_absolute_using_c5_c22ee2:
    rts
