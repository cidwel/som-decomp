; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-graphics-audio.md.
.setcpu "65816"
.smart
.a8
.i16

send_spell_entity_positional_sound = $376A

.segment "CODE"
.org $37AD
send_spell_entity_actor_positional_sound:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0002
    tcd
    tcs
    lda $03,S
    sep #$20
    .a8
    cmp #$00
    beq send_spell_entity_actor_positional_sound_c137e0
    xba
    .a8
    cmp #$00
    beq send_spell_entity_actor_positional_sound_c137d9
    xba
    pha
    lda a:$0000,X
    asl
    .a8
    ora #$E0
    xba
    .a8
    lda #$00
    tax
    lda a:$0020,X
    xba
    pla
    bra send_spell_entity_actor_positional_sound_c137dd
send_spell_entity_actor_positional_sound_c137d9:
    lda a:$0022,X
    xba
send_spell_entity_actor_positional_sound_c137dd:
    jsr send_spell_entity_positional_sound
send_spell_entity_actor_positional_sound_c137e0:
    pla
    pla
    pla
    pla
    plp
    pld
    rts
