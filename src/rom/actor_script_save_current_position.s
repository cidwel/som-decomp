; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121
read_actor_y_minus_height_y = $032E

ACTOR_POSITION_X = $0020
ACTOR_SAVED_X = $0148
ACTOR_SAVED_Y_MINUS_HEIGHT = $014A

.segment "CODE"
.org $2183
actor_script_save_current_position:
    rep #$20
    lda a:ACTOR_POSITION_X,Y
    sta a:ACTOR_SAVED_X,Y
    jsr read_actor_y_minus_height_y
    sta a:ACTOR_SAVED_Y_MINUS_HEIGHT,Y
    jmp advance_actor_script_1_bytes
