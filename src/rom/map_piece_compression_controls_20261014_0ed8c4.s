.setcpu "65816"
.segment "CODE"
.org $D8C4
map_control_0ed8c4:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
