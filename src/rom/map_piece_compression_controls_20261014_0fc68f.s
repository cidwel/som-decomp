.setcpu "65816"
.segment "CODE"
.org $C68F
map_control_0fc68f:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
