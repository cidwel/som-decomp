.setcpu "65816"
.segment "CODE"
.org $DE5B
map_control_0dde5b:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
