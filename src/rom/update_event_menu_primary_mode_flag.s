; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-actor-selection.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6A5B
update_event_menu_primary_mode_flag:
    sep #$30
    phx
    lda a:$1802
    ldx a:$1820
    .i8
    cpx #$00
    bne update_event_menu_primary_mode_flag_c06a6c
    .a8
    ora #$01
    bra update_event_menu_primary_mode_flag_c06a6e
update_event_menu_primary_mode_flag_c06a6c:
    .a8
    and #$FE
update_event_menu_primary_mode_flag_c06a6e:
    sta a:$1802
    plx
    rts
