.setcpu "65816"
.segment "CODE"
.org $8D47
map_control_0c8d47:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
