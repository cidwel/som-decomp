; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-spell-remaining.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_message_queue_line = $5CCF
append_rom_message_text = $5C2A

.segment "CODE"
.org $5BB6
enqueue_wall_expiration_notice:
    jsr allocate_message_queue_line
    .i16
    ldx #$6310
    jsr append_rom_message_text
    rtl
