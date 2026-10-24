; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-spell-remaining.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_reverse_combat_message_slot = $5D08
append_rom_message_text = $5C2A

.segment "CODE"
.org $5BA4
enqueue_lunar_magic_effect_notice:
    asl
    tax
    rep #$20
    lda f:$C05E59,X
    tax
    sep #$20
    jsr allocate_reverse_combat_message_slot
    jsr append_rom_message_text
    rtl
