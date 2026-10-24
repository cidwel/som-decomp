; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

advance_boss_random_pool_index = $3048

.segment "CODE"
.org $302C
advance_boss_xor_random_pool:
    .i8
    ldx #$00
    jsr advance_boss_random_pool_index
    jsr advance_boss_random_pool_index
    ldx a:$033E
    lda a:$0306,X
    sta $46
    ldx a:$033D
    lda a:$0306,X
    eor $46
    sta a:$0306,X
    rts
