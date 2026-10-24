; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-motion.md.
.setcpu "65816"
.smart
.a8
.i16

get_spell_sprite_object_history_entry = $EFAE
project_spell_sprite_object_child = $EF74
scale_native_spell_sprite_angle_coefficient_long = $C12EC5
scale_native_spell_sprite_quarter_turn_coefficient_long = $C12EC1

.segment "CODE"
.org $EFC4
advance_spell_sprite_object_motion:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$000A
    tcd
    tcs
    lda $0B,S
    sep #$20
    stx $03
    xba
    lda a:$023A,X
    rep #$20
    pha
    jsl f:scale_native_spell_sprite_angle_coefficient_long
    sta $07
    pla
    jsl f:scale_native_spell_sprite_quarter_turn_coefficient_long
    sta $09
    ldx $03
    clc
    adc a:$0237,X
    sta a:$0237,X
    sep #$20
    lda $0A
    .a8
    and #$80
    beq advance_spell_sprite_object_motion_d3effd
    .a8
    lda #$FF
advance_spell_sprite_object_motion_d3effd:
    adc a:$0239,X
    sta a:$0239,X
    rep #$20
    lda $07
    clc
    adc a:$0234,X
    sta a:$0234,X
    sep #$20
    lda $08
    .a8
    and #$80
    beq advance_spell_sprite_object_motion_d3f018
    .a8
    lda #$FF
advance_spell_sprite_object_motion_d3f018:
    adc a:$0236,X
    sta a:$0236,X
    lda a:$023A,X
    clc
    .a8
    adc #$10
    lsr
    lsr
    lsr
    lsr
    lsr
    sta $0B
    lda a:$023B,X
    inc
    .a8
    cmp #$78
    bcc advance_spell_sprite_object_motion_d3f035
    .a8
    lda #$00
advance_spell_sprite_object_motion_d3f035:
    sta a:$023B,X
    jsr get_spell_sprite_object_history_entry
    rep #$20
    lda a:$0238,X
    sta a:$0002,Y
    lda a:$0235,X
    sta a:$0000,Y
    .a16
    lda #$000A
    sta $01
    ldx $03
    clc
    txa
    .a16
    adc #$0000
    tax
advance_spell_sprite_object_motion_d3f056:
    stx $05
    lda a:$0007,X
    .a16
    and #$00FF
    .a16
    bit #$0080
    bne advance_spell_sprite_object_motion_d3f087
    ldx $03
    jsr get_spell_sprite_object_history_entry
    ldx $05
    lda a:$0002,Y
    sta a:$0004,X
    lda a:$0000,Y
    sta a:$0002,X
    lda $01
    .a16
    cmp #$0004
    bcc advance_spell_sprite_object_motion_d3f082
    .a16
    lda #$0008
    bra advance_spell_sprite_object_motion_d3f084
advance_spell_sprite_object_motion_d3f082:
    lda $0B
advance_spell_sprite_object_motion_d3f084:
    jsr project_spell_sprite_object_child
advance_spell_sprite_object_motion_d3f087:
    ldx $05
    sep #$20
    lda a:$0007,X
    inc
    .a8
    cmp #$78
    bcc advance_spell_sprite_object_motion_d3f099
    .a8
    bit #$80
    bne advance_spell_sprite_object_motion_d3f099
    .a8
    lda #$00
advance_spell_sprite_object_motion_d3f099:
    sta a:$0007,X
    rep #$20
    clc
    txa
    .a16
    adc #$0008
    tax
    dec $01
    bne advance_spell_sprite_object_motion_d3f056
    tsc
    clc
    .a16
    adc #$000C
    tcs
    plp
    pld
    rts
