; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-rebound-landing.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $56C3
test_boss_height_minus_thirty_two_and_clear_landing_state:
    lda a:$0066,X
    sec
    .a16
    sbc #$0020
    beq test_boss_height_minus_thirty_two_and_clear_landing_state_c256ce
    bpl test_boss_height_minus_thirty_two_and_clear_landing_state_c256d9
test_boss_height_minus_thirty_two_and_clear_landing_state_c256ce:
    stz a:$0064,X
    stz a:$0066,X
    stz a:$0090,X
    sec
    rts
test_boss_height_minus_thirty_two_and_clear_landing_state_c256d9:
    clc
    rts
