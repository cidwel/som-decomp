.setcpu "65816"
.segment "CODE"
.org $987E
map_control_0d987e:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
