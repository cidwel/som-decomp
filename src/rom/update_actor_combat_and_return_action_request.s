; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

apply_actor_status_and_timers = $C8E301
apply_pending_actor_hp_mp_damage_and_healing = $4004
clear_controller_guard_when_actor_leaves_saved_rectangle = $3DDC
coordinate_actor_combat_status_and_buff_timers = $3C19
dispatch_pending_actor_status_program = $3F08
initialize_actor_combat_controller_and_status = $3A3A
rebuild_actor_stats_and_record_status_change_flags = $3E80
refresh_controller_status_bits_from_party = $3F2C
resolve_actor_pending_physical_hits = $C04F7B

.segment "CODE"
.org $3A79
update_actor_combat_and_return_action_request:
    phd
    phb
    php
    rep #$30
    .a16
    and #$00FF
    .a16
    cmp #$00FF
    beq initialize_actor_combat_controller_and_status
    .a16
    lda #$0300
    tcd
    stz $96
    txa
    .a16
    and #$1FFF
    sta $85
    tax
    sep #$20
    xba
    lsr
    sta $81
    lda a:$E060,X
    .a8
    cmp #$20
    bne update_actor_combat_and_return_action_request_c03aad
    inc a:$E1FC,X
    lda a:$E1FC,X
    .a8
    cmp #$40
    bne update_actor_combat_and_return_action_request_c03ab0
    stz a:$E060,X
update_actor_combat_and_return_action_request_c03aad:
    stz a:$E1FC,X
update_actor_combat_and_return_action_request_c03ab0:
    lda a:$E1F8,X
    beq update_actor_combat_and_return_action_request_c03ac1
    dec a:$E1F8,X
    bne update_actor_combat_and_return_action_request_c03abd
    stz a:$E059,X
update_actor_combat_and_return_action_request_c03abd:
    .a8
    lda #$00
    bra update_actor_combat_and_return_action_request_c03b08
update_actor_combat_and_return_action_request_c03ac1:
    lda a:$E1FB,X
    .a8
    bit #$36
    beq update_actor_combat_and_return_action_request_c03b16
update_actor_combat_and_return_action_request_c03ac8:
    .a8
    bit #$02
    beq update_actor_combat_and_return_action_request_c03ae6
    lda a:$E060,X
    .a8
    cmp #$40
    beq update_actor_combat_and_return_action_request_c03ad7
    .a8
    bit #$E0
    bne update_actor_combat_and_return_action_request_c03ae6
update_actor_combat_and_return_action_request_c03ad7:
    lda a:$E1FB,X
    .a8
    and #$FD
    sta a:$E1FB,X
update_actor_combat_and_return_action_request_c03adf:
    rep #$20
    .a16
    lda #$0002
    bra update_actor_combat_and_return_action_request_c03b08
update_actor_combat_and_return_action_request_c03ae6:
    lda a:$E1F0,X
    bmi update_actor_combat_and_return_action_request_c03afe
    asl
    xba
    .a8
    lda #$00
    tay
    lda a:$E180,Y
    .a8
    cmp #$EA
    bne update_actor_combat_and_return_action_request_c03afe
    lda a:$E000,Y
    beq update_actor_combat_and_return_action_request_c03afe
    bra update_actor_combat_and_return_action_request_c03adf
update_actor_combat_and_return_action_request_c03afe:
    lda a:$E1FB,X
    .a8
    and #$FB
    sta a:$E1FB,X
    .a8
    lda #$00
update_actor_combat_and_return_action_request_c03b08:
    sep #$20
    .a8
    cmp #$00
    bne update_actor_combat_and_return_action_request_c03b12
    plp
    plb
    pld
    rtl
update_actor_combat_and_return_action_request_c03b12:
    plp
    plb
    pld
    rtl
update_actor_combat_and_return_action_request_c03b16:
    jsr clear_controller_guard_when_actor_leaves_saved_rectangle
    lda a:$E190,X
    bpl update_actor_combat_and_return_action_request_c03b21
    jsr refresh_controller_status_bits_from_party
update_actor_combat_and_return_action_request_c03b21:
    jsl f:apply_actor_status_and_timers
    jsl f:resolve_actor_pending_physical_hits
    jsr coordinate_actor_combat_status_and_buff_timers
    ldx $85
    jsl f:apply_actor_status_and_timers
    jsr apply_pending_actor_hp_mp_damage_and_healing
    sep #$20
    jsr dispatch_pending_actor_status_program
    lda a:$E1FB,X
    .a8
    bit #$02
    beq update_actor_combat_and_return_action_request_c03b44
    jmp update_actor_combat_and_return_action_request_c03ac8
update_actor_combat_and_return_action_request_c03b44:
    lda a:$E060,X
    .a8
    cmp #$40
    beq update_actor_combat_and_return_action_request_c03b52
    .a8
    bit #$E0
    beq update_actor_combat_and_return_action_request_c03b52
    jmp update_actor_combat_and_return_action_request_c03c05
update_actor_combat_and_return_action_request_c03b52:
    rep #$20
    lda a:$E190,X
    eor a:$E19E,X
    .a16
    bit #$D760
    sep #$20
    bne update_actor_combat_and_return_action_request_c03ba1
    lda a:$E1E5,X
    bmi update_actor_combat_and_return_action_request_c03b8a
    rep #$20
    lda a:$E19E,X
    ora a:$E190,X
    .a16
    bit #$C570
    sep #$20
    beq update_actor_combat_and_return_action_request_c03b7c
    .a8
    lda #$FF
    sta a:$E1E5,X
    bra update_actor_combat_and_return_action_request_c03b8a
update_actor_combat_and_return_action_request_c03b7c:
    lda a:$E1E5,X
    xba
    .a8
    lda #$FF
    sta a:$E1E5,X
    .a8
    lda #$02
    jmp update_actor_combat_and_return_action_request_c03b08
update_actor_combat_and_return_action_request_c03b8a:
    lda a:$E175,X
    beq update_actor_combat_and_return_action_request_c03ba1
    .a8
    lda #$00
    xba
    ldy a:$E17B,X
    lda a:$E175,X
    stz a:$E175,X
    tax
    .a8
    lda #$01
    jmp update_actor_combat_and_return_action_request_c03b08
update_actor_combat_and_return_action_request_c03ba1:
    rep #$20
    lda a:$E19E,X
    .a16
    bit #$4560
    sep #$20
    bne update_actor_combat_and_return_action_request_c03bf4
    lda a:$E1B1,X
    .a8
    bit #$08
    beq update_actor_combat_and_return_action_request_c03bcc
    .a8
    and #$F7
    sta a:$E1B1,X
    lda a:$E191,X
    rep #$20
    bmi update_actor_combat_and_return_action_request_c03bc6
    .a16
    lda #$2B02
    jmp update_actor_combat_and_return_action_request_c03b08
update_actor_combat_and_return_action_request_c03bc6:
    .a16
    lda #$2F02
    jmp update_actor_combat_and_return_action_request_c03b08
update_actor_combat_and_return_action_request_c03bcc:
    lda a:$E1B1,X
    .a8
    bit #$01
    beq update_actor_combat_and_return_action_request_c03bf4
    .a8
    and #$FE
    sta a:$E1B1,X
    lda a:$E190,X
    .a8
    bit #$10
    beq update_actor_combat_and_return_action_request_c03bf4
    lda a:$E1FB,X
    .a8
    bit #$81
    rep #$20
    beq update_actor_combat_and_return_action_request_c03bee
    .a16
    lda #$0F02
    jmp update_actor_combat_and_return_action_request_c03b08
update_actor_combat_and_return_action_request_c03bee:
    .a16
    lda #$0A02
    jmp update_actor_combat_and_return_action_request_c03b08
update_actor_combat_and_return_action_request_c03bf4:
    jsr rebuild_actor_stats_and_record_status_change_flags
    lda a:$E1FA,X
    beq update_actor_combat_and_return_action_request_c03c05
    stz a:$E1FA,X
    tax
    .a8
    lda #$04
    jmp update_actor_combat_and_return_action_request_c03b08
update_actor_combat_and_return_action_request_c03c05:
    lda a:$E1FB,X
    bpl update_actor_combat_and_return_action_request_c03c14
    .a8
    lda #$40
    trb $80
    beq update_actor_combat_and_return_action_request_c03c14
    .a8
    lda #$03
    bra update_actor_combat_and_return_action_request_c03c16
update_actor_combat_and_return_action_request_c03c14:
    .a8
    lda #$00
update_actor_combat_and_return_action_request_c03c16:
    jmp update_actor_combat_and_return_action_request_c03b08
