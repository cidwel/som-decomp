.setcpu "65816"
.segment "CODE"
.org $B1BB
map_control_0fb1bb:
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E6 ; previous-row copy count
