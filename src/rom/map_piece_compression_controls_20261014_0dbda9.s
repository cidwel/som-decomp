.setcpu "65816"
.segment "CODE"
.org $BDA9
map_control_0dbda9:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
