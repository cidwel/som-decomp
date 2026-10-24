; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-spell-reflection.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_reverse_combat_message_slot = $5D08
append_rom_message_text = $5C2A

.segment "CODE"
.org $595F
enqueue_unique_spell_reflection_notice:
    .i16
    ldx #$FFE2
    .a8
    lda #$0B
    sta $B2
enqueue_unique_spell_reflection_notice_c05966:
    rep #$20
    txa
    clc
    .a16
    adc #$001E
    tax
    sep #$20
    lda a:$FE00,X
    beq enqueue_unique_spell_reflection_notice_c0597d
    lda a:$FE1D,X
    .a8
    cmp #$01
    bne enqueue_unique_spell_reflection_notice_c0597d
    rtl
enqueue_unique_spell_reflection_notice_c0597d:
    dec $B2
    bne enqueue_unique_spell_reflection_notice_c05966
    jsr allocate_reverse_combat_message_slot
    .a8
    lda #$01
    sta a:$FE1C,Y
    .i16
    ldx #$62A3
    jsr append_rom_message_text
    rtl
