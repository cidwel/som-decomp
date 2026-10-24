.setcpu "65816"
.segment "CODE"
.org $41D7
map_control_0d41d7:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
