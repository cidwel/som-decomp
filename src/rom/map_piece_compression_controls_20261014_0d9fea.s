.setcpu "65816"
.segment "CODE"
.org $9FEA
map_control_0d9fea:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
