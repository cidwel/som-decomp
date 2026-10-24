.setcpu "65816"
.segment "CODE"
.org $D7EA
map_control_0dd7ea:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
