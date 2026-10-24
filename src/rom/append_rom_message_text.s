; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


message_queue_buffer = $FE00

.segment "CODE"
.org $5C2A
append_rom_message_text:
append_rom_message_text_c05c2a:
    lda f:$C00000,X
    beq append_rom_message_text_c05c37
    sta a:message_queue_buffer,Y
    iny
    inx
    bra append_rom_message_text_c05c2a
append_rom_message_text_c05c37:
    rts
