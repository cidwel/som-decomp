; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-next-frontier.md.
.setcpu "65816"
.smart
.a8
.i16

cast_sprite_emission_long = $E328
execute_native_spell_entity_scheduler_long = $C10038
initialize_sprite_workspace_long = $E351

.segment "CODE"
.org $CAE7
publish_actor_sprites_and_run_spell_entity_between_native_frames:
    phb
    phy
    phx
    jsl f:cast_sprite_emission_long
    sep #$20
    .a8
    lda #$01
    sta $EC
publish_actor_sprites_and_run_spell_entity_between_native_frames_c1caf4:
    bit $EC
    bne publish_actor_sprites_and_run_spell_entity_between_native_frames_c1caf4
    rep #$20
    plx
    ply
    phx
    jsl f:execute_native_spell_entity_scheduler_long
    plx
    jsl f:initialize_sprite_workspace_long
    plb
    sep #$20
    .a8
    lda #$02
    sta $EC
publish_actor_sprites_and_run_spell_entity_between_native_frames_c1cb0d:
    bit $EC
    bne publish_actor_sprites_and_run_spell_entity_between_native_frames_c1cb0d
    rts
