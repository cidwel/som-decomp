; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

jump_actor_script_after_1_bytes = $0285
read_actor_y_minus_height_y = $032E
skip_actor_script_after_1_bytes = $0213

ACTOR_POSITION_X = $0020
ACTOR_SAVED_X = $0148
ACTOR_SAVED_Y_MINUS_HEIGHT = $014A

.segment "CODE"
.org $2168
actor_script_if_saved_position_changed:
    rep #$20
    lda a:ACTOR_POSITION_X,Y
    cmp a:ACTOR_SAVED_X,Y
    bne actor_script_if_saved_position_changed_c1217f
    jsr read_actor_y_minus_height_y
    cmp a:ACTOR_SAVED_Y_MINUS_HEIGHT,Y
    bne actor_script_if_saved_position_changed_c1217f
    jsr skip_actor_script_after_1_bytes
    bra actor_script_if_saved_position_changed_c12182
actor_script_if_saved_position_changed_c1217f:
    jsr jump_actor_script_after_1_bytes
actor_script_if_saved_position_changed_c12182:
    rts
