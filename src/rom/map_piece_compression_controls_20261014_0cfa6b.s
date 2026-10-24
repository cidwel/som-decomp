.setcpu "65816"
.segment "CODE"
.org $FA6B
map_control_0cfa6b:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
