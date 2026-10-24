.setcpu "65816"
.segment "CODE"
.org $431F
map_control_0d431f:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
