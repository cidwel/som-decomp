; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-target-selector.md.
.setcpu "65816"
.smart
.a8
.i16

hide_shop_hero_markers_before_price_selection = $C0793D
publish_one_native_actor_target_marker_and_advance_list_cursor = $DC74

.segment "CODE"
.org $DC44
publish_native_single_or_blinking_multi_target_markers:
    .a16
    lda #$082C
    sta a:$1832
    jsl f:hide_shop_hero_markers_before_price_selection
    ldx a:$1822
    lda $00,X
    inc
    bne publish_native_single_or_blinking_multi_target_markers_d0dc70
    lda a:$181E
    inc
    .a16
    cmp #$0002
    bcc publish_native_single_or_blinking_multi_target_markers_d0dc62
    .a16
    lda #$0000
publish_native_single_or_blinking_multi_target_markers_d0dc62:
    sta a:$181E
    beq publish_native_single_or_blinking_multi_target_markers_d0dc73
    .i16
    ldx #$1812
    jsr publish_one_native_actor_target_marker_and_advance_list_cursor
    jsr publish_one_native_actor_target_marker_and_advance_list_cursor
publish_native_single_or_blinking_multi_target_markers_d0dc70:
    jsr publish_one_native_actor_target_marker_and_advance_list_cursor
publish_native_single_or_blinking_multi_target_markers_d0dc73:
    rts
