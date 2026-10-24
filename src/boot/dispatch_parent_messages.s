; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

ensure_parent_control_task = $D14C
handle_input_task_completion = $D0AE
handle_parent_buffer_message = $D081
handle_parent_image_message = $CFE2
handle_parent_tracked_task_message = $D023
receive_parent_message_or_cancel = $AEC4

.segment "CODE"
.org $D17F
dispatch_parent_messages:
    phd
    php
    rep #$30
    sep #$20
    bra dispatch_parent_messages_d18a
dispatch_parent_messages_d187:
    .i16
    ldx #$0000
dispatch_parent_messages_d18a:
    jsr receive_parent_message_or_cancel
    .i16
    cpx #$0000
    beq dispatch_parent_messages_d1cb
    lda a:$0002,X
    cmp a:$0312
    beq dispatch_parent_messages_d1ba
    cmp a:$0314
    beq dispatch_parent_messages_d1bf
    cmp a:$0315
    beq dispatch_parent_messages_d1c6
    cmp a:$0311
    beq dispatch_parent_messages_d1ae
    jsr handle_parent_tracked_task_message
    bra dispatch_parent_messages_d187
dispatch_parent_messages_d1ae:
    jsr handle_parent_image_message
    .a8
    cmp #$00
    beq dispatch_parent_messages_d187
    .i16
    ldx #$0000
    bra dispatch_parent_messages_d1d7
dispatch_parent_messages_d1ba:
    jsr handle_parent_buffer_message
    bra dispatch_parent_messages_d187
dispatch_parent_messages_d1bf:
    stz a:$0314
    .a8
    lda #$00
    bra dispatch_parent_messages_d1d7
dispatch_parent_messages_d1c6:
    jsr handle_input_task_completion
    bra dispatch_parent_messages_d187
dispatch_parent_messages_d1cb:
    .a8
    cmp #$00
    bne dispatch_parent_messages_d1d7
    jsr ensure_parent_control_task
    lda a:$0314
    bne dispatch_parent_messages_d187
dispatch_parent_messages_d1d7:
    plp
    pld
    rts
