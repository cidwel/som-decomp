; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-resources.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_heap_bytes = $3D29
build_spell_entity_script_transfers = $302E
construct_spell_entity_visual_resource = $332C
convert_spell_entity_graphics_planes = $3007
initialize_spell_entity_oam_workspace = $3D8F
send_spell_entity_actor_positional_sound = $37AD
wait_for_spell_entity_irq_completion = $2FE4

.segment "CODE"
.org $37E7
construct_spell_entity_graphics_audio_resources:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0008
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    stx $05
    sty $01
    .a8
    lda #$0F
    xba
    .a8
    lda #$01
    jsr initialize_spell_entity_oam_workspace
    rep #$20
    lda $05
    sec
    .a16
    sbc #$F800
    sta $05
    tax
    lda f:$DCF800,X
    .a16
    and #$00FF
    sta $07
    asl
    asl
    asl
    asl
    asl
    tax
    jsr allocate_spell_entity_heap_bytes
    stx $03
    ldx $05
    lda f:$DCF801,X
    tay
    sep #$20
    ldx $01
    lda a:$0029,X
    sec
    .a8
    sbc #$E0
    lsr
    xba
    lda $07
    ldx $03
    jsr convert_spell_entity_graphics_planes
    jsr wait_for_spell_entity_irq_completion
    ldx $05
    rep #$20
    lda f:$DCF804,X
    tay
    lda f:$DCF803,X
    ldx $03
    jsr build_spell_entity_script_transfers
    ldx $05
    lda f:$DCF80E,X
    ldx $01
    jsr send_spell_entity_actor_positional_sound
    ldy $01
    ldx $05
    jsr construct_spell_entity_visual_resource
    plb
    tsc
    clc
    .a16
    adc #$0008
    tcs
    plp
    pld
    rts
