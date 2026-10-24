.setcpu "65816"
.segment "CODE"
.org $379C
map_control_0d379c:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
