; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-map-terrain-queries.md.
.setcpu "65816"
.smart
.a8
.i16

resolve_actor_axis_or_diagonal_terrain_step = $BBE3

.segment "CODE"
.org $B93E
test_actor_signed_step_against_wrapped_terrain:
    sep #$20
    rep #$10
    lda $1E
    .a8
    cmp #$80
    rep #$20
    .a16
    and #$000F
    bcs test_actor_signed_step_against_wrapped_terrain_c1b958
    clc
    adc $12
    cmp $C0
    bcc test_actor_signed_step_against_wrapped_terrain_c1b963
    sbc $C0
    bra test_actor_signed_step_against_wrapped_terrain_c1b963
test_actor_signed_step_against_wrapped_terrain_c1b958:
    .a16
    eor #$FFFF
    sec
    adc $12
    bpl test_actor_signed_step_against_wrapped_terrain_c1b963
    clc
    adc $C0
test_actor_signed_step_against_wrapped_terrain_c1b963:
    lsr
    lsr
    lsr
    lsr
    sta $08
    sep #$20
    lda $1F
    .a8
    cmp #$80
    rep #$20
    .a16
    and #$000F
    bcs test_actor_signed_step_against_wrapped_terrain_c1b981
    clc
    adc $14
    cmp $C2
    bcc test_actor_signed_step_against_wrapped_terrain_c1b98c
    sbc $C2
    bra test_actor_signed_step_against_wrapped_terrain_c1b98c
test_actor_signed_step_against_wrapped_terrain_c1b981:
    .a16
    eor #$FFFF
    sec
    adc $14
    bpl test_actor_signed_step_against_wrapped_terrain_c1b98c
    clc
    adc $C2
test_actor_signed_step_against_wrapped_terrain_c1b98c:
    .a16
    and #$0FF0
    asl
    asl
    asl
    ora $08
    tay
    lda [$0A],Y
    .a16
    and #$00FF
    sta $00
    asl
    asl
    tay
    sep #$20
    ldx $10
    lda $00
    cmp $4D
    bcc test_actor_signed_step_against_wrapped_terrain_c1b9c9
    .i16
    cpx #$0600
    bcs test_actor_signed_step_against_wrapped_terrain_c1b9bc
    lda a:$E02C,X
    bne test_actor_signed_step_against_wrapped_terrain_c1b9be
    rep #$20
    lda [$0D],Y
    .a16
    bit #$4000
    bne test_actor_signed_step_against_wrapped_terrain_c1b9c9
test_actor_signed_step_against_wrapped_terrain_c1b9bc:
    sec
    rtl
test_actor_signed_step_against_wrapped_terrain_c1b9be:
    lda $FF
    bne test_actor_signed_step_against_wrapped_terrain_c1b9c9
    lda $D0
    ora a:$E01C,X
    bne test_actor_signed_step_against_wrapped_terrain_c1b9bc
test_actor_signed_step_against_wrapped_terrain_c1b9c9:
    rep #$20
    lda [$0D],Y
    .a16
    bit #$1000
    sep #$20
    beq test_actor_signed_step_against_wrapped_terrain_c1b9e0
    .i16
    cpx #$0600
    bcs test_actor_signed_step_against_wrapped_terrain_c1b9bc
    lda $D0
    ora a:$E01C,X
    bne test_actor_signed_step_against_wrapped_terrain_c1b9bc
test_actor_signed_step_against_wrapped_terrain_c1b9e0:
    .a8
    and #$08
    beq test_actor_signed_step_against_wrapped_terrain_c1b9e6
    clc
    rtl
test_actor_signed_step_against_wrapped_terrain_c1b9e6:
    jsr resolve_actor_axis_or_diagonal_terrain_step
    rtl
