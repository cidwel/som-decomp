; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

assign_boss_palette_list = $2309
change_actor_identity_public_jump = $C0003F
prepare_boss_object_terrain = $15B7

.segment "CODE"
.org $2293
prepare_boss_object_identity_palette_and_terrain:
    stx $87
    ldy a:$0FA6
    lda a:$C80A,Y
    .a16
    and #$007F
    asl
    asl
    asl
    asl
    sta a:$002B,X
    lda a:$C80B,Y
    .a16
    and #$007F
    asl
    asl
    asl
    asl
    sta a:$0032,X
    lda a:$C80E,Y
    .a16
    and #$0FFF
    sta a:$0072,X
    lda a:$0304
    sta a:$0042,X
    .a16
    lda #$0001
    sta a:$0000,X
    stz a:$0029,X
    stz a:$0030,X
    stz a:$00A5,X
    lda a:$0032,X
    sta a:$0022,X
    stz a:$0034,X
    .a16
    lda #$3000
    sta a:$0092,X
    stz a:$0060,X
    sep #$20
    stz a:$0046,X
    stz a:$0047,X
    stz a:$0074,X
    .a8
    lda #$01
    sta a:$0010,X
    rep #$20
    lda a:$0FA2
    jsl f:change_actor_identity_public_jump
    lda a:$0FA2
    ldx $87
    jsr assign_boss_palette_list
    ldx $87
    jsr prepare_boss_object_terrain
    rts
