.setcpu "65816"
.segment "CODE"
.org $1713
map_control_0e1713:
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E5 ; previous-row copy count
