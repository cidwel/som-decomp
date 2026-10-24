.setcpu "65816"
.segment "CODE"
.org $35AC
map_control_0e35ac:
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E3 ; previous-row copy count
