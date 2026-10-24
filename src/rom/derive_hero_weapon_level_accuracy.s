; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4A0C
derive_hero_weapon_level_accuracy:
    lda a:$E19C,X
    asl
    clc
    adc a:$E19C,X
    sta $A4
    .i16
    ldy #$1006
    clc
    adc [$C0],Y
    sta $A4
    .a8
    lda #$04
    cmp a:$E1E4,X
    bcs derive_hero_weapon_level_accuracy_c04a27
    lsr $A4
derive_hero_weapon_level_accuracy_c04a27:
    lda $A4
    sta a:$E196,X
    rts
