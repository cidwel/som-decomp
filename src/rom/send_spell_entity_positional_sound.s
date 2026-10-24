; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-graphics-audio.md.
.setcpu "65816"
.smart
.a8
.i16

audio_command_sender_public_jump = $C30004

.segment "CODE"
.org $376A
send_spell_entity_positional_sound:
    phd
    php
    rep #$30
    sep #$20
    phb
    pha
    .a8
    lda #$00
    pha
    plb
    pla
    .a8
    cmp #$00
    beq send_spell_entity_positional_sound_c137a9
    sta a:$1E01
    .a8
    lda #$02
    sta a:$1E00
    .a8
    lda #$00
    sta a:$1E02
    xba
    clc
    .a8
    adc #$08
    bcc send_spell_entity_positional_sound_c13790
    .a8
    lda #$FF
send_spell_entity_positional_sound_c13790:
    lsr
    lsr
    lsr
    lsr
    bne send_spell_entity_positional_sound_c13798
    .a8
    lda #$01
send_spell_entity_positional_sound_c13798:
    sta a:$1E03
    asl
    asl
    asl
    asl
    ora a:$1E03
    sta a:$1E03
    jsl f:audio_command_sender_public_jump
send_spell_entity_positional_sound_c137a9:
    plb
    plp
    pld
    rts
