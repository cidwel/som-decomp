; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-execution-check.md.
.setcpu "65816"
.smart
.a8
.i16

cancel_cast_and_deliver_pending_target_hits = $8C96
copy_object_weapon_palette = $859B
load_actor_cast_graphics_by_spell_and_level = $8654
prepare_actor_cast_three_target_presentation = $8B82
select_actor_cast_presentation_record = $86D1

.segment "CODE"
.org $8775
execute_ordinary_actor_cast_presentation:
    stx $14
    sep #$20
    stz a:$E012,X
    stz a:$E084,X
    jsr prepare_actor_cast_three_target_presentation
    bcs execute_ordinary_actor_cast_presentation_c18787
    jmp cancel_cast_and_deliver_pending_target_hits
execute_ordinary_actor_cast_presentation_c18787:
    sep #$20
    lda a:$E111,X
    xba
    lda a:$E170,X
    jsr load_actor_cast_graphics_by_spell_and_level
    jsr select_actor_cast_presentation_record
    txy
    tax
    sep #$20
    lda f:$D02AA0,X
    sta a:$E04F,Y
    .a8
    lda #$E0
    sta a:$E060,Y
    rep #$20
    lda f:$D02AA2,X
    sta a:$E06A,Y
    lda f:$D02AA4,X
    sta a:$E0FC,Y
    sta a:$E0FE,Y
    sep #$20
    lda a:$E04F,Y
    tyx
    jmp copy_object_weapon_palette
