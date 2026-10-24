; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-animation-operands.md.
.setcpu "65816"
.smart
.a8
.i16

audio_command_sender_public_jump = $C30004
derive_actor_animation_sound_volume = $D503

.segment "CODE"
.org $D48D
read_actor_animation_velocity_or_sound_operands:
    pha
    rep #$20
    .i16
    ldy #$0001
    lda [$00],Y
    sta $0C
    iny
    lda [$00],Y
    sta $0D
    lda $00
    clc
    .a16
    adc #$0004
    sta $00
    sep #$20
    pla
    .a8
    cmp #$F8
    bne read_actor_animation_velocity_or_sound_operands_c1d4de
    lda $0E
    sta a:$E008,X
    lda a:$E010,X
    .a8
    and #$80
    sta $0F
    lda $0D
    bpl read_actor_animation_velocity_or_sound_operands_c1d4c0
    .a8
    eor #$7F
    inc
    .a8
    ora #$80
read_actor_animation_velocity_or_sound_operands_c1d4c0:
    eor $0F
    .a8
    cmp #$80
    bne read_actor_animation_velocity_or_sound_operands_c1d4c8
    .a8
    lda #$00
read_actor_animation_velocity_or_sound_operands_c1d4c8:
    sta a:$E006,X
    lda $0C
    bpl read_actor_animation_velocity_or_sound_operands_c1d4d4
    .a8
    eor #$FF
    inc
    .a8
    ora #$80
read_actor_animation_velocity_or_sound_operands_c1d4d4:
    .a8
    cmp #$80
    bne read_actor_animation_velocity_or_sound_operands_c1d4da
    .a8
    lda #$00
read_actor_animation_velocity_or_sound_operands_c1d4da:
    sta a:$E007,X
    rtl
read_actor_animation_velocity_or_sound_operands_c1d4de:
    .a8
    cmp #$F9
    bne read_actor_animation_velocity_or_sound_operands_c1d502
    .a8
    lda #$02
    sta a:$1E00
    lda $0C
    sta a:$1E01
    lda $0D
    sta a:$1E02
    jsr derive_actor_animation_sound_volume
    sta a:$1E03
    rep #$20
    dec $00
    sep #$20
    jsl f:audio_command_sender_public_jump
    rtl
read_actor_animation_velocity_or_sound_operands_c1d502:
    rtl
