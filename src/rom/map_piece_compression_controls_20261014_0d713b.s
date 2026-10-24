.setcpu "65816"
.segment "CODE"
.org $713B
map_control_0d713b:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
