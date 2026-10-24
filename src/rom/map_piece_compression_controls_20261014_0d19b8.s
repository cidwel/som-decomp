.setcpu "65816"
.segment "CODE"
.org $19B8
map_control_0d19b8:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
