; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-actor-cycle.md.
.setcpu "65816"
.smart
.a8
.i16

bind_event_menu_controller_to_party_actor = $6A73
choose_other_available_menu_actor = $6ADE
update_event_menu_primary_mode_flag = $6A5B

.segment "CODE"
.org $69F0
restore_menu_actor_and_controller_selection_from_coordinates:
    rep #$30
    lda a:$183E
    xba
    tax
    lda a:$1840
    xba
    tay
    jsr update_event_menu_primary_mode_flag
    sep #$30
    .a8
    lda #$00
    .i8
    cpx #$00
    beq restore_menu_actor_and_controller_selection_from_coordinates_c06a0d
    inc
    .i8
    cpx #$02
    beq restore_menu_actor_and_controller_selection_from_coordinates_c06a0d
    inc
restore_menu_actor_and_controller_selection_from_coordinates_c06a0d:
    sta a:$1808
    phx
    .i8
    ldx #$00
    .a8
    lda #$01
    .i8
    cpy #$00
    beq restore_menu_actor_and_controller_selection_from_coordinates_c06a21
    inx
    asl
    .i8
    cpy #$02
    beq restore_menu_actor_and_controller_selection_from_coordinates_c06a21
    inx
    asl
restore_menu_actor_and_controller_selection_from_coordinates_c06a21:
    stx a:$1805
    plx
    pha
    jsr choose_other_available_menu_actor
    pla
    jsr bind_event_menu_controller_to_party_actor
    rep #$30
    lda a:$1808
    .a16
    and #$00FF
    clc
    .a16
    adc #$1870
    tax
    sep #$20
    lda $00,X
    sta a:$1809
