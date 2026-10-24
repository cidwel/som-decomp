.setcpu "65816"
.segment "CODE"
.org $2D71
map_control_0e2d71:
    .byte $E5 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
