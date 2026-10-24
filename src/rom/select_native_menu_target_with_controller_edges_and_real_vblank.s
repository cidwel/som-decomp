; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-target-selector.md.
.setcpu "65816"
.smart
.a8
.i16

advance_native_target_cursor_and_skip_unavailable_entries = $DC14
hide_native_menu_icon_oam_objects = $D0C83F
open_native_menu_ring_and_wait_for_phase_zero_public = $C068EA
publish_native_single_or_blinking_multi_target_markers = $DC44
request_native_menu_audio_0c = $D0CEF8
request_native_menu_audio_0e = $D0CF08
wait_vblank_and_poll_menu_through_native_long_wrapper = $C0695A

.segment "CODE"
.org $DB58
select_native_menu_target_with_controller_edges_and_real_vblank:
    jsl f:request_native_menu_audio_0e
    jsl f:hide_native_menu_icon_oam_objects
    sep #$30
    lda a:$1842
    bmi select_native_menu_target_with_controller_edges_and_real_vblank_d0db7a
    lda a:$1808
    asl
    tax
    rep #$30
    lda a:$1812,X
    php
    txa
    clc
    .a16
    adc #$1812
    plp
    bne select_native_menu_target_with_controller_edges_and_real_vblank_d0db8f
select_native_menu_target_with_controller_edges_and_real_vblank_d0db7a:
    rep #$30
    .a16
    lda #$1812
    ldx a:$1812
    bne select_native_menu_target_with_controller_edges_and_real_vblank_d0db8f
    .a16
    lda #$1814
    ldx a:$1814
    bne select_native_menu_target_with_controller_edges_and_real_vblank_d0db8f
    .a16
    lda #$1816
select_native_menu_target_with_controller_edges_and_real_vblank_d0db8f:
    sta a:$1822
    sta a:$183E
    stz a:$1840
    jsr advance_native_target_cursor_and_skip_unavailable_entries
    sep #$20
    .a8
    lda #$20
    tsb a:$1803
    .a8
    lda #$04
    tsb a:$1802
select_native_menu_target_with_controller_edges_and_real_vblank_d0dba7:
    jsl f:wait_vblank_and_poll_menu_through_native_long_wrapper
    jsr publish_native_single_or_blinking_multi_target_markers
    rep #$20
    lda a:$1800
    bmi select_native_menu_target_with_controller_edges_and_real_vblank_d0dba7
select_native_menu_target_with_controller_edges_and_real_vblank_d0dbb5:
    jsl f:wait_vblank_and_poll_menu_through_native_long_wrapper
    jsr publish_native_single_or_blinking_multi_target_markers
    sep #$20
    lda a:$1801
    .a8
    bit #$40
    bne select_native_menu_target_with_controller_edges_and_real_vblank_d0dbcb
    .a8
    bit #$80
    beq select_native_menu_target_with_controller_edges_and_real_vblank_d0dbe0
    .a8
    lda #$00
select_native_menu_target_with_controller_edges_and_real_vblank_d0dbcb:
    pha
    .a8
    lda #$20
    trb a:$1803
    pla
    rep #$20
    .a16
    bit #$0040
    beq select_native_menu_target_with_controller_edges_and_real_vblank_d0dbdf
    php
    jsl f:open_native_menu_ring_and_wait_for_phase_zero_public
    plp
select_native_menu_target_with_controller_edges_and_real_vblank_d0dbdf:
    rtl
select_native_menu_target_with_controller_edges_and_real_vblank_d0dbe0:
    sep #$20
    lda a:$1801
    .i16
    ldx #$FFFE
    .a8
    bit #$0A
    bne select_native_menu_target_with_controller_edges_and_real_vblank_d0dbf3
    .i16
    ldx #$0002
    .a8
    bit #$05
    beq select_native_menu_target_with_controller_edges_and_real_vblank_d0dc12
select_native_menu_target_with_controller_edges_and_real_vblank_d0dbf3:
    jsl f:request_native_menu_audio_0c
    .a8
    lda #$04
    tsb a:$1802
    stx a:$1840
    jsr advance_native_target_cursor_and_skip_unavailable_entries
select_native_menu_target_with_controller_edges_and_real_vblank_d0dc02:
    jsl f:wait_vblank_and_poll_menu_through_native_long_wrapper
    jsr publish_native_single_or_blinking_multi_target_markers
    sep #$20
    lda a:$1801
    .a8
    and #$8F
    bne select_native_menu_target_with_controller_edges_and_real_vblank_d0dc02
select_native_menu_target_with_controller_edges_and_real_vblank_d0dc12:
    bra select_native_menu_target_with_controller_edges_and_real_vblank_d0dbb5
