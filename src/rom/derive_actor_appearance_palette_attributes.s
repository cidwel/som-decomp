; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $49AA
derive_actor_appearance_palette_attributes:
    lda a:$E189,X
    lsr
    lsr
    sta $A4
    phy
    .i16
    ldy #$1007
    lda [$C0],Y
    ply
    clc
    adc $A4
    .a8
    cmp #$63
    bcc derive_actor_appearance_palette_attributes_c049c1
    .a8
    lda #$63
derive_actor_appearance_palette_attributes_c049c1:
    sta a:$E197,X
    phy
    .i16
    ldy #$1008
    lda [$C0],Y
    ply
    clc
    adc a:$E188,X
    sta a:$E198,X
    rep #$20
    lda a:$CC78
    sep #$20
    bne derive_actor_appearance_palette_attributes_c049f1
    lda a:$E19D,X
    bne derive_actor_appearance_palette_attributes_c049f1
    stz a:$E195,X
    rep #$20
    phy
    .i16
    ldy #$1009
    lda [$C0],Y
    ply
    sta a:$E199,X
    sep #$20
derive_actor_appearance_palette_attributes_c049f1:
    phy
    .i16
    ldy #$1005
    lda [$C0],Y
    ply
    sta a:$E194,X
    phy
    .i16
    ldy #$1000
    lda [$C0],Y
    ply
    sta $A4
    lda a:$E1E4,X
    .a8
    and #$80
    ora $A4
    rts
