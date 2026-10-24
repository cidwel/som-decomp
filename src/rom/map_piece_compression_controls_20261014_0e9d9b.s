.setcpu "65816"
.segment "CODE"
.org $9D9B
map_control_0e9d9b:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
