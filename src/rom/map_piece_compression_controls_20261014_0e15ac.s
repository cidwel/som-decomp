.setcpu "65816"
.segment "CODE"
.org $15AC
map_control_0e15ac:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C3 ; same-value copy count/distance
