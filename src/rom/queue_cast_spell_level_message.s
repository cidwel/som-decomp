; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_reverse_combat_message_slot = $5D08
append_message_byte_decimal = $5C38
append_rom_message_text = $5C2A

.segment "CODE"
.org $5AFD
queue_cast_spell_level_message:
    jsr allocate_reverse_combat_message_slot
    .a8
    lda #$56
    sta a:$FE00,Y
    iny
    ldx $83
    lda a:$E170,X
    sta a:$FE00,Y
    iny
    .i16
    ldx #$6251
    jsr append_rom_message_text
    lda $9D
    jsr append_message_byte_decimal
    .a8
    lda #$00
    sta a:$FE00,Y
    rtl
