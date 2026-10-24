; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-initializer-completion.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7e94bf = $94BF

.segment "CODE"
.org $9575
call_warm_colour_hdma_constructor:
    jsr routine_7e94bf
