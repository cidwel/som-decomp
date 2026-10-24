; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_eight_byte_record = $B1A9
append_pending_record = $B258

.segment "CODE"
.org $A4E9
detect_controller_interface:
    phd
    php
    rep #$30
    sep #$20
    .a8
    lda #$40
    xba
    .a8
    lda #$00
    tcd
    .a8
    lda #$FF
    sta f:$004201
    sta $16
    .i16
    ldy #$0008
detect_controller_interface_a500:
    lda $16
    .a8
    and #$02
    beq detect_controller_interface_a509
    dey
    bne detect_controller_interface_a500
detect_controller_interface_a509:
    pha
    .i16
    ldy #$0008
detect_controller_interface_a50d:
    lda $17
    .a8
    and #$02
    beq detect_controller_interface_a516
    dey
    bne detect_controller_interface_a50d
detect_controller_interface_a516:
    asl
    ora $01,S
    sta $01,S
    stz $16
    .i16
    ldy #$0008
detect_controller_interface_a520:
    lda $16
    .a8
    and #$02
    beq detect_controller_interface_a52f
    dey
    bne detect_controller_interface_a520
    .a8
    eor #$FF
    and $01,S
    sta $01,S
detect_controller_interface_a52f:
    .i16
    ldy #$0008
detect_controller_interface_a532:
    lda $17
    .a8
    and #$02
    beq detect_controller_interface_a542
    dey
    bne detect_controller_interface_a532
    asl
    .a8
    eor #$FF
    and $01,S
    sta $01,S
detect_controller_interface_a542:
    pla
    asl
    asl
    asl
    asl
    asl
    cmp a:$0096
    beq detect_controller_interface_a570
    sta a:$0096
    lda a:$0097
    beq detect_controller_interface_a570
    jsr allocate_eight_byte_record
    .a8
    lda #$FE
    sta a:$0002,X
    .a8
    lda #$03
    sta a:$0004,X
    lda $01,S
    sta a:$0005,X
    lda a:$0097
    jsr append_pending_record
    lda a:$0096
detect_controller_interface_a570:
    plp
    pld
    rts
