.setcpu "65816"
.segment "CODE"
.org $9FF1
map_control_0d9ff1:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
