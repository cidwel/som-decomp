; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-line-completion.md.
.setcpu "65816"
.smart
.a8
.i16

publish_eight_dialogue_control_object_sprite_records = $133C

.segment "CODE"
.org $1322
mark_or_publish_dialogue_control_object:
    lda f:$001D13
    beq mark_or_publish_dialogue_control_object_c01338
    rep #$20
    lda f:$001D14
    tax
    sep #$20
    .a8
    lda #$01
    sta a:$0000,X
    bra mark_or_publish_dialogue_control_object_c0133b
mark_or_publish_dialogue_control_object_c01338:
    jsr publish_eight_dialogue_control_object_sprite_records
mark_or_publish_dialogue_control_object_c0133b:
    rts
