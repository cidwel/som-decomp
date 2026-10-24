.setcpu "65816"
.segment "CODE"
.org $F4D8
map_control_0ef4d8:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
