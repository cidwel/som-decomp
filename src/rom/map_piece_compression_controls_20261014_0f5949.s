.setcpu "65816"
.segment "CODE"
.org $5949
map_control_0f5949:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E7 ; previous-row copy count
