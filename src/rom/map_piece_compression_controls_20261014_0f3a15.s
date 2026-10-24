.setcpu "65816"
.segment "CODE"
.org $3A15
map_control_0f3a15:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
