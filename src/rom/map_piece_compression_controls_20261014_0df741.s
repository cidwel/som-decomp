.setcpu "65816"
.segment "CODE"
.org $F741
map_control_0df741:
    .byte $CB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
