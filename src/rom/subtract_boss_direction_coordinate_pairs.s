; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2EA0
subtract_boss_direction_coordinate_pairs:
    sec
    lda $46
    sbc $56
    sta $46
    sec
    lda $4E
    sbc $5E
    sta $4E
    rts
