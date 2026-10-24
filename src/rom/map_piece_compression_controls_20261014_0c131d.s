.setcpu "65816"
.segment "CODE"
.org $131D
map_control_0c131d:
    .byte $E2 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
