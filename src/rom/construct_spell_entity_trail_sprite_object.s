; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-init.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_spell_entity_bytes_long = $C12E78
draw_spell_entity_bounded_random_long = $C12ED1
position_spell_entity_from_actor_long = $C12EB1
routine_c12e80 = $C12E80

.segment "CODE"
.org $F8C2
construct_spell_entity_trail_sprite_object:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0007
    tcd
    tcs
    lda $08,S
    sep #$20
    sta $01
    xba
    lsr
    lsr
    lsr
    lsr
    lsr
    lsr
    sta $05
    sty $06
    lda a:$0018,X
    lsr
    lsr
    lsr
    lsr
    .a8
    and #$07
    sta $04
    .i16
    ldx #$0156
    .a8
    lda #$00
    jsl f:allocate_and_fill_spell_entity_bytes_long
    stx $02
    clc
    rep #$20
    txa
    .a16
    adc #$0140
    tax
    sep #$20
    lda $01
    jsl f:position_spell_entity_from_actor_long
    ldx $02
    lda $06
    sta a:$0146,X
    lda $07
    sta a:$0144,X
    .a8
    lda #$01
    sta a:$0152,X
    .a8
    lda #$04
    jsl f:draw_spell_entity_bounded_random_long
    inc
    inc
    ldx $02
    sta a:$014E,X
    lda $05
    sta a:$014C,X
    rep #$20
    .a16
    and #$00FF
    beq construct_spell_entity_trail_sprite_object_d3f93d
    dec
    beq construct_spell_entity_trail_sprite_object_d3f945
    dec
    beq construct_spell_entity_trail_sprite_object_d3f94d
    .a16
    lda #$FFF0
    sta a:$0148,X
    bra construct_spell_entity_trail_sprite_object_d3f953
construct_spell_entity_trail_sprite_object_d3f93d:
    .a16
    lda #$0010
    sta a:$014A,X
    bra construct_spell_entity_trail_sprite_object_d3f953
construct_spell_entity_trail_sprite_object_d3f945:
    .a16
    lda #$0010
    sta a:$0148,X
    bra construct_spell_entity_trail_sprite_object_d3f953
construct_spell_entity_trail_sprite_object_d3f94d:
    .a16
    lda #$FFF0
    sta a:$014A,X
construct_spell_entity_trail_sprite_object_d3f953:
    .a16
    lda #$0014
    sta $08
construct_spell_entity_trail_sprite_object_d3f958:
    phx
    .a16
    lda #$000F
    jsl f:routine_c12e80
    lda $04
    sta a:$0001,X
    txa
    plx
    sta a:$0000,X
    clc
    txa
    .a16
    adc #$0010
    tax
    dec $08
    bne construct_spell_entity_trail_sprite_object_d3f958
    ldx $02
    tsc
    clc
    .a16
    adc #$0009
    tcs
    plp
    pld
    rts
