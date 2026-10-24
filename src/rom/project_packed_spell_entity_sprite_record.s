; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-projection.md.
.setcpu "65816"
.smart
.a8
.i16

hide_spell_entity_sprite_oam_entry = $4090
publish_spell_entity_individual_sprite_projection = $4118

.segment "CODE"
.org $386F
project_packed_spell_entity_sprite_record:
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
    phx
    lda f:$DCF800,X
    sta $01
    ldx a:$0000,Y
    sep #$20
    lda $01
    .a8
    cmp #$FF
    beq project_packed_spell_entity_sprite_record_c138de
    rep #$20
    .a16
    and #$003F
    .a16
    cmp #$0030
    bcc project_packed_spell_entity_sprite_record_c1389f
    clc
    .a16
    adc #$0010
project_packed_spell_entity_sprite_record_c1389f:
    clc
    .a16
    adc #$0100
    sta a:$0006,X
    sep #$20
    lda $01
    .a8
    and #$C0
    sta a:$0000,X
    lda $02
    lsr
    lsr
    rep #$20
    .a16
    and #$003C
    sec
    .a16
    sbc #$0020
    clc
    adc $0A
    sta a:$0002,X
    sep #$20
    lda $02
    asl
    asl
    rep #$20
    .a16
    and #$003C
    sec
    .a16
    sbc #$0020
    clc
    adc $08
    sta a:$0004,X
    sep #$20
    jsr publish_spell_entity_individual_sprite_projection
    bra project_packed_spell_entity_sprite_record_c138e1
project_packed_spell_entity_sprite_record_c138de:
    jsr hide_spell_entity_sprite_oam_entry
project_packed_spell_entity_sprite_record_c138e1:
    plx
    inx
    inx
    plb
    pla
    pla
    plp
    pld
    rts
