; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-frames.md.
.setcpu "65816"
.smart
.a8
.i16

await_native_menu_vblank_edge = $28FF

.segment "CODE"
.org $2910
fade_out_native_menu_unless_initializing:
    lda f:$7EA212
    .a8
    bit #$10
    bne fade_out_native_menu_unless_initializing_c0292f
    .a8
    lda #$0F
fade_out_native_menu_unless_initializing_c0291a:
    pha
    jsr await_native_menu_vblank_edge
    pla
    sta f:$002100
    dec
    dec
    .a8
    cmp #$FF
    bne fade_out_native_menu_unless_initializing_c0291a
    .a8
    lda #$00
    sta f:$002100
fade_out_native_menu_unless_initializing_c0292f:
    rts
