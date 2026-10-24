; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-objects.md.
.setcpu "65816"
.smart
.a8
.i16

project_packed_spell_entity_sprite_record_long = $C12E94

.segment "CODE"
.org $F9B8
project_spell_entity_trail_sprite_frames:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0006
    tcd
    tcs
    stz $05
    .a16
    lda #$0014
    sta $01
project_spell_entity_trail_sprite_frames_d3f9ca:
    dec a:$0008,X
    bne project_spell_entity_trail_sprite_frames_d3fa04
    inc $05
    txy
    ldx a:$0006,Y
    lda a:$0002,Y
    pha
    lda a:$0004,Y
    pha
    sty $03
    jsl f:project_packed_spell_entity_sprite_record_long
    txa
    ldx $03
    sta a:$0006,X
    ply
    ply
    dec a:$000C,X
    beq project_spell_entity_trail_sprite_frames_d3fa04
    .a16
    lda #$0001
    sta a:$0008,X
    lda a:$000C,X
    .a16
    cmp #$0003
    bne project_spell_entity_trail_sprite_frames_d3fa04
    .a16
    lda #$0020
    sta a:$0008,X
project_spell_entity_trail_sprite_frames_d3fa04:
    clc
    txa
    .a16
    adc #$0010
    tax
    tax
    dec $01
    bne project_spell_entity_trail_sprite_frames_d3f9ca
    lda $05
    sta $05,S
    tsc
    clc
    .a16
    adc #$0004
    tcs
    pla
    plp
    pld
    rts
