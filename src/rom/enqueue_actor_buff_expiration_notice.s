; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_message_queue_line = $5CCF
append_actor_name_message_token = $5C06
append_rom_message_text = $5C2A

.segment "CODE"
.org $58B9
enqueue_actor_buff_expiration_notice:
    phx
    jsr allocate_message_queue_line
    jsr append_actor_name_message_token
    .i16
    ldx #$62F3
    jsr append_rom_message_text
    plx
    rtl
