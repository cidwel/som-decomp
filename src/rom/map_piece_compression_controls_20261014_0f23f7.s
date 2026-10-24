.setcpu "65816"
.segment "CODE"
.org $23F7
map_control_0f23f7:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
