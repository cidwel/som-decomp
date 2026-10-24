; Recovered Secret of Mana USA routine; behaviour documented in docs/native-controller-signal-wait.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0040
wait_for_controller_two_signal_and_unpack_saved_registers:
    phd
    php
    rep #$20
    sep #$20
    phb
    pha
    .a8
    lda #$00
    pha
    plb
    pla
    rep #$10
    phx
    pha
    xba
    pha
    lda a:$0100
    xba
    .a8
    lda #$40
    sta a:$0100
wait_for_controller_two_signal_and_unpack_saved_registers_c1005c:
    wai
    .i16
    ldx #$0000
wait_for_controller_two_signal_and_unpack_saved_registers_c10060:
    dex
    bne wait_for_controller_two_signal_and_unpack_saved_registers_c10060
    lda a:$421B
    lda a:$421A
    .a8
    and #$10
    beq wait_for_controller_two_signal_and_unpack_saved_registers_c1005c
    xba
    sta a:$0100
    pla
    xba
    plx
    pla
    plb
    plp
    pld
    rts
