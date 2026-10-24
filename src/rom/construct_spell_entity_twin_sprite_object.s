; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-twin-objects.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_sprite_pointer_group_long = $C12EB5
routine_c12e78 = $C12E78
routine_c12eb1 = $C12EB1

.segment "CODE"
.org $2CC7
construct_spell_entity_twin_sprite_object:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0002
    tcd
    tcs
    lda $03,S
    sep #$20
    sta $01
    lda a:$0018,X
    lsr
    lsr
    lsr
    lsr
    .a8
    and #$07
    sta $04
    .i16
    ldx #$003A
    .a8
    lda #$00
    jsl f:routine_c12e78
    stx $02
    clc
    rep #$20
    txa
    .a16
    adc #$0034
    tax
    sep #$20
    lda $01
    jsl f:routine_c12eb1
    ldx $02
    .a8
    lda #$14
    sta a:$0039,X
    .a8
    lda #$0A
    sta a:$0018,X
    sta a:$0032,X
    lda $04
    xba
    .a8
    lda #$0A
    jsl f:allocate_spell_entity_sprite_pointer_group_long
    rep #$20
    lda $02
    clc
    .a16
    adc #$001A
    tax
    sep #$20
    lda $04
    xba
    .a8
    lda #$0A
    jsl f:allocate_spell_entity_sprite_pointer_group_long
    ldx $02
    pla
    pla
    pla
    pla
    plp
    pld
    rts
