; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_animation_background_blocks = $1CA4
prepare_boss_animation_sprite_piece_records = $1E80
read_and_mirror_boss_animation_collision_shapes = $1E06

.segment "CODE"
.org $1C37
prepare_boss_animation_frame_geometry_and_collision:
    lda a:$00A0,X
    sta $79
    lda a:$00A2,X
    sta $7B
    lda [$79]
    bmi prepare_boss_animation_frame_geometry_and_collision_c21c6f
    lda a:$0088,X
    sta $93
    lda $89
    sta $7C
    lda [$79]
    .a16
    and #$00FF
    sta ($7C)
    beq prepare_boss_animation_frame_geometry_and_collision_c21c69
    sta $85
    inc $79
    inc $79
    inc $7C
    stz $66
    lda a:$0098,X
    sta $8D
    jsr prepare_boss_animation_sprite_piece_records
prepare_boss_animation_frame_geometry_and_collision_c21c69:
    ldx $87
    jsr read_and_mirror_boss_animation_collision_shapes
    rts
prepare_boss_animation_frame_geometry_and_collision_c21c6f:
    lda a:$0088,X
    sta $93
    sep #$10
    lda [$79]
    .a16
    and #$00FF
    sta $66
    .i8
    ldy #$02
    lda [$79],Y
    sta a:$0FB4
    .i8
    ldy #$04
    lda [$79],Y
    sta a:$0FB6
    lda $79
    clc
    .a16
    adc #$0006
    sta $79
    jsr prepare_boss_animation_background_blocks
    rep #$10
    ldx $87
    tya
    clc
    adc $79
    sta $79
    jsr read_and_mirror_boss_animation_collision_shapes
    rts
