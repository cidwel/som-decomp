.setcpu "65816"
.segment "CODE"
.org $36E8
map_control_0d36e8:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
