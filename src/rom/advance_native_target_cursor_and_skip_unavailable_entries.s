; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-target-selector.md.
.setcpu "65816"
.smart
.a8
.i16

routine_d0dc02 = $DC02

.segment "CODE"
.org $DC14
advance_native_target_cursor_and_skip_unavailable_entries:
advance_native_target_cursor_and_skip_unavailable_entries_d0dc14:
    rep #$30
    lda a:$1840
    clc
    adc a:$1822
    .i16
    ldx #$1812
    .a16
    cmp #$181A
    bcs advance_native_target_cursor_and_skip_unavailable_entries_d0dc2e
    tax
    .a16
    cmp #$1812
    bcs advance_native_target_cursor_and_skip_unavailable_entries_d0dc2e
    .i16
    ldx #$1818
advance_native_target_cursor_and_skip_unavailable_entries_d0dc2e:
    stx a:$1822
    lda $00,X
    bne advance_native_target_cursor_and_skip_unavailable_entries_d0dc3f
    lda a:$1822
    cmp a:$183E
    beq routine_d0dc02
    bra advance_native_target_cursor_and_skip_unavailable_entries_d0dc14
advance_native_target_cursor_and_skip_unavailable_entries_d0dc3f:
    .a16
    cmp #$FFFE
    beq advance_native_target_cursor_and_skip_unavailable_entries_d0dc14
