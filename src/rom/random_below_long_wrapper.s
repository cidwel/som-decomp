; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

random_below_byte = $3888

.segment "CODE"
.org $3884
random_below_long_wrapper:
    jsr random_below_byte
    rtl
