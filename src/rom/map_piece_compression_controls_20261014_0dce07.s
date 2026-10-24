.setcpu "65816"
.segment "CODE"
.org $CE07
map_control_0dce07:
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
