.setcpu "65816"
.segment "CODE"
.org $8EE5
map_control_0e8ee5:
    .byte $E4 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
