; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

advance_additive_random_generator = $38A0

.segment "CODE"
.org $3888
random_below_byte:
    sta f:$004202
    jsr advance_additive_random_generator
    sta f:$004203
    nop
    nop
    nop
    nop
    lda f:$004217
    rts
