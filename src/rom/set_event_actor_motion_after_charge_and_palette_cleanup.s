; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-actor-movement.md.
.setcpu "65816"
.smart
.a8
.i16

clear_actor_movement_charge_and_palette_effects = $CA6C

.segment "CODE"
.org $EEAF
set_event_actor_motion_after_charge_and_palette_cleanup:
    .i8
    ldy #$02
    lda [$D1],Y
    sta $02
    rep #$30
    ldy $D1
    iny
    iny
    iny
    sty $D1
    ldx $D4
    lda $05
    .a16
    and #$00FF
    beq set_event_actor_motion_after_charge_and_palette_cleanup_c1eed2
    ldx $3A
    .a16
    bit #$0080
    bne set_event_actor_motion_after_charge_and_palette_cleanup_c1eed2
    dec
    asl
    xba
    tax
set_event_actor_motion_after_charge_and_palette_cleanup_c1eed2:
    jsr clear_actor_movement_charge_and_palette_effects
    .a8
    lda #$40
    sta a:$E01C,X
    lda $02
    sta a:$E011,X
    .a8
    lda #$FF
    sta a:$E030,X
    .a8
    lda #$01
    sta a:$E042,X
    rts
