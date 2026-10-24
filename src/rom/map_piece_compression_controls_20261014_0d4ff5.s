.setcpu "65816"
.segment "CODE"
.org $4FF5
map_control_0d4ff5:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
