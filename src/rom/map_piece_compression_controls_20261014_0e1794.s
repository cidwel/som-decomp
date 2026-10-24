.setcpu "65816"
.segment "CODE"
.org $1794
map_control_0e1794:
    .byte $E4 ; previous-row copy count
    .byte $CE ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E5 ; previous-row copy count
