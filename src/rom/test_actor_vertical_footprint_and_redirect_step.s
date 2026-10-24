; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-map-terrain-queries.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c1bbfb = $BBFB
test_actor_horizontal_footprint_and_redirect_step = $B9EA
test_horizontal_terrain_shape_and_preceding_cells = $BC37

.segment "CODE"
.org $BAE2
test_actor_vertical_footprint_and_redirect_step:
    php
    lda $1F
    clc
    .a8
    adc #$04
    .a8
    cmp #$80
    rep #$20
    .a16
    and #$007F
    bcs test_actor_vertical_footprint_and_redirect_step_c1bafc
    clc
    adc $14
    cmp $C2
    bcc test_actor_vertical_footprint_and_redirect_step_c1bb07
    sbc $C2
    bra test_actor_vertical_footprint_and_redirect_step_c1bb07
test_actor_vertical_footprint_and_redirect_step_c1bafc:
    .a16
    eor #$FFFF
    sec
    adc $14
    bpl test_actor_vertical_footprint_and_redirect_step_c1bb07
    clc
    adc $C2
test_actor_vertical_footprint_and_redirect_step_c1bb07:
    sta $04
    .a16
    and #$0FF0
    asl
    asl
    asl
    sta $08
    sep #$20
    lda $1E
    bpl test_actor_vertical_footprint_and_redirect_step_c1bb1a
    .a8
    eor #$7F
    inc
test_actor_vertical_footprint_and_redirect_step_c1bb1a:
    sta $00
    lda $1A
    lsr
    clc
    adc $00
    bpl test_actor_vertical_footprint_and_redirect_step_c1bb33
    rep #$20
    .a16
    ora #$FF00
    clc
    adc $12
    bpl test_actor_vertical_footprint_and_redirect_step_c1bb41
    clc
    adc $C0
    bra test_actor_vertical_footprint_and_redirect_step_c1bb41
test_actor_vertical_footprint_and_redirect_step_c1bb33:
    rep #$20
    .a16
    and #$007F
    clc
    adc $12
    cmp $C0
    bcc test_actor_vertical_footprint_and_redirect_step_c1bb41
    sbc $C0
test_actor_vertical_footprint_and_redirect_step_c1bb41:
    pha
    xba
    sep #$20
    lda $04
    rep #$20
    xba
    .a16
    and #$0F0F
    sta $04
    pla
    lsr
    lsr
    lsr
    lsr
    .a16
    and #$007F
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
    beq test_actor_vertical_footprint_and_redirect_step_c1bb78
    stz $06
test_actor_vertical_footprint_and_redirect_step_c1bb78:
    jsr test_horizontal_terrain_shape_and_preceding_cells
    bcs test_actor_vertical_footprint_and_redirect_step_c1bb80
    plp
    clc
    rts
test_actor_vertical_footprint_and_redirect_step_c1bb80:
    plp
    bcs test_actor_vertical_footprint_and_redirect_step_c1bb89
    lda $02
    bne test_actor_vertical_footprint_and_redirect_step_c1bb8b
test_actor_vertical_footprint_and_redirect_step_c1bb87:
    stz $1F
test_actor_vertical_footprint_and_redirect_step_c1bb89:
    sec
    rts
test_actor_vertical_footprint_and_redirect_step_c1bb8b:
    .a8
    cmp #$08
    bcc test_actor_vertical_footprint_and_redirect_step_c1bba7
    beq test_actor_vertical_footprint_and_redirect_step_c1bba3
    .a8
    cmp #$09
    bne test_actor_vertical_footprint_and_redirect_step_c1bb87
    lda $1F
    .a8
    eor #$80
test_actor_vertical_footprint_and_redirect_step_c1bb99:
    sta $1E
    stz $1F
    inc $1C
    sec
    brl test_actor_horizontal_footprint_and_redirect_step
test_actor_vertical_footprint_and_redirect_step_c1bba3:
    lda $1F
    bra test_actor_vertical_footprint_and_redirect_step_c1bb99
test_actor_vertical_footprint_and_redirect_step_c1bba7:
    bit $1F
    bmi test_actor_vertical_footprint_and_redirect_step_c1bbc7
    .a8
    cmp #$04
    bne test_actor_vertical_footprint_and_redirect_step_c1bbb8
    lda $1F
    sta $1E
    inc $1C
    brl routine_c1bbfb
test_actor_vertical_footprint_and_redirect_step_c1bbb8:
    .a8
    cmp #$07
    bne test_actor_vertical_footprint_and_redirect_step_c1bb87
    lda $1F
    .a8
    eor #$80
    sta $1E
    inc $1C
    brl routine_c1bbfb
test_actor_vertical_footprint_and_redirect_step_c1bbc7:
    .a8
    cmp #$05
    bne test_actor_vertical_footprint_and_redirect_step_c1bbd4
    lda $1F
    sta $1E
    inc $1C
    brl routine_c1bbfb
test_actor_vertical_footprint_and_redirect_step_c1bbd4:
    .a8
    cmp #$06
    bne test_actor_vertical_footprint_and_redirect_step_c1bb87
    lda $1F
    .a8
    eor #$80
    sta $1E
    inc $1C
    brl routine_c1bbfb
