; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-oam.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3E9C
project_spell_entity_sprite_record_to_oam:
    phd
    php
    rep #$20
    phb
    phx
    tsc
    tcd
    sep #$20
    txy
    lda a:$000A,X
    sta $01
    rep #$20
    .a16
    and #$00FF
    asl
    asl
    clc
    adc a:$841E
    tax
    lda a:$0008,Y
    .a16
    and #$00FF
    beq project_spell_entity_sprite_record_to_oam_c13ed8
    lda a:$0002,Y
    clc
    .a16
    adc #$0010
    .a16
    cmp #$00F0
    bcs project_spell_entity_sprite_record_to_oam_c13ed8
    lda a:$0004,Y
    clc
    .a16
    adc #$0010
    .a16
    cmp #$0110
    bcc project_spell_entity_sprite_record_to_oam_c13ee2
project_spell_entity_sprite_record_to_oam_c13ed8:
    sep #$20
    .a8
    lda #$F0
    sta a:$0001,X
    jmp project_spell_entity_sprite_record_to_oam_c13f6b
project_spell_entity_sprite_record_to_oam_c13ee2:
    sep #$20
    lda a:$000B,Y
    .a8
    and #$03
    asl
    asl
    asl
    pha
    lda a:$0001,Y
    .a8
    and #$07
    ora $01,S
    asl
    sta $01,S
    lda a:$0007,Y
    .a8
    and #$01
    ora $01,S
    sta $01,S
    lda a:$0000,Y
    .a8
    and #$C0
    ora $01,S
    sta a:$0003,X
    lda a:$0006,Y
    sta a:$0002,X
    lda a:$0002,Y
    sta a:$0001,X
    lda a:$0004,Y
    sta a:$0000,X
    lda a:$8421
    bne project_spell_entity_sprite_record_to_oam_c13f6a
    lda a:$0000,Y
    .a8
    and #$02
    sta $01,S
    lda a:$0005,Y
    .a8
    and #$01
    ora $01,S
    sta $01,S
    lda $01
    .a8
    and #$03
    inc
    sta $02
    .a8
    lda #$03
    sta $03
    pla
project_spell_entity_sprite_record_to_oam_c13f3d:
    dec $02
    beq project_spell_entity_sprite_record_to_oam_c13f49
    asl
    asl
    asl $03
    asl $03
    bra project_spell_entity_sprite_record_to_oam_c13f3d
project_spell_entity_sprite_record_to_oam_c13f49:
    pha
    lda $03
    .a8
    eor #$FF
    sta $03
    lda $01
    lsr
    lsr
    rep #$20
    .a16
    and #$001F
    clc
    adc a:$841E
    tax
    sep #$20
    lda a:$0200,X
    and $03
    ora $01,S
    sta a:$0200,X
project_spell_entity_sprite_record_to_oam_c13f6a:
    pla
project_spell_entity_sprite_record_to_oam_c13f6b:
    pla
    pla
    pla
    plp
    pld
    rts
