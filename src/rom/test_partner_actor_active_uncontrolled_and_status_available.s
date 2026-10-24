; Recovered Secret of Mana USA routine; behaviour documented in docs/map-main-frame-partner-selection.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A9F4
test_partner_actor_active_uncontrolled_and_status_available:
    lda f:$7EE000,X
    beq test_partner_actor_active_uncontrolled_and_status_available_c2aa15
    bmi test_partner_actor_active_uncontrolled_and_status_available_c2aa15
    lda f:$7EE02C,X
    ora f:$7EE08C,X
    bne test_partner_actor_active_uncontrolled_and_status_available_c2aa15
    rep #$20
    lda f:$7EE190,X
    .a16
    bit #$C160
    sep #$20
    bne test_partner_actor_active_uncontrolled_and_status_available_c2aa15
    clc
    rts
test_partner_actor_active_uncontrolled_and_status_available_c2aa15:
    sec
    rts
