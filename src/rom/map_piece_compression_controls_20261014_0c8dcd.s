.setcpu "65816"
.segment "CODE"
.org $8DCD
map_control_0c8dcd:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
