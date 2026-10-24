; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-screen-requests.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_palette_transition_object = $272D

.segment "CODE"
.org $6F05
request_boss_palette_slots_six_seven_to_zero:
    sep #$20
    .a8
    lda #$00
    .i16
    ldx #$0006
    sta a:$033F,X
    inx
    sta a:$033F,X
    rep #$20
    .i16
    ldx #$0000
    .i16
    ldy #$0006
    .a16
    lda #$0036
    jsr allocate_boss_palette_transition_object
    .i16
    ldx #$0000
    .i16
    ldy #$0007
    .a16
    lda #$0036
    jsr allocate_boss_palette_transition_object
    rts
