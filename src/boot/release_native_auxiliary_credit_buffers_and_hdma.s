; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-auxiliary-cleanup-abi.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7e88cf = $88CF
routine_7e9066 = $9066

.segment "CODE"
.org $8DAC
release_native_auxiliary_credit_buffers_and_hdma:
    phd
    php
    rep #$30
    sep #$20
    .i16
    ldx #$004A
    jsr routine_7e88cf
    .i16
    ldx #$0046
    jsr routine_7e88cf
    .i16
    ldx #$0042
    jsr routine_7e88cf
    ldx a:$0040
    jsr routine_7e9066
    plp
    pld
    rts
