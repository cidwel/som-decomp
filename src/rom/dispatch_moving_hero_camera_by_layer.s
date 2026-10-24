; Recovered Secret of Mana USA routine; behaviour documented in docs/map-hero-motion.md.
.setcpu "65816"
.smart
.a8
.i16

move_secondary_then_primary_map_cameras = $DAB6

.segment "CODE"
.org $DA6E
dispatch_moving_hero_camera_by_layer:
    sep #$30
    lda $FF
    beq dispatch_moving_hero_camera_by_layer_c0da75
dispatch_moving_hero_camera_by_layer_c0da74:
    rts
dispatch_moving_hero_camera_by_layer_c0da75:
    lda a:$010E
    ora a:$010F
    beq dispatch_moving_hero_camera_by_layer_c0da74
    lda $1B
    bmi move_secondary_then_primary_map_cameras
