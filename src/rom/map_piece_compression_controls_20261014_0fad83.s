.setcpu "65816"
.segment "CODE"
.org $AD83
map_control_0fad83:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
