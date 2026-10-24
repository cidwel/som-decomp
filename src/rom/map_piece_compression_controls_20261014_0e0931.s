.setcpu "65816"
.segment "CODE"
.org $0931
map_control_0e0931:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
