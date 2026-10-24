; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3DDC
clear_controller_guard_when_actor_leaves_saved_rectangle:
    lda a:$E1B1,X
    .a8
    bit #$20
    beq clear_controller_guard_when_actor_leaves_saved_rectangle_c03e34
    .a8
    lda #$00
    xba
    lda $81
    asl
    asl
    tay
    rep #$20
    lda a:$FF86,Y
    clc
    .a16
    adc #$000C
    sta $A4
    sec
    .a16
    sbc #$0018
    sta $A6
    lda a:$FF88,Y
    clc
    .a16
    adc #$000C
    sta $A8
    sec
    .a16
    sbc #$0018
    sta $AA
    lda a:$E002,X
    cmp $A4
    bcs clear_controller_guard_when_actor_leaves_saved_rectangle_c03e23
    cmp $A6
    bcc clear_controller_guard_when_actor_leaves_saved_rectangle_c03e23
    lda a:$E004,X
    cmp $A8
    bcs clear_controller_guard_when_actor_leaves_saved_rectangle_c03e23
    cmp $AA
    bcc clear_controller_guard_when_actor_leaves_saved_rectangle_c03e23
    bra clear_controller_guard_when_actor_leaves_saved_rectangle_c03e30
clear_controller_guard_when_actor_leaves_saved_rectangle_c03e23:
    sep #$20
    stz a:$CF03
    lda a:$E1B1,X
    .a8
    and #$DF
    sta a:$E1B1,X
clear_controller_guard_when_actor_leaves_saved_rectangle_c03e30:
    sep #$20
    ldx $85
clear_controller_guard_when_actor_leaves_saved_rectangle_c03e34:
    rts
