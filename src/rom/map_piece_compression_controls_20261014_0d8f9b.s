.setcpu "65816"
.segment "CODE"
.org $8F9B
map_control_0d8f9b:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
