.setcpu "65816"
.segment "CODE"
.org $B3AC
map_control_0fb3ac:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E1 ; previous-row copy count
