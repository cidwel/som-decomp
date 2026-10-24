; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_bytes = $B0A1
allocate_ppu_register_entry = $C030
allocate_vram_pages = $D5F3
append_oneshot_ppu_entry = $C097
select_vram_registration_slot = $C710

.segment "CODE"
.org $C76D
create_registered_vram_buffer:
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
    jsr select_vram_registration_slot
    sta $02
    sep #$20
    lda $01
    .a8
    and #$03
    .i16
    ldx #$0800
    .a8
    cmp #$00
    beq create_registered_vram_buffer_c7a8
    .i16
    ldx #$1000
    .a8
    cmp #$01
    beq create_registered_vram_buffer_c7a8
    .a8
    cmp #$02
    beq create_registered_vram_buffer_c7a8
    .i16
    ldx #$2000
create_registered_vram_buffer_c7a8:
    phx
    .a8
    lda #$00
    jsr allocate_and_fill_bytes
    rep #$20
    txa
    ldx $02
    sta a:$0002,X
    stz a:$0004,X
    stz a:$0006,X
    pla
    xba
    sep #$20
    sta a:$0001,X
    lsr
    lsr
    lsr
    xba
    lda $01
    .a8
    and #$FC
    xba
    jsr allocate_vram_pages
    ldx $02
    sta a:$0000,X
    asl
    asl
    sta $06
    lda $01
    .a8
    and #$03
    ora $06
    sta $06
    lda $01
    lsr
    lsr
    .a8
    and #$03
    sta $04
    clc
    .a8
    adc #$07
    jsr allocate_ppu_register_entry
    lda $06
    sta a:$0002,X
    jsr append_oneshot_ppu_entry
    lda $04
    asl
    clc
    .a8
    adc #$0D
    jsr allocate_ppu_register_entry
    rep #$20
    stz a:$0002,X
    jsr append_oneshot_ppu_entry
    lda $04
    asl
    clc
    .a16
    adc #$000E
    jsr allocate_ppu_register_entry
    stz a:$0002,X
    jsr append_oneshot_ppu_entry
    ldy $02
    ldx a:$0002,Y
    plb
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts
