.setcpu "65816"
.segment "CODE"
.org $F53D
map_control_0cf53d:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E3 ; previous-row copy count
