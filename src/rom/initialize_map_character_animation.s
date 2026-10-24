; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_map_character_animation_record_and_frames = $B1D0

.segment "CODE"
.org $B17E
initialize_map_character_animation:
    sep #$30
    ldx $1C
    txa
    .a8
    and #$40
    bne initialize_map_character_animation_c1b18a
    stz $9A
    rtl
initialize_map_character_animation_c1b18a:
    stz $12
    phb
    .a8
    lda #$7F
    pha
    plb
    txa
    rep #$30
    .a16
    and #$003F
    asl
    tax
    lda f:$C80602,X
    sec
    sbc f:$C80600,X
    lsr
    .a16
    cmp #$0011
    bcc initialize_map_character_animation_c1b1ab
    .a16
    lda #$0010
initialize_map_character_animation_c1b1ab:
    sta $10
    sep #$20
    sta $9A
    rep #$20
    lda f:$C80600,X
    tax
    .a16
    lda #$8400
    sta $06
    stz $14
initialize_map_character_animation_c1b1bf:
    phx
    jsr prepare_map_character_animation_record_and_frames
    rep #$30
    plx
    inx
    inx
    dec $10
    bne initialize_map_character_animation_c1b1bf
    sep #$30
    plb
    rtl
