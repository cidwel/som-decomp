; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


hero_ai_attribute_adjustment_table = $C0473F

.segment "CODE"
.org $464F
load_hero_level_attributes_and_controller_adjustments:
    lda a:$E1E7,X
    sec
    .a8
    sbc #$80
    rep #$20
    .a16
    and #$00FF
    tay
    .a16
    lda #$0318
    sta $A4
    .a16
    lda #$0000
load_hero_level_attributes_and_controller_adjustments_c04663:
    dey
    bmi load_hero_level_attributes_and_controller_adjustments_c0466b
    clc
    adc $A4
    bra load_hero_level_attributes_and_controller_adjustments_c04663
load_hero_level_attributes_and_controller_adjustments_c0466b:
    sta $B4
    lda a:$E181,X
    .a16
    and #$00FF
    asl
    asl
    asl
    clc
    adc $B4
    txy
    tax
    lda f:$D04210,X
    sta a:$E184,Y
    sep #$20
    lda f:$D04212,X
    sta a:$E187,Y
    lda f:$D04213,X
    sta a:$E188,Y
    lda f:$D04214,X
    sta a:$E189,Y
    lda f:$D04215,X
    sta a:$E18A,Y
    lda f:$D04216,X
    sta a:$E18B,Y
    lda f:$D04217,X
    sta a:$E18C,Y
    lda a:$E181,Y
    sta f:$004202
    .a8
    lda #$03
    sta f:$004203
    nop
    nop
    nop
    rep #$20
    lda f:$004216
    tax
    lda f:$D04B58,X
    sta a:$E17D,Y
    sep #$20
    lda f:$D04B5A,X
    sta a:$E17F,Y
    ldx $BD
    lda $BA
    inc
    .a8
    cmp #$03
    bne load_hero_level_attributes_and_controller_adjustments_c046df
    inc
load_hero_level_attributes_and_controller_adjustments_c046df:
    sta $A4
    lda a:$00D9
    .a8
    and #$0F
    cmp $A4
    beq load_hero_level_attributes_and_controller_adjustments_c046fe
    lda a:$00DA
    .a8
    and #$0F
    cmp $A4
    beq load_hero_level_attributes_and_controller_adjustments_c046fe
    lda a:$00DB
    .a8
    and #$0F
    cmp $A4
    beq load_hero_level_attributes_and_controller_adjustments_c046fe
    bra load_hero_level_attributes_and_controller_adjustments_c046ff
load_hero_level_attributes_and_controller_adjustments_c046fe:
    rts
load_hero_level_attributes_and_controller_adjustments_c046ff:
    .a8
    lda #$00
    xba
    lda $BA
    tay
    lda a:$CC7A,Y
    tax
    lda f:hero_ai_attribute_adjustment_table,X
    sta $A4
    .a8
    lda #$03
    sta $A6
    ldx $BD
load_hero_level_attributes_and_controller_adjustments_c04715:
    lda $A4
    .a8
    and #$03
    beq load_hero_level_attributes_and_controller_adjustments_c04733
    .a8
    cmp #$01
    bne load_hero_level_attributes_and_controller_adjustments_c04724
    inc a:$E188,X
    bra load_hero_level_attributes_and_controller_adjustments_c04733
load_hero_level_attributes_and_controller_adjustments_c04724:
    .a8
    cmp #$02
    bne load_hero_level_attributes_and_controller_adjustments_c04730
    inc a:$E188,X
    inc a:$E188,X
    bra load_hero_level_attributes_and_controller_adjustments_c04733
load_hero_level_attributes_and_controller_adjustments_c04730:
    dec a:$E188,X
load_hero_level_attributes_and_controller_adjustments_c04733:
    lsr $A4
    lsr $A4
    inx
    dec $A6
    bne load_hero_level_attributes_and_controller_adjustments_c04715
    ldx $BD
    rts
