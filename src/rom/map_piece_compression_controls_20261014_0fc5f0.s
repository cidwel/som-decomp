.setcpu "65816"
.segment "CODE"
.org $C5F0
map_control_0fc5f0:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
