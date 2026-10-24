.setcpu "65816"
.segment "CODE"
.org $D208
map_control_0dd208:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
