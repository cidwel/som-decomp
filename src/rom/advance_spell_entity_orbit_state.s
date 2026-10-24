; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-orbit-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c12ebd = $C12EBD
scale_spell_entity_signed_angle_vector_long = $C12EC9
scale_spell_entity_signed_quarter_turn_vector_long = $C12ECD

.segment "CODE"
.org $F398
advance_spell_entity_orbit_state:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0010
    tcd
    tcs
    stx $07
    .a16
    lda #$0005
    sta a:$00E8,X
    lda a:$00EA,X
    sta $03
    inc
    .a16
    cmp #$0008
    bcc advance_spell_entity_orbit_state_d3f3e2
    lda a:$00EC,X
    inc
    .a16
    cmp #$0003
    bcc advance_spell_entity_orbit_state_d3f3dc
    sep #$20
    lda a:$00E2,X
    xba
    .a8
    lda #$49
    rep #$20
    jsl f:routine_c12ebd
    ldx $07
    lda a:$00E6,X
    .a16
    eor #$FFFF
    inc
    sta a:$00E6,X
    .a16
    lda #$0000
advance_spell_entity_orbit_state_d3f3dc:
    sta a:$00EC,X
    .a16
    lda #$0000
advance_spell_entity_orbit_state_d3f3e2:
    sta a:$00EA,X
    lda a:$00EC,X
    .a16
    cmp #$0002
    bcc advance_spell_entity_orbit_state_d3f3f0
    jmp advance_spell_entity_orbit_state_d3f473
advance_spell_entity_orbit_state_d3f3f0:
    lda a:$00E4,X
    sta $09
    clc
    adc a:$00E6,X
    sta a:$00E4,X
    lda a:$00E0,X
    sta $0D
    lda a:$00E2,X
    sta $0B
    .a16
    lda #$001C
    sep #$20
    xba
    lda $03
    rep #$20
    sta f:$004202
    pha
    pla
    lda f:$004216
    clc
    adc $07
    sta $03
    tax
    clc
    .a16
    adc #$000C
    sta $05
    .a16
    lda #$0001
    sta a:$0018,X
    stz a:$001A,X
    .i16
    ldx #$0030
    lda $09
    jsl f:scale_spell_entity_signed_angle_vector_long
    txa
    sta $0F
    .a16
    eor #$FFFF
    inc
    clc
    adc $0D
    ldx $05
    sta a:$0008,X
    lda $0F
    clc
    adc $0D
    ldx $03
    sta a:$0008,X
    .i16
    ldx #$0030
    lda $09
    jsl f:scale_spell_entity_signed_quarter_turn_vector_long
    txa
    sta $0F
    .a16
    eor #$FFFF
    inc
    clc
    adc $0B
    ldx $05
    sta a:$000A,X
    lda $0F
    clc
    adc $0B
    ldx $03
    sta a:$000A,X
advance_spell_entity_orbit_state_d3f473:
    tsc
    clc
    .a16
    adc #$0010
    tcs
    plp
    pld
    rts
