; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3048
advance_boss_random_pool_index:
    inc a:$033D,X
    lda a:$033D,X
    .a8
    cmp #$37
    bne advance_boss_random_pool_index_c23055
    stz a:$033D,X
advance_boss_random_pool_index_c23055:
    inx
    rts
