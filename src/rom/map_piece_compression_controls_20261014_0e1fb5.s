.setcpu "65816"
.segment "CODE"
.org $1FB5
map_control_0e1fb5:
    .byte $E7 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
