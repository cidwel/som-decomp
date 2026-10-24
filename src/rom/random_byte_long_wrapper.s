; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

advance_additive_random_generator = $38A0

.segment "CODE"
.org $389C
random_byte_long_wrapper:
    jsr advance_additive_random_generator
    rtl
