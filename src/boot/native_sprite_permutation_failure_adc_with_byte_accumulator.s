; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-dirty-sprite-loop.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B8C6
native_sprite_permutation_failure_adc_with_byte_accumulator:
    tsc
    clc
    .a8
    adc #$08
