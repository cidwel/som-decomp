.setcpu "65816"
.segment "CODE"
.org $725E
map_control_0e725e:
    .byte $C2 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
