; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-queue.md.
.setcpu "65816"
.smart
.a8
.i16

find_highest_set_entity_flag_bit = $4720

.segment "CODE"
.org $2923
retire_spell_entity_actor_record:
    phd
    php
    rep #$20
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    .i16
    cpx #$0000
    beq retire_spell_entity_actor_record_c12993
    lda a:$000D,X
    beq retire_spell_entity_actor_record_c1295a
    .a8
    cmp #$20
    beq retire_spell_entity_actor_record_c1293e
    bcs retire_spell_entity_actor_record_c1295a
retire_spell_entity_actor_record_c1293e:
    dec
    rep #$20
    .a16
    and #$00FF
    clc
    adc a:$8216
    tay
    sep #$20
    lda a:$0000,Y
    dec
    .a8
    cmp #$01
    beq retire_spell_entity_actor_record_c12955
    bcs retire_spell_entity_actor_record_c12957
retire_spell_entity_actor_record_c12955:
    .a8
    lda #$00
retire_spell_entity_actor_record_c12957:
    sta a:$0000,Y
retire_spell_entity_actor_record_c1295a:
    lda a:$000F,X
    .a8
    cmp #$05
    bne retire_spell_entity_actor_record_c12990
    lda a:$0009,X
    .a8
    eor #$FF
    and a:$821E
    sta a:$821E
    lda a:$0009,X
    phx
    rep #$20
    .a16
    and #$00FF
    tax
    jsr find_highest_set_entity_flag_bit
    .a16
    and #$0007
    tax
    sep #$20
    stz a:$8220,X
    plx
    lda a:$0009,X
    .a8
    cmp #$80
    bne retire_spell_entity_actor_record_c12990
    stz a:$8228
    stz a:$8229
retire_spell_entity_actor_record_c12990:
    stz a:$000F,X
retire_spell_entity_actor_record_c12993:
    plb
    plp
    pld
    rts
