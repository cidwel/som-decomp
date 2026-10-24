; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

apply_single_armor_attribute_flags = $4B90

.segment "CODE"
.org $4B7D
apply_three_armor_attribute_flags:
    .i16
    ldy #$3ED0
    lda [$C9],Y
    jsr apply_single_armor_attribute_flags
    lda [$C6],Y
    jsr apply_single_armor_attribute_flags
    lda [$C3],Y
    jsr apply_single_armor_attribute_flags
    rts
