; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-repeat-finish.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eb1a9 = $B1A9
routine_7eb258 = $B258
routine_7ed17f = $D17F
routine_7ed1da = $D1DA
routine_7ed3aa = $D3AA

.segment "CODE"
.org $D40D
fade_notify_image_and_teardown_before_title_repeat:
    phd
    php
    rep #$30
    phb
    tsc
    tcd
    sep #$20
    jsr routine_7ed1da
    .a8
    cmp #$00
    beq fade_notify_image_and_teardown_before_title_repeat_d43f
    .i16
    ldx #$0004
    jsr routine_7ed17f
    .a8
    cmp #$00
    beq fade_notify_image_and_teardown_before_title_repeat_d43f
    jsr routine_7eb1a9
    lda a:$0311
    jsr routine_7eb258
    stz a:$0312
    stz a:$0311
    jsr routine_7ed3aa
    .i16
    ldx #$00B4
    jsr routine_7ed17f
fade_notify_image_and_teardown_before_title_repeat_d43f:
    sta $01,S
    pla
    plp
    pld
    rts
