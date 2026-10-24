.setcpu "65816"
.segment "CODE"
.org $B394
map_control_0fb394:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E1 ; previous-row copy count
