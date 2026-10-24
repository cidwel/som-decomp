.setcpu "65816"
.segment "CODE"
.org $C934
map_control_0fc934:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
