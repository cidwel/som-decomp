; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


message_queue_buffer = $FE00

.segment "CODE"
.org $5D33
clear_message_queue_line:
    phx
    phy
    .i16
    ldx #$000F
    .a16
    lda #$0000
clear_message_queue_line_c05d3b:
    sta a:message_queue_buffer,Y
    iny
    iny
    dex
    bne clear_message_queue_line_c05d3b
    ply
    plx
    rts
