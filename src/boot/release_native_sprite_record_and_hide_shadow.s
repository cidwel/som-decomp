; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-sprite-record-release.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B75F
release_native_sprite_record_and_hide_shadow:
    phd
    php
    rep #$30
    .a16
    lda #$FFF0
    sta a:$0002,X
    stz a:$0004,X
    stz a:$0008,X
    lda a:$000A,X
    .a16
    and #$00FF
    asl
    asl
    clc
    adc a:$02CC
    tax
    sep #$20
    .a8
    lda #$F0
    sta a:$0001,X
    plp
    pld
    rts
