; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-projectile-child.md.
.setcpu "65816"
.smart
.a8
.i16

derive_fine_direction_to_low_byte_target = $0965
request_follow_spell_target_sound = $9AD1
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $9AF7
seed_sixteen_direction_spell_velocity_animation_and_sound:
    lda a:$00B8,X
    jsr derive_fine_direction_to_low_byte_target
    lsr
    lsr
    lsr
    lsr
    sta $95
    asl
    tax
    lda f:$C29B60,X
    sta $97
    lda f:$C29B80,X
    sta $99
    txa
    asl
    asl
    tax
    lda f:$C29BA0,X
    sta $9B
    lda f:$C29BA2,X
    sta $9D
    lda f:$C29BA4,X
    sta $9F
    lda f:$C29BA6,X
    sta $A1
    ldx $87
    lda $9B
    sta a:$003A,X
    lda $9D
    sta a:$003C,X
    lda $9F
    sta a:$003E,X
    lda $A1
    sta a:$0040,X
    lda a:$0098,X
    .a16
    and #$FF3F
    ora $99
    sta a:$0098,X
    lda $97
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$9C20
    sta a:$0090,X
    stz a:$0096,X
    jsr request_follow_spell_target_sound
    rts
