; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_message_queue_line = $5CCF
append_actor_name_message_token = $5C06
append_message_byte_decimal = $5C38
append_rom_message_text = $5C2A

.segment "CODE"
.org $5B20
enqueue_actor_level_up_notice:
    stx $B4
    jsr allocate_message_queue_line
    jsr append_actor_name_message_token
    .i16
    ldx #$6256
    jsr append_rom_message_text
    ldx $B4
    lda a:$E181,X
    inc
    jsr append_message_byte_decimal
    .i16
    ldx #$6263
    jsr append_rom_message_text
    ldx $B4
    rts
