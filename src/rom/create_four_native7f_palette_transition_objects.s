; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-entrance-chain.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_palette_transition_object = $272D

.segment "CODE"
.org $91F3
create_four_native7f_palette_transition_objects:
    .a16
    lda #$00BB
    .i16
    ldx #$0066
    .i16
    ldy #$0004
    jsr allocate_boss_palette_transition_object
    .a16
    lda #$00BB
    .i16
    ldx #$0066
    .i16
    ldy #$0005
    jsr allocate_boss_palette_transition_object
    .a16
    lda #$00BB
    .i16
    ldx #$0066
    .i16
    ldy #$0006
    jsr allocate_boss_palette_transition_object
    .a16
    lda #$00BB
    .i16
    ldx #$0066
    .i16
    ldy #$0007
    jsr allocate_boss_palette_transition_object
    rts
