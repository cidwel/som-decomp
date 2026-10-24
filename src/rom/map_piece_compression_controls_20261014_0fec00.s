.setcpu "65816"
.segment "CODE"
.org $EC00
map_control_0fec00:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
