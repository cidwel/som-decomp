.setcpu "65816"
.segment "CODE"
.org $C51F
map_control_0fc51f:
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
