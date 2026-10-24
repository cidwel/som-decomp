.setcpu "65816"
.segment "CODE"
.org $8E37
map_control_0d8e37:
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
