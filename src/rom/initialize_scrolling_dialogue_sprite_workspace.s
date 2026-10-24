; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-scroll.md.
.setcpu "65816"
.smart
.a8
.i16

construct_scrolling_dialogue_sprite_list = $D3F4F1
initialize_spell_entity_heap = $3BD3
initialize_spell_entity_oam_workspace = $3D8F

.segment "CODE"
.org $481F
initialize_scrolling_dialogue_sprite_workspace:
    phd
    php
    rep #$20
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    .a16
    lda #$8438
    sec
    .a16
    sbc #$8200
    tax
    jsr initialize_spell_entity_heap
    .a16
    lda #$0F03
    jsr initialize_spell_entity_oam_workspace
    jsl f:construct_scrolling_dialogue_sprite_list
    stx a:$8436
    plb
    plp
    pld
    rts
