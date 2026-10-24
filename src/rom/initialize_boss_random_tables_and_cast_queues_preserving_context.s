; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-public-initialize.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_boss_random_seed_pool_and_two_separated_indices = $3057
public_cast_queue_initializer_jump = $C00045

.segment "CODE"
.org $001B
initialize_boss_random_tables_and_cast_queues_preserving_context:
    php
    phd
    phb
    pha
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    rep #$30
    .a16
    lda #$0200
    tcd
    pla
    pha
    jsr initialize_boss_random_seed_pool_and_two_separated_indices
    stz $C5
    .a16
    lda #$FFFF
    sta $C7
    pla
    jsl f:public_cast_queue_initializer_jump
    plb
    pld
    plp
    rtl
