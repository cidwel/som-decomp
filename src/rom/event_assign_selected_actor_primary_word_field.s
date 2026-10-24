; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-actor-fields-and-bindings.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F04B
event_assign_selected_actor_primary_word_field:
    rep #$30
    .i16
    ldy #$0002
    lda [$D1],Y
    sta $00
    lda $D1
    clc
    .a16
    adc #$0004
    sta $D1
    ldx $D4
    lda $05
    .a16
    and #$00FF
    beq event_assign_selected_actor_primary_word_field_c1f069
    dec
    asl
    xba
    tax
event_assign_selected_actor_primary_word_field_c1f069:
    lda $00
    sta a:$E040,X
    rts
