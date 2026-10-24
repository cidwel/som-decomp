; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

emit_all_actor_effect_sprite_lists = $E88A
emit_alternate_actor_body_sprites = $E6CF
emit_packed_actor_sprite_list = $E640
finish_actor_sprite_emission = $E8C6
prepare_actor_body_list_tail = $E5F5
prepare_and_emit_actor_body_sprites = $E5CE

.segment "CODE"
.org $E4C1
select_and_emit_actor_sprite_lists:
    sep #$20
    lda a:$E084,X
    .a8
    and #$0F
    sta $02
    beq select_and_emit_actor_sprite_lists_c0e4e8
    bit $ED
    bmi select_and_emit_actor_sprite_lists_c0e4eb
    bvs select_and_emit_actor_sprite_lists_c0e4e8
    .i16
    cpx #$0600
    bcs select_and_emit_actor_sprite_lists_c0e4e8
    lda a:$E02F,X
    bne select_and_emit_actor_sprite_lists_c0e553
    lda a:$E060,X
    bne select_and_emit_actor_sprite_lists_c0e4f0
    lda a:$E191,X
    .a8
    bit #$C5
    bne select_and_emit_actor_sprite_lists_c0e553
select_and_emit_actor_sprite_lists_c0e4e8:
    brl finish_actor_sprite_emission
select_and_emit_actor_sprite_lists_c0e4eb:
    lda a:$E060,X
    beq select_and_emit_actor_sprite_lists_c0e553
select_and_emit_actor_sprite_lists_c0e4f0:
    .a8
    cmp #$E0
    bne select_and_emit_actor_sprite_lists_c0e4f7
    jmp emit_all_actor_effect_sprite_lists
select_and_emit_actor_sprite_lists_c0e4f7:
    .a8
    cmp #$20
    beq select_and_emit_actor_sprite_lists_c0e553
    .a8
    cmp #$40
    beq select_and_emit_actor_sprite_lists_c0e527
    .a8
    cmp #$80
    beq select_and_emit_actor_sprite_lists_c0e527
    lda a:$E00E,X
    .a8
    bit #$20
    beq select_and_emit_actor_sprite_lists_c0e511
    lda $F4
    lsr
    bcc select_and_emit_actor_sprite_lists_c0e511
    bcs select_and_emit_actor_sprite_lists_c0e4e8
select_and_emit_actor_sprite_lists_c0e511:
    lda a:$E110,X
    .a8
    cmp #$05
    bcc select_and_emit_actor_sprite_lists_c0e520
    bit a:$E114,X
    bvc select_and_emit_actor_sprite_lists_c0e520
    brl emit_alternate_actor_body_sprites
select_and_emit_actor_sprite_lists_c0e520:
    lda a:$E028,X
    .a8
    bit #$20
    bne select_and_emit_actor_sprite_lists_c0e57c
select_and_emit_actor_sprite_lists_c0e527:
    rep #$20
    lda a:$E118,X
    clc
    adc a:$E020,X
    sta $04
    lda a:$E074,X
    .a16
    and #$007F
    clc
    adc a:$E045,X
    .a16
    eor #$FFFF
    sec
    adc a:$E11A,X
    adc a:$E022,X
    sta $06
    txa
    .a16
    ora #$E0D0
    tax
    jsr emit_packed_actor_sprite_list
    brl finish_actor_sprite_emission
select_and_emit_actor_sprite_lists_c0e553:
    lda a:$E024,X
    bpl select_and_emit_actor_sprite_lists_c0e565
    rep #$20
    txa
    .a16
    ora #$E0D0
    tay
    jsr prepare_actor_body_list_tail
    brl prepare_and_emit_actor_body_sprites
select_and_emit_actor_sprite_lists_c0e565:
    jsr prepare_and_emit_actor_body_sprites
    rep #$20
    ldx $14
    lda a:$E084,X
    .a16
    and #$000F
    sta $02
    txa
    .a16
    ora #$E0D0
    tay
    brl prepare_actor_body_list_tail
select_and_emit_actor_sprite_lists_c0e57c:
    .a8
    bit #$10
    beq select_and_emit_actor_sprite_lists_c0e5af
    rep #$20
    ldy a:$E10C,X
    lda a:$E118,X
    clc
    adc a:$E020,Y
    sta $04
    lda a:$E074,Y
    .a16
    and #$007F
    clc
    adc a:$E045,Y
    .a16
    eor #$FFFF
    sec
    adc a:$E11A,X
    adc a:$E022,Y
    sta $06
    txa
    .a16
    ora #$E0D0
    tax
    jsr emit_packed_actor_sprite_list
    brl finish_actor_sprite_emission
select_and_emit_actor_sprite_lists_c0e5af:
    rep #$20
    lda a:$E118,X
    clc
    .a16
    adc #$0080
    sta $04
    lda a:$E11A,X
    clc
    .a16
    adc #$0070
    sta $06
    txa
    .a16
    ora #$E0D0
    tax
    jsr emit_packed_actor_sprite_list
    brl finish_actor_sprite_emission
