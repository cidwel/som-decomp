; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-burst-objects.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_spell_entity_bytes_long = $C12E78
draw_spell_entity_bounded_random_long = $C12ED1
position_spell_entity_from_actor_long = $C12EB1
routine_c12e80 = $C12E80
seed_spell_entity_burst_child_velocity = $EA93

.segment "CODE"
.org $EB83
construct_spell_entity_burst_sprite_object:
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
    sta $01
    lda a:$0018,X
    lsr
    lsr
    lsr
    lsr
    .a8
    and #$07
    sta $06
    .i16
    ldx #$0058
    .a8
    lda #$00
    jsl f:allocate_and_fill_spell_entity_bytes_long
    stx $02
    rep #$20
    .a16
    lda #$0032
    sta a:$0054,X
    clc
    txa
    .a16
    adc #$0050
    tax
    lda $01
    jsl f:position_spell_entity_from_actor_long
    ldx $02
    .a16
    lda #$0005
    sta $07
construct_spell_entity_burst_sprite_object_d3ebc6:
    stx $04
    .a16
    lda #$000F
    jsl f:routine_c12e80
    txa
    ldy $04
    sta a:$0000,Y
    ldx $02
    jsr seed_spell_entity_burst_child_velocity
    .a16
    lda #$0080
    jsl f:draw_spell_entity_bounded_random_long
    .a16
    eor #$FFFF
    inc
    ldx $04
    sta a:$000E,X
    clc
    txa
    .a16
    adc #$0010
    tax
    dec $07
    bne construct_spell_entity_burst_sprite_object_d3ebc6
    ldx $02
    tsc
    clc
    .a16
    adc #$0008
    tcs
    plp
    pld
    rts
