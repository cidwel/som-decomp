.setcpu "65816"
.segment "CODE"
.org $19BF
map_control_0f19bf:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
