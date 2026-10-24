; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_ppu_register_entry = $C030
append_oneshot_ppu_entry = $C097
dispatch_parent_messages = $D17F

.segment "CODE"
.org $D1DA
fade_parent_display_until_control_exit:
    phd
    php
    rep #$30
    sep #$20
fade_parent_display_until_control_exit_d1e0:
    .i16
    ldx #$0004
    jsr dispatch_parent_messages
    .a8
    cmp #$00
    beq fade_parent_display_until_control_exit_d20a
    lda a:$0314
    bne fade_parent_display_until_control_exit_d1e0
    .a8
    lda #$00
    jsr allocate_ppu_register_entry
    lda a:$0002,X
    .a8
    cmp #$00
    beq fade_parent_display_until_control_exit_d208
    dec
    sta a:$0002,X
    pha
    jsr append_oneshot_ppu_entry
    pla
    .a8
    cmp #$00
    bne fade_parent_display_until_control_exit_d1e0
fade_parent_display_until_control_exit_d208:
    .a8
    lda #$01
fade_parent_display_until_control_exit_d20a:
    plp
    pld
    rts
