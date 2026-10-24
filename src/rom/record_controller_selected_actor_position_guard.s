; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3E35
record_controller_selected_actor_position_guard:
    phd
    phb
    php
    rep #$30
    .a16
    lda #$0300
    tcd
    sep #$20
    xba
    lda a:$00D9
    bmi record_controller_selected_actor_position_guard_c03e53
    lda a:$00DA
    bmi record_controller_selected_actor_position_guard_c03e53
    lda a:$00DB
    bmi record_controller_selected_actor_position_guard_c03e53
    jmp record_controller_selected_actor_position_guard_c03e7c
record_controller_selected_actor_position_guard_c03e53:
    .a8
    and #$0F
    dec
    .a8
    cmp #$03
    bne record_controller_selected_actor_position_guard_c03e5b
    dec
record_controller_selected_actor_position_guard_c03e5b:
    sta $A4
    asl
    xba
    tax
    xba
    lda a:$E1B1,X
    .a8
    ora #$20
    sta a:$E1B1,X
    lda $A4
    asl
    asl
    tay
    rep #$20
    lda a:$E002,X
    sta a:$FF86,Y
    lda a:$E004,X
    sta a:$FF88,Y
record_controller_selected_actor_position_guard_c03e7c:
    plp
    plb
    pld
    rtl
