.setcpu "65816"
.segment "CODE"
.org $B16A
map_control_0eb16a:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
