; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-target-eligibility.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DAA1
test_one_native_menu_target_actor_and_advance_target_cursor:
    rep #$30
    phx
    .a16
    lda #$0000
    sta a:$0000,Y
    lda f:$7E0020,X
    .a16
    cmp #$0008
    bcc test_one_native_menu_target_actor_and_advance_target_cursor_d0dae9
    .a16
    cmp #$00F8
    bcs test_one_native_menu_target_actor_and_advance_target_cursor_d0dae9
    lda f:$7E0022,X
    .a16
    cmp #$00D8
    bcs test_one_native_menu_target_actor_and_advance_target_cursor_d0dae9
    sep #$20
    lda f:$7E0000,X
    dec
    bne test_one_native_menu_target_actor_and_advance_target_cursor_d0dae9
    .i16
    cpx #$E600
    bcc test_one_native_menu_target_actor_and_advance_target_cursor_d0daeb
    lda a:$1842
    bpl test_one_native_menu_target_actor_and_advance_target_cursor_d0dada
    lda f:$7E0180,X
    bpl test_one_native_menu_target_actor_and_advance_target_cursor_d0db32
test_one_native_menu_target_actor_and_advance_target_cursor_d0dada:
    .a8
    lda #$20
    bit a:$1842
    beq test_one_native_menu_target_actor_and_advance_target_cursor_d0dae9
    lda f:$7E0180,X
    .a8
    cmp #$EA
    beq test_one_native_menu_target_actor_and_advance_target_cursor_d0db44
test_one_native_menu_target_actor_and_advance_target_cursor_d0dae9:
    bra test_one_native_menu_target_actor_and_advance_target_cursor_d0db4d
test_one_native_menu_target_actor_and_advance_target_cursor_d0daeb:
    .a8
    lda #$40
    bit a:$1842
    beq test_one_native_menu_target_actor_and_advance_target_cursor_d0db01
    .i16
    cpx #$E000
    bne test_one_native_menu_target_actor_and_advance_target_cursor_d0db4d
    lda f:$7ECC55
    .a8
    and #$C0
    .a8
    cmp #$40
    bne test_one_native_menu_target_actor_and_advance_target_cursor_d0db4d
test_one_native_menu_target_actor_and_advance_target_cursor_d0db01:
    lda a:$1809
    bne test_one_native_menu_target_actor_and_advance_target_cursor_d0db20
    lda a:$19F1
    .a8
    cmp #$04
    beq test_one_native_menu_target_actor_and_advance_target_cursor_d0db11
    .a8
    cmp #$05
    bra test_one_native_menu_target_actor_and_advance_target_cursor_d0db28
test_one_native_menu_target_actor_and_advance_target_cursor_d0db11:
    rep #$20
    lda f:$7E0190,X
    .a16
    bit #$73FC
    beq test_one_native_menu_target_actor_and_advance_target_cursor_d0db4d
    sep #$20
    bra test_one_native_menu_target_actor_and_advance_target_cursor_d0db44
test_one_native_menu_target_actor_and_advance_target_cursor_d0db20:
    dec
    bne test_one_native_menu_target_actor_and_advance_target_cursor_d0db32
    lda a:$1839
    .a8
    cmp #$21
test_one_native_menu_target_actor_and_advance_target_cursor_d0db28:
    bne test_one_native_menu_target_actor_and_advance_target_cursor_d0db32
    lda f:$7E0191,X
    bpl test_one_native_menu_target_actor_and_advance_target_cursor_d0db4d
    bra test_one_native_menu_target_actor_and_advance_target_cursor_d0db44
test_one_native_menu_target_actor_and_advance_target_cursor_d0db32:
    lda f:$7E0180,X
    .a8
    cmp #$54
    beq test_one_native_menu_target_actor_and_advance_target_cursor_d0db44
    .a8
    cmp #$55
    beq test_one_native_menu_target_actor_and_advance_target_cursor_d0db44
    lda f:$7E0191,X
    bmi test_one_native_menu_target_actor_and_advance_target_cursor_d0db4d
test_one_native_menu_target_actor_and_advance_target_cursor_d0db44:
    inc a:$1834
    rep #$20
    txa
    sta a:$0000,Y
test_one_native_menu_target_actor_and_advance_target_cursor_d0db4d:
    rep #$20
    iny
    iny
    pla
    clc
    .a16
    adc #$0200
    tax
    rts
