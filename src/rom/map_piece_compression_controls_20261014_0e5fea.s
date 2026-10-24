.setcpu "65816"
.segment "CODE"
.org $5FEA
map_control_0e5fea:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
