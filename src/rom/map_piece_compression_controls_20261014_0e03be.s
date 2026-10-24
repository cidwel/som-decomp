.setcpu "65816"
.segment "CODE"
.org $03BE
map_control_0e03be:
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
