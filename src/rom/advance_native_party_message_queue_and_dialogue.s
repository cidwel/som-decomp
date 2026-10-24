; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-message-queue.md.
.setcpu "65816"
.smart
.a8
.i16

advance_additive_random_generator = $38A0
request_native_party_message_resume_script = $5BF8
request_native_party_message_suspend_script = $5BEA
run_native_dialogue_public_jump = $C00092

.segment "CODE"
.org $57C9
advance_native_party_message_queue_and_dialogue:
    sep #$20
    .a8
    lda #$01
    sta a:$1D13
    jsl f:run_native_dialogue_public_jump
    phd
    phb
    php
    rep #$30
    .a16
    lda #$0300
    tcd
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    jsr advance_additive_random_generator
    lda $80
    bmi advance_native_party_message_queue_and_dialogue_c057fa
    lda a:$1D04
    .a8
    bit #$01
    beq advance_native_party_message_queue_and_dialogue_c057f4
    jmp advance_native_party_message_queue_and_dialogue_c05828
advance_native_party_message_queue_and_dialogue_c057f4:
    lda $A0
    beq advance_native_party_message_queue_and_dialogue_c057fe
    dec $A0
advance_native_party_message_queue_and_dialogue_c057fa:
    plp
    plb
    pld
    rtl
advance_native_party_message_queue_and_dialogue_c057fe:
    lda $A2
    sta f:$004202
    .a8
    lda #$1E
    sta f:$004203
    nop
    nop
    nop
    rep #$20
    lda f:$004216
    tay
    sep #$20
    lda a:$FE00,Y
    bne advance_native_party_message_queue_and_dialogue_c0581e
    jmp advance_native_party_message_queue_and_dialogue_c058a1
advance_native_party_message_queue_and_dialogue_c0581e:
    lda a:$1D12
    .a8
    bit #$20
    bne advance_native_party_message_queue_and_dialogue_c0582c
    jsr request_native_party_message_suspend_script
advance_native_party_message_queue_and_dialogue_c05828:
    plp
    plb
    pld
    rtl
advance_native_party_message_queue_and_dialogue_c0582c:
    inc $A2
    lda $A2
    .a8
    cmp #$0C
    bne advance_native_party_message_queue_and_dialogue_c05836
    stz $A2
advance_native_party_message_queue_and_dialogue_c05836:
    lda a:$FE00,Y
    bpl advance_native_party_message_queue_and_dialogue_c05859
    .a8
    lda #$60
    sta a:$FE00,Y
    lda $A3
    beq advance_native_party_message_queue_and_dialogue_c05859
    rep #$20
    lda a:$FE10,Y
    tax
    lda a:$FE12,Y
    bit a:$E190,X
    sep #$20
    bne advance_native_party_message_queue_and_dialogue_c05859
    .a8
    lda #$00
    sta a:$FE01,Y
advance_native_party_message_queue_and_dialogue_c05859:
    inc $A3
    sep #$20
    .a8
    lda #$7E
    sta a:$1D03
    .i16
    ldx #$FF69
    stx a:$1D01
    phy
    .a8
    lda #$1E
    sta $A4
advance_native_party_message_queue_and_dialogue_c0586d:
    lda a:$FE01,Y
    sta a:$0000,X
    iny
    inx
    dec $A4
    bne advance_native_party_message_queue_and_dialogue_c0586d
    ply
    dec $9F
    lda $9F
    asl
    asl
    asl
    .a8
    eor #$FF
    sta f:$004202
    lda a:$FE00,Y
    sta f:$004203
    nop
    nop
    nop
    nop
    lda f:$004217
    sta $A0
    .a8
    lda #$00
    sta a:$FE00,Y
    plp
    plb
    pld
    rtl
advance_native_party_message_queue_and_dialogue_c058a1:
    lda a:$1D12
    .a8
    bit #$20
    beq advance_native_party_message_queue_and_dialogue_c058ab
    jsr request_native_party_message_resume_script
advance_native_party_message_queue_and_dialogue_c058ab:
    plp
    plb
    pld
    rtl
