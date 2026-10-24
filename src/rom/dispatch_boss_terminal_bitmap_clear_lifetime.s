; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-death-effects.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3C78
dispatch_boss_terminal_bitmap_clear_lifetime:
    lda a:$0094,X
    asl
    tax
    jmp ($3C80,X)
