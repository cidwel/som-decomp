.setcpu "65816"
.segment "CODE"
.org $C9E4
map_control_0fc9e4:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
