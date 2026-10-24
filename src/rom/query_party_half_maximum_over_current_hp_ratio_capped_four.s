; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-party-hp-query.md.
.setcpu "65816"
.smart
.a8
.i16

divide_unsigned_word_by_word_in_software = $2CBF

.segment "CODE"
.org $0989
query_party_half_maximum_over_current_hp_ratio_capped_four:
    .a16
    and #$00FF
    xba
    asl
    clc
    .a16
    adc #$E000
    tax
    lda a:$0190,X
    bpl query_party_half_maximum_over_current_hp_ratio_capped_four_c2099b
    lda $C5
    rts
query_party_half_maximum_over_current_hp_ratio_capped_four_c2099b:
    lda a:$0182,X
    sta $4E
    lda a:$0184,X
    sta $46
    jsr divide_unsigned_word_by_word_in_software
    lda $56
    lsr
    .a16
    cmp #$0004
    bcc query_party_half_maximum_over_current_hp_ratio_capped_four_c209b3
    .a16
    lda #$0004
query_party_half_maximum_over_current_hp_ratio_capped_four_c209b3:
    rts
