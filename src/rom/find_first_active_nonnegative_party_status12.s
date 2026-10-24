; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-target-status-queries.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $328D
find_first_active_nonnegative_party_status12:
    .i16
    ldy #$0000
find_first_active_nonnegative_party_status12_c23290:
    tya
    xba
    asl
    clc
    .a16
    adc #$E000
    tax
    lda a:$0000,X
    .a16
    and #$00FF
    .a16
    cmp #$0001
    bne find_first_active_nonnegative_party_status12_c232b2
    lda a:$0190,X
    bmi find_first_active_nonnegative_party_status12_c232b2
    lda a:$0190,X
    .a16
    bit #$0012
    beq find_first_active_nonnegative_party_status12_c232b2
    tya
    rts
find_first_active_nonnegative_party_status12_c232b2:
    iny
    .i16
    cpy #$0003
    bne find_first_active_nonnegative_party_status12_c23290
    .a16
    lda #$FFFF
    rts
