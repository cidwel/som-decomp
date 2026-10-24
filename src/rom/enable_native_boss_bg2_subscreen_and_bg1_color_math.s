; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-visual-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6ECB
enable_native_boss_bg2_subscreen_and_bg1_color_math:
    sep #$20
    lda a:$0021
    .a8
    and #$FD
    sta f:$00212C
    lda a:$0022
    .a8
    ora #$02
    sta f:$00212D
    lda a:$0023
    .a8
    ora #$01
    sta f:$002131
    rep #$20
    rts
