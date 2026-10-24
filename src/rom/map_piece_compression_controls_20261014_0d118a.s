.setcpu "65816"
.segment "CODE"
.org $118A
map_control_0d118a:
    .byte $E8 ; backreference distance high bits
    .byte $99 ; distance low bit/count
