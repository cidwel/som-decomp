.setcpu "65816"
.segment "CODE"
.org $17E7
map_control_0d17e7:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
