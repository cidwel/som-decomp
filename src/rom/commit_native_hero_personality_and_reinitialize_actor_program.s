; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-personality-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

set_actor_program_long = $C10020

.segment "CODE"
.org $6CA7
commit_native_hero_personality_and_reinitialize_actor_program:
    .a8
    lda #$00
    xba
    lda a:$A22B
    tay
    lda a:$A136
    sta a:$A257,Y
    tax
    phx
    lda f:$C76D8B,X
    sta a:$A173
    lda a:$CC73,Y
    .a8
    and #$80
    ora a:$A173
    sta a:$CC73,Y
    plx
    lda f:$C76D9B,X
    sta a:$CC7A,Y
    lda a:$A211
    sta a:$CC7D,Y
    rep #$20
    tya
    xba
    asl
    clc
    .a16
    adc #$E000
    tax
    tya
    sep #$20
    clc
    .a8
    adc #$80
    jsl f:set_actor_program_long
    rtl
