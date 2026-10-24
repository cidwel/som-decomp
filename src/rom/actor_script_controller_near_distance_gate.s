; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

classify_actor_squared_distance = $0358
jump_actor_script_after_1_bytes = $0285
reject_ineligible_or_nonmonster_actor = $058B
resolve_controller_hero_actor = $04D3
skip_actor_script_after_1_bytes = $0213

.segment "CODE"
.org $1CFF
actor_script_controller_near_distance_gate:
    phd
    php
    rep #$20
    phb
    tsc
    tcd
    sep #$20
    .a8
    lda #$03
    sta $01
    .i16
    ldx #$E600
actor_script_controller_near_distance_gate_c11d0f:
    jsr reject_ineligible_or_nonmonster_actor
    bcc actor_script_controller_near_distance_gate_c11d26
    clc
    rep #$20
    txa
    .a16
    adc #$0200
    tax
    sep #$20
    sep #$20
    dec $01
    bne actor_script_controller_near_distance_gate_c11d0f
    bra actor_script_controller_near_distance_gate_c11d44
actor_script_controller_near_distance_gate_c11d26:
    sep #$20
    .a8
    lda #$03
    sta $01
actor_script_controller_near_distance_gate_c11d2c:
    .a8
    lda #$03
    sec
    sbc $01
    jsr resolve_controller_hero_actor
    .i16
    cpx #$0000
    beq actor_script_controller_near_distance_gate_c11d40
    jsr classify_actor_squared_distance
    .a8
    bit #$20
    beq actor_script_controller_near_distance_gate_c11d49
actor_script_controller_near_distance_gate_c11d40:
    dec $01
    bne actor_script_controller_near_distance_gate_c11d2c
actor_script_controller_near_distance_gate_c11d44:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_controller_near_distance_gate_c11d4c
actor_script_controller_near_distance_gate_c11d49:
    jsr skip_actor_script_after_1_bytes
actor_script_controller_near_distance_gate_c11d4c:
    sta $01,S
    pla
    plp
    pld
    rts
