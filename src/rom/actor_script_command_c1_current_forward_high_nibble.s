; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_actor_direction_codes = $0404
resolve_visible_current_actor_target = $05A5

.segment "CODE"
.org $1B98
actor_script_command_c1_current_forward_high_nibble:
    jsr resolve_visible_current_actor_target
    bne actor_script_command_c1_current_forward_high_nibble_c11bcc
    jsr calculate_actor_direction_codes
    lsr
    lsr
    lsr
    lsr
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
    bra actor_script_command_c1_current_forward_high_nibble_c11bdb
actor_script_command_c1_current_forward_high_nibble_c11bcc:
    rep #$20
    lda a:$0144,Y
    clc
    .a16
    adc #$0003
    sta a:$0144,Y
    .a16
    lda #$FFFF
actor_script_command_c1_current_forward_high_nibble_c11bdb:
    rts
