; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-death-effects.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3197
dispatch_death_explosion_animation_lifetime:
    lda a:$0094,X
    asl
    tax
    jmp ($319F,X)
