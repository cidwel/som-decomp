; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-chest-reward.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_reverse_combat_message_slot = $5D08
append_rom_message_text = $5C2A

.segment "CODE"
.org $5907
publish_existing_chest_class_notice:
    jsr allocate_reverse_combat_message_slot
    ldx $85
    .a8
    lda #$00
    xba
    lda a:$E1C8,X
    asl
    tax
    rep #$20
    lda f:$C05DEB,X
    tax
    sep #$20
    jsr append_rom_message_text
    rtl
