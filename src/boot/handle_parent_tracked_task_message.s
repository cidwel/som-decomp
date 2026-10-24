; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

release_eight_byte_record = $B1DD

.segment "CODE"
.org $D023
handle_parent_tracked_task_message:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    sep #$20
    lda a:$0002,X
    sta $02
    jsr release_eight_byte_record
    .i16
    ldx #$0318
    .a8
    lda #$14
    sta $01
    lda $02
handle_parent_tracked_task_message_d03d:
    cmp a:$0000,X
    beq handle_parent_tracked_task_message_d049
    inx
    dec $01
    bne handle_parent_tracked_task_message_d03d
    bra handle_parent_tracked_task_message_d04c
handle_parent_tracked_task_message_d049:
    stz a:$0000,X
handle_parent_tracked_task_message_d04c:
    pla
    pla
    plp
    pld
    rts
