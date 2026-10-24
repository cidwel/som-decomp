; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-child.md.
.setcpu "65816"
.smart
.a8
.i16

advance_linked_child_strip_collapse_and_request_sound = $5A66

.segment "CODE"
.org $5A41
initialize_linked_child_strip_collapse_from_parent_variant:
    dec a:$0083,X
    stz a:$0090,X
    stz a:$0049,X
    .a16
    lda #$5A66
    sta a:$008E,X
    ldy a:$00B0,X
    lda a:$0042,Y
    bne initialize_linked_child_strip_collapse_from_parent_variant_c25a60
    .a16
    lda #$FFFF
    sta a:$0015,X
    bra advance_linked_child_strip_collapse_and_request_sound
initialize_linked_child_strip_collapse_from_parent_variant_c25a60:
    .a16
    lda #$0040
    sta a:$0015,X
