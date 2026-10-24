.setcpu "65816"
.segment "CODE"
.org $D39A
map_control_0dd39a:
    .byte $E5 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
