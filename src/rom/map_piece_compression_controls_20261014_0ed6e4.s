.setcpu "65816"
.segment "CODE"
.org $D6E4
map_control_0ed6e4:
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E7 ; previous-row copy count
