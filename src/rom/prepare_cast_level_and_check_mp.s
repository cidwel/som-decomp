; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

check_cast_mp_and_queue_level_message = $C03F69
prepare_cast_actor_context_long = $C0395E
read_actor_element_spell_level = $4E6E
select_cast_level_with_grade_eight_progress = $4EAC

.segment "CODE"
.org $4D9E
prepare_cast_level_and_check_mp:
    phd
    phb
    php
    jsl f:prepare_cast_actor_context_long
    ldx $83
    .a8
    lda #$FF
    sta a:$E172,X
    sta a:$E173,X
    sta a:$E174,X
    jsr read_actor_element_spell_level
    ldx $83
    jsr select_cast_level_with_grade_eight_progress
    ldx $83
    lda a:$E170,X
    sta f:$004202
    .a8
    lda #$40
    sta f:$004203
    jml f:check_cast_mp_and_queue_level_message
