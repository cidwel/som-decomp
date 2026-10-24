; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_eight_byte_record = $B1A9
append_pending_record = $B258
detect_controller_interface = $A4E9
select_input_interface_reader = $A6B7

.segment "CODE"
.org $A6FF
update_controller_states_and_messages:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$000A
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    lda a:$0090
    .a16
    and #$0001
    bne update_controller_states_and_messages_a71e
    jmp update_controller_states_and_messages_a80a
update_controller_states_and_messages_a71e:
    jsr detect_controller_interface
    .a16
    lda #$0005
    sta $01
    .i16
    ldx #$0000
    ldy a:$0092
update_controller_states_and_messages_a72c:
    stx $07
    sty $09
    jsr select_input_interface_reader
    .a16
    cmp #$3030
    beq update_controller_states_and_messages_a740
    .a16
    bit #$000F
    beq update_controller_states_and_messages_a74b
    jmp update_controller_states_and_messages_a7e9
update_controller_states_and_messages_a740:
    .a16
    lda #$0000
    pha
    lda f:$00FFFC
    dec
    pha
    rtl
update_controller_states_and_messages_a74b:
    sta $05
    .a16
    eor #$FFF0
    sta $03
    lda a:$0002,Y
    eor $05
    and $05
    sta a:$0004,Y
    and a:$0008,Y
    beq update_controller_states_and_messages_a798
    lda a:$0001,Y
    .a16
    and #$00FF
    .a16
    cmp #$0002
    bcc update_controller_states_and_messages_a798
    jsr allocate_eight_byte_record
    sep #$20
    .a8
    lda #$FE
    sta a:$0002,X
    .a8
    lda #$01
    sta a:$0004,X
    .a8
    lda #$05
    sec
    sbc $01
    sta a:$0005,X
    rep #$20
    ldy $09
    lda a:$0004,Y
    and a:$0008,Y
    sta a:$0006,X
    lda a:$0001,Y
    jsr append_pending_record
    ldy $09
update_controller_states_and_messages_a798:
    lda a:$0002,Y
    eor $05
    and $03
    sta a:$0006,Y
    and a:$000A,Y
    beq update_controller_states_and_messages_a7de
    lda a:$0001,Y
    .a16
    and #$00FF
    .a16
    cmp #$0002
    bcc update_controller_states_and_messages_a7de
    jsr allocate_eight_byte_record
    sep #$20
    .a8
    lda #$FE
    sta a:$0002,X
    .a8
    lda #$02
    sta a:$0004,X
    .a8
    lda #$05
    sec
    sbc $01
    sta a:$0005,X
    rep #$20
    ldy $09
    lda a:$0006,Y
    and a:$000A,Y
    sta a:$0006,X
    lda a:$0001,Y
    jsr append_pending_record
    ldy $09
update_controller_states_and_messages_a7de:
    sep #$20
    .a8
    lda #$01
    sta a:$0000,Y
    rep #$20
    bra update_controller_states_and_messages_a7f4
update_controller_states_and_messages_a7e9:
    stz $05
    sep #$20
    .a8
    lda #$00
    sta a:$0000,Y
    rep #$20
update_controller_states_and_messages_a7f4:
    lda $05
    sta a:$0002,Y
    ldx $07
    inx
    inx
    clc
    tya
    .a16
    adc #$0010
    tay
    dec $01
    beq update_controller_states_and_messages_a80a
    jmp update_controller_states_and_messages_a72c
update_controller_states_and_messages_a80a:
    plb
    tsc
    clc
    .a16
    adc #$000A
    tcs
    plp
    pld
    rts
