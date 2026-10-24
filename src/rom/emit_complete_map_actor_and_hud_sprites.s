; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-sprite-publication.md.
.setcpu "65816"
.smart
.a8
.i16

boss_alternating_object_emission_public_jump = $C2000C
emit_one_actor_or_boss_sprite = $E3CF
routine_01e61d = $1E61D

.segment "CODE"
.org $E38E
emit_complete_map_actor_and_hud_sprites:
    jsl f:routine_01e61d
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$10
    ldy a:$057E
    beq emit_complete_map_actor_and_hud_sprites_c0e3ae
    dey
    dey
emit_complete_map_actor_and_hud_sprites_c0e3a2:
    ldx a:$0540,Y
    phy
    jsr emit_one_actor_or_boss_sprite
    ply
    dey
    dey
    bpl emit_complete_map_actor_and_hud_sprites_c0e3a2
emit_complete_map_actor_and_hud_sprites_c0e3ae:
    ldy a:$053E
    beq emit_complete_map_actor_and_hud_sprites_c0e3c1
    dey
    dey
emit_complete_map_actor_and_hud_sprites_c0e3b5:
    ldx a:$0500,Y
    phy
    jsr emit_one_actor_or_boss_sprite
    ply
    dey
    dey
    bpl emit_complete_map_actor_and_hud_sprites_c0e3b5
emit_complete_map_actor_and_hud_sprites_c0e3c1:
    sep #$20
    bit $5C
    bpl emit_complete_map_actor_and_hud_sprites_c0e3cd
    rep #$20
    jsl f:boss_alternating_object_emission_public_jump
emit_complete_map_actor_and_hud_sprites_c0e3cd:
    plb
    rts
