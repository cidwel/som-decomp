; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2AA6
multiply_boss_terrain_row_stride:
    lda $46
    sta f:$004202
    lda $4E
    sta f:$004203
    nop
    nop
    nop
    nop
    lda f:$004216
    sta $56
    lda f:$004217
    sta $57
    rts
