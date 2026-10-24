; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-groups.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c12e80 = $C12E80

.segment "CODE"
.org $392B
allocate_spell_entity_sprite_pointer_group:
    phd
    php
    rep #$30
    pha
    tsc
    tcd
    pla
    phx
    sep #$20
    sta $01
    xba
    sta $02
allocate_spell_entity_sprite_pointer_group_c1393b:
    phx
    .a8
    lda #$0F
    jsl f:routine_c12e80
    lda $02
    sta a:$0001,X
    rep #$20
    txa
    plx
    sta a:$0000,X
    sep #$20
    inx
    inx
    dec $01
    bne allocate_spell_entity_sprite_pointer_group_c1393b
    pla
    pla
    plp
    pld
    rts
