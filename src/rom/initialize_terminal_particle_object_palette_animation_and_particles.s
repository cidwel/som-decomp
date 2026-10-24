; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-death-particles.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_256_native_death_particles = $3B98
request_boss_sound_with_parameter_word = $30E3
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $3AE7
initialize_terminal_particle_object_palette_animation_and_particles:
    .a16
    lda #$001F
    sta a:$07FC
    .a16
    lda #$7FFF
    sta a:$07FE
    ldx $87
    .a16
    lda #$EFB4
    sta a:$0100,X
    .a16
    lda #$000F
    sta a:$0018,X
    .a16
    lda #$0001
    sta a:$0000,X
    .a16
    lda #$07FF
    sta a:$0022,X
    .a16
    lda #$0001
    jsr select_boss_animation_and_reset_frame_cursor
    inc a:$0094,X
    jsr initialize_256_native_death_particles
    .a16
    lda #$0001
    sta a:$0351
    .a16
    lda #$0015
    .i16
    ldx #$000F
    jsr request_boss_sound_with_parameter_word
    clc
    rts
