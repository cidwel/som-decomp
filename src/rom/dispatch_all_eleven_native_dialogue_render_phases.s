; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-core.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $111A
dispatch_all_eleven_native_dialogue_render_phases:
    lda f:$001D00
    .a8
    and #$40
    beq dispatch_all_eleven_native_dialogue_render_phases_c01133
    lda f:$001D00
    .a8
    and #$BF
    sta f:$001D00
    .a8
    lda #$52
    sta a:$A170
    bra dispatch_all_eleven_native_dialogue_render_phases_c0113e
dispatch_all_eleven_native_dialogue_render_phases_c01133:
    .a8
    lda #$00
    xba
    lda a:$A15D
    asl
    tax
    jsr ($1A0C,X)
dispatch_all_eleven_native_dialogue_render_phases_c0113e:
    rts
