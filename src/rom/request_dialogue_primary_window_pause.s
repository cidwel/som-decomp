; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-pause.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c00f86 = $0F86

.segment "CODE"
.org $0F6C
request_dialogue_primary_window_pause:
    .a8
    lda #$50
    sta a:$A170
    lda a:$A187
    .a8
    and #$01
    bne routine_c00f86
    .a8
    lda #$01
    tsb a:$A187
