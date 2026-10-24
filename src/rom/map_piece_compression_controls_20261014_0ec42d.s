.setcpu "65816"
.segment "CODE"
.org $C42D
map_control_0ec42d:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
