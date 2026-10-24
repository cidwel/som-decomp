; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-particle-initialize.md.
.setcpu "65816"
.smart
.a8
.i16

publish_nine_native_title_particle_sprites_from_frame_offsets = $9793

.segment "CODE"
.org $9875
integrate_native_title_particle_signed_fractional_positions:
    php
    sep #$20
    jsr publish_nine_native_title_particle_sprites_from_frame_offsets
    lda $02
    clc
    adc $06
    sta $06
    lda $03
    adc $07
    sta $07
    lda $03
    .a8
    and #$80
    beq integrate_native_title_particle_signed_fractional_positions_9890
    .a8
    lda #$FF
integrate_native_title_particle_signed_fractional_positions_9890:
    adc $08
    sta $08
    lda $04
    clc
    adc $09
    sta $09
    lda $05
    adc $0A
    sta $0A
    lda $05
    .a8
    and #$80
    beq integrate_native_title_particle_signed_fractional_positions_98a9
    .a8
    lda #$FF
integrate_native_title_particle_signed_fractional_positions_98a9:
    adc $0B
    sta $0B
    plp
    rts
