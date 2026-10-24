.setcpu "65816"
.segment "CODE"
.org $0C5C
map_control_0f0c5c:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
