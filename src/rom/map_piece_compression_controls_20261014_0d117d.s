.setcpu "65816"
.segment "CODE"
.org $117D
map_control_0d117d:
    .byte $E8 ; backreference distance high bits
    .byte $99 ; distance low bit/count
