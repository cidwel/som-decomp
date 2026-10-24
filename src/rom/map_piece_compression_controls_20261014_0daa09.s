.setcpu "65816"
.segment "CODE"
.org $AA09
map_control_0daa09:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
