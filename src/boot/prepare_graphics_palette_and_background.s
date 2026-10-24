; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_palette_slot = $BBAB
allocate_ppu_register_entry = $C030
allocate_transfer_descriptor = $8FC7
append_oneshot_ppu_entry = $C097
copy_palette_colours = $BC9A
create_graphics_buffer = $809B
create_registered_vram_buffer = $C76D
queue_palette_upload = $BBFE
queue_registered_vram_buffer = $C870
submit_transfer_or_program_hdma = $90DA

.segment "CODE"
.org $BA7F
prepare_graphics_palette_and_background:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0008
    tcd
    tcs
    .a16
    lda #$0049
    .i16
    ldx #$0200
    jsr create_graphics_buffer
    stx $07
    .a16
    lda #$0001
    jsr allocate_transfer_descriptor
    lda $07
    sta a:$000A,X
    .a16
    lda #$2000
    sta a:$0002,X
    .a16
    lda #$1000
    sta a:$0005,X
    sep #$20
    .a8
    lda #$7E
    sta a:$0004,X
    rep #$20
    jsr submit_transfer_or_program_hdma
    .a16
    lda #$0001
    jsr allocate_transfer_descriptor
    lda $07
    clc
    .a16
    adc #$0800
    sta a:$000A,X
    .a16
    lda #$3000
    sta a:$0002,X
    .a16
    lda #$1000
    sta a:$0005,X
    sep #$20
    .a8
    lda #$7E
    sta a:$0004,X
    jsr submit_transfer_or_program_hdma
    .a8
    lda #$00
    jsr allocate_palette_slot
    phx
    .a8
    lda #$7E
    xba
    .a8
    lda #$12
    .i16
    ldy #$5150
    jsr copy_palette_colours
    plx
    jsr queue_palette_upload
    asl
    asl
    .a8
    ora #$20
    xba
    .a8
    lda #$00
    rep #$20
    sta $05
    .a16
    lda #$0019
    jsr create_registered_vram_buffer
    stx $03
    .a16
    lda #$000E
    sta $01
prepare_graphics_palette_and_background_bb0a:
    .i16
    ldy #$0010
    lda $05
prepare_graphics_palette_and_background_bb0f:
    sta a:$0000,X
    .a16
    eor #$0100
    sta a:$0020,X
    .a16
    eor #$0100
    inx
    inx
    inc
    dey
    bne prepare_graphics_palette_and_background_bb0f
    sta $05
    clc
    txa
    .a16
    adc #$0020
    tax
    dec $01
    bne prepare_graphics_palette_and_background_bb0a
    .i16
    ldy #$0640
    .a16
    lda #$210F
prepare_graphics_palette_and_background_bb33:
    sta a:$0000,X
    inx
    inx
    dey
    bne prepare_graphics_palette_and_background_bb33
    ldx $03
    jsr queue_registered_vram_buffer
    .a16
    lda #$0012
    jsr allocate_ppu_register_entry
    .a16
    lda #$FFC8
    sta a:$0002,X
    jsr append_oneshot_ppu_entry
    .a16
    lda #$0011
    jsr allocate_ppu_register_entry
    .a16
    lda #$0000
    sta a:$0002,X
    jsr append_oneshot_ppu_entry
    tsc
    clc
    .a16
    adc #$0008
    tcs
    plp
    pld
    rts
