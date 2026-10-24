; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-dirty-sprite-brk.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B8CA
native_sprite_permutation_failure_brk_signature:
    brk $1B
