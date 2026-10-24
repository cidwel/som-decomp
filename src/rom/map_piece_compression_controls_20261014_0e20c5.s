.setcpu "65816"
.segment "CODE"
.org $20C5
map_control_0e20c5:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E6 ; previous-row copy count
