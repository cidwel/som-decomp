.setcpu "65816"
.segment "CODE"
.org $DA07
map_control_0fda07:
    .byte $E6 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
