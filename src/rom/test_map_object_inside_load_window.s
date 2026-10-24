; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DF85
test_map_object_inside_load_window:
    sep #$20
    lda a:$C80C,Y
    .a8
    and #$08
    bne test_map_object_inside_load_window_c0dfb2
    lda a:$C80A,Y
    .a8
    and #$7F
    sec
    sbc $04
    bcs test_map_object_inside_load_window_c0df9a
    adc $9C
test_map_object_inside_load_window_c0df9a:
    cmp $08
    bcs test_map_object_inside_load_window_c0dfb0
    lda a:$C80B,Y
    .a8
    and #$7F
    sec
    sbc $05
    bcs test_map_object_inside_load_window_c0dfaa
    adc $9D
test_map_object_inside_load_window_c0dfaa:
    cmp $09
    bcs test_map_object_inside_load_window_c0dfb0
    sec
    rts
test_map_object_inside_load_window_c0dfb0:
    clc
    rts
test_map_object_inside_load_window_c0dfb2:
    lda a:$C80A,Y
    .a8
    and #$7F
    sec
    sbc $06
    bcs test_map_object_inside_load_window_c0dfbe
    adc $9C
test_map_object_inside_load_window_c0dfbe:
    cmp $08
    bcs test_map_object_inside_load_window_c0dfb0
    lda a:$C80B,Y
    .a8
    and #$7F
    sec
    sbc $07
    bcs test_map_object_inside_load_window_c0dfce
    adc $9D
test_map_object_inside_load_window_c0dfce:
    cmp $09
    bcs test_map_object_inside_load_window_c0dfb0
    sec
    rts
