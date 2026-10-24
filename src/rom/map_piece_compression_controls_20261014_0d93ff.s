.setcpu "65816"
.segment "CODE"
.org $93FF
map_control_0d93ff:
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
