; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

integrate_boss_vertical_position_and_velocity = $1226

.segment "CODE"
.org $11F4
integrate_boss_height_and_dispatch_enabled_motion_callback:
    lda a:$0070,X
    .a16
    bit #$0001
    beq integrate_boss_height_and_dispatch_enabled_motion_callback_c211ff
    jsr integrate_boss_vertical_position_and_velocity
integrate_boss_height_and_dispatch_enabled_motion_callback_c211ff:
    lda f:$7ECFFF
    .a16
    bit #$0001
    bne integrate_boss_height_and_dispatch_enabled_motion_callback_c21225
    lda a:$1D04
    .a16
    bit #$0040
    bne integrate_boss_height_and_dispatch_enabled_motion_callback_c21225
    lda a:$0060,X
    .a16
    and #$00FF
    .a16
    cmp #$00C0
    beq integrate_boss_height_and_dispatch_enabled_motion_callback_c21225
    lda a:$0090,X
    beq integrate_boss_height_and_dispatch_enabled_motion_callback_c21225
    sta $76
    jmp ($0276)
integrate_boss_height_and_dispatch_enabled_motion_callback_c21225:
    rts
