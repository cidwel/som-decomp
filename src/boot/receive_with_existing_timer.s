; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

boot_ac3f = $AC3F
mark_timer_ready = $CC43
mark_timer_waiting = $CC57
release_eight_byte_record = $B1DD
suspend_current_task = $A911

.segment "CODE"
.org $ABAD
receive_with_existing_timer:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    php
    sei
    ldy a:$009E
    ldx a:$000C,Y
    jsr mark_timer_waiting
    jsr suspend_current_task
    phx
    ldy a:$009E
    ldx a:$000C,Y
    jsr mark_timer_ready
    plx
    beq boot_ac3f
    lda a:$0002,X
    .a8
    and #$FF
    .a8
    cmp #$FF
    bne receive_with_existing_timer_abe2
    jsr release_eight_byte_record
    .i16
    ldx #$0000
receive_with_existing_timer_abe2:
    plp
    plb
    plp
    pld
    rts
