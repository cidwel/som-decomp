; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-font-rows.md.
.setcpu "65816"
.smart
.a8
.i16

decode_dialogue_font_stream_and_all_insertion_commands = $16B8

.segment "CODE"
.org $113F
decode_dialogue_font_stream_and_advance_phase:
    lda f:$001D04
    .a8
    ora #$01
    sta f:$001D04
    jsr decode_dialogue_font_stream_and_all_insertion_commands
    inc a:$A15D
    rts
