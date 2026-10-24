; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-death-particles.md.
.setcpu "65816"
.smart
.a8
.i16

derive_cosine_by_adding_quarter_turn = $2A59
draw_boss_frame_random_number = $300B
mask_angle_and_derive_native_sine = $2A60
multiply_unsigned_words_with_four_hardware_products = $2AC3

.segment "CODE"
.org $3B98
initialize_256_native_death_particles:
    .a16
    lda #$2000
    sta $1A
initialize_256_native_death_particles_c23b9d:
    lda $C5
    jsr draw_boss_frame_random_number
    sta $95
    jsr derive_cosine_by_adding_quarter_turn
    sta $97
    lda $95
    jsr mask_angle_and_derive_native_sine
    sta $99
    lda $C5
    jsr draw_boss_frame_random_number
    jsr derive_cosine_by_adding_quarter_turn
    sta $46
    .a16
    lda #$02C0
    sta $4E
    jsr multiply_unsigned_words_with_four_hardware_products
    lda $57
    sta $95
    sta $46
    lda $97
    sta $4E
    jsr multiply_unsigned_words_with_four_hardware_products
    lda $57
    sta $97
    lda $95
    sta $46
    lda $99
    sta $4E
    jsr multiply_unsigned_words_with_four_hardware_products
    lda $57
    sta $99
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    ldy $1A
    lda $C5
    sta a:$0000,Y
    sta a:$0002,Y
    lda $97
    sta a:$0004,Y
    lda $99
    sta a:$0006,Y
    plb
    lda $1A
    clc
    .a16
    adc #$0008
    sta $1A
    .a16
    cmp #$2800
    bcc initialize_256_native_death_particles_c23b9d
    rts
