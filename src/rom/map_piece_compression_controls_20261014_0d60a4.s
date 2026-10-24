.setcpu "65816"
.segment "CODE"
.org $60A4
map_control_0d60a4:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
