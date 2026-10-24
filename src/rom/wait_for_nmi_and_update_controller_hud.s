; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

write_actor_controller_hud_tile = $BF73

.segment "CODE"
.org $BF38
wait_for_nmi_and_update_controller_hud:
    sep #$20
    lda f:$7ECF00
    bne wait_for_nmi_and_update_controller_hud_c0bf41
    rts
wait_for_nmi_and_update_controller_hud_c0bf41:
    rep #$10
    .a8
    lda #$02
    sta $EC
wait_for_nmi_and_update_controller_hud_c0bf47:
    bit $EC
    bne wait_for_nmi_and_update_controller_hud_c0bf47
    stz a:$2115
    .a8
    lda #$5B
    xba
    lda a:$0A55
    beq wait_for_nmi_and_update_controller_hud_c0bf5c
    .i16
    ldx #$0000
    jsr write_actor_controller_hud_tile
wait_for_nmi_and_update_controller_hud_c0bf5c:
    lda a:$0A65
    beq wait_for_nmi_and_update_controller_hud_c0bf67
    .i16
    ldx #$0200
    jsr write_actor_controller_hud_tile
wait_for_nmi_and_update_controller_hud_c0bf67:
    lda a:$0A75
    beq wait_for_nmi_and_update_controller_hud_c0bf72
    .i16
    ldx #$0400
    jsr write_actor_controller_hud_tile
wait_for_nmi_and_update_controller_hud_c0bf72:
    rts
