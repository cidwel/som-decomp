.setcpu "65816"
.segment "CODE"
.org $508D
map_control_0d508d:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
