.setcpu "65816"
.segment "CODE"
.org $D376
map_control_0dd376:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
