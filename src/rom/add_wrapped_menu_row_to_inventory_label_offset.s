; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_wrapped_native_menu_row_index = $C06BE2

.segment "CODE"
.org $D530
add_wrapped_menu_row_to_inventory_label_offset:
    sep #$30
    pha
    lda a:$1847
    .a8
    cmp #$02
    bne add_wrapped_menu_row_to_inventory_label_offset_d0d540
    jsl f:calculate_wrapped_native_menu_row_index
    bra add_wrapped_menu_row_to_inventory_label_offset_d0d55d
add_wrapped_menu_row_to_inventory_label_offset_d0d540:
    lda a:$180A
    clc
    adc a:$182E
    tax
    inc
    cmp a:$180B
    bcc add_wrapped_menu_row_to_inventory_label_offset_d0d55c
    sec
    sbc a:$180B
    tax
    cmp a:$182E
    bne add_wrapped_menu_row_to_inventory_label_offset_d0d55c
    ldx a:$180B
    dex
add_wrapped_menu_row_to_inventory_label_offset_d0d55c:
    txa
add_wrapped_menu_row_to_inventory_label_offset_d0d55d:
    clc
    adc $01,S
    sta $01,S
    pla
    rts
