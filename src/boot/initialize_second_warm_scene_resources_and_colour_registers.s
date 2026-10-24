; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-secondary-resources.md.
.setcpu "65816"
.smart
.a8
.i16

construct_second_warm_scene_background_resources = $CA65
routine_7ec030 = $C030
routine_7ec097 = $C097

.segment "CODE"
.org $CAF8
initialize_second_warm_scene_resources_and_colour_registers:
    phd
    php
    rep #$30
    sep #$20
    jsr construct_second_warm_scene_background_resources
    .a8
    lda #$30
    jsr routine_7ec030
    .a8
    lda #$00
    sta a:$0002,X
    jsr routine_7ec097
    .a8
    lda #$31
    jsr routine_7ec030
    .a8
    lda #$81
    sta a:$0002,X
    jsr routine_7ec097
    .a8
    lda #$32
    jsr routine_7ec030
    .a8
    lda #$FF
    sta a:$0002,X
    jsr routine_7ec097
    plp
    pld
    rts
