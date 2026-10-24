; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-map-terrain-queries.md.
.setcpu "65816"
.smart
.a8
.i16

test_actor_horizontal_footprint_and_redirect_step = $B9EA
test_actor_vertical_footprint_and_redirect_step = $BAE2

.segment "CODE"
.org $BBE3
resolve_actor_axis_or_diagonal_terrain_step:
    sep #$20
    lda $1E
    bne resolve_actor_axis_or_diagonal_terrain_step_c1bbf3
    lda $1F
    beq resolve_actor_axis_or_diagonal_terrain_step_c1bbf1
    clc
    brl test_actor_vertical_footprint_and_redirect_step
resolve_actor_axis_or_diagonal_terrain_step_c1bbf1:
    sec
    rts
resolve_actor_axis_or_diagonal_terrain_step_c1bbf3:
    lda $1F
    bne resolve_actor_axis_or_diagonal_terrain_step_c1bbfb
    clc
    brl test_actor_horizontal_footprint_and_redirect_step
resolve_actor_axis_or_diagonal_terrain_step_c1bbfb:
    sec
    jsr test_actor_horizontal_footprint_and_redirect_step
    bcs resolve_actor_axis_or_diagonal_terrain_step_c1bc08
    sec
    jsr test_actor_vertical_footprint_and_redirect_step
    bcs resolve_actor_axis_or_diagonal_terrain_step_c1bc08
    rts
resolve_actor_axis_or_diagonal_terrain_step_c1bc08:
    lda $1F
    pha
    stz $1F
    sec
    jsr test_actor_horizontal_footprint_and_redirect_step
    bcs resolve_actor_axis_or_diagonal_terrain_step_c1bc15
    pla
    rts
resolve_actor_axis_or_diagonal_terrain_step_c1bc15:
    pla
    sta $1F
    lda $1E
    pha
    stz $1E
    sec
    jsr test_actor_vertical_footprint_and_redirect_step
    bcs resolve_actor_axis_or_diagonal_terrain_step_c1bc25
    pla
    rts
resolve_actor_axis_or_diagonal_terrain_step_c1bc25:
    pla
    stz $1E
    stz $1F
    sec
    rts
