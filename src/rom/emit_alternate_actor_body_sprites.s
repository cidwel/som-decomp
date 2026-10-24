; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

emit_packed_actor_sprite_list = $E640
finish_actor_sprite_emission = $E8C6
duplicate_and_mirror_actor_sprite_list = $2AB54

.segment "CODE"
.org $E6CF
emit_alternate_actor_body_sprites:
    .a8
    cmp #$05
    bne emit_alternate_actor_body_sprites_c0e704
    ldx $14
    lda a:$E116,X
    .a8
    and #$0F
    sta $02
    rep #$20
    lda a:$E020,X
    sta $04
    lda a:$E074,X
    .a16
    and #$007F
    clc
    .a16
    adc #$0060
    adc a:$E045,X
    .a16
    eor #$FFFF
    adc a:$E022,X
    sta $06
    lda $14
    .a16
    ora #$E0D0
    tax
    jsr emit_packed_actor_sprite_list
    brl finish_actor_sprite_emission
emit_alternate_actor_body_sprites_c0e704:
    lda a:$E116,X
    pha
    .a8
    and #$0F
    .a8
    cmp #$06
    bcc emit_alternate_actor_body_sprites_c0e710
    .a8
    lda #$05
emit_alternate_actor_body_sprites_c0e710:
    sta $02
    pla
    rep #$20
    bcc emit_alternate_actor_body_sprites_c0e724
    .a16
    and #$000F
    .a16
    sbc #$0005
    asl
    asl
    .a16
    adc #$00D0
    bra emit_alternate_actor_body_sprites_c0e727
emit_alternate_actor_body_sprites_c0e724:
    .a16
    lda #$00D0
emit_alternate_actor_body_sprites_c0e727:
    ora $14
    .a16
    ora #$E000
    tay
    lda a:$E028,X
    .a16
    and #$0030
    .a16
    cmp #$0030
    bne emit_alternate_actor_body_sprites_c0e73e
    rep #$20
    lda a:$E10C,X
    tax
emit_alternate_actor_body_sprites_c0e73e:
    lda a:$E020,X
    sta $04
    lda a:$E074,X
    .a16
    and #$007F
    adc a:$E045,X
    .a16
    eor #$FFFF
    adc a:$E022,X
    sta $06
    ldx $14
    jsl f:duplicate_and_mirror_actor_sprite_list
    jsr emit_packed_actor_sprite_list
    brl finish_actor_sprite_emission
