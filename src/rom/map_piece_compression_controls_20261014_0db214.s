.setcpu "65816"
.segment "CODE"
.org $B214
map_control_0db214:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
