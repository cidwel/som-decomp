; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-cast-targets.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $731F
write_native_menu_cast_record_single_or_multiple_actor_targets:
    rep #$30
    lda a:$1844
    clc
    .a16
    adc #$FFF0
    tax
    sep #$20
    lda a:$1839
    sta f:$7E0000,X
    lda a:$1846
    sta f:$7E0007,X
    .a8
    lda #$00
    sta f:$7E0008,X
    sta f:$7E0009,X
    sta f:$7E000A,X
    sta a:$1820
    phx
    ldx a:$1822
    lda $01,X
    plx
    .a8
    cmp #$FF
    beq write_native_menu_cast_record_single_or_multiple_actor_targets_c07364
    .a8
    and #$0E
    lsr
    inc
    sta f:$7E0008,X
    .a8
    lda #$01
    sta f:$7E0006,X
    rts
write_native_menu_cast_record_single_or_multiple_actor_targets_c07364:
    .i16
    ldy #$0000
    lda a:$1842
    bpl write_native_menu_cast_record_single_or_multiple_actor_targets_c0736f
    iny
    iny
    iny
write_native_menu_cast_record_single_or_multiple_actor_targets_c0736f:
    tya
    phx
    inc
    ldy a:$1812
    .i16
    cpy #$0000
    beq write_native_menu_cast_record_single_or_multiple_actor_targets_c07382
    sta f:$7E0008,X
    inc a:$1820
    inx
write_native_menu_cast_record_single_or_multiple_actor_targets_c07382:
    inc
    ldy a:$1814
    .i16
    cpy #$0000
    beq write_native_menu_cast_record_single_or_multiple_actor_targets_c07393
    sta f:$7E0008,X
    inc a:$1820
    inx
write_native_menu_cast_record_single_or_multiple_actor_targets_c07393:
    inc
    ldy a:$1816
    .i16
    cpy #$0000
    beq write_native_menu_cast_record_single_or_multiple_actor_targets_c073a3
    sta f:$7E0008,X
    inc a:$1820
write_native_menu_cast_record_single_or_multiple_actor_targets_c073a3:
    plx
    lda a:$1820
    sta f:$7E0006,X
    rts
