; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-target-eligibility.md.
.setcpu "65816"
.smart
.a8
.i16

test_one_native_menu_target_actor_and_advance_target_cursor = $DAA1

.segment "CODE"
.org $DA60
build_native_three_actor_menu_target_list_and_count:
    rep #$10
    sep #$20
    .i16
    ldx #$FFFF
    lda a:$1842
    .a8
    bit #$01
    bne build_native_three_actor_menu_target_list_and_count_d0da6f
    dex
build_native_three_actor_menu_target_list_and_count_d0da6f:
    stx a:$1818
    .i16
    ldx #$E000
    lda a:$1842
    bpl build_native_three_actor_menu_target_list_and_count_d0da7d
    .i16
    ldx #$E600
build_native_three_actor_menu_target_list_and_count_d0da7d:
    rep #$20
    stz a:$1834
    .i16
    ldy #$1812
    jsr test_one_native_menu_target_actor_and_advance_target_cursor
    jsr test_one_native_menu_target_actor_and_advance_target_cursor
    jsr test_one_native_menu_target_actor_and_advance_target_cursor
    lda a:$1834
    .a16
    and #$00FF
    dec
    bne build_native_three_actor_menu_target_list_and_count_d0da9f
    pha
    .a16
    lda #$FFFE
    sta a:$1818
    pla
build_native_three_actor_menu_target_list_and_count_d0da9f:
    inc
    rtl
