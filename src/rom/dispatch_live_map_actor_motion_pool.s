; Recovered Secret of Mana USA routine; behaviour documented in docs/map-actor-motion.md.
.setcpu "65816"
.smart
.a8
.i16

move_live_map_actor_through_ground_effect_and_terrain = $D229

.segment "CODE"
.org $D1FE
dispatch_live_map_actor_motion_pool:
    rep #$10
    sep #$20
    bit $5C
    bpl dispatch_live_map_actor_motion_pool_c0d207
    rts
dispatch_live_map_actor_motion_pool_c0d207:
    .i16
    ldx #$0600
dispatch_live_map_actor_motion_pool_c0d20a:
    phx
    jsr move_live_map_actor_through_ground_effect_and_terrain
    rep #$30
    plx
    txa
    clc
    .a16
    adc #$0200
    tax
    sep #$20
    bit $ED
    bmi dispatch_live_map_actor_motion_pool_c0d223
    .i16
    cpx #$1800
    bcc dispatch_live_map_actor_motion_pool_c0d20a
    rts
dispatch_live_map_actor_motion_pool_c0d223:
    .i16
    cpx #$0C00
    bcc dispatch_live_map_actor_motion_pool_c0d20a
    rts
