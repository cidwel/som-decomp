; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-frame-geometry.md.
.setcpu "65816"
.smart
.a8
.i16

publish_actor_frame_tiles_points_and_collision_rectangle = $F1CF

.segment "CODE"
.org $F1AE
publish_secondary_hero_frame_geometry_with_saved_data_bank:
    sep #$20
    rep #$10
    phb
    .a8
    lda #$7E
    pha
    plb
    .i16
    ldx #$0200
    jsr publish_actor_frame_tiles_points_and_collision_rectangle
    rep #$10
    .i16
    ldx #$0400
    jsr publish_actor_frame_tiles_points_and_collision_rectangle
    plb
    rts
