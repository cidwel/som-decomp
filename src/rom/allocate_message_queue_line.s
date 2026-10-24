; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

clear_message_queue_line = $5D33

message_queue_buffer = $FE00

.segment "CODE"
.org $5CCF
allocate_message_queue_line:
    lda $9F
    .a8
    cmp #$0C
    bne allocate_message_queue_line_c05cd8
    .i16
    ldy #$0186
allocate_message_queue_line_c05cd8:
    lda $A1
    sta f:$004202
    .a8
    lda #$1E
    sta f:$004203
    rep #$20
    nop
    nop
    nop
    lda f:$004216
    tay
    jsr clear_message_queue_line
    sep #$20
    .a8
    lda #$60
    sta a:message_queue_buffer,Y
    iny
    inc $9F
    inc $A1
    lda $A1
    .a8
    cmp #$0C
    bne allocate_message_queue_line_c05d07
    .a8
    lda #$00
    sta $A1
allocate_message_queue_line_c05d07:
    rts
