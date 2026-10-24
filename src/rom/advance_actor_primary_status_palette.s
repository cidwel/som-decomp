; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-status-palette-animation.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $ED08
advance_actor_primary_status_palette:
    sep #$20
    sta $00
    lda $F4
    .a8
    and #$03
    beq advance_actor_primary_status_palette_c0ed13
    rts
advance_actor_primary_status_palette_c0ed13:
    lda $00
    .a8
    bit #$20
    beq advance_actor_primary_status_palette_c0ed28
    lda a:$E103,X
    xba
    lda a:$E101,X
    ldy a:$E0F8,X
    dey
    dey
    brl advance_actor_primary_status_palette_c0eda8
advance_actor_primary_status_palette_c0ed28:
    .a8
    bit #$40
    bne advance_actor_primary_status_palette_c0ed56
    lda a:$E103,X
    cmp a:$E102,X
    bcc advance_actor_primary_status_palette_c0ed50
    lsr $00
    bcs advance_actor_primary_status_palette_c0ed40
    lda a:$E101,X
    sta a:$E103,X
    bra advance_actor_primary_status_palette_c0ed74
advance_actor_primary_status_palette_c0ed40:
    dec
    sta a:$E103,X
    pha
    lda a:$E100,X
    .a8
    eor #$40
    sta a:$E100,X
    pla
    bra advance_actor_primary_status_palette_c0ed74
advance_actor_primary_status_palette_c0ed50:
    inc
    sta a:$E103,X
    bra advance_actor_primary_status_palette_c0ed74
advance_actor_primary_status_palette_c0ed56:
    lda a:$E103,X
    cmp a:$E101,X
    beq advance_actor_primary_status_palette_c0ed60
    bcs advance_actor_primary_status_palette_c0ed70
advance_actor_primary_status_palette_c0ed60:
    inc
    sta a:$E103,X
    pha
    lda a:$E100,X
    .a8
    eor #$40
    sta a:$E100,X
    pla
    bra advance_actor_primary_status_palette_c0ed74
advance_actor_primary_status_palette_c0ed70:
    dec
    sta a:$E103,X
advance_actor_primary_status_palette_c0ed74:
    ldy a:$E0F8,X
    sta f:$004202
    .a8
    lda #$1E
    sta f:$004203
    .a8
    lda #$C8
    sta $0F
    rep #$20
    .a16
    lda #$1000
    clc
    adc f:$004216
    sta $0D
    .a16
    lda #$000F
    sta $0A
advance_actor_primary_status_palette_c0ed96:
    lda [$0D]
    sta a:$0700,Y
    inc $0D
    inc $0D
    iny
    iny
    dec $0A
    bne advance_actor_primary_status_palette_c0ed96
    sep #$20
    rts
advance_actor_primary_status_palette_c0eda8:
    sty $0E
    rep #$20
    pha
    .a16
    and #$000F
    asl
    clc
    adc $0E
    tay
    pla
    xba
    .a16
    and #$000F
    asl
    clc
    adc $0E
    sta $0E
    lda a:$0700,Y
    pha
advance_actor_primary_status_palette_c0edc4:
    lda a:$0702,Y
    sta a:$0700,Y
    iny
    iny
    cpy $0E
    bcc advance_actor_primary_status_palette_c0edc4
    pla
    sta a:$0700,Y
    sep #$20
    rts
