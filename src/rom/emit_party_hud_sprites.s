; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

emit_one_party_hud_sprite = $E668

.segment "CODE"
.org $E621
emit_party_hud_sprites:
    sep #$20
    lda f:$7ECF00
    bne emit_party_hud_sprites_c1e62a
    rts
emit_party_hud_sprites_c1e62a:
    rep #$10
    lda $52
    beq emit_party_hud_sprites_c1e631
emit_party_hud_sprites_c1e630:
    rts
emit_party_hud_sprites_c1e631:
    lda $E8
    .a8
    cmp #$03
    beq emit_party_hud_sprites_c1e630
    lda a:$0A55
    beq emit_party_hud_sprites_c1e647
    xba
    .i16
    ldy #$01E8
    lda f:$7EE093
    jsr emit_one_party_hud_sprite
emit_party_hud_sprites_c1e647:
    lda a:$0A65
    beq emit_party_hud_sprites_c1e657
    xba
    .i16
    ldy #$01EA
    lda f:$7EE293
    jsr emit_one_party_hud_sprite
emit_party_hud_sprites_c1e657:
    lda a:$0A75
    beq emit_party_hud_sprites_c1e667
    xba
    .i16
    ldy #$01EC
    lda f:$7EE493
    jsr emit_one_party_hud_sprite
emit_party_hud_sprites_c1e667:
    rts
