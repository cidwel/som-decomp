; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_message_queue_line = $5CCF
append_rom_message_text = $5C2A

.segment "CODE"
.org $58AF
enqueue_generic_actor_status_notice:
    jsr allocate_message_queue_line
    .i16
    ldx #$62E2
    jsr append_rom_message_text
    rtl
