.setcpu "65816"
.segment "CODE"
.org $C5FF
map_control_0fc5ff:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
