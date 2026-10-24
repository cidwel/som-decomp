.setcpu "65816"
.segment "CODE"
.org $BCA9
map_control_0fbca9:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E7 ; previous-row copy count
