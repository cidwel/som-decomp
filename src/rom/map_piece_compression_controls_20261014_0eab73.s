.setcpu "65816"
.segment "CODE"
.org $AB73
map_control_0eab73:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E5 ; previous-row copy count
