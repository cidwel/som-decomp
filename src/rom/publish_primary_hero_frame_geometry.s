; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-frame-geometry.md.
.setcpu "65816"
.smart
.a8
.i16

publish_actor_frame_tiles_points_and_collision_rectangle = $F1CF

.segment "CODE"
.org $F1C7
publish_primary_hero_frame_geometry:
    rep #$30
    .i16
    ldx #$0000
    jmp publish_actor_frame_tiles_points_and_collision_rectangle
