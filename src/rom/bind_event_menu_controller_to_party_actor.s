; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-actor-selection.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6A73
bind_event_menu_controller_to_party_actor:
    sep #$30
    pha
    .i8
    ldx #$01
    lda $D9
    .a8
    and #$07
    cmp $01,S
    beq bind_event_menu_controller_to_party_actor_c06a8c
    .i8
    ldx #$02
    lda $DA
    .a8
    and #$07
    cmp $01,S
    beq bind_event_menu_controller_to_party_actor_c06a8c
    .i8
    ldx #$04
bind_event_menu_controller_to_party_actor_c06a8c:
    pla
    txa
    asl
    asl
    asl
    asl
    asl
    pha
    lda a:$1802
    .a8
    and #$1F
    ora $01,S
    sta a:$1802
    pla
    txa
    lsr
    sta a:$1836
    rts
