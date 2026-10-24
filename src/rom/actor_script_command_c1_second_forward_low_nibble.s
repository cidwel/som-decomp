; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_actor_direction_codes = $0404
resolve_visible_second_actor_target = $05BA

.segment "CODE"
.org $1A40
actor_script_command_c1_second_forward_low_nibble:
    jsr resolve_visible_second_actor_target
    bne actor_script_command_c1_second_forward_low_nibble_c11a72
    jsr calculate_actor_direction_codes
    .a8
    and #$0F
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
    bra actor_script_command_c1_second_forward_low_nibble_c11a81
actor_script_command_c1_second_forward_low_nibble_c11a72:
    rep #$20
    lda a:$0144,Y
    clc
    .a16
    adc #$0003
    sta a:$0144,Y
    .a16
    lda #$FFFF
actor_script_command_c1_second_forward_low_nibble_c11a81:
    rts
