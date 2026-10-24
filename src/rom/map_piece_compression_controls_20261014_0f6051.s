.setcpu "65816"
.segment "CODE"
.org $6051
map_control_0f6051:
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
