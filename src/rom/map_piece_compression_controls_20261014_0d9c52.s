.setcpu "65816"
.segment "CODE"
.org $9C52
map_control_0d9c52:
    .byte $E8 ; backreference distance high bits
    .byte $96 ; distance low bit/count
