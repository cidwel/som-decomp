; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

clear_message_queue_line = $5D33

.segment "CODE"
.org $5D08
allocate_reverse_combat_message_slot:
    lda $A2
    dec
    bpl allocate_reverse_combat_message_slot_c05d0f
    .a8
    lda #$0B
allocate_reverse_combat_message_slot_c05d0f:
    sta $A2
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
    sta a:$FE00,Y
    iny
    inc $9F
    rts
