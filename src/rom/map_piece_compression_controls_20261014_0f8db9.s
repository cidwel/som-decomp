.setcpu "65816"
.segment "CODE"
.org $8DB9
map_control_0f8db9:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
