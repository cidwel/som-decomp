; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_boss_resources_public_jump = $C20000

.segment "CODE"
.org $DE0D
start_map_boss_resources:
    .a8
    lda #$80
    sta $5C
    rep #$20
    lda a:$C80A,Y
    .a16
    and #$007F
    asl
    asl
    asl
    asl
    sta a:$0300
    lda a:$C80B,Y
    .a16
    and #$007F
    asl
    asl
    asl
    asl
    sta a:$0302
    lda a:$C80D,Y
    .a16
    and #$00FF
    jsl f:initialize_boss_resources_public_jump
    sep #$20
    sec
    rts
