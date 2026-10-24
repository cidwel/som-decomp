; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

rebuild_actor_stats_public_jump = $C00036



.segment "CODE"
.org $2599
rebuild_hero_for_actor_program:
    phd
    php
    rep #$30
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    clc
    .a8
    adc #$80
    .a8
    cmp #$03
    bcs rebuild_hero_for_actor_program_c125b2
    tyx
    jsl f:rebuild_actor_stats_public_jump
rebuild_hero_for_actor_program_c125b2:
    plb
    plp
    pld
    rts
