; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_message_queue_line = $5CCF
append_actor_name_message_token = $5C06
append_rom_message_text = $5C2A

status_message_pointer_table = $5DBB

.segment "CODE"
.org $5A87
queue_actor_status_messages:
    lda a:$E1E7,X
    .a8
    cmp #$83
    bcc queue_actor_status_messages_c05a8f
    rtl
queue_actor_status_messages_c05a8f:
    phx
    phy
    .i16
    ldy #status_message_pointer_table
    sty $B4
    ldy $98
    sty $D8
    sep #$20
    lda a:$E1FB,X
    bmi queue_actor_status_messages_c05aa7
    lda $D9
    .a8
    and #$7F
    sta $D9
queue_actor_status_messages_c05aa7:
    rep #$20
    .a16
    lda #$000F
    sta $D0
    .a16
    lda #$8000
    sta $CC
    sep #$20
    .a8
    lda #$C0
    sta $B6
    rep #$20
queue_actor_status_messages_c05abb:
    lda $CC
    bit $D8
    bne queue_actor_status_messages_c05acc
queue_actor_status_messages_c05ac1:
    dec $D0
    lsr $CC
    bne queue_actor_status_messages_c05abb
    ply
    plx
    sep #$20
    rtl
queue_actor_status_messages_c05acc:
    lda $D0
    asl
    phy
    tay
    lda [$B4],Y
    ply
    tax
    sep #$20
    jsr allocate_message_queue_line
    dey
    .a8
    lda #$C0
    sta a:$FE00,Y
    iny
    phx
    ldx $85
    rep #$20
    txa
    sta a:$FE0F,Y
    lda a:$E190,X
    sta a:$FE11,Y
    sep #$20
    jsr append_actor_name_message_token
    plx
    jsr append_rom_message_text
    rep #$20
    bra queue_actor_status_messages_c05ac1
