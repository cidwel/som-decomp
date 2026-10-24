; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-status-child.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_reverse_combat_message_slot = $5D08
append_rom_message_text = $5C2A

.segment "CODE"
.org $5BCA
enqueue_numeric_boss_attack_notice_preserving_context:
    phd
    phb
    php
    rep #$30
    asl
    tax
    .a16
    lda #$0300
    tcd
    lda f:$C05E0B,X
    tax
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    jsr allocate_reverse_combat_message_slot
    jsr append_rom_message_text
    plp
    plb
    pld
    rtl
