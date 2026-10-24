; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4B90
apply_single_armor_attribute_flags:
    sta $A4
    .a8
    lda #$04
    sta $A6
    .a8
    lda #$05
    sta $AA
    lda $A4
    bit a:$0040
    beq apply_single_armor_attribute_flags_c04ba5
    .a8
    lda #$FE
    sta $AA
apply_single_armor_attribute_flags_c04ba5:
    lda $A4
    .a8
    bit #$10
    beq apply_single_armor_attribute_flags_c04bb4
    lda $AA
    clc
    adc a:$E188,X
    sta a:$E188,X
apply_single_armor_attribute_flags_c04bb4:
    asl $A4
    inx
    dec $A6
    bne apply_single_armor_attribute_flags_c04ba5
    ldx $BD
    rts
