; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-projectiles.md.
.setcpu "65816"
.smart
.a8
.i16

move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding = $0A47
request_boss_sound_with_parameter_word = $30E3

.segment "CODE"
.org $507D
advance_projectile_height_bounce_sound_and_simple_terrain_motion:
    lda a:$0064,X
    clc
    adc a:$00C4,X
    sta a:$0064,X
    lda a:$0066,X
    adc a:$00C6,X
    bpl advance_projectile_height_bounce_sound_and_simple_terrain_motion_c250a7
    .a16
    lda #$001C
    .i16
    ldx #$000F
    jsr request_boss_sound_with_parameter_word
    ldx $87
    lda a:$00C6,X
    .a16
    eor #$FFFF
    inc
    sta a:$00C6,X
    .a16
    lda #$0000
advance_projectile_height_bounce_sound_and_simple_terrain_motion_c250a7:
    sta a:$0066,X
    lda $C5
    jsr move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding
    lda a:$00C6,X
    sec
    .a16
    sbc #$0001
    sta a:$00C6,X
    rts
