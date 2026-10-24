.setcpu "65816"
.segment "CODE"
.org $8E4D
map_control_0e8e4d:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E3 ; previous-row copy count
