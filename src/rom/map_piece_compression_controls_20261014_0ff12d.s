.setcpu "65816"
.segment "CODE"
.org $F12D
map_control_0ff12d:
    .byte $C2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
