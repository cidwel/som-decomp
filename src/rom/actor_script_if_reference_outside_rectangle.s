; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

jump_actor_script_after_2_bytes = $028D
read_actor_y_minus_height_x = $0343
resolve_actor_script_field_reference = $1FEB
skip_actor_script_after_2_bytes = $021B

ACTOR_POSITION_X = $0020

.segment "CODE"
.org $2194
actor_script_if_reference_outside_rectangle:
    rep #$20
    jsr resolve_actor_script_field_reference
    txa
    .a16
    and #$FE00
    tax
    lda a:ACTOR_POSITION_X,X
    .a16
    cmp #$0008
    bmi actor_script_if_reference_outside_rectangle_c121aa
    bvs actor_script_if_reference_outside_rectangle_c121d9
    bra actor_script_if_reference_outside_rectangle_c121ac
actor_script_if_reference_outside_rectangle_c121aa:
    bvc actor_script_if_reference_outside_rectangle_c121d9
actor_script_if_reference_outside_rectangle_c121ac:
    .a16
    cmp #$00F8
    beq actor_script_if_reference_outside_rectangle_c121b9
    bmi actor_script_if_reference_outside_rectangle_c121b7
    bvc actor_script_if_reference_outside_rectangle_c121d9
    bra actor_script_if_reference_outside_rectangle_c121b9
actor_script_if_reference_outside_rectangle_c121b7:
    bvs actor_script_if_reference_outside_rectangle_c121d9
actor_script_if_reference_outside_rectangle_c121b9:
    jsr read_actor_y_minus_height_x
    .a16
    cmp #$0008
    bmi actor_script_if_reference_outside_rectangle_c121c5
    bvs actor_script_if_reference_outside_rectangle_c121d9
    bra actor_script_if_reference_outside_rectangle_c121c7
actor_script_if_reference_outside_rectangle_c121c5:
    bvc actor_script_if_reference_outside_rectangle_c121d9
actor_script_if_reference_outside_rectangle_c121c7:
    .a16
    cmp #$00D8
    beq actor_script_if_reference_outside_rectangle_c121d4
    bmi actor_script_if_reference_outside_rectangle_c121d2
    bvc actor_script_if_reference_outside_rectangle_c121d9
    bra actor_script_if_reference_outside_rectangle_c121d4
actor_script_if_reference_outside_rectangle_c121d2:
    bvs actor_script_if_reference_outside_rectangle_c121d9
actor_script_if_reference_outside_rectangle_c121d4:
    jsr skip_actor_script_after_2_bytes
    bra actor_script_if_reference_outside_rectangle_c121dc
actor_script_if_reference_outside_rectangle_c121d9:
    jsr jump_actor_script_after_2_bytes
actor_script_if_reference_outside_rectangle_c121dc:
    rts
