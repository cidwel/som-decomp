.setcpu "65816"
.segment "CODE"
.org $D6B5
map_control_0fd6b5:
    .byte $C2 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $0A ; distance low bit/count
