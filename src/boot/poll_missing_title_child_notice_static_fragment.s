; Static original-decoded fragment. Callee completion and gameplay entry unclaimed.
.setcpu "65816"
.smart
.a8
.i16
title_notice_flag_check = $D506
wait_title_phase_tick = $D17F
.segment "CODE"
.org $D50B
title_notice_zero_flag_poll_fragment:
    ldx #$0001
    jsr wait_title_phase_tick
    bra title_notice_flag_check
