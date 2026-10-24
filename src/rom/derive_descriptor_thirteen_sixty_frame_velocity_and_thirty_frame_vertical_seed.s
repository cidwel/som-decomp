; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-thirteen-trajectory.md.
.setcpu "65816"
.smart
.a8
.i16

divide_unsigned_double_words_in_software = $2CE6
multiply_signed_double_words_to_quad_word = $2BC3
multiply_unsigned_double_words_in_software = $2B2F

.segment "CODE"
.org $6877
derive_descriptor_thirteen_sixty_frame_velocity_and_thirty_frame_vertical_seed:
    stz $46
    lda $AD
    sta $48
    .a16
    lda #$003C
    sta $4E
    stz $50
    jsr divide_unsigned_double_words_in_software
    lda $56
    sta $1A
    sta $46
    lda $58
    sta $1C
    sta $48
    lda $A5
    sta $4E
    lda $A7
    sta $50
    jsr multiply_signed_double_words_to_quad_word
    ldx $87
    lda $58
    sta a:$003A,X
    lda $5A
    sta a:$003C,X
    lda $1A
    sta $46
    lda $1C
    sta $48
    lda $A9
    sta $4E
    lda $AB
    sta $50
    jsr multiply_signed_double_words_to_quad_word
    ldx $87
    lda $58
    sta a:$003E,X
    lda $5A
    sta a:$0040,X
    lda a:$0FC0
    sta $46
    lda a:$0FC2
    sta $48
    lda $48
    bpl derive_descriptor_thirteen_sixty_frame_velocity_and_thirty_frame_vertical_seed_c268e4
    sec
    lda $C5
    sbc $46
    sta $46
    lda $C5
    sbc $48
    sta $48
derive_descriptor_thirteen_sixty_frame_velocity_and_thirty_frame_vertical_seed_c268e4:
    .a16
    lda #$001E
    sta $4E
    stz $50
    jsr multiply_unsigned_double_words_in_software
    ldx $87
    lda $56
    sta a:$00C4,X
    lda $58
    sta a:$00C6,X
    rts
