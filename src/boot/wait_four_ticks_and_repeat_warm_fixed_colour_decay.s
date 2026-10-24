; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-colour-decay.md.
.setcpu "65816"
.smart
.a8
.i16

decrease_warm_fixed_colour_or_requeue_zero_intensity = $CB37
routine_7eabe7 = $ABE7

.segment "CODE"
.org $CB4C
wait_four_ticks_and_repeat_warm_fixed_colour_decay:
    .i16
    ldx #$0004
    jsr routine_7eabe7
    bra decrease_warm_fixed_colour_or_requeue_zero_intensity
