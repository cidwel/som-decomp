.setcpu "65816"
.segment "CODE"
.org $41B2
map_control_0d41b2:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
