.setcpu "65816"
.segment "CODE"
.org $862D
map_control_0f862d:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E7 ; previous-row copy count
