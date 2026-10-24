; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_bytes = $B0A1
allocate_ppu_register_entry = $C030
allocate_vram_pages = $D5F3
append_oneshot_ppu_entry = $C097
boot_c34d = $C34D
select_graphics_registration = $805F

.segment "CODE"
.org $809B
create_graphics_buffer:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    lda $05,S
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    rep #$20
    sta $01
    stx $02
    jsr select_graphics_registration
    rep #$20
    sta $04
    ldx $02
    .a16
    lda #$0000
    jsr allocate_and_fill_bytes
    txa
    ldx $04
    sta a:$0006,X
    sta a:$0004,X
    sep #$20
    lda $01
    .a8
    and #$03
    sta a:$0002,X
    dec
    jsr boot_c34d
    rep #$20
    txa
create_graphics_buffer_80e0:
    lsr
    bcs create_graphics_buffer_80e7
    asl $02
    bra create_graphics_buffer_80e0
create_graphics_buffer_80e7:
    lda $02
    clc
    .a16
    adc #$007F
    .a16
    and #$FF80
    lsr
    lsr
    lsr
    lsr
    lsr
    lsr
    lsr
    sep #$20
    ldx $04
    sta a:$0001,X
    xba
    lda $01
    .a8
    and #$FC
    xba
    jsr allocate_vram_pages
    ldx $04
    sta a:$0000,X
    lsr
    lsr
    sta $06
    lda $01
    .a8
    and #$FC
    .a8
    cmp #$80
    beq create_graphics_buffer_8178
    .a8
    cmp #$40
    beq create_graphics_buffer_8167
    .a8
    cmp #$44
    beq create_graphics_buffer_814e
    .a8
    cmp #$48
    beq create_graphics_buffer_813d
    lda $06
    asl
    asl
    asl
    asl
    sta $06
    .a8
    lda #$0C
    jsr allocate_ppu_register_entry
    lda a:$0002,X
    .a8
    and #$0F
    ora $06
    sta a:$0002,X
    bra create_graphics_buffer_818c
create_graphics_buffer_813d:
    .a8
    lda #$0C
    jsr allocate_ppu_register_entry
    lda a:$0002,X
    .a8
    and #$F0
    ora $06
    sta a:$0002,X
    bra create_graphics_buffer_818c
create_graphics_buffer_814e:
    lda $06
    asl
    asl
    asl
    asl
    sta $06
    .a8
    lda #$0B
    jsr allocate_ppu_register_entry
    lda a:$0002,X
    .a8
    and #$0F
    ora $06
    sta a:$0002,X
    bra create_graphics_buffer_818c
create_graphics_buffer_8167:
    .a8
    lda #$0B
    jsr allocate_ppu_register_entry
    lda a:$0002,X
    .a8
    and #$F0
    ora $06
    sta a:$0002,X
    bra create_graphics_buffer_818c
create_graphics_buffer_8178:
    lda $06
    lsr
    sta $06
    .a8
    lda #$01
    jsr allocate_ppu_register_entry
    lda a:$0002,X
    .a8
    and #$F8
    ora $06
    sta a:$0002,X
create_graphics_buffer_818c:
    jsr append_oneshot_ppu_entry
    ldx $04
    lda a:$0000,X
    asl
    asl
    xba
    rep #$20
    .a16
    and #$FF00
    tax
    plb
    sta $05,S
    tsc
    clc
    .a16
    adc #$0004
    tcs
    pla
    plp
    pld
    rts
