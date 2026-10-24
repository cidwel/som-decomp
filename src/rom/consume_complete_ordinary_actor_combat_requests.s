; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

actor_combat_tick_public_jump = $C0002D
cancel_actor_charge_for_interrupting_motion = $CA58
create_complete_floating_combat_number = $810E
refresh_actor_graphics_status_and_controller = $939C
wait_for_native_nmi_and_refresh_party_hud_numbers = $E326

.segment "CODE"
.org $8089
consume_complete_ordinary_actor_combat_requests:
    sep #$20
    lda $52
    ora $FF
    bne consume_complete_ordinary_actor_combat_requests_c180b7
    lda $F1
    bmi consume_complete_ordinary_actor_combat_requests_c180b7
    lda $E8
    .a8
    and #$04
    bne consume_complete_ordinary_actor_combat_requests_c180b7
    lda $D0
    beq consume_complete_ordinary_actor_combat_requests_c180ae
    .i16
    cpx #$0600
    bcc consume_complete_ordinary_actor_combat_requests_c180aa
    cpx $3A
    bne consume_complete_ordinary_actor_combat_requests_c180ae
    beq consume_complete_ordinary_actor_combat_requests_c180b7
consume_complete_ordinary_actor_combat_requests_c180aa:
    cpx $D4
    beq consume_complete_ordinary_actor_combat_requests_c180b7
consume_complete_ordinary_actor_combat_requests_c180ae:
    bit $ED
    bmi consume_complete_ordinary_actor_combat_requests_c180b8
    .i16
    cpx #$0600
    bcc consume_complete_ordinary_actor_combat_requests_c180b8
consume_complete_ordinary_actor_combat_requests_c180b7:
    rtl
consume_complete_ordinary_actor_combat_requests_c180b8:
    .a8
    lda #$00
    phx
    jsl f:actor_combat_tick_public_jump
    sep #$20
    .a8
    cmp #$00
    beq consume_complete_ordinary_actor_combat_requests_c1810c
    .a8
    cmp #$01
    bne consume_complete_ordinary_actor_combat_requests_c180d4
    txa
    plx
    sta a:$E04F,X
    sty $1E
    jsr create_complete_floating_combat_number
    rtl
consume_complete_ordinary_actor_combat_requests_c180d4:
    .a8
    cmp #$02
    bne consume_complete_ordinary_actor_combat_requests_c180f3
    plx
    xba
    .a8
    ora #$80
    sta a:$E011,X
    jsr cancel_actor_charge_for_interrupting_motion
    .a8
    lda #$40
    sta a:$E01C,X
    stz a:$E006,X
    stz a:$E007,X
    .a8
    lda #$FF
    sta a:$E030,X
    rtl
consume_complete_ordinary_actor_combat_requests_c180f3:
    .a8
    cmp #$03
    bne consume_complete_ordinary_actor_combat_requests_c180fe
    jsr wait_for_native_nmi_and_refresh_party_hud_numbers
    rep #$10
    plx
consume_complete_ordinary_actor_combat_requests_c180fd:
    rtl
consume_complete_ordinary_actor_combat_requests_c180fe:
    .a8
    cmp #$04
    bne consume_complete_ordinary_actor_combat_requests_c1810c
    txa
    plx
    .a8
    bit #$0F
    beq consume_complete_ordinary_actor_combat_requests_c180fd
    jsr refresh_actor_graphics_status_and_controller
    rtl
consume_complete_ordinary_actor_combat_requests_c1810c:
    plx
    rtl
