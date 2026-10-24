; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-actor-selection.md.
.setcpu "65816"
.smart
.a8
.i16

bind_event_menu_controller_to_party_actor = $6A73
update_event_menu_primary_mode_flag = $6A5B

.segment "CODE"
.org $6AA5
initialize_event_menu_controller_and_descriptor:
    sep #$30
    stz a:$1809
    jsr update_event_menu_primary_mode_flag
    lda $D9
    bmi initialize_event_menu_controller_and_descriptor_c06ab7
    lda $DA
    bmi initialize_event_menu_controller_and_descriptor_c06ab7
    lda $DB
initialize_event_menu_controller_and_descriptor_c06ab7:
    .a8
    and #$07
    lsr
    sta a:$1808
    sta a:$1805
    asl
    bne initialize_event_menu_controller_and_descriptor_c06ac4
    inc
initialize_event_menu_controller_and_descriptor_c06ac4:
    jsr bind_event_menu_controller_to_party_actor
    rep #$30
    lda a:$1840
    .a16
    and #$00FF
    asl
    clc
    adc f:$D8FB80
    tax
    lda f:$D80000,X
    sta a:$183C
    rts
