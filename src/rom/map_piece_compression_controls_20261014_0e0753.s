.setcpu "65816"
.segment "CODE"
.org $0753
map_control_0e0753:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
