; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-projectiles.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_palette_transition_object = $272D

.segment "CODE"
.org $511F
begin_native54_second_palette_transition_or_terminate:
    ldx $87
    lda a:$00B4,X
    tax
    lda a:$0094,X
    .a16
    cmp #$0004
    bcs begin_native54_second_palette_transition_or_terminate_c2514e
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$000C
    bne begin_native54_second_palette_transition_or_terminate_c2514c
    lda a:$00B2,X
    tax
    .a16
    lda #$0008
    .i16
    ldy #$000F
    jsr allocate_boss_palette_transition_object
    ldx $87
    dec a:$0094,X
    stz a:$0096,X
begin_native54_second_palette_transition_or_terminate_c2514c:
    clc
    rts
begin_native54_second_palette_transition_or_terminate_c2514e:
    sec
    rts
