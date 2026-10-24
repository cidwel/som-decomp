; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

multiply_byte_by_word = $54B6

.segment "CODE"
.org $54B2
multiply_byte_by_word_long_wrapper:
    jsr multiply_byte_by_word
    rtl
