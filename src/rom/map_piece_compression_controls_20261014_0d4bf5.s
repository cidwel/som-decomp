.setcpu "65816"
.segment "CODE"
.org $4BF5
map_control_0d4bf5:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
