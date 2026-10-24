; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


appearance_attribute_adjustment_table = $C04B79

.segment "CODE"
.org $4AFF
apply_packed_appearance_attribute_adjustments:
    .a8
    lda #$00
    xba
    txy
    phy
    .i16
    ldy #$1002
    lda [$C0],Y
    ply
    .a8
    and #$03
    tax
    lda f:appearance_attribute_adjustment_table,X
    clc
    adc a:$E188,Y
    sta a:$E188,Y
    phy
    .i16
    ldy #$1001
    lda [$C0],Y
    ply
    lsr
    lsr
    lsr
    lsr
    lsr
    lsr
    tax
    lda f:appearance_attribute_adjustment_table,X
    clc
    adc a:$E189,Y
    sta a:$E189,Y
    phy
    .i16
    ldy #$1001
    lda [$C0],Y
    ply
    lsr
    lsr
    lsr
    lsr
    .a8
    and #$03
    tax
    lda f:appearance_attribute_adjustment_table,X
    clc
    adc a:$E18A,Y
    sta a:$E18A,Y
    phy
    .i16
    ldy #$1001
    lda [$C0],Y
    ply
    lsr
    lsr
    .a8
    and #$03
    tax
    lda f:appearance_attribute_adjustment_table,X
    clc
    adc a:$E18B,Y
    sta a:$E18B,Y
    phy
    .i16
    ldy #$1001
    lda [$C0],Y
    ply
    .a8
    and #$03
    tax
    lda f:appearance_attribute_adjustment_table,X
    clc
    adc a:$E18C,Y
    sta a:$E18C,Y
    ldx $BD
    rts
