; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

copy_colour_scene_map_template = $9763
create_graphics_buffer = $809B
create_registered_vram_buffer = $C76D
queue_registered_vram_buffer = $C870

.segment "CODE"
.org $BE5B
prepare_colour_scene:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$000A
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    .a16
    lda #$0043
    .i16
    ldx #$0180
    jsr create_graphics_buffer
    stx $05
    .a16
    lda #$0010
    jsr create_registered_vram_buffer
    stx a:$02D4
    clc
    txa
    .a16
    adc #$0600
    tax
    .a16
    lda #$000C
    sta $03
    .a16
    lda #$0000
    sta $07
prepare_colour_scene_be93:
    .a16
    lda #$0010
    sta $01
    sec
    txa
    .a16
    sbc #$0080
    tax
    stx $09
    lda $07
prepare_colour_scene_bea2:
    sta a:$0000,X
    inc
    sta a:$0040,X
    inc
    sta a:$0042,X
    inc
    sta a:$0002,X
    inc
    inx
    inx
    inx
    inx
    dec $01
    bne prepare_colour_scene_bea2
    sta $07
    ldx $09
    dec $03
    bne prepare_colour_scene_be93
    lda a:$02D4
    clc
    .a16
    adc #$0600
    tax
    jsr copy_colour_scene_map_template
    ldx a:$02D4
    jsr queue_registered_vram_buffer
    plb
    tsc
    clc
    .a16
    adc #$000A
    tcs
    plp
    pld
    rts
