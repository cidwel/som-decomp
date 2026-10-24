; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-body.md.
.setcpu "65816"
.smart
.a8
.i16

boss_attack_row_public_jump = $C0006C
change_actor_identity_public_jump = $C0003F
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $4B27
initialize_native54_body_identity67_attack1e:
    ldx $87
    .a16
    lda #$0001
    sta a:$0000,X
    stz a:$00A5,X
    lda a:$0032,X
    sta a:$0022,X
    .a16
    lda #$0003
    sta a:$0094,X
    .a16
    lda #$0000
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$0002
    sta a:$001E,X
    .a16
    lda #$3000
    sta a:$0092,X
    stz a:$0066,X
    stz a:$003C,X
    stz a:$0040,X
    sep #$20
    stz a:$0046,X
    stz a:$0047,X
    stz a:$0074,X
    .a8
    lda #$01
    sta a:$0010,X
    rep #$20
    .a16
    lda #$0067
    jsl f:change_actor_identity_public_jump
    ldx $87
    .a16
    lda #$001E
    jsl f:boss_attack_row_public_jump
    ldx $87
    clc
    rts
