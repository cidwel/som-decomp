; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-nine.md.
.setcpu "65816"
.smart
.a8
.i16

draw_boss_frame_random_number = $300B
select_nearest_living_target_and_eight_way_direction = $3A41

.segment "CODE"
.org $654B
choose_descriptor_nine_nonrepeating_phase_or_dispatch_current:
    jsr select_nearest_living_target_and_eight_way_direction
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    bne choose_descriptor_nine_nonrepeating_phase_or_dispatch_current_c2657c
    ldx $87
    lda a:$007E,X
    .a16
    bit #$8000
    beq choose_descriptor_nine_nonrepeating_phase_or_dispatch_current_c2657c
    lda a:$007E,X
    .a16
    and #$00FF
    sta $00
    .a16
    lda #$0004
    jsr draw_boss_frame_random_number
    ldx $87
    cmp $00
    beq choose_descriptor_nine_nonrepeating_phase_or_dispatch_current_c2657c
    asl
    tax
    lda f:$DCE324,X
    clc
    rts
choose_descriptor_nine_nonrepeating_phase_or_dispatch_current_c2657c:
    ldx $87
    lda a:$007E,X
    .a16
    and #$00FF
    asl
    tax
    jmp ($6589,X)
