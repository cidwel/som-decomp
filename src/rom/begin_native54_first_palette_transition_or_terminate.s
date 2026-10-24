; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-projectiles.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_palette_transition_object = $272D

.segment "CODE"
.org $50EE
begin_native54_first_palette_transition_or_terminate:
    ldx $87
    lda a:$00B4,X
    tax
    lda a:$0094,X
    .a16
    cmp #$0004
    bcs begin_native54_first_palette_transition_or_terminate_c2511d
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$000C
    bne begin_native54_first_palette_transition_or_terminate_c2511b
    lda a:$00B0,X
    tax
    .a16
    lda #$0008
    .i16
    ldy #$000F
    jsr allocate_boss_palette_transition_object
    ldx $87
    inc a:$0094,X
    stz a:$0096,X
begin_native54_first_palette_transition_or_terminate_c2511b:
    clc
    rts
begin_native54_first_palette_transition_or_terminate_c2511d:
    sec
    rts
