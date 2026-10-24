.setcpu "65816"
.segment "CODE"
.org $1EE7
map_control_0e1ee7:
    .byte $E2 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
