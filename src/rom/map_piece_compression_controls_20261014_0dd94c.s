.setcpu "65816"
.segment "CODE"
.org $D94C
map_control_0dd94c:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
