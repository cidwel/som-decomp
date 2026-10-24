.setcpu "65816"
.segment "CODE"
.org $D8BA
map_control_0fd8ba:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
