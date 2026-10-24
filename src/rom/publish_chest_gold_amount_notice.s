; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-chest-reward.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_reverse_combat_message_slot = $5D08
append_rom_message_text = $5C2A
format_word_into_combat_message_digits = $5C6C

.segment "CODE"
.org $58C8
publish_chest_gold_amount_notice:
    pha
    jsr allocate_reverse_combat_message_slot
    pla
    sta $D0
    stz $D1
    jsr format_word_into_combat_message_digits
    .i16
    ldx #$6294
    jsr append_rom_message_text
    rtl
