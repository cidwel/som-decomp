.setcpu "65816"
.segment "CODE"
.org $5813
map_control_0c5813:
    .byte $ED ; backreference distance high bits
    .byte $8B ; distance low bit/count
