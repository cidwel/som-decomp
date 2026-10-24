; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-child.md.
.setcpu "65816"
.smart
.a8
.i16

consume_linked_child_request_and_select_native_definition = $5E9D
derive_boss_threshold_from_hardware_division_and_clamp = $5920

.segment "CODE"
.org $5ACF
hide_child_strip_countdown_and_update_parent_threshold:
    ldy $89
    .a16
    lda #$0000
    sta a:$0000,Y
    dec a:$0015,X
    bne hide_child_strip_countdown_and_update_parent_threshold_c25aec
    .a16
    lda #$59F7
    sta a:$008E,X
    stz a:$0083,X
    lda a:$00B0,X
    tax
    jsr derive_boss_threshold_from_hardware_division_and_clamp
hide_child_strip_countdown_and_update_parent_threshold_c25aec:
    lda a:$0081,X
    .a16
    cmp #$0004
    bne hide_child_strip_countdown_and_update_parent_threshold_c25af7
    jsr consume_linked_child_request_and_select_native_definition
hide_child_strip_countdown_and_update_parent_threshold_c25af7:
    stz a:$0081,X
    clc
    rts
