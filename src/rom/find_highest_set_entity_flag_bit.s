; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-events.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4720
find_highest_set_entity_flag_bit:
    phd
    php
    rep #$20
    txa
    .i16
    ldx #$0010
find_highest_set_entity_flag_bit_c14728:
    asl
    bcs find_highest_set_entity_flag_bit_c14733
    dex
    bne find_highest_set_entity_flag_bit_c14728
    .a16
    lda #$FFFF
    bra find_highest_set_entity_flag_bit_c14735
find_highest_set_entity_flag_bit_c14733:
    txa
    dec
find_highest_set_entity_flag_bit_c14735:
    plp
    pld
    rts
