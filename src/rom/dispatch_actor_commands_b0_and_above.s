; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

copy_object_weapon_palette = $859B
load_actor_fifteen_palette_colors_from_rom = $D90D

.segment "CODE"
.org $D6EF
dispatch_actor_commands_b0_and_above:
    .a8
    cmp #$C0
    bcc dispatch_actor_commands_b0_and_above_c1d704
    .a8
    cmp #$D0
    bcs dispatch_actor_commands_b0_and_above_c1d6fa
    brl dispatch_actor_commands_b0_and_above_c1d7df
dispatch_actor_commands_b0_and_above_c1d6fa:
    .a8
    cmp #$E0
    bcs dispatch_actor_commands_b0_and_above_c1d701
    brl dispatch_actor_commands_b0_and_above_c1d83c
dispatch_actor_commands_b0_and_above_c1d701:
    brl dispatch_actor_commands_b0_and_above_c1d8f2
dispatch_actor_commands_b0_and_above_c1d704:
    .a8
    cmp #$B8
    bcc dispatch_actor_commands_b0_and_above_c1d70b
    brl dispatch_actor_commands_b0_and_above_c1d7a2
dispatch_actor_commands_b0_and_above_c1d70b:
    .a8
    cmp #$B4
    bcs dispatch_actor_commands_b0_and_above_c1d74b
    .a8
    cmp #$B2
    bcs dispatch_actor_commands_b0_and_above_c1d742
    .a8
    cmp #$B0
    bne dispatch_actor_commands_b0_and_above_c1d72f
    bit $5C
    bpl dispatch_actor_commands_b0_and_above_c1d73b
    .i16
    cpx #$0600
    bcc dispatch_actor_commands_b0_and_above_c1d73b
    sta a:$E100,X
    sta a:$E102,X
    lda $0C
    sta a:$E101,X
    sta a:$E103,X
    rtl
dispatch_actor_commands_b0_and_above_c1d72f:
    lda $0C
    sta a:$E069,X
    stz a:$E104,X
    jsr copy_object_weapon_palette
    rtl
dispatch_actor_commands_b0_and_above_c1d73b:
    stz a:$E100,X
    jsr load_actor_fifteen_palette_colors_from_rom
    rtl
dispatch_actor_commands_b0_and_above_c1d742:
    stz a:$E104,X
    lda $0C
    jsr copy_object_weapon_palette
    rtl
dispatch_actor_commands_b0_and_above_c1d74b:
    beq dispatch_actor_commands_b0_and_above_c1d760
    .a8
    cmp #$B6
    bcs dispatch_actor_commands_b0_and_above_c1d78d
    lda $0C
    sta a:$1057
    lda $E6
    sta a:$1058
    .a8
    lda #$04
    tsb $E2
    rtl
dispatch_actor_commands_b0_and_above_c1d760:
    bit $5C
    bpl dispatch_actor_commands_b0_and_above_c1d772
    .i16
    cpx #$0600
    bcc dispatch_actor_commands_b0_and_above_c1d772
    lda $0C
    sta a:$E101,X
    .a8
    lda #$B4
    bra dispatch_actor_commands_b0_and_above_c1d789
dispatch_actor_commands_b0_and_above_c1d772:
    lda $0C
    pha
    .a8
    and #$0F
    sta a:$E103,X
    pla
    lsr
    lsr
    lsr
    lsr
    sta a:$E101,X
    cmp a:$E103,X
    bcs dispatch_actor_commands_b0_and_above_c1d789
    .a8
    lda #$A0
dispatch_actor_commands_b0_and_above_c1d789:
    sta a:$E100,X
    rtl
dispatch_actor_commands_b0_and_above_c1d78d:
    bne dispatch_actor_commands_b0_and_above_c1d793
    .a8
    lda #$00
    beq dispatch_actor_commands_b0_and_above_c1d795
dispatch_actor_commands_b0_and_above_c1d793:
    .a8
    lda #$0F
dispatch_actor_commands_b0_and_above_c1d795:
    sta $E7
    lda $0C
    sta $E4
    sta $E5
    .a8
    lda #$01
    tsb $E2
    rtl
dispatch_actor_commands_b0_and_above_c1d7a2:
    .a8
    cmp #$B8
    bne dispatch_actor_commands_b0_and_above_c1d7a7
    rtl
dispatch_actor_commands_b0_and_above_c1d7a7:
    .a8
    cmp #$BC
    bcs dispatch_actor_commands_b0_and_above_c1d7d7
    .a8
    cmp #$BA
    bcs dispatch_actor_commands_b0_and_above_c1d7b9
    lda $0C
    asl
    asl
    asl
    asl
    sta a:$E047,X
    rtl
dispatch_actor_commands_b0_and_above_c1d7b9:
    bne dispatch_actor_commands_b0_and_above_c1d7d6
    lda $0C
    pha
    .a8
    and #$0F
    dec
    sta a:$E107,X
    pla
    lsr
    lsr
    lsr
    lsr
    sta a:$E105,X
    cmp a:$E107,X
    bcs dispatch_actor_commands_b0_and_above_c1d7d3
    .a8
    lda #$A0
dispatch_actor_commands_b0_and_above_c1d7d3:
    sta a:$E104,X
dispatch_actor_commands_b0_and_above_c1d7d6:
    rtl
dispatch_actor_commands_b0_and_above_c1d7d7:
    bne dispatch_actor_commands_b0_and_above_c1d7de
    lda $0C
    sta $49
    rtl
dispatch_actor_commands_b0_and_above_c1d7de:
    rtl
dispatch_actor_commands_b0_and_above_c1d7df:
    .a8
    cmp #$C8
    bcs dispatch_actor_commands_b0_and_above_c1d809
    pha
    .a8
    and #$03
    inc
    clc
    adc $0C
    sta a:$E106,X
    lda $0C
    sta a:$E105,X
    inc
    sta a:$E107,X
    pla
    .a8
    and #$04
    lsr
    lsr
    .a8
    ora #$80
    sta a:$E104,X
    stz a:$E047,X
    lda $0C
    jsr copy_object_weapon_palette
    rtl
dispatch_actor_commands_b0_and_above_c1d809:
    bit $5C
    bpl dispatch_actor_commands_b0_and_above_c1d81b
    .i16
    cpx #$0600
    bcc dispatch_actor_commands_b0_and_above_c1d81b
    sta a:$E100,X
    lda $0C
    sta a:$E101,X
    rtl
dispatch_actor_commands_b0_and_above_c1d81b:
    pha
    .a8
    and #$03
    inc
    clc
    adc $0C
    sta a:$E102,X
    lda $0C
    sta a:$E101,X
    inc
    sta a:$E103,X
    pla
    .a8
    and #$04
    lsr
    lsr
    .a8
    ora #$80
    sta a:$E100,X
    jsr load_actor_fifteen_palette_colors_from_rom
    rtl
dispatch_actor_commands_b0_and_above_c1d83c:
    .a8
    cmp #$D0
    bne dispatch_actor_commands_b0_and_above_c1d878
    lda a:$E010,X
    .a8
    and #$80
    sta $0F
    lda $0C
    .a8
    and #$0F
    .a8
    cmp #$08
    bcc dispatch_actor_commands_b0_and_above_c1d854
    .a8
    eor #$87
    inc
    .a8
    and #$87
dispatch_actor_commands_b0_and_above_c1d854:
    eor $0F
    .a8
    cmp #$80
    bne dispatch_actor_commands_b0_and_above_c1d85c
    .a8
    lda #$00
dispatch_actor_commands_b0_and_above_c1d85c:
    sta a:$E006,X
    lda $0C
    lsr
    lsr
    lsr
    lsr
    .a8
    cmp #$08
    bcc dispatch_actor_commands_b0_and_above_c1d86e
    .a8
    eor #$87
    inc
    .a8
    and #$87
dispatch_actor_commands_b0_and_above_c1d86e:
    .a8
    cmp #$80
    bne dispatch_actor_commands_b0_and_above_c1d874
    .a8
    lda #$00
dispatch_actor_commands_b0_and_above_c1d874:
    sta a:$E007,X
    rtl
dispatch_actor_commands_b0_and_above_c1d878:
    .a8
    cmp #$D4
    bcs dispatch_actor_commands_b0_and_above_c1d8b8
    .a8
    cmp #$D3
    beq dispatch_actor_commands_b0_and_above_c1d8b2
    xba
    xba
    bit $0C
    bpl dispatch_actor_commands_b0_and_above_c1d897
    xba
    lda $0C
    .a8
    eor #$FF
    inc
    .a8
    ora #$80
    .a8
    cmp #$80
    bne dispatch_actor_commands_b0_and_above_c1d894
    .a8
    lda #$00
dispatch_actor_commands_b0_and_above_c1d894:
    sta $0C
    xba
dispatch_actor_commands_b0_and_above_c1d897:
    .a8
    cmp #$D1
    bne dispatch_actor_commands_b0_and_above_c1d8a1
    lda $0C
    sta a:$E007,X
    rtl
dispatch_actor_commands_b0_and_above_c1d8a1:
    lda a:$E010,X
    .a8
    and #$80
    eor $0C
    .a8
    cmp #$80
    bne dispatch_actor_commands_b0_and_above_c1d8ae
    .a8
    lda #$00
dispatch_actor_commands_b0_and_above_c1d8ae:
    sta a:$E006,X
    rtl
dispatch_actor_commands_b0_and_above_c1d8b2:
    lda $0C
    sta a:$E008,X
    rtl
dispatch_actor_commands_b0_and_above_c1d8b8:
    bne dispatch_actor_commands_b0_and_above_c1d8f1
    ldy a:$E05E,X
    lda a:$E060,Y
    beq dispatch_actor_commands_b0_and_above_c1d8c6
    .a8
    cmp #$40
    bne dispatch_actor_commands_b0_and_above_c1d8f1
dispatch_actor_commands_b0_and_above_c1d8c6:
    rep #$20
    lda a:$E002,X
    sta a:$E002,Y
    lda a:$E004,X
    sta a:$E004,Y
    .a16
    lda #$0000
    sta a:$E006,Y
    sep #$20
    lda $0C
    sta a:$E011,Y
    .a8
    lda #$40
    sta a:$E01C,Y
    .a8
    lda #$80
    sta a:$E064,Y
    .a8
    lda #$FF
    sta a:$E030,Y
    rtl
dispatch_actor_commands_b0_and_above_c1d8f1:
    rtl
dispatch_actor_commands_b0_and_above_c1d8f2:
    rtl
