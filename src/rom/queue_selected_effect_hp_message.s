; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_message_queue_line = $5CCF
append_rom_message_text = $5C2A

.segment "CODE"
.org $5BC0
queue_selected_effect_hp_message:
    jsr allocate_message_queue_line
    .i16
    ldx #$6303
    jsr append_rom_message_text
    rtl
