; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

cap_combat_24bit_value_at_9999999 = $39A4

.segment "CODE"
.org $39CF
add_or_spend_party_gold_with_saved_context:
    phd
    phb
    php
    rep #$10
    sep #$20
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    rep #$20
    pha
    .a16
    lda #$0300
    tcd
    pla
    .i16
    cpx #$0037
    beq add_or_spend_party_gold_with_saved_context_c03a0d
    clc
    adc a:$CC6A
    sta $D0
    sep #$20
    .a8
    lda #$00
    adc a:$CC6C
    sta $D2
    jsr cap_combat_24bit_value_at_9999999
    rep #$20
    lda $D0
    sta a:$CC6A
    sep #$20
    lda $D2
    sta a:$CC6C
    plp
    plb
    pld
    rtl
add_or_spend_party_gold_with_saved_context_c03a0d:
    sta $AE
    lda a:$CC6A
    sec
    sbc $AE
    sta $A6
    sep #$20
    lda a:$CC6C
    .a8
    sbc #$00
    bcs add_or_spend_party_gold_with_saved_context_c03a29
    .a8
    lda #$01
    sta a:$CF0F
    .a8
    lda #$FF
    bra add_or_spend_party_gold_with_saved_context_c03a36
add_or_spend_party_gold_with_saved_context_c03a29:
    sta a:$CC6C
    lda $A6
    sta a:$CC6A
    lda $A7
    sta a:$CC6B
add_or_spend_party_gold_with_saved_context_c03a36:
    plp
    plb
    pld
    rtl
