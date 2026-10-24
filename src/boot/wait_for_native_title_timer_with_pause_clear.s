; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-unpaused-wait.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7ea814 = $A814
routine_7eabe7 = $ABE7

.segment "CODE"
.org $8B00
wait_for_native_title_timer_with_pause_clear:
    phd
    php
    rep #$30
    sep #$20
    phx
wait_for_native_title_timer_with_pause_clear_8b07:
    jsr routine_7ea814
    .a8
    and #$40
    bne wait_for_native_title_timer_with_pause_clear_8b07
    plx
    jsr routine_7eabe7
    plp
    pld
    rts
