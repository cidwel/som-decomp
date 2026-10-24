.setcpu "65816"
.segment "CODE"
.org $901B
map_control_0d901b:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
