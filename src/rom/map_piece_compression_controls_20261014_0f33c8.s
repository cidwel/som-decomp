.setcpu "65816"
.segment "CODE"
.org $33C8
map_control_0f33c8:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
