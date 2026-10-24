; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8BF7
update_descriptor_eleven_facing_phase_or_return_transition_abort:
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    lda a:$002B,X
    sec
    sbc a:$0002,Y
    bpl update_descriptor_eleven_facing_phase_or_return_transition_abort_c28c0e
    lda $C5
    bra update_descriptor_eleven_facing_phase_or_return_transition_abort_c28c11
update_descriptor_eleven_facing_phase_or_return_transition_abort_c28c0e:
    .a16
    lda #$0001
update_descriptor_eleven_facing_phase_or_return_transition_abort_c28c11:
    cmp a:$007E,X
    beq update_descriptor_eleven_facing_phase_or_return_transition_abort_c28c1e
    sta a:$007E,X
    .a16
    lda #$F030
    sec
    rts
update_descriptor_eleven_facing_phase_or_return_transition_abort_c28c1e:
    clc
    rts
