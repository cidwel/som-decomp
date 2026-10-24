; Recovered Secret of Mana USA routine; behaviour documented in docs/map-oam-spell-frames.md.
.setcpu "65816"
.smart
.a8
.i16

advance_and_publish_spell_frame_sprite = $F683
refresh_spell_frame_random_velocity_groups = $F6C9
reset_spell_frame_sprite_record = $F747

.segment "CODE"
.org $F79F
expand_and_render_spell_frame_group:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0008
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    stx $03
    dec a:$010C,X
    bne expand_and_render_spell_frame_group_d3f7f7
    lda a:$010E,X
    sta a:$010C,X
    lda a:$0108,X
    .a16
    cmp #$0018
    bcs expand_and_render_spell_frame_group_d3f7cc
    inc
    sta a:$0108,X
expand_and_render_spell_frame_group_d3f7cc:
    lda a:$010A,X
    cmp a:$0108,X
    bcc expand_and_render_spell_frame_group_d3f7da
    .a16
    lda #$0000
    sta a:$010A,X
expand_and_render_spell_frame_group_d3f7da:
    sep #$20
    xba
    .a8
    lda #$0A
    rep #$20
    sta f:$004202
    pha
    pla
    lda f:$004216
    clc
    adc $03
    tax
    jsr reset_spell_frame_sprite_record
    ldx $03
    inc a:$010A,X
expand_and_render_spell_frame_group_d3f7f7:
    jsr refresh_spell_frame_random_velocity_groups
    ldx $03
    txa
    clc
    .a16
    adc #$00F0
    sta $07
    lda a:$0108,X
    beq expand_and_render_spell_frame_group_d3f827
    sta $01
expand_and_render_spell_frame_group_d3f80a:
    stx $05
    lda a:$0008,X
    asl
    clc
    adc a:$0008,X
    asl
    clc
    adc $07
    tay
    jsr advance_and_publish_spell_frame_sprite
    lda $05
    clc
    .a16
    adc #$000A
    tax
    dec $01
    bne expand_and_render_spell_frame_group_d3f80a
expand_and_render_spell_frame_group_d3f827:
    plb
    tsc
    clc
    .a16
    adc #$0008
    tcs
    plp
    pld
    rtl
