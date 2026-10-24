; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-secondary-resources.md.
.setcpu "65816"
.smart
.a8
.i16

routine_0095c6 = $95C6
routine_0095e5 = $95E5
routine_7ec030 = $C030
routine_7ec097 = $C097

.segment "CODE"
.org $95CC
increment_warm_scene_brightness_and_repeat_four_tick_wait:
    .a8
    lda #$00
    jsr routine_7ec030
    lda a:$0002,X
    .a8
    cmp #$0F
    bcs routine_0095e5
    inc
    sta a:$0002,X
    pha
    jsr routine_7ec097
    pla
    .a8
    cmp #$0F
    bcc routine_0095c6
