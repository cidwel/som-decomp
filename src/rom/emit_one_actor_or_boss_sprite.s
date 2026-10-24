; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-sprite-publication.md.
.setcpu "65816"
.smart
.a8
.i16

boss_selected_object_emission_public_jump = $C20006
emit_actor_ground_shadow = $E760
select_and_emit_actor_sprite_lists = $E4C1
update_actor_screen_position_and_emit_sprites = $E40E

.segment "CODE"
.org $E3CF
emit_one_actor_or_boss_sprite:
    sep #$20
    stx $14
    .i16
    cpx #$0600
    bcc emit_one_actor_or_boss_sprite_c0e3fe
    bit $5C
    bpl emit_one_actor_or_boss_sprite_c0e3fe
    lda a:$E000,X
    beq emit_one_actor_or_boss_sprite_c0e403
    .i16
    cpx #$0C00
    bcs emit_one_actor_or_boss_sprite_c0e3f0
    lda a:$E060,X
    beq emit_one_actor_or_boss_sprite_c0e3f0
    phx
    jsr select_and_emit_actor_sprite_lists
    plx
emit_one_actor_or_boss_sprite_c0e3f0:
    rep #$20
    txa
    sec
    .a16
    sbc #$0600
    lsr
    xba
    jsl f:boss_selected_object_emission_public_jump
    rts
emit_one_actor_or_boss_sprite_c0e3fe:
    lda a:$E000,X
    bne emit_one_actor_or_boss_sprite_c0e404
emit_one_actor_or_boss_sprite_c0e403:
    rts
emit_one_actor_or_boss_sprite_c0e404:
    bmi emit_one_actor_or_boss_sprite_c0e403
    phx
    jsr update_actor_screen_position_and_emit_sprites
    plx
    brl emit_actor_ground_shadow
