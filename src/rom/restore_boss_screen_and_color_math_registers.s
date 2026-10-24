; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-screen-requests.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6EEB
restore_boss_screen_and_color_math_registers:
    sep #$20
    lda a:$0021
    sta f:$00212C
    lda a:$0022
    sta f:$00212D
    lda a:$0023
    sta f:$002131
    rep #$20
    rts
