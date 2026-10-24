; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-projectile-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9C20
integrate_spell_projectile_fraction_and_integer_position:
    lda a:$0029,X
    clc
    adc a:$003A,X
    sta a:$0029,X
    lda a:$002B,X
    adc a:$003C,X
    sta a:$002B,X
    lda a:$0030,X
    clc
    adc a:$003E,X
    sta a:$0030,X
    lda a:$0032,X
    adc a:$0040,X
    sta a:$0032,X
    rts
