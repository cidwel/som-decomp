.setcpu "65816"
.segment "CODE"
.org $5CB2
map_control_0c5cb2:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
