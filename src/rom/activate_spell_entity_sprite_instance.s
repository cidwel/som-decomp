; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-sprite-activation-literal.md.
.setcpu "65816"
.smart
.a8
.i16

find_free_spell_entity_sprite_instance = $3F71
find_free_spell_entity_sprite_quad = $3FD0

.segment "CODE"
.org $402F
activate_spell_entity_sprite_instance:
    phd
    php
    rep #$30
    pha
    tsc
    tcd
    pla
    phx
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    sta $02
    lda a:$8420
    beq activate_spell_entity_sprite_instance_c1405e
    lda $02
    jsr find_free_spell_entity_sprite_instance
    .i16
    cpx #$0000
    beq activate_spell_entity_sprite_instance_c1408a
    .a8
    lda #$01
    sta a:$0008,X
    lda $02
    sta a:$000B,X
    bra activate_spell_entity_sprite_instance_c1408a
activate_spell_entity_sprite_instance_c1405e:
    lda $02
    jsr find_free_spell_entity_sprite_quad
    .i16
    cpx #$0000
    beq activate_spell_entity_sprite_instance_c1408a
    .a8
    lda #$01
    sta a:$0008,X
    lda $02
    sta a:$000B,X
    .a8
    lda #$04
    sta $01
activate_spell_entity_sprite_instance_c14076:
    ldy a:$0000,X
    .a8
    lda #$01
    sta a:$0008,Y
    lda $02
    sta a:$000B,Y
    inx
    inx
    dec $01
    bne activate_spell_entity_sprite_instance_c14076
    plx
activate_spell_entity_sprite_instance_c1408a:
    plb
    pla
    pla
    plp
    pld
    rts
