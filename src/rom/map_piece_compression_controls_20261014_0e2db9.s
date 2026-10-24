.setcpu "65816"
.segment "CODE"
.org $2DB9
map_control_0e2db9:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E4 ; previous-row copy count
