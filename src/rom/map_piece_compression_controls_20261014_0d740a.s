.setcpu "65816"
.segment "CODE"
.org $740A
map_control_0d740a:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
