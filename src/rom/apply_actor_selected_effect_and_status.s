; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

apply_actor_status_and_timers = $C8E301
prepare_cast_actor_context_long = $C0395E
restore_selected_effect_native_context_long = $E128

actor_selected_effect_handler_table = $E259

.segment "CODE"
.org $E1ED
apply_actor_selected_effect_and_status:
    phd
    phb
    php
    phx
    phy
    plx
    ply
    jsl f:prepare_cast_actor_context_long
    .a8
    lda #$03
    sta $A4
    .i16
    ldx #$0000
    stx $B4
apply_actor_selected_effect_and_status_c8e201:
    ldx $B4
    lda a:$E1FB,X
    .a8
    bit #$04
    beq apply_actor_selected_effect_and_status_c8e213
    lda $B5
    lsr
    sta $81
    stx $85
    bra apply_actor_selected_effect_and_status_c8e21b
apply_actor_selected_effect_and_status_c8e213:
    inc $B5
    inc $B5
    dec $A4
    bne apply_actor_selected_effect_and_status_c8e201
apply_actor_selected_effect_and_status_c8e21b:
    ldx $85
    lda $82
    sta a:$E1EC,X
    lda a:$E190,X
    .a8
    and #$FC
    sta a:$E190,X
    stz a:$E1F1,X
    stz a:$E1F2,X
    stz a:$E059,X
    lda a:$E1FB,X
    .a8
    and #$FB
    sta a:$E1FB,X
    rep #$20
    lda a:$E181,X
    asl
    .a16
    and #$00FF
    sta $96
    sep #$20
    lda a:$E1C8,Y
    asl
    tax
    jsr (actor_selected_effect_handler_table,X)
    ldx $85
    jsl f:apply_actor_status_and_timers
    jmp restore_selected_effect_native_context_long
