.setcpu "65816"
.segment "CODE"
.org $49D1
map_control_0c49d1:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
