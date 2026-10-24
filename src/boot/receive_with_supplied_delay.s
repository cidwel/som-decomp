; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

mark_timer_ready = $CC43
release_eight_byte_record = $B1DD
set_timer_countdown = $CC16
suspend_current_task = $A911

.segment "CODE"
.org $ABE7
receive_with_supplied_delay:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    php
    sei
    txa
    bne receive_with_supplied_delay_ac09
    ldx a:$009E
    lda a:$000A,X
    bne receive_with_supplied_delay_ac13
    .a16
    lda #$FFFF
    sta a:$000A,X
    bra receive_with_supplied_delay_ac13
receive_with_supplied_delay_ac09:
    ldy a:$009E
    ldx a:$000C,Y
    tay
    jsr set_timer_countdown
receive_with_supplied_delay_ac13:
    jsr suspend_current_task
    phx
    ldy a:$009E
    ldx a:$000C,Y
    jsr mark_timer_ready
    plx
    beq receive_with_supplied_delay_ac3f
    lda a:$0002,X
    .a16
    and #$00FF
    .a16
    cmp #$00FF
    bne receive_with_supplied_delay_ac3f
    ldy a:$009E
    lda a:$000C,Y
    cmp a:$0004,X
    bne receive_with_supplied_delay_ac3f
    jsr release_eight_byte_record
    .i16
    ldx #$0000
receive_with_supplied_delay_ac3f:
    plp
    plb
    plp
    pld
    rts
