; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

test_animation_party_radii_and_mark_contact_slot = $17A9

.segment "CODE"
.org $1723
test_animation_movement_against_three_active_party_actors:
    lda a:$0098,X
    .a16
    bit #$0010
    beq test_animation_movement_against_three_active_party_actors_c217a7
    lda a:$0066,X
    .a16
    cmp #$0040
    bcs test_animation_movement_against_three_active_party_actors_c217a7
    lda a:$002B,X
    sta $46
    lda a:$0032,X
    clc
    adc a:$00A5,X
    sta $4E
    lda a:$001E,X
    asl
    tax
    lda f:$D97F09,X
    .a16
    and #$00FF
    sta $48
    lda f:$D97F0A,X
    .a16
    and #$00FF
    sta $50
    .i16
    ldy #$0000
test_animation_movement_against_three_active_party_actors_c2175b:
    tya
    xba
    asl
    clc
    .a16
    adc #$E000
    tax
    lda a:$0000,X
    .a16
    cmp #$0001
    bne test_animation_movement_against_three_active_party_actors_c2179f
    lda a:$0190,X
    .a16
    bit #$8000
    bne test_animation_movement_against_three_active_party_actors_c2179f
    lda a:$0002,X
    sta $56
    lda a:$0004,X
    sta $5E
    lda a:$0089,X
    .a16
    and #$0003
    inc
    asl
    tax
    lda f:$D97F09,X
    .a16
    and #$00FF
    sta $58
    lda f:$D97F0A,X
    .a16
    and #$00FF
    sta $60
    jsr test_animation_party_radii_and_mark_contact_slot
    bcc test_animation_movement_against_three_active_party_actors_c2179f
    sec
    rts
test_animation_movement_against_three_active_party_actors_c2179f:
    iny
    .i16
    cpy #$0003
    bne test_animation_movement_against_three_active_party_actors_c2175b
    ldx $87
test_animation_movement_against_three_active_party_actors_c217a7:
    clc
    rts
