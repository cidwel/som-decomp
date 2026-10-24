; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

copy_object_weapon_palette = $859B
dispatch_actor_commands_b0_and_above = $D6EF
restore_actor_cached_fifteen_palette_colors = $D8F3

.segment "CODE"
.org $D5CB
dispatch_actor_commands_below_b0:
    .a8
    cmp #$8F
    bcc dispatch_actor_commands_below_b0_c1d5d2
    brl dispatch_actor_commands_below_b0_c1d682
dispatch_actor_commands_below_b0_c1d5d2:
    .a8
    cmp #$88
    bcs dispatch_actor_commands_below_b0_c1d645
    .a8
    cmp #$84
    bcs dispatch_actor_commands_below_b0_c1d621
    .a8
    cmp #$82
    bcs dispatch_actor_commands_below_b0_c1d617
    .a8
    cmp #$80
    bne dispatch_actor_commands_below_b0_c1d5ef
    bit $5C
    bpl dispatch_actor_commands_below_b0_c1d613
    .i16
    cpx #$0600
    bcc dispatch_actor_commands_below_b0_c1d613
    sta a:$E100,X
    rtl
dispatch_actor_commands_below_b0_c1d5ef:
    phx
    rep #$20
    lda a:$E1E3,X
    .a16
    and #$00FF
    asl
    asl
    sta $0C
    asl
    asl
    sec
    sbc $0C
    tax
    sep #$20
    lda f:$D01004,X
    plx
    sta a:$E069,X
    stz a:$E104,X
    jsr copy_object_weapon_palette
    rtl
dispatch_actor_commands_below_b0_c1d613:
    jsr restore_actor_cached_fifteen_palette_colors
    rtl
dispatch_actor_commands_below_b0_c1d617:
    stz a:$E104,X
    lda a:$E069,X
    jsr copy_object_weapon_palette
    rtl
dispatch_actor_commands_below_b0_c1d621:
    .a8
    cmp #$86
    bcs dispatch_actor_commands_below_b0_c1d636
    sec
    .a8
    sbc #$83
    .a8
    eor #$03
    ora a:$E00E,X
    sta a:$E00E,X
    .a8
    lda #$10
    sta a:$E039,X
    rtl
dispatch_actor_commands_below_b0_c1d636:
    bne dispatch_actor_commands_below_b0_c1d641
    .a8
    lda #$40
dispatch_actor_commands_below_b0_c1d63a:
    ora a:$E00E,X
    sta a:$E00E,X
    rtl
dispatch_actor_commands_below_b0_c1d641:
    .a8
    lda #$20
    bra dispatch_actor_commands_below_b0_c1d63a
dispatch_actor_commands_below_b0_c1d645:
    bne dispatch_actor_commands_below_b0_c1d650
    lda a:$E00E,X
    .a8
    and #$0F
    sta a:$E00E,X
    rtl
dispatch_actor_commands_below_b0_c1d650:
    .a8
    cmp #$8D
    bcs dispatch_actor_commands_below_b0_c1d672
    .a8
    cmp #$8A
    bcs dispatch_actor_commands_below_b0_c1d65f
    stz a:$E000,X
    stz a:$E043,X
    rtl
dispatch_actor_commands_below_b0_c1d65f:
    bne dispatch_actor_commands_below_b0_c1d664
    stz $49
    rtl
dispatch_actor_commands_below_b0_c1d664:
    .a8
    cmp #$8B
    bne dispatch_actor_commands_below_b0_c1d66d
    .a8
    lda #$E0
    sta $49
    rtl
dispatch_actor_commands_below_b0_c1d66d:
    .a8
    lda #$60
    sta $49
    rtl
dispatch_actor_commands_below_b0_c1d672:
    bne dispatch_actor_commands_below_b0_c1d681
    stz a:$E047,X
    lda a:$E069,X
    sta $0C
    .a8
    lda #$C0
    brl dispatch_actor_commands_b0_and_above
dispatch_actor_commands_below_b0_c1d681:
    rtl
dispatch_actor_commands_below_b0_c1d682:
    .a8
    cmp #$AB
    bcs dispatch_actor_commands_below_b0_c1d6d2
    sec
    .a8
    sbc #$8F
    rep #$20
    .a16
    and #$00FF
    asl
    asl
    tay
    sep #$20
    lda a:$E010,X
    .a8
    and #$80
    sta $0F
    lda a:$C700,Y
    .a8
    cmp #$80
    beq dispatch_actor_commands_below_b0_c1d6bd
    eor $0F
    .a8
    cmp #$80
    bne dispatch_actor_commands_below_b0_c1d6a9
    .a8
    lda #$00
dispatch_actor_commands_below_b0_c1d6a9:
    sta a:$E006,X
    xba
    lda a:$E013,X
    beq dispatch_actor_commands_below_b0_c1d6bd
    asl
    xba
    beq dispatch_actor_commands_below_b0_c1d6ba
    bcc dispatch_actor_commands_below_b0_c1d6ba
    .a8
    eor #$80
dispatch_actor_commands_below_b0_c1d6ba:
    sta a:$E007,X
dispatch_actor_commands_below_b0_c1d6bd:
    lda a:$C701,Y
    .a8
    cmp #$80
    beq dispatch_actor_commands_below_b0_c1d6c7
    sta a:$E007,X
dispatch_actor_commands_below_b0_c1d6c7:
    lda a:$C702,Y
    .a8
    cmp #$80
    beq dispatch_actor_commands_below_b0_c1d6d1
    sta a:$E008,X
dispatch_actor_commands_below_b0_c1d6d1:
    rtl
dispatch_actor_commands_below_b0_c1d6d2:
    sec
    .a8
    sbc #$AB
    sta a:$E036,X
    sta a:$E037,X
    rtl
