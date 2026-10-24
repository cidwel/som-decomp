.setcpu "65816"
.segment "CODE"
.org $2389
map_control_0f2389:
    .byte $E8 ; backreference distance high bits
    .byte $39 ; distance low bit/count
