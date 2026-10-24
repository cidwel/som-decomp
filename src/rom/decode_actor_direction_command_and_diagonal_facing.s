; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-action-direction.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DB27
decode_actor_direction_command_and_diagonal_facing:
    lda a:$E141,X
    .a8
    bit #$01
    beq decode_actor_direction_command_and_diagonal_facing_c1db42
    .a8
    bit #$04
    beq decode_actor_direction_command_and_diagonal_facing_c1db36
    .a8
    lda #$01
    bra decode_actor_direction_command_and_diagonal_facing_c1db3c
decode_actor_direction_command_and_diagonal_facing_c1db36:
    .a8
    bit #$08
    beq decode_actor_direction_command_and_diagonal_facing_c1db3f
    .a8
    lda #$80
decode_actor_direction_command_and_diagonal_facing_c1db3c:
    sta a:$E013,X
decode_actor_direction_command_and_diagonal_facing_c1db3f:
    .a8
    lda #$02
    rts
decode_actor_direction_command_and_diagonal_facing_c1db42:
    .a8
    bit #$02
    beq decode_actor_direction_command_and_diagonal_facing_c1db5a
    .a8
    bit #$04
    beq decode_actor_direction_command_and_diagonal_facing_c1db4e
    .a8
    lda #$80
    bra decode_actor_direction_command_and_diagonal_facing_c1db54
decode_actor_direction_command_and_diagonal_facing_c1db4e:
    .a8
    bit #$08
    beq decode_actor_direction_command_and_diagonal_facing_c1db57
    .a8
    lda #$01
decode_actor_direction_command_and_diagonal_facing_c1db54:
    sta a:$E013,X
decode_actor_direction_command_and_diagonal_facing_c1db57:
    .a8
    lda #$82
    rts
decode_actor_direction_command_and_diagonal_facing_c1db5a:
    .a8
    bit #$04
    beq decode_actor_direction_command_and_diagonal_facing_c1db61
    .a8
    lda #$01
    rts
decode_actor_direction_command_and_diagonal_facing_c1db61:
    .a8
    bit #$08
    beq decode_actor_direction_command_and_diagonal_facing_c1db68
    .a8
    lda #$00
    rts
decode_actor_direction_command_and_diagonal_facing_c1db68:
    .a8
    lda #$00
    rts
