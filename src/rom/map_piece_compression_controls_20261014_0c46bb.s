.setcpu "65816"
.segment "CODE"
.org $46BB
map_control_0c46bb:
    .byte $D3 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
