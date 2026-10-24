; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-status-palette-animation.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c0eda8 = $EDA8

.segment "CODE"
.org $EDD7
advance_actor_secondary_status_palette:
    sep #$20
    sta $00
    lda a:$E047,X
    .a8
    bit #$F0
    beq advance_actor_secondary_status_palette_c0edf9
    pha
    .a8
    and #$0F
    dec
    bmi advance_actor_secondary_status_palette_c0edee
    pla
    dec
    sta a:$E047,X
    rts
advance_actor_secondary_status_palette_c0edee:
    pla
    lsr
    lsr
    lsr
    lsr
    ora a:$E047,X
    sta a:$E047,X
advance_actor_secondary_status_palette_c0edf9:
    lda $00
    .a8
    bit #$20
    beq advance_actor_secondary_status_palette_c0ee0c
    lda a:$E107,X
    xba
    lda a:$E105,X
    ldy a:$E0FA,X
    brl routine_c0eda8
advance_actor_secondary_status_palette_c0ee0c:
    .a8
    bit #$40
    bne advance_actor_secondary_status_palette_c0ee3a
    lda a:$E107,X
    cmp a:$E106,X
    bcc advance_actor_secondary_status_palette_c0ee34
    lsr $00
    bcs advance_actor_secondary_status_palette_c0ee24
    lda a:$E105,X
    sta a:$E107,X
    bra advance_actor_secondary_status_palette_c0ee58
advance_actor_secondary_status_palette_c0ee24:
    dec
    sta a:$E107,X
    pha
    lda a:$E104,X
    .a8
    eor #$40
    sta a:$E104,X
    pla
    bra advance_actor_secondary_status_palette_c0ee58
advance_actor_secondary_status_palette_c0ee34:
    inc
    sta a:$E107,X
    bra advance_actor_secondary_status_palette_c0ee58
advance_actor_secondary_status_palette_c0ee3a:
    lda a:$E107,X
    cmp a:$E105,X
    beq advance_actor_secondary_status_palette_c0ee44
    bcs advance_actor_secondary_status_palette_c0ee54
advance_actor_secondary_status_palette_c0ee44:
    inc
    sta a:$E107,X
    pha
    lda a:$E104,X
    .a8
    eor #$40
    sta a:$E104,X
    pla
    bra advance_actor_secondary_status_palette_c0ee58
advance_actor_secondary_status_palette_c0ee54:
    dec
    sta a:$E107,X
advance_actor_secondary_status_palette_c0ee58:
    ldy a:$E0FA,X
    sta f:$004202
    .a8
    lda #$0A
    sta f:$004203
    .a8
    lda #$D1
    sta $0F
    rep #$20
    .a16
    lda #$F600
    clc
    adc f:$004216
    sta $0D
    .a16
    lda #$0005
    sta $0A
advance_actor_secondary_status_palette_c0ee7a:
    lda [$0D]
    sta a:$0700,Y
    inc $0D
    inc $0D
    iny
    iny
    dec $0A
    bne advance_actor_secondary_status_palette_c0ee7a
    sep #$20
    rts
