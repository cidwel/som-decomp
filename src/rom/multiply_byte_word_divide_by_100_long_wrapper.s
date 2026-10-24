; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

multiply_byte_word_divide_by_100 = $543B

.segment "CODE"
.org $5437
multiply_byte_word_divide_by_100_long_wrapper:
    jsr multiply_byte_word_divide_by_100
    rtl
