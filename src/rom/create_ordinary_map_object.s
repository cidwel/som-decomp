; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

assign_map_object_priority_and_terrain = $DF55
release_map_object_to_position_cache = $E2E1
routine_01dfcf = $1DFCF
routine_c0df45 = $DF45
set_actor_program_long = $C10020

.segment "CODE"
.org $DE3B
create_ordinary_map_object:
    .a8
    lda #$01
    sta a:$E000,X
    stz a:$E001,X
    lda a:$E043,X
    beq create_ordinary_map_object_c0de4b
    jsr release_map_object_to_position_cache
create_ordinary_map_object_c0de4b:
    rep #$20
    phx
    phy
    .i16
    ldy #$0030
create_ordinary_map_object_c0de52:
    stz a:$E002,X
    inx
    inx
    dey
    bne create_ordinary_map_object_c0de52
    ply
    plx
    lda a:$C80E,Y
    sta a:$E03E,X
    lda a:$C80C,Y
    sta a:$E03C,X
    sep #$20
    stz a:$E045,X
    stz a:$E060,X
    stz a:$E061,X
    stz a:$E069,X
    stz a:$E100,X
    stz a:$E104,X
    stz a:$E108,X
    xba
    sta a:$E180,X
    asl
    .a8
    lda #$D2
    bcs create_ordinary_map_object_c0de89
    inc
create_ordinary_map_object_c0de89:
    sta a:$E033,X
    .a8
    lda #$00
    sta a:$E083,X
    jsl f:routine_01dfcf
    rep #$20
    lda f:$D0FFF0
    sta a:$E02A,X
    lda a:$C80A,Y
    .a16
    and #$007F
    asl
    sec
    rol
    asl
    asl
    sta a:$E002,X
    lda a:$C80B,Y
    .a16
    and #$007F
    asl
    sec
    rol
    asl
    asl
    sta a:$E004,X
    tya
    sta a:$E034,X
    txa
    sta a:$C802,Y
    sep #$20
    lda a:$C807,Y
    sta a:$E044,X
    .a8
    lda #$81
    sta a:$C800,Y
    lda a:$E03C,X
    pha
    asl
    asl
    asl
    asl
    .a8
    and #$80
    sta a:$E00B,X
    pla
    pha
    asl
    rol
    rol
    .a8
    and #$03
    .a8
    cmp #$03
    bne create_ordinary_map_object_c0deeb
    .a8
    lda #$02
    bra create_ordinary_map_object_c0def1
create_ordinary_map_object_c0deeb:
    .a8
    cmp #$02
    bne create_ordinary_map_object_c0def1
    .a8
    lda #$82
create_ordinary_map_object_c0def1:
    sta a:$E010,X
    lda a:$E071,X
    .a8
    and #$20
    beq create_ordinary_map_object_c0df00
    .a8
    lda #$00
    sta a:$E010,X
create_ordinary_map_object_c0df00:
    .a8
    lda #$00
    sta a:$E011,X
    .a8
    lda #$FF
    sta a:$E030,X
    pla
    bit $ED
    bpl create_ordinary_map_object_c0df12
    brl routine_c0df45
create_ordinary_map_object_c0df12:
    .a8
    and #$30
    lsr
    lsr
    lsr
    sta $00
    lda a:$E08B,X
    .a8
    and #$F9
    ora $00
    sta a:$E08B,X
    .a8
    and #$0E
    asl
    asl
    asl
    asl
    rep #$20
    .a16
    and #$00FF
    inc
    inc
    sta a:$E0F8,X
    jsr assign_map_object_priority_and_terrain
    rep #$10
    phx
    sep #$20
    lda a:$E03D,X
    jsl f:set_actor_program_long
    plx
    sec
    rts
