; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-initializer-completion.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7ec030 = $C030
routine_7ec097 = $C097

.segment "CODE"
.org $9599
queue_warm_scene_display_mode_and_restore_initializer:
    .a16
    lda #$0005
    jsr routine_7ec030
    .a16
    lda #$0009
    sta a:$0002,X
    jsr routine_7ec097
    .a16
    lda #$002C
    jsr routine_7ec030
    .a16
    lda #$0015
    sta a:$0002,X
    jsr routine_7ec097
    tsc
    clc
    .a16
    adc #$000C
    tcs
    plp
    pld
    rts
