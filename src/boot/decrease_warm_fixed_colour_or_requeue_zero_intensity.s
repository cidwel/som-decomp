; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-colour-decay.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7ec030 = $C030
routine_7ec097 = $C097

.segment "CODE"
.org $CB37
decrease_warm_fixed_colour_or_requeue_zero_intensity:
    .a8
    lda #$32
    jsr routine_7ec030
    lda a:$0002,X
    .a8
    and #$1F
    beq decrease_warm_fixed_colour_or_requeue_zero_intensity_cb49
    dec
    .a8
    ora #$E0
    sta a:$0002,X
decrease_warm_fixed_colour_or_requeue_zero_intensity_cb49:
    jsr routine_7ec097
