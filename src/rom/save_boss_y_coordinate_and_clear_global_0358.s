; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $73AD
save_boss_y_coordinate_and_clear_global_0358:
    lda a:$0032,X
    sta a:$035C
    stz a:$0358
    rts
