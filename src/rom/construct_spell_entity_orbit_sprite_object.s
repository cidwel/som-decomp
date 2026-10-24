; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-orbit-objects.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_sprite_pointer_group_long = $C12EB5
routine_c12e78 = $C12E78
routine_c12eb1 = $C12EB1

.segment "CODE"
.org $F287
construct_spell_entity_orbit_sprite_object:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0006
    tcd
    tcs
    lda $07,S
    sep #$20
    sta $08
    lda a:$0018,X
    lsr
    lsr
    lsr
    lsr
    .a8
    and #$07
    sta $07
    .i16
    ldx #$00EE
    .a8
    lda #$00
    jsl f:routine_c12e78
    stx $05
    clc
    rep #$20
    txa
    .a16
    adc #$00E0
    tax
    sep #$20
    lda $08
    jsl f:routine_c12eb1
    ldx $05
    rep #$20
    .a16
    lda #$0008
    sta $03
construct_spell_entity_orbit_sprite_object_d3f2c8:
    phx
    .a16
    lda #$0002
    sta $01
construct_spell_entity_orbit_sprite_object_d3f2ce:
    phx
    lda $07
    xba
    .a16
    lda #$0004
    jsl f:allocate_spell_entity_sprite_pointer_group_long
    plx
    clc
    txa
    .a16
    adc #$000C
    tax
    dec $01
    bne construct_spell_entity_orbit_sprite_object_d3f2ce
    plx
    clc
    txa
    .a16
    adc #$001C
    tax
    dec $03
    bne construct_spell_entity_orbit_sprite_object_d3f2c8
    ldx $05
    .a16
    lda #$0001
    sta a:$00E8,X
    .a16
    lda #$0010
    sta a:$00E6,X
    tsc
    clc
    .a16
    adc #$0008
    tcs
    plp
    pld
    rts
