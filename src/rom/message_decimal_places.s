; Numeric decimal-place divisors used by the word formatter.
.setcpu "65816"
.segment "CODE"
.org $5CC5
message_decimal_places:
    .word 10000, 1000, 100, 10, 1
