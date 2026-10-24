; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-chest-reward.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_message_queue_line = $5CCF
append_rom_message_text = $5C2A

.segment "CODE"
.org $58F1
publish_full_chest_inventory_notice:
    jsr allocate_message_queue_line
    .a8
    lda #$55
    sta a:$FE00,Y
    iny
    lda $A6
    sta a:$FE00,Y
    iny
    .i16
    ldx #$62C6
    jsr append_rom_message_text
    rtl
