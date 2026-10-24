.setcpu "65816"
.segment "CODE"
.org $2EE9
map_control_0d2ee9:
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
