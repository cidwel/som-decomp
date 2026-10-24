.setcpu "65816"
.segment "CODE"
.org $E206
map_control_0de206:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
