; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-death-effects.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3C84
initialize_boss_terminal_bitmap_clear_then_update:
    ldx $87
    inc a:$0094,X
