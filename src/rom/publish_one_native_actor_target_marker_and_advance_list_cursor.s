; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-target-selector.md.
.setcpu "65816"
.smart
.a8
.i16

select_native_menu_marker_palette_attribute_long = $C070DB

.segment "CODE"
.org $DC74
publish_one_native_actor_target_marker_and_advance_list_cursor:
    phx
    lda $00,X
    beq publish_one_native_actor_target_marker_and_advance_list_cursor_d0dcba
    tax
    sep #$20
    lda f:$7E0022,X
    sec
    .a8
    sbc #$16
    sec
    sbc f:$7E0045,X
    xba
    .i16
    ldy #$0120
    lda f:$7E0020,X
    clc
    .a8
    adc #$04
    .a8
    cmp #$F0
    bcc publish_one_native_actor_target_marker_and_advance_list_cursor_d0dc9d
    sec
    .a8
    sbc #$18
    .i16
    ldy #$4120
publish_one_native_actor_target_marker_and_advance_list_cursor_d0dc9d:
    rep #$20
    ldx a:$1832
    sta $00,X
    inx
    inx
    .a16
    lda #$0001
    jsl f:select_native_menu_marker_palette_attribute_long
    sta $00,X
    tya
    clc
    adc $00,X
    sta $00,X
    inx
    inx
    stx a:$1832
publish_one_native_actor_target_marker_and_advance_list_cursor_d0dcba:
    plx
    inx
    inx
    rts
