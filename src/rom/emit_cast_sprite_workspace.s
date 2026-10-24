; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-sprite-publication.md.
.setcpu "65816"
.smart
.a8
.i16

emit_complete_map_actor_and_hud_sprites = $E38E
initialize_map_sprite_workspace = $E355

.segment "CODE"
.org $E32C
emit_cast_sprite_workspace:
    sep #$20
    lda $ED
    pha
    .a8
    lda #$40
    sta $ED
    jsr initialize_map_sprite_workspace
    sep #$20
    .a8
    lda #$01
    sta $7D
    stz $7C
    .a8
    lda #$10
    sta $5A
    .a8
    lda #$01
    sta $59
    jsr emit_complete_map_actor_and_hud_sprites
    sep #$20
    pla
    sta $ED
    rts
