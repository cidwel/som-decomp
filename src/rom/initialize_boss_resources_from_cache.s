; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

interpret_boss_loader_commands = $21B7

.segment "CODE"
.org $0040
initialize_boss_resources_from_cache:
    php
    phd
    phb
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    rep #$30
    .a16
    lda #$0200
    tcd
    .a16
    lda #$61BA
    jsr interpret_boss_loader_commands
    stz a:$0FAE
    stz a:$0352
    stz a:$0351
    stz a:$0360
    stz a:$0362
    stz a:$02CD
    stz a:$02CF
    stz a:$02D1
    stz a:$02D3
    stz a:$02D5
    stz a:$02D7
    stz a:$0FA4
    stz a:$0364
    ldy $C5
    lda $C5
initialize_boss_resources_from_cache_c20080:
    sta a:$033F,Y
    iny
    iny
    .i16
    cpy #$0010
    bne initialize_boss_resources_from_cache_c20080
    ldy $C5
initialize_boss_resources_from_cache_c2008c:
    sty a:$0FA6
    lda $C5
    sep #$20
    lda a:$C80D,Y
    beq initialize_boss_resources_from_cache_c200ea
    .a8
    cmp #$57
    bcc initialize_boss_resources_from_cache_c200e0
    .a8
    cmp #$80
    bcs initialize_boss_resources_from_cache_c200e0
    sta $1E
    lda a:$C808,Y
    tax
    lda a:$CF00,X
    .a8
    and #$0F
    sta $1A
    lda a:$C809,Y
    .a8
    and #$F0
    lsr
    lsr
    lsr
    lsr
    sta $1C
    lda $1A
    cmp $1C
    bcc initialize_boss_resources_from_cache_c200e0
    lda a:$C809,Y
    .a8
    and #$0F
    cmp $1A
    bcc initialize_boss_resources_from_cache_c200e0
    lda $1E
    rep #$20
    sta a:$0FA2
    sec
    .a16
    sbc #$0054
    asl
    tax
    lda f:$C200EE,X
    phy
    jsr interpret_boss_loader_commands
    ply
    inc a:$0FA4
initialize_boss_resources_from_cache_c200e0:
    rep #$20
    tya
    clc
    .a16
    adc #$0010
    tay
    bra initialize_boss_resources_from_cache_c2008c
initialize_boss_resources_from_cache_c200ea:
    plb
    pld
    plp
    rtl
