; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-motion.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c24974 = $4974

.segment "CODE"
.org $4965
test_native54_negative_status_or_begin_hurt_shift:
    lda a:$0190,X
    bmi routine_c24974
    clc
    rts
