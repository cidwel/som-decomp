.setcpu "65816"
.segment "CODE"
.org $1787
map_control_0e1787:
    .byte $E5 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
