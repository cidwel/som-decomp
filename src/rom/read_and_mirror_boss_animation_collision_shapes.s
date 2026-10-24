; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1E06
read_and_mirror_boss_animation_collision_shapes:
    .i16
    ldy #$0000
    lda [$79],Y
    sta a:$00CA,X
    beq read_and_mirror_boss_animation_collision_shapes_c21e17
    iny
    iny
    lda [$79],Y
    sta a:$00C8,X
read_and_mirror_boss_animation_collision_shapes_c21e17:
    iny
    iny
    lda [$79],Y
    sta a:$00C2,X
    beq read_and_mirror_boss_animation_collision_shapes_c21e27
    iny
    iny
    lda [$79],Y
    sta a:$00C0,X
read_and_mirror_boss_animation_collision_shapes_c21e27:
    iny
    iny
    lda [$79],Y
    sta a:$00CE,X
    beq read_and_mirror_boss_animation_collision_shapes_c21e37
    iny
    iny
    lda [$79],Y
    sta a:$00CC,X
read_and_mirror_boss_animation_collision_shapes_c21e37:
    sep #$20
    lda a:$0098,X
    .a8
    bit #$40
    beq read_and_mirror_boss_animation_collision_shapes_c21e5b
    lda a:$00C0,X
    .a8
    eor #$FF
    inc
    sta a:$00C0,X
    lda a:$00C8,X
    .a8
    eor #$FF
    inc
    sta a:$00C8,X
    lda a:$00CC,X
    .a8
    eor #$FF
    inc
    sta a:$00CC,X
read_and_mirror_boss_animation_collision_shapes_c21e5b:
    lda a:$0098,X
    .a8
    bit #$80
    beq read_and_mirror_boss_animation_collision_shapes_c21e7d
    lda a:$00C1,X
    .a8
    eor #$FF
    inc
    sta a:$00C1,X
    lda a:$00C9,X
    .a8
    eor #$FF
    inc
    sta a:$00C9,X
    lda a:$00CD,X
    .a8
    eor #$FF
    inc
    sta a:$00CD,X
read_and_mirror_boss_animation_collision_shapes_c21e7d:
    rep #$20
    rts
