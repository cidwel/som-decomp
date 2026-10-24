; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

read_actor_facing_direction_code = $0502

.segment "CODE"
.org $1C24
actor_script_command_c1_from_velocity_and_native_mask:
    phd
    php
    rep #$20
    phb
    tsc
    tcd
    sep #$20
    stz $01
    lda a:$0006,Y
    beq actor_script_command_c1_from_velocity_and_native_mask_c11c42
    bit $80
    beq actor_script_command_c1_from_velocity_and_native_mask_c11c3e
    .a8
    lda #$02
    sta $01
    bra actor_script_command_c1_from_velocity_and_native_mask_c11c42
actor_script_command_c1_from_velocity_and_native_mask_c11c3e:
    .a8
    lda #$01
    sta $01
actor_script_command_c1_from_velocity_and_native_mask_c11c42:
    lda a:$0007,Y
    beq actor_script_command_c1_from_velocity_and_native_mask_c11c59
    bit $80
    beq actor_script_command_c1_from_velocity_and_native_mask_c11c53
    lda $01
    .a8
    ora #$08
    sta $01
    bra actor_script_command_c1_from_velocity_and_native_mask_c11c59
actor_script_command_c1_from_velocity_and_native_mask_c11c53:
    lda $01
    .a8
    ora #$04
    sta $01
actor_script_command_c1_from_velocity_and_native_mask_c11c59:
    lda $01
    bne actor_script_command_c1_from_velocity_and_native_mask_c11c60
    jsr read_actor_facing_direction_code
actor_script_command_c1_from_velocity_and_native_mask_c11c60:
    sta a:$0141,Y
    .a8
    lda #$C1
    sta a:$0140,Y
    ldx a:$0144,Y
    lda f:$D04F16,X
    sta a:$0142,Y
    lda f:$D04F17,X
    sta a:$0143,Y
    rep #$20
    txa
    clc
    .a16
    adc #$0003
    sta a:$0144,Y
    .a16
    lda #$0000
    sep #$20
    sta $01,S
    pla
    plp
    pld
    rts
