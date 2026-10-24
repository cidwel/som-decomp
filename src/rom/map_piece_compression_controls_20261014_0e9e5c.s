.setcpu "65816"
.segment "CODE"
.org $9E5C
map_control_0e9e5c:
    .byte $E8 ; backreference distance high bits
    .byte $29 ; distance low bit/count
