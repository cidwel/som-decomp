; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $396D
prepare_boss_spell_targets:
    sta $95
    sep #$20
    lda $95
    sta a:$0170,X
    stz a:$0177,X
    stz a:$0178,X
    stz a:$0179,X
    stz a:$017A,X
    lda $96
    .a8
    bit #$02
    bne prepare_boss_spell_targets_c239e2
    .a8
    bit #$01
    bne prepare_boss_spell_targets_c2399b
    .a8
    lda #$01
    sta a:$0176,X
    lda a:$00A9,X
    inc
    sta a:$0178,X
    rep #$20
    rts
prepare_boss_spell_targets_c2399b:
    rep #$20
    stz $24
    stz $26
prepare_boss_spell_targets_c239a1:
    lda $26
    xba
    asl
    .a16
    adc #$E000
    tay
    lda a:$0000,Y
    .a16
    and #$00FF
    .a16
    cmp #$0001
    bne prepare_boss_spell_targets_c239d0
    lda a:$0190,Y
    .a16
    bit #$8000
    bne prepare_boss_spell_targets_c239d0
    lda $87
    clc
    adc $24
    tax
    sep #$20
    lda $26
    inc
    sta a:$0178,X
    rep #$20
    inc $24
    ldx $87
prepare_boss_spell_targets_c239d0:
    inc $26
    lda $26
    .a16
    cmp #$0003
    bcc prepare_boss_spell_targets_c239a1
    sep #$20
    lda $24
    sta a:$0176,X
    bra prepare_boss_spell_targets_c23a3e
prepare_boss_spell_targets_c239e2:
    .a8
    bit #$01
    bne prepare_boss_spell_targets_c239f5
    .a8
    lda #$01
    sta a:$0176,X
    lda $8B
    clc
    .a8
    adc #$04
    sta a:$0178,X
    bra prepare_boss_spell_targets_c23a3e
prepare_boss_spell_targets_c239f5:
    rep #$20
    stz $24
    stz $26
prepare_boss_spell_targets_c239fb:
    lda $26
    xba
    asl
    .a16
    adc #$E600
    tay
    lda a:$0000,Y
    .a16
    and #$00FF
    .a16
    cmp #$0001
    bne prepare_boss_spell_targets_c23a2c
    lda a:$0190,Y
    .a16
    bit #$8000
    bne prepare_boss_spell_targets_c23a2c
    lda $87
    clc
    adc $24
    tax
    sep #$20
    lda $26
    clc
    .a8
    adc #$04
    sta a:$0178,X
    rep #$20
    inc $24
    ldx $87
prepare_boss_spell_targets_c23a2c:
    inc $26
    lda $26
    .a16
    cmp #$0003
    bcc prepare_boss_spell_targets_c239fb
    sep #$20
    lda $24
    sta a:$0176,X
    bra prepare_boss_spell_targets_c23a3e
prepare_boss_spell_targets_c23a3e:
    rep #$20
    rts
