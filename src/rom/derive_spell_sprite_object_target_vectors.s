; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-motion.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c12ebd = $C12EBD
scale_native_spell_sprite_angle_coefficient_long = $C12EC5
scale_native_spell_sprite_quarter_turn_coefficient_long = $C12EC1

.segment "CODE"
.org $F0B1
derive_spell_sprite_object_target_vectors:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$000C
    tcd
    tcs
    sep #$20
    stx $01
    lda a:$0238,X
    xba
    .a8
    lda #$52
    jsl f:routine_c12ebd
    rep #$20
    ldx $01
    lda a:$0230,X
    sec
    sbc a:$0235,X
    stz $03
    .a16
    bit #$8000
    beq derive_spell_sprite_object_target_vectors_d3f0e2
    dec $03
    .a16
    eor #$FFFF
    inc
derive_spell_sprite_object_target_vectors_d3f0e2:
    sep #$20
    lsr
    xba
    lda a:$023A,X
    rep #$20
    pha
    jsl f:scale_native_spell_sprite_angle_coefficient_long
    asl $03
    bcc derive_spell_sprite_object_target_vectors_d3f0f8
    .a16
    eor #$FFFF
    inc
derive_spell_sprite_object_target_vectors_d3f0f8:
    sta $05
    pla
    jsl f:scale_native_spell_sprite_quarter_turn_coefficient_long
    asl $03
    bcc derive_spell_sprite_object_target_vectors_d3f107
    .a16
    eor #$FFFF
    inc
derive_spell_sprite_object_target_vectors_d3f107:
    sta $07
    ldx $01
    lda a:$0232,X
    sec
    sbc a:$0238,X
    stz $03
    .a16
    bit #$8000
    beq derive_spell_sprite_object_target_vectors_d3f11f
    dec $03
    .a16
    eor #$FFFF
    inc
derive_spell_sprite_object_target_vectors_d3f11f:
    sep #$20
    lsr
    xba
    lda a:$023A,X
    rep #$20
    pha
    jsl f:scale_native_spell_sprite_angle_coefficient_long
    asl $03
    bcc derive_spell_sprite_object_target_vectors_d3f135
    .a16
    eor #$FFFF
    inc
derive_spell_sprite_object_target_vectors_d3f135:
    sta $09
    pla
    jsl f:scale_native_spell_sprite_quarter_turn_coefficient_long
    asl $03
    bcc derive_spell_sprite_object_target_vectors_d3f144
    .a16
    eor #$FFFF
    inc
derive_spell_sprite_object_target_vectors_d3f144:
    sta $0B
    clc
    adc $05
    tax
    lda $07
    sec
    sbc $09
    tay
    tsc
    clc
    .a16
    adc #$000C
    tcs
    plp
    pld
    rts
