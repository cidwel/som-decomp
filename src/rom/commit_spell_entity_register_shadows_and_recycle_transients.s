; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-registers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $45E0
commit_spell_entity_register_shadows_and_recycle_transients:
    phd
    php
    rep #$20
    phx
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    lda a:$8432
    sta $01
    .i16
    ldy #$842A
commit_spell_entity_register_shadows_and_recycle_transients_c145f8:
    lda a:$0001,Y
    .a16
    and #$00FF
    beq commit_spell_entity_register_shadows_and_recycle_transients_c1463c
    clc
    adc a:$8426
    tax
    pha
    lda a:$0000,X
    .a16
    and #$00FF
    tay
    lda a:$0002,X
    sep #$20
    sta ($01),Y
    tyx
    lda f:$DCFC8E,X
    beq commit_spell_entity_register_shadows_and_recycle_transients_c14637
    .a8
    cmp #$01
    bne commit_spell_entity_register_shadows_and_recycle_transients_c14625
    iny
    xba
    sta ($01),Y
    bra commit_spell_entity_register_shadows_and_recycle_transients_c14637
commit_spell_entity_register_shadows_and_recycle_transients_c14625:
    lda ($01),Y
    rep #$20
    pha
    lda f:$DCFC8E,X
    .a16
    and #$00FF
    tay
    pla
    sta ($01),Y
    sep #$20
commit_spell_entity_register_shadows_and_recycle_transients_c14637:
    ply
    rep #$20
    bra commit_spell_entity_register_shadows_and_recycle_transients_c145f8
commit_spell_entity_register_shadows_and_recycle_transients_c1463c:
    .i16
    ldy #$842E
commit_spell_entity_register_shadows_and_recycle_transients_c1463f:
    lda a:$0001,Y
    .a16
    and #$00FF
    beq commit_spell_entity_register_shadows_and_recycle_transients_c14691
    clc
    adc a:$8426
    tax
    pha
    .i16
    cpy #$842E
    beq commit_spell_entity_register_shadows_and_recycle_transients_c1465b
    lda a:$8428
    sta a:$0000,Y
    sty a:$8428
commit_spell_entity_register_shadows_and_recycle_transients_c1465b:
    lda a:$0000,X
    .a16
    and #$00FF
    tay
    lda a:$0002,X
    sep #$20
    sta ($01),Y
    tyx
    lda f:$DCFC8E,X
    beq commit_spell_entity_register_shadows_and_recycle_transients_c1468c
    .a8
    cmp #$01
    bne commit_spell_entity_register_shadows_and_recycle_transients_c1467a
    iny
    xba
    sta ($01),Y
    bra commit_spell_entity_register_shadows_and_recycle_transients_c1468c
commit_spell_entity_register_shadows_and_recycle_transients_c1467a:
    lda ($01),Y
    rep #$20
    pha
    lda f:$DCFC8E,X
    .a16
    and #$00FF
    tay
    pla
    sta ($01),Y
    sep #$20
commit_spell_entity_register_shadows_and_recycle_transients_c1468c:
    ply
    rep #$20
    bra commit_spell_entity_register_shadows_and_recycle_transients_c1463f
commit_spell_entity_register_shadows_and_recycle_transients_c14691:
    .i16
    cpy #$842E
    beq commit_spell_entity_register_shadows_and_recycle_transients_c1469f
    lda a:$8428
    sta a:$0000,Y
    sty a:$8428
commit_spell_entity_register_shadows_and_recycle_transients_c1469f:
    stz a:$842E
    .a16
    lda #$842E
    sta a:$8430
    plb
    sep #$20
    pla
    pla
    plp
    pld
    rts
