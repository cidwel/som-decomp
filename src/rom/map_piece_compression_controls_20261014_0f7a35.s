.setcpu "65816"
.segment "CODE"
.org $7A35
map_control_0f7a35:
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
