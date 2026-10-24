.setcpu "65816"
.segment "CODE"
.org $29F6
map_control_0e29f6:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
