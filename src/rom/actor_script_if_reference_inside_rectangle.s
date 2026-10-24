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
.org $21DD
actor_script_if_reference_inside_rectangle:
    rep #$20
    jsr resolve_actor_script_field_reference
    txa
    .a16
    and #$FE00
    tax
    lda a:ACTOR_POSITION_X,X
    .a16
    cmp #$0008
    bmi actor_script_if_reference_inside_rectangle_c121f3
    bvs actor_script_if_reference_inside_rectangle_c12222
    bra actor_script_if_reference_inside_rectangle_c121f5
actor_script_if_reference_inside_rectangle_c121f3:
    bvc actor_script_if_reference_inside_rectangle_c12222
actor_script_if_reference_inside_rectangle_c121f5:
    .a16
    cmp #$00F8
    beq actor_script_if_reference_inside_rectangle_c12202
    bmi actor_script_if_reference_inside_rectangle_c12200
    bvc actor_script_if_reference_inside_rectangle_c12222
    bra actor_script_if_reference_inside_rectangle_c12202
actor_script_if_reference_inside_rectangle_c12200:
    bvs actor_script_if_reference_inside_rectangle_c12222
actor_script_if_reference_inside_rectangle_c12202:
    jsr read_actor_y_minus_height_x
    .a16
    cmp #$0008
    bmi actor_script_if_reference_inside_rectangle_c1220e
    bvs actor_script_if_reference_inside_rectangle_c12222
    bra actor_script_if_reference_inside_rectangle_c12210
actor_script_if_reference_inside_rectangle_c1220e:
    bvc actor_script_if_reference_inside_rectangle_c12222
actor_script_if_reference_inside_rectangle_c12210:
    .a16
    cmp #$00D8
    beq actor_script_if_reference_inside_rectangle_c1221d
    bmi actor_script_if_reference_inside_rectangle_c1221b
    bvc actor_script_if_reference_inside_rectangle_c12222
    bra actor_script_if_reference_inside_rectangle_c1221d
actor_script_if_reference_inside_rectangle_c1221b:
    bvs actor_script_if_reference_inside_rectangle_c12222
actor_script_if_reference_inside_rectangle_c1221d:
    jsr jump_actor_script_after_2_bytes
    bra actor_script_if_reference_inside_rectangle_c12225
actor_script_if_reference_inside_rectangle_c12222:
    jsr skip_actor_script_after_2_bytes
actor_script_if_reference_inside_rectangle_c12225:
    rts
