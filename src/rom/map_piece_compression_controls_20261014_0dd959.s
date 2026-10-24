.setcpu "65816"
.segment "CODE"
.org $D959
map_control_0dd959:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
