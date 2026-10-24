; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-map-terrain-queries.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c1bbfb = $BBFB
test_actor_vertical_footprint_and_redirect_step = $BAE2
test_vertical_terrain_shape_and_preceding_cells = $BE15

.segment "CODE"
.org $B9EA
test_actor_horizontal_footprint_and_redirect_step:
    php
    lda $1A
    lsr
    clc
    adc $1E
    .a8
    cmp #$80
    rep #$20
    .a16
    and #$007F
    bcs test_actor_horizontal_footprint_and_redirect_step_c1ba05
    clc
    adc $12
    cmp $C0
    bcc test_actor_horizontal_footprint_and_redirect_step_c1ba10
    sbc $C0
    bra test_actor_horizontal_footprint_and_redirect_step_c1ba10
test_actor_horizontal_footprint_and_redirect_step_c1ba05:
    .a16
    eor #$FFFF
    sec
    adc $12
    bpl test_actor_horizontal_footprint_and_redirect_step_c1ba10
    clc
    adc $C0
test_actor_horizontal_footprint_and_redirect_step_c1ba10:
    sta $04
    lsr
    lsr
    lsr
    lsr
    sta $08
    sep #$20
    lda $1F
    bpl test_actor_horizontal_footprint_and_redirect_step_c1ba21
    .a8
    eor #$7F
    inc
test_actor_horizontal_footprint_and_redirect_step_c1ba21:
    clc
    .a8
    adc #$04
    .a8
    cmp #$80
    rep #$20
    .a16
    and #$007F
    bcs test_actor_horizontal_footprint_and_redirect_step_c1ba37
    adc $14
    cmp $C2
    bcc test_actor_horizontal_footprint_and_redirect_step_c1ba42
    sbc $C2
    bra test_actor_horizontal_footprint_and_redirect_step_c1ba42
test_actor_horizontal_footprint_and_redirect_step_c1ba37:
    .a16
    eor #$FFFF
    sec
    adc $14
    bpl test_actor_horizontal_footprint_and_redirect_step_c1ba42
    clc
    adc $C2
test_actor_horizontal_footprint_and_redirect_step_c1ba42:
    pha
    xba
    sep #$20
    lda $04
    rep #$20
    .a16
    and #$0F0F
    sta $04
    pla
    .a16
    and #$0FF0
    asl
    asl
    asl
    ora $08
    sta $08
    tay
    lda [$0A],Y
    .a16
    and #$00FF
    asl
    asl
    tay
    sep #$20
    lda [$0D],Y
    sta $07
    iny
    iny
    lda [$0D],Y
    sta $06
    .a8
    and #$F0
    .a8
    cmp #$10
    beq test_actor_horizontal_footprint_and_redirect_step_c1ba77
    stz $06
test_actor_horizontal_footprint_and_redirect_step_c1ba77:
    jsr test_vertical_terrain_shape_and_preceding_cells
    bcs test_actor_horizontal_footprint_and_redirect_step_c1ba7f
    plp
    clc
    rts
test_actor_horizontal_footprint_and_redirect_step_c1ba7f:
    plp
    bcs test_actor_horizontal_footprint_and_redirect_step_c1ba88
    lda $02
    bne test_actor_horizontal_footprint_and_redirect_step_c1ba8a
test_actor_horizontal_footprint_and_redirect_step_c1ba86:
    stz $1E
test_actor_horizontal_footprint_and_redirect_step_c1ba88:
    sec
    rts
test_actor_horizontal_footprint_and_redirect_step_c1ba8a:
    .a8
    cmp #$08
    bcc test_actor_horizontal_footprint_and_redirect_step_c1baa6
    beq test_actor_horizontal_footprint_and_redirect_step_c1baa2
    .a8
    cmp #$09
    bne test_actor_horizontal_footprint_and_redirect_step_c1ba86
    lda $1E
    .a8
    eor #$80
test_actor_horizontal_footprint_and_redirect_step_c1ba98:
    sta $1F
    stz $1E
    inc $1D
    sec
    brl test_actor_vertical_footprint_and_redirect_step
test_actor_horizontal_footprint_and_redirect_step_c1baa2:
    lda $1E
    bra test_actor_horizontal_footprint_and_redirect_step_c1ba98
test_actor_horizontal_footprint_and_redirect_step_c1baa6:
    bit $1E
    bmi test_actor_horizontal_footprint_and_redirect_step_c1bac6
    .a8
    cmp #$05
    bne test_actor_horizontal_footprint_and_redirect_step_c1bab7
    lda $1E
    sta $1F
    inc $1D
    brl routine_c1bbfb
test_actor_horizontal_footprint_and_redirect_step_c1bab7:
    .a8
    cmp #$07
    bne test_actor_horizontal_footprint_and_redirect_step_c1ba86
    lda $1E
    .a8
    eor #$80
    sta $1F
    inc $1D
    brl routine_c1bbfb
test_actor_horizontal_footprint_and_redirect_step_c1bac6:
    .a8
    cmp #$04
    bne test_actor_horizontal_footprint_and_redirect_step_c1bad3
    lda $1E
    sta $1F
    inc $1D
    brl routine_c1bbfb
test_actor_horizontal_footprint_and_redirect_step_c1bad3:
    .a8
    cmp #$06
    bne test_actor_horizontal_footprint_and_redirect_step_c1ba86
    lda $1E
    .a8
    eor #$80
    sta $1F
    inc $1D
    brl routine_c1bbfb
