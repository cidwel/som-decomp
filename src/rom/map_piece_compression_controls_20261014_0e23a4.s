.setcpu "65816"
.segment "CODE"
.org $23A4
map_control_0e23a4:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
