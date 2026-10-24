.setcpu "65816"
.segment "CODE"
.org $7351
map_control_0d7351:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
