.setcpu "65816"
.segment "CODE"
.org $BA2C
map_control_0eba2c:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
