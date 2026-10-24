; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

queue_registered_vram_buffer = $C870

.segment "CODE"
.org $CD82
copy_and_submit_title_tilemap:
    phd
    php
    rep #$30
    phb
    phx
    tsc
    tcd
    sep #$20
    lda a:$0310
    sta $03
    ldy a:$0306
    .a8
    lda #$1D
    sta $02
copy_and_submit_title_tilemap_cd98:
    .a8
    lda #$20
    sta $01
copy_and_submit_title_tilemap_cd9c:
    lda f:$7E64A6,X
    inx
    sta a:$0000,Y
    iny
    lda $03
    sta a:$0000,Y
    iny
    dec $01
    bne copy_and_submit_title_tilemap_cd9c
    dec $02
    bne copy_and_submit_title_tilemap_cd98
    ldx a:$0306
    jsr queue_registered_vram_buffer
    pla
    pla
    pla
    plp
    pld
    rts
