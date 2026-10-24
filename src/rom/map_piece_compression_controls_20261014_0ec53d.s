.setcpu "65816"
.segment "CODE"
.org $C53D
map_control_0ec53d:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E2 ; previous-row copy count
