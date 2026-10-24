; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-particle-initialize.md.
.setcpu "65816"
.smart
.a8
.i16

draw_native_random_byte_below_low_byte_limit = $C288
routine_7eb6d0 = $B6D0

.segment "CODE"
.org $9808
initialize_nine_native_title_particle_sprites_and_random_velocity:
    php
    sep #$20
    .i16
    ldy #$0012
    .a8
    lda #$09
    sta $20
    .a8
    lda #$F3
    sta $22
initialize_nine_native_title_particle_sprites_and_random_velocity_9816:
    phy
    .a8
    lda #$01
    jsr routine_7eb6d0
    lda $22
    dec
    sta a:$0006,X
    .a8
    cmp #$F0
    bne initialize_nine_native_title_particle_sprites_and_random_velocity_9828
    .a8
    lda #$C0
initialize_nine_native_title_particle_sprites_and_random_velocity_9828:
    sta $22
    .a8
    lda #$07
    sta a:$0001,X
    ply
    dey
    dey
    stx $0C,Y
    dec $20
    bne initialize_nine_native_title_particle_sprites_and_random_velocity_9816
    stz $06
    stz $09
    stz $00
    stz $01
    .a8
    lda #$80
    jsr draw_native_random_byte_below_low_byte_limit
    .a8
    ora #$80
    sta $02
    .a8
    lda #$FF
    sta $03
    .a8
    lda #$00
    jsr draw_native_random_byte_below_low_byte_limit
    sta $04
    .a8
    lda #$02
    jsr draw_native_random_byte_below_low_byte_limit
    clc
    .a8
    adc #$FC
    sta $05
    .a8
    lda #$40
    jsr draw_native_random_byte_below_low_byte_limit
    rep #$20
    .a16
    and #$00FF
    clc
    .a16
    adc #$0020
    sta $07
    .a16
    lda #$0100
    sta $0A
    plp
    rts
